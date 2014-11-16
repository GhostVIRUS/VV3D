#include "VMainWindow.h"

VMainWindow::VMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); // applies interface

	particlesContainer = 0;
//	particlesPreContainer = 0;
	particlesOrder = 0;
	ndd = 0;
	epd = 0;

	ui.mainContent->clear();

	//ui.particlesEditorTable->resizeColumnsToContents();
	//ui.particlesEditorTable->resizeRowsToContents();
	ui.particlesEditorTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

VMainWindow::~VMainWindow()
{
	//if (particlesContainer != 0)
	//{
	//	particlesContainer->clear();
	//}
	delete particlesContainer; //Crash fixed, but possible there is memory leak | Look container_base destructor
//	delete particlesPreContainer;
	delete particlesOrder;
	delete ndd;
	delete epd;

	qDeleteAll(canvases);
	qDeleteAll(cells);
}

void VMainWindow::createNewFile(QString name, int type, VPoint a, VPoint b)
{
	delete particlesContainer;
	delete particlesOrder;

	containerBorders.first = a; //min
	containerBorders.second = b; //max

	particlesContainer = new voro::container(a.x, b.x, a.y, b.y, a.z, b.z, 
		abs(a.x - b.x) * 1, abs(a.y - b.y) * 1, abs(a.z - b.z) * 1, false, false, false, 8);
	particlesOrder = new voro::particle_order();

	ui.addParticle->setEnabled(true);
	ui.deleteParticle->setEnabled(true);
	ui.editParticlesAction->setEnabled(true);

	ui.particlesEditorTable->clear();
	ui.particlesEditorTable->setHorizontalHeaderLabels(QStringList() << "x" << "y" << "z");
	ui.particlesEditorTable->setRowCount(0);

	ui.mainContent->clear();
	canvases.insert(QString("mainCanvas"), new VCanvas(ui.mainContent));
	ui.mainContent->addTab(canvases.last(), name);
	double lengthX, lengthY, lengthZ;
	lengthX = qMax(qAbs(a.x), qAbs(b.x));
	lengthY = qMax(qAbs(a.y), qAbs(b.y));
	lengthZ = qMax(qAbs(a.z), qAbs(b.z));

	canvases.value(QString("mainCanvas"))->setAxesLength(qMax(lengthX, qMax(lengthY, lengthZ))+1);
	canvases.value(QString("mainCanvas"))->setScaling(3/qMax(lengthX, qMax(lengthY, lengthZ)));

	qDeleteAll(cells);
	cells.clear();
}

void VMainWindow::newFile()
{
	if (ndd == 0)
	{
		ndd = new VNewDiagramDialog(this);
		connect(ndd, SIGNAL(valuesAccepted(QString, int, VPoint, VPoint)), this, SLOT(createNewFile(QString, int, VPoint, VPoint)));
	}

	ndd->show();
	ndd->raise();
	ndd->activateWindow();
}


void VMainWindow::editParticles()
{
	if (epd == 0)
	{
		epd = new VEditParticlesDialog(this);
		//connect(epd, SIGNAL(valuesAccepted(QString, int, VPoint, VPoint)), this, SLOT(createNewFile(QString, int, VPoint, VPoint)));
		connect(epd, SIGNAL(valuesAccepted(QList<VPoint *>)), this, SLOT(updateParticles(QList<VPoint *>)));
	}
	epd->setMinMax(containerBorders.first, containerBorders.second);

	QList<const VPoint *> particles;
	QMapIterator<int, VCell *> i(cells);
	while (i.hasNext())
	{
		i.next();
		particles << i.value()->getParticle();
	}
	epd->setData(particles);

	epd->show();
	epd->raise();
	epd->activateWindow();
}


void VMainWindow::updateParticles(QList<VPoint *> particles)
{
	qDeleteAll(cells);
	cells.clear();

	ui.particlesEditorTable->clear();
	ui.particlesEditorTable->setRowCount(particles.size());
	for (int i = 0; i < particles.size(); ++i)
	{
		if (checkParticle(particles[i]->x, particles[i]->y, particles[i]->z))
		{
			cells[i] = new VCell;
			cells.value(i)->setParticle(*particles[i]);

			ui.particlesEditorTable->setItem(i, 0, new QTableWidgetItem(QString::number(particles[i]->x)));
			ui.particlesEditorTable->setItem(i, 1, new QTableWidgetItem(QString::number(particles[i]->y)));
			ui.particlesEditorTable->setItem(i, 2, new QTableWidgetItem(QString::number(particles[i]->z)));
		}
		/*else
		{
			QErrorMessage err;
			err.showMessage(QString("SOME COORDINATES ARE OUT OF CONTAINER!"));
			err.exec(); //stops program and shows the message
		}*/
	}
	updateContainer();
}


