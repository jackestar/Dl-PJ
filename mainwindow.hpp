  #ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QTranslator>

typedef unsigned short int MinInt;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void Iniz(const MinInt& Mode);

    void Iniz2(const bool FileNameBool,const MinInt& Mode,QString FileName="");

    void IStart (void);

    bool GetIdiom();

    void on_Mode1_clicked();

    void on_URL_textChanged(const QString &arg1);

    void on_Config_clicked();

    void on_Bsave_clicked();

    void on_Brest_clicked();

    void on_Done_clicked();

    void on_Babut_clicked();

    void on_LKgit_clicked();

    void on_LKweb_clicked();

    void on_LKdoc_clicked();

    void on_LKmal_clicked();

    void on_Mode2_clicked();

    void on_Mode3_clicked();

    void on_Bupdt_clicked();

    void on_Oanam_stateChanged(int arg1);

    void on_Oalbm_stateChanged(int arg1);

  private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
