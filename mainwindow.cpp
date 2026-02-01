#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
        this,SLOT(button()));
    connect(ui->pushButton_2, SIGNAL(clicked()),
            this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button()
{
    QString name[] = {"Andre", "Aaron", "Andrew"};
    QString passwords[] = {"Test1234", "TestABCD", "Test1A2B"};

    QString userName = ui->lineEdit->text();
    QString userPassword = ui->lineEdit_2->text();


    bool found = false;

    for (int i = 0; i < name->length(); ++i) {
        if(userName == name[i] && userPassword == passwords[i]) {
            QMessageBox::information(this, "Welcome Message",
            "Hi, "+ name[i]+ "!\n"
            "Welcome to the Login Management System.");
            found = true;
            break;
        }
    }
     if (!found){
        QMessageBox::information(this, "Error Message",
        "Invalid username or password. Sorry, please try again.");
    }
}

