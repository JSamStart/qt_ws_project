#include "test_klasse.h"
#include "qdebug.h"
#include "test_klasse_2.h"

TestKlasse::TestKlasse(QObject *parent) : QObject { parent }
{
    TestKlasse2 *tk2 = new TestKlasse2(this);
    connect(this, &TestKlasse::testChanged, tk2, &TestKlasse2::testSlot);
}

bool TestKlasse::getTest() const
{
    return m_test;
}

void TestKlasse::setTest(bool value)
{
    if (m_test == value)
        return;
    m_test = value;
    emit testChanged();
}

bool TestKlasse::onButtonClick()
{
    qDebug() << "on button click";

    setTest(!getTest());

    qDebug() << getTest();

    emit colorChanged(getTest() ? "green" : "red");

    return getTest();
}
