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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "commonutils.h"
#include "emotivconnectionthread.h"
#include "OSCSender.h"

#ifdef EGG_DEF
#include "Secret.h"
#endif

namespace Ui {
    class MainWindow;
}
//Brainstorm 
//58:08
//Graph - What is it? How can I make one?

class MainWindow : public QMainWindow

#ifdef SECRET_H_
	, public Secret 
#endif

{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
	void closeEvent(QEvent *e);
	void keyPressEvent(QKeyEvent *q);
	void keyReleaseEvent(QKeyEvent *q);

private:

    Ui::MainWindow *ui;
    EmotivConnectionThread emoEngine;
	OSCSender oscSender;

	CognitivSuite cogSuite;

    void setEmotivConnectSettings(QString, int, bool = false);
    void setOSCConnectionSettings(QString, int, bool = false);

	void affectivHandler(AffectivSuite&);
	void expressivHandler(ExpressivSuite&);
	void cognitivHandler(CognitivSuite&);

private slots:
    void emotivComboActivated(QString);
    void emotivConnectButtonPressed();
    void emotivDisconnectButtonPressed();

    void oscComboActivated(QString);
    void oscConnectButtonPressed();
    void oscDisconnectButtonPressed();

	void HandleEmotivUpdate(EmoStateHandle);

#ifdef EGG_DEF
	void cmdBtnClick();
#endif

};

#endif // MAINWINDOW_H