#include "AddStuInfoDlg.h"
#include "ui_AddStuInfoDlg.h"

#include <QMessageBox>

AddStuInfoDlg::AddStuInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStuInfoDlg),
    isUpdate(false)
{
    ui->setupUi(this);

    //界面设置
    ui->edtId->setPlaceholderText("请输入四位数字的学号");
    ui->edtPhone->setPlaceholderText("请输入长度为11位的手机号");
    ui->cmbSex->addItem("男");
    ui->cmbSex->addItem("女");
    ui->spbCet4->setRange(0,750);
    ui->spbGpa->setRange(0.0,4.0);

    //输入规则设置
    //学号 要求：四位数字
    QRegularExpression regExp("^[0-9]{4}$");
    ui->edtId->setValidator(new QRegularExpressionValidator(regExp,this));

    //名字 要求中文或字母
    QRegularExpression regExpName("^[A-Za-z\u4e00-\u9fa5]{0,}$");
    ui->edtName->setValidator(new QRegularExpressionValidator(regExpName,this));

    //手机号 非0开头的11位数字
    QRegExp regExpPhone("^[1-9][0-9]{10}$");
    ui->edtPhone->setValidator(new QRegExpValidator(regExpPhone,this));


    setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);

}

AddStuInfoDlg::~AddStuInfoDlg()
{
    delete ui;
}

bool AddStuInfoDlg::setData(int id, QString name, QString sex, QString phone, int cet4, double gpa)
{
    QString _id = QString("%1").arg(id,4,10,QLatin1Char('0'));
    ui->edtId->setText(_id);
    ui->edtId->setReadOnly(true);
    ui->edtName->setText(name);
    ui->cmbSex->setCurrentText(sex);
    ui->edtPhone->setText(phone);
    ui->spbCet4->setValue(cet4);
    ui->spbGpa->setValue(gpa);

    return true;
}

bool AddStuInfoDlg::clearText()
{
    ui->edtId->clear();
    ui->edtName->clear();
    ui->edtPhone->clear();
    ui->spbCet4->setValue(0);
    ui->spbGpa->setValue(0.0);

    return true;
}

void AddStuInfoDlg::on_btnConfirm_clicked()
{
    CStuInfo stuInfo;
    QString id = ui->edtId->text();
    if(id.size()!=4){
        QMessageBox::information(this,"提示","学号输入不合规,\n请输入四位数字的学号！！！");
        return;
    }
    QString name = ui->edtName->text();
    if(name==""){
        QMessageBox::information(this,"提示","名字不能为空！！！");
        return;
    }
    QString sex = ui->cmbSex->currentText();
    QString phone = ui->edtPhone->text();
    if(phone.size()!=11){
        QMessageBox::information(this,"提示","手机号输入不合规，\n请输入11位数字的手机号");
        return;
    }

    int cet4 = ui->spbCet4->value();
    double gpa = ui->spbGpa->value();
    stuInfo.setData(id.toInt(),name,sex,phone,cet4,gpa);

    if(!isUpdate)
    {
        emit sig_addStuInfo(stuInfo);
    }
    else
    {
        emit sig_updateStuInfo(stuInfo);
    }
    if(!isUpdate)
        clearText();
}

void AddStuInfoDlg::on_btnCancel_clicked()
{

    clearText();
    close();
}

void AddStuInfoDlg::setIsUpdate(bool value)
{
    isUpdate = value;
}
