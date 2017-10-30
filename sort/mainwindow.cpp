#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&generation, SIGNAL(clicked()), SLOT(on_generation_clicked()));
    connect(&sort, SIGNAL(clicked()), SLOT(on_sort_clicked()));
    connect(&bubble, SIGNAL(clicked()), SLOT(on_bubble_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bubble_clicked()
{
    ui->time_text->clear();
   unsigned int start_time =  clock();
    ui->after->clear();
    for (int i = 0; i <vector.size(); i++) {
        for (int j = 0; j < vector.size()-1; j++) {
            if (vector[j] > vector[j + 1]) {

                int temp;
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time)/1000;
    for(int i=0; i<vector.size(); i++)
    {
        str += QString::number(vector[i]);
        str += " ";
    }
    ui->after->append(str);
    sec+=QString::number(search_time);
    ui->time_text->append(sec + "msec");
    search_time=0;
    str.clear();
    sec.clear();
}

void MainWindow::on_sort_clicked()
{
    unsigned int start_time =  clock();
    ui->after->clear();
    ui->time_text->clear();
    std::sort(vector.begin(), vector.end());
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
       for(int i=0; i<vector.size(); i++)
       {
           str += QString::number(vector[i]);
           str +=" ";

       }
       sec+=QString::number(search_time);
       ui->after->append(str);
       ui->time_text->append(sec + "msec");
       search_time=0;
        str.clear();
        sec.clear();
}

void MainWindow::on_generation_clicked()
{
    ui->before->clear();
    srand(time(NULL));
    for(int i=0; i<vector.size(); i++)
        vector[i]=rand()%100;

    for(int i=0; i<vector.size(); i++)
    {
        str += QString::number(vector[i]);
        str += " ";
    }
    ui->before->append(str);
    str.clear();

}
