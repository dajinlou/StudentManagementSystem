#ifndef CSTUINFO_H
#define CSTUINFO_H

#include <QString>
#include <QMetaType>

class CStuInfo
{
public:
    CStuInfo();

    /**
     * @brief 设置学生数据
     * @param id[in] 学号
     * @param name[in] 姓名
     * @param sex[in] 性别
     * @param phone[in] 手机号
     * @param cet4[in] 四级
     * @param gpa[in]
     * @return true - 成功，false-失败
     */
    int setData(int id,QString name,QString sex,QString phone,int cet4,double gpa);

    /**
     * @brief 设置id
     * @param id[in] 学号
     * @return true-成功，false-失败
     */
    bool setId(int id);
    int id() const;

    bool setPhone(const QString &phone);
    QString phone() const;

    QString name() const;
    void setName(const QString &name);

    QString sex() const;
    void setSex(const QString &sex);

    int cet4() const;
    void setCet4(int cet4);

    double gpa() const;
    void setGpa(double gpa);

    double overallScore() const;
    void setOverallScore(double overallScore);

private:
    int m_id;              //学生ID(4位数字)
    QString m_name;        //学生姓名
    QString m_sex;         //学生性别
    QString m_phone;       //学生手机号[11位，且不能为0开头]
    int m_cet4;            //英语四级[0~750]
    double m_gpa;          //gpa[0~4]
    double m_overallScore; //综合成绩= 0.04*cet4 + gpa*17.5;
};
Q_DECLARE_METATYPE(CStuInfo)
#endif // CSTUINFO_H

