#include "mainwindow.hpp"
#include "ui_mainwindow.h"

// Predefinidos para Libreira
#define MMPEG
#define ConDebug
#include "PreconfQT.hpp"
//#include "Strings_Langs.hpp"
//#include <QMessageBox>

//#include <QLocale>
QString LangString[10];

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{


//const QLocale Lang = QLocale::system();

// Returns
// QLocale::Chinese 25
// QLocale::English 31
// QLocale::French 37
// QLocale::Italian 58
// QLocale::Japanese 59
// QLocale::Portugues 91
// QLocale::Russian 96
// QLocale::Spanish 111

// Spanish def

//QString LangString[9] = {
//  "Completo",
//  "Error",
//  "Falta Youtube-DL y FFmpeg",
//  "Falta Youtube-DL",
//  "Descarga De Youtube DL & FFMpeg",
//  "Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg",
//  "Ingrese URL",
//  "Ingrese todos los datos",
//  "Ingrese un nombre!!!"
//};

//////English

/*QString Eng[9] = {
  "Complete",
  "Error",
  "Falta Youtube-DL y FFmpeg",
  "Falta Youtube-DL",
  "Descarga De Youtube DL & FFMpeg",
  "Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg",
  "Enter URL",
  "Ingrese todos los datos",
  "Ingrese un nombre!!!"
};
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
else {*/
  LangString[0] ="Completo";
  LangString[1] ="Error";
  LangString[2] ="Falta Youtube-DL y FFmpeg";
  LangString[3] ="Falta Youtube-DL";
  LangString[4] ="Descarga De Youtube DL & FFMpeg";
  LangString[5] ="Presiona Ctrl + U Para descargar Youtube-DL y FFMpeg";
  LangString[6] ="Ingrese URL";
  LangString[7] ="Ingrese todos los datos";
  LangString[8] ="Ingrese un nombre!!!";
//  ui->Status->setText(LangString[1]);
//  if (Lang == QLocale::Spanish) {
//    ui->Report->setText("weTalkSpan");
//  }
//  ui->Report->setText(Lang.name());
//}
//ingles

  ui->setupUi(this);
  QFile f(":qdarkstyle/style.qss");
  if (!f.exists())  {
//    QMessageBox msgBox;
//    msgBox.setText("Error durante la compilación, Estilos Erroneos");
//    msgBox.exec();
    ui->Status->setText(LangString[1]);
} else   {
      f.open(QFile::ReadOnly | QFile::Text);
      QTextStream ts(&f);
      qApp->setStyleSheet(ts.readAll());
  }
  ui->ConfigW->move(400,300);
  ui->Fname->move(400,300);
  ui->Fabot->move(400,300);
  system("title YoutubeDL-JS && color 3 && cls");
}

MainWindow::~MainWindow()
{
  delete ui;
}

