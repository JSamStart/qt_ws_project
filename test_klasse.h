#pragma once

#include <QObject>
#include <QQmlEngine>

class TestKlasse : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit TestKlasse(QObject *parent = nullptr);

    bool getTest() const;
    void setTest(bool value);

signals:
    void testChanged();
    void colorChanged(QString p_color);

public slots:
    bool onButtonClick();

private:
    bool m_test = false;

    Q_PROPERTY(bool test READ getTest WRITE setTest NOTIFY testChanged)
};
