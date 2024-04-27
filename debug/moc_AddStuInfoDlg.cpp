/****************************************************************************
** Meta object code from reading C++ file 'AddStuInfoDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AddStuInfoDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddStuInfoDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddStuInfoDlg_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddStuInfoDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddStuInfoDlg_t qt_meta_stringdata_AddStuInfoDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AddStuInfoDlg"
QT_MOC_LITERAL(1, 14, 14), // "sig_addStuInfo"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "CStuInfo&"
QT_MOC_LITERAL(4, 40, 7), // "stuInfo"
QT_MOC_LITERAL(5, 48, 17), // "sig_updateStuInfo"
QT_MOC_LITERAL(6, 66, 21), // "on_btnConfirm_clicked"
QT_MOC_LITERAL(7, 88, 20) // "on_btnCancel_clicked"

    },
    "AddStuInfoDlg\0sig_addStuInfo\0\0CStuInfo&\0"
    "stuInfo\0sig_updateStuInfo\0"
    "on_btnConfirm_clicked\0on_btnCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddStuInfoDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddStuInfoDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddStuInfoDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_addStuInfo((*reinterpret_cast< CStuInfo(*)>(_a[1]))); break;
        case 1: _t->sig_updateStuInfo((*reinterpret_cast< CStuInfo(*)>(_a[1]))); break;
        case 2: _t->on_btnConfirm_clicked(); break;
        case 3: _t->on_btnCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddStuInfoDlg::*)(CStuInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddStuInfoDlg::sig_addStuInfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddStuInfoDlg::*)(CStuInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddStuInfoDlg::sig_updateStuInfo)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddStuInfoDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AddStuInfoDlg.data,
    qt_meta_data_AddStuInfoDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AddStuInfoDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddStuInfoDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddStuInfoDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddStuInfoDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddStuInfoDlg::sig_addStuInfo(CStuInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddStuInfoDlg::sig_updateStuInfo(CStuInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
