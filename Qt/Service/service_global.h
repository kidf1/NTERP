﻿#ifndef SERVICE_GLOBAL_H
#define SERVICE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>
#include <QVector>



#if defined(SERVICE_LIBRARY)
#  define SERVICESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SERVICESHARED_EXPORT Q_DECL_IMPORT
#endif



struct OderFlow{
    QString UserName;   //用户姓名
    QString OpreatTime; //操作时间
    QString Action;     //动作
    QString Status;     //状态
};


struct Order{
    QString           UID;            //用户id
    QString           UserName;       //用户姓名
    QString           OrderID;        //订单id
    QString           OrderType;      //订单类型（普通订单、批量订单、试样订单）
    QString           MaterielID;     //材料id
    QString           MaterielDes;    //材料描述
    QString           Unit;           //单位
    QString           CustomID;       //客户ID
    QString           CustomName;     //客户姓名
    QString           CustomBatch;    //客户批次
    QString           CustomNote;     //客户备注
    QString           ProduceID;      //生产编号
    QString           SuccessTime;    //出货时间
    QString           CreatTime;      //创建时间
    OderFlow          Current;        //当前状态
    QVector<OderFlow> Flow;           //订单流程
    int               OrderNum;       //订单数量
    int               Money;          //价格
};

struct User {
    QString UID;        //用户id
    QString Name;       //用户姓名
    QString Author;     //用户权限
};


//客户
struct Customer{
    QString CID;                    //客户编号
    QString Name;                   //客户姓名
    QString Icon;                   //客户logo
    QString Addr;                   //客户地址
    QString Tel;                    //联系电话
    QString BankName;               //开户行
    QString BankNumber;             //银行卡号
    QString Bankbranch;             //银行支行
    QString Certificates;           //客户证件（营业执照）
    QString Note;                   //备注
};

//供应商
struct Supplier{
    QString SID;                    //客户编号
    QString Name;                   //客户姓名
    QString Icon;                   //客户logo
    QString Addr;                   //客户地址
    QString Tel;                    //联系电话
    QString BankName;               //开户行
    QString BankNumber;             //银行卡号
    QString Bankbranch;             //银行支行
    QString Certificates;           //客户证件（营业执照）
    QString Note;                   //备注
    QVector<QString> Goods;         //供应的商品列表
};

//物料
struct Materiel{
    QString MaterID;            //物料编号
    QString MaterDes;           //物料描述
};




















#endif // SERVICE_GLOBAL_H