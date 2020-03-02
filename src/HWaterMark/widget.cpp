#include "widget.h"

#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);

    imageLable = new QLabel("image", this);

    Text1 = new QLabel("加载图片:",this);
    Text2 = new QLabel("颜色:",this);
    Text3 = new QLabel("font:",this);
    Text4 = new QLabel("size:",this);
    Text5 = new QLabel(QString("透明度:"),this);
    Text6 = new QLabel("输入文字:",this);
    Text7 = new QLabel("提示",this);

    pathText = new QLineEdit(this);
    //灰色的默认提示
    pathText->setPlaceholderText(" 上传您需要水印的图片");

    waterText = new QLineEdit("water",this);

    colorBox = new QComboBox(this);
    fontBox = new QComboBox(this);
    sizeBox = new QComboBox(this);

    mSlider = new QSlider(this);
    mSlider->setOrientation(Qt::Horizontal);  // 水平方向
    mSlider->setMinimum(120);  // 最小值
    mSlider->setMaximum(200);  // 最大值
    mSlider->setSingleStep(5);  // 步长
    mSlider->setTickPosition(QSlider::TicksAbove);

    Button1 = new QPushButton("open",this);
    Button2 = new QPushButton("start",this);
    Button3 = new QPushButton("加载",this);

    layout->addWidget(Text1,0,0,1,1);//添加布局
    layout->addWidget(pathText,0,1,1,1);
    layout->addWidget(Button1,0,2,1,1);
     layout->addWidget(Text2,0,3,1,1);

     layout->addWidget(Text7,1,0,1,1);

     layout->addWidget(imageLable,2,0,10,3);

     layout->addWidget(Text1,0,0,1,1);//添加布局
     layout->addWidget(pathText,0,1);
     layout->addWidget(Button1,0,2,1,1);
     layout->addWidget(Text2,0,3,1,1);

     layout->addWidget(colorBox,1,3,1,1);

     layout->addWidget(Text3,2,3,1,1);

     layout->addWidget(fontBox,3,3,1,1);

     layout->addWidget(Text4,4,3,1,1);

     layout->addWidget(sizeBox,5,3,1,1);

     layout->addWidget(Text5,6,3,1,1);

     layout->addWidget(mSlider,7,3,1,1);

     layout->addWidget(Text6,8,3,1,1);

     layout->addWidget(waterText,9,3,1,1);


     layout->addWidget(Button2,10,3,1,1);
     layout->addWidget(Button3,11,3,1,1);

     connect(Button1,SIGNAL(pressed()),this,SLOT(openfileSlot()));

     connect(Button3,SIGNAL(pressed()),this,SLOT(loadSlot()));

     connect(Button2,SIGNAL(pressed()),this,SLOT());

}

void Widget::openfileSlot()
{
    PicfileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Image Files (*.png *.jpg *.bmp *.gif)"));
    image = new QImage(PicfileName);

    if("" == PicfileName)
    {
        bFlag = false;
        Text7->setText("未成功上传图片文件名为空");
        pathText->setText("");
        PicfileName = "";
    }
    else
    {
        bFlag = true;
        Text7->setText("成功上传图片!");
        pathText->setText(PicfileName);
    }
}

void Widget::loadSlot()
{
    imageLable->setPixmap(QPixmap::fromImage(*image));
    imageLable->resize(image->size());//重置size
}

Widget::~Widget()
{

}
