/********************************************************************************
** Form generated from reading UI file 'newDiagramDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIAGRAMDIALOG_H
#define UI_NEWDIAGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_newDiagramDialog
{
public:
    QGridLayout *gridLayoutDialog;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *typeLabel;
    QLineEdit *nameLineEdit;
    QComboBox *typeComboBox;
    QGroupBox *parametersGroup;
    QGridLayout *gridLayoutParams;
    QDoubleSpinBox *vertex1xSpin;
    QDoubleSpinBox *vertex1ySpin;
    QLabel *diagonalVertex1Label;
    QDoubleSpinBox *vertex1zSpin;
    QLabel *diagonalVertex2Label;
    QDoubleSpinBox *vertex2zSpin;
    QDoubleSpinBox *vertex2xSpin;
    QDoubleSpinBox *vertex2ySpin;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newDiagramDialog)
    {
        if (newDiagramDialog->objectName().isEmpty())
            newDiagramDialog->setObjectName(QStringLiteral("newDiagramDialog"));
        newDiagramDialog->setWindowModality(Qt::WindowModal);
        newDiagramDialog->resize(640, 480);
        newDiagramDialog->setMinimumSize(QSize(320, 240));
        newDiagramDialog->setMaximumSize(QSize(640, 480));
        gridLayoutDialog = new QGridLayout(newDiagramDialog);
        gridLayoutDialog->setObjectName(QStringLiteral("gridLayoutDialog"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        nameLabel = new QLabel(newDiagramDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setScaledContents(false);
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        typeLabel = new QLabel(newDiagramDialog);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));
        typeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(typeLabel, 2, 0, 1, 1);

        nameLineEdit = new QLineEdit(newDiagramDialog);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 1, 1, 1, 1);

        typeComboBox = new QComboBox(newDiagramDialog);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));
        typeComboBox->setEnabled(false);
        typeComboBox->setMouseTracking(false);
        typeComboBox->setModelColumn(1);

        gridLayout->addWidget(typeComboBox, 2, 1, 1, 1);

        parametersGroup = new QGroupBox(newDiagramDialog);
        parametersGroup->setObjectName(QStringLiteral("parametersGroup"));
        parametersGroup->setAlignment(Qt::AlignCenter);
        parametersGroup->setFlat(false);
        parametersGroup->setCheckable(false);
        gridLayoutParams = new QGridLayout(parametersGroup);
        gridLayoutParams->setObjectName(QStringLiteral("gridLayoutParams"));
        vertex1xSpin = new QDoubleSpinBox(parametersGroup);
        vertex1xSpin->setObjectName(QStringLiteral("vertex1xSpin"));
        vertex1xSpin->setMinimum(-5);
        vertex1xSpin->setMaximum(4);
        vertex1xSpin->setSingleStep(0.5);
        vertex1xSpin->setValue(-5);

        gridLayoutParams->addWidget(vertex1xSpin, 0, 1, 1, 1);

        vertex1ySpin = new QDoubleSpinBox(parametersGroup);
        vertex1ySpin->setObjectName(QStringLiteral("vertex1ySpin"));
        vertex1ySpin->setMinimum(-5);
        vertex1ySpin->setMaximum(4);
        vertex1ySpin->setSingleStep(0.5);
        vertex1ySpin->setValue(-5);

        gridLayoutParams->addWidget(vertex1ySpin, 0, 2, 1, 1);

        diagonalVertex1Label = new QLabel(parametersGroup);
        diagonalVertex1Label->setObjectName(QStringLiteral("diagonalVertex1Label"));

        gridLayoutParams->addWidget(diagonalVertex1Label, 0, 0, 1, 1);

        vertex1zSpin = new QDoubleSpinBox(parametersGroup);
        vertex1zSpin->setObjectName(QStringLiteral("vertex1zSpin"));
        vertex1zSpin->setMinimum(-5);
        vertex1zSpin->setMaximum(4);
        vertex1zSpin->setSingleStep(0.5);
        vertex1zSpin->setValue(-5);

        gridLayoutParams->addWidget(vertex1zSpin, 0, 3, 1, 1);

        diagonalVertex2Label = new QLabel(parametersGroup);
        diagonalVertex2Label->setObjectName(QStringLiteral("diagonalVertex2Label"));

        gridLayoutParams->addWidget(diagonalVertex2Label, 1, 0, 1, 1);

        vertex2zSpin = new QDoubleSpinBox(parametersGroup);
        vertex2zSpin->setObjectName(QStringLiteral("vertex2zSpin"));
        vertex2zSpin->setDecimals(2);
        vertex2zSpin->setMinimum(-4);
        vertex2zSpin->setMaximum(5);
        vertex2zSpin->setSingleStep(0.5);
        vertex2zSpin->setValue(5);

        gridLayoutParams->addWidget(vertex2zSpin, 1, 3, 1, 1);

        vertex2xSpin = new QDoubleSpinBox(parametersGroup);
        vertex2xSpin->setObjectName(QStringLiteral("vertex2xSpin"));
        vertex2xSpin->setDecimals(2);
        vertex2xSpin->setMinimum(-4);
        vertex2xSpin->setMaximum(5);
        vertex2xSpin->setSingleStep(0.5);
        vertex2xSpin->setValue(5);

        gridLayoutParams->addWidget(vertex2xSpin, 1, 1, 1, 1);

        vertex2ySpin = new QDoubleSpinBox(parametersGroup);
        vertex2ySpin->setObjectName(QStringLiteral("vertex2ySpin"));
        vertex2ySpin->setDecimals(2);
        vertex2ySpin->setMinimum(-4);
        vertex2ySpin->setMaximum(5);
        vertex2ySpin->setSingleStep(0.5);
        vertex2ySpin->setValue(5);

        gridLayoutParams->addWidget(vertex2ySpin, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutParams->addItem(verticalSpacer, 2, 0, 1, 4);

        vertex1xSpin->raise();
        vertex1ySpin->raise();
        vertex1zSpin->raise();
        diagonalVertex2Label->raise();
        vertex2xSpin->raise();
        vertex2ySpin->raise();
        vertex2zSpin->raise();
        diagonalVertex1Label->raise();

        gridLayout->addWidget(parametersGroup, 3, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(newDiagramDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMinimumSize(QSize(0, 50));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayoutDialog->addLayout(horizontalLayout, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        nameLabel->setBuddy(nameLineEdit);
        typeLabel->setBuddy(typeComboBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(nameLineEdit, typeComboBox);
        QWidget::setTabOrder(typeComboBox, vertex1xSpin);
        QWidget::setTabOrder(vertex1xSpin, vertex1ySpin);
        QWidget::setTabOrder(vertex1ySpin, vertex1zSpin);
        QWidget::setTabOrder(vertex1zSpin, vertex2xSpin);
        QWidget::setTabOrder(vertex2xSpin, vertex2ySpin);
        QWidget::setTabOrder(vertex2ySpin, vertex2zSpin);

        retranslateUi(newDiagramDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), newDiagramDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newDiagramDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(newDiagramDialog);
    } // setupUi

    void retranslateUi(QDialog *newDiagramDialog)
    {
        newDiagramDialog->setWindowTitle(QApplication::translate("newDiagramDialog", "\320\235\320\276\320\262\320\260\321\217 \320\264\320\270\320\260\320\263\321\200\320\260\320\274\320\260", 0));
        nameLabel->setText(QApplication::translate("newDiagramDialog", "\320\230\320\274\321\217:", 0));
        typeLabel->setText(QApplication::translate("newDiagramDialog", "\320\242\320\270\320\277:", 0));
        nameLineEdit->setText(QApplication::translate("newDiagramDialog", "NewDiagram", 0));
        typeComboBox->setCurrentText(QString());
        parametersGroup->setTitle(QApplication::translate("newDiagramDialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0));
        diagonalVertex1Label->setText(QApplication::translate("newDiagramDialog", "1 \320\262\320\265\321\200\321\210\320\270\320\275\320\260 \320\264\320\270\320\260\320\263\320\276\320\275\320\260\320\273\320\270 (x, y, z):", 0));
        diagonalVertex2Label->setText(QApplication::translate("newDiagramDialog", "2 \320\262\320\265\321\200\321\210\320\270\320\275\320\260 \320\264\320\270\320\260\320\263\320\276\320\275\320\260\320\273\320\270 (x, y, z):", 0));
    } // retranslateUi

};

namespace Ui {
    class newDiagramDialog: public Ui_newDiagramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIAGRAMDIALOG_H
