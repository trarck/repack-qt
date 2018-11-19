#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStandardPaths>
#include "newprojectdialog.h"
#include "actionmanager.h"
#include "startwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    ActionManager::instance();

    m_ui->setupUi(this);

    ActionManager::registerAction(m_ui->actionNewProject, "file.new_project");
    ActionManager::registerAction(m_ui->actionOpen, "file.open_project");

//    connect(m_ui->rdBrowseButton,&QPushButton::clicked,
//            this,&MainWindow::browseResourceDirectory);

//    connect(m_ui->pdBrowseButton,&QPushButton::clicked,
//            this,&MainWindow::browseProjectDirectory);

//    connect(m_ui->odBrowseButton,&QPushButton::clicked,
//            this,&MainWindow::browseOutputDirectory);

//    connect(m_ui->ddBrowseButton,&QPushButton::clicked,
//            this,&MainWindow::browseDataDirectory);

//    connect(m_ui->cfBrowseButton,&QPushButton::clicked,
//            this,&MainWindow::browseConfigFile);

//    connect(m_ui->sfBrowseButton,&QPushButton::clicked,
//            this,&MainWindow::browseStepFile);

//    connect(m_ui->createProjectButton,&QPushButton::clicked,
//            this,&MainWindow::createNewProject);

    StartWidget* startWidget=new StartWidget(this);
    setCentralWidget(startWidget);

    m_ui->actionNewProject->setShortcuts(QKeySequence::New);
    m_ui->actionOpen->setShortcuts(QKeySequence::Open);

    connect(m_ui->actionNewProject,&QAction::triggered, this,&MainWindow::createNewProject);
    connect(m_ui->actionOpen,&QAction::triggered, this,&MainWindow::openProjectDialog);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::browseResourceDirectory()
{
    QString caption = tr("Select Resource Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->resourceDirectoryEdit->setText(directoryName);
}

void MainWindow::browseProjectDirectory()
{
    QString caption = tr("Select Matrix Project Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->projectDirectoryEdit->setText(directoryName);
}

void MainWindow::browseOutputDirectory()
{
    QString caption = tr("Select Output Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->outputDirectoryEdit->setText(directoryName);
}

void MainWindow::browseDataDirectory()
{
    QString caption = tr("Select Data Directory");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString directoryName = QFileDialog::getExistingDirectory(this, caption, dir,
                            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!directoryName.isEmpty())
        m_ui->dataDirectoryEdit->setText(directoryName);
}

void MainWindow::browseConfigFile()
{
    QString caption = tr("Select Config File");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
    QString fileName = QFileDialog::getOpenFileName(this, caption, dir);

    if (!fileName.isEmpty())
        m_ui->configFileEdit->setText(fileName);
}

void MainWindow::browseStepFile()
{
    QString caption = tr("Select Step File");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
    QString fileName = QFileDialog::getOpenFileName(this, caption, dir);

    if (!fileName.isEmpty())
        m_ui->stepFileEdit->setText(fileName);
}

void MainWindow::createNewProject()
{
    qDebug("call crate new");
    NewProjectDialog newProjectDialog(this);
    newProjectDialog.createProject(this);
}

void MainWindow::openProjectDialog()
{
    QString caption = tr("Select Config File");
    QString dir = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
    QString fileName = QFileDialog::getOpenFileName(this, caption, dir);

    if (!fileName.isEmpty()){
        openProject(fileName);
    }
}

bool MainWindow::openProject(const QString &fileName)
{
    qDebug("Open project file %s",fileName.data());
    return true;
}
