#include "VCanvas.h"

VCanvas::VCanvas(QWidget *parent)
	: QGLWidget(parent)
{
	setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));

	rotationX = 30.0; defaultRotationX = 30.0;
	rotationY = 45.0; defaultRotationY = 45.0;
	rotationZ = 0.0; defaultRotationZ = 0.0;
	scaling = 1;
	defaultScaling = 1;

	drawingData = 0;

	translX = 0.0; translY = 0.0; translZ = 0.0;

	areParticlesNumbersVisible = true;
	areAxesVisible = true;

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
	glPointSize(4);

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

	qglColor(Qt::darkBlue);

	glBegin(GL_POINTS);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glScalef(scaling, scaling, scaling);

	glRotatef(rotationX, 1.0, 0.0, 0.0);
	glRotatef(rotationY, 0.0, 1.0, 0.0);
	glRotatef(rotationZ, 0.0, 0.0, 1.0);

	glTranslatef(translX, translY, translZ); //

	//drawAxes(axesLength);
	if (drawingData != 0)
		drawData();
	if (areAxesVisible)
		drawAxes(axesLength);
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
	updateGL();
}

void VCanvas::drawAxes(GLdouble length)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	qglColor(Qt::darkCyan);

	renderText(length, 0.1, 0.0, QChar('x'));
	for (GLdouble i = 1; i <= length-1; i = i + 1.0)
	{
 		glBegin(GL_POINTS);
		glVertex3f(i, 0.0, 0.0);
		glVertex3f(-i, 0.0, 0.0);
 		glEnd();

		if ((int)i % 1 == 0)
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
	qglColor(Qt::darkYellow);
	renderText(0.1, length, 0.0, QChar('y'));
	for (GLdouble i = 1; i <= length-1; i = i + 1.0)
	{
		glBegin(GL_POINTS);
		glVertex3f(0.0, i, 0.0);
		glVertex3f(0.0, -i, 0.0);
		glEnd();

		if ((int)i % 1 == 0)
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
	qglColor(Qt::darkMagenta);
	renderText(0.0, 0.1, length, QChar('z'));
	for (GLdouble i = 1; i <= length-1; i = i + 1.0)
	{
		glBegin(GL_POINTS);
		glVertex3f(0.0, 0.0, i);
		glVertex3f(0.0, 0.0, -i);
		glEnd();

		if ((int)i % 1 == 0)
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

void VCanvas::drawData()
{
	//drawing particles
	QMapIterator<int, VCell *> i(*drawingData);
	qglColor(Qt::red);
	while (i.hasNext())
	{
		i.next();
		if (1)
		{
			const VPoint *pParticle = i.value()->getParticle();
			glBegin(GL_POINTS);
			glVertex3f(pParticle->x, pParticle->y, pParticle->z);
			glEnd();
			if (areParticlesNumbersVisible)
				renderText(pParticle->x + 0.05 / defaultScaling, pParticle->y + 0.05 / defaultScaling, pParticle->z + 0.05 / defaultScaling, QString::number(i.key() + 1));
		}
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
		if (i.value()->getVisibility())
		{
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
		if (i.value()->getVisibility())
		{
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
	}
	glDisable(GL_BLEND);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void VCanvas::keyPressed(QString key)
{
	if (key == "z")
		translX += 0.1;
	else if (key == "a")
		translX -= 0.1;
	else if (key == "x")
		translY += 0.1;
	else if (key == "s")
		translY -= 0.1;
	else if (key == "c")
		translZ += 0.1;
	else if (key == "d")
		translZ -= 0.1;
	updateGL();
}

