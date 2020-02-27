/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *horizontalSlider;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(617, 509);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 30, 201, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 71, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 30, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 340, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 411, 311));
        label_2->setMaximumSize(QSize(411, 311));
        label_2->setAutoFillBackground(true);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(true);
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(440, 30, 91, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(440, 90, 91, 22));
        comboBox_3 = new QComboBox(centralWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(440, 150, 91, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(440, 10, 101, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 70, 141, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(440, 130, 171, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(440, 190, 171, 16));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setEnabled(true);
        horizontalSlider->setGeometry(QRect(440, 210, 160, 22));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setValue(155);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(440, 250, 161, 16));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(440, 270, 141, 20));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(530, 340, 75, 23));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(30, 420, 371, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 617, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\351\242\204\345\212\240\350\275\275\345\233\276\347\211\207\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\345\233\276\347\211\207", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\346\230\276\347\244\272\345\214\272", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "grey", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "black", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "red", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "yellow", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "blue", nullptr));

        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "\345\276\256\350\275\257\351\233\205\351\273\221", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "\346\245\267\344\275\223", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow", "\344\273\277\345\256\213", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("MainWindow", "Roman", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "\346\260\264\345\215\260\351\242\234\350\211\262\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\260\264\345\215\260\345\255\227\344\275\223\357\274\232\351\273\230\350\256\244 \345\276\256\350\275\257\351\233\205\351\273\221", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\260\264\345\215\260\346\226\207\345\255\227\345\244\247\345\260\217\357\274\232\351\273\230\350\256\244 16\345\217\267\345\255\227\344\275\223", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\260\264\345\215\260\351\200\217\346\230\216\345\272\246\357\274\23255-255 \351\273\230\350\256\244155", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\260\264\345\215\260\346\226\207\346\234\254\357\274\232\346\234\200\345\244\232xx\345\255\227\347\254\246", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\260\264\345\215\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
