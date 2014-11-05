#include "VCanvas.h"

VCanvas::VCanvas(QWidget *parent)
	: QGLWidget(parent)
{
	setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));

	rotationX = 30.0;
	rotationY = 45.0;
	rotationZ = 0.0;
	scaling = 1;

	drawingData = 0;

}
VCanvas::~VCanvas()
{
}

void VCanvas::initializeGL()
{
	qglClearColor(Qt::white);

	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	//glEnable(GL_MULTISAMPLE);

	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);

	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	//glEnable(GL_COLOR_MATERIAL);

	//glDisable(GL_CULL_FACE);

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glLineWidth(1.0);
	glPointSize(5);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
	//glEnable(GL_POLYGON_OFFSET_LINE);
	//glPolygonOffset(0.0, 5.0);
}

void VCanvas::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = GLfloat(width) / height;
	glFrustum(-x, +x, -1.0, +1.0, 4.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
}

void VCanvas::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -10.0);

	glScalef(scaling, scaling, scaling);

	glRotatef(rotationX, 1.0, 0.0, 0.0);
	glRotatef(rotationY, 0.0, 1.0, 0.0);
	glRotatef(rotationZ, 0.0, 0.0, 1.0);

	drawAxes(30.0);
	if (drawingData != 0)
		drawData();
}

void VCanvas::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
}

void VCanvas::mouseMoveEvent(QMouseEvent *event)
{
	GLfloat dx = GLfloat(event->x() - lastPos.x()) / width();
	GLfloat dy = GLfloat(event->y() - lastPos.y()) / height();

	if (event->buttons() & Qt::LeftButton) {
		rotationX += 180 * dy;
		rotationY += 180 * dx;
		updateGL();
	}
	else if (event->buttons() & Qt::RightButton) {
		rotationX += 180 * dy;
		rotationZ += 180 * dx;
		updateGL();
	}
	lastPos = event->pos();
}

void VCanvas::wheelEvent(QWheelEvent *event)
{
	double numDegrees = -event->delta() / 8.0;
	double numSteps = numDegrees / 15.0;
	scaling *= std::pow(1.125, numSteps);
	updateGL();
}

void VCanvas::mouseDoubleClickEvent(QMouseEvent *event)
{
//	int face = faceAtPosition(event->pos());
//	if (face != -1) {
//		QColor color = QColorDialog::getColor(faceColors[face], this);
//		if (color.isValid()) {
//			faceColors[face] = color;
//			updateGL();
//		}
//	}
	//else
	//{
	/*	for (int i = 1; i < voronoiCells.size(); ++i)
		{
			voronoiCells[i].transparency = voronoiCells[0].transparency ? false : true;
		}
		voronoiCells[0].transparency = voronoiCells[0].transparency ? false : true;
		updateGL();
	}*/
}

void VCanvas::drawAxes(GLdouble length)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	qglColor(Qt::darkBlue);

	renderText(0.3, 0.1, 0.0, QChar('x'));
	for (GLdouble i = 1; i <= length; i = i + 1.0)
	{
 		glBegin(GL_POINTS);
		glVertex3f(i, 0.0, 0.0);
		glVertex3f(-i, 0.0, 0.0);
 		glEnd();

		if ((int)i%5 == 0)
		{
			renderText(i, 0.1, 0.0, QString::number(i));
			renderText(-i, 0.1, 0.0, QString::number(-i));
		}
	}
	glBegin(GL_LINES);
	glVertex3f(-length, 0.0, 0.0);
	glVertex3f(length, 0.0, 0.0);
	glEnd();

	//glPopMatrix();

	//glPushMatrix();
	renderText(0.1, 0.3, 0.0, QChar('y'));
	for (GLdouble i = 1; i <= length; i = i + 1.0)
	{
		glBegin(GL_POINTS);
		glVertex3f(0.0, i, 0.0);
		glVertex3f(0.0, -i, 0.0);
		glEnd();

		if ((int)i % 5 == 0)
		{
			renderText(0.1, i, 0.0, QString::number(i));
			renderText(0.1, -i, 0.0, QString::number(-i));
		}
	}
	glBegin(GL_LINES);
	glVertex3f(0.0, - length, 0.0);
	glVertex3f(0.0, length, 0.0);
	glEnd();

	//glPopMatrix();

	//glPushMatrix();
	renderText(0.0, 0.1, 0.3, QChar('z'));
	for (GLdouble i = 1; i <= length; i = i + 1.0)
	{
		glBegin(GL_POINTS);
		glVertex3f(0.0, 0.0, i);
		glVertex3f(0.0, 0.0, -i);
		glEnd();

		if ((int)i % 5 == 0)
		{
			renderText(0.0, 0.1, i, QString::number(i));
			renderText(0.0, 0.1, -i, QString::number(-i));
		}
	}
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -length);
	glVertex3f(0.0, 0.0, length);
	glEnd();

	glPopMatrix();

	glDisable(GL_BLEND);
}


