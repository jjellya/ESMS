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
            //qDebug("%d\n",attendance0.getEmployeeId());
            //qDebug("%d / %d\n",attendance0.getAttDate().month,attendance0.getAttDate().day);
        result [i++] = attendance0;
     }
    return result;
}

Attendance AttendanceDAO::getAttentanceById(int id){
    QSqlQuery query;
    query.prepare("select * from attendance where attendance_id = :id"); //准备执行SQL查询
    query.bindValue(":id",id);
    query.exec();
    //qDebug("SQL语句执行无误！\n");

    if(true != query.next()) qDebug("AttendanceID 为%d的考勤记录不存在 ",id);

    //int id =  query.value(0).toString().toInt();                //取第一列 ,不需要
    int employee_id =  query.value(1).toString().toInt();       //取第二列 ,employee_id
    int leftEarly =  query.value(2).toString().toInt();         //取第三列 ,早退
    int late = query.value(3).toString().toInt();               //取第四列 ,迟到
    int nonPunch = query.value(4).toString().toInt();           //取第五列 ,未打卡
    int overtime = query.value(5).toString().toInt();           //取第六列 ,加班
    int leave = query.value(6).toString().toInt();              //取第七列 ,请假
    int calDay = query.value(7).toString().toInt();             //取第八列 ,应出勤天数
    string attDate  = query.value(8).toString().toStdString();  //取第九列
    //qDebug("attendance date = %s\n",attDate.data());
    Attendance result(id,employee_id,leftEarly,late,nonPunch,overtime,leave,calDay,attDate);
    return result;
}

Attendance* AttendanceDAO::getAttentanceByDate(const DATE& p_date){//通过日期查找考勤记录;
    QSqlQuery query;
    query.prepare("select * from attendance where att_date = :date"); //准备执行SQL查询
    //绑定参数
    string strDate = to_string(p_date.year)+"-"+to_string(p_date.month)+"-"+to_string(p_date.day);
    query.bindValue(":date",QString::fromStdString(strDate));
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
            //qDebug("%d\n",attendance0.getEmployeeId());
            //qDebug("%d / %d\n",attendance0.getAttDate().month,attendance0.getAttDate().day);
        result [i++] = attendance0;
     }
    return result;
}
bool AttendanceDAO::updateAttendance(const Attendance &attendance){
    QSqlQuery query;
    query.prepare("update attendance set employee_id = :employee_id, "
                                        "left_early = :left_early, "
                                        "late = :late, "
                                        "non_punch = :non_punch, "
                                        "overtime = :overtime, "
                                        "`leave`  = :leave,"
                                        "calculated_day = :calculated_day, "
                                        "att_date = :att_date "
                                        " where attendance_id = :id"); //准备执行SQL查询
    //属性绑定
    query.bindValue(":id",attendance.getAttendanceId());
    query.bindValue(":employee_id",attendance.getEmployeeId());
    query.bindValue(":left_early",attendance.getLeftEarly());
    query.bindValue(":late",attendance.getLate());
    query.bindValue(":non_punch",attendance.getNonPunch());
    query.bindValue(":overtime",attendance.getOvertime());
    query.bindValue(":leave",attendance.getLeave());
    query.bindValue(":calculated_day",attendance.getCalculatedDay());
    string strDate = to_string(attendance.getAttDate().year)+"-"+to_string(attendance.getAttDate().month)+"-"+to_string(attendance.getAttDate().day);
    query.bindValue(":att_date",QString::fromStdString(strDate));
    //qDebug("日期=%s\n",strDate.data());

    //qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    //qDebug("SQL语句执行:  %d\n",result);
    return result;
}

bool AttendanceDAO::addAttendance(const Attendance &attendance){
    QSqlQuery query;
    query.prepare("insert into attendance(employee_id,left_early,late,non_punch,overtime,`leave`,calculated_day,att_date) values(:employee_id, "
                  ":left_early, "
                  ":late, "
                  ":non_punch, "
                  ":overtime, "
                  ":leave, "
                  ":calculated_day, "
                  ":att_date )"); //准备执行SQL查询
    query.bindValue(":employee_id",attendance.getEmployeeId());
    query.bindValue(":left_early",attendance.getLeftEarly());
    query.bindValue(":late",attendance.getLate());
    query.bindValue(":non_punch",attendance.getNonPunch());
    query.bindValue(":overtime",attendance.getOvertime());
    query.bindValue(":leave",attendance.getLeave());
    query.bindValue(":calculated_day",attendance.getCalculatedDay());
    string strDate = to_string(attendance.getAttDate().year)+"-"+to_string(attendance.getAttDate().month)+"-"+to_string(attendance.getAttDate().day);
    query.bindValue(":att_date",QString::fromStdString(strDate));
    //qDebug("日期=%s\n",strDate.data());
    //qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    //qDebug("SQL语句执行:  %d\n",result);
    return result;
}
bool AttendanceDAO::deleteAttendance(const int id){
    QSqlQuery query;
    query.prepare("delete from attendance where attendance_id = :id"); //准备执行SQL查询
    query.bindValue(":id",id);
    //qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    //qDebug("SQL语句执行:  %d\n",result);
    return result;
}
