#include <VMainWindow.h>
#include <voro++/container.hh>
#include <QtWidgets/QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
	//voro::container vd(-3, 3, -3, 3, -3, 3, 30, 30, 30, false, false, false, 10);

	//vd.put(0, 1, 1, -1);
	//vd.put(1, -1, 0, 0);

	//vd.draw_particles("thefk_p.gnu");

	//vd.draw_cells_gnuplot("thefk_v.gnu");

	QApplication a(argc, argv);
	a.setStyle(QStyleFactory::create("Fusion"));
	/*QPalette p;
	p = a.palette();
	p.setColor(QPalette::Window, QColor(53, 53, 53));
	p.setColor(QPalette::Button, QColor(53, 53, 53));
	p.setColor(QPalette::Highlight, QColor(142, 45, 197));
	p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
	a.setPalette(p);*/
	VMainWindow mw;
	mw.showMaximized();
	return a.exec();
}
