#include "id.h"
#include <QHash>

class StringHash
{
public:
    StringHash()
        : hash(0)
    {}

    explicit StringHash(const QByteArray &s)
        : string(s)
        , hash(qHash(s))
    {}

    QByteArray string;
    uint hash;
};

static bool operator==(const StringHash &sh1, const StringHash &sh2)
{
    return sh1.string == sh2.string;
}

static uint qHash(const StringHash &sh)
{
    return sh.hash;
}

static QHash<quintptr, StringHash> stringFromId;
static QHash<StringHash, quintptr> idFromString;


Id::Id(const char *name)
{
    static uint firstUnusedId = 1;

    static QByteArray temp;
    temp.setRawData(name, qstrlen(name));                           // avoid copying data

    StringHash sh(temp);

    int id = idFromString.value(sh, 0);

    if (id == 0) {
        id = firstUnusedId++;
        sh.string = QByteArray(temp.constData(), temp.length());    // copy
        idFromString.insert(sh, id);
        stringFromId.insert(id, sh);
    }

    m_id = id;
}

QByteArray Id::name() const
{
    return stringFromId.value(m_id).string;
}
