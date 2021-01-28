#include "Salary.h"
#include "QDebug"

Salary::Salary() {}

Salary::Salary(int salaryId, int employeeId, int baseSalary, int postSalary, int meritSalary, int socialSecurity,
               int fullAttBonus, int absentDeduction, int lateDeduction, int earlyDeduction, int overtimeBonus,
               int beforeTax, int afterTax, const string &p_salaryDate) : salary_id(salaryId), employee_id(employeeId),
                                                                      base_salary(baseSalary), post_salary(postSalary),
                                                                      merit_salary(meritSalary),
                                                                      social_security(socialSecurity),
                                                                      full_att_bonus(fullAttBonus),
                                                                      absent_deduction(absentDeduction),
                                                                      late_deduction(lateDeduction),
                                                                      early_deduction(earlyDeduction),
                                                                      overtime_bonus(overtimeBonus),
                                                                      before_tax(beforeTax), after_tax(afterTax) {
    if(p_salaryDate.size()>=10) {
        qDebug("p_salaryDate.size = %d, %s\n",p_salaryDate.size(),p_salaryDate.data());
        this->salary_date.year =  atoi(p_salaryDate.substr(0,4).data());//将参数的年份(string类型)转化为int类型并赋值给salary_date.year成员参数 
        this->salary_date.month =  atoi(p_salaryDate.substr(5,7).data());//将参数的年份(string类型)转化为int类型并赋值给salary_date.month成员参数
        this->salary_date.day =  atoi(p_salaryDate.substr(8,10).data());//将参数的年份(string类型)转化为int类型并赋值给salary_date.day成员参数
        qDebug("year = %d,month = %d,day = %d\n",salary_date.year,salary_date.month,salary_date.day);
    }
}

Salary::~Salary() {

}

Salary::Salary(const Salary &another )  {}

int Salary::getSalaryId() const {
    return salary_id;
}

void Salary::setSalaryId(int salaryId) {
    salary_id = salaryId;
}

int Salary::getEmployeeId() const {
    return employee_id;
}

void Salary::setEmployeeId(int employeeId) {
    employee_id = employeeId;
}

int Salary::getBaseSalary() const {
    return base_salary;
}

void Salary::setBaseSalary(int baseSalary) {
    base_salary = baseSalary;
}

int Salary::getPostSalary() const {
    return post_salary;
}

void Salary::setPostSalary(int postSalary) {
    post_salary = postSalary;
}

int Salary::getMeritSalary() const {
    return merit_salary;
}

void Salary::setMeritSalary(int meritSalary) {
    merit_salary = meritSalary;
}

int Salary::getSocialSecurity() const {
    return social_security;
}

void Salary::setSocialSecurity(int socialSecurity) {
    social_security = socialSecurity;
}

int Salary::getFullAttBonus() const {
    return full_att_bonus;
}

void Salary::setFullAttBonus(int fullAttBonus) {
    full_att_bonus = fullAttBonus;
}

int Salary::getAbsentDeduction() const {
    return absent_deduction;
}

void Salary::setAbsentDeduction(int absentDeduction) {
    absent_deduction = absentDeduction;
}

int Salary::getLateDeduction() const {
    return late_deduction;
}

void Salary::setLateDeduction(int lateDeduction) {
    late_deduction = lateDeduction;
}

int Salary::getEarlyDeduction() const {
    return early_deduction;
}

void Salary::setEarlyDeduction(int earlyDeduction) {
    early_deduction = earlyDeduction;
}

int Salary::getOvertimeBonus() const {
    return overtime_bonus;
}

void Salary::setOvertimeBonus(int overtimeBonus) {
    overtime_bonus = overtimeBonus;
}

int Salary::getBeforeTax() const {
    return before_tax;
}

void Salary::setBeforeTax(int beforeTax) {
    before_tax = beforeTax;
}

int Salary::getAfterTax() const {
    return after_tax;
}

void Salary::setAfterTax(int afterTax) {
    after_tax = afterTax;
}

const DATE &Salary::getSalaryDate() const {
    return salary_date;
}

void Salary::setSalaryDate(const DATE &salaryDate) {
    salary_date = salaryDate;
}
