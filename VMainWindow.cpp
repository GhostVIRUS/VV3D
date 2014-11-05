#include "VMainWindow.h"

VMainWindow::VMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); // applies interface

	particlesContainer = 0;
//	particlesPreContainer = 0;
	particlesOrder = 0;
	ndd = 0;

	ui.mainContent->clear();

	//ui.particlesEditorTable->resizeColumnsToContents();
	ui.particlesEditorTable->resizeRowsToContents();
//	ui.particlesEditorTable->setSiz
}

VMainWindow::~VMainWindow()
{
	delete particlesContainer; //Crash fixed, but possible there is memory leak | Look container_base destructor
//	delete particlesPreContainer;
	delete particlesOrder;

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
		abs(a.x - b.x) * 10, abs(a.y - b.y) * 10, abs(a.z - b.z) * 10, false, false, false, 10);
	particlesOrder = new voro::particle_order();

	ui.addParticle->setEnabled(true);
	ui.deleteParticle->setEnabled(true);

	ui.particlesEditorTable->clear();
	ui.particlesEditorTable->setRowCount(0);
	ui.mainContent->clear();
	canvases.insert(QString("mainCanvas"), new VCanvas(ui.mainContent));
	ui.mainContent->addTab(canvases.last(), name);
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
		err.showMessage(QString("SOME COORDINATES ARE OUT OF CONTAINER!!\n\n\nBITCH!"));
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


