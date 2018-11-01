#include "preferences.h"
#include <QSettings>

static Preferences *s_instance=nullptr;

Preferences *Preferences::instance()
{
    if (!s_instance)
        s_instance = new Preferences;
    return s_instance;
}

void Preferences::deleteInstance()
{
    delete s_instance;
    s_instance = nullptr;
}

Preferences::Preferences()
    : mSettings(new QSettings(this))
{

}

Preferences::~Preferences()
{
}
