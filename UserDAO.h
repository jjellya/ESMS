#ifndef USERDAO_H
#define USERDAO_H

#include"User.h"

class UserDAO
{
public:
    UserDAO();
    /*实现了 */
    User* getAllUser();//获取全部用户
    User getUserById(string);//通过Id获取用户
};

#endif // USERDAO_H
