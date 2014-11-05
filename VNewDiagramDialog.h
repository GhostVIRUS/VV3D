#ifndef VNEWDIAGRAMDIALOG_H
#define VNEWDIAGRAMDIALOG_H

#include <QDialog>
#include "ui_newDiagramDialog.h"

#include "VPoint.h"
#include <QString>

class VNewDiagramDialog : public QDialog
{
	Q_OBJECT

public:
	VNewDiagramDialog(QWidget *parent);
	~VNewDiagramDialog();

signals:
	void valuesAccepted(QString name, int type, VPoint a, VPoint b);

public slots:
	void accept();

private:
	Ui::newDiagramDialog ui;
};

#endif // VNEWDIAGRAMDIALOG_H
