#include "AttendanceDAO.h"

AttendanceDAO::AttendanceDAO()
{

}
Attendance* AttendanceDAO::getAttentancePage(int start,int size){
    Attendance *result;
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
