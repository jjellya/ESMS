#ifndef USER_H
#define USER_H


#include "Global.h"

class User {
public:
    User();

    User(string,string,string);

    virtual ~User();

    const string &getUserId() const;

    void setUserId(const string &userId);

    const string &getUserPwd() const;

    void setUserPwd(const string &userPwd);

    const string &getUserName() const;

    void setUserName(const string &userName);

private:
    //用户ID
    string user_id;
    //用户密码
    string user_pwd;
    //用户名
    string user_name;
};

#endif // USER_H
