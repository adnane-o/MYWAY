#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <iostream>
#define q2c(string) string.toStdString()
using namespace std;

int main(int argc, char *argv[])
{
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("test.db");
    bd.open();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
    return 0;
}
