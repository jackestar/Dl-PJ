#ifndef PRECONFQT_HPP
#include "../PreconfQT.hpp"
#endif

#define Run_HPP
#define DLexe ".\\youtube-dl.exe"
#define FFMpegExe ".\\ffmpeg.exe"
#define Wget ".\\Wget.exe"

#define Mont "%WINDIR%\\Fonts\\Montserrat-Regular.ttf"
#define Mont2 "%WINDIR%\\Fonts\\Montserrat-Regular.otf"

const QString z7 = "\"%ProgramFiles%\\7-Zip\\7z.exe\" ";	// -aoa e ffmpeg-*.7z ffmpeg.exe -r
const QString WR = "\"%ProgramFiles%\\WinRAR\\WinRar.exe\" "; //e ffmpeg-4.3.1-2020-10-01-essentials_build.7z -r ffmpeg*exe

#define dl_86 ".\\Wget.exe -o \".\\youtube-dl.exe\" -q https://youtube-dl.org/downloads/latest/youtube-dl.exe"

#ifdef Q_OS_WIN64
  #define ffmpeg_url ".\\Wget.exe -o \".\\Ffmpeg.7z\" -q https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.7z"
  #define Wget_url ".\\Wget.exe -o \".\\Wget.unk\" -q https://"
  #define Li_Lis_url ".\\Wget.exe -o \".\\Core.7z\" -q https://github.com/jackestar/Dl-PJ/releases/latest/download/DL-JS.Lis.64.7z"
  #define z7_url ".\\Wget.exe -o \".\\7zi.msi\" -q https://"
#elif defined Q_OS_WIN32
  #define ffmpeg_url ".\\Wget.exe -o \".\\Ffmpeg.unk\" -q https://"
  #define Wget_url ".\\Wget.exe -o \".\\Wget.unk\" -q https://"
  #define Li_Lis_url ".\\Wget.exe -o \".\\Core.7z\" -q https://github.com/jackestar/Dl-PJ/releases/latest/download/DL-JS.Lis.32.7z"
  #define z7_url ".\\Wget.exe -o \".\\7zi.msi\" -q https://"
#endif

bool Inicio(void) {
  QFile file(z7);
  QFile file2(z7);
  if (!file.exists() || !file2.exists()) {
    return 1;
  } else {
     //Instalar fuentes de Montserrant Principales (7)
  return !system("copy \"Fonts\\Montserrat-Black.ttf\" \"%WINDIR%\\Fonts\" && reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"Montserrat Black (TrueType)\" /t REG_SZ /d Fonts\\Montserrat-Black.ttf /f && copy \"Fonts\\Montserrat-Bold.ttf\" \"%WINDIR%\\Fonts\" && reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"Montserrat Bold (TrueType)\" /t REG_SZ /d Fonts\\Montserrat-Bold.ttf /f && copy \"Fonts\\Montserrat-Italic.ttf\" \"%WINDIR%\\Fonts\" && reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"Montserrat Italic (TrueType)\" /t REG_SZ /d Fonts\\Montserrat-Italic.ttf /f && copy \"Fonts\\Montserrat-Light.ttf\" \"%WINDIR%\\Fonts\" && reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"Montserrat Light (TrueType)\" /t REG_SZ /d Fonts\\Montserrat-Light.ttf /f && copy \"Fonts\\Montserrat-Medium.ttf\" \"%WINDIR%\\Fonts\" && reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"Montserrat Medium (TrueType)\" /t REG_SZ /d Fonts\\Montserrat-Medium.ttf /f && copy \"Fonts\\Montserrat-Regular.ttf\" \"%WINDIR%\\Fonts\" && reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"Montserrat Regular (TrueType)\" /t REG_SZ /d Fonts\\Montserrat-Regular.ttf /f && copy \"Fonts\\Montserrat-Thin.ttf\" \"%WINDIR%\\Fonts\" && reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts\" /v \"Montserrat Thin (TrueType)\" /t REG_SZ /d Fonts\\Montserrat-Thin.ttf /f");

  }
}

#include "Update.hpp"
