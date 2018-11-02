#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QJsonObject>
#include <QJsonDocument>
#include "mainwindow.h"

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::NewProjectDialog)
{
    m_ui->setupUi(this);

    connect(m_ui->rdBrowseButton,&QPushButton::clicked,
            this,&NewProjectDialog::browseResourceDirectory);

    connect(m_ui->pdBrowseButton,&QPushButton::clicked,
            this,&NewProjectDialog::browseProjectDirectory);

    connect(m_ui->odBrowseButton,&QPushButton::clicked,
            this,&NewProjectDialog::browseOutputDirectory);

    connect(m_ui->ddBrowseButton,&QPushButton::clicked,
            this,&NewProjectDialog::browseDataDirectory);
}

NewProjectDialog::~NewProjectDialog()
{
    delete m_ui;
}

void NewProjectDialog::createProject(MainWindow* mainWidow)
{
    if (exec() == QDialog::Accepted)
    {
        qDebug("ok");

        QString dir = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
        QString fileName = QFileDialog::getSaveFileName(mainWidow, QString(),
                                                dir);

        if (!fileName.isEmpty())
        {
            QFile saveFile(fileName.toLatin1());

            if (!saveFile.open(QIODevice::WriteOnly)) {

            }

            mainWidow->projectInfo.mainProjectPath=m_ui->projectDirectoryEdit->text().toLatin1();
            mainWidow->projectInfo.resourcePath=m_ui->resourceDirectoryEdit->text().toLatin1();
            mainWidow->projectInfo.outputPath=m_ui->outputDirectoryEdit->text().toLatin1();
            mainWidow->projectInfo.dataPath=m_ui->dataDirectoryEdit->text().toLatin1();

            QJsonObject projectObject;
            projectObject["mainProjectPath"]=mainWidow->projectInfo.mainProjectPath;
            projectObject["resourcePath"]=mainWidow->projectInfo.resourcePath;
            projectObject["outputPath"]=mainWidow->projectInfo.outputPath;
            projectObject["dataPath"]=mainWidow->projectInfo.dataPath;

            QJsonDocument saveDoc(projectObject);
            saveFile.write(saveDoc.toJson());
        }
    }
}


void NewProjectDialog::browseResourceDirectory()
{
    QString caption = tr("Select Resource Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->resourceDirectoryEdit->setText(directoryName);
}

void NewProjectDialog::browseProjectDirectory()
{
    QString caption = tr("Select Matrix Project Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->projectDirectoryEdit->setText(directoryName);
}

void NewProjectDialog::browseOutputDirectory()
{
    QString caption = tr("Select Output Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->outputDirectoryEdit->setText(directoryName);
}

void NewProjectDialog::browseDataDirectory()
{
    QString caption = tr("Select Data Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->dataDirectoryEdit->setText(directoryName);
}
