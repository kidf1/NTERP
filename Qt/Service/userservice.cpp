﻿#include "userservice.h"
#include <QJsonObject>
UserService::UserService()
{

}


User UserService::newUser(const QJsonObject para, bool &ok, QString hostname, QString hostport)
{
#if 1
    User user;
    ok = true;
    return user;
#endif

#if 0
    User user;
    std::string url = Net_NewUser;
    bool r   = false;
    Ret ret  = Http::fetch(url,para,r,hostname,hostport);
    if(r&&ret.ret){
        if(ret.data.isObject()){
            user = fromJsonObject(ret.data.toObject());
            ok = true;
            return  user;
        }
    }
    if(!ret.ret)
        qDebug()<<"newUser ret is not 0";
    ok = false;
    return user;
#endif
}

User UserService::modUser(const QJsonObject para, bool &ok, QString hostname, QString hostport)
{
#if 1
    User user;
    ok = true;
    return user;
#endif
}

User UserService::outUser(const QJsonObject para, bool &ok, QString hostname, QString hostport)
{
#if 1
    User user;
    ok = true;
    return user;
#endif
}

User UserService::delUser(const QJsonObject para, bool &ok, QString hostname, QString hostport)
{
#if 1
    User user;
    ok = true;
    return user;
#endif
}



QJsonObject UserService::toJsonObject(User user)
{
    QJsonObject obj;
    obj.insert("UID",user.UID);
    obj.insert("Name",user.Name);
    obj.insert("Sex",user.Sex);
    obj.insert("Cell",user.Cell);
    obj.insert("CID",user.CID);
    obj.insert("CommpanyName",user.CommpanyName);
    obj.insert("Department",user.Department);
    obj.insert("Author",user.Author);
    obj.insert("InTime",user.InTime);
    obj.insert("OutTime",user.OutTime);
    obj.insert("CreatTime",user.CreatTime);
    obj.insert("Status",user.Status);
    obj.insert("Account",user.Account);
    obj.insert("Code",user.Code);
    obj.insert("Salary",user.Salary);
    obj.insert("Age",user.Age);

    return obj;

}

User UserService::fromJsonObject(QJsonObject obj)
{
    User user;
    if(obj.contains("UID")){
        QJsonValue value = obj.value("UID");
        if(value.isString())
            user.UID = value.toString();
    }
    if(obj.contains("Name")){
        QJsonValue value = obj.value("Name");
        if(value.isString())
            user.Name = value.toString();
    }
    if(obj.contains("Sex")){
        QJsonValue value = obj.value("Sex");
        if(value.isString())
            user.Sex = value.toString();
    }
    if(obj.contains("Cell")){
        QJsonValue value = obj.value("Cell");
        if(value.isString())
            user.Cell = value.toString();
    }
    if(obj.contains("CID")){
        QJsonValue value = obj.value("CID");
        if(value.isString())
            user.CID = value.toString();
    }
    if(obj.contains("CommpanyName")){
        QJsonValue value = obj.value("CommpanyName");
        if(value.isString())
            user.CommpanyName = value.toString();
    }
    if(obj.contains("Department")){
        QJsonValue value = obj.value("Department");
        if(value.isString())
            user.Department = value.toString();
    }
    if(obj.contains("Author")){
        QJsonValue value = obj.value("Author");
        if(value.isString())
            user.Author = value.toString();
    }
    if(obj.contains("InTime")){
        QJsonValue value = obj.value("InTime");
        if(value.isString())
            user.InTime = value.toString();
    }
    if(obj.contains("OutTime")){
        QJsonValue value = obj.value("OutTime");
        if(value.isString())
            user.OutTime = value.toString();
    }
    if(obj.contains("CreatTime")){
        QJsonValue value = obj.value("CreatTime");
        if(value.isString())
            user.CreatTime = value.toString();
    }
    if(obj.contains("Status")){
        QJsonValue value = obj.value("Status");
        if(value.isString())
            user.Status = value.toString();
    }
    if(obj.contains("Salary")){
        QJsonValue value = obj.value("Salary");
        if(value.isDouble())
            user.Department = value.toInt();
    }
    if(obj.contains("Age")){
        QJsonValue value = obj.value("Age");
        if(value.isDouble())
            user.Age = value.toInt();
    }
    if(obj.contains("Account")){
        QJsonValue value = obj.value("Account");
        if(value.isDouble())
            user.Account = value.toInt();
    }
    if(obj.contains("Code")){
        QJsonValue value = obj.value("Code");
        if(value.isDouble())
            user.Code = value.toInt();
    }
    return user;
}
