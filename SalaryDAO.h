#ifndef SALARYDAO_H
#define SALARYDAO_H
#include"Global.h"
#include"Salary.h"

class SalaryDAO
{
public:
    SalaryDAO();
    /*只写了头文件方法名 */
    Salary* getAttentancePage(int start,int size);//获取工资记录,start:第几条记录开始,size:获取几条;
    Salary getAttentanceById(int id);//通过id查找工资记录;
    bool updateEmployee(const Salary &salary);
    bool addEmployee(const Salary &salary);
    bool deleteEmployee(const Salary &salary);
};

#endif // SALARYDAO_H
