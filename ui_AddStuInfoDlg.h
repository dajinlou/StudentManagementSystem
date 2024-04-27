/********************************************************************************
** Form generated from reading UI file 'AddStuInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUINFODLG_H
#define UI_ADDSTUINFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddStuInfoDlg
{
public:
    QPushButton *btnConfirm;
    QPushButton *btnCancel;
    QLabel *label_6;
    QDoubleSpinBox *spbGpa;
    QLabel *label;
    QLineEdit *edtId;
    QLineEdit *edtName;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *cmbSex;
    QLabel *label_4;
    QLineEdit *edtPhone;
    QLabel *label_5;
    QSpinBox *spbCet4;

    void setupUi(QDialog *AddStuInfoDlg)
    {
        if (AddStuInfoDlg->objectName().isEmpty())
            AddStuInfoDlg->setObjectName(QString::fromUtf8("AddStuInfoDlg"));
        AddStuInfoDlg->resize(334, 349);
        btnConfirm = new QPushButton(AddStuInfoDlg);
        btnConfirm->setObjectName(QString::fromUtf8("btnConfirm"));
        btnConfirm->setGeometry(QRect(50, 300, 93, 28));
        btnCancel = new QPushButton(AddStuInfoDlg);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(170, 300, 93, 28));
        label_6 = new QLabel(AddStuInfoDlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(61, 251, 39, 16));
        spbGpa = new QDoubleSpinBox(AddStuInfoDlg);
        spbGpa->setObjectName(QString::fromUtf8("spbGpa"));
        spbGpa->setGeometry(QRect(112, 251, 72, 21));
        spbGpa->setMinimumSize(QSize(60, 0));
        label = new QLabel(AddStuInfoDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(61, 41, 45, 16));
        edtId = new QLineEdit(AddStuInfoDlg);
        edtId->setObjectName(QString::fromUtf8("edtId"));
        edtId->setGeometry(QRect(112, 41, 171, 21));
        edtName = new QLineEdit(AddStuInfoDlg);
        edtName->setObjectName(QString::fromUtf8("edtName"));
        edtName->setGeometry(QRect(112, 81, 171, 21));
        label_2 = new QLabel(AddStuInfoDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(61, 81, 45, 16));
        label_3 = new QLabel(AddStuInfoDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(61, 121, 45, 16));
        cmbSex = new QComboBox(AddStuInfoDlg);
        cmbSex->setObjectName(QString::fromUtf8("cmbSex"));
        cmbSex->setGeometry(QRect(112, 121, 94, 21));
        cmbSex->setMinimumSize(QSize(94, 0));
        label_4 = new QLabel(AddStuInfoDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(47, 162, 60, 16));
        edtPhone = new QLineEdit(AddStuInfoDlg);
        edtPhone->setObjectName(QString::fromUtf8("edtPhone"));
        edtPhone->setGeometry(QRect(112, 162, 171, 21));
        label_5 = new QLabel(AddStuInfoDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(62, 212, 40, 16));
        spbCet4 = new QSpinBox(AddStuInfoDlg);
        spbCet4->setObjectName(QString::fromUtf8("spbCet4"));
        spbCet4->setGeometry(QRect(112, 212, 72, 21));
        spbCet4->setMinimumSize(QSize(60, 0));

        retranslateUi(AddStuInfoDlg);

        QMetaObject::connectSlotsByName(AddStuInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *AddStuInfoDlg)
    {
        AddStuInfoDlg->setWindowTitle(QCoreApplication::translate("AddStuInfoDlg", "\346\267\273\345\212\240/\344\277\256\346\224\271", nullptr));
        btnConfirm->setText(QCoreApplication::translate("AddStuInfoDlg", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("AddStuInfoDlg", "\345\217\226\346\266\210", nullptr));
        label_6->setText(QCoreApplication::translate("AddStuInfoDlg", "gpa\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("AddStuInfoDlg", "\345\255\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("AddStuInfoDlg", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("AddStuInfoDlg", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("AddStuInfoDlg", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("AddStuInfoDlg", "cet4:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStuInfoDlg: public Ui_AddStuInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUINFODLG_H
