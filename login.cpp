#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>
#include <fstream>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    Par = parent;
    parent->hide();
    string s;
    ifstream fp("C:\\Users\\aryas\\OneDrive\\Documents\\firstGUI\\credentials.txt");
    getline(fp, s);
    QString qs = QString::fromStdString(s);
    QStringList lst = qs.split(" ");
    username = lst[0].toStdString();
    password = lst[1].toStdString();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    string u = ui->lineEdit->text().toStdString();
    string p = ui->lineEdit_2->text().toStdString();
    if (u == username && p == password) {
        QMessageBox::information(this, "Logged in", "Authenticated and logged in.");
        Par->show();
        close();
    } else {
        qApp->quit();
    }
}

