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

#ifndef EMOTIVCONNECTIONTHREAD_H
#define EMOTIVCONNECTIONTHREAD_H


#include "commonutils.h"
#include <QThread>

static EE_DataChannel_t targetChannelList[] = {
		ED_COUNTER,
		ED_AF3, ED_F7, ED_F3, ED_FC5, ED_T7, 
		ED_P7, ED_O1, ED_O2, ED_P8, ED_T8, 
		ED_FC6, ED_F4, ED_F8, ED_AF4, ED_GYROX, ED_GYROY, ED_TIMESTAMP, 
		ED_FUNC_ID, ED_FUNC_VALUE, ED_MARKER, ED_SYNC_SIGNAL
	};

class EmotivConnectionThread : public QThread
{

Q_OBJECT

public:
    explicit EmotivConnectionThread(QObject *parent = 0);

    void startThread(const char *, const char *, int);
    void stop();

signals:
	void EmotivStateUpdated(EmoStateHandle);

public slots:

protected:
    void run();

private:
    EmoEngineEventHandle eEvent;
    EmoStateHandle eState;
	//DataHandle hData;

    bool connectedToEngine;
	int engineStatusCode;

	int * gyroXdelta, gyroYdelta;

	void handleEEG(unsigned int userId);
};

#endif // EMOTIVCONNECTIONTHREAD_H
