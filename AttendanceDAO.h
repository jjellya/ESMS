#ifndef ATTENDANCEDAO_H
#define ATTENDANCEDAO_H
#include "Global.h"
#include "Attendance.h"

class AttendanceDAO
{
public:
    AttendanceDAO();
    /*只写了头文件方法名 */
    Attendance* getAttentancePage(int start,int size);//获取考勤记录,start:第几条记录开始(从零开始),size:获取几条;
    Attendance getAttentanceById(int id);//通过id查找考勤记录;
    Attendance* getAttentanceByDate(DATE p_date);//通过日期查找考勤记录;
    bool updateEmployee(const Attendance &attendance);
    bool addEmployee(const Attendance &attendance);
    bool deleteEmployee(const Attendance &attendance);

};

#endif // ATTENDANCEDAO_H
