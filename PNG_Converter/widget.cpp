#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("PNG Converter");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_inputBtn_clicked()
{
    inputFilePath = QFileDialog::getExistingDirectory(this);

    // 如果文件名不为空
    if (!inputFilePath.isEmpty())
    {
        ui->inputlineEdit->setText(inputFilePath);
    }
    ui->progressBar->setValue(0);
}

void Widget::on_outputBtn_clicked()
{
    outputFilePath = QFileDialog::getExistingDirectory(this);

    // 如果文件名不为空
    if (!outputFilePath.isEmpty())
    {
        ui->outputlineEdit->setText(outputFilePath);
    }
}

void Widget::on_startBtn_clicked()
{
    QImage img;
    QDir   dir(inputFilePath);

    if (!dir.exists())
        return;

    QStringList filters;
    filters << "*.png";                            // 文件格式，可以多种格式或者单个格式
    dir.setFilter(QDir::Files | QDir::NoSymLinks); // 设置类型过滤器，只为文件格式
    dir.setNameFilters(filters);                   // 设置文件名称过滤器

    int count = dir.count();
    if (count <= 0)
        return;

    if (count <= 1)
    {
        ui->progressBar->setRange(0, 1);
        img.load(inputFilePath + "/" + dir[0]);
        img.save(outputFilePath + "/" + dir[0]);
        ui->progressBar->setValue(1);
    }
    else
    {
        ui->progressBar->setRange(0, count - 1);

        for (int i = 0; i < count; i++)
        {
            img.load(inputFilePath + "/" + dir[i]);
            img.save(outputFilePath + "/" + dir[i]);
            ui->progressBar->setValue(i);
        }
    }
}
