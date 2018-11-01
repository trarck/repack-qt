#ifndef ID_H
#define ID_H

#include <QLatin1String>

class Id
{
public:
    Id(const char *name);

    QByteArray name() const;

    bool operator==(Id id) const { return m_id == id.m_id; }
    bool operator!=(Id id) const { return m_id != id.m_id; }

private:
    uint m_id;

    friend uint qHash(Id id) Q_DECL_NOTHROW;
};


inline uint qHash(Id id) Q_DECL_NOTHROW
{
    return id.m_id;
}


#endif // ID_H
