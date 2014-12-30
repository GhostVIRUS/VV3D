#ifndef VCELL_H
#define VCELL_H

#include <QList>
#include <QColor>
#include "VPoint.h"
#include <voro++/cell.hh>

class VCell
{
public:
	VCell();
	~VCell();

	void addFace(QList<VPoint> &f) { faces << f; }
	void setParticle(VPoint &p) { particle = p; }
	void setColor(QColor &c) { faceColor = c; faceColor.setAlpha(50); }
	void setVisibility(bool val) { isVisible = val; }
	void toggleVisibity() { isVisible = !isVisible; }
	void clearFaces() { faces.clear(); }
	int faceCount() const { return faces.size(); }
	const QColor* getColor() const { return &faceColor; }
	const QList<VPoint>* getFace(int i) const { return &faces.at(i); }
	const VPoint* getParticle() const { return &particle; }
	bool getVisibility() { return isVisible; }
private:
	QList<QList<VPoint>> faces;
	VPoint particle;
	QColor faceColor;
	voro::voronoicell *vppCell;
	bool isVisible;
};

#endif
