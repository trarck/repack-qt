#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "projectinfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool openProject(const QString &fileName);

public slots:
    void browseResourceDirectory();
    void browseProjectDirectory();
    void browseOutputDirectory();
    void browseDataDirectory();
    void browseConfigFile();
    void browseStepFile();

    void createNewProject();
    void openProjectDialog();

public:
    ProjectInfo projectInfo;
private:
    Ui::MainWindow *m_ui;
};

#endif // MAINWINDOW_H
