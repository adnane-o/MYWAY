#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <string>
#include <iostream>
#include <QtSql>
#include <Dijkstra.h>
#define q2c(string) string.toStdString()
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id_depart=-1;
    id_arrive=-1;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setvalues(int n)
{
    this->id_arrive=n;
    this->id_depart=n;
}
void MainWindow::Show_Route(std::vector<int>& A,std::vector<QWidget*>& R)
{

    for(unsigned int i=0;i<A.size()-1;i++)
    {
        QSqlQuery qry;
        QString B="select id_R from distance where id_d="+QString::number(A[i])+" and id_a="+QString::number(A[i+1]);
        qry.exec(B);
        while(qry.next())
        {
            R[qry.value(0).toInt()]->show();
        }
    }
}

void MainWindow::on_Reintialiser_clicked()
{
    setvalues(-1);
    ui->Ville_depart->setText("");
    ui->Ville_arrivee->setText("");
    ui->Distance->setText("");
}
void MainWindow::on_LaayouneButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=17;
    }
    else if (id_arrive==-1)
    {
     id_arrive=17;
    }
}
void MainWindow::on_TantanButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=9;
    }
    else if (id_arrive==-1)
    {
     id_arrive=9;
    }
}
void MainWindow::on_AgadirButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=8;
    }
      else if (id_arrive==-1)
    {
     id_arrive=8;
    }
}
void MainWindow::on_OuarzazateButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=16;
    }
        else if (id_arrive==-1)
    {
     id_arrive=16;
    }
}
void MainWindow::on_EssaouiraButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=6;
    }
    else if (id_arrive==-1)
    {
     id_arrive=6;
    }
}
void MainWindow::on_MarrakechButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=7;
    }
    else if (id_arrive==-1)
    {
     id_arrive=7;
    }
}
void MainWindow::on_BeniMellalButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=13;
    }
     else if (id_arrive==-1)
    {
     id_arrive=13;
    }
}
void MainWindow::on_ErrachidiaButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=14;
    }
    else if (id_arrive==-1)
    {
     id_arrive=14;
    }
}
void MainWindow::on_EljadidaButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=5;
    }
    else if (id_arrive==-1)
    {
     id_arrive=5;
    }
}
void MainWindow::on_CasablancaButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=4;
    }
    else if (id_arrive==-1)
    {
     id_arrive=4;
    }
}
void MainWindow::on_RabatButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=3;
    }
    else if (id_arrive==-1)
    {
     id_arrive=3;
    }
}
void MainWindow::on_KenitraButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=2;
    }
    else if (id_arrive==-1)
    {
     id_arrive=2;
    }
}
void MainWindow::on_FesButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=12;
    }
     else if (id_arrive==-1)
    {
     id_arrive=12;
    }
}
void MainWindow::on_MeknesButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=18;
    }
    else if (id_arrive==-1)
    {
     id_arrive=18;
    }
}
void MainWindow::on_OujdaButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=15;
    }
    else if (id_arrive==-1)
    {
     id_arrive=15;
    }
}
void MainWindow::on_NadorButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=11;
    }
     else if (id_arrive==-1)
    {
     id_arrive=11;
    }
}
void MainWindow::on_AlhoceimaButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=10;
    }
      else if (id_arrive==-1)
    {
     id_arrive=10;
    }
}
void MainWindow::on_TetouanButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=1;
    }
      else if (id_arrive==-1)
    {
     id_arrive=1;
    }
}
void MainWindow::on_TangerButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=0;
    }
    else if (id_arrive==-1)
    {
     id_arrive=0;
    }
}
void MainWindow::on_ChefchaouenButton_clicked()
{
    if (id_depart==-1)
    {
    id_depart=19;
    }
    else if (id_arrive==-1)
    {
     id_arrive=19;
    }
}
void MainWindow::on_Generer_clicked()
{
    if(id_arrive==-1 || id_depart==-1)
    {

    }
    else
    {
        Dijkstra G(id_depart);
        G.read();
        G.calculateDistance();
        vector<int> Path;//hada howa vecteur lifih dikchi
        G.printPath(id_arrive,Path);//ymklek tkhdem bih mur hadi
        Show_Route(Path,R);
        ui->Ville_depart->setText(tab_villes[id_depart]);
        ui->Ville_arrivee->setText(tab_villes[id_arrive]);
        ui->Distance->setText(QString::number(G.getdistance(id_arrive)));
    }
}
