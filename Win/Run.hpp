#ifndef PRECONFQT_HPP
#include "../PreconfQT.hpp"
#endif

#define Run_HPP
#define DLexe ".\\youtube-dl.exe"
#define FFMpegExe ".\\ffmpeg.exe"
#define Wget ".\\wget.exe"

const QString z7 = "\"%ProgramFiles%\\7-Zip\\7z.exe\" ";	// -aoa e ffmpeg-*.7z ffmpeg.exe -r
const QString WR = "\"%ProgramFiles%\\WinRAR\\WinRar.exe\" "; //e ffmpeg-4.3.1-2020-10-01-essentials_build.7z -r ffmpeg*exe

#define dl_86 ".\\wget.exe -o \".\\youtube-dl.exe\" -q https://youtube-dl.org/downloads/latest/youtube-dl.exe"

#ifdef Q_OS_WIN64
	#define ffmpeg_url ".\\wget.exe -o \".\\ffmpeg.7z\" -q https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.7z"
	#define Wget_url ".\\wget.exe -o \".\\Wget.unk\" -q https://"
	#define Li_Lis_url ".\\wget.exe -o \".\\Core.7z\" -q https://github.com/jackestar/Dl-PJ/releases/latest/download/DL-JS.Lis.64.7z"
	#define z7_url ".\\wget.exe -o \".\\7zi.msi\" -q https://"
#elif defined Q_OS_WIN32
	#define ffmpeg_url ".\\wget.exe -o \".\\ffmpeg.unk\" -q https://"
	#define Wget_url ".\\wget.exe -o \".\\Wget.unk\" -q https://"
	#define Li_Lis_url ".\\wget.exe -o \".\\Core.7z\" -q https://github.com/jackestar/Dl-PJ/releases/latest/download/DL-JS.Lis.32.7z"
	#define z7_url ".\\wget.exe -o \".\\7zi.msi\" -q https://"
#endif

#include "Update.hpp"