void VMainWindow::updateParticle(int row, double x, double y, double z)
{
	if (checkParticle(x, y, z))
	{
		if (!cells.contains(row))
		{
			cells[row] = new VCell;
		}
		cells.value(row)->setParticle(VPoint(x, y, z));
		updateContainer();
	}
	else
	{
		QErrorMessage err;
		err.showMessage(QString("Recently added values is out of container's borders!\nParticle haven't been changed."));
		err.exec(); //stops program and shows the message
	}
}


void VMainWindow::deleteParticle(int row)
{
	delete cells.value(row);
	cells.remove(row);
	QMapIterator<int, VCell *> i(cells);
	while (i.hasNext())
	{
		i.next();
		if (i.key() > row)
		{
			cells[i.key() - 1] = cells[i.key()];
			cells.remove(i.key());
		}
	}
	if (cells.size() > 0)
	{
		updateContainer();
	}
}


void VMainWindow::updateContainer(int added)
{
	//if (added != -1)
	//{
	//	particlesContainer->put(*particlesOrder, added, 
	//		particles.value(added).x, particles.value(added).y, particles.value(added).z);
	//}
	//else
	//{
		delete particlesOrder;
		particlesOrder = new voro::particle_order();
		particlesContainer->clear();

		//QMapIterator<int, VPoint> i(particles);
		QMapIterator<int, VCell *> i(cells);
		while (i.hasNext())
		{
			i.next();
			const VPoint *pParticle = i.value()->getParticle();
			particlesContainer->put(*particlesOrder, i.key(), pParticle->x, pParticle->y, pParticle->z);
		}
	//}
	updateContent();
}

bool VMainWindow::checkParticle(double x, double y, double z)
{
	if (x < containerBorders.second.x && x > containerBorders.first.x &&
		y < containerBorders.second.y && y > containerBorders.first.y &&
		z < containerBorders.second.z && z > containerBorders.first.z)
		return true;
	else
		return false;
}

void VMainWindow::updateContent()
{
	QMapIterator<QString, VCanvas *> i(canvases);
	while (i.hasNext())
	{
		i.next();
		if (i.key() == QString("mainCanvas"))
		{
			getCells();
			i.value()->setCells(&cells);
		}
		else
		{
		}
		//cout << i.key() << ": " << i.value() << endl;
	}
}

void VMainWindow::getCells()
{
	voro::c_loop_order vl(*particlesContainer, *particlesOrder);
	//voro::c_loop_all vl(*particlesContainer);
	voro::voronoicell cell; 
	double *pp;
//	int colorIter = 0;
	QMapIterator<int, VCell *> i(cells);
	if (vl.start()) do if (particlesContainer->compute_cell(cell, vl))
	{
		//cells << new VCell();
		//cells.last()->setColor(cellColors[colorIter++]);
		i.next();

		pp = particlesContainer->p[vl.ijk] + particlesContainer->ps*vl.q;
		double x = *pp, y = pp[1], z = pp[2];
		int index = i.key();
		cells.value(index)->clearFaces();
		//cells.value(index)->setParticle(VPoint(x, y, z));

		std::vector<int> v; 
		cell.face_vertices(v);
		int j, k = 0, l;
		QList<VPoint> face;
		if (v.size() > 0) {
			l = v[k++];
			if (l <= 1) {
				if (l == 1)
				{
					face << VPoint(x + 0.5*cell.pts[3 * v[k]], y + 0.5*cell.pts[3 * v[k] + 1], z + 0.5*cell.pts[3 * v[k] + 2]);
					cells.value(index)->addFace(face);
					face.clear();

					k++;
				}
			}
			else 
			{
				j = k + l;

				face << VPoint(x + 0.5*cell.pts[3 * v[k]], y + 0.5*cell.pts[3 * v[k] + 1], z + 0.5*cell.pts[3 * v[k] + 2]);

				k++;
				while (k < j)
				{
					face << VPoint(x + 0.5*cell.pts[3 * v[k]], y + 0.5*cell.pts[3 * v[k] + 1], z + 0.5*cell.pts[3 * v[k] + 2]);

					k++;
				}
				cells.value(index)->addFace(face);
				face.clear();
			}
			while ((unsigned int)k < v.size()) 
			{
				l = v[k++];
				if (l <= 1) {
					if (l == 1)
					{
						face << VPoint(x + 0.5*cell.pts[3 * v[k]], y + 0.5*cell.pts[3 * v[k] + 1], z + 0.5*cell.pts[3 * v[k] + 2]);

						cells.value(index)->addFace(face);
						face.clear();

						k++;
					}
				}
				else 
				{
					j = k + l;

					face << VPoint(x + 0.5*cell.pts[3 * v[k]], y + 0.5*cell.pts[3 * v[k] + 1], z + 0.5*cell.pts[3 * v[k] + 2]);

					k++;
					while (k < j)
					{
						face << VPoint(x + 0.5*cell.pts[3 * v[k]], y + 0.5*cell.pts[3 * v[k] + 1], z + 0.5*cell.pts[3 * v[k] + 2]);

						k++;
					}
					cells.value(index)->addFace(face);
					face.clear();
				}
			}
		}
	} while (vl.inc());
}


