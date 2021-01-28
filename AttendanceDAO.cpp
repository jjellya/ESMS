#include "AttendanceDAO.h"

#include"Global.h"
#include"Attendance.h"
#include"QtSql"

AttendanceDAO::AttendanceDAO()
{

}
Attendance* AttendanceDAO::getAttentancePage(int start,int size){
    QSqlQuery query;
    query.prepare("select * from attendance limit :start,:size"); //准备执行SQL查询
    //绑定参数
    query.bindValue(":start",start);//或者QString::number(start)
    query.bindValue(":size",size);//或者QString::number(size)
    query.exec();
    //qDebug("SQL语句执行无误！\n");
    Attendance *result; //返回的结果
    result = new Attendance[ARRARY_MAXSIZE];
    int i = 0;
    while (true == query.next()) {  //一行一行遍历
        //取出当前行的内容，以列为单位
        int id =  query.value(0).toString().toInt();                //取第一列 ,attendance_id
        int employee_id =  query.value(1).toString().toInt();       //取第二列 ,employee_id
        int leftEarly =  query.value(2).toString().toInt();         //取第三列 ,早退
        int late = query.value(3).toString().toInt();               //取第四列 ,迟到
        int nonPunch = query.value(4).toString().toInt();           //取第五列 ,未打卡
        int overtime = query.value(5).toString().toInt();           //取第六列 ,加班
        int leave = query.value(6).toString().toInt();              //取第七列 ,请假
        int calDay = query.value(7).toString().toInt();             //取第八列 ,应出勤天数
        string attDate  = query.value(8).toString().toStdString();  //取第九列
            //qDebug("编号 : %d ,  ",id);
        Attendance attendance0(id,employee_id,leftEarly,late,nonPunch,overtime,leave,calDay,attDate);
            qDebug("%d\n",attendance0.getEmployeeId());
            qDebug("%d / %d\n",attendance0.getAttDate().month,attendance0.getAttDate().day);
        result [i++] = attendance0;
     }
    return result;
}

Attendance AttendanceDAO::getAttentanceById(int id){
    Attendance result;
    return result;
}

Attendance* getAttentanceByDate(DATE p_date){//通过日期查找考勤记录;
    Attendance *result;
    return result;
}
bool AttendanceDAO::updateEmployee(const Attendance &attendance){
    return false;
}

bool AttendanceDAO::addEmployee(const Attendance &attendance){
    return false;
}
bool AttendanceDAO::deleteEmployee(const Attendance &attendance){
    return false;
}
