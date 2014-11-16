/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "VCanvas.h"
#include "VParticlesTableEdit.h"

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *newDiagramAction;
    QAction *openAction;
    QAction *newWindowAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exit;
    QAction *editParticlesAction;
    QAction *toggleParticleEditorAction;
    QWidget *centralWidget;
    QGridLayout *windowGridLayout;
    QTabWidget *mainContent;
    VCanvas *mainCanvas;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *edit;
    QMenu *view;
    QMenu *settings;
    QMenu *tools;
    QMenu *windows;
    QMenu *ref;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QDockWidget *particlesEditor;
    QWidget *particlesEditorWrapper;
    QGridLayout *gridLayout;
    QToolButton *addParticle;
    QToolButton *deleteParticle;
    VParticlesTableEdit *particlesEditorTable;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(800, 619);
        mainWindow->setMinimumSize(QSize(800, 600));
        newDiagramAction = new QAction(mainWindow);
        newDiagramAction->setObjectName(QStringLiteral("newDiagramAction"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/v_res/Resources/icons/document_16.png"), QSize(), QIcon::Normal, QIcon::Off);
        newDiagramAction->setIcon(icon);
        newDiagramAction->setMenuRole(QAction::ApplicationSpecificRole);
        openAction = new QAction(mainWindow);
        openAction->setObjectName(QStringLiteral("openAction"));
        newWindowAction = new QAction(mainWindow);
        newWindowAction->setObjectName(QStringLiteral("newWindowAction"));
        saveAction = new QAction(mainWindow);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        saveAsAction = new QAction(mainWindow);
        saveAsAction->setObjectName(QStringLiteral("saveAsAction"));
        exit = new QAction(mainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        editParticlesAction = new QAction(mainWindow);
        editParticlesAction->setObjectName(QStringLiteral("editParticlesAction"));
        editParticlesAction->setCheckable(false);
        editParticlesAction->setEnabled(false);
        toggleParticleEditorAction = new QAction(mainWindow);
        toggleParticleEditorAction->setObjectName(QStringLiteral("toggleParticleEditorAction"));
        toggleParticleEditorAction->setCheckable(true);
        centralWidget = new QWidget(mainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        windowGridLayout = new QGridLayout(centralWidget);
        windowGridLayout->setSpacing(6);
        windowGridLayout->setContentsMargins(11, 11, 11, 11);
        windowGridLayout->setObjectName(QStringLiteral("windowGridLayout"));
        windowGridLayout->setContentsMargins(-1, -1, -1, 6);
        mainContent = new QTabWidget(centralWidget);
        mainContent->setObjectName(QStringLiteral("mainContent"));
        mainContent->setTabPosition(QTabWidget::North);
        mainContent->setTabShape(QTabWidget::Rounded);
        mainContent->setElideMode(Qt::ElideNone);
        mainContent->setDocumentMode(false);
        mainContent->setTabsClosable(true);
        mainContent->setMovable(true);
        mainCanvas = new VCanvas();
        mainCanvas->setObjectName(QStringLiteral("mainCanvas"));
        mainContent->addTab(mainCanvas, QString());

        windowGridLayout->addWidget(mainContent, 0, 0, 1, 1);

        mainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        file = new QMenu(menuBar);
        file->setObjectName(QStringLiteral("file"));
        edit = new QMenu(menuBar);
        edit->setObjectName(QStringLiteral("edit"));
        view = new QMenu(menuBar);
        view->setObjectName(QStringLiteral("view"));
        settings = new QMenu(menuBar);
        settings->setObjectName(QStringLiteral("settings"));
        tools = new QMenu(menuBar);
        tools->setObjectName(QStringLiteral("tools"));
        windows = new QMenu(menuBar);
        windows->setObjectName(QStringLiteral("windows"));
        ref = new QMenu(menuBar);
        ref->setObjectName(QStringLiteral("ref"));
        mainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(mainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(mainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        mainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        particlesEditor = new QDockWidget(mainWindow);
        particlesEditor->setObjectName(QStringLiteral("particlesEditor"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(particlesEditor->sizePolicy().hasHeightForWidth());
        particlesEditor->setSizePolicy(sizePolicy);
        particlesEditor->setFloating(false);
        particlesEditorWrapper = new QWidget();
        particlesEditorWrapper->setObjectName(QStringLiteral("particlesEditorWrapper"));
        gridLayout = new QGridLayout(particlesEditorWrapper);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(1);
        gridLayout->setContentsMargins(6, 0, 0, 6);
        addParticle = new QToolButton(particlesEditorWrapper);
        addParticle->setObjectName(QStringLiteral("addParticle"));
        addParticle->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/v_res/Resources/icons/plus_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        addParticle->setIcon(icon1);
        addParticle->setIconSize(QSize(24, 24));
        addParticle->setCheckable(false);
        addParticle->setChecked(false);
        addParticle->setAutoRepeat(false);
        addParticle->setPopupMode(QToolButton::DelayedPopup);
        addParticle->setAutoRaise(true);

        gridLayout->addWidget(addParticle, 0, 0, 1, 1);

        deleteParticle = new QToolButton(particlesEditorWrapper);
        deleteParticle->setObjectName(QStringLiteral("deleteParticle"));
        deleteParticle->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/v_res/Resources/icons/delete_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteParticle->setIcon(icon2);
        deleteParticle->setIconSize(QSize(24, 24));
        deleteParticle->setPopupMode(QToolButton::DelayedPopup);
        deleteParticle->setToolButtonStyle(Qt::ToolButtonIconOnly);
        deleteParticle->setAutoRaise(true);
        deleteParticle->setArrowType(Qt::NoArrow);

        gridLayout->addWidget(deleteParticle, 0, 1, 1, 1);

        particlesEditorTable = new VParticlesTableEdit(particlesEditorWrapper);
        particlesEditorTable->setObjectName(QStringLiteral("particlesEditorTable"));
        particlesEditorTable->setGridStyle(Qt::SolidLine);
        particlesEditorTable->setSortingEnabled(false);
        particlesEditorTable->horizontalHeader()->setCascadingSectionResizes(false);
        particlesEditorTable->horizontalHeader()->setDefaultSectionSize(50);

        gridLayout->addWidget(particlesEditorTable, 1, 0, 1, 3);

        particlesEditor->setWidget(particlesEditorWrapper);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), particlesEditor);
        toolBar_2 = new QToolBar(mainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        mainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(edit->menuAction());
        menuBar->addAction(view->menuAction());
        menuBar->addAction(settings->menuAction());
        menuBar->addAction(tools->menuAction());
        menuBar->addAction(windows->menuAction());
        menuBar->addAction(ref->menuAction());
        file->addAction(newDiagramAction);
        file->addAction(newWindowAction);
        file->addSeparator();
        file->addAction(openAction);
        file->addSeparator();
        file->addAction(saveAction);
        file->addAction(saveAsAction);
        file->addSeparator();
        file->addAction(exit);
        edit->addAction(editParticlesAction);
        view->addAction(toggleParticleEditorAction);
        toolBar->addAction(newDiagramAction);

        retranslateUi(mainWindow);
        QObject::connect(newDiagramAction, SIGNAL(triggered()), mainWindow, SLOT(newFile()));
        QObject::connect(toggleParticleEditorAction, SIGNAL(triggered(bool)), particlesEditor, SLOT(setVisible(bool)));
        QObject::connect(particlesEditor, SIGNAL(visibilityChanged(bool)), toggleParticleEditorAction, SLOT(setChecked(bool)));
        QObject::connect(addParticle, SIGNAL(clicked()), particlesEditorTable, SLOT(addRow()));
        QObject::connect(deleteParticle, SIGNAL(clicked()), particlesEditorTable, SLOT(deleteRow()));
        QObject::connect(particlesEditorTable, SIGNAL(cellChanged(int,int)), particlesEditorTable, SLOT(checkRow(int,int)));
        QObject::connect(particlesEditorTable, SIGNAL(particleChanged(int,double,double,double)), mainWindow, SLOT(updateParticle(int,double,double,double)));
        QObject::connect(particlesEditorTable, SIGNAL(particleDeleted(int)), mainWindow, SLOT(deleteParticle(int)));
        QObject::connect(editParticlesAction, SIGNAL(triggered()), mainWindow, SLOT(editParticles()));

        mainContent->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "Voronoi Viewer 3D", 0));
        newDiagramAction->setText(QApplication::translate("mainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\264\320\270\320\260\320\263\321\200\320\260\320\274\320\274\320\260", 0));
        openAction->setText(QApplication::translate("mainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        newWindowAction->setText(QApplication::translate("mainWindow", "\320\235\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276", 0));
        saveAction->setText(QApplication::translate("mainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        saveAsAction->setText(QApplication::translate("mainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272 ...", 0));
        exit->setText(QApplication::translate("mainWindow", "\320\222\321\213\320\271\321\202\320\270", 0));
        editParticlesAction->setText(QApplication::translate("mainWindow", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", 0));
        toggleParticleEditorAction->setText(QApplication::translate("mainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\262\321\205\320\276\320\264\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        mainContent->setTabText(mainContent->indexOf(mainCanvas), QApplication::translate("mainWindow", "Main Canvas", 0));
        file->setTitle(QApplication::translate("mainWindow", "\320\244\320\260\320\271\320\273", 0));
        edit->setTitle(QApplication::translate("mainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", 0));
        view->setTitle(QApplication::translate("mainWindow", "\320\222\320\270\320\264", 0));
        settings->setTitle(QApplication::translate("mainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        tools->setTitle(QApplication::translate("mainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", 0));
        windows->setTitle(QApplication::translate("mainWindow", "\320\236\320\272\320\275\320\260", 0));
        ref->setTitle(QApplication::translate("mainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
        toolBar->setWindowTitle(QApplication::translate("mainWindow", "toolBar", 0));
        particlesEditor->setWindowTitle(QApplication::translate("mainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\207\320\260\321\201\321\202\320\270\321\206", 0));
        addParticle->setText(QString());
        deleteParticle->setText(QString());
        toolBar_2->setWindowTitle(QApplication::translate("mainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
