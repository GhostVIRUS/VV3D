#include "VEditParticlesDialog.h"

VEditParticlesDialog::VEditParticlesDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

VEditParticlesDialog::~VEditParticlesDialog()
{

}

void VEditParticlesDialog::accept()
{
	QString dataStr = ui.particlesTextEditor->toPlainText();
	if (!dataStr.isEmpty()) 
	{
		QStringList dataStrListLines = dataStr.split("\n", QString::SkipEmptyParts);
		/*for (int i = 0; i < dataStrListLines.size(); ++i)
		{

		}
		QStringList dataStrList = dataStrListLines.split(" ", QString::SkipEmptyParts);
		QList<VPoint *> dataPointsList;
		for (int i = 2; i < dataStrList.size(); i += 3)
		{
			dataPointsList << new VPoint(dataStrList[i - 2].toDouble(), dataStrList[i - 1].toDouble(), dataStrList[i].toDouble());
		}*/
		QList<VPoint *> dataPointsList;
		QStringList dataStrLine;
		for (int i = 0; i < dataStrListLines.size(); ++i)
		{
			dataStrLine = dataStrListLines[i].split(" ", QString::SkipEmptyParts);
			if (dataStrLine.size() == 3)
			{
				dataPointsList << new VPoint(dataStrLine[0].toDouble(), dataStrLine[1].toDouble(), dataStrLine[2].toDouble());
			}
		}

		valuesAccepted(dataPointsList);
		qDeleteAll(dataPointsList);
		this->close();
	}
}

void VEditParticlesDialog::setRandomParticles()
{
	ui.particlesTextEditor->clear();

	QString dataStr;
	double val;
	for (int i = 0; i < ui.randomCountSpin->value(); ++i)
	{
		val = (double)rand() / RAND_MAX;
		val = minVals.x + val * (maxVals.x - minVals.x);
		dataStr += QString::number(val) + " ";

		val = (double)rand() / RAND_MAX;
		val = minVals.y + val * (maxVals.y - minVals.y);
		dataStr += QString::number(val) + " ";

		val = (double)rand() / RAND_MAX;
		val = minVals.z + val * (maxVals.z - minVals.z);
		dataStr += QString::number(val) + "\n";
	}

	ui.particlesTextEditor->setPlainText(dataStr);
}

void VEditParticlesDialog::setData(QList<const VPoint *> particles)
{
	ui.particlesTextEditor->clear();

	QString dataStr;
	for (int i = 0; i < particles.size(); ++i)
	{
		dataStr += QString::number(particles[i]->x) + " "
				+  QString::number(particles[i]->y) + " "
				+  QString::number(particles[i]->z) + "\n";
	}
	
	ui.particlesTextEditor->setPlainText(dataStr);
}
