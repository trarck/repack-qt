#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>

namespace Ui {
class StartWidget;
}

class StartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();

public slots:
    void createNewProject();
    void openProjectDialog();
private:
    Ui::StartWidget *m_ui;
};

#endif // STARTWIDGET_H
