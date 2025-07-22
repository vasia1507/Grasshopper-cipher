#include "mainwindow.h"
#include "grasshopper_cipher.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  QString fileName = QFileDialog::getSaveFileName();
  ui->lineEdit_2->setText(fileName);
}

void MainWindow::on_pushButton_2_clicked() {
  std::string file = ui->lineEdit_2->text().toUtf8().data();
  std::string main_key = ui->lineEdit->text().toStdString();
  if (validate(main_key) != 0) {
    QMessageBox::critical(this, "Error", "Bad key");
  } else {
    Encript_File(file, main_key);
  }
}

void MainWindow::on_pushButton_3_clicked() {
  std::string main_key = ui->lineEdit->text().toStdString();
  std::string file = ui->lineEdit_2->text().toStdString();
  if (validate(main_key) != 0) {
    QMessageBox::critical(this, "Error", "Bad key");
  } else {
    Decript_File(file, main_key);
  }
}
