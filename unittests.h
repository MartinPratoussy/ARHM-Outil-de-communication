#pragma once

#include <QObject>

#include "userlist.h"

class UnitTests : public QObject
{
	Q_OBJECT

// Les fonctions de test sont entrepos�s dans les slots de la classe
private slots:


public:
	UnitTests(QObject *parent);
	~UnitTests();
};