//Audio Video Sub
void MainWindow::Iniz2 (QString FileName,const bool FileNameBool,const MinInt& Mode) {
  ui->Lfnam->clear();
  MinInt Estate = Start();
  char PrConfg[16] = "...............";

  if (Mode==1) {
    PrConfg[0] = 'a';                          //best a
  } else if (Mode==2) {
      if (Estate == 1) PrConfg[0] = 'b';       //best
      else if (Estate == 3) PrConfg[0] = '&';  //best v+a
  } else if (Mode==3) {
    PrConfg[0] = '#'; // Por descarte          //worst
  }
  if (Mode!=3) {
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
  switch (ui->VFPS->currentIndex()) {
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
  switch (ui->AAdR->currentIndex()) {
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
 }

  QString WebName = URLanlz(ui->URL->text()).toLower();

  if (ui->Oname->isChecked()) PrConfg[4] = '1';   // ASSic Name
  PrConfg[5] = '2';                               // COntinue & Console title
    if (ui->Oalbm->isChecked()) PrConfg[6] = '+'; // Album Mode
    else if (!FileNameBool) PrConfg[6] = '3';     // File Name

  if ( (WebName == "crunchyroll") || ( Mode == 3 && Mode != 1) || (Estate == 3 && Mode == 2) ) {
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
    if ((Estate == 3 && Mode == 2)) PrConfg[8] = '/'; //Embed Sub
  }

  bool URLc[3] = {false,false,false};
  if (WebName.contains("youtube")) {
    if (ui->Osydt->isChecked()) PrConfg[7] = '5';   // Youtube Manifest
    if (ui->Ovsto->isChecked()) PrConfg[14] = '%';   // Marcar Visto
    if (Mode == 1) URLc[0] = true;                  // Auto music.youtube.com
  }
  bool MetaAsing = ((Mode == 1 && Estate == 3) || (ui->Ofzmt->isChecked() && Mode != 3));
  if (Mode == 1 && Estate == 3) PrConfg[9] = '6'; // Audio Mp3 Best
  if (ui->Otumb->isChecked() && MetaAsing) PrConfg[10] = '7'; //Tumbl
  if (ui->Ometa->isChecked() && MetaAsing) PrConfg[11] = '8'; //Meta
  if (Mode == 3) PrConfg[15] = '9';               //Skip dowload 4 sub
  ui->Progress->setValue(25);

  if (ui->Ourla->isChecked()) URLc[1] = true;     //Analizar URL
  // if (ui->Oelst->isChecked()) URLc[2] = true;
  if (ui->Oelst->isChecked()) PrConfg[12] = '(';  //Playlist
  QString Conf = Config(PrConfg);
  if (!(ui->Lpass->text().isEmpty())/* && ui->Luser->text().isEmpty())*/) { // Descartada doble verificación
    Conf +=" -u \"" + ui->Luser->text() +"\" -p \"";
    Conf += ui->Lpass->text()+"\"";

  }

  if (FileNameBool) {
    Conf += " -o \"" + FileName + ".%(ext)s\"";
    ui->Lfnam->clear();
  }

  ui->Progress->setValue(35);
  if(!Execut(URLanlz(ui->URL->text() , URLc) , Conf)) {
      if (!(ui->Lpass->text().isEmpty())) {
      Conf = Conf.replace( (Conf.indexOf("\" -p \"") + 6) , ui->Lpass->text().length() ,"******");
      }
    ui->Progress->setEnabled(false);
    ui->Progress->setValue(100);
    ui->Status->setText(LangString[0]);
    ui->Report->setText(Conf);
  } else  {
    if (!(ui->Lpass->text().isEmpty())) {
    Conf = Conf.replace( (Conf.indexOf("\" -p \"") + 6) , ui->Lpass->text().length() ,"******");
    }
    ui->Status->setText(LangString[1]);
    ui->Report->setText(Conf);
    ui->Progress->setEnabled(false);
    ui->Progress->setValue(0);
  }
}

void MainWindow::on_URL_textChanged(const QString &arg1)
{
    MinInt Inic = Start();
    if (Inic == 0 || Inic == 2) {
      ui->Mode1->setEnabled(false);
      ui->Mode2->setEnabled(false);
      ui->Mode3->setEnabled(false);
      Inic == 0 ? ui->Status->setText(LangString[2]): void();
      Inic == 2 ? ui->Status->setText(LangString[3]): void();
      ui->Bupdt->setEnabled(true);
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
}

// Boton de configuración
void MainWindow::on_Config_clicked()
{
    ui->ConfigW->move(0,0);
    ui->ConfigW->setEnabled(true);
    if (Start() == 1) {
      ui->Ometa->setEnabled(false);
      ui->Otumb->setEnabled(false);
      ui->Ofzmt->setEnabled(false);
      ui->Ometa->setChecked(false);
      ui->Otumb->setChecked(false);
      ui->Ofzmt->setChecked(false);
    } else {
      ui->Ometa->setEnabled(true);
      ui->Otumb->setEnabled(true);
      ui->Ofzmt->setEnabled(true);
      ui->Ometa->setChecked(true);
      ui->Otumb->setChecked(true);
    }
}

// Boton Guardar Configuración
void MainWindow::on_Bsave_clicked()
{
  if ((!ui->Lpass->text().isEmpty() && !ui->Luser->text().isEmpty()) || (ui->Lpass->text().isEmpty() && ui->Luser->text().isEmpty())) {
    ui->ConfigW->move(400,300);
    ui->ConfigW->setEnabled(false);
    ui->CLabel7->setText("");
  } else {
    ui->CLabel7->setText(LangString[7]);
  }
}

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
    ui->Lfnam->clear();
    ui->URL->clear();
    ui->VRes->setCurrentIndex(0);
    ui->VFPS->setCurrentIndex(0);
    ui->AAdR->setCurrentIndex(0);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    arg1.isEmpty()? ui->Bfnme->setEnabled(false) : ui->Bfnme->setEnabled(true);
}

void MainWindow::on_Done_clicked()
{
    ui->Fabot->move(400,300);
    ui->Fabot->setEnabled(false);
    ui->ConfigW->setEnabled(true);
}

//Acerca de
void MainWindow::on_Babut_clicked()
{
    ui->Fabot->move(10,15);
    ui->Fabot->setEnabled(true);
    ui->ConfigW->setEnabled(false);
}

//Modo 1
void MainWindow::on_Mode1_clicked()
{
 Iniz(1);
}

// Modo 2
void MainWindow::on_Mode2_clicked()
{
  Iniz(2);
}
// Modo 3
void MainWindow::on_Mode3_clicked()
{
  Iniz(3);
}


void MainWindow::on_Ourla_stateChanged(int arg1)
{
  if (arg1 == 0) ui->Oelst->setEnabled(false);
  else if (arg1 == 2) ui->Oelst->setEnabled(true);
}

void MainWindow::on_Oanam_stateChanged(int arg1)
{
  if (arg1 == 2) ui->Oalbm->setEnabled(true);
  else if (arg1 == 0) ui->Oalbm->setEnabled(false);
}

void MainWindow::on_Oalbm_stateChanged(int arg1)
{
  if (arg1 == 0) ui->Oanam->setEnabled(true);
  else if (arg1 == 2) {
    ui->Oanam->setEnabled(false);
    ui->Oanam->setChecked(true);
  }
}

//Update
void MainWindow::on_Bupdt_clicked()
{
  system("DL-net.exe d c");
}

void MainWindow::on_Bfnme_clicked()
{
  if (ui->Lfnam->text().isEmpty()) {
    ui->fnamL->setText(LangString[8]);
    ui->Bfnme->setEnabled(false);
  }
  else {
    ui->Fname->move(400,300);
    ui->Fname->setEnabled(false);
  }
}

void MainWindow::on_Lfnam_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty()) ui->Bfnme->setEnabled(true);
    else ui->Bfnme->setEnabled(true);
}

