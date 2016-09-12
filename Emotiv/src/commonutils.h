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

#ifndef COMMONUTILS_H
#define COMMONUTILS_H

#include <QString>
#include <QMap>
#include <QMetaType>

#include "IEmoStateDLL.h"
#include "Iedk.h"
#include "IedkErrorCode.h"

#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"

#include <iostream>
using std::cout;
using std::endl;

Q_DECLARE_METATYPE(EmoStateHandle);

static UdpTransmitSocket transmitSocket(IpEndpointName("127.0.0.1", 7400));

static std::string getStringFromQString(QString string){

	QByteArray asc = string.toAscii();
	std::string str(asc.constData(), asc.length());
	return str;
}

enum IndexNames
{
    CONTROL,
    COMPOSER,
    ENGINE,
    CUSTOM
};

static QString ConnectionTypes[] =
{
    "Control Panel",
    "EmoComposer",
    "Emotiv Engine",
    "Custom"

};

enum
{
    MAX
};

static QString OSCConnectionTypes[] =
{
    "Max/MSP"
};

class AffectivSuite
{
	
public:

	typedef enum AffectivTypes
	{
		ENGAGED_BORED, 
		EXCITEMENT,
		EXCITEMENTLT, 
		MEDITATION, 
		FRUSTRATION
	} AffectivTypes_t;

	
	AffectivSuite()
	{
		AffectivLabels[ENGAGED_BORED] = "Engaged/Bored";
		AffectivLabels[EXCITEMENT] = "Excitement";
		AffectivLabels[EXCITEMENTLT] = "Excitement Long Term";
		AffectivLabels[MEDITATION] = "Meditation";
		AffectivLabels[FRUSTRATION] = "Frustration";
	}

	void stateHandle(EmoStateHandle eState)
	{
		AffectivValues[ENGAGED_BORED] = ES_AffectivGetEngagementBoredomScore(eState);
		AffectivValues[EXCITEMENT]    = ES_AffectivGetExcitementShortTermScore(eState);
		AffectivValues[EXCITEMENTLT]  = ES_AffectivGetExcitementLongTermScore(eState);
		AffectivValues[MEDITATION]    = ES_AffectivGetMeditationScore(eState);
		AffectivValues[FRUSTRATION]   = ES_AffectivGetFrustrationScore(eState);

		//return AffectivValues;
	}

	QMap<int, QString> getLabels()
		{ return AffectivLabels; }

	QMap<int, float> getValues()
		{ return AffectivValues; }

	void getData(QMap<int, QString>& labels, QMap<int, float>& values)
	{
		labels = AffectivLabels;
		values = AffectivValues;
	}


private:
	QMap<int, float> AffectivValues;
	QMap<int, QString> AffectivLabels;
};

class ExpressivSuite
{

public:

	enum ExpressivTypes_Eyes
	{
		WINK_LEFT,
		WINK_RIGHT,
		BLINK,
		LEFT_LID,
		RIGHT_LID,
		HORIEYE,
		LOOK_LEFT,
		LOOK_RIGHT,
		VERTEYE,
		LOOK_UP,
		LOOK_DOWN
	};

	enum ExpressivTypes_LowerFace
	{
		SMILE = LOOK_DOWN + 1, 
		CLENCH,
		LAUGH,
		SMIRK_LEFT,
		SMIRK_RIGHT
	};

	enum ExpressivTypes_UpperFace
	{
		FURROW = SMIRK_RIGHT + 1,
		EYEBROW
	};

	ExpressivSuite()
	{
		for(int i=0; i<EYEBROW; i++)
			values[i] = 0;

		labels[WINK_LEFT] = "WINK_LEFT";
		labels[WINK_RIGHT] = "WINK_RIGHT";
		labels[BLINK] = "BLINK";
		labels[LEFT_LID] = "LEFT_LID";
		labels[RIGHT_LID] = "RIGHT_LID";
		labels[HORIEYE] = "HORIEYE";

		labels[VERTEYE] = "VERTEYE";

		labels[SMILE] = "SMILE";
		labels[CLENCH] = "CLENCH";
		labels[LAUGH] = "LAUGH";
		labels[SMIRK_LEFT] = "SMIRK_LEFT";
		labels[SMIRK_RIGHT] = "SMIRK_RIGHT";
		labels[FURROW] = "FURROW";
		labels[EYEBROW] = "EYEBROW";
	}

	/*
	typedef enum EE_ExpressivAlgo_enum {

		EXP_NEUTRAL			= 0x0001,
		EXP_BLINK			= 0x0002,
		EXP_WINK_LEFT		= 0x0004,
		EXP_WINK_RIGHT		= 0x0008,
        EXP_HORIEYE			= 0x0010,
		EXP_EYEBROW			= 0x0020,
		EXP_FURROW			= 0x0040,
        EXP_SMILE			= 0x0080,
		EXP_CLENCH			= 0x0100,
		EXP_LAUGH			= 0x0200,
		EXP_SMIRK_LEFT		= 0x0400,
		EXP_SMIRK_RIGHT		= 0x0800

	} EE_ExpressivAlgo_t;
	*/

