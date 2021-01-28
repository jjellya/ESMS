#include "Attendance.h"

#include "Attendance.h"

Attendance::Attendance() {}

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
