#ifndef PRECONFQT_HPP
  #define PRECONFQT_HPP

#endif // PRECONFQT_HPP

// Define dependencia absoluta de FFmpeg
#ifdef MMPEG_NEED
# define MMPEG_N true
#else
# define MMPEG_N false
#endif

// Habilita compatibilidad con FFmpeg
#ifdef MMPEG
# define MMPEG_A true
#else
# define MMPEG_A false
#endif

//using namespace std;

#ifndef LangStrings_HPP
#include "LangStrings.hpp"
#endif

typedef unsigned short int MinInt;

inline const char* toCharString(QString String);

MinInt Start(void);                             // Deteccion de componentes
QString URLanlz (QString URL, bool config[]);   // Limpeza de URL
QString URLanlz (QString URL);                  // WebSite Name
QString Config (char config[]);                 // Argumentos para DL
bool Execut (QString URLanlz, QString &Config); // Ejecucion de DL

//SO Variants
MinInt Updte (MinInt Type = 0);

inline const char* toCharString(QString String) { // inline para trasformar de QString
    QByteArray tst = String.toLocal8Bit();
  return (const char *) tst;
}

QString URLanlz (QString URL, bool config[]) {
/*  Bool Config Array

    1 Auto music.youtube.com
    2 clean "&"
*/
  const QString Uyout = "www.youtube.com";
  const QString Umyot = "music.youtube.com";
  if (config[0] && URL.contains(Uyout)) URL.replace(URL.indexOf(Uyout),Uyout.length(),Umyot);
  if (config[1] && URL.contains("&")) URL.remove(URL.indexOf("&"),(URL.length()) - URL.indexOf("&"));
  return URL;
}

QString URLanlz (QString URL) {

URL = URL.toLower();
// Salida de nombres complejos
if (URL.contains("music.youtube.com/")) return  "Youtube Music";
else if (URL.contains("drive.google.com/")) return  "Google Drive";
else if (URL.contains("www.hbo.com/")) return  "HBO";
else if (URL.contains("abc.net.au/")) return  "ABC";
else if (URL.contains("abcnews.go.com/")) return  "ABC News";
else if (URL.contains("abc7news.com/") || URL.contains("clips.abcotvs.com")) return "ABC Owned Television Stations";
else if (URL.contains("anime-on-demand.de/")) return  "Anime On Demand";
else if (URL.contains("bbc.co.uk/") || URL.contains("bbc.com")) return "BBC iPlayer";
else if (URL.contains("cartoonnetwork.com/")) return  "Cartoon Network";
else if (URL.contains("comedycentral.com/") || URL.contains("cc.com")) return "Comedy Central";
else if (URL.contains("cnn.com/")) return  "CNN";
else if (URL.contains("tiktok.com/")) return "TikTok";
else if (URL.contains("adultswim.com/")) return "Adult Swim";
else if (URL.contains("plus.google.com/")) return "Google Plus";
else if (URL.contains("roosterteeth.com/")) return "Rooster Teeth";
//else if (URL.contains("")) return "";

// Salida predeterminada
else {
    QString Temp = URL;
    if (Temp.count(".html") == 1) Temp = Temp.remove(".html");
    else if (Temp.count(".php") == 1) Temp = Temp.remove(".php");
    else if (Temp.count(".xhtml") == 1) Temp = Temp.remove(".xhtml");

    if (URL.contains("://") && Temp.count(".") == 1) Temp = URL.mid((URL.indexOf("://")+3),URL.indexOf(".") - (URL.indexOf("://")+3));
    else { //Simple Between
      if (Temp.count(".") > 1) Temp = URL.mid((URL.indexOf(".")+1), (URL.indexOf(".",(URL.indexOf(".")+1)) - (URL.indexOf(".")+1) ));
      else if (Temp.count(".") == 1) Temp = Temp.left(URL.indexOf("."));
    }

    return Temp;
  }

}

