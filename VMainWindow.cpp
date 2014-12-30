#include "VMainWindow.h"

VMainWindow::VMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); // applies interface

	particlesContainer = 0;
	particlesOrder = 0;
	ndd = 0;
	epd = 0;

	//ui.mainContent->clear();

	ui.particlesEditorTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.cellsViewerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	codec = QTextCodec::codecForName("Windows-1251");

	ui.initalImageLabel->setStyleSheet("background-color: #646464");
}

VMainWindow::~VMainWindow()
{
	delete particlesContainer; //Crash fixed, but possible there is memory leak | Look container_base destructor
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
		abs(a.x - b.x) * 1 + 1, abs(a.y - b.y) * 1 + 1, abs(a.z - b.z) * 1 + 1, false, false, false, 8);
	particlesOrder = new voro::particle_order();

	ui.addParticle->setEnabled(true);
	ui.deleteParticle->setEnabled(true);
	ui.editParticlesAction->setEnabled(true);
	ui.toggleParticlesNumbersVisibilityAction->setEnabled(true);
	ui.toggleAxesVisibilityAction->setEnabled(true);
	ui.toggleParticlesNumbersVisibilityAction->setChecked(true);
	ui.toggleAxesVisibilityAction->setChecked(true);

	ui.particlesEditorTable->clear();
	ui.particlesEditorTable->setHorizontalHeaderLabels(QStringList() << "x" << "y" << "z");
	ui.particlesEditorTable->setRowCount(0);
	
	ui.cellsViewerTable->clear();
	ui.cellsViewerTable->setHorizontalHeaderLabels(QStringList() << codec->toUnicode("Колір") << codec->toUnicode("Видимість") << codec->toUnicode("Інформ."));
	ui.cellsViewerTable->setRowCount(0);

	ui.mainContent->clear();
	canvases.insert(QString("mainCanvas"), new VCanvas(ui.mainContent));
	ui.mainContent->addTab(canvases.last(), name);
	double lengthX, lengthY, lengthZ;
	lengthX = qMax(qAbs(a.x), qAbs(b.x));
	lengthY = qMax(qAbs(a.y), qAbs(b.y));
	lengthZ = qMax(qAbs(a.z), qAbs(b.z));

	canvases.value(QString("mainCanvas"))->setAxesLength(qMax(lengthX, qMax(lengthY, lengthZ))+1);
	canvases.value(QString("mainCanvas"))->setScaling(2/qMax(lengthX, qMax(lengthY, lengthZ)));
	canvases.value(QString("mainCanvas"))->setDefaultScaling(2/qMax(lengthX, qMax(lengthY, lengthZ)));

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
	ui.cellsViewerTable->clear();
	ui.cellsViewerTable->setHorizontalHeaderLabels(QStringList() << codec->toUnicode("Колір") << codec->toUnicode("Видимість") << codec->toUnicode("Інформ."));
	ui.cellsViewerTable->setRowCount(0);

	ui.particlesEditorTable->clear();
	ui.particlesEditorTable->setRowCount(particles.size());
	ui.particlesEditorTable->setHorizontalHeaderLabels(QStringList() << "x" << "y" << "z");
	for (int i = 0; i < particles.size(); ++i)
	{
		if (checkParticle(particles[i]->x, particles[i]->y, particles[i]->z))
		{
			ui.particlesEditorTable->setItem(i, 0, new QTableWidgetItem(QString::number(particles[i]->x)));
			ui.particlesEditorTable->setItem(i, 1, new QTableWidgetItem(QString::number(particles[i]->y)));
			ui.particlesEditorTable->setItem(i, 2, new QTableWidgetItem(QString::number(particles[i]->z)));
		}
		else
		{
			QErrorMessage err;
			err.showMessage(QString("SOME COORDINATES ARE OUT OF CONTAINER!"));
			err.exec(); //stops program and shows the message
		}
	}
}


