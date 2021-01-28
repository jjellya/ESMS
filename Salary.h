#ifndef SALARY_H
#define SALARY_H

#include "Global.h"

class Salary {
public:
    Salary();

    Salary(int salaryId, int employeeId, int baseSalary, int postSalary, int meritSalary, int socialSecurity,
               int fullAttBonus, int absentDeduction, int lateDeduction, int earlyDeduction, int overtimeBonus,
               int beforeTax, int afterTax, const string &salaryDate);

    Salary(const Salary &another);

    virtual ~Salary();

    /*getter & setter*/
    int getSalaryId() const;

    void setSalaryId(int salaryId);

    int getEmployeeId() const;

    void setEmployeeId(int employeeId);

    int getBaseSalary() const;

    void setBaseSalary(int baseSalary);

    int getPostSalary() const;

    void setPostSalary(int postSalary);

    int getMeritSalary() const;

    void setMeritSalary(int meritSalary);

    int getSocialSecurity() const;

    void setSocialSecurity(int socialSecurity);

    int getFullAttBonus() const;

    void setFullAttBonus(int fullAttBonus);

    int getAbsentDeduction() const;

    void setAbsentDeduction(int absentDeduction);

    int getLateDeduction() const;

    void setLateDeduction(int lateDeduction);

    int getEarlyDeduction() const;

    void setEarlyDeduction(int earlyDeduction);

    int getOvertimeBonus() const;

    void setOvertimeBonus(int overtimeBonus);

    int getBeforeTax() const;

    void setBeforeTax(int beforeTax);

    int getAfterTax() const;

    void setAfterTax(int afterTax);

    const DATE &getSalaryDate() const;

    void setSalaryDate(const DATE &salaryDate);

private:
    //ID
    int salary_id;
    //员工工号
    int employee_id;
    //基本工资
    int base_salary;
    //岗位工资
    int post_salary;
    //绩效工资
    int merit_salary;
    //社保扣款
    int social_security;
    //全勤奖
    int full_att_bonus;
    //旷工扣款(元/次)
    int absent_deduction;
    //迟到扣款(元/次)
    int late_deduction;
    //早退扣款(元/次)
    int early_deduction;
    //加班费(元/天)
    int overtime_bonus;
    //应发工资
    int before_tax;
    //实发工资
    int after_tax;
    //工资日期
    DATE salary_date;


};
#endif // SALARY_H
