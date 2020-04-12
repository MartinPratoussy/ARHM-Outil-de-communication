#include "testinterface.h"

TestInterface::TestInterface(QObject* parent)
	: QObject(parent)
{
}

TestInterface::~TestInterface()
{
}

void TestInterface::launchInterface()
{
	QSqlDatabase* db = new QSqlDatabase();
	QSqlQuery* query = new QSqlQuery(*db);

	User* user = new User(0, "John", "DOE", "01/01/2000", db, query);

	QPixmap pixmap("../ARHM-Outil-de-communication/data/test.png");
	Sound sound("../ARHM-Outil-de-communication/data/test.mp3");
	Pictogram* picto = new Pictogram("test", pixmap, sound, "test");

	Interface* interface = new Interface();
	interface->InitInterface(user);

	QCOMPARE(interface->GetUser()->getFirstname(), QString("John"));
	QCOMPARE(interface->GetUser()->getLastname(), QString("DOE"));
	QCOMPARE(interface->GetUser()->getBirthDate(), QString("01/01/2000"));
}