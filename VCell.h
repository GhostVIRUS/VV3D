#ifndef VCELL_H
#define VCELL_H

#include <QList>
#include <QColor>
#include "VPoint.h"

class VCell
{
public:
	VCell();
	~VCell();

	void addFace(QList<VPoint> &f) { faces << f; }
	void setParticle(VPoint &p) { particle = p; }
	void setColor(QColor &c) { faceColor = c; faceColor.setAlpha(30); }
	void clearFaces() { faces.clear(); }
	int faceCount() const { return faces.size(); }
	const QColor* getColor() const { return &faceColor; }
	const QList<VPoint>* getFace(int i) const { return &faces.at(i); }
	const VPoint* getParticle() const { return &particle; }
private:
	QList<QList<VPoint>> faces;
	VPoint particle;
	QColor faceColor;
};

#endif
