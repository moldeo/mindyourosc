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
#include <QtGui/QApplication>


#define OUTPUT_BUFFER_SIZE 1024	

int main(int argc, char *argv[])
{
	char buffer[OUTPUT_BUFFER_SIZE];

    QApplication a(argc, argv);
	UdpTransmitSocket socket(IpEndpointName("127.0.0.1", 7400));
    MainWindow w;
    w.show();
    return a.exec();
    //return 0;
}
