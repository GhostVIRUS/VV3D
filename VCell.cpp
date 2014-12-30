#include "VCell.h"


VCell::VCell()
{
	faceColor = QColor::fromHsv(rand() % 359 + 0, rand() % 128 + 100, 192 + rand() % 63 + 0);
	faceColor.setAlpha(50);

	isVisible = true;
	vppCell = 0;
}


VCell::~VCell()
{
	delete vppCell;
}

