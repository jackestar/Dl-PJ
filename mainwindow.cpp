#include "mainwindow.hpp"
#include "ui_mainwindow.h"

// Predefinidos para Libreira
#define MMPEG
#define ConDebug

#ifndef PRECONFQT_HPP
#include "PreconfQT.hpp"
#endif

#ifndef LangStrings_HPP
#include "LangStrings.hpp"
#endif

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // Establecer Idioma

  if (MainWindow::GetIdiom()) {
    ui->Status->setText("Traducción no disponible");
    ui->Report->setText("La aplicación no tiene soporte para el idioma "+LangString[10]+" .La aplicación pasa al Español por defecto");
  }

  // Lang Sub Inde
  if (LangString[10] == "Spanish") ui->SLang->setCurrentIndex(0);
  else if (LangString[10] == "English") ui->SLang->setCurrentIndex(1);

  // Establecer Estilos
  QFile f(":style/style.qss");
  if (!f.exists()) ui->Status->setText(LangString[1]);
  else {
      f.open(QFile::ReadOnly | QFile::Text);
      QTextStream ts(&f);
      qApp->setStyleSheet(ts.readAll());
  }

  IStart();
  ui->ConfigW->move(400,300);
  ui->Fabot->move(400,300);
  ui->Prox_Updt->move(400,300);
  system(toCharString("title DL-JS "+tr("Consola")+" && color 3 && cls"));
}

MainWindow::~MainWindow() {
  delete ui;
}

