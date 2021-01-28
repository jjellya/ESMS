#include "EmployeeDAO.h"
#include "QtSql"
EmployeeDAO::EmployeeDAO()
{

}
Employee* EmployeeDAO::getEmployeePage(int start,int size){//获取员工记录,start:第几条记录开始,size:获取几条;
    QSqlQuery query;
    query.prepare("select * from employee"); //准备执行SQL查询
    //query.bindValue(":id", QString::fromStdString(id));
    query.exec();
    Employee *result;
    return result;

}

Employee EmployeeDAO::getEmployeeById(int id){
    Employee result;
    return result;
}//通过id查找员工;
bool EmployeeDAO::updateEmployee(const Employee &employee){
return false;
}
bool EmployeeDAO::addEmployee(const Employee &employee){
return false;
}
bool EmployeeDAO::deleteEmployee(const Employee &employee){
    return false;
}
