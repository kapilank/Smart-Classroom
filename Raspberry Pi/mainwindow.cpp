#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include<qthread.h>
#include<QDebug>
#include<QTime>
#define IO_ReadOnly QIODevice::ReadOnly


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QTimer *timer = new QTimer(this);
      //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
      //timer->start(1000);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);


   QPixmap bkgnd("./image/bg.jpg");
  //bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
   // bkgnd=bkgnd.scaled(this->size(),Qt::AlignVCenter);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

//       QPixmap pix("./image/logo.jpg");

//       pix =pix.scaled(this->size(),Qt::AlignTop);
//       QPalette palette1;
//       palette1.setBrush(QPalette::Background, pix);


//       this->setPalette(palette1);
       //ui->infoButton->setStyleSheet("background-image:url(./image/s.png)");
       //ui->infoButton->adjustSize();
     //  ui->infoButton->setAutoFillBackground(true);
       QPixmap pixmap("./image/s.png");
       QIcon ButtonIcon(pixmap);

       //ui->infoButton->setIcon(ButtonIcon);
       //ui->infoButton->setIconSize(pixmap.rect().size());
       //ui->infoButton->setAutoFillBackground(true);
       //ui->infoButton->adjustSize();

       QPixmap pixmap1("./image/c.png");
       QIcon ButtonIcon1(pixmap1);
       ui->okButton->setIcon(ButtonIcon1);
       ui->okButton->setIconSize(pixmap1.rect().size());

       QPixmap pixmap2("./image/d.png");
       QIcon ButtonIcon2(pixmap2);
       ui->quitButton->setIcon(ButtonIcon2);
       ui->quitButton->setIconSize(pixmap2.rect().size());


       QPixmap pixmap3("./image/v.png");
       QIcon ButtonIcon3(pixmap3);
       ui->pushButton->setIcon(ButtonIcon3);
       ui->pushButton->setIconSize(pixmap3.rect().size());

  //      ui->frame->setFrameStyle(QFrame::StyledPanel);

//ui->frame->setStyleSheet("background-image: url(./image/url.jpeg)");

       //QObject::connect(ui->infoButton,SIGNAL(toggled(bool)),this,SLOT(close()));
     //  ui->infoButton->setFocus(Qt::FocusReason);

       QPixmap p("./image/url.jpeg");
       QIcon  i(p);
       ui->label->setStyleSheet("border-image:url(:/image/url.jpeg);");
       ui->label->setPixmap(p);
       ui->label->setScaledContents(true);
       ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );



/*
       QPixmap p1("./image/y.jpg");
       QIcon  i1(p1);
       ui->label_5->setStyleSheet("border-image:url(:/image/y.jpg);");
       ui->label_5->setPixmap(p1);
       ui->label_5->setScaledContents(true);
       ui->label_5->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );*/

/*
       QPalette palette1 = ui->label_3->palette();
        palette1.setColor(ui->label_3->backgroundRole(), Qt::yellow);
        palette1.setColor(ui->label_3->foregroundRole(), Qt::yellow);
        ui->label_3->setPalette(palette1);

        QPalette palette2 = ui->label_4->palette();
         palette2.setColor(ui->label_4->backgroundRole(), Qt::yellow);
         palette2.setColor(ui->label_4->foregroundRole(), Qt::yellow);
         ui->label_4->setPalette(palette2);*/




         QPalette palette3 = ui->label_5->palette();
          palette3.setColor(ui->label_5->backgroundRole(), Qt::yellow);
          palette3.setColor(ui->label_5->foregroundRole(), Qt::green);
          ui->label_5->setPalette(palette3);

  //  QObject::connect(ui->sizeSpinBox,SIGNAL(valueChanged(int)),ui->sizeSlider,SLOT(setValue(int)));
 //   QObject::connect(ui->sizeSlider,SIGNAL(valueChanged(int)),ui->sizeSpinBox,SLOT(setValue(int)));
  //  ui->correcLevel->addItem(tr("L Level"));
  //  ui->correcLevel->addItem(tr("M Level"));
  //  ui->correcLevel->addItem(tr("Q Level"));
   // ui->correcLevel->addItem(tr("H Level"));
   // ui->fileLineEdit->setText(QFSFileEngine::currentPath().append("/test.png"));
   // ui->fileLineEdit->setText(QFSFileEngine::rootPath().append("/tmp/test.png"));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_quitButton_clicked()
{



    system("sh doff.sh");
    system("killall recv.bin");
    system("killall recv2.bin");
    system("killall sendclass.bin");
    system("killall syl.bin");
    system("killall passwd.bin");
    system("killall pin.bin");
    system("killall userblock.bin");
    system("killall failed.bin");
    system("killall balenq.bin");
    system("killall leafpad ");
    system("rm -r /tmp/*.dat");
    system("rm -r /tmp/*.strm");
    system("rm -r /tmp/*.jpg");
    system("rm -r /tmp/*.png");
    this->close();
}

