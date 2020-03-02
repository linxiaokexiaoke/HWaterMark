#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QPoint>
#include <QComboBox>
#include <QSlider>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

signals:


public slots:
    void openfileSlot();
    void loadSlot();

public:
    QGridLayout *layout;
    QLabel *imageLable;
    QLabel *Text1;
    QLabel *Text2;
    QLabel *Text3;
    QLabel *Text4;
    QLabel *Text5;
    QLabel *Text6;
    QLabel *Text7;

    QLineEdit *pathText;
    QLineEdit *waterText;

    QComboBox *colorBox;
    QComboBox *fontBox;
    QComboBox *sizeBox;

    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;

    QSlider *mSlider;

public:
    QString PicfileName;
    bool bFlag = false;
    QImage *image;
};

#endif // WIDGET_H
