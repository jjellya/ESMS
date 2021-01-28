#ifndef ATTENDANCE_H
#define ATTENDANCE_H


#include "Global.h"
class Attendance {
public:
    Attendance();

    virtual ~Attendance();

    int getAttendanceId() const;

    void setAttendanceId(int attendanceId);

    int getEmployeeId() const;

    void setEmployeeId(int employeeId);

    int getLeftEarly() const;

    void setLeftEarly(int leftEarly);

    int getLate() const;

    void setLate(int late);

    int getNonPunch() const;

    void setNonPunch(int nonPunch);

    int getOvertime() const;

    void setOvertime(int overtime);

    int getLeave() const;

    void setLeave(int leave);

    int getCalculatedDay() const;

    void setCalculatedDay(int calculatedDay);

    const DATE &getAttDate() const;

    void setAttDate(const DATE &attDate);

private:
    //出勤id
    int attendance_id;
    //员工工号
    int employee_id;
    //早退次数
    int left_early;
    //迟到次数
    int late;
    //未打卡次数
    int non_punch;
    //加班天数
    int overtime;
    //请假次数
    int leave;
    //应出勤天数
    int calculated_day;
    //考勤日期
    DATE att_date;
};

#endif // ATTENDANCE_H
