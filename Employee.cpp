#include "Employee.h"


Employee::Employee() {}

Employee::Employee(int employeeId, const string &employeeName, const string &phone, int degree, int status,
                   int department, const string &email, int isFulltime, const string &p_hiredate) : employee_id(employeeId),
                                                                                                employee_name(employeeName),
                                                                                                phone(phone),
                                                                                                degree(degree),
                                                                                                status(status),
                                                                                                department(department),
                                                                                                email(email),is_fulltime(isFulltime) {
    if(p_hiredate.size()>=10) {
        hiredate.year =  atoi(p_hiredate.substr(0,4).data());//将参数的年份(string类型)转化为int类型并赋值给hiredate.year成员参数
        hiredate.month =  atoi(p_hiredate.substr(5,7).data());//将参数的年份(string类型)转化为int类型并赋值给hiredate.month成员参数
        hiredate.day =  atoi(p_hiredate.substr(8,10).data());//将参数的年份(string类型)转化为int类型并赋值给hiredate.day成员参数
    }
}

Employee::~Employee() {

}

string Employee::toString(){
    string str = "工号: "+to_string(employee_id)+", 姓名: "+employee_name +", 手机号:  "+phone;
    return str;
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