void VMainWindow::updateParticle(int row, double x, double y, double z)
{
	if (checkParticle(x, y, z))
	{
		if (!cells.contains(row))
		{
			cells[row] = new VCell;
			ui.cellsViewerTable->addCell(row, cells[row]->getColor());
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
	if (ui.particlesEditorTable->item(row, 0) != 0 &&
		ui.particlesEditorTable->item(row, 1) != 0 &&
		ui.particlesEditorTable->item(row, 2) != 0)
	{
		bool *chX = new bool, *chY = new bool, *chZ = new bool;
		ui.particlesEditorTable->item(row, 0)->text().toDouble(chX);
		ui.particlesEditorTable->item(row, 1)->text().toDouble(chY);
		ui.particlesEditorTable->item(row, 2)->text().toDouble(chZ);
		if (*chX && *chY && *chZ)
		{
			delete cells.value(row);
			cells.remove(row);
		}
	}
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

	ui.particlesEditorTable->removeRow(row);
	ui.cellsViewerTable->removeRow(row);

	if (cells.size() > 0)
	{
		updateContainer();
	}
	else
		canvases.value(QString("mainCanvas"))->updateGL();
}


void VMainWindow::updateContainer(int added)
{
	delete particlesOrder;
	particlesOrder = new voro::particle_order();
	particlesContainer->clear();

	QMapIterator<int, VCell *> i(cells);
	while (i.hasNext())
	{
		i.next();
		//fill container
		const VPoint *pParticle = i.value()->getParticle();
		particlesContainer->put(*particlesOrder, i.key(), pParticle->x, pParticle->y, pParticle->z);
	}
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
	}
}

void VMainWindow::getCells()
{
	voro::c_loop_order vl(*particlesContainer, *particlesOrder);
	voro::voronoicell cell; 
	double *pp;
	QMapIterator<int, VCell *> i(cells);
	if (vl.start()) do if (particlesContainer->compute_cell(cell, vl))
	{
		i.next();

		//voro::voronoicell *pCell = new voro::voronoicell(cell);
		pp = particlesContainer->p[vl.ijk] + particlesContainer->ps*vl.q;
		double x = *pp, y = pp[1], z = pp[2];
		//int index = i.key();
		i.value()->clearFaces();
		//i.value()->setVoroPPCell(pCell);

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
					i.value()->addFace(face);
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
				i.value()->addFace(face);
				face.clear();
			}
			while ((unsigned int)k < v.size()) 
			{
				l = v[k++];
				if (l <= 1) {
					if (l == 1)
					{
						face << VPoint(x + 0.5*cell.pts[3 * v[k]], y + 0.5*cell.pts[3 * v[k] + 1], z + 0.5*cell.pts[3 * v[k] + 2]);

						i.value()->addFace(face);
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
					i.value()->addFace(face);
					face.clear();
				}
			}
		}
	} while (vl.inc());

}

void VMainWindow::changeCellColor(int id, QColor color)
{
	if (cells.contains(id))
	{
		cells.value(id)->setColor(color);
		canvases.value(QString("mainCanvas"))->updateGL();
	}
}

void VMainWindow::toggleCellVisibility(int id)
{
	if (cells.contains(id))
	{
		cells.value(id)->toggleVisibity();
		canvases.value(QString("mainCanvas"))->updateGL();
	}
}

