#include "Attendance.h"

#include "Attendance.h"

Attendance::Attendance() {}

Attendance::Attendance(int attendanceId, int employeeId, int leftEarly, int late, int nonPunch, int overtime, int leave,
                       int calculatedDay, const string &p_attDate) : attendance_id(attendanceId), employee_id(employeeId),
                                                                 left_early(leftEarly), late(late), non_punch(nonPunch),
                                                                 overtime(overtime), leave(leave),
                                                                 calculated_day(calculatedDay){
    if(p_attDate.size()>=10) {
        att_date.year =  atoi(p_attDate.substr(0,4).data());//将参数的年份(string类型)转化为int类型并赋值给att_date.year成员参数
        att_date.month =  atoi(p_attDate.substr(5,7).data());//将参数的年份(string类型)转化为int类型并赋值给att_date.month成员参数
        att_date.day =  atoi(p_attDate.substr(8,10).data());//将参数的年份(string类型)转化为int类型并赋值给att_date.day成员参数
    }

}

Attendance::~Attendance() {

}

int Attendance::getAttendanceId() const {
    return attendance_id;
}

void Attendance::setAttendanceId(int attendanceId) {
    attendance_id = attendanceId;
}

int Attendance::getEmployeeId() const {
    return employee_id;
}

void Attendance::setEmployeeId(int employeeId) {
    employee_id = employeeId;
}

int Attendance::getLeftEarly() const {
    return left_early;
}

void Attendance::setLeftEarly(int leftEarly) {
    left_early = leftEarly;
}

int Attendance::getLate() const {
    return late;
}

void Attendance::setLate(int late) {
    Attendance::late = late;
}

int Attendance::getNonPunch() const {
    return non_punch;
}

void Attendance::setNonPunch(int nonPunch) {
    non_punch = nonPunch;
}

int Attendance::getOvertime() const {
    return overtime;
}

void Attendance::setOvertime(int overtime) {
    Attendance::overtime = overtime;
}

int Attendance::getLeave() const {
    return leave;
}

void Attendance::setLeave(int leave) {
    Attendance::leave = leave;
}

int Attendance::getCalculatedDay() const {
    return calculated_day;
}

void Attendance::setCalculatedDay(int calculatedDay) {
    calculated_day = calculatedDay;
}

const DATE &Attendance::getAttDate() const {
    return att_date;
}

void Attendance::setAttDate(const DATE &attDate) {
    att_date = attDate;
}
