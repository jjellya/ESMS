#include "Employee.h"


Employee::Employee() {}

Employee::~Employee() {

}

int Employee::getEmployeeId() const {
    return employee_id;
}

void Employee::setEmployeeId(int employeeId) {
    employee_id = employeeId;
}

const string &Employee::getEmployeeName() const {
    return employee_name;
}

void Employee::setEmployeeName(const string &employeeName) {
    employee_name = employeeName;
}

const string &Employee::getPhone() const {
    return phone;
}

void Employee::setPhone(const string &phone) {
    Employee::phone = phone;
}

int Employee::getDegree() const {
    return degree;
}

void Employee::setDegree(int degree) {
    Employee::degree = degree;
}

int Employee::getStatus() const {
    return status;
}

void Employee::setStatus(int status) {
    Employee::status = status;
}

int Employee::getDepartment() const {
    return department;
}

void Employee::setDepartment(int department) {
    Employee::department = department;
}

const string &Employee::getEmail() const {
    return email;
}

void Employee::setEmail(const string &email) {
    Employee::email = email;
}

int Employee::getIsFulltime() const {
    return is_fulltime;
}

void Employee::setIsFulltime(int isFulltime) {
    is_fulltime = isFulltime;
}

const DATE &Employee::getHiredate() const {
    return hiredate;
}

void Employee::setHiredate(const DATE &hiredate) {
    Employee::hiredate = hiredate;
}
