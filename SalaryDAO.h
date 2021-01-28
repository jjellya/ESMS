#ifndef SALARYDAO_H
#define SALARYDAO_H
#include"Global.h"
#include"Salary.h"

class SalaryDAO
{
public:
    SalaryDAO();
    /*只写了头文件方法名 */
    Salary* getSalaryPage(int start,int size);//获取工资记录,start:第几条记录开始(从零开始),size:获取几条;
    Salary getSalaryById(int id);//通过id查找工资记录;
    bool updateSalary(const Salary &salary);
    bool addSalary(const Salary &salary);
    bool deleteSalary(const int id);
};

#endif // SALARYDAO_H
