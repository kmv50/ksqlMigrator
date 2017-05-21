#ifndef SETTINGS_H
#define SETTINGS_H
#include <baseclass.h>

class Settings : public BaseClass
{
    Q_OBJECT
public:
    Settings();
    ~Settings();

    // BaseClass interface
public:
    virtual void onLoad() override;
public slots:
    void Save();
    void TestDatasource1();
};

#endif // SETTINGS_H
