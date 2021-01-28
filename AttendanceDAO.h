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
    Attendance* getAttentanceByDate(const DATE& p_date);//通过日期查找考勤记录;
    bool updateAttendance(const Attendance &attendance);
    bool addAttendance(const Attendance &attendance);
    bool deleteAttendance(const int id);

};

#endif // ATTENDANCEDAO_H
