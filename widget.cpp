#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_dataSouce(NULL)
    , m_standModel(NULL)
    , m_addStuInfoDlg(NULL)
    , m_pSpinBaoDelegate(NULL)
{
    ui->setupUi(this);
    qRegisterMetaType<CStuInfo>("CStuInfo");
    qRegisterMetaType<CStuInfo>("CStuInfo&");


    //实例化数据源
    m_dataSouce = new CDataSourceSQLite();
    //    m_dataSouce = new CDataSourceJSON();

    //实例化模型
    m_standModel = new QStandardItemModel(this);
    //实例化代理
    m_pSpinBaoDelegate = new CQSpinBoxDelegate(this);
    ui->tbStuInfo->setItemDelegateForColumn(4,m_pSpinBaoDelegate);
    //创建添加窗口
    m_addStuInfoDlg = new AddStuInfoDlg(this);

    //菜单初始化
    m_menu = new QMenu(this);
    m_actUpdate = new QAction("修改",this);
    m_actDelete = new QAction("删除",this);
    m_menu->addAction(m_actUpdate);
    m_menu->addAction(m_actDelete);

    ui->tbStuInfo->setContextMenuPolicy(Qt::CustomContextMenu);

    //关联槽函数
    connect(m_standModel,&QStandardItemModel::itemChanged,this,&Widget::slot_itemCheckedChanged);
    connect(m_addStuInfoDlg,&AddStuInfoDlg::sig_addStuInfo,this,&Widget::slot_addStuInfo);
    connect(m_addStuInfoDlg,&AddStuInfoDlg::sig_updateStuInfo,this,&Widget::slot_updateStuInfoToDB);
    connect(m_actUpdate,&QAction::triggered,this,&Widget::slot_updateStuInfo);
    connect(m_actDelete,&QAction::triggered,this,&Widget::slot_deleteStuInfo);
    connect(ui->tbStuInfo,&QTableView::customContextMenuRequested,this,&Widget::slot_popMenu);

    initUI();
}

Widget::~Widget()
{
    delete m_dataSouce;
    delete ui;
}

bool Widget::appendStuInfoToModel(CStuInfo &stuInfo)
{
    QStandardItem* itemId = new QStandardItem(QString("%1").arg(stuInfo.id(),4,10,QLatin1Char('0')));
    itemId->setCheckable(true);
    itemId->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    itemId->setEditable(false);
    QStandardItem* itemName = new QStandardItem(stuInfo.name());
    itemName->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    QStandardItem* itemSex = new QStandardItem(stuInfo.sex());
    itemSex->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    QStandardItem* itemPhone = new QStandardItem(stuInfo.phone());
    itemPhone->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    QStandardItem* itemCet4 = new QStandardItem(QString::number(stuInfo.cet4()));
    itemCet4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//    itemCet4->setEditable(false);
    QStandardItem* itemGpa = new QStandardItem(QString::number(stuInfo.gpa()));
    itemGpa->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    QStandardItem* itemOverallScore = new QStandardItem(QString::number(stuInfo.overallScore()));
    itemOverallScore->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    QList<QStandardItem*> itemRow;
    itemRow.append(itemId);
    itemRow.append(itemName);
    itemRow.append(itemSex);
    itemRow.append(itemPhone);
    itemRow.append(itemCet4);
    itemRow.append(itemGpa);
    itemRow.append(itemOverallScore);
    m_standModel->appendRow(itemRow);

    return true;
}

bool Widget::delTips()
{
    QMessageBox::StandardButton chooseButton = QMessageBox::information(this,"提示","你真的确定要删除吗？？？？",QMessageBox::Yes|QMessageBox::No);
    if(chooseButton == QMessageBox::Yes)
    {
        return true;
    }
    else {
        return false;
    }
}

void Widget::resizeEvent(QResizeEvent *event)
{
    //设置列宽要放到setModel之后
    for(int col = 0;col<CONST_COLUMN_SIZE;++col)
        ui->tbStuInfo->setColumnWidth(col,(width()-30)/CONST_COLUMN_SIZE);

    QWidget::resizeEvent(event);
}

void Widget::initUI()
{

    //设置表头
    QStringList headStr;
    headStr<<"学号"<<"姓名"<<"性别"<<"手机号"<<"CET4"<<"GPA"<<"综合成绩";
    m_standModel->setHorizontalHeaderLabels(headStr);
    //隐藏垂直表头
    ui->tbStuInfo->verticalHeader()->setVisible(false);
    //不可编辑
//    ui->tbStuInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //获取数据
    QList<CStuInfo> outResult;
    m_dataSouce->selectStuInfo(outResult);
    for(int i=0;i<outResult.size();++i)
    {
        appendStuInfoToModel(outResult[i]);
    }
    ui->tbStuInfo->setModel(m_standModel);

    //设置列宽要放到setModel之后
    for(int col = 0;col<CONST_COLUMN_SIZE;++col)
        ui->tbStuInfo->setColumnWidth(col,(width()-30)/CONST_COLUMN_SIZE);
}


