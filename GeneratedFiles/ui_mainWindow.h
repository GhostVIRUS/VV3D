/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "VCanvas.h"
#include "VCellsViewerTable.h"
#include "VParticlesEditTable.h"

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
    QAction *toggleCellsViewerAction;
    QAction *getDiagramInfoAction;
    QAction *getCellInfoAction;
    QAction *toggleParticlesNumbersVisibilityAction;
    QAction *restoreCameraDefaultViewAction;
    QAction *toggleAxesVisibilityAction;
    QAction *toggleFullscreenAction;
    QWidget *centralWidget;
    QGridLayout *windowGridLayout;
    QTabWidget *mainContent;
    VCanvas *initalContentWrapper;
    QHBoxLayout *horizontalLayout;
    QLabel *initalImageLabel;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *edit;
    QMenu *view;
    QDockWidget *particlesEditor;
    QWidget *particlesEditorWrapper;
    QGridLayout *gridLayout;
    QToolButton *addParticle;
    QToolButton *deleteParticle;
    VParticlesEditTable *particlesEditorTable;
    QDockWidget *cellsViewer;
    QWidget *cellsViewerWrapper;
    QVBoxLayout *verticalLayout;
    VCellsViewerTable *cellsViewerTable;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(800, 619);
        mainWindow->setMinimumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/v_res/Resources/icons/voro_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainWindow->setWindowIcon(icon);
        mainWindow->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        newDiagramAction = new QAction(mainWindow);
        newDiagramAction->setObjectName(QStringLiteral("newDiagramAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/v_res/Resources/icons/document_16.png"), QSize(), QIcon::Normal, QIcon::Off);
        newDiagramAction->setIcon(icon1);
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
        exit->setMenuRole(QAction::QuitRole);
        editParticlesAction = new QAction(mainWindow);
        editParticlesAction->setObjectName(QStringLiteral("editParticlesAction"));
        editParticlesAction->setCheckable(false);
        editParticlesAction->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/v_res/Resources/icons/application_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editParticlesAction->setIcon(icon2);
        toggleParticleEditorAction = new QAction(mainWindow);
        toggleParticleEditorAction->setObjectName(QStringLiteral("toggleParticleEditorAction"));
        toggleParticleEditorAction->setCheckable(true);
        toggleParticleEditorAction->setChecked(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/v_res/Resources/icons/note_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        toggleParticleEditorAction->setIcon(icon3);
        toggleCellsViewerAction = new QAction(mainWindow);
        toggleCellsViewerAction->setObjectName(QStringLiteral("toggleCellsViewerAction"));
        toggleCellsViewerAction->setCheckable(true);
        toggleCellsViewerAction->setChecked(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/v_res/Resources/icons/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        toggleCellsViewerAction->setIcon(icon4);
        getDiagramInfoAction = new QAction(mainWindow);
        getDiagramInfoAction->setObjectName(QStringLiteral("getDiagramInfoAction"));
        getCellInfoAction = new QAction(mainWindow);
        getCellInfoAction->setObjectName(QStringLiteral("getCellInfoAction"));
        toggleParticlesNumbersVisibilityAction = new QAction(mainWindow);
        toggleParticlesNumbersVisibilityAction->setObjectName(QStringLiteral("toggleParticlesNumbersVisibilityAction"));
        toggleParticlesNumbersVisibilityAction->setCheckable(true);
        toggleParticlesNumbersVisibilityAction->setChecked(true);
        toggleParticlesNumbersVisibilityAction->setEnabled(false);
        restoreCameraDefaultViewAction = new QAction(mainWindow);
        restoreCameraDefaultViewAction->setObjectName(QStringLiteral("restoreCameraDefaultViewAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/v_res/Resources/icons/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        restoreCameraDefaultViewAction->setIcon(icon5);
        restoreCameraDefaultViewAction->setMenuRole(QAction::ApplicationSpecificRole);
        toggleAxesVisibilityAction = new QAction(mainWindow);
        toggleAxesVisibilityAction->setObjectName(QStringLiteral("toggleAxesVisibilityAction"));
        toggleAxesVisibilityAction->setCheckable(true);
        toggleAxesVisibilityAction->setChecked(true);
        toggleAxesVisibilityAction->setEnabled(false);
        toggleFullscreenAction = new QAction(mainWindow);
        toggleFullscreenAction->setObjectName(QStringLiteral("toggleFullscreenAction"));
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
        initalContentWrapper = new VCanvas();
        initalContentWrapper->setObjectName(QStringLiteral("initalContentWrapper"));
        horizontalLayout = new QHBoxLayout(initalContentWrapper);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        initalImageLabel = new QLabel(initalContentWrapper);
        initalImageLabel->setObjectName(QStringLiteral("initalImageLabel"));
        initalImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/v_res/Resources/inital.png")));
        initalImageLabel->setScaledContents(false);
        initalImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(initalImageLabel);

        mainContent->addTab(initalContentWrapper, QString());

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
        mainWindow->setMenuBar(menuBar);
        particlesEditor = new QDockWidget(mainWindow);
        particlesEditor->setObjectName(QStringLiteral("particlesEditor"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(particlesEditor->sizePolicy().hasHeightForWidth());
        particlesEditor->setSizePolicy(sizePolicy);
        particlesEditor->setWindowIcon(icon3);
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
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/v_res/Resources/icons/plus_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        addParticle->setIcon(icon6);
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
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/v_res/Resources/icons/delete_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteParticle->setIcon(icon7);
        deleteParticle->setIconSize(QSize(24, 24));
        deleteParticle->setPopupMode(QToolButton::DelayedPopup);
        deleteParticle->setToolButtonStyle(Qt::ToolButtonIconOnly);
        deleteParticle->setAutoRaise(true);
        deleteParticle->setArrowType(Qt::NoArrow);

        gridLayout->addWidget(deleteParticle, 0, 1, 1, 1);

        particlesEditorTable = new VParticlesEditTable(particlesEditorWrapper);
        particlesEditorTable->setObjectName(QStringLiteral("particlesEditorTable"));
        particlesEditorTable->setGridStyle(Qt::SolidLine);
        particlesEditorTable->setSortingEnabled(false);
        particlesEditorTable->horizontalHeader()->setCascadingSectionResizes(false);
        particlesEditorTable->horizontalHeader()->setDefaultSectionSize(50);

        gridLayout->addWidget(particlesEditorTable, 1, 0, 1, 3);

        particlesEditor->setWidget(particlesEditorWrapper);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), particlesEditor);
        cellsViewer = new QDockWidget(mainWindow);
        cellsViewer->setObjectName(QStringLiteral("cellsViewer"));
        cellsViewer->setAcceptDrops(false);
        cellsViewer->setWindowIcon(icon4);
        cellsViewer->setFloating(false);
        cellsViewerWrapper = new QWidget();
        cellsViewerWrapper->setObjectName(QStringLiteral("cellsViewerWrapper"));
        verticalLayout = new QVBoxLayout(cellsViewerWrapper);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 3, 0, 6);
        cellsViewerTable = new VCellsViewerTable(cellsViewerWrapper);
        if (cellsViewerTable->columnCount() < 3)
            cellsViewerTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        cellsViewerTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        cellsViewerTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        cellsViewerTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        cellsViewerTable->setObjectName(QStringLiteral("cellsViewerTable"));
        cellsViewerTable->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(cellsViewerTable);

        cellsViewer->setWidget(cellsViewerWrapper);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), cellsViewer);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(edit->menuAction());
        menuBar->addAction(view->menuAction());
        file->addAction(newDiagramAction);
        file->addSeparator();
        file->addAction(exit);
        edit->addAction(editParticlesAction);
        view->addAction(toggleParticleEditorAction);
        view->addAction(toggleCellsViewerAction);
        view->addSeparator();
        view->addAction(toggleParticlesNumbersVisibilityAction);
        view->addAction(toggleAxesVisibilityAction);
        view->addSeparator();
        view->addAction(restoreCameraDefaultViewAction);
        view->addSeparator();
        view->addAction(toggleFullscreenAction);

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
        QObject::connect(toggleCellsViewerAction, SIGNAL(triggered(bool)), cellsViewer, SLOT(setVisible(bool)));
        QObject::connect(cellsViewer, SIGNAL(visibilityChanged(bool)), toggleCellsViewerAction, SLOT(setChecked(bool)));
        QObject::connect(cellsViewerTable, SIGNAL(cellVisibilityToggled(int)), mainWindow, SLOT(toggleCellVisibility(int)));
        QObject::connect(cellsViewerTable, SIGNAL(cellColorChanged(int,QColor)), mainWindow, SLOT(changeCellColor(int,QColor)));
        QObject::connect(cellsViewerTable, SIGNAL(cellInfoCalled(int)), mainWindow, SLOT(showCellInfo(int)));
        QObject::connect(mainContent, SIGNAL(tabCloseRequested(int)), mainWindow, SLOT(closeContentTab(int)));
        QObject::connect(toggleParticlesNumbersVisibilityAction, SIGNAL(triggered()), mainWindow, SLOT(toggleParticlesNumbersVisibility()));
        QObject::connect(restoreCameraDefaultViewAction, SIGNAL(triggered()), mainWindow, SLOT(restoreDefaultView()));
        QObject::connect(exit, SIGNAL(triggered()), mainWindow, SLOT(close()));
        QObject::connect(toggleFullscreenAction, SIGNAL(triggered(bool)), mainWindow, SLOT(showFullScreen()));
        QObject::connect(toggleAxesVisibilityAction, SIGNAL(triggered()), mainWindow, SLOT(toggleAxesVisibility()));

        mainContent->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "Voronoi Viewer 3D", 0));
        newDiagramAction->setText(QApplication::translate("mainWindow", "\320\235\320\276\320\262\320\260 \320\264\321\226\320\260\320\263\321\200\320\260\320\274\320\260", 0));
        newDiagramAction->setShortcut(QApplication::translate("mainWindow", "Ctrl+N", 0));
        openAction->setText(QApplication::translate("mainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        newWindowAction->setText(QApplication::translate("mainWindow", "\320\235\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276", 0));
        saveAction->setText(QApplication::translate("mainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        saveAsAction->setText(QApplication::translate("mainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272 ...", 0));
        exit->setText(QApplication::translate("mainWindow", "\320\222\320\270\320\271\321\202\320\270", 0));
        editParticlesAction->setText(QApplication::translate("mainWindow", "\320\222\321\205\321\226\320\264\320\275\321\226 \320\264\320\260\320\275\320\275\321\226", 0));
        editParticlesAction->setShortcut(QApplication::translate("mainWindow", "Ctrl+E", 0));
        toggleParticleEditorAction->setText(QApplication::translate("mainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\262\321\205\321\226\320\264\320\275\320\270\321\205 \320\264\320\260\320\275\320\275\320\270\321\205", 0));
        toggleCellsViewerAction->setText(QApplication::translate("mainWindow", "\320\232\320\276\320\274\321\226\321\200\320\272\320\270", 0));
        getDiagramInfoAction->setText(QApplication::translate("mainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\270\320\260\320\263\321\200\320\260\320\274\320\265", 0));
        getCellInfoAction->setText(QApplication::translate("mainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\217\321\207\320\265\320\271\320\272\320\265", 0));
        toggleParticlesNumbersVisibilityAction->setText(QApplication::translate("mainWindow", "\320\235\320\276\320\274\320\265\321\200\320\260 \321\207\320\260\321\201\321\202\320\270\320\275\320\276\320\272", 0));
        restoreCameraDefaultViewAction->setText(QApplication::translate("mainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\275\321\217 \320\272\320\260\320\274\320\265\321\200\320\270 \320\267\320\260 \321\203\320\274\320\276\320\262\321\207\320\260\320\275\320\275\321\217\320\274", 0));
        toggleAxesVisibilityAction->setText(QApplication::translate("mainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\275\321\226 \320\262\321\226\321\201\321\226", 0));
        toggleFullscreenAction->setText(QApplication::translate("mainWindow", "\320\237\320\276\320\262\320\275\320\276\320\265\320\272\321\200\320\260\320\275\320\275\320\270\320\271 \321\200\320\265\320\266\320\270\320\274", 0));
        toggleFullscreenAction->setShortcut(QApplication::translate("mainWindow", "F11", 0));
        initalImageLabel->setText(QString());
        mainContent->setTabText(mainContent->indexOf(initalContentWrapper), QApplication::translate("mainWindow", "\320\237\320\276\321\207\320\260\321\202\320\272\320\276\320\262\320\260 \321\201\321\202\320\276\321\200\321\226\320\275\320\272\320\260", 0));
        file->setTitle(QApplication::translate("mainWindow", "\320\244\320\260\320\271\320\273", 0));
        edit->setTitle(QApplication::translate("mainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", 0));
        view->setTitle(QApplication::translate("mainWindow", "\320\222\320\270\320\264", 0));
        particlesEditor->setWindowTitle(QApplication::translate("mainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\207\320\260\321\201\321\202\320\270\320\275\320\276\320\272", 0));
        addParticle->setText(QString());
        deleteParticle->setText(QString());
        cellsViewer->setWindowTitle(QApplication::translate("mainWindow", "\320\232\320\276\320\274\321\226\321\200\320\272\320\270", 0));
        QTableWidgetItem *___qtablewidgetitem = cellsViewerTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mainWindow", "\320\232\320\276\320\273\321\226\321\200", 0));
        QTableWidgetItem *___qtablewidgetitem1 = cellsViewerTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mainWindow", "\320\222\320\270\320\264\320\270\320\274\321\226\321\201\321\202\321\214", 0));
        QTableWidgetItem *___qtablewidgetitem2 = cellsViewerTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("mainWindow", "\320\206\320\275\321\204\320\276\321\200\320\274.", 0));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
