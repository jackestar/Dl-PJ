#ifndef Run_HPP
#include "Run.hpp"
#endif
#ifndef PRECONFQT_HPP
#include "../PreconfQT.hpp"
#endif

// #include <iostream>
// using namespace std;


#include <QMessageBox>
MinInt Updte (MinInt Type) {

//Returns
  // 0 = wget no disponible (Actualización Manual)
//Type
// 0  = ALL
// 1  = DL
// 2  = FF
// 4  = LL
// 8  = WG
// 16 = 7Z (Local)

  // Verifica si WGet esta instalado
	MinInt Ret = 0;
  QFile file(Wget);
  if (!file.exists()) {
    file.close();
    return 0;
  }
  else {
	file.close();
    // Sistema de descompreción (Pre-Instalado)
    // None = 0
    // 7z   = 1
    // WinR = 2
    MinInt DeC = 0;
    QFile file(z7);
    if (!file.exists()) {
      file.close();

      QFile file(WR);
      if (!file.exists()) {
        file.close();
				DeC = 0;
        if (Type<=15) Type += 16;
        // Si no hay sistema de descomprecion compatible se descarga 7z
			} else DeC = 2;
    file.close();
		} else DeC = 1;
    file.close();

    // Descarga de componentes
    // 7zip Primero
		if ((Type >= 16)) {
      if (!(system(z7_url))) Ret += 16;
      if (!system("7zi.msi /quiet /passive /norestart")) {
        Ret+=16;
				DeC = 1;
      }
    }
    //DL-JS
    if (!(Type%2)) {
      if (!(system(dl_86))) {
        QFile file(DLexe);
				if (file.exists()) Ret += 1;
        file.close();
      }
    }
    //FFMpeg
    if ( !(!(Type%4) || !((Type-1)%4)) || (Type==0)) {
      if (!(system(ffmpeg_url))) {
				QFile file("ffmpeg.7z");
        if (file.exists()){
          file.close();
          switch (DeC){
            case 0:
              break;
						case 1:
							if (system(toCharString(z7+"-aoa e ffmpeg.7z ffmpeg.exe -r"))) Ret += 2;
              break;
            case 2:
              if (system(toCharString(WR+"e ffmpeg.7z -r ffmpeg.exe"))) Ret += 2;
              break;
            default:
              break;
          }
        }
      }
    }
    //Lis-Core
    if ((Type==0) || ((Type>=4)&&(Type<=7)) || ((Type>=12)&&(Type<=15)) || ((Type>=20)&&(Type<=23)) || ((Type>=28)&&(Type<=31))) {
      if (!(system(Li_Lis_url))) {
        QFile file("Core.7z");
        if (file.exists()){
          file.close();
          switch (DeC){
            case 0:
              break;
            case 1:
              if (system(toCharString(z7+"-aoa x Core.7z"))) Ret += 2;
              break;
            case 2:
              if (system(toCharString(WR+"x +o Core.7z"))) Ret += 2;
              break;
            default:
              break;
          }
        }
      }
    }

    if (((Type >= 8) && (Type<=15)) || ((Type >= 24) && (Type<=31)) || (Type==0)) {
      if (!(system(Wget_url))) {
        QFile file("wget.unk"); //Revisar
        if (file.exists()){
          file.close();
          switch (DeC){
            case 0:
              break;
            case 1:
              if (system(toCharString(z7+"-aoa e ffmpeg.7z ffmpeg.exe -r"))) Ret += 8;
              break;
            case 2:
              if (system(toCharString(WR+"e ffmpeg.7z -r ffmpeg.exe"))) Ret += 8;
              break;
            default:
              break;
          }
        }
      }
    }
  }

  if (Type==Ret) return 0;
  else return Ret;
}