//Audio Video Sub
void MainWindow::Iniz2 (const bool FileNameBool,const MinInt& Mode,QString FileName) {

  MinInt Estate = Start();
  char PrConfg[16] = "...............";

    //Modo
  if (Mode == 1) PrConfg[0] = 'a';               // Best A
  else if (Mode == 2) {
      if (Estate == 1) PrConfg[0] = 'b';       // Best
      else if (Estate == 3) PrConfg[0] = '&';  // Best A+V
  } else if (Mode == 3) PrConfg[0] = '#';        // Worst por descarte

  if (Mode!=3) {
    switch (ui->AAdR->currentIndex()) { // Audio rate
      case 1:
        PrConfg[3] = 'H';
        break;
      case 2:
        PrConfg[3] = 'I';
        break;
      default:
        PrConfg[3] = ' ';
        break;
    }

  if (Mode!=1) {
    switch (ui->VRes->currentIndex()) { //Resolucion
      case 1:
        PrConfg[1] = 'A';
        break;
      case 2:
        PrConfg[1] = 'B';
        break;
      case 3:
        PrConfg[1] = 'C';
        break;
      case 4:
        PrConfg[1] = 'D';
        break;
      case 5:
        PrConfg[1] = 'E';
        break;
      case 6:
        PrConfg[1] = 'F';
        break;
      case 7:
        PrConfg[1] = 'G';
        break;
      default:
        PrConfg[1] = ' ';
        break;
    }

    switch (ui->VFPS->currentIndex()) { //FPS
      case 1:
        PrConfg[2] = 'J';
        break;
      case 2:
        PrConfg[2] = 'K';
        break;
      default:
        PrConfg[2] = ' ';
        break;
     }
   }
 }

  QString WebName = URLanlz(ui->URL->text()).toLower();

  if (ui->Oname->isChecked()) PrConfg[4] = '1';   // ASSic Name
  PrConfg[5] = '2';                               // COntinue & Console title

  if ( (WebName == "crunchyroll") || ( Mode == 3 ) || (Estate == 3 && Mode == 2 && ui->Ofzsb->isChecked()) ) {
    PrConfg[9] = '4';                             // Write Sub
      switch (ui->SLang->currentIndex()) {
        case 0:
          PrConfg[13] = '0';                       //Esp
          break;
        case 1:
          PrConfg[13] = '-';                       //Eng
          break;
        default:
          PrConfg[13] = ' ';
          break;
    }
    if (Mode == 2) PrConfg[8] = '/'; //Embed Sub
  }

  bool URLc[3] = {false,false};
  if (WebName.contains("youtube")) {
    if (ui->Osydt->isChecked()) PrConfg[7] = '5';   // Youtube Manifest
    if (ui->Ovsto->isChecked()) PrConfg[14] = '%';  // Marcar Visto
  }
  bool MetaAsing = ((Mode == 1 && Estate == 3) || (ui->Ofzmt->isChecked() && Mode != 3));
  if (Mode == 1 && Estate == 3 && FileNameBool == false ) PrConfg[9] = '6'; // Audio Mp3 Best
  if (ui->Otumb->isChecked() && MetaAsing) PrConfg[10] = '7'; //Tumbl
  if (ui->Ometa->isChecked() && MetaAsing) PrConfg[11] = '8'; //Meta
  if (Mode == 3) PrConfg[15] = '9';               //Skip dowload 4 sub
  if (ui->Oelst->isChecked()) PrConfg[12] = '(';  //Playlist
  else if (ui->Ourla->isChecked()) URLc[1] = true;     //Analizar URL

  ui->Progress->setValue(25);

  QString Conf = Config(PrConfg);

  //Configuración de Usuario
  if (!(ui->Lpass->text().isEmpty())) { // Descartada doble verificación
    Conf += " -u \"" + ui->Luser->text() +"\" -p \"";
    Conf += ui->Lpass->text()+"\"";
  }

  if (FileNameBool) { // Establecer Formato de salida
    if (Estate == 3) {
      if (FileName.contains(".unk")) Conf += " -o \"" + FileName + "\""; // Salida sin etención

    // Nombre en caso de playlist
      if (ui->Oelst->isChecked()) FileName = FileName.insert(FileName.lastIndexOf('.'),"-%(playlist_index)s");
    // Salida de video segun la etencion
      else if (FileName.contains(".mp4") && Mode == 2) Conf += " -o \"" + FileName + "\" --recode-video \"mp4\"";
      else if (FileName.contains(".flv") && Mode == 2) Conf += " -o \"" + FileName + "\" --recode-video \"flv\"";
      else if (FileName.contains(".ogg") && Mode == 2) Conf += " -o \"" + FileName + "\" --recode-video \"ogg\"";
      else if (FileName.contains(".mkv") && Mode == 2) Conf += " -o \"" + FileName + "\" --recode-video \"mkv\"";
      else if (FileName.contains(".avi") && Mode == 2) Conf += " -o \"" + FileName + "\" --recode-video \"avi\"";
    // Salida de Audio según la etencion
      else if (FileName.contains(".mp3") && Mode == 1) Conf += " -o \"" + FileName + "\"  --audio-quality 0 -x --audio-format \"mp3\"";
      else if (FileName.contains(".aac") && Mode == 1) Conf += " -o \"" + FileName + "\"  --audio-quality 0 -x --audio-format \"aac\"";
      else if (FileName.contains(".flac") && Mode == 1) Conf += " -o \"" + FileName + "\"  --audio-quality 0 -x --audio-format \"flac\"";
      else if (FileName.contains(".m4a") && Mode == 1) Conf += " -o \"" + FileName + "\"  --audio-quality 0 -x --audio-format \"m4a\"";
      else if (FileName.contains(".opus") && Mode == 1) Conf += " -o \"" + FileName + "\"  --audio-quality 0 -x --audio-format \"opus\"";
      else if (FileName.contains(".vorbis") && Mode == 1) Conf += " -o \"" + FileName + "\"  --audio-quality 0 -x --audio-format \"vorbis\"";
    // Salida de Subtitulo según la etencion
      else if (FileName.contains(".srt") && Mode == 3) Conf += " -o \"" + FileName + "\" --convert-subs \"srt\"";
      else if (FileName.contains(".ass") && Mode == 3) Conf += " -o \"" + FileName + "\" --convert-subs \"ass\"";
      else if (FileName.contains(".vtt") && Mode == 3) Conf += " -o \"" + FileName + "\" --convert-subs \"vtt\"";
      else if (FileName.contains(".lrc") && Mode == 3) Conf += " -o \"" + FileName + "\" --convert-subs \"lrc\"";
      else if (FileName.contains(".unk")) Conf += " -o \"" + FileName + "\"";
      else Conf += " -o \"" + FileName + ".%(ext)s\""; // Extencion por defecto

    }else if (Estate == 1)  Conf += " -o \"" + FileName + ".%(ext)s\""; // Extencion por defecto
    // Salidas a Directorio
  }else {
    Conf += " -o \"";
    QString Flnm;

    // Ubicación
    if (Mode == 2) Flnm = QFileDialog::getExistingDirectory(this, LangString[12],
                                                                 QDir::toNativeSeparators(QDir::homePath()+"\\Videos") ,
                                                                 QFileDialog::ShowDirsOnly
                                                                 | QFileDialog::DontResolveSymlinks);
    else if (Mode == 3) Flnm = QFileDialog::getExistingDirectory(this, LangString[13],
                                                                 QDir::toNativeSeparators(QDir::homePath()+"\\Videos") ,
                                                                 QFileDialog::ShowDirsOnly
                                                                 | QFileDialog::DontResolveSymlinks);
    else if (Mode == 1 ) Flnm = QFileDialog::getExistingDirectory(this, LangString[11],
                                                                  QDir::toNativeSeparators(QDir::homePath()+"\\Music") ,
                                                                  QFileDialog::ShowDirsOnly
                                                                  | QFileDialog::DontResolveSymlinks);

    if (Flnm == "") goto salida;

    // Titulo de Salida
    if (ui->Oalbm->isChecked())  Flnm += "/%(playlist)s/%(playlist_index)s - %(title)s.%(ext)s\" "; //Album Mode


    else Flnm += "/%(title)s.%(ext)s\"";
  }
  if (!ui->Lproxy->text().isEmpty()) {
    Conf += " --proxy \"" + ui->Lproxy->text() +"\" ";
  }
  ui->Progress->setValue(35);
  setWindowTitle("DL-JS Lis - "+LangString[9]); //Rev

  if (!Execut(URLanlz(ui->URL->text(),URLc) , Conf)) {
    if (!(ui->Lpass->text().isEmpty())) Conf = Conf.replace( (Conf.indexOf("\" -p \"") + 6) , ui->Lpass->text().length() ,"******");

    ui->Status->setText(LangString[0]);
    ui->Progress->setValue(100);
    setWindowTitle("DL-JS Lis");
  } else  {
    if (!(ui->Lpass->text().isEmpty())) Conf = Conf.replace( (Conf.indexOf("\" -p \"") + 6) , ui->Lpass->text().length() ,"******");
    salida:;
    ui->Status->setText(LangString[1]);
    ui->Progress->setValue(0);
    setWindowTitle("DL-JS Lis");
  }

  ui->Progress->setEnabled(false);
  ui->Report->setText(Conf);
}