void MainWindow::on_infoButton_clicked()
{

    //QTime tm2;

   // tm2.setHMS(12, 00, 45, 155);
    //tm2.currentTime();

    //ui->timeEdit->setTime(tm2);


      //  QMessageBox customMsgBox;
    //customMsgBox.setWindowTitle(tr("test"));
    //customMsgBox.addButton(tr(""),QMessageBox::ActionRole);
//    customMsgBox.setIconPixmap(QPixmap(""));
  //  customMsgBox.setText(tr("").arg("")
    //                     .arg(tr(""))
      //                   .arg(tr(""))
        //                 .arg(tr("")));
    //customMsgBox.exec();
    //return;

  //  system("./idsend.bin  10.0.0.42 1234 ");
 //   system("./recv.bin");

//    system("./mkqr.bin");

    cout<<"print......"<<endl;
    //system("./passwd.bin  &");
 //   system("./recv.bin &");
//        mythread t;
//        t.start();
//        t.wait();








}

void MainWindow::on_okButton_clicked()
{


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    ui->okButton->setEnabled(false);
//    ui->textEdit->setDisabled(true);


    int size;
    char level;
    QString args;
    const char* run;
    QByteArray toChar;


    // system("./passwd.bin &");
    system("./recv.bin &");

            mythread t;
            t.start();
           // t.wait();


    //QTimer timer1;
    //connect(&timer1, SIGNAL(timeout()), this, SLOT(smclass()));
    //timer1.start(1000);


//    if(ui->fileLineEdit->text().isEmpty())
//    {
//        QMessageBox::warning(this,tr("alert"),tr("output file name is not specific！"),QMessageBox::Close);
//        ui->okButton->setEnabled(true);
//        return;
//    }

    QFile file("status.strm");

    QString line;

    if (!file.open(IO_ReadOnly)) // Open the file
    {
        QMessageBox::warning(this,tr("alert"),tr("data not yet recieve ！"),QMessageBox::Close);
        ui->okButton->setEnabled(true);
        return;
    }


    QTextStream stream(&file); // Set the stream to read from myFile

    while(!stream.atEnd()){
        line = stream.readLine(); // this reads a line (QString) from the file
      // ui->textEdit->append(line);
      //  ui->textEdit->appendPlainText(line);
        ui->label_5->setText(line);
       }


   //if(ui->textEdit->toPlainText()==NULL)
    if(ui->label_5->text()==NULL)
//
    {
        QMessageBox::warning(this,tr("alert"),tr("No Data is Present！"),QMessageBox::Close);
        ui->okButton->setEnabled(true);
        return;
    }
    else

    {
  //  size = ui->sizeSlider->value();
    /*switch(ui->correcLevel->currentIndex())
    {
    case 0:level = 'L';
        break;
    case 1:level = 'M';
        break;
    case 2:level = 'Q';
        break;
    case 3:level = 'H';
        break;
    default:QMessageBox::warning(this,tr("alert"),tr("undefine error ！"),QMessageBox::Close);
        this->close();
    }*/

    //stringstream out1;
    //for (int k = 0; k < 1; k++)
    //{
     //   out1 <<"cat "<<""<< "cont.txt" <<endl;
    //     string c1 = out1.str();
  //          cout << c1;

//    }

//    system(out1.str().c_str());

//    }



    args = QString("qrencode -s %1 -l %2 -o %3 \"%4\"")
           .arg(size).
           arg(level).
           //arg(fileName).
            arg("/tmp/test.png").
          // arg(ui->textEdit->toPlainText());
            arg(ui->label_5->text());
            //arg(out1);
    toChar = args.toLocal8Bit();
    run = toChar.data();
    //
    system(run);

    this->statusBar()->showMessage(tr("opertion complited ."),2000);
    //showPNG(fileName);
  //  showPNG("/tmp/test.png");
    ui->okButton->setEnabled(true);
   // system("./passwd");
   // system("./thread");

//        system("./pin.bin &");



    }
}
/*
void MainWindow::on_fileButton_clicked()
{
    QString filename;
    filename="/tmp/test.png";



    //fileName = QFileDialog::getSaveFileName(this,tr("save as"),".",tr("PNG File(*.png)"));

   // if(fileName.isEmpty())
           // if(filename==NULL)
        return;
   // ui->fileLineEdit->setText(fileName);
}
*/
/*void MainWindow::on_fileLineEdit_textChanged(QString )
{
    //if(ui->fileLineEdit->text().isEmpty())
      //  return;
    //fileName = ui->fileLineEdit->text();
    fileName ="/tmp/test.png";
}*/

