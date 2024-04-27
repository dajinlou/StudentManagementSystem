#include "CQSpinBoxDelegate.h"

#include <QSpinBox>

CQSpinBoxDelegate::CQSpinBoxDelegate(QObject *parent):QStyledItemDelegate(parent)
{

}

QWidget *CQSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    QSpinBox *spinBox = new QSpinBox(parent); //0~750
    spinBox->setRange(0,750);
    return spinBox;
}
//将模型中的数据赋值给编辑器
void CQSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    //1.拿到编辑器
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    //2.拿到模型中的数据
    int val = index.model()->data(index,Qt::DisplayRole).toInt();
    //3.放到编辑器中
    spinBox->setValue(val);
}
//将编辑器的值再赋值给模型
void CQSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    //1.拿到编辑器
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    int val = spinBox->value();
    model->setData(index,val);
}

void CQSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)

    editor->setGeometry(option.rect);
}