void MainWindow::on_URL_textChanged(const QString &arg1) {
    MinInt Inic = Start();
    if (Inic == 0 || Inic == 2) {
      ui->Mode1->setEnabled(false);
      ui->Mode2->setEnabled(false);
      ui->Mode3->setEnabled(false);
      if (Inic == 0) ui->Status->setText(LangString[2]);
      if (Inic == 2) ui->Status->setText(LangString[3]);
      ui->Bwebc->setEnabled(true);
      ui->Report->setText(LangString[4]);
      ui->Report->setText(LangString[5]);
    }else if (arg1.isEmpty()) {
      ui->Status->setText(LangString[6]);
      ui->Report->setText("");
      ui->Mode1->setEnabled(false);
      ui->Mode2->setEnabled(false);
      ui->Mode3->setEnabled(false);
    }else {
      ui->Status->setText("");
      ui->Report->setText("");
      ui->Mode1->setEnabled(true);
      ui->Mode2->setEnabled(true);
      ui->Mode3->setEnabled(true);
    }
    QString temp = URLanlz(arg1);
    if (temp == "crunchyroll") ui->Mode1->setEnabled(false);
    ui->Site->setText(temp.replace(0 , 1 , temp.begin()->toUpper()));
    ui->Progress->setValue(0);
}

