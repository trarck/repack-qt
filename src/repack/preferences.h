#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QObject>
class QSettings;

class Preferences : public QObject
{
    Q_OBJECT
public:
    static Preferences *instance();
    static void deleteInstance();

    QSettings *settings() const { return mSettings; }

public slots:

private:
    Preferences();
    ~Preferences() override;

    QSettings *mSettings;
};

#endif // PREFERENCES_H
