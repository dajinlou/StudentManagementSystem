#ifndef ADDSTUINFODLG_H
#define ADDSTUINFODLG_H
#include "CStuInfo.h"

#include <QDialog>

namespace Ui {
class AddStuInfoDlg;
}
class CStuInfo;

class AddStuInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddStuInfoDlg(QWidget *parent = nullptr);
    ~AddStuInfoDlg();

    bool setData(int id,QString name,QString sex,QString phone,int cet4,double gpa);
    /**
     * @brief 清空文本
     * @return true-成功，false-失败
     */
    bool clearText();

    void setIsUpdate(bool value);

signals:
    void sig_addStuInfo(CStuInfo &stuInfo);
    void sig_updateStuInfo(CStuInfo &stuInfo);

private slots:
    void on_btnConfirm_clicked();

    void on_btnCancel_clicked();

private:
    Ui::AddStuInfoDlg *ui;
    bool isUpdate;  //是否是修改操作
};
#endif // ADDSTUINFODLG_H