// Boton de configuración
void MainWindow::on_Config_clicked() {
    ui->ConfigW->move(0,0);
    ui->ConfigW->setEnabled(true);
    IStart();
}

void MainWindow::IStart (void) {
  MinInt Inicio = Start();
  if (Inicio == 1) {
    ui->Ometa->setEnabled(false);
    ui->Otumb->setEnabled(false);
    ui->Ofzmt->setEnabled(false);
    ui->Ofzsb->setEnabled(false);

    ui->Ometa->setChecked(false);
    ui->Otumb->setChecked(false);
    ui->Ofzmt->setChecked(false);
    ui->Ofzsb->setChecked(false);
  } else if (Inicio == 3) {
    ui->Ometa->setEnabled(true);
    ui->Otumb->setEnabled(true);
    ui->Ofzmt->setEnabled(true);
    ui->Ofzsb->setEnabled(true);

    ui->Ometa->setChecked(true);  //Default
    ui->Otumb->setChecked(true);  //Default
  }
  if (ui->Rbper->isChecked()) {
    ui->Oucor->setEnabled(false);
    ui->Ouffm->setEnabled(false);
    ui->Ourla->setEnabled(false);
    ui->Ouvrd->setEnabled(false);
    ui->Ouwgt->setEnabled(false);
    ui->Ouydl->setEnabled(false);

    if (ui->Ouydl->isChecked()) {
      ui->Ouvrd->setEnabled(true);
    } else {
      ui->Ouvrd->setEnabled(false);
      ui->Ouvrd->setChecked(true);
    }
  } else {
    ui->Oucor->setEnabled(true);
    ui->Ouffm->setEnabled(true);
    ui->Ourla->setEnabled(true);
    ui->Ouvrd->setEnabled(true);
    ui->Ouwgt->setEnabled(true);
    ui->Ouydl->setEnabled(true);
  }
}

// Boton Guardar Configuración
void MainWindow::on_Bsave_clicked() {
  if ((!ui->Lpass->text().isEmpty() && !ui->Luser->text().isEmpty()) || (ui->Lpass->text().isEmpty() && ui->Luser->text().isEmpty())) {
    ui->ConfigW->move(400,300);
    ui->ConfigW->setEnabled(false);
    ui->Llinfo->setText("");
  } else {
    ui->Llinfo->setText(LangString[7]);
  }
}
// Reset
void MainWindow::on_Brest_clicked()
{
    ui->Oanam->setChecked(true);
    ui->Ofzsb->setChecked(false);
    ui->Odebg->setChecked(true);
    ui->Ometa->setChecked(true);
    ui->Oname->setChecked(true);
    ui->Osydt->setChecked(true);
    ui->Otumb->setChecked(true);
    ui->Ourla->setChecked(true);
    ui->Oelst->setChecked(false);
    ui->Ovsto->setChecked(true);
    ui->Ofzmt->setChecked(false);
    ui->Oalbm->setChecked(false);
    ui->Lpass->clear();
    ui->Luser->clear();
    ui->URL->clear();
    ui->VRes->setCurrentIndex(0);
    ui->VFPS->setCurrentIndex(0);
    ui->AAdR->setCurrentIndex(0);
    // Sub Idiom
    if (LangString[10] == "Spanish") ui->VRes->setCurrentIndex(0);
    else if (LangString[10] == "English") ui->VRes->setCurrentIndex(1);
    system("cls"); // Liampiar Consola

    ui->Progress->setValue(0);
    ui->Lproxy->clear();
    ui->Rbrec->setChecked(true);

    IStart();
}