bool Widget::slot_itemCheckedChanged(QStandardItem *item)
{
    if(m_standModel->indexFromItem(item).column()>0)
    {
        int row = m_standModel->indexFromItem(item).row();
        CStuInfo stuInfo;
        stuInfo.setId(m_standModel->item(row,0)->data(Qt::DisplayRole).toInt());
        stuInfo.setName(m_standModel->item(row,1)->data(Qt::DisplayRole).toString());
        stuInfo.setSex(m_standModel->item(row,2)->data(Qt::DisplayRole).toString());
        stuInfo.setPhone(m_standModel->item(row,3)->data(Qt::DisplayRole).toString());
        stuInfo.setCet4(m_standModel->item(row,4)->data(Qt::DisplayRole).toInt());
        stuInfo.setGpa(m_standModel->item(row,5)->data(Qt::DisplayRole).toDouble());
        stuInfo.setOverallScore(m_standModel->item(row,6)->data(Qt::DisplayRole).toDouble());
        qDebug()<<m_dataSouce->updateStuInfo(stuInfo);
        return false;
    }
    //判断是否全选了
    for(int i=0;i<m_standModel->rowCount();++i)
    {
        if(m_standModel->item(i)->checkState()!=Qt::Checked)
        {
            ui->chkSelectAll->setCheckState(Qt::Unchecked);
            return false;
        }
    }
    ui->chkSelectAll->setCheckState(Qt::Checked);
    return true;
}

void Widget::on_chkSelectAll_clicked(bool checked)
{
    for(int i=0;i<m_standModel->rowCount();++i)
    {
        if(checked)
            m_standModel->item(i)->setCheckState(Qt::Checked);
        else
            m_standModel->item(i)->setCheckState(Qt::Unchecked);
    }
}

bool Widget::slot_addStuInfo(CStuInfo &stuInfo)
{
    bool res =  m_dataSouce->addStuInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this,"提示","学号已经存在，添加信息失败！！！");
        return false;
    }
    //添加成功后，就不在重新查询数据库了，而是直接添加到model的末尾
    appendStuInfoToModel(stuInfo);

    return true;
}

bool Widget::slot_updateStuInfoToDB(CStuInfo &stuInfo)
{
    bool res = m_dataSouce->updateStuInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this,"提示","修改学生信息失败！！！");
        return false;
    }
    else
    {
        //修改Model中的数据
        int row = ui->tbStuInfo->currentIndex().row();
        m_standModel->setData(m_standModel->item(row,1)->index(),stuInfo.name());
        m_standModel->setData(m_standModel->item(row,2)->index(),stuInfo.sex());
        m_standModel->setData(m_standModel->item(row,3)->index(),stuInfo.phone());
        m_standModel->setData(m_standModel->item(row,4)->index(),stuInfo.cet4());
        m_standModel->setData(m_standModel->item(row,5)->index(),stuInfo.gpa());
        m_standModel->setData(m_standModel->item(row,6)->index(),stuInfo.overallScore());

        QMessageBox::information(this,"提示","恭喜你，修改学生信息成功！！！");
    }

    return true;
}

bool Widget::slot_updateStuInfo()
{
    int row = ui->tbStuInfo->currentIndex().row();
    int itemId = m_standModel->item(row,0)->text().toInt();
    QString itemName = m_standModel->item(row,1)->text();
    QString itemSex = m_standModel->item(row,2)->text();
    QString itemPhone = m_standModel->item(row,3)->text();
    int itemCet4 = m_standModel->item(row,4)->text().toInt();
    double itemGpa = m_standModel->item(row,5)->text().toDouble();
    m_addStuInfoDlg->setData(itemId,itemName,itemSex,itemPhone,itemCet4,itemGpa);
    m_addStuInfoDlg->setIsUpdate(true);
    m_addStuInfoDlg->show();
    return true;
}

bool Widget::slot_deleteStuInfo()
{
    bool res = delTips();
    if(res)
    {
        //删除
        int row =  ui->tbStuInfo->currentIndex().row();
        int id = m_standModel->item(row)->text().toInt();
        m_dataSouce->deleteStuInfo(id);
        m_standModel->removeRow(row);
    }
    return true;
}

bool Widget::slot_popMenu(const QPoint &pos)
{
    if(m_standModel->itemFromIndex(ui->tbStuInfo->indexAt(pos))!=NULL)
        m_menu->exec(QCursor::pos());
    return true;
}

void Widget::on_btnAdd_clicked()
{
    m_addStuInfoDlg->setIsUpdate(false);
    m_addStuInfoDlg->show();
}

void Widget::on_btnDelete_clicked()
{
    //记录将要删除的行和存储学号的item
    QMap<int,QStandardItem*> delRows;
    for(int i=0;i<m_standModel->rowCount();++i){
        QStandardItem *item = m_standModel->item(i,0);
        if(item->checkState()==Qt::Checked)
        {
            delRows.insert(i,item);
        }
    }
    if(delRows.size()==0)
        return;

    bool res = delTips();
    if(!res)
    {
        return;
    }
    //从model中删除选中的行
    QList<int> ids = delRows.keys();
    for (int i=ids.size()-1;i>=0;i--) {
        //删除数据库中的数据
        m_dataSouce->deleteStuInfo(delRows.value(ids[i])->text().toInt());
        //从Model中移除
        m_standModel->removeRow(ids[i]);
    }

}
