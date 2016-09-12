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

#include "OSCSender.h"

OSCSender::OSCSender(void)
{
	connected = false;
}

OSCSender::~OSCSender(void)
{
}

void OSCSender::connectToOSC(QString ip, QString port)
{

	//transmitSocket.Bind(IpEndpointName(ip.toStdString().c_str(), port.toInt()));
	connected = true;
}

void OSCSender::disconnect(){

	//delete transmitSocket;
	connected = false;
}

void OSCSender::HandleEmotivUpdate(EmotivToOSCPacket p)
{
	if(connected)
	{
		//connected = false;
		packet = p;
		start();	
		//sendOver();
	}
}

void OSCSender::run()
{
	//TODO see if wrapping BeginBundleImmediate and EndBundle is enough
	// to have one proper send statement that isn't oversized packet

	
	sendCog();

	sendAff();

	sendExp();

}

void OSCSender::sendCog(){

	osc::OutboundPacketStream out(buffer, OUTPUT_BUFFER_SIZE);
	out<<osc::BeginBundleImmediate;

	QString cogType;
	float cogPower;
	packet.getCognitiv().getCogData(cogType, cogPower);

	cogType = QString("/COG/" + cogType);
	//cogType.append(": ");
	//cogType.append(QString::number(cogPower));
	
	//out<<osc::BeginMessage("/COG")<<osc::EndMessage;
	out<<osc::BeginMessage((getStringFromQString(cogType)).c_str())
	<<(float)cogPower
	<<osc::EndMessage;
	

	out<<osc::EndBundle;
	transmitSocket.Send( out.Data(), out.Size() );
	//out.Clear();
}

void OSCSender::sendAff(){

	osc::OutboundPacketStream out(buffer, OUTPUT_BUFFER_SIZE);
	out<<osc::BeginBundleImmediate;

	QMap<int, QString> affLabels;
	QMap<int, float> affValues;

	packet.getAffectiv().getData(affLabels, affValues);

	QMap<int, QString>::iterator labelIt = affLabels.begin();
	QMap<int, float>::iterator valueIt = affValues.begin();	

	while(labelIt != affLabels.end())
	{
		QString temp = QString("/AFF/" + *labelIt);

		
		//temp.append(": ");
		//temp.append(QString::number(*valueIt));

		out<<osc::BeginMessage((getStringFromQString(temp)).c_str())
			<<(float)(*valueIt)
			<<osc::EndMessage;;

		labelIt++;
		valueIt++;
	}

	out<<osc::EndBundle;
	transmitSocket.Send( out.Data(), out.Size() );

}
void OSCSender::sendExp(){

	osc::OutboundPacketStream out(buffer, OUTPUT_BUFFER_SIZE);
	out<<osc::BeginBundleImmediate;

	QMap<int, QString> expLabels;
	QMap<int, float> expValues;

	packet.getExpressiv().getData(expLabels, expValues);

	QMap<int, QString>::iterator labelIt = expLabels.begin();
	QMap<int, float>::iterator valueIt = expValues.begin();

	while(labelIt != expLabels.end())
	{
		QString temp = ("/EXP/" + *labelIt);

		//temp.append(": ");
		//temp.append(QString::number(*valueIt));

		out<<osc::BeginMessage((getStringFromQString(temp)).c_str())
			<<(float)(expValues[labelIt.key()])
			<<osc::EndMessage;

		cout<<(getStringFromQString(temp)).c_str()<<": "<<(*valueIt)<<endl;

		labelIt++;
		valueIt++;
	}
	out<<osc::EndBundle;

	transmitSocket.Send( out.Data(), out.Size() );
}