void MainWindow::on_Done_clicked() {
    ui->Fabot->move(400,300);
    ui->Fabot->setEnabled(false);
    ui->ConfigW->setEnabled(true);
}

//Acerca de
void MainWindow::on_Babut_clicked() {
    ui->Fabot->move(10,15);
    ui->Fabot->setEnabled(true);
    ui->ConfigW->setEnabled(false);
}

//Modo 1
void MainWindow::on_Mode1_clicked() {
 Iniz(1);
}

// Modo 2
void MainWindow::on_Mode2_clicked() {
  Iniz(2);
}
// Modo 3
void MainWindow::on_Mode3_clicked() {
  Iniz(3);
}

void MainWindow::on_Oanam_stateChanged(int arg1) {
  if (arg1 == 2) ui->Oalbm->setEnabled(true);
  else if (arg1 == 0) ui->Oalbm->setEnabled(false);
}

void MainWindow::on_Oalbm_stateChanged(int arg1) {
  if (arg1 == 0) ui->Oanam->setEnabled(true);
  else if (arg1 == 2) {
    ui->Oanam->setEnabled(false);
    ui->Oanam->setChecked(true);
  }
}

void MainWindow::on_Bwebc_clicked() {
   // Updte(0);
   //1 Sistema de deteccion de componentes instalados (Otro modo del Start())
   //2 Si falta uno esencial El nombre del boton pasa de Actualizar a Instalar
   //3 Revisa las acciones del usuario
   //3a Recomendado
   // - Detecta si hay actualizaciones de DL-JS
   // - Las descarga si hay
   // - Autualiza el YoutubeDL (Indeferentemente)
   // - Si Hay Autualizacion de DL-JS 
   //     Crea un programa en 2do Plano e intala DL-JS
   //     El antiguo YoutubeDL queda respaldado como un .Resp
    ui->Prox_Updt->move(0,0);
}

void MainWindow::Iniz (const MinInt& Mode) {
  ui->Status->setText(LangString[9]);
  system("color 3");
  MinInt Estate = Start();
  if (!ui->URL->text().isEmpty()) {
    ui->Progress->setEnabled(true);
    ui->Progress->setValue(10);
    if (!ui->Oanam->isChecked()) {
      ui->centralwidget->setEnabled(false);
      QString fileName;

      if (Estate == 3) {

      if (Mode == 2) fileName = QFileDialog::getSaveFileName(this,
          LangString[12],
          QDir::toNativeSeparators(QDir::homePath()+"\\Videos\\VideoSinNombre"),
          "Formato Orignal (*) ;;Video MP4 (*.mp4) ;;Video FLV (*.flv) ;;Video Ogg (*.ogg) ;;Video Matroska (*.mkv) ;;Video AVI (*.avi) ;;Sin Extencion (*.unk)");

      else if (Mode == 1) fileName = QFileDialog::getSaveFileName(this,
          LangString[11],
          QDir::toNativeSeparators(QDir::homePath()+"\\Music\\AudioSinNombre"),
          "Formato Orignal (*) ;;Audio MP3 (*.mp3) ;;Audio ACC (*.acc) ;;Audio FLAC (*.flac) ;;Audio M4A (*.m4a) ;;Audio OPUS (*.opus) ;;Audio Vorbis (*.vorbis)");

      else if (Mode == 3) fileName = QFileDialog::getSaveFileName(this,
          LangString[13],
          QDir::toNativeSeparators(QDir::homePath()+"\\Videos\\SubtitulosSinNombre"),
          "Formato Orignal (*) ;;Sub STR (*.str) ;;Sub ASS (*.ass) ;;Sub VTT (*.vtt) ;;Sub LRC (*.lrc)");

      } else if (Estate == 1) {
        fileName = QFileDialog::getSaveFileName(this,
                  LangString[14],
                  QDir::toNativeSeparators(QDir::homePath()+"\\Videos\\SinNombre"));
      }
      ui->centralwidget->setEnabled(true);

      if (fileName != "") Iniz2(true,Mode,fileName);
    } else Iniz2(false,Mode);
  }
  else {
    on_URL_textChanged(ui->URL->text());
  }
}

