#pragma once

#include <QObject>

class UnitTests : public QObject
{
	Q_OBJECT

public:
	UnitTests(QObject *parent);
	~UnitTests();
};
