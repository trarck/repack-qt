#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rdBrowseButton,&QPushButton::clicked,
            this,&MainWindow::browseResourceDirectory);

    connect(ui->pdBrowseButton,&QPushButton::clicked,
            this,&MainWindow::browseProjectDirectory);

    connect(ui->odBrowseButton,&QPushButton::clicked,
            this,&MainWindow::browseOutputDirectory);

    connect(ui->ddBrowseButton,&QPushButton::clicked,
            this,&MainWindow::browseDataDirectory);

    connect(ui->cfBrowseButton,&QPushButton::clicked,
            this,&MainWindow::browseConfigFile);

    connect(ui->sfBrowseButton,&QPushButton::clicked,
            this,&MainWindow::browseStepFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::browseResourceDirectory()
{
    QString caption = tr("Select Resource Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        ui->resourceDirectoryEdit->setText(directoryName);
}

void MainWindow::browseProjectDirectory()
{
    QString caption = tr("Select Matrix Project Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        ui->projectDirectoryEdit->setText(directoryName);
}

void MainWindow::browseOutputDirectory()
{
    QString caption = tr("Select Output Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        ui->outputDirectoryEdit->setText(directoryName);
}

void MainWindow::browseDataDirectory()
{
    QString caption = tr("Select Data Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        ui->dataDirectoryEdit->setText(directoryName);
}

void MainWindow::browseConfigFile()
{
    QString caption = tr("Select Config File");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
    QString fileName = QFileDialog::getOpenFileName(this, caption, dir);

    if (!fileName.isEmpty())
        ui->configFileEdit->setText(fileName);
}

void MainWindow::browseStepFile()
{
    QString caption = tr("Select Step File");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
    QString fileName = QFileDialog::getOpenFileName(this, caption, dir);

    if (!fileName.isEmpty())
        ui->stepFileEdit->setText(fileName);
}