	void stateHandle(EmoStateHandle eState)
	{
		ES_ExpressivGetEyelidState(eState, &values[LEFT_LID], &values[RIGHT_LID]);
		ES_ExpressivGetEyeLocation (eState, &values[HORIEYE], &values[VERTEYE]);

		actionLow = ES_ExpressivGetLowerFaceAction      ( eState );
		powerLow  = ES_ExpressivGetLowerFaceActionPower ( eState );

		actionHigh = ES_ExpressivGetUpperFaceAction      ( eState );		
		powerHigh  = ES_ExpressivGetUpperFaceActionPower ( eState );

		values[WINK_LEFT] = (values[LEFT_LID] == 1);
		values[WINK_RIGHT] = (values[RIGHT_LID] == 1);
		values[BLINK] = (values[LEFT_LID] == values[RIGHT_LID] && values[RIGHT_LID] == 1);
		
		if((actionLow & EXP_SMILE) == EXP_SMILE){ values[SMILE] = powerLow; }
		if((actionLow & EXP_CLENCH) == EXP_CLENCH){ values[CLENCH] = powerLow; }
		if((actionLow & EXP_LAUGH) == EXP_LAUGH){ values[LAUGH] = powerLow; }
		if((actionLow & EXP_SMIRK_LEFT) == EXP_SMIRK_LEFT){ values[SMIRK_LEFT] = powerLow; }
		if((actionLow & EXP_SMIRK_RIGHT) == EXP_SMIRK_RIGHT){ values[SMIRK_RIGHT] = powerLow; }

		if((actionHigh & EXP_EYEBROW) == EXP_EYEBROW){ values[EYEBROW] = powerHigh; }
		if((actionHigh & EXP_FURROW) == EXP_FURROW){ values[FURROW] = powerHigh; }
	}

	QMap<int, float> getValues()
	{ return values; }

	void getData(QMap<int, QString>& labels, QMap<int, float>& values)
	{
		labels = this->labels;
		values = this->values;
	}

private:


	QMap<int, QString> labels;
	QMap<int, float> values;

	float x, y, leftLid, rightLid;

	EE_ExpressivAlgo_t actionLow;
	EE_ExpressivAlgo_t actionHigh;
	float powerLow;
	float powerHigh;

};

class CognitivSuite
{
	QMap<EE_CognitivAction_t, QString> CognitivValues;
	EE_CognitivAction_t currentCogType;
	float power;

public:
	CognitivSuite()
	{
		currentCogType = COG_NEUTRAL;

		CognitivValues[COG_NEUTRAL] = "NEUTRAL";
		CognitivValues[COG_PUSH] = "PUSH";
		CognitivValues[COG_PULL] = "PULL";
		CognitivValues[COG_LIFT] = "LIFT";
		CognitivValues[COG_DROP] = "DROP";
		CognitivValues[COG_LEFT] = "LEFT";
		CognitivValues[COG_RIGHT] = "RIGHT";
		CognitivValues[COG_ROTATE_LEFT] = "ROTATE_LEFT";
		CognitivValues[COG_ROTATE_RIGHT] = "ROTATE_RIGHT";
		CognitivValues[COG_ROTATE_CLOCKWISE] = "ROTATE_CLOCKWISE";
		CognitivValues[COG_ROTATE_COUNTER_CLOCKWISE] = "ROTATE_COUNTER_CLOCKWISE";
		CognitivValues[COG_ROTATE_FORWARDS] = "ROTATE_FORWARDS";
		CognitivValues[COG_ROTATE_REVERSE] = "ROTATE_REVERSE";
		CognitivValues[COG_DISAPPEAR] = "DISAPPEAR";		
	}

	void stateHandle(EmoStateHandle eState)
	{
		currentCogType = ES_CognitivGetCurrentAction(eState);
		power = ES_CognitivGetCurrentActionPower(eState);			
	}

	void getCogData(QString &cog, float &pow)
	{
		cog = CognitivValues[currentCogType]; 
		pow = power;
	}


};

class EmotivToOSCPacket
{
	AffectivSuite  aff;
	ExpressivSuite exp;
	CognitivSuite  cog;

public:
	
	EmotivToOSCPacket(){}

	EmotivToOSCPacket(EmoStateHandle state)
	{
		aff.stateHandle(state);
		exp.stateHandle(state);
		cog.stateHandle(state);
	}
	
	AffectivSuite  getAffectiv()  { return aff; }
	ExpressivSuite getExpressiv() { return exp; }
	CognitivSuite  getCognitiv()  { return cog; }

};

#endif // COMMONUTILS_H
