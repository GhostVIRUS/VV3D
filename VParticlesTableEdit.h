#ifndef VPARTICLESTABLEEDIT_H
#define VPARTICLESTABLEEDIT_H

#include <QTableWidget>
#include <QList>

class VParticlesTableEdit : public QTableWidget
{
	Q_OBJECT

public:
	VParticlesTableEdit(QWidget *parent);
	~VParticlesTableEdit();

signals:
	void particleChanged(int row, double x, double y, double z);
	void particleDeleted(int row);

public slots:
	void addRow();
	void deleteRow();
	void checkRow(int row, int column);

//protected slots:
//	void checkData();

private:
	
};

#endif // VPARTICLESTABLEEDIT_H
