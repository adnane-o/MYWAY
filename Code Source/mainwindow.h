#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include<vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setvalues(int);
    char tab_villes[20][20]={"Tanger","Tetouan","Kenitra","Rabat","Casablanca","Eljadida",
                             "Essaouira","Marrakech","Agadir","Tantan","AlHoceima","Nador",
                             "Fes","Beni-Mellal","Errachidia","Oujda","Ouarzazate","Laayoune",
                             "Meknes","Chefchaouen"};
    int id_depart;
    int id_arrive;
    std::vector<QWidget*> R;
    void Show_Route(std::vector<int>&,std::vector<QWidget*>&);
    
private slots:
    void on_LaayouneButton_clicked();
    void on_TantanButton_clicked();
    void on_AgadirButton_clicked();
    void on_OuarzazateButton_clicked();
    void on_EssaouiraButton_clicked();
    void on_Reintialiser_clicked();
    void on_MarrakechButton_clicked();
    void on_BeniMellalButton_clicked();
    void on_ErrachidiaButton_clicked();
    void on_EljadidaButton_clicked();
    void on_CasablancaButton_clicked();
    void on_RabatButton_clicked();
    void on_KenitraButton_clicked();
    void on_FesButton_clicked();
    void on_MeknesButton_clicked();
    void on_OujdaButton_clicked();
    void on_NadorButton_clicked();
    void on_AlhoceimaButton_clicked();
    void on_TetouanButton_clicked();
    void on_TangerButton_clicked();
    void on_Generer_clicked();
    void on_ChefchaouenButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H


/*<property name="visible">
   <bool>false</bool>
</property>  */
