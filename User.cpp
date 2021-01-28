#include "User.h"

User::User() {}

User::User(string id,string password,string name):user_id(id),user_pwd(password),user_name(name){}

User::~User() {

}

const string &User::getUserId() const {
    return user_id;
}

void User::setUserId(const string &userId) {
    user_id = userId;
}

const string &User::getUserPwd() const {
    return user_pwd;
}

void User::setUserPwd(const string &userPwd) {
    user_pwd = userPwd;
}

const string &User::getUserName() const {
    return user_name;
}

void User::setUserName(const string &userName) {
    user_name = userName;
}
