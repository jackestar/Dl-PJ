#include <QLocale>
bool GetIdiom();

QString LangString[11];
bool GetIdiom() {
  QLocale Lang;
  Lang = Lang.language();
  LangString[10] = Lang.languageToString(Lang.language());
  if (Lang == QLocale::Spanish) {
    LangString[0] = "Completo";
    LangString[1] = "Error";
    LangString[2] = "Falta Youtube-DL y FFmpeg";
    LangString[3] = "Falta Youtube-DL";
    LangString[4] = "Descarga De Youtube DL & FFMpeg";
    LangString[5] = "Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg";
    LangString[6] = "Ingrese URL";
    LangString[7] = "Ingrese todos los datos";
    LangString[8] = "Ingrese un nombre!!!";
    LangString[9] = "Espere a la Consola";
    return 0;
  }
  else if (Lang == QLocale::English) {
    LangString[0] = "Complete";
    LangString[1] = "Error";
    LangString[2] = "Youtube-DL and FFmpeg are Miss";
    LangString[3] = "Youtube-DL are Miss";
    LangString[4] = "Download Youtube DL & FFMpeg";
    LangString[5] = "Push Ctrl + U to Download Youtube-DL & FFMpeg";
    LangString[6] = "Enter URL";
    LangString[7] = "&Ingrese todos los datos";
    LangString[8] = "Write filename!!!";
    LangString[9] = "Console Waiting";
    return 0;
  }
  else {
    LangString[0] = "Completo";
    LangString[1] = "Error";
    LangString[2] = "Falta Youtube-DL y FFmpeg";
    LangString[3] = "Falta Youtube-DL";
    LangString[4] = "Descarga De Youtube DL & FFMpeg";
    LangString[5] = "Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg";
    LangString[6] = "Ingrese URL";
    LangString[7] = "Ingrese todos los datos";
    LangString[8] = "Ingrese un nombre!!!";
    LangString[9] = "Espere a la Consola";
    return 1;
  }
  //LangString[10] = Lang.languageToString(Lang.language());
}
