/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 12. Sep 16:24:09 2016
**      by: Qt User Interface Compiler version 4.6.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *emotivIPedit;
    QLineEdit *emotivPortEdit;
    QLineEdit *oscIPedit;
    QLineEdit *oscPortEdit;
    QComboBox *emotivCombo;
    QFrame *leftLine;
    QFrame *rightLine;
    QLabel *emotivLabel;
    QPushButton *emotivConnectButton;
    QPushButton *emotivDisconnectButton;
    QPushButton *oscConnectButton;
    QPushButton *oscDisconnectButton;
    QLabel *emotivConnectionStatusLabel;
    QLabel *cogLabel;
    QLineEdit *cogTypeLine;
    QLCDNumber *cogPowerLCD;
    QLabel *cogPowerLabel;
    QLabel *affLabel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *affEngageBoredLabel;
    QLabel *affFrustrationLabel;
    QLabel *affMeditationLabel;
    QLabel *affExciteLabel;
    QLabel *affExcitementLTLabel;
    QLCDNumber *affEngageBoredLCD;
    QLCDNumber *affFrustrationLCD;
    QLCDNumber *affMeditationLCD;
    QLCDNumber *affExcitementLCD;
    QLCDNumber *affExcitementLTLCD;
    QFrame *line;
    QFrame *line_2;
    QFrame *affLabelFrame;
    QFrame *cogLabelFrame;
    QFrame *emotivLabelFrame;
    QFrame *oscLabelFrame;
    QLabel *oscLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *expSmileLabel;
    QLabel *expClenchLabel;
    QLabel *expSmirkRightLabel;
    QLabel *expLaughLabel;
    QLabel *expSmirkLeftLabel;
    QLCDNumber *expSmileLCD;
    QLCDNumber *expClenchLCD;
    QLCDNumber *expSmirkLeftLCD;
    QLCDNumber *expSmirkRightLCD;
    QLCDNumber *expLaughLCD;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *expRaiseBrowLabel;
    QLCDNumber *expRaiseBrowLCD;
    QLabel *expFurrowBrowLabel;
    QLCDNumber *expFurrowBrowLCD;
    QFrame *frame_2;
    QFrame *frame_4;
    QFrame *frame_5;
    QFrame *frame_6;
    QFrame *frame_7;
    QFrame *frame_8;
    QFrame *frame_3;
    QCheckBox *expWinkLeftCheck;
    QCheckBox *expLookLeftCheck;
    QCheckBox *expWinkRightCheck;
    QCheckBox *expLookRightCheck;
    QLabel *expWinkRightLabel;
    QLabel *expLookRightLabel;
    QLabel *expLookLeftLabel;
    QLabel *expWinkLeftLabel;
    QLabel *expBlinkLabel;
    QCheckBox *expBlinkCheck;
    QFrame *expLabelFrame;
    QLabel *expLabel;
    QFrame *frame;
    QLabel *OSCConnectedLabel;
    QPushButton *cmdBtn;
    QPlainTextEdit *cmdLnEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(717, 562);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        emotivIPedit = new QLineEdit(centralWidget);
        emotivIPedit->setObjectName(QString::fromUtf8("emotivIPedit"));
        emotivIPedit->setGeometry(QRect(23, 200, 113, 20));
        emotivIPedit->setReadOnly(true);
        emotivPortEdit = new QLineEdit(centralWidget);
        emotivPortEdit->setObjectName(QString::fromUtf8("emotivPortEdit"));
        emotivPortEdit->setGeometry(QRect(23, 220, 113, 20));
        emotivPortEdit->setReadOnly(true);
        oscIPedit = new QLineEdit(centralWidget);
        oscIPedit->setObjectName(QString::fromUtf8("oscIPedit"));
        oscIPedit->setEnabled(false);
        oscIPedit->setGeometry(QRect(581, 200, 113, 20));
        oscIPedit->setReadOnly(true);
        oscPortEdit = new QLineEdit(centralWidget);
        oscPortEdit->setObjectName(QString::fromUtf8("oscPortEdit"));
        oscPortEdit->setEnabled(false);
        oscPortEdit->setGeometry(QRect(581, 220, 113, 20));
        oscPortEdit->setReadOnly(true);
        emotivCombo = new QComboBox(centralWidget);
        emotivCombo->setObjectName(QString::fromUtf8("emotivCombo"));
        emotivCombo->setGeometry(QRect(33, 150, 91, 22));
        leftLine = new QFrame(centralWidget);
        leftLine->setObjectName(QString::fromUtf8("leftLine"));
        leftLine->setGeometry(QRect(153, 20, 20, 507));
        leftLine->setFrameShape(QFrame::VLine);
        leftLine->setFrameShadow(QFrame::Sunken);
        rightLine = new QFrame(centralWidget);
        rightLine->setObjectName(QString::fromUtf8("rightLine"));
        rightLine->setGeometry(QRect(534, -7, 40, 553));
        rightLine->setFrameShape(QFrame::VLine);
        rightLine->setFrameShadow(QFrame::Sunken);
        emotivLabel = new QLabel(centralWidget);
        emotivLabel->setObjectName(QString::fromUtf8("emotivLabel"));
        emotivLabel->setGeometry(QRect(66, 107, 46, 13));
        emotivConnectButton = new QPushButton(centralWidget);
        emotivConnectButton->setObjectName(QString::fromUtf8("emotivConnectButton"));
        emotivConnectButton->setGeometry(QRect(83, 270, 75, 23));
        emotivDisconnectButton = new QPushButton(centralWidget);
        emotivDisconnectButton->setObjectName(QString::fromUtf8("emotivDisconnectButton"));
        emotivDisconnectButton->setGeometry(QRect(3, 270, 75, 23));
        oscConnectButton = new QPushButton(centralWidget);
        oscConnectButton->setObjectName(QString::fromUtf8("oscConnectButton"));
        oscConnectButton->setGeometry(QRect(639, 271, 75, 23));
        oscDisconnectButton = new QPushButton(centralWidget);
        oscDisconnectButton->setObjectName(QString::fromUtf8("oscDisconnectButton"));
        oscDisconnectButton->setGeometry(QRect(559, 270, 75, 23));
        emotivConnectionStatusLabel = new QLabel(centralWidget);
        emotivConnectionStatusLabel->setObjectName(QString::fromUtf8("emotivConnectionStatusLabel"));
        emotivConnectionStatusLabel->setGeometry(QRect(49, 114, 58, 16));
        cogLabel = new QLabel(centralWidget);
        cogLabel->setObjectName(QString::fromUtf8("cogLabel"));
        cogLabel->setGeometry(QRect(449, 69, 46, 13));
        cogTypeLine = new QLineEdit(centralWidget);
        cogTypeLine->setObjectName(QString::fromUtf8("cogTypeLine"));
        cogTypeLine->setGeometry(QRect(419, 104, 113, 20));
        cogTypeLine->setReadOnly(true);
        cogPowerLCD = new QLCDNumber(centralWidget);
        cogPowerLCD->setObjectName(QString::fromUtf8("cogPowerLCD"));
        cogPowerLCD->setGeometry(QRect(464, 132, 64, 27));
        cogPowerLCD->setSegmentStyle(QLCDNumber::Flat);
        cogPowerLabel = new QLabel(centralWidget);
        cogPowerLabel->setObjectName(QString::fromUtf8("cogPowerLabel"));
        cogPowerLabel->setGeometry(QRect(425, 134, 36, 16));
        affLabel = new QLabel(centralWidget);
        affLabel->setObjectName(QString::fromUtf8("affLabel"));
        affLabel->setGeometry(QRect(191, 17, 46, 13));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(200, 45, 178, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        affEngageBoredLabel = new QLabel(formLayoutWidget);
        affEngageBoredLabel->setObjectName(QString::fromUtf8("affEngageBoredLabel"));
        affEngageBoredLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, affEngageBoredLabel);

        affFrustrationLabel = new QLabel(formLayoutWidget);
        affFrustrationLabel->setObjectName(QString::fromUtf8("affFrustrationLabel"));
        affFrustrationLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, affFrustrationLabel);

        affMeditationLabel = new QLabel(formLayoutWidget);
        affMeditationLabel->setObjectName(QString::fromUtf8("affMeditationLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, affMeditationLabel);

        affExciteLabel = new QLabel(formLayoutWidget);
        affExciteLabel->setObjectName(QString::fromUtf8("affExciteLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, affExciteLabel);

        affExcitementLTLabel = new QLabel(formLayoutWidget);
        affExcitementLTLabel->setObjectName(QString::fromUtf8("affExcitementLTLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, affExcitementLTLabel);

        affEngageBoredLCD = new QLCDNumber(formLayoutWidget);
        affEngageBoredLCD->setObjectName(QString::fromUtf8("affEngageBoredLCD"));
        affEngageBoredLCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(0, QFormLayout::FieldRole, affEngageBoredLCD);

        affFrustrationLCD = new QLCDNumber(formLayoutWidget);
        affFrustrationLCD->setObjectName(QString::fromUtf8("affFrustrationLCD"));
        affFrustrationLCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(1, QFormLayout::FieldRole, affFrustrationLCD);

        affMeditationLCD = new QLCDNumber(formLayoutWidget);
        affMeditationLCD->setObjectName(QString::fromUtf8("affMeditationLCD"));
        affMeditationLCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(2, QFormLayout::FieldRole, affMeditationLCD);

        affExcitementLCD = new QLCDNumber(formLayoutWidget);
        affExcitementLCD->setObjectName(QString::fromUtf8("affExcitementLCD"));
        affExcitementLCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(3, QFormLayout::FieldRole, affExcitementLCD);

        affExcitementLTLCD = new QLCDNumber(formLayoutWidget);
        affExcitementLTLCD->setObjectName(QString::fromUtf8("affExcitementLTLCD"));
        affExcitementLTLCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(4, QFormLayout::FieldRole, affExcitementLTLCD);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(162, 196, 389, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(386, 1, 40, 202));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        affLabelFrame = new QFrame(centralWidget);
        affLabelFrame->setObjectName(QString::fromUtf8("affLabelFrame"));
        affLabelFrame->setGeometry(QRect(177, 14, 68, 22));
        affLabelFrame->setFrameShape(QFrame::StyledPanel);
        affLabelFrame->setFrameShadow(QFrame::Raised);
        cogLabelFrame = new QFrame(centralWidget);
        cogLabelFrame->setObjectName(QString::fromUtf8("cogLabelFrame"));
        cogLabelFrame->setGeometry(QRect(433, 66, 71, 21));
        cogLabelFrame->setFrameShape(QFrame::StyledPanel);
        cogLabelFrame->setFrameShadow(QFrame::Raised);
        emotivLabelFrame = new QFrame(centralWidget);
        emotivLabelFrame->setObjectName(QString::fromUtf8("emotivLabelFrame"));
        emotivLabelFrame->setGeometry(QRect(50, 100, 62, 27));
        emotivLabelFrame->setFrameShape(QFrame::StyledPanel);
        emotivLabelFrame->setFrameShadow(QFrame::Raised);
        oscLabelFrame = new QFrame(centralWidget);
        oscLabelFrame->setObjectName(QString::fromUtf8("oscLabelFrame"));
        oscLabelFrame->setGeometry(QRect(610, 99, 55, 28));
        oscLabelFrame->setFrameShape(QFrame::StyledPanel);
        oscLabelFrame->setFrameShadow(QFrame::Raised);
        oscLabel = new QLabel(oscLabelFrame);
        oscLabel->setObjectName(QString::fromUtf8("oscLabel"));
        oscLabel->setGeometry(QRect(17, 6, 21, 16));
        oscLabel->setMouseTracking(true);
        oscLabel->setTextFormat(Qt::AutoText);
        oscLabel->setOpenExternalLinks(true);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(174, 424, 361, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        expSmileLabel = new QLabel(gridLayoutWidget);
        expSmileLabel->setObjectName(QString::fromUtf8("expSmileLabel"));
        expSmileLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(expSmileLabel, 0, 0, 1, 1);

        expClenchLabel = new QLabel(gridLayoutWidget);
        expClenchLabel->setObjectName(QString::fromUtf8("expClenchLabel"));
        expClenchLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(expClenchLabel, 0, 1, 1, 1);

        expSmirkRightLabel = new QLabel(gridLayoutWidget);
        expSmirkRightLabel->setObjectName(QString::fromUtf8("expSmirkRightLabel"));
        expSmirkRightLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(expSmirkRightLabel, 0, 4, 1, 1);

        expLaughLabel = new QLabel(gridLayoutWidget);
        expLaughLabel->setObjectName(QString::fromUtf8("expLaughLabel"));
        expLaughLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(expLaughLabel, 0, 5, 1, 1);

        expSmirkLeftLabel = new QLabel(gridLayoutWidget);
        expSmirkLeftLabel->setObjectName(QString::fromUtf8("expSmirkLeftLabel"));
        expSmirkLeftLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(expSmirkLeftLabel, 0, 3, 1, 1);

        expSmileLCD = new QLCDNumber(gridLayoutWidget);
        expSmileLCD->setObjectName(QString::fromUtf8("expSmileLCD"));

        gridLayout->addWidget(expSmileLCD, 1, 0, 1, 1);

        expClenchLCD = new QLCDNumber(gridLayoutWidget);
        expClenchLCD->setObjectName(QString::fromUtf8("expClenchLCD"));

        gridLayout->addWidget(expClenchLCD, 1, 1, 1, 1);

        expSmirkLeftLCD = new QLCDNumber(gridLayoutWidget);
        expSmirkLeftLCD->setObjectName(QString::fromUtf8("expSmirkLeftLCD"));

        gridLayout->addWidget(expSmirkLeftLCD, 1, 3, 1, 1);

        expSmirkRightLCD = new QLCDNumber(gridLayoutWidget);
        expSmirkRightLCD->setObjectName(QString::fromUtf8("expSmirkRightLCD"));

        gridLayout->addWidget(expSmirkRightLCD, 1, 4, 1, 1);

        expLaughLCD = new QLCDNumber(gridLayoutWidget);
        expLaughLCD->setObjectName(QString::fromUtf8("expLaughLCD"));

        gridLayout->addWidget(expLaughLCD, 1, 5, 1, 1);

        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(177, 350, 161, 54));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        expRaiseBrowLabel = new QLabel(formLayoutWidget_2);
        expRaiseBrowLabel->setObjectName(QString::fromUtf8("expRaiseBrowLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, expRaiseBrowLabel);

        expRaiseBrowLCD = new QLCDNumber(formLayoutWidget_2);
        expRaiseBrowLCD->setObjectName(QString::fromUtf8("expRaiseBrowLCD"));
        expRaiseBrowLCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, expRaiseBrowLCD);

        expFurrowBrowLabel = new QLabel(formLayoutWidget_2);
        expFurrowBrowLabel->setObjectName(QString::fromUtf8("expFurrowBrowLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, expFurrowBrowLabel);

        expFurrowBrowLCD = new QLCDNumber(formLayoutWidget_2);
        expFurrowBrowLCD->setObjectName(QString::fromUtf8("expFurrowBrowLCD"));
        expFurrowBrowLCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, expFurrowBrowLCD);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(170, 418, 371, 92));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(15, 14, 46, 26));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(85, 16, 51, 23));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(157, 12, 54, 27));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_7 = new QFrame(frame_2);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(228, 15, 58, 23));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_8 = new QFrame(frame_2);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(308, 18, 47, 17));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(170, 209, 176, 112));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        expWinkLeftCheck = new QCheckBox(frame_3);
        expWinkLeftCheck->setObjectName(QString::fromUtf8("expWinkLeftCheck"));
        expWinkLeftCheck->setGeometry(QRect(60, 60, 16, 18));
        expWinkLeftCheck->setCheckable(false);
        expLookLeftCheck = new QCheckBox(frame_3);
        expLookLeftCheck->setObjectName(QString::fromUtf8("expLookLeftCheck"));
        expLookLeftCheck->setGeometry(QRect(60, 90, 16, 18));
        expLookLeftCheck->setCheckable(false);
        expWinkRightCheck = new QCheckBox(frame_3);
        expWinkRightCheck->setObjectName(QString::fromUtf8("expWinkRightCheck"));
        expWinkRightCheck->setGeometry(QRect(150, 60, 16, 18));
        expWinkRightCheck->setCheckable(false);
        expLookRightCheck = new QCheckBox(frame_3);
        expLookRightCheck->setObjectName(QString::fromUtf8("expLookRightCheck"));
        expLookRightCheck->setGeometry(QRect(150, 90, 16, 18));
        expLookRightCheck->setCheckable(false);
        expWinkRightLabel = new QLabel(frame_3);
        expWinkRightLabel->setObjectName(QString::fromUtf8("expWinkRightLabel"));
        expWinkRightLabel->setGeometry(QRect(90, 60, 58, 16));
        expLookRightLabel = new QLabel(frame_3);
        expLookRightLabel->setObjectName(QString::fromUtf8("expLookRightLabel"));
        expLookRightLabel->setGeometry(QRect(90, 90, 51, 16));
        expLookLeftLabel = new QLabel(frame_3);
        expLookLeftLabel->setObjectName(QString::fromUtf8("expLookLeftLabel"));
        expLookLeftLabel->setGeometry(QRect(10, 90, 46, 13));
        expWinkLeftLabel = new QLabel(frame_3);
        expWinkLeftLabel->setObjectName(QString::fromUtf8("expWinkLeftLabel"));
        expWinkLeftLabel->setGeometry(QRect(10, 60, 46, 13));
        expBlinkLabel = new QLabel(frame_3);
        expBlinkLabel->setObjectName(QString::fromUtf8("expBlinkLabel"));
        expBlinkLabel->setGeometry(QRect(61, 35, 21, 16));
        expBlinkCheck = new QCheckBox(frame_3);
        expBlinkCheck->setObjectName(QString::fromUtf8("expBlinkCheck"));
        expBlinkCheck->setGeometry(QRect(90, 36, 16, 18));
        expBlinkCheck->setCheckable(false);
        expLabelFrame = new QFrame(frame_3);
        expLabelFrame->setObjectName(QString::fromUtf8("expLabelFrame"));
        expLabelFrame->setGeometry(QRect(0, 10, 61, 23));
        expLabelFrame->setFrameShape(QFrame::StyledPanel);
        expLabelFrame->setFrameShadow(QFrame::Raised);
        expLabel = new QLabel(expLabelFrame);
        expLabel->setObjectName(QString::fromUtf8("expLabel"));
        expLabel->setGeometry(QRect(8, 5, 46, 13));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(170, 344, 176, 65));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        OSCConnectedLabel = new QLabel(centralWidget);
        OSCConnectedLabel->setObjectName(QString::fromUtf8("OSCConnectedLabel"));
        OSCConnectedLabel->setGeometry(QRect(599, 144, 76, 16));
        cmdBtn = new QPushButton(centralWidget);
        cmdBtn->setObjectName(QString::fromUtf8("cmdBtn"));
        cmdBtn->setGeometry(QRect(0, 490, 161, 16));
        cmdLnEdit = new QPlainTextEdit(centralWidget);
        cmdLnEdit->setObjectName(QString::fromUtf8("cmdLnEdit"));
        cmdLnEdit->setEnabled(false);
        cmdLnEdit->setGeometry(QRect(0, 470, 161, 21));
        cmdLnEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        cmdLnEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        cmdLnEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mind Your OSCs", 0, QApplication::UnicodeUTF8));
        oscIPedit->setText(QApplication::translate("MainWindow", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        oscPortEdit->setText(QApplication::translate("MainWindow", "7400", 0, QApplication::UnicodeUTF8));
        emotivCombo->clear();
        emotivCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Control Panel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "EmoComposer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Emotiv Engine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Custom", 0, QApplication::UnicodeUTF8)
        );
        emotivLabel->setText(QApplication::translate("MainWindow", "Emotiv", 0, QApplication::UnicodeUTF8));
        emotivConnectButton->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        emotivDisconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        oscConnectButton->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        oscDisconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        emotivConnectionStatusLabel->setText(QString());
        cogLabel->setText(QApplication::translate("MainWindow", "Cognitiv", 0, QApplication::UnicodeUTF8));
        cogPowerLabel->setText(QApplication::translate("MainWindow", "Power:", 0, QApplication::UnicodeUTF8));
        affLabel->setText(QApplication::translate("MainWindow", "Affectiv", 0, QApplication::UnicodeUTF8));
        affEngageBoredLabel->setText(QApplication::translate("MainWindow", "Engagement/Boredom", 0, QApplication::UnicodeUTF8));
        affFrustrationLabel->setText(QApplication::translate("MainWindow", "Frustration", 0, QApplication::UnicodeUTF8));
        affMeditationLabel->setText(QApplication::translate("MainWindow", "Meditation", 0, QApplication::UnicodeUTF8));
        affExciteLabel->setText(QApplication::translate("MainWindow", "Excitement", 0, QApplication::UnicodeUTF8));
        affExcitementLTLabel->setText(QApplication::translate("MainWindow", "Excitement Long Term", 0, QApplication::UnicodeUTF8));
        oscLabel->setText(QApplication::translate("MainWindow", "OSC", 0, QApplication::UnicodeUTF8));
        expSmileLabel->setText(QApplication::translate("MainWindow", "Smile", 0, QApplication::UnicodeUTF8));
        expClenchLabel->setText(QApplication::translate("MainWindow", "Clench", 0, QApplication::UnicodeUTF8));
        expSmirkRightLabel->setText(QApplication::translate("MainWindow", "Smirk Right", 0, QApplication::UnicodeUTF8));
        expLaughLabel->setText(QApplication::translate("MainWindow", "Laugh", 0, QApplication::UnicodeUTF8));
        expSmirkLeftLabel->setText(QApplication::translate("MainWindow", "Smirk Left", 0, QApplication::UnicodeUTF8));
        expRaiseBrowLabel->setText(QApplication::translate("MainWindow", "Raise Brow", 0, QApplication::UnicodeUTF8));
        expFurrowBrowLabel->setText(QApplication::translate("MainWindow", "Furrow Brow", 0, QApplication::UnicodeUTF8));
        expWinkLeftCheck->setText(QString());
        expLookLeftCheck->setText(QString());
        expWinkRightCheck->setText(QString());
        expLookRightCheck->setText(QString());
        expWinkRightLabel->setText(QApplication::translate("MainWindow", "Wink Right", 0, QApplication::UnicodeUTF8));
        expLookRightLabel->setText(QApplication::translate("MainWindow", "Look Right", 0, QApplication::UnicodeUTF8));
        expLookLeftLabel->setText(QApplication::translate("MainWindow", "Look Left", 0, QApplication::UnicodeUTF8));
        expWinkLeftLabel->setText(QApplication::translate("MainWindow", "Wink Left", 0, QApplication::UnicodeUTF8));
        expBlinkLabel->setText(QApplication::translate("MainWindow", "Blink", 0, QApplication::UnicodeUTF8));
        expBlinkCheck->setText(QString());
        expLabel->setText(QApplication::translate("MainWindow", "Expressiv", 0, QApplication::UnicodeUTF8));
        OSCConnectedLabel->setText(QString());
        cmdBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