QString Config (char config[]) {
  QString Ret;
  Ret = " -f \"";
  switch (config[0]) {
    case 'a':
    Ret += "(bestaudio)";
    break;
    case 'b':
    Ret += "(best)";
    break;
    case 'c':
    Ret += "(acc/bestaudio/best)";
    break;
    case 'f':
    Ret += "(flv/best)";
    break;
    case 'g':
    Ret += "(3gp/best)";
    break;
    case 'i':
    Ret += "(flac/bestaudio)";
    break;
    case 'm':
    Ret += "(bestvideo+bestaudio)";
    break;
    case 'n':
    Ret += "(mp3/bestaudio)";
    break;
    case 'o':
    Ret += "(ogg/best)";
    break;
    case 'p':
    Ret += "(m4a/bestaudio)";
    break;
    case 'q':
    Ret += "(mp4/best)";
    break;
    case 'r':
    Ret += "(mkv/best)";
    break;
    case 's':
    Ret += "(opus/best)";
    break;
    case 't':
    Ret += "(avi/best)";
    break;
    case 'v':
    Ret += "(bestvideo)";
    break;
    case 'w':
    Ret += "(wav/best)";
    break;
    case 'x':
    Ret += "(webm/best)";
    break;
    case 'z':
    Ret += "(vorbis/best)";
    break;
    case '&':
    Ret += "(bestvideo+bestaudio/best)";
    break;
    case '@':
    Ret += "(best/bestvideo+bestaudio)";
    break;
    case '#':
    Ret += "(worst)";
    break;
    case '$': // No Formato
    Ret = " ";
    break;
    case '!':
    Ret = " -F "; // Format List
    break;
    case '*':
    Ret += "";
    break;
    default:
    Ret += "(best)";
    break;
  }
  for (MinInt lis = 1; lis <= (strlen(config) + 3); ++lis) {
    switch (config[lis]) {
      case 'A':
      Ret+= "[height<?200]"; //114p
      break;
      case 'B':
      Ret+= "[height<?400]"; //360p
      break;
      case 'C':
      Ret+= "[height<?500]"; //480p
      break;
      case 'D':
      Ret+= "[height<?700]"; //640p
      break;
      case 'E':
      Ret+= "[height<?800]"; //720p
      break;
      case 'F':
      Ret+= "[height<?1100]"; //1080p
      break;
      case 'G':
      Ret+= "[height>?1000]"; //More Than
      break;
      case 'H':
      Ret+= "[asr<?45000]"; //44KHZ
      break;
      case 'I':
      Ret+= "[asr>?45000]"; //48KHZ
      break;
      case 'J':
      Ret+= "[fps>?35]"; // 60FPS
      break;
      case 'K':
      Ret+= "[fps<?35]";  // <35 FPS
      break;
      case '1':
      Ret+= " --restrict-filenames"; // Nombres para Windows filename
      break;
      case '2':
      Ret+= " --console-title --no-continue --ignore-errors"; // No continua a archivos prciales
      break;
//      case '3':
//      Ret+= " -o \"%(title)s.%(ext)s\""; // Titulo Predet
//      break;
      case '/':
      Ret+= " --embed-subs";
      break;
      case '4':
      Ret+= " --write-sub";
      break;
      case '5':
      Ret+= " --youtube-skip-dash-manifest";
      break;
      case '6':
      Ret+= " --audio-quality 0 -x --audio-format mp3";
      break;
      case '7':
      Ret+= " --embed-thumbnail";
      break;
      case '8':
      Ret+= " --add-metadata";
      break;
      case '9':
      Ret+= " --skip-download";
      break;
      case '%':
      Ret+= " --mark-watched";
      break;
      case '0':
      Ret+= " --sub-lang \"esLA/esES/esVE/es/esp/es_LA/es_419/es-419\"";
      break;
      case '-':
      Ret+= " --sub-lang \"enUS/enUK/en/eng\"";
      break;
      case '(':
      Ret+= " --yes-playlist ";
      break;
//      case '+':
//      Ret+= " -o \"%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s\" ";
      break;
      default:
      break;
    }
  }
  if (Ret.contains("]")) Ret.replace(Ret.indexOf("] -"), 3,"]\" -");
  else Ret.replace(Ret.indexOf(") -"), 3,")\" -");
  return Ret;
}

#ifndef ConDebug
# define Debug false
#else
# define Debug true
#endif

#ifdef Q_OS_WIN
  #ifdef Q_PROCESSOR_ARM
    #error "Aun No Compatible Con Procesadores ARM (Posibilidad no muy brillante)"
  #endif

  #include <QFile>
  #include "Win/Run.hpp"


#elif defined Q_OS_LINUX
  #error "Vercion en dessarrollo Aun no Terminado"
#include "Lin/Run.hpp"

#elif defined Q_OS_MACOS
  #error "Vercion en dessarrollo Aun no Terminado"
#include "Lin/Run.hpp"

#elif defined Q_OS_ANDROID
  #error "Vercion en dessarrollo Aun no Terminado"

#endif

// retorna en 0 si se ejecuto correntamente
bool Execut (QString URLanlz, QString &Config) {
      QString comandoA = DLexe + Config + " " + URLanlz;
      Config = comandoA;
      bool resul = system(toCharString(comandoA));
			if (resul) system(toCharString("color 4 && echo ///////// "+LangString[1]+" /////////"));
			else system(toCharString("color 2 && echo ///////// "+LangString[0]+" /////////"));
      return resul;
}

MinInt Start(void) {
  QFile ydl((DLexe));
  MinInt Ret = 0;
  if (ydl.exists()) {
    Ret += 1;
    ydl.close();
  }
  if (MMPEG_A || MMPEG_N) {
      QFile mpg(FFMpegExe);
      if (mpg.exists()) Ret += 2;
      else if (MMPEG_N) Ret = 0;
      mpg.close();
  }
  return Ret;
      //0 = No Se Puede ejectar la aplicacion (exit)
      //1 = Se Encontro Youtube DL
      //2 = Solo se Encontro FFMpeg (Advertencia)
      //3 = Se encontro DL y FFMpeg

  //Reforma
    //=0  Inicial 
    //+1  FFMpeg
    //+2  Wget
    //+4  youtubeDL
    //+8  Visual Studio C
      //0 = No Se Puede ejectar la aplicacion       (exit)
      //1 = Solo se encuentra FFMpeg                (In operable)
      //2 = Solo se encuentra Wget                  (in operable)
      //3 = Solo se encuentra FFMpeg y Wget         (In opereble/Actualizable)
      //4 = Se encontro YoutubeDL                   (Operable/Limitante)
      //5 = Se encontro YoutubeDL y FFmpeg          (Opereble)
      //6 = Se encontro YoutubeDL y Wget            (Operable/Limitante/Actualizable)
      //7 = Se encontro Todas las caracteristicas   (Full Operacion/Actualizable)
}
