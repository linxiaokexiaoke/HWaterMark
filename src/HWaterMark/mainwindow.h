#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QMetaEnum>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_pushButton_2_clicked();

    void on_lineEdit_2_editingFinished();

    void on_pushButton_3_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

public:
    QString PicfileName;
    QString WaterName;
    QPixmap Picpixmap;
    /* 保存路径*/
    QString runPath;
    QString hglpName;
    QString hglpPath;
    bool bFlag = false;
    QPainter Mypainter;
    QString sColor;//保存 颜色
    QString sFont;//保存 字体类型
    int iTransparency = 155;//透明度 0-255


public:
    void MyMark(QPixmap & pm,const QString& text);
    void MyGetColor();
    void MyGetFont();
};

#endif // MAINWINDOW_H
