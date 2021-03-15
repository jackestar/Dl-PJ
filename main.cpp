#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QTranslator translator;
  if (translator.load(QLocale(), QLatin1String("DL-JS_Lis")))
    a.installTranslator(&translator);

  MainWindow w;
  w.show();
  return a.exec();
}
