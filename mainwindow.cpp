#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodos()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::metodos(){

    QString temp,temp1,temp2,temp3;         //Temporary use text strings

    double X1=ui->x1->value();   //Retrieves the X1-7 value of the spinbox
    double X2=ui->x2->value();   //
    double X3=ui->x3->value();   //
    double X4=ui->x4->value();   //
    double X5=ui->x5->value();   //
    double X6=ui->x6->value();   //
    double X7=ui->x7->value();

    double Y1=ui->y1->value();   //Retrieves the Y1-7 value of the spinbox
    double Y2=ui->y2->value();   //
    double Y3=ui->y3->value();   //
    double Y4=ui->y4->value();   //
    double Y5=ui->y5->value();   //
    double Y6=ui->y6->value();   //
    double Y7=ui->y7->value();   //

    double A[7]={X1,X2,X3,X4,X5,X6,X7};
    double B[7]={Y1,Y2,Y3,Y4,Y5,Y6,Y7};

    int i=1;      // storage usage variables
    double a=0;   //
    double b=0;   //
    double c=0;   //
    double d=0;   //
    double m=0;   //
    double r=0;   //
    double cu=0;  //
    double cua=0; //
    double xn=0;  //
    double yn=0;  //
    double a1=0;  //
    double num=0;  //
    double den=0;  //
    double a0=0;   //
    double Sr=0;   //
    double srr=0;  //
    double n=7;    //
    double R=0;    //
    double numr=0;
    double denr=0;
    double cuy=0;
    double cuay=0;
    double Sxy=0;
    for(i=0;i<n;i++){
        a=A[i];//summation of Xi
        b=b+a;//result of summation Xi
        c=B[i]; //summation of Yi
        d=c+d; //result of summation Yi
        m=A[i]*B[i];
        r=r+m; //multiplication sum of Xi * Yi
        cu=A[i]*A[i];//sums of squares of Xi
        cua=cua+cu; //result of sums of squares Xi
        cuy=B[i]*B[i];// sums of squares of Yi
        cuay=cuay+cuy; //result of sums of squares Yi
        xn=b/n;  //deniedX
        yn=d/n;  //deniedY
        srr=(B[i]-a0-a1*A[i])*(B[i]-a0-a1*A[i]);//calculation
        Sr=Sr+srr;                              // of Sr
    }
    num=(n*r-b*d);//numerator
    den=(n*cua-b*b);//denominator
    a1=num/den;     //calculation of a1

    a0=yn-a1*xn;    //calculation of a0
    Sxy=sqrt((Sr)/(n-2));// Calculation of Sx / y
   numr=(n*r-b*d);//numerator for the calculation of r
   denr=sqrt(n*cua-b*b)*sqrt(n*cuay-d*d);//denominator for the calculation of r
   R=(numr)/(denr); //calculation of r
    temp.append("\ny=").append(temp1.setNum(a0)).append("+").append(temp2.setNum(a1)).append("x \nr=").append(temp3.setNum(R));
     ui->text->setText(temp); //print;
       }
void MainWindow::borrar(){
    ui->x1->setValue(0.0);  //The spinbox is deleted
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);  //The spinbox is deleted
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);
    ui->x7->setValue(0.0);  //The spinbox is deleted

    ui->y1->setValue(0.0);
    ui->y2->setValue(0.0);
    ui->y3->setValue(0.0);  //The spinbox is deleted
    ui->y4->setValue(0.0);
    ui->y5->setValue(0.0);
    ui->y6->setValue(0.0);
    ui->y7->setValue(0.0);  //The spinbox is deleted
    ui->text->clear();
}

