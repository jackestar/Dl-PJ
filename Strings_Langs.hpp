#include <QLocale>
void GetIdiom();

QString LangString[10];
const QLocale Lang = QLocale::system();
void GetIdiom() {
  if (Lang == QLocale::Spanish) {
    LangString[0] ="Completo";
    LangString[1] ="Error";
    LangString[2] ="Falta Youtube-DL y FFmpeg";
    LangString[3] ="Falta Youtube-DL";
    LangString[4] ="Descarga De Youtube DL & FFMpeg";
    LangString[5] ="Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg";
    LangString[6] ="Ingrese URL";
    LangString[7] ="Ingrese todos los datos";
    LangString[8] ="Ingrese un nombre!!!";
  }
  else if (Lang == QLocale::English) {
    LangString[0] = "Complete";
    LangString[1] = "Error";
    LangString[2] = "Falta Youtube-DL y FFmpeg";
    LangString[3] = "Falta Youtube-DL";
    LangString[4] = "Descarga De Youtube DL & FFMpeg";
    LangString[5] = "Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg";
    LangString[6] = "Enter URL";
    LangString[7] = "Ingrese todos los datos";
    LangString[8] = "Ingrese un nombre!!!";
  }
  else {
    LangString[0] ="Completo";
    LangString[1] ="Error";
    LangString[2] ="Falta Youtube-DL y FFmpeg";
    LangString[3] ="Falta Youtube-DL";
    LangString[4] ="Descarga De Youtube DL & FFMpeg";
    LangString[5] ="Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg";
    LangString[6] ="Ingrese URL";
    LangString[7] ="Ingrese todos los datos";
    LangString[8] ="Ingrese un nombre!!!";
  }


}
