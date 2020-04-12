#pragma once

#include <QObject>

#include <QtTest/QtTest>

#include "userlist.h"

class TestInterface : public QObject
{
	Q_OBJECT

private slots:
	void launchInterface();

public:
	TestInterface(QObject *parent);
	~TestInterface();
};
