#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

using namespace std;

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    QWidget *Par;
    string username, password;
};

#endif // LOGIN_H
