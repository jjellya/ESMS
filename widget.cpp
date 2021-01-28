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
#include "EmployeeDAO.h"
#include "AttendanceDAO.h"

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
    ui->tableView123->setUpdatesEnabled(true); //恢复界面刷新

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
//    UserDAO userDAO;
//    User *userArr = userDAO.getAllUser();
//    //QString qstr = QString::fromStdString(userArr[0].getUserName());
//    qDebug("%s",userArr[0].getUserId().data());

//    User admin = userDAO.getUserById("admin");
//    qDebug("admin的密码为%s",admin.getUserPwd().data());


//    EmployeeDAO employeeDAO;
//    Employee *employeeArr = employeeDAO.getEmployeePage(0,10);

//    Employee emp5 = employeeDAO.getEmployeeById(5);
//    qDebug("%s\n",emp5.toString().data());
//    string strName = "李四";
//    emp5.setEmployeeName(strName);
//    employeeDAO.updateEmployee(emp5);

//    emp5.setEmployeeName("汤学希headsomeboy ");
//    employeeDAO.addEmployee(emp5);

//    employeeDAO.deleteEmployee(28);

//      AttendanceDAO attendanceDAO;
//      attendanceDAO.getAttentancePage(0,10);

//      Attendance att2 = attendanceDAO.getAttentanceById(2);

//      DATE tomorrow;
//      tomorrow.year=2021;tomorrow.month=1;tomorrow.day=30;
//      Attendance *attArr3 = attendanceDAO.getAttentanceByDate(tomorrow);

//      att2.setCalculatedDay(31);
//      attendanceDAO.updateAttendance(att2);

//      att2.setEmployeeId(4);
//      attendanceDAO.addAttendance(att2);

//      attendanceDAO.deleteAttendance(4);

}
