#ifndef VOROGL_H
#define VOROGL_H

#include <QtGui>
#include "voro++/container.hh"
#include "voro++/c_loops.hh"

#include "ui_mainWindow.h"
#include "VNewDiagramDialog.h"
#include "VEditParticlesDialog.h"
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

	void updateParticle(int row, double x, double y, double z);
	void deleteParticle(int row);
	void editParticles();
	void updateParticles(QList<VPoint *> particles);

	void changeCellColor(int id, QColor color);
	void toggleCellVisibility(int id);
//	void setCellVisibility(int id, bool state);
	void toggleParticlesNumbersVisibility();
	void toggleAxesVisibility();

	void restoreDefaultView();

	void showCellInfo(int id);

	void closeContentTab(int id);


public:
	QTextCodec *codec;

protected:
	void keyPressEvent(QKeyEvent *event);

private:
	void updateContainer(int added = -1);
	bool checkParticle(double x, double y, double z);
	void getCells();
	void updateContent();

	Ui::mainWindow ui; // contains objects and settings for user interface

	VNewDiagramDialog *ndd;
	VEditParticlesDialog *epd;

	QMap<QString, VCanvas *> canvases;
	QPair<VPoint, VPoint> containerBorders;

	voro::container *particlesContainer;
	voro::particle_order *particlesOrder;

	QMap<int, VCell *> cells;
};

#endif // VOROGL_H