void MainWindow::showPNG(QString fileName)
{
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("qrcode"));
    customMsgBox.addButton(tr("close"),QMessageBox::ActionRole);
    customMsgBox.setIconPixmap(QPixmap(fileName));
    customMsgBox.exec();
    return;
}



void MainWindow::on_pushButton_clicked()
{ //fun open
//int i;
//int attempts= 3;
system("sh don.sh");
//static int count;

 // count++;

  //ui->label->setText(QString::number(count));
  //ui->textEdit_2->setText(QString::number(count));

//if(ui->textEdit_2->toPlainText()==NULL)
 // a:
    /*if(ui->lineEdit->text()==NULL)

    {
        QMessageBox::warning(this,tr("alert"),tr("pin number Not Entered ！"),QMessageBox::Close);
    }
else
      { //else
    QFile file("/tmp/passwd.dat");

            QString line;
            if (!file.open(IO_ReadOnly)) // Open the file
            {
                QMessageBox::warning(this,tr("alert"),tr("data not yet recieve ！"),QMessageBox::Close);
                ui->okButton->setEnabled(true);
                return;
            }

             QTextStream stream(&file); // Set the stream to read from myFile
             while(!stream.atEnd()){
                 line = stream.readLine(); // this reads a line (QString) from the file

                }

        //if(ui->textEdit_2->toPlainText()==line)
            if(ui->lineEdit->text()==line)
                {


//    QMessageBox::information(this,tr("information"),tr("transaction  succeded ！"),QMessageBox::Close);
//  ui->okButton->setEnabled(true);
                system("./transaction/trans.bin");
                    return;

        }

        //else  if(ui->textEdit_2->toPlainText()!=line )
          else  if(ui->lineEdit->text()!=line)
       {
            if(count<=3)
            //if()
            {


            QMessageBox::warning(this,tr("information"),tr("Transaction  Failed  Try Again ！"),QMessageBox::Close);
                            ui->okButton->setEnabled(true);
                            return;



            }
            else if(count>3)
            {
                QMessageBox::warning(this,tr("alert"),tr("Sorry, only allowed 3 attempts ！"),QMessageBox::Close);


                                ui->okButton->setEnabled(true);
                                 //ui->textEdit->setDisabled(true);
//                                ui->textEdit_2->setDisabled(true);
                                ui->pushButton->setDisabled(true);



                                cout<<"start capturing ..."<<endl;
                                system("./facedetect/facedetect");
                                system("./imgsend.bin 10.0.0.42 1238 ");
                                  system("./loading/load.bin &");
                                system("./userblock.bin");
                                //return;
////////////////////////////////////

                                QFile file3("/tmp/status.dat");

                                        QString line3;
                                       if (!file3.open(IO_ReadOnly)) // Open the file
                                        {
                                            QMessageBox::warning(this,tr("alert"),tr("data not yet recieve ！"),QMessageBox::Close);
                                            ui->okButton->setEnabled(true);
                                            return;
                                        }

                                         QTextStream stream3(&file3); // Set the stream to read from myFile
                                         while(!stream3.atEnd()){
                                             line3 = stream3.readLine(); // this reads a line (QString) from the file

                                            }
                                         system("killall load.bin");
                                         if(line3=="true")
                                          {
                                             system("./success/success.bin &");
                                             sleep(5);
                                             system("killall success.bin");

                                             ui->pushButton->setEnabled(true);
                                             ui->lineEdit->setText("");
                                             system("./pin/pin.bin &");

                                        //     goto a;
//                                             static int count1;
//                                             count1++;

//                                         if(count1<=6)
//                                         //if()
//                                         {


//                                         QMessageBox::warning(this,tr("information"),tr("Again Transaction  Failed  Try Again ！"),QMessageBox::Close);
//                                                        // ui->okButton->setEnabled(true);
//                                                         return;



//                                         }
//                                         else if(count1>6)
//                                         {
//                                             QMessageBox::warning(this,tr("alert"),tr("Sorry, You Tried All Attempts ！"),QMessageBox::Close);
//                                             ui->pushButton->setDisabled(true);
//                                             ui->okButton->setDisabled(true);
//                                             ui->infoButton->setDisabled(true);
//                                             ui->pushButton->setEnabled(true);
//                                             return;

//                                         }


}
                                         else if(line3=="false")
                                         {
                                            // QMessageBox::critical(this,tr("Failed"),tr("Your Identity  Ultimatly Failed ！"),QMessageBox::Close);
                                           ui->pushButton->setDisabled(true);
                                           ui->okButton->setDisabled(true);
                                           ui->infoButton->setDisabled(true);

                                           ui->pushButton->setDisabled(true);

                                           system("./failed/failed.bin &");

                                           sleep(5);
                                           system("killall failed.bin");

                                         }

                                        /* else
                                         {
                                             QMessageBox::critical(this,tr("Failed"),tr("Your Procsess ultimatly Failed ！"),QMessageBox::Close);
                                             //ui->okButton->setEnabled(true);
                                             ui->pushButton->setDisabled(true);
                                             ui->okButton->setDisabled(true);
                                             ui->infoButton->setDisabled(true);
                                             //ui->pushButton->setEnabled(true);
                                             ui->pushButton->setDisabled(true);
                                             return;

                                         }*/


///////////////////////////////////////////




    //        }
        //    }






      //}//else


} //fun close



