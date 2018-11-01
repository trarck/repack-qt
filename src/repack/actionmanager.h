#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H
#include <QObject>
#include "id.h"

class QAction;

class MainWindow;

class ActionManager : public QObject
{
    Q_OBJECT
public:
    static ActionManager *instance();
    static void deleteInstance();

    static void registerAction(QAction *action, Id id);

    static QAction *action(Id id);

signals:
    void actionAdded(Id id);

private:
    explicit ActionManager(QObject *parent = nullptr);
    ~ActionManager();

    friend class MainWindow;   // creation
};

#endif // ACTIONMANAGER_H
