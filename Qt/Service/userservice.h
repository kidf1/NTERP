﻿#ifndef USERSERVICE_H
#define USERSERVICE_H
#include "service_global.h"


class SERVICESHARED_EXPORT UserService
{
public:
    UserService();
    static User newUser(const QJsonObject para, bool &ok, QString hostname, QString hostport);
    static User modUser(const QJsonObject para, bool &ok, QString hostname, QString hostport);
    static User outUser(const QJsonObject para, bool &ok, QString hostname, QString hostport);
    static User delUser(const QJsonObject para, bool &ok, QString hostname, QString hostport);
    static QJsonObject toJsonObject(User user);
    static User fromJsonObject(QJsonObject obj);

    static bool exportUser(QVector<User> list);
    static bool printUser(QVector<User> list);

};

#endif // USERSERVICE_H
