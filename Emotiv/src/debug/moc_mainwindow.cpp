/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 12. Sep 16:24:09 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      71,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     130,   11,   11,   11, 0x08,
     156,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0emotivComboActivated(QString)\0"
    "emotivConnectButtonPressed()\0"
    "emotivDisconnectButtonPressed()\0"
    "oscComboActivated(QString)\0"
    "oscConnectButtonPressed()\0"
    "oscDisconnectButtonPressed()\0"
    "HandleEmotivUpdate(EmoStateHandle)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: emotivComboActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: emotivConnectButtonPressed(); break;
        case 2: emotivDisconnectButtonPressed(); break;
        case 3: oscComboActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: oscConnectButtonPressed(); break;
        case 5: oscDisconnectButtonPressed(); break;
        case 6: HandleEmotivUpdate((*reinterpret_cast< EmoStateHandle(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE