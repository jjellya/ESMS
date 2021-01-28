#include "SalaryDAO.h"
#include "QtSql"


SalaryDAO::SalaryDAO()
{

}
Salary* SalaryDAO::getSalaryPage(int start,int size){
    QSqlQuery query;
    query.prepare("select * from salary limit :start,:size"); //准备执行SQL查询
    //绑定参数
    query.bindValue(":start",start);//或者QString::number(start)
    query.bindValue(":size",size);//或者QString::number(size)
    query.exec();
    //qDebug("SQL语句执行无误！\n");
    Salary *result; //返回的结果
    result = new Salary[ARRARY_MAXSIZE];
    int i = 0;
    while (true == query.next()) {  //一行一行遍历
        //取出当前行的内容，以列为单位
        int id =  query.value(0).toString().toInt();                   //取第一列 ,salary_id
        int employee_id =  query.value(1).toString().toInt();          //取第二列 ,employee_id
        int baseSalary =  query.value(2).toString().toInt();           //取第三列 ,基本工资
        int postSalary = query.value(3).toString().toInt();            //取第四列 ,岗位工资
        int meritSalary = query.value(4).toString().toInt();           //取第五列 ,绩效工资
        int socialSecurity = query.value(5).toString().toInt();        //取第六列 ,社保扣款
        int fullAttBonus = query.value(6).toString().toInt();          //取第七列 ,全勤奖
        int absentDeduction = query.value(7).toString().toInt();       //取第八列 ,旷工扣款
        int lateDeduction = query.value(8).toString().toInt();         //取第九列 ,迟到扣款
        int earlyDeduction = query.value(9).toString().toInt();        //取第十列 ,早退扣款
        int overtimeBonus = query.value(10).toString().toInt();        //取第十一列 ,加班费
        int beforeTax = query.value(11).toString().toInt();            //取第十二列 ,应发工资
        int afterTax = query.value(12).toString().toInt();             //取第十三列 ,实发工资
        string salaryDate  = query.value(13).toString().toStdString();  //取第十四列 ,工资日期
            //qDebug("编号 : %d  ",id);
        Salary salary0(id,employee_id,baseSalary,postSalary,meritSalary,socialSecurity,fullAttBonus,absentDeduction,
                       lateDeduction,earlyDeduction,overtimeBonus,beforeTax,afterTax,salaryDate);
            //qDebug("%d\n",salary0.getEmployeeId());
            //qDebug("%d / %d\n",salary0.getSalaryDate().month,salary0.getSalaryDate().day);
        result [i++] = salary0;
     }
    return result;
}

Salary SalaryDAO::getSalaryById(int id){
    QSqlQuery query;
    query.prepare("select * from salary where salary_id = :id"); //准备执行SQL查询
    query.bindValue(":id",id);
    query.exec();
    //qDebug("SQL语句执行无误！\n");

    if(true != query.next()) qDebug("SalaryID 为%d的工资记录不存在 ",id);

    //int id =  query.value(0).toString().toInt();                   //取第一列 ,salary_id(不需要)
    int employee_id =  query.value(1).toString().toInt();          //取第二列 ,employee_id
    int baseSalary =  query.value(2).toString().toInt();           //取第三列 ,基本工资
    int postSalary = query.value(3).toString().toInt();            //取第四列 ,岗位工资
    int meritSalary = query.value(4).toString().toInt();           //取第五列 ,绩效工资
    int socialSecurity = query.value(5).toString().toInt();        //取第六列 ,社保扣款
    int fullAttBonus = query.value(6).toString().toInt();          //取第七列 ,全勤奖
    int absentDeduction = query.value(7).toString().toInt();       //取第八列 ,旷工扣款
    int lateDeduction = query.value(8).toString().toInt();         //取第九列 ,迟到扣款
    int earlyDeduction = query.value(9).toString().toInt();        //取第十列 ,早退扣款
    int overtimeBonus = query.value(10).toString().toInt();        //取第十一列 ,加班费
    int beforeTax = query.value(11).toString().toInt();            //取第十二列 ,应发工资
    int afterTax = query.value(12).toString().toInt();             //取第十三列 ,实发工资
    string salaryDate  = query.value(13).toString().toStdString();  //取第十四列 ,工资日期
    qDebug("salaryDate = %s\n",salaryDate.data());
    Salary result(id,employee_id,baseSalary,postSalary,meritSalary,socialSecurity,fullAttBonus,absentDeduction,
                   lateDeduction,earlyDeduction,overtimeBonus,beforeTax,afterTax,salaryDate);
    qDebug("result date  = %d / %d / %d\n",result.getSalaryDate().year,result.getSalaryDate().month,result.getSalaryDate().day);
    return result;
}

