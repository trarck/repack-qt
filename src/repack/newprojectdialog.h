#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

class MainWindow;

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = nullptr);
    ~NewProjectDialog();

    void createProject(MainWindow* mainWidow);
protected slots:
    void browseResourceDirectory();
    void browseProjectDirectory();
    void browseOutputDirectory();
    void browseDataDirectory();

private:
    Ui::NewProjectDialog *m_ui;
};

#endif // NEWPROJECTDIALOG_H
