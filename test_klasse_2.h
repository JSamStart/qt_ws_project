#pragma once

#include <QObject>

class TestKlasse2 : public QObject
{
    Q_OBJECT
public:
    explicit TestKlasse2(QObject *parent = nullptr);

signals:

public slots:
    void testSlot(void);
};