#include <QLocale>
bool MainWindow::GetIdiom() {
  QLocale Lang;
  Lang = Lang.language();
  LangString[10] = Lang.languageToString(Lang.language());
  LangString[0] = tr("Completo");
  LangString[1] = tr("Error");
  LangString[2] = tr("Falta Youtube-DL y FFmpeg");
  LangString[3] = tr("Falta Youtube-DL");
  LangString[4] = tr("Descarga De Youtube DL & FFMpeg");
  LangString[5] = tr("Instale Youtube-DL y FFMpeg junto al ejecutable");
  LangString[6] = tr("Ingrese URL");
  LangString[7] = tr("Ingrese todos los datos");
//  LangString[8] = tr("");
  LangString[9] = tr("Espere a la Consola");
  LangString[11] = tr("Guardar Audio...");
  LangString[12] = tr("Guardar Video...");
  LangString[13] = tr("Guardar Subtitulos...");
  LangString[14] = tr("Guardar...");

  if ((Lang == QLocale::Spanish) || (Lang == QLocale::English)) return 0 ; else return 1;
}

//Links Externos
#include <QDesktopServices>
#include <QUrl>

void MainWindow::on_LKgit_clicked() {
  QDesktopServices::openUrl(QUrl("www.github.com/jackestar"));
}

void MainWindow::on_LKweb_clicked() {
  QDesktopServices::openUrl(QUrl("jackestar.netlify.app/indexDL"));
}

void MainWindow::on_LKdoc_clicked() {
  QDesktopServices::openUrl(QUrl("jackestar.netlify.app/HowTo"));
}

void MainWindow::on_LKmal_clicked() {
  QDesktopServices::openUrl(QUrl("mailto:drxzen@gmail.com"));
}

void MainWindow::on_Bout_clicked() {
    ui->Prox_Updt->move(400,300);
}

void MainWindow::on_pushButton_clicked()
{
  MinInt Salida = 0;
    if (ui->Rbrec->isChecked()){
      Salida = Updte(1);
      //All Updte
    } else if (ui->Rbper->isChecked()){
      MinInt Entrada = 0;
      if (ui->Oucor->isChecked()) Entrada +=4;
      if (ui->Ouydl->isChecked()) Entrada +=1;
      if (ui->Ouffm->isChecked()) Entrada +=2;
      if (ui->Ouwgt->isChecked()) Entrada +=8;
      Salida = Updte(Entrada);
    }
    if (Salida==0) ui->Status->setText(tr("Actualización Exitosa"));
    else {
      ui->Status->setText(tr(&"Error Durante la actulización: "[Salida]));
    }
}

void MainWindow::on_Rbrec_clicked() {
  // ui->Oresp->setEnabled(false);
  ui->Oucor->setEnabled(false);
  ui->Ouffm->setEnabled(false);
  // ui->Ouvrd->setEnabled(false);
  ui->Ouwgt->setEnabled(false);
  ui->Ouydl->setEnabled(false);
}

void MainWindow::on_Rbper_clicked() {
  // ui->Oresp->setEnabled(true);
  ui->Oucor->setEnabled(true);
  ui->Ouffm->setEnabled(true);
  // ui->Ouvrd->setEnabled(true);
  ui->Ouwgt->setEnabled(true);
  ui->Ouydl->setEnabled(true);
}
