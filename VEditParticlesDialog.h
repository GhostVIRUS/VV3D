#ifndef VEDITPARTICLESDIALOG_H
#define VEDITPARTICLESDIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include "VPoint.h"
#include <QList>
#include "ui_editParticlesDialog.h"

class VEditParticlesDialog : public QDialog
{
	Q_OBJECT

public:
	VEditParticlesDialog(QWidget *parent);
	~VEditParticlesDialog();

	void setData(QList<const VPoint *> particles);
	void setMinMax(VPoint &a, VPoint &b) { minVals = a; maxVals = b; }

signals:
	void valuesAccepted(QList<VPoint *> particles);

public slots:
	void accept();
	void setRandomParticles();

private:
	Ui::editParticlesDialog ui;
	VPoint minVals, maxVals;

};

#endif // VEDITPARTICLESDIALOG_H
