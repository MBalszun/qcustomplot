
#include <qcustomplot/utils/supress_common_qt_warnings_start.h>

#include <QApplication>
#include "mainwindow.h"

#include <qcustomplot/utils/supress_common_qt_warnings_stop.h>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
