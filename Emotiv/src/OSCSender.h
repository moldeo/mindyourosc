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

#ifndef OSCSENDER_H_
#define OSCSENDER_H_


#include "commonutils.h"
#include <QThread>
#include <QMutex>

#define OUTPUT_BUFFER_SIZE 1024	
	
class OSCSender : public QThread
{
public:
	OSCSender(void);
	~OSCSender(void);

	void disconnect();
	void connectToOSC(QString ip, QString port);
	void HandleEmotivUpdate(EmotivToOSCPacket);
private:	
	char buffer[OUTPUT_BUFFER_SIZE];
	bool connected;
	void run();
	// void sendOver();

	 void sendCog();
	 void sendAff();
	 void sendExp();

	//UdpTransmitSocket *transmitSocket;
	EmotivToOSCPacket packet;

	QMutex mutex;


};

#endif //OSCSENDER_H_

