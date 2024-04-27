#ifndef CQSPINBOXDELEGATE_H
#define CQSPINBOXDELEGATE_H

#include <QStyledItemDelegate>


class CQSpinBoxDelegate : public QStyledItemDelegate
{
public:
    CQSpinBoxDelegate(QObject *parent = NULL);

    // QAbstractItemDelegate interface
public:
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // CQSPINBOXDELEGATE_H
