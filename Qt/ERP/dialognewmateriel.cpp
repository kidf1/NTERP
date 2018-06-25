﻿#include "dialognewmateriel.h"
#include "ui_dialognewmateriel.h"
#include <QDateTime>
#include <QCompleter>


DialogNewMateriel::DialogNewMateriel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewMateriel)
{
    ui->setupUi(this);
    initCommbox();
    connect(ui->comboBox_friction,SIGNAL(currentTextChanged(QString)),this,SLOT(DesChange()));
    connect(ui->comboBox_thickness,SIGNAL(currentTextChanged(QString)),this,SLOT(DesChange()));
    connect(ui->comboBox_Salt,SIGNAL(currentTextChanged(QString)),this,SLOT(DesChange()));
    connect(ui->comboBox_type,SIGNAL(currentTextChanged(QString)),this,SLOT(DesChange()));



}

DialogNewMateriel::~DialogNewMateriel()
{
    delete ui;
}

void DialogNewMateriel::on_pushButton_ok_clicked()
{
    mater.MaterID = QString("%1").arg(QDateTime::currentDateTime().toMSecsSinceEpoch());
    mater.MaterDes = ui->textEdit->toPlainText();
    done(123);
}

void DialogNewMateriel::on_pushButton_cancle_clicked()
{
    done(-1);
}



void DialogNewMateriel::initCommbox()
{
    QStringList type;
    type<<"银色涂覆"<<"黑色涂覆"<<"绿色涂覆"<<"蓝白锌"<<"白锌"<<"封闭"<<"蓝白锌镍"<<"本色锌镍"<<"黑色镀锌"<<"去氢"<<"黑色锌镍";
    QCompleter *completertype = new QCompleter(type, this);
    ui->comboBox_type->clear();
    ui->comboBox_type->addItems(type);
    ui->comboBox_type->setEditable(true);
    ui->comboBox_type->setCompleter(completertype);

    QStringList friction;
    friction<<"0.06~0.09"<<"0.09~0.15"<<"0.08~0.14"<<"0.10~0.16"<<"0.12~0.18"<<"0.18以上";
    QCompleter *completerCus = new QCompleter(friction, this);
    ui->comboBox_friction->clear();
    ui->comboBox_friction->setEditable(true);
    ui->comboBox_friction->addItems(friction);
    ui->comboBox_friction->setCompleter(completerCus);

    QStringList salt;
    salt<<"120h(120/240h)"<<"480h(240/720h)"<<"500h(840h)"<<"1000h(240/1000h)";
    QCompleter *completersalt = new QCompleter(salt, this);
    ui->comboBox_Salt->clear();
    ui->comboBox_Salt->setEditable(true);
    ui->comboBox_Salt->addItems(salt);
    ui->comboBox_Salt->setCompleter(completersalt);

    QStringList thick;
    thick<<"5um以上(8~20um)"<<"8um以上(10~25um)"<<"10um以上(12~25um)"<<"12um以上(10~20um)"<<"13um以上(6~20um)";
    QCompleter *completerThickness= new QCompleter(thick, this);
    ui->comboBox_thickness->clear();
    ui->comboBox_thickness->setEditable(true);
    ui->comboBox_thickness->addItems(thick);
    ui->comboBox_thickness->setCompleter(completerThickness);

}

Materiel DialogNewMateriel::getMater() const
{
    return mater;
}


void DialogNewMateriel::on_pushButton_clear_clicked()
{
    ui->textEdit->clear();
}

void DialogNewMateriel::DesChange()
{
    QString str ;
    if(!ui->comboBox_type->currentText().isEmpty())
        str+= "/"+ui->comboBox_type->currentText();
    if(!ui->comboBox_thickness->currentText().isEmpty())
        str+= "/"+ui->comboBox_thickness->currentText();
    if(!ui->comboBox_Salt->currentText().isEmpty())
        str+= "/"+ui->comboBox_Salt->currentText();
    if(!ui->comboBox_friction->currentText().isEmpty())
        str+= "/"+ui->comboBox_friction->currentText();


    ui->textEdit->setText(str);
}


