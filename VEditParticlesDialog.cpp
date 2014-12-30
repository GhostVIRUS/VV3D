#include "VEditParticlesDialog.h"

VEditParticlesDialog::VEditParticlesDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	QPushButton* pCancelButton = ui.buttonBox->button(QDialogButtonBox::Cancel);
	pCancelButton->setText(codec->toUnicode("Скасувати"));
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
	int c = ui.randomCountSpin->value();
	int len = 0; while (c /= 10) ++len;
	if (len == 0) len = 1;
	len = qPow(10, len);
	int temp, tempLen;
	double tempDouble;
	for (int i = 0; i < ui.randomCountSpin->value(); ++i)
	{
		val = maxVals.x - minVals.x; tempLen = 0; while (val < 1) { val *= 10; ++tempLen; }
		tempLen = qPow(10, tempLen);
		len *= tempLen;
		tempDouble = 1 / (double)len;
		val = (double)rand() / RAND_MAX;
		val = minVals.x + tempDouble + val * (maxVals.x - tempDouble - (minVals.x + tempDouble));
		val *= len;
		temp = val;
		val = (double)temp / (double)len;
		dataStr += QString::number(val) + " ";
		len /= tempLen;

		val = maxVals.y - minVals.y; tempLen = 0; while (val < 1) { val *= 10; ++tempLen; }
		tempLen = qPow(10, tempLen);
		len *= tempLen;
		tempDouble = 1 / (double)len;
		val = (double)rand() / RAND_MAX;
		val = minVals.y + tempDouble + val * (maxVals.y - tempDouble - (minVals.y + tempDouble));
		val *= len;
		temp = val;
		val = (double)temp / (double)len;
		dataStr += QString::number(val) + " ";
		len /= tempLen;

		val = maxVals.z - minVals.z; tempLen = 0; while (val < 1) { val *= 10; ++tempLen; }
		tempLen = qPow(10, tempLen);
		len *= tempLen;
		tempDouble = 1 / (double)len;
		val = (double)rand() / RAND_MAX;
		val = minVals.z + tempDouble + val * (maxVals.z - tempDouble - (minVals.z + tempDouble));
		val *= len;
		temp = val;
		val = (double)temp / (double)len;
		dataStr += QString::number(val) + "\n";
		len /= tempLen;
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
