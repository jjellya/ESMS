#ifndef EMPLOYEEDAO_H
#define EMPLOYEEDAO_H

#include "Global.h"
#include "Employee.h"
class EmployeeDAO
{
public:
    EmployeeDAO();
    /*只写了头文件方法名 */
    Employee* getEmployeePage(int start,int size);//获取员工记录,start:第几条记录开始(从零开始),size:获取几条;
    Employee getEmployeeById(int id);//通过id查找员工;
    bool updateEmployee(const Employee &employee);
    bool addEmployee(const Employee &employee);
    bool deleteEmployee(const int id);//通过id删除员工;
};

#endif // EMPLOYEEDAO_H