void mythread::run()
{
    // qDebug() << " thread " << thread()->currentThreadId();
    //cout<<"thred"<<thread()->currentThreadId()<<endl;

    forever

   {
 //       sleep(2);
system("./syl.bin &");
sleep(240);

    }
    /*QTimer timer1;

    //connect(&timer1, SIGNAL(timeout()),this,SLOT(fire(),Qt::DirectConnection));
    connect(&timer1, SIGNAL(timeout()), this, SLOT(showTime()));
         qDebug() << "A::worker  -- currentThread:" << currentThread();

         timer1.start(1000);

         QThread::exec();;*/


}




/*
void MainWindow::on_infoButton_Hover()
{

    QMessageBox::warning(this,tr("information"),tr("  try again ！"),QMessageBox::Close);
                    ui->okButton->setEnabled(true);
                    return;

}*/

void MainWindow::on_infoButton_toggled(bool checked)
{

    if(checked==true) {


    QMessageBox::warning(this,tr("information"),tr("  try again ！"),QMessageBox::Close);
                    ui->okButton->setEnabled(true);
                   // return;

    }

    else if(checked==false)
    {
        QMessageBox::warning(this,tr("information"),tr(" again ！"),QMessageBox::Close);
                        ui->okButton->setEnabled(true);
                      //  return;

    }

}


//void MainWindow::focusOutEvent(QFocusEvent *)
//{
//    QMessageBox::warning(this,tr("information"),tr("  try again ！"),QMessageBox::Close);
//                    ui->okButton->setEnabled(true);
//                    return;

//}



void MainWindow::on_lineEdit_selectionChanged()
{
    system("killall pin.bin");
}
void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
   // display(text);
    //ui->timeEdit->settime(text);
    ui->lcdNumber->display(text);
}


//}
void mythread::syll()
{

    system("./smart");
}
void MainWindow::smclass()
{
system("./syl.bin &");
}
