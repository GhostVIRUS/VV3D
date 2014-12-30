#ifndef VCANVAS_H
#define VCANVAS_H

#include <QGLWidget>
#include <voro++/container.hh>

#include <QtOpenGL>
#include <GL/glu.h>

#include "VCell.h"

class VCanvas : public QGLWidget
{
	Q_OBJECT
public:
	VCanvas(QWidget *parent = 0);
	~VCanvas();

	void setCells(QMap<int, VCell *> *cells) { drawingData = cells; updateGL(); }
	void setAxesLength(double lenght) { axesLength = lenght; }
	void setScaling(float scl) { scaling = scl; }
	void setDefaultScaling(float scl) { defaultScaling = scl; }
	void restoreDefaultView() { scaling = defaultScaling; 
								rotationX = defaultRotationX; rotationY = defaultRotationY; rotationZ = defaultRotationZ;
								translX = 0.0; translY = 0.0; translZ = 0.0; updateGL(); }

	void toggleParticlesNumbersVisibility() { areParticlesNumbersVisible = !areParticlesNumbersVisible; updateGL(); }
	void toggleAxesVisibility() { areAxesVisible = !areAxesVisible; updateGL(); }
	void keyPressed(QString key);

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	//void keyPressEvent(QKeyEvent *event);

private:
	void drawData();
	void drawAxes(GLdouble length);
	int faceAtPosition(const QPoint &pos);

	GLfloat rotationX, defaultRotationX;
	GLfloat rotationY, defaultRotationY;
	GLfloat rotationZ, defaultRotationZ;
	QPoint lastPos;
	GLfloat scaling, defaultScaling;
	GLfloat translX, translY, translZ;
	
	GLdouble axesLength;

	QMap<int, VCell *> *drawingData;

	bool areParticlesNumbersVisible, areAxesVisible;
};

#endif //VCANVAS_H