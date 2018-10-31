#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void browseResourceDirectory();
    void browseProjectDirectory();
    void browseOutputDirectory();
    void browseDataDirectory();
    void browseConfigFile();
    void browseStepFile();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
