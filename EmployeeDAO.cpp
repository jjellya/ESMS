#include "EmployeeDAO.h"
#include "QtSql"
EmployeeDAO::EmployeeDAO()
{

}

//获取员工记录,start:第几条记录开始,size:获取几条;
Employee* EmployeeDAO::getEmployeePage(int start,int size){
    QSqlQuery query;
    query.prepare("select * from employee limit :start,:size"); //准备执行SQL查询
    //绑定参数
    query.bindValue(":start",start);//或者QString::number(start)
    query.bindValue(":size",size);//或者QString::number(size)
    query.exec();
    //qDebug("SQL语句执行无误！\n");
    Employee *result; //返回的结果
    result = new Employee[ARRARY_MAXSIZE];
    int i = 0;
    while (true == query.next()) {  //一行一行遍历
        //取出当前行的内容，以列为单位
        int id =  query.value(0).toString().toInt();                //取第一列
        string name =  query.value(1).toString().toStdString();     //取第二列
        string phone =  query.value(2).toString().toStdString();    //取取第三列
        int degree = query.value(3).toString().toInt();             //取第四列
        int status = query.value(4).toString().toInt();             //取第五列
        int department = query.value(5).toString().toInt();         //取第六列
        string email =  query.value(6).toString().toStdString();    //取取第七列
        int is_fulltime = query.value(7).toString().toInt();        //取第八列
        string hiredate  = query.value(8).toString().toStdString(); //取第九列
            //qDebug("编号 : %d ,  ",id);
        Employee employee0(id,name,phone,degree,status,department,email,is_fulltime,hiredate);
            //qDebug("%s\n",employee0.getEmployeeName().data());
            //qDebug("%d / %d\n",employee0.getHiredate().month,employee0.getHiredate().day);
        result [i++] = employee0;
     }
    return result;
}

//通过id查找员工;
Employee EmployeeDAO::getEmployeeById(int id){
    QSqlQuery query;
    query.prepare("select * from employee where employee_id = :id"); //准备执行SQL查询
    query.bindValue(":id",id);
    query.exec();
    qDebug("SQL语句执行无误！\n");

    if(true != query.next()) qDebug("ID 为%d的员工不存在",id);

    //int id =  query.value(0).toString().toInt();              //取第一列(这里不需要)
    string name =  query.value(1).toString().toStdString();     //取第二列
    string phone =  query.value(2).toString().toStdString();    //取第三列
    int degree = query.value(3).toString().toInt();             //取第四列
    int status = query.value(4).toString().toInt();             //取第五列
    int department = query.value(5).toString().toInt();         //取第六列
    string email =  query.value(6).toString().toStdString();    //取取第七列
    int is_fulltime = query.value(7).toString().toInt();        //取第八列
    string hiredate  = query.value(8).toString().toStdString(); //取第九列
    //qDebug("姓名 : %s ,  ",name.data());
    //qDebug("%s\n",hiredate.data());
    Employee result(id,name,phone,degree,status,department,email,is_fulltime,hiredate);
    return result;
}


bool EmployeeDAO::updateEmployee(const Employee &employee){
    QSqlQuery query;
    query.prepare("update employee set employee_name = :name, "
                  "                    phone = :phone,"
                  "                    degree = :degree,"
                  "                    status = :status,"
                  "                    department = :department,"
                  "                    email  = :email,"
                  "                    is_fulltime = :is_fulltime,"
                  "                    hiredate = :hiredate "
                  " where employee_id = :id"); //准备执行SQL查询
    query.bindValue(":id",employee.getEmployeeId());
    query.bindValue(":name",QString::fromStdString(employee.getEmployeeName()));
    query.bindValue(":phone",QString::fromStdString(employee.getPhone()));
    query.bindValue(":degree",employee.getDegree());
    query.bindValue(":status",employee.getStatus());
    query.bindValue(":department",employee.getDepartment());
    query.bindValue(":email",QString::fromStdString(employee.getEmail()));
    query.bindValue(":is_fulltime",employee.getIsFulltime());
    string strDate = to_string(employee.getHiredate().year)+"-"+to_string(employee.getHiredate().month)+"-"+to_string(employee.getHiredate().day);
    query.bindValue(":hiredate",QString::fromStdString(strDate));
    //qDebug("日期为 %s\n",strDate.data());
    //qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    //qDebug("SQL语句执行:  %d\n",result);
    return result;
}
bool EmployeeDAO::addEmployee(const Employee &employee){
    QSqlQuery query;
    query.prepare("insert into employee(employee_name,phone,degree,status,department,email,is_fulltime,hiredate) values(:name, "
                  "                     :phone,"
                  "                     :degree,"
                  "                     :status,"
                  "                     :department,"
                  "                     :email,"
                  "                     :is_fulltime,"
                  "                     :hiredate )"); //准备执行SQL查询
    //query.bindValue(":id",employee.getEmployeeId());//ID自动分配无需指定
    query.bindValue(":name",QString::fromStdString(employee.getEmployeeName()));
    query.bindValue(":phone",QString::fromStdString(employee.getPhone()));
    query.bindValue(":degree",employee.getDegree());
    query.bindValue(":status",employee.getStatus());
    query.bindValue(":department",employee.getDepartment());
    query.bindValue(":email",QString::fromStdString(employee.getEmail()));
    query.bindValue(":is_fulltime",employee.getIsFulltime());
    string strDate = to_string(employee.getHiredate().year)+"-"+to_string(employee.getHiredate().month)+"-"+to_string(employee.getHiredate().day);
    query.bindValue(":hiredate",QString::fromStdString(strDate));
    //qDebug("日期为 %s\n",strDate.data());
    //qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    //qDebug("SQL语句执行:  %d\n",result);
    return result;
}
bool EmployeeDAO::deleteEmployee(const int id){
    QSqlQuery query;
    query.prepare("delete from employee where employee_id = :id"); //准备执行SQL查询
    query.bindValue(":id",id);
    qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    qDebug("SQL语句执行:  %d\n",result);
    return result;
}
