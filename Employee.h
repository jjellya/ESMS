#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Global.h"

class Employee {
public:
    Employee();

    virtual ~Employee();

    int getEmployeeId() const;

    void setEmployeeId(int employeeId);

    const string &getEmployeeName() const;

    void setEmployeeName(const string &employeeName);

    const string &getPhone() const;

    void setPhone(const string &phone);

    int getDegree() const;

    void setDegree(int degree);

    int getStatus() const;

    void setStatus(int status);

    int getDepartment() const;

    void setDepartment(int department);

    const string &getEmail() const;

    void setEmail(const string &email);

    int getIsFulltime() const;

    void setIsFulltime(int isFulltime);

    const DATE &getHiredate() const;

    void setHiredate(const DATE &hiredate);

private:
    //员工工号
    int employee_id;
    //员工姓名
    string employee_name;
    //手机号
    string phone;
    //学位
    int degree;
    //状态
    int status;
    //部门
    int department;
    //邮箱
    string email;
    //是否转正
    int is_fulltime;
    //入职日期
    DATE hiredate;

};


#endif // EMPLOYEE_H
