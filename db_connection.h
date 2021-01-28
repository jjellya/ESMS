#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <QtSql\QSqlDatabase>
#include <QtSql\QtSql>
#include <QtCore\QDebug>
#include <QtSql\QSqlQuery>
#include <QMessageBox>
#include <QtCore\QString>

//创建一个默认的连接，即只有一个连接
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("120.79.175.205");
        db.setPort(3306);
        db.setDatabaseName("ESMS");
        db.setUserName("root");
        db.setPassword("mysql123455");
        if (db.open()){
            QMessageBox::information(0, "Information", "DataBase Connecting Success");
        }
        else {
            QMessageBox::information(0, "Error", "DataBase Connecting Failed");
            qDebug()<<"【Error】: Cann't open database because "<<db.lastError().text();
        }
    db.open();
    return true;
}


#endif // DB_CONNECTION_H
