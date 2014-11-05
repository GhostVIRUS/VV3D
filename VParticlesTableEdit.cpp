#include "VParticlesTableEdit.h"

VParticlesTableEdit::VParticlesTableEdit(QWidget *parent)
	: QTableWidget(parent)
{
	setColumnCount(3);
	setHorizontalHeaderLabels(QStringList() << "x" << "y" << "z");
}

VParticlesTableEdit::~VParticlesTableEdit()
{

}

void VParticlesTableEdit::addRow()
{
	insertRow(rowCount());
}

void VParticlesTableEdit::deleteRow()
{
	if (item(currentRow(), 0) != 0 && item(currentRow(), 1) != 0 && item(currentRow(), 2) != 0)
	{
		bool *chX = new bool, *chY = new bool, *chZ = new bool;
		//double x, y, z;
		/*x = */item(currentRow(), 0)->text().toDouble(chX);
		/*y = */item(currentRow(), 1)->text().toDouble(chY);
		/*z = */item(currentRow(), 2)->text().toDouble(chZ);
		if (*chX && *chY && *chZ)
		{
			particleDeleted(currentRow());
		}
	}
	removeRow(currentRow());
}

void VParticlesTableEdit::checkRow(int row, int column)
{
	if (item(row, 0) != 0 && item(row, 1) != 0 && item(row, 2) != 0)
	{
		bool *chX = new bool, *chY = new bool, *chZ = new bool;
		double x, y, z;
		x = item(row, 0)->text().toDouble(chX);
		y = item(row, 1)->text().toDouble(chY);
		z = item(row, 2)->text().toDouble(chZ);
		if (*chX && *chY && *chZ)
		{
			particleChanged(row, x, y, z);
		}
		else
		{
			particleDeleted(row);
			//alarm
		}
	}
}

/*
void VParticlesTableEdit::checkData()
{
	bool isAllValid = true;
	for (int i = 0; i < rowCount(); ++i)
	{
		
		if (item(i, 0) != 0 && item(i, 1) != 0 && item(i, 2) != 0)
		{
			bool *chX = new bool, *chY = new bool, *chZ = new bool;
			double x, y, z;
			x = item(i, 0)->text().toDouble(chX);
			y = item(i, 1)->text().toDouble(chY);
			z = item(i, 2)->text().toDouble(chZ);
			if (*chX && *chY && *chZ)
			{
			}
			else
			{
				isAllValid = false;
				break;
			}
		}
		else
		{
			isAllValid = false;
			break;
		}
	}
	if (isAllValid)
	{
		void dataChanged();
	}
}
*/
