/********************************************************************************
** Form generated from reading UI file 'IsoStufferFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISOSTUFFERFRAME_H
#define UI_ISOSTUFFERFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "ui/IsoStufferCanvas.h"

QT_BEGIN_NAMESPACE

class Ui_IsoStufferFrame
{
public:
    QAction *actionLoadBody;
    QAction *actionExportMatlab;
    QAction *actionExportAbaqus;
    QAction *actionModeShapes;
    QAction *actionLoadModes;
    QAction *actionExportMatrices;
    QAction *actionExportSurfaceMesh;
    QAction *actionExportImpulses;
    QAction *actionFacet;
    QAction *actionStep;
    QAction *actionWireframe;
    QAction *actionParams;
    QAction *actionLoad;
    QAction *actionConvert;
    QAction *actionExit;
    QAction *actionCenterize;
    QAction *actionFlipTgl;
    QAction *actionReload;
    QAction *actionSaveMesh;
    QAction *actionExportStellar;
    QAction *actionCheckMesh;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    IsoStufferCanvas *canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuExport;
    QMenu *menuView;
    QMenu *menuProcess;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *IsoStufferFrame)
    {
        if (IsoStufferFrame->objectName().isEmpty())
            IsoStufferFrame->setObjectName(QStringLiteral("IsoStufferFrame"));
        IsoStufferFrame->resize(889, 702);
        IsoStufferFrame->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/fracture.png"), QSize(), QIcon::Normal, QIcon::Off);
        IsoStufferFrame->setWindowIcon(icon);
        actionLoadBody = new QAction(IsoStufferFrame);
        actionLoadBody->setObjectName(QStringLiteral("actionLoadBody"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/load_frac.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadBody->setIcon(icon1);
        actionExportMatlab = new QAction(IsoStufferFrame);
        actionExportMatlab->setObjectName(QStringLiteral("actionExportMatlab"));
        actionExportAbaqus = new QAction(IsoStufferFrame);
        actionExportAbaqus->setObjectName(QStringLiteral("actionExportAbaqus"));
        actionModeShapes = new QAction(IsoStufferFrame);
        actionModeShapes->setObjectName(QStringLiteral("actionModeShapes"));
        actionLoadModes = new QAction(IsoStufferFrame);
        actionLoadModes->setObjectName(QStringLiteral("actionLoadModes"));
        actionExportMatrices = new QAction(IsoStufferFrame);
        actionExportMatrices->setObjectName(QStringLiteral("actionExportMatrices"));
        actionExportSurfaceMesh = new QAction(IsoStufferFrame);
        actionExportSurfaceMesh->setObjectName(QStringLiteral("actionExportSurfaceMesh"));
        actionExportImpulses = new QAction(IsoStufferFrame);
        actionExportImpulses->setObjectName(QStringLiteral("actionExportImpulses"));
        actionFacet = new QAction(IsoStufferFrame);
        actionFacet->setObjectName(QStringLiteral("actionFacet"));
        actionStep = new QAction(IsoStufferFrame);
        actionStep->setObjectName(QStringLiteral("actionStep"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon2);
        actionWireframe = new QAction(IsoStufferFrame);
        actionWireframe->setObjectName(QStringLiteral("actionWireframe"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/grid.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWireframe->setIcon(icon3);
        actionParams = new QAction(IsoStufferFrame);
        actionParams->setObjectName(QStringLiteral("actionParams"));
        actionLoad = new QAction(IsoStufferFrame);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/load.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon4);
        actionConvert = new QAction(IsoStufferFrame);
        actionConvert->setObjectName(QStringLiteral("actionConvert"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConvert->setIcon(icon5);
        actionExit = new QAction(IsoStufferFrame);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionCenterize = new QAction(IsoStufferFrame);
        actionCenterize->setObjectName(QStringLiteral("actionCenterize"));
        actionCenterize->setCheckable(true);
        actionFlipTgl = new QAction(IsoStufferFrame);
        actionFlipTgl->setObjectName(QStringLiteral("actionFlipTgl"));
        actionFlipTgl->setCheckable(true);
        actionReload = new QAction(IsoStufferFrame);
        actionReload->setObjectName(QStringLiteral("actionReload"));
        actionReload->setIcon(icon1);
        actionSaveMesh = new QAction(IsoStufferFrame);
        actionSaveMesh->setObjectName(QStringLiteral("actionSaveMesh"));
        actionExportStellar = new QAction(IsoStufferFrame);
        actionExportStellar->setObjectName(QStringLiteral("actionExportStellar"));
        actionCheckMesh = new QAction(IsoStufferFrame);
        actionCheckMesh->setObjectName(QStringLiteral("actionCheckMesh"));
        centralwidget = new QWidget(IsoStufferFrame);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        canvas = new IsoStufferCanvas(centralwidget);
        canvas->setObjectName(QStringLiteral("canvas"));

        horizontalLayout->addWidget(canvas);

        IsoStufferFrame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IsoStufferFrame);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 889, 27));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuProcess = new QMenu(menubar);
        menuProcess->setObjectName(QStringLiteral("menuProcess"));
        IsoStufferFrame->setMenuBar(menubar);
        statusbar = new QStatusBar(IsoStufferFrame);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        IsoStufferFrame->setStatusBar(statusbar);
        toolBar = new QToolBar(IsoStufferFrame);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        IsoStufferFrame->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuProcess->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(actionCenterize);
        menuFile->addAction(actionFlipTgl);
        menuFile->addAction(actionReload);
        menuFile->addSeparator();
        menuFile->addAction(actionSaveMesh);
        menuFile->addAction(menuExport->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuExport->addAction(actionExportStellar);
        menuView->addAction(actionWireframe);
        menuView->addAction(actionFacet);
        menuProcess->addAction(actionStep);
        menuProcess->addAction(actionConvert);
        menuProcess->addSeparator();
        menuProcess->addAction(actionParams);
        menuProcess->addSeparator();
        menuProcess->addAction(actionCheckMesh);
        toolBar->addSeparator();
        toolBar->addAction(actionLoad);
        toolBar->addAction(actionReload);
        toolBar->addSeparator();
        toolBar->addAction(actionStep);
        toolBar->addAction(actionConvert);
        toolBar->addSeparator();
        toolBar->addAction(actionWireframe);

        retranslateUi(IsoStufferFrame);
        QObject::connect(actionExit, SIGNAL(triggered()), IsoStufferFrame, SLOT(close()));

        QMetaObject::connectSlotsByName(IsoStufferFrame);
    } // setupUi

    void retranslateUi(QMainWindow *IsoStufferFrame)
    {
        IsoStufferFrame->setWindowTitle(QApplication::translate("IsoStufferFrame", "Isosurface Stuffing", Q_NULLPTR));
        actionLoadBody->setText(QApplication::translate("IsoStufferFrame", "Load Rigid Body", Q_NULLPTR));
        actionExportMatlab->setText(QApplication::translate("IsoStufferFrame", "&Export Matlab Data", Q_NULLPTR));
        actionExportAbaqus->setText(QApplication::translate("IsoStufferFrame", "&Export Abaqus Mesh", Q_NULLPTR));
        actionModeShapes->setText(QApplication::translate("IsoStufferFrame", "Mode Shapes", Q_NULLPTR));
        actionLoadModes->setText(QApplication::translate("IsoStufferFrame", "Load Modes", Q_NULLPTR));
        actionExportMatrices->setText(QApplication::translate("IsoStufferFrame", "Export Matrices", Q_NULLPTR));
        actionExportSurfaceMesh->setText(QApplication::translate("IsoStufferFrame", "Export Surface Mesh", Q_NULLPTR));
        actionExportImpulses->setText(QApplication::translate("IsoStufferFrame", "Export Impulses", Q_NULLPTR));
        actionFacet->setText(QApplication::translate("IsoStufferFrame", "&Facet", Q_NULLPTR));
        actionStep->setText(QApplication::translate("IsoStufferFrame", "Step", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionStep->setShortcut(QApplication::translate("IsoStufferFrame", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionWireframe->setText(QApplication::translate("IsoStufferFrame", "&Wire frame", Q_NULLPTR));
        actionParams->setText(QApplication::translate("IsoStufferFrame", "Parameters", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("IsoStufferFrame", "&Load", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionLoad->setShortcut(QApplication::translate("IsoStufferFrame", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionConvert->setText(QApplication::translate("IsoStufferFrame", "Convert", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionConvert->setShortcut(QApplication::translate("IsoStufferFrame", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("IsoStufferFrame", "&Exit", Q_NULLPTR));
        actionCenterize->setText(QApplication::translate("IsoStufferFrame", "Centerize", Q_NULLPTR));
        actionFlipTgl->setText(QApplication::translate("IsoStufferFrame", "Flip triangles", Q_NULLPTR));
        actionReload->setText(QApplication::translate("IsoStufferFrame", "Reload current mesh", Q_NULLPTR));
        actionSaveMesh->setText(QApplication::translate("IsoStufferFrame", "Save tetra mesh", Q_NULLPTR));
        actionExportStellar->setText(QApplication::translate("IsoStufferFrame", "TetGen/Stellar Format", Q_NULLPTR));
        actionCheckMesh->setText(QApplication::translate("IsoStufferFrame", "Check mesh", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("IsoStufferFrame", "&File", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("IsoStufferFrame", "Export", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("IsoStufferFrame", "&View", Q_NULLPTR));
        menuProcess->setTitle(QApplication::translate("IsoStufferFrame", "&Process", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("IsoStufferFrame", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IsoStufferFrame: public Ui_IsoStufferFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISOSTUFFERFRAME_H
