#include "widget.h"
#include "ui_widget.h"
#include "QtDebug"

#include <QSqlTableModel>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtSql>
#include "db_connection.h"
#include "UserDAO.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    createConnection();
        QSqlTableModel *model = new QSqlTableModel(this);
        model->setTable("employee");
        model->select();
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);    //设置编辑策略。

    ui->setupUi(this);
    ui->tableView123->setModel(model);
    ui->tableView123->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置视图为只读模式

}

Widget::~Widget()
{
    delete ui;
}

//void Widget::on_pushButton_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("120.79.175.205");
//    db.setPort(3306);
//    db.setDatabaseName("ESMS");
//    db.setUserName("root");
//    db.setPassword("mysql123455");

//    if(db.open()){
//        QMessageBox::information(this,"Connection","Database Connected Success!");
//    }else{
//        QMessageBox::information(this,"ERROR","Database Connected Failed!");
//    }
//}

void Widget::on_pushButton_clicked()
{
    /*测试内容,无需理会*/
    UserDAO userDAO;
    User *userArr = userDAO.getAllUser();
    //QString qstr = QString::fromStdString(userArr[0].getUserName());
    qDebug("%s",userArr[0].getUserId().data());

    User admin = userDAO.getUserById("admin");
    qDebug("admin的密码为%s",admin.getUserPwd().data());
}
