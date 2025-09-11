#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar la señal textChanged del QLineEdit con el slot onTextChanged
    connect(ui->campo, &QLineEdit::textChanged,
            this, &MainWindow::onTextChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot que actualiza el texto del QLabel
void MainWindow::onTextChanged(const QString &text)
{
    ui->labelNombre->setText("Hola " + text);
}
