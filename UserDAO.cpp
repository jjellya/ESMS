#include "UserDAO.h"
#include "QtSql"
#include "Global.h"
#include "User.h"

UserDAO::UserDAO()
{

}

/*
1.QString转换String:

string s = qstr.toStdString();

2.String转换QString:

QString qstr2 = QString::fromStdString(s);
*/
User* UserDAO::getAllUser(){
    User *result;
    result = new User[255];
    int i = 0;
    QSqlQuery query;
    query.exec("select * from user");
        while (true == query.next()) {  //一行一行遍历
            //取出当前行的内容，以列为单位
            qDebug() << query.value(0).toString() //取第一列
                     << query.value(1).toString() //取第二列
                     << query.value("user_name").toString()<<endl;  //按名字查找

            string id =  query.value(0).toString().toStdString();//取第一列
            string password =  query.value(1).toString().toStdString();//取第二列
            string name =  query.value(2).toString().toStdString();//取取第三列
            User user0;
            user0.setUserId(id); user0.setUserPwd(password);user0.setUserName(name);
            result [i++] = user0;
        }
        return result;
}

/*
Example:
QSqlQuery query;
query.prepare("INSERT INTO T_USER (name, age) VALUES (:name, :age)"); //准备执行SQL查询
query.bindValue(":name", "justin");   //在这定占位符上确定绑定的值
query.bindValue(":age", 33);
query.exec();

*/

User UserDAO::getUserById(string id){

QSqlQuery query;
query.prepare("select * from user where user_id = :id"); //准备执行SQL查询
query.bindValue(":id", QString::fromStdString(id));
query.exec();
if(true != query.next()) qDebug("id 为%s的用户不存在",id.data());
string tid =  query.value(0).toString().toStdString();//取第一列
string tpassword =  query.value(1).toString().toStdString();//取第二列
string tname =  query.value(2).toString().toStdString();//取取第三列

User result(tid,tpassword,tname);

return result;
}
