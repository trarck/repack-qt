#include "actionmanager.h"
#include <QHash>

class ActionManagerPrivate
{
public:
    QHash<Id, QAction*> m_idToAction;
};

static ActionManager *s_instance = nullptr;
static ActionManagerPrivate *d;

ActionManager *ActionManager::instance()
{
    if (!s_instance)
        s_instance = new ActionManager;
    return s_instance;
}

void ActionManager::deleteInstance()
{
    delete s_instance;
    s_instance = nullptr;
}


ActionManager::ActionManager(QObject *parent)
    : QObject(parent)
{
    s_instance = this;
    d = new ActionManagerPrivate;
}

ActionManager::~ActionManager()
{
    delete d;
}

void ActionManager::registerAction(QAction *action, Id id)
{
    Q_ASSERT_X(!d->m_idToAction.contains(id), "ActionManager::registerAction", "duplicate id");
    d->m_idToAction.insert(id, action);
}

QAction *ActionManager::action(Id id)
{
    auto act = d->m_idToAction.value(id);
    Q_ASSERT_X(act, "ActionManager::action", "unknown id");
    return act;
}
