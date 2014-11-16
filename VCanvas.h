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

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);

private:
	void drawData();
	void drawAxes(GLdouble length);
	int faceAtPosition(const QPoint &pos);

	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat rotationZ;
	QPoint lastPos;
	GLfloat scaling;
	
	GLdouble axesLength;

	QMap<int, VCell *> *drawingData;
};

#endif //VCANVAS_H