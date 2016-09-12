
/*
Copyright (c) 2010 Raye Herron <bitrayne@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program (see LICENSE).  If not, see <http://www.gnu.org/licenses/>.

This program uses:

Qt 4.6 (VS2008) (c) Nokia
http://qt.nokia.com/products

oscpack (c) Ross Bencina
<http://www.audiomulch.com/~rossb/code/oscpack/>
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
using std::cout;
using std::endl;
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	qRegisterMetaType<EmoStateHandle>("EmoStateHandle");

    ui->setupUi(this);

    connect(ui->emotivCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(emotivComboActivated(QString)));
   // connect(ui->oscCombo,  SIGNAL(currentIndexChanged(QString)), this, SLOT(oscComboActivated(QString)));
    connect(ui->emotivConnectButton, SIGNAL(clicked()), this, SLOT(emotivConnectButtonPressed()));
    connect(ui->emotivDisconnectButton, SIGNAL(clicked()), this, SLOT(emotivDisconnectButtonPressed()));
    connect(ui->oscConnectButton, SIGNAL(clicked()), this, SLOT(oscConnectButtonPressed()));
    connect(ui->oscDisconnectButton, SIGNAL(clicked()), this, SLOT(oscDisconnectButtonPressed()));

#ifdef EGG_DEF
	connect(ui->cmdBtn,SIGNAL(clicked() ), this, SLOT(cmdBtnClick()));
#endif

	connect(&emoEngine, SIGNAL(EmotivStateUpdated(EmoStateHandle)), this, SLOT(HandleEmotivUpdate(EmoStateHandle)));
    
	emotivComboActivated(ui->emotivCombo->currentText());
	//oscComboActivated(ui->oscCombo->currentText());

	this->setFixedSize(this->size());
	ui->cmdLnEdit->setVisible(false);
	ui->cmdBtn->setVisible(false);
	
}

#ifdef EGG_DEF
void MainWindow::cmdBtnClick(){
	
	std::string cmd;

	if(enableEdit){
		cmd = getStringFromQString(ui->cmdLnEdit->toPlainText());
		ui->cmdLnEdit->setPlainText("");
	}else
		cmd = "";

	handleButtonPress(-123, cmd);

	if(showLineEdit)
		ui->cmdLnEdit->setVisible(true);
}
#endif

void MainWindow::keyPressEvent(QKeyEvent *q){

#ifdef EGG_DEF
	handleButtonPress(q->key());

	if(showButton)
		ui->cmdBtn->setVisible(true);
	if(enableEdit)
		ui->cmdLnEdit->setEnabled(true);
#endif

}

void MainWindow::keyReleaseEvent(QKeyEvent *q){

}

MainWindow::~MainWindow()
{

	
emoEngine.stop();
emoEngine.wait();

oscSender.wait();

delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QEvent *e)
{

}



void MainWindow::emotivComboActivated(QString comboText)
{


    if(comboText == ConnectionTypes[CONTROL])
    {
        setEmotivConnectSettings("127.0.0.1", 3008);
    }else if(comboText == ConnectionTypes[COMPOSER])
    {
        setEmotivConnectSettings("127.0.0.1", 1726);
    }else if(comboText == ConnectionTypes[ENGINE])
    {
        setEmotivConnectSettings("127.0.0.1", 0);
    }else if(comboText == ConnectionTypes[CUSTOM])
    {
        setEmotivConnectSettings("0", 0, true);
    }

}

void MainWindow::oscComboActivated(QString comboText)
{
    if(comboText == OSCConnectionTypes[MAX])
        setOSCConnectionSettings("127.0.0.1", 7400);
}


void MainWindow::emotivConnectButtonPressed()
{

	QString temp = ui->emotivCombo->currentText();
	QByteArray asc = temp.toAscii();
	std::string str(asc.constData(), asc.length());
	//temp.toStdString();
	const char *connectToWhere = str.c_str();

	temp = ui->emotivIPedit->text();
	asc = temp.toAscii();
	std::string str2 = std::string(asc.constData(), asc.length());
	const char *ipText = str2.c_str();

	int portNum = ui->emotivPortEdit->text().toInt();

	//const char *t = temp.toStdString().c_str();

    emoEngine.startThread(connectToWhere, ipText, portNum);

	ui->emotivConnectionStatusLabel->setText("Waiting...");
    //emoEngine->startThread();

}

void MainWindow::emotivDisconnectButtonPressed()
{

    emoEngine.stop();
}

void MainWindow::oscConnectButtonPressed()
{

	ui->OSCConnectedLabel->setText("Connected");
	oscSender.connectToOSC(ui->oscIPedit->text(), ui->oscPortEdit->text());

}

void MainWindow::oscDisconnectButtonPressed()
{

	ui->OSCConnectedLabel->setText("Disconnected");
	oscSender.disconnect();

}

void MainWindow::setEmotivConnectSettings(QString ipText, int portNum, bool enableEdit)
{
    ui->emotivIPedit->setText(ipText);
    ui->emotivPortEdit->setText(QString::number(portNum));

    ui->emotivIPedit->setEnabled(enableEdit);
    ui->emotivPortEdit->setEnabled(enableEdit);
}

void MainWindow::setOSCConnectionSettings(QString ipText, int portNum, bool editEnabled)
{
    ui->oscIPedit->setText(ipText);
    ui->oscPortEdit->setText(QString::number(portNum));

    //ui->oscIPedit->setEnabled(editEnabled);
   // ui->oscPortEdit->setEnabled(editEnabled);
}

void MainWindow::HandleEmotivUpdate(EmoStateHandle eState)
{
	ui->emotivConnectionStatusLabel->setText("Connected");

	EmotivToOSCPacket packet(eState);

	affectivHandler(packet.getAffectiv());
	expressivHandler(packet.getExpressiv());
	cognitivHandler(packet.getCognitiv());

	oscSender.HandleEmotivUpdate(packet);
	oscSender.wait();
}

void MainWindow::affectivHandler(AffectivSuite &aff)
{			

	QMap<int, float> affValues = aff.getValues();

	ui->affEngageBoredLCD->display(affValues[aff.ENGAGED_BORED]);
	ui->affExcitementLCD->display(affValues[aff.EXCITEMENT]);
	ui->affExcitementLTLCD->display(affValues[aff.EXCITEMENTLT]);
	ui->affFrustrationLCD->display(affValues[aff.FRUSTRATION]);
	ui->affMeditationLCD->display(affValues[aff.MEDITATION]);	
}

void MainWindow::expressivHandler(ExpressivSuite& exp)
{

	QMap<int, float> values = exp.getValues();

	ui->expBlinkCheck->setChecked(values[ExpressivSuite::BLINK]);
	ui->expWinkLeftCheck->setChecked(values[ExpressivSuite::WINK_LEFT]);
	ui->expWinkRightCheck->setChecked(values[ExpressivSuite::WINK_RIGHT]);
	//ui-->setChecked(values[ExpressivSuite:]);
	//ui-->setChecked(values[ExpressivSuite:]);
	
	ui->expClenchLCD->display(values[ExpressivSuite::CLENCH]);
	ui->expSmileLCD->display(values[ExpressivSuite::SMILE]);
	ui->expLaughLCD->display(values[ExpressivSuite::LAUGH]);
	ui->expSmirkLeftLCD->display(values[ExpressivSuite::SMIRK_LEFT]);
	ui->expSmirkRightLCD->display(values[ExpressivSuite::SMIRK_RIGHT]);
	
	ui->expFurrowBrowLCD->display(values[ExpressivSuite::FURROW]);
	ui->expRaiseBrowLCD->display(values[ExpressivSuite::EYEBROW]);
	

}

void MainWindow::cognitivHandler(CognitivSuite& cog)
{

	QString cogType;
	float power;

	cog.getCogData(cogType, power);

	ui->cogTypeLine->setText(cogType);
	ui->cogPowerLCD->display(power);

}
