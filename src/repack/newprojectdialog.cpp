#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

#include <QJsonObject>

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::NewProjectDialog)
{
    m_ui->setupUi(this);
}

NewProjectDialog::~NewProjectDialog()
{
    delete m_ui;
}

void NewProjectDialog::createProject()
{
    if (exec() != QDialog::Accepted){
        qDebug("cancel");
    }else{
        qDebug("ok");
    }
}
