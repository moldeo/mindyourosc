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

#include "commonutils.h"
#include "emotivconnectionthread.h"

#include <QMessageBox>
#include <string>
using std::string;


EmotivConnectionThread::EmotivConnectionThread(QObject *parent) :
QThread(parent)
{
	connectedToEngine = false;
}

void EmotivConnectionThread::startThread(const char * connectType,
										 const char * ipText,
										 int portNum)
{    
	eEvent = EE_EmoEngineEventCreate();
	eState = EE_EmoStateCreate();

	QMessageBox::StandardButton selectedButtonFromError;

	EE_EngineDisconnect();
	do
	{
		//string st = ipText.toStdString();
		//char* ip;
		//ip = new char[st.size() + 1];
		//strcpy(ip, st.c_str());
		//int port = (unsigned int)portText.toInt();


		if(connectType == ConnectionTypes[ENGINE])
			engineStatusCode = EE_EngineConnect();
		else
			engineStatusCode = EE_EngineRemoteConnect(ipText, portNum);

		if(engineStatusCode != EDK_OK)
		{
			selectedButtonFromError = QMessageBox::warning(0,
				"",
				"Can not connect to " + QString(connectType),
				QMessageBox::Retry | QMessageBox::Abort,
				QMessageBox::Retry);
		}
		else
			connectedToEngine = true;

	}while(engineStatusCode != EDK_OK && selectedButtonFromError == QMessageBox::Retry);



	if(connectedToEngine){}
	start();


	//this->start();


}

void EmotivConnectionThread::stop()
{
	connectedToEngine = false;

}

void EmotivConnectionThread::run()
{
	int secs = 1;
	unsigned int userId;

	DataHandle hData = EE_DataCreate();
	//EE_DataSetBufferSizeInSec(secs);

	while(connectedToEngine)
	{
		engineStatusCode = EE_EngineGetNextEvent(eEvent);

		if(engineStatusCode == EDK_OK)
		{
			EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);
			EE_EmoEngineEventGetUserId(eEvent, &userId);

			if (eventType == EE_UserAdded) {
				std::cout << "User added";
				EE_DataAcquisitionEnable(userId,true);
				//readytocollect = true;
			}

			if(eventType == EE_EmoStateUpdated)
			{
				EE_EmoEngineEventGetEmoState(eEvent, eState);

				emit EmotivStateUpdated(eState);


				//handleEEG(userId);
				EE_DataUpdateHandle(userId, hData);

				unsigned int nSamplesTaken=0;
				EE_DataGetNumberOfSample(hData,&nSamplesTaken);

				std::cout << "Updated " << nSamplesTaken << std::endl;

				if (nSamplesTaken != 0) {

					double* data = new double[nSamplesTaken];
					for (int sampleIdx=0 ; sampleIdx<(int)nSamplesTaken ; ++ sampleIdx) {
						for (int i = 0 ; i<sizeof(targetChannelList)/sizeof(EE_DataChannel_t) ; i++) {

							EE_DataGet(hData, targetChannelList[i], data, nSamplesTaken);
							std::cout << data[sampleIdx] << ",";
						}	
						std::cout << std::endl;
					}
					delete[] data;
				}
			}
		}

	}

	EE_EngineDisconnect();
}

void EmotivConnectionThread::handleEEG(unsigned int userId){

	/*EE_DataUpdateHandle(userId, hData);

	unsigned int nSamplesTaken=0;
	EE_DataGetNumberOfSample(hData,&nSamplesTaken);

	std::cout << "Updated " << nSamplesTaken << std::endl;

	if (nSamplesTaken != 0) {

		double* data = new double[nSamplesTaken];
		for (int sampleIdx=0 ; sampleIdx<(int)nSamplesTaken ; ++ sampleIdx) {
			for (int i = 0 ; i<sizeof(targetChannelList)/sizeof(EE_DataChannel_t) ; i++) {

				EE_DataGet(hData, targetChannelList[i], data, nSamplesTaken);
				std::cout << data[sampleIdx] << ",";
			}	
			std::cout << std::endl;
		}
		delete[] data;
	}*/
}
