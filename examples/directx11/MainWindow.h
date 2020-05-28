#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DockManager.h"
#include "QDirect3D11Widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);
    ~MainWindow();

    void adjustWindowSize();

private:
    void closeEvent(QCloseEvent* event) override;


public Q_SLOTS:
    bool init1(bool success);
    bool init2(bool success);


private:
    Ui::MainWindow*    ui;
    QDirect3D11Widget* m_View1;
    QDirect3D11Widget* m_View2;
    ads::CDockManager* m_DockManager;
    bool               m_bWindowClosing;
};

#endif // MAINWINDOW_H