#include <QTest>
#include <QSignalSpy>
#include <QTimer>

void MainWindow::Iniz (const MinInt& Mode) {
  system("color 2");
  if (!ui->URL->text().isEmpty()) {
    ui->Progress->setEnabled(true);
    ui->Progress->setValue(10);
    if (!ui->Oanam->isChecked()) {
      ui->Fname->move(75,100);
      ui->Mode1->setEnabled(false);
      ui->Mode2->setEnabled(false);
      ui->Mode3->setEnabled(false);
      ui->Config->setEnabled(false);
      ui->URL->setEnabled(false);
      ui->Fname->setEnabled(true);
      bool temp = true;
      while ( temp && ui->Lfnam->text().isEmpty()) {
        QSignalSpy spy(ui->Bfnme, SIGNAL(clicked(bool)));
        temp = !spy.wait(1610612737); // We Need Change this
//        int ttem = 1610612737;
      }

      ui->Mode1->setEnabled(true);
      ui->Mode2->setEnabled(true);
      ui->Mode3->setEnabled(true);
      ui->Config->setEnabled(true);
      ui->URL->setEnabled(true);
      Iniz2(ui->Lfnam->text().toLocal8Bit(),true,Mode); //Need Rev...
    } else Iniz2("",false,Mode);
  }
  else {
    on_URL_textChanged(ui->URL->text());
  }
}

//Links Externos
#include <QDesktopServices>
#include <QUrl>

void MainWindow::on_LKgit_clicked()
{
     QDesktopServices::openUrl(QUrl("www.github.com/"));
}

void MainWindow::on_LKweb_clicked()
{
    QDesktopServices::openUrl(QUrl("#/indexDL.html"));
}

void MainWindow::on_LKdoc_clicked()
{
    QDesktopServices::openUrl(QUrl("#/DLdocs.html"));
}

void MainWindow::on_LKmal_clicked()
{
  QDesktopServices::openUrl(QUrl("mailto:drxzen@gmail.com"));
}

