#include "test_klasse_2.h"
#include "qdebug.h"

TestKlasse2::TestKlasse2(QObject *parent) : QObject { parent } { }

void TestKlasse2::testSlot()
{
    qDebug() << "test slot";
}