/*
int VCanvas::faceAtPosition(const QPoint &pos)
{
	const int MaxSize = 512;
	GLuint buffer[MaxSize];
	GLint viewport[4];

	makeCurrent();

	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(MaxSize, buffer);
	glRenderMode(GL_SELECT);

	glInitNames();
	glPushName(0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPickMatrix(GLdouble(pos.x()), GLdouble(viewport[3] - pos.y()),
		5.0, 5.0, viewport);
	GLfloat x = GLfloat(width()) / height();
	glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
//	drawCells();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	if (!glRenderMode(GL_RENDER))
		return -1;
	return buffer[3];
}*/

void VCanvas::drawData()
{/*
	//drawing particles
	qglColor(Qt::red);
	for (int c = 0; c < drawingData->size(); ++c)
	{
		const VPoint *pParticle = drawingData->at(c)->getParticle();
		glBegin(GL_POINTS);
		glVertex3f(pParticle->x, pParticle->y, pParticle->z);
		glEnd();
		renderText(pParticle->x - 0.3, pParticle->y, pParticle->z, QString::number(c+1));
	}
	

	//drawing faces
//	if (!transparency)
//	{
	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int c = 0; c < drawingData->size(); ++c)
	{
		qglColor(*drawingData->at(c)->getColor());
		int fc = drawingData->at(c)->faceCount();
		for (int i = 0; i < fc; ++i)
		{
			//glLoadName(i);
			const QList<VPoint> *pFace = drawingData->at(c)->getFace(i);
			glBegin(GL_POLYGON);
			for (int j = 0; j < pFace->size(); ++j)
			{
				glVertex3f(pFace->at(j).x, pFace->at(j).y, pFace->at(j).z);
			}
			glEnd();
		}
	}
//	}
	glDepthMask(GL_TRUE);

	//drawing face' wires
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	qglColor(Qt::black);
	for (int c = 0; c < drawingData->size(); ++c)
	{
		int fc = drawingData->at(c)->faceCount();
		for (int i = 0; i < fc; ++i) {
			//glLoadName(i);
			const QList<VPoint> *pFace = drawingData->at(c)->getFace(i);
			glBegin(GL_LINE_LOOP);
			for (int j = 0; j < pFace->size(); ++j)
			{
				glVertex3f(pFace->at(j).x, pFace->at(j).y, pFace->at(j).z);
			}
			glEnd();
		}
	}
	glDisable(GL_BLEND);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);*/


	//////////////////////////////////////////////////////////////////////////


	//drawing particles
	QMapIterator<int, VCell *> i(*drawingData);
	qglColor(Qt::red);
	while (i.hasNext())
	{
		i.next();
		const VPoint *pParticle = i.value()->getParticle();
		glBegin(GL_POINTS);
		glVertex3f(pParticle->x, pParticle->y, pParticle->z);
		glEnd();
		renderText(pParticle->x - 0.3, pParticle->y, pParticle->z, QString::number(i.key() + 1));
	}

	//drawing faces
	i = QMapIterator<int, VCell *>(*drawingData);
	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	while (i.hasNext())
	{
		i.next();
		qglColor(*i.value()->getColor());
		int fc = i.value()->faceCount();
		for (int j = 0; j < fc; ++j)
		{
			//glLoadName(i);
			const QList<VPoint> *pFace = i.value()->getFace(j);
			glBegin(GL_POLYGON);
			for (int j = 0; j < pFace->size(); ++j)
			{
				glVertex3f(pFace->at(j).x, pFace->at(j).y, pFace->at(j).z);
			}
			glEnd();
		}
	}

	glDepthMask(GL_TRUE);

	//drawing face' wires
	i = QMapIterator<int, VCell *>(*drawingData);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	qglColor(Qt::black);
	while (i.hasNext())
	{
		i.next();
		int fc = i.value()->faceCount();
		for (int j = 0; j < fc; ++j) {
			//glLoadName(i);
			const QList<VPoint> *pFace = i.value()->getFace(j);
			glBegin(GL_LINE_LOOP);
			for (int j = 0; j < pFace->size(); ++j)
			{
				glVertex3f(pFace->at(j).x, pFace->at(j).y, pFace->at(j).z);
			}
			glEnd();
		}
	}
	glDisable(GL_BLEND);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

