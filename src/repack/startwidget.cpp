#include "startwidget.h"
#include "ui_startwidget.h"
#include <QAction>
#include "actionmanager.h"

StartWidget::StartWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::StartWidget)
{
    m_ui->setupUi(this);

    connect(m_ui->newProjectButton,&QPushButton::clicked,this,&StartWidget::createNewProject);
    connect(m_ui->openProjectButton,&QPushButton::clicked,this,&StartWidget::openProjectDialog);
}

StartWidget::~StartWidget()
{
    delete m_ui;
}

void StartWidget::createNewProject()
{
    ActionManager::action("file.new_project")->trigger();
}

void StartWidget::openProjectDialog()
{
    ActionManager::action("file.open_project")->trigger();
}