bool SalaryDAO::updateSalary(const Salary &salary){
    QSqlQuery query;
    query.prepare("update salary set `employee_id` = :employee_id, "
                                        "`base_salary` = :base_salary, "
                                        "`post_salary` = :post_salary, "
                                        "`merit_salary` = :merit_salary, "
                                        "`social_security` = :social_security, "
                                        "`full_att_bonus`  = :full_att_bonus,"
                                        "`absent_deduction` = :absent_deduction, "
                                        "`late_deduction` = :late_deduction, "
                                        "`early_deduction` = :early_deduction, "
                                        "`overtime_bonus` = :overtime_bonus, "
                                        "`before_tax` = :before_tax, "
                                        "`after_tax` = :after_tax, "
                                        "`salary_date` = :salary_date "
                                        " where salary_id = :id"); //准备执行SQL查询
    //属性绑定
    query.bindValue(":id",salary.getSalaryId());
    query.bindValue(":employee_id",salary.getEmployeeId());
    query.bindValue(":base_salary",salary.getBaseSalary());
    query.bindValue(":post_salary",salary.getPostSalary());
    query.bindValue(":merit_salary",salary.getMeritSalary());
    query.bindValue(":social_security",salary.getSocialSecurity());
    query.bindValue(":full_att_bonus",salary.getFullAttBonus());
    query.bindValue(":absent_deduction",salary.getAbsentDeduction());
    query.bindValue(":late_deduction",salary.getLateDeduction());
    query.bindValue(":early_deduction",salary.getEarlyDeduction());
    query.bindValue(":overtime_bonus",salary.getOvertimeBonus());
    query.bindValue(":before_tax",salary.getBeforeTax());
    query.bindValue(":after_tax",salary.getAfterTax());
    qDebug("日期= %d / %d / %d\n",salary.getSalaryDate().year,salary.getSalaryDate().month,salary.getSalaryDate().day);
    string strDate = to_string(salary.getSalaryDate().year)+"-"+to_string(salary.getSalaryDate().month)+"-"+to_string(salary.getSalaryDate().day);
    query.bindValue(":salary_date",QString::fromStdString(strDate));
    qDebug("日期= %s\n",strDate.data());

    qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    qDebug("SQL语句执行:  %d\n",result);
    return result;
}

bool SalaryDAO::addSalary(const Salary &salary){
    QSqlQuery query;
    query.prepare("insert into salary(employee_id,base_salary,post_salary,merit_salary,social_security,"
                  "full_att_bonus,absent_deduction,late_deduction,early_deduction,overtime_bonus,before_tax,after_tax,salary_date) "
                  "values(:employee_id, "
                  ":base_salary, "
                  ":post_salary, "
                  ":merit_salary, "
                  ":social_security, "
                  ":full_att_bonus, "
                  ":absent_deduction, "
                  ":late_deduction,"
                  ":early_deduction,"
                  ":overtime_bonus,"
                  ":before_tax,"
                  ":after_tax,"
                  ":salary_date )"); //准备执行SQL查询
    //属性绑定
    //query.bindValue(":id",salary.getSalaryId());//id自增，不能指定ID
    query.bindValue(":employee_id",salary.getEmployeeId());
    query.bindValue(":base_salary",salary.getBaseSalary());
    query.bindValue(":post_salary",salary.getPostSalary());
    query.bindValue(":merit_salary",salary.getMeritSalary());
    query.bindValue(":social_security",salary.getSocialSecurity());
    query.bindValue(":full_att_bonus",salary.getFullAttBonus());
    query.bindValue(":absent_deduction",salary.getAbsentDeduction());
    query.bindValue(":late_deduction",salary.getLateDeduction());
    query.bindValue(":early_deduction",salary.getEarlyDeduction());
    query.bindValue(":overtime_bonus",salary.getOvertimeBonus());
    query.bindValue(":before_tax",salary.getBeforeTax());
    query.bindValue(":after_tax",salary.getAfterTax());
    string strDate = to_string(salary.getSalaryDate().year)+"-"+to_string(salary.getSalaryDate().month)+"-"+to_string(salary.getSalaryDate().day);
    query.bindValue(":salary_date",QString::fromStdString(strDate));
    qDebug("日期= %s\n",strDate.data());
    qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    qDebug("SQL语句执行:  %d\n",result);
    return result;
}

bool SalaryDAO::deleteSalary(const int id){
    QSqlQuery query;
    query.prepare("delete from salary where salary_id = :id"); //准备执行SQL查询
    query.bindValue(":id",id);
    //qDebug("%s",query.lastQuery().toStdString().data());
    bool result = query.exec();
    //qDebug("SQL语句执行:  %d\n",result);
    return result;
}
