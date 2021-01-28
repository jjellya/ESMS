#include "Salary.h"

Salary::Salary() {}

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
