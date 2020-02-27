#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QFileInfo>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化
    //灰色的默认提示
    ui->lineEdit->setPlaceholderText(" 上传您需要水印的图片");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//选择上传图片
void MainWindow::on_pushButton_clicked()
{
    PicfileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Image Files (*.png *.jpg *.bmp *.gif)"));

    if("" == PicfileName)
    {
        bFlag = false;
        ui->lineEdit_3->setText("未成功上传图片文件名为空");
        ui->lineEdit->setText("");
        PicfileName = "";
    }
    else
    {
        bFlag = true;
        ui->lineEdit_3->setText("成功上传图片!");
        ui->lineEdit->setText(PicfileName);
    }

}

void MainWindow::on_lineEdit_editingFinished()
{

    PicfileName = ui->lineEdit->text();
    ui->lineEdit_3->setText(PicfileName);
}

//pushButton_2显示图片，加载
void MainWindow::on_pushButton_2_clicked()
{
    ui->label_2->setScaledContents(true);

    QMovie *movie = new QMovie(PicfileName);
    ui->label_2->setMovie(movie);
    movie->start();

    //加载 路径图片
    if(Picpixmap.load(PicfileName))
    {
        bFlag = true;
        ui->lineEdit_3->setText("图片加载成功!");
    }
    else
    {
        bFlag = false;
        ui->lineEdit_3->setText("图片加载失败!");
    }

}

//lineEdit_2保存水印文本
void MainWindow::on_lineEdit_2_editingFinished()
{
    WaterName = ui->lineEdit_2->text();
}

//pushButton_3 水印按钮
void MainWindow::on_pushButton_3_clicked()
{
    if(!bFlag)
    {
        if("" == PicfileName)
        {
            ui->lineEdit_3->setText("请先选择图片!");
        }
        else
        {
            ui->lineEdit_3->setText("图片加载失败请重试!");//显示 最后几个字出现乱码
        }
    }
    else
    {
        //加载 路径图片
        Picpixmap.load(PicfileName);
        MainWindow::MyMark(Picpixmap,WaterName);

        QFile file(PicfileName);

        if(Picpixmap.save(&file, "JPG"))
        {
            bFlag = true;
            //ui->lineEdit_3->setText("文件保存成功!");
        }
        else
        {
            bFlag = false;
            ui->lineEdit_3->setText("文件保存失败!");
        }
        file.close();
    }
}

//加水印
void MainWindow::MyMark(QPixmap & pm,const QString& text)
{
    //
    if(!Mypainter.begin(&pm))
    {
        ui->lineEdit_3->setText("图片初始化失败!");
    }



    int fontSize = 25, spacing = 10;

    //设置字体
    MainWindow::MyGetFont();

    QFont font(sFont, fontSize, QFont::Thin);//默认
    font.setLetterSpacing(QFont::AbsoluteSpacing, spacing);
    Mypainter.setFont(font);

    //设置颜色
    MainWindow::MyGetColor();

    Mypainter.translate(pm.width() / 2, -pm.width() / 2);//调整位置

    Mypainter.rotate(45);
    int squareEdgeSize = pm.width() * sin(45.0) + pm.height() * sin(45.0);//对角线长度
    int hCount = squareEdgeSize / ((fontSize + spacing) * (text.size() + 1)) + 1;
    int x = squareEdgeSize / hCount + (fontSize + spacing) * 3;
    int y = x / 2;

    for (int i = 0; i < hCount; i++)
    {
        for (int j = 0; j < hCount * 2; j++)
        {
           Mypainter.drawText(x * i, y * j,text);
        }
    }

    /*结束painter；
     * 否则会报错:QPixmap::operator=: Cannot assign to pixmap during painting;
     *          QPainter::begin: A paint device can only be painted by one painter at a time.
     */
    Mypainter.end();
}

//光标改变 槽函数
void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    PicfileName = ui->lineEdit->text();
    ui->lineEdit_3->setText(PicfileName);
}

void MainWindow::MyGetColor()
{
    if(sColor == "black")
    {
      Mypainter.setPen(QColor(0, 0, 0, iTransparency));
    }
    else if(sColor == "red")
    {
      Mypainter.setPen(QColor(255, 0, 0, iTransparency));
    }
    else if (sColor == "yellow") {
      Mypainter.setPen(QColor(255, 255, 0, iTransparency));
    }
    else if (sColor == "blue") {
      Mypainter.setPen(QColor(0, 0, 255, iTransparency));
    }
    else if (sColor == "grey") {
      Mypainter.setPen(QColor(128, 128, 128, iTransparency));//默认灰色
    }
    else
    {
        ui->lineEdit_3->setText("error");
        Mypainter.setPen(QColor(128, 128, 128, iTransparency));//意外 则默认灰色
    }

}

void MainWindow::MyGetFont()
{
    if(sFont == "微软雅黑")
    {
       sFont = "微软雅黑";
    }
    else if(sColor == "楷体")
    {
        sFont = "楷体";
    }
    else if (sColor == "仿宋") {
        sFont = "仿宋";
    }
    else if (sColor == "Roman") {
        sFont = "Roman";
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

}

//水印文字 颜色选择
void MainWindow::on_comboBox_activated(const QString &arg1)
{
    ui->lineEdit_3->setText(arg1);
    sColor = arg1;
}

//水印字体选择
void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    ui->lineEdit_3->setText(arg1);
    sFont = arg1;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    iTransparency = value;
    ui->lineEdit_3->setText(QString("%1").arg(value));
}
