#ifndef WIDGET_H
#define WIDGET_H
#include"CDataSourceSQLite.h"
#include "AddStuInfoDlg.h"
#include "CStuInfo.h"
#include "CQSpinBoxDelegate.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

const int CONST_COLUMN_SIZE = 7;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    /**
     * @brief 向model中追加数据
     * @param stuInfo 学生数据
     * @return true-成功，false-失败
     */
    bool appendStuInfoToModel(CStuInfo &stuInfo);

    /**
     * @brief 删除提示
     * @return
     */
    bool delTips();

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:

    /**
     * @brief 勾选信息发送变化
     * @param item 发送变化的单元格项
     * @return
     */
    bool slot_itemCheckedChanged(QStandardItem *item);

    /**
     * @brief 点击“全选”复选框，勾选所有的学生信息
     * @param checked 是否勾选
     */
    void on_chkSelectAll_clicked(bool checked);

    /**
     * @brief 添加学生信息槽函数
     * @param stuInfo 学生信息
     * @return true-成功，false-失败
     */
    bool slot_addStuInfo(CStuInfo &stuInfo);

    /**
     * @brief 修改数据源中的数据
     * @param stuInfo
     * @return
     */
    bool slot_updateStuInfoToDB(CStuInfo &stuInfo);

    /**
     * @brief 菜单“修改”项槽函数
     * @return true-成功，false-失败
     */
    bool slot_updateStuInfo();

    /**
    * @brief 菜单“删除”项槽函数
    * @return true-成功，false-失败
    */
   bool slot_deleteStuInfo();

   /**
    * @brief 右键弹出菜单
    * @param pos 位置
    * @return
    */
   bool slot_popMenu(const QPoint &pos);

    /**
     * @brief 点击“添加”按钮，添加学生信息
     */
    void on_btnAdd_clicked();

    /**
     * @brief 点击“删除”按钮，删除勾选的学生信息
     */
    void on_btnDelete_clicked();

private:
    /**
     * @brief 初始化界面数据
     */
    void initUI();

private:
    Ui::Widget *ui;
    CDataSourceSQLite *m_dataSouce;   //数据源
    QStandardItemModel *m_standModel; //标准模型
    AddStuInfoDlg *m_addStuInfoDlg;   //添加学生信息窗口
    CQSpinBoxDelegate* m_pSpinBaoDelegate; //cet4列代理
    QMenu *m_menu;                    //菜单
    QAction *m_actUpdate;             //修改项
    QAction *m_actDelete;             //删除项


};
#endif // WIDGET_H
