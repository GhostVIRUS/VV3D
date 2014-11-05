#ifndef VOROGL_H
#define VOROGL_H

//#include <QtWidgets/QMainWindow>
#include <QtGui>
#include "voro++/container.hh"
#include "voro++/pre_container.hh"
#include "voro++/c_loops.hh"

#include "ui_mainWindow.h"
#include "VNewDiagramDialog.h"
#include "VPoint.h"
#include "VCanvas.h"
#include "VCell.h"

class VMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	VMainWindow(QWidget *parent = 0);
	~VMainWindow();

public slots:
	void createNewFile(QString name, int type, VPoint a, VPoint b);
	void newFile();
	//void updateParticles();
	void updateParticle(int row, double x, double y, double z);
	void deleteParticle(int row);

private:
	void updateContainer(int added = -1);
	bool checkParticle(double x, double y, double z);
	void getCells();
	//void getCell();
	void updateContent();

	Ui::mainWindow ui; // contains objects and settings for user interface

	VNewDiagramDialog *ndd;

	//QList<VCanvas *> canvases;
	QMap<QString, VCanvas *> canvases;
	//QMap<int, VPoint> particles;
	QPair<VPoint, VPoint> containerBorders;

	voro::container *particlesContainer;
	voro::particle_order *particlesOrder;
//	voro::pre_container *particlesPreContainer;

	//QList<VCell *> cells;
	QMap<int, VCell *> cells;
};

#endif // VOROGL_H
