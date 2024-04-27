#include "CStuInfo.h"

CStuInfo::CStuInfo()
{

}

int CStuInfo::setData(int id, QString name, QString sex, QString phone, int cet4, double gpa)
{
    if(!setId(id))
        return false;  //学号不符合规定
    m_name = name;
    m_sex = sex;
    if(!setPhone(phone))
        return  false; //手机号不合法
    m_cet4 = cet4;
    m_gpa = gpa;
    m_overallScore = 0.04*m_cet4 + 17.5*m_gpa;

    return true;
}

bool CStuInfo::setId(int id)
{
    //判断数据是否符合要求【学号为四位数字】
    m_id = id;
    return true;
}

bool CStuInfo::setPhone(const QString &phone)
{
    //判断数据是否合法

    m_phone = phone;
    return true;
}

int CStuInfo::id() const
{
    return m_id;
}

QString CStuInfo::name() const
{
    return m_name;
}

void CStuInfo::setName(const QString &name)
{
    m_name = name;
}

QString CStuInfo::sex() const
{
    return m_sex;
}

void CStuInfo::setSex(const QString &sex)
{
    m_sex = sex;
}

QString CStuInfo::phone() const
{
    return m_phone;
}

int CStuInfo::cet4() const
{
    return m_cet4;
}

void CStuInfo::setCet4(int cet4)
{
    m_cet4 = cet4;
}

double CStuInfo::gpa() const
{
    return m_gpa;
}

void CStuInfo::setGpa(double gpa)
{
    m_gpa = gpa;
}

double CStuInfo::overallScore() const
{
    return m_overallScore;
}

void CStuInfo::setOverallScore(double overallScore)
{
    m_overallScore = overallScore;
}

