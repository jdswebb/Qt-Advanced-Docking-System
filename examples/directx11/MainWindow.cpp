#include "../../examples/directx11/MainWindow.h"

#include "ui_MainWindow.h"

#include <QTime>
#include <QLabel>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the dock manager. Because the parent parameter is a QMainWindow
    // the dock manager registers itself as the central widget.
	m_DockManager = new ads::CDockManager(this);

    m_View1 = new QDirect3D11Widget(this);
    m_View2 = new QDirect3D11Widget(this);

    ads::CDockWidget* DockWidget = new ads::CDockWidget("View 1");
    DockWidget->setWidget(m_View1);
    m_DockManager->addDockWidget(ads::CenterDockWidgetArea, DockWidget);

    ads::CDockWidget* DockWidget2 = new ads::CDockWidget("View 2");
    DockWidget2->setWidget(m_View2);
    m_DockManager->addDockWidget(ads::CenterDockWidgetArea, DockWidget2);

    ads::CDockWidget* DockWidget3 = new ads::CDockWidget("Test");
    DockWidget3->setWidget(new QLabel("Label"));
    m_DockManager->addDockWidget(ads::LeftDockWidgetArea, DockWidget3);

    connect(m_View1, &QDirect3D11Widget::deviceInitialized, this, &MainWindow::init1);
    connect(m_View2, &QDirect3D11Widget::deviceInitialized, this, &MainWindow::init2);

    resize(1280, 800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::init1(bool success)
{
    if (!success)
        return false;
    m_View1->setRenderActive(true);
    disconnect(m_View1, &QDirect3D11Widget::deviceInitialized, this, &MainWindow::init1);
    return true;
}

bool MainWindow::init2(bool success)
{
    if (!success)
        return false;
    m_View2->setRenderActive(true);
    disconnect(m_View2, &QDirect3D11Widget::deviceInitialized, this, &MainWindow::init2);
    return true;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    event->ignore();
    m_View1->release();
    m_View2->release();
    m_bWindowClosing = true;
    QTime dieTime = QTime::currentTime().addMSecs(500);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    event->accept();
}