void VMainWindow::showCellInfo(int id)
{
	double x = cells.value(id)->getParticle()->x;
	double y = cells.value(id)->getParticle()->y;
	double z = cells.value(id)->getParticle()->z;

	voro::c_loop_order vl(*particlesContainer, *particlesOrder);
	voro::voronoicell voroCell;
	if (vl.start())
	{
		for (double *pp; ; vl.inc())
		{
			pp = particlesContainer->p[vl.ijk] + particlesContainer->ps*vl.q;
			if (x == *pp && y == pp[1] && z == pp[2])
				break;
		}
	}
	particlesContainer->compute_cell(voroCell, vl);

	QTextEdit *pCellInfoContainer = new QTextEdit(ui.mainContent);
	pCellInfoContainer->setFontPointSize(12);
	pCellInfoContainer->setReadOnly(true);
	QString infoString;
	
	infoString += codec->toUnicode("Координати частинки: (") + QString::number(x) + "; " +
		QString::number(y) + "; " +
		QString::number(z) + ")";
	infoString += "\n--------------------------------------------------------------\n\n" +
		codec->toUnicode("Кількість вершин в комірці: ") + QString::number(voroCell.p) + "\n" +
		codec->toUnicode("Координати вершин: ");
	std::vector<double> vecDouble;
	voroCell.vertices(x, y, z, vecDouble);
	for (int i = 0; i < vecDouble.size(); i += 3)
	{
		infoString += "(" + QString::number(vecDouble[i]) + "; " + QString::number(vecDouble[i+1]) + "; " + QString::number(vecDouble[i+2]) + ") ";
	}
	infoString += "\n--------------------------------------------------------------\n\n" +
		codec->toUnicode("Кількість ребер в комірці: ") + QString::number(voroCell.number_of_edges()) + "\n" +
		codec->toUnicode("Сумарна довжина усіх ребер: ") + QString::number(voroCell.total_edge_distance());
		
	infoString += "\n--------------------------------------------------------------\n\n" +
		codec->toUnicode("Кількість граней: ") + QString::number(voroCell.number_of_faces()) + "\n" +
		codec->toUnicode("Номери вершин, що входять до кожної з граней: ");
	std::vector<int> v;
	voroCell.face_vertices(v);
	int j, k = 0, l;
	if (v.size() > 0) {
		l = v[k++];
		if (l <= 1) {
			if (l == 1)
			{
				infoString += "(" + QString::number(v[k++]) + ") ";
			}
			else
			{
				infoString += "( ) ";
			}
		}
		else
		{
			j = k + l;
			infoString += "(" + QString::number(v[k++]);
			while (k < j)
			{
				infoString += ", " + QString::number(v[k++]);
			}
			infoString += ") ";
		}
		while ((unsigned int)k < v.size())
		{
			l = v[k++];
			if (l <= 1) {
				if (l == 1)
				{
					infoString += "(" + QString::number(v[k++]) + ") ";
				}
				else
				{
					infoString += "( ) ";
				}
			}
			else
			{
				j = k + l;
				infoString += "(" + QString::number(v[k++]);
				while (k < j)
				{
					infoString += ", " + QString::number(v[k++]);
				}
				infoString += ") ";
			}
		}
	}
	vecDouble.clear();
	voroCell.face_perimeters(vecDouble);
	infoString += codec->toUnicode("\nПериметри граней: ");
	for (int i = 0; i < vecDouble.size(); ++i)
	{
		infoString += QString::number(vecDouble[i]) + " | ";
	}
	infoString += codec->toUnicode("\nПлоща поверхні: ") + QString::number(voroCell.surface_area()) + "\n";
	vecDouble.clear();
	voroCell.face_areas(vecDouble);
	infoString += codec->toUnicode("Площі граней: ");
	for (int i = 0; i < vecDouble.size(); ++i)
	{
		infoString += QString::number(vecDouble[i]) + " | ";
	}
	infoString += "\n--------------------------------------------------------------\n\n" +
		codec->toUnicode("Об'єм: ") + QString::number(voroCell.volume());

	pCellInfoContainer->setPlainText(infoString);
	QString header = codec->toUnicode("Інформація про ") + QString::number(id + 1) + codec->toUnicode(" комірку");
	ui.mainContent->addTab(pCellInfoContainer, header);
}

void VMainWindow::closeContentTab(int id)
{
	if (ui.mainContent->widget(id) != canvases.value(QString("mainCanvas")))
	{
		ui.mainContent->removeTab(id);
	}
}

void VMainWindow::toggleParticlesNumbersVisibility()
{
	if (!canvases.isEmpty())
		canvases.value(QString("mainCanvas"))->toggleParticlesNumbersVisibility();
}

void VMainWindow::restoreDefaultView()
{
	if (!canvases.isEmpty())
		canvases.value(QString("mainCanvas"))->restoreDefaultView();
}

void VMainWindow::keyPressEvent(QKeyEvent *event)
{
	if (!canvases.isEmpty())
		canvases.value(QString("mainCanvas"))->keyPressed(event->text());
}

void VMainWindow::toggleAxesVisibility()
{
	if (!canvases.isEmpty())
		canvases.value(QString("mainCanvas"))->toggleAxesVisibility();
}


