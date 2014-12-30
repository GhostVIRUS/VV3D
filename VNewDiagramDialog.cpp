#include "VNewDiagramDialog.h"

VNewDiagramDialog::VNewDiagramDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//setAttribute(Qt::WA_DeleteOnClose, true);

	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	QPushButton* pCancelButton = ui.buttonBox->button(QDialogButtonBox::Cancel);
	pCancelButton->setText(codec->toUnicode("Скасувати"));
}

VNewDiagramDialog::~VNewDiagramDialog()
{

}


void VNewDiagramDialog::accept()
{
	if (1) //TODO: check, if data is valid
	{
		valuesAccepted(ui.nameLineEdit->text(), 0, 
			VPoint(ui.vertex1xSpin->value(), ui.vertex1ySpin->value(), ui.vertex1zSpin->value()),
			VPoint(ui.vertex2xSpin->value(), ui.vertex2ySpin->value(), ui.vertex2zSpin->value()));
		this->close(); //maybe done will be needed
	}
}

