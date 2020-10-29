#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QStringList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_inputBtn_clicked();

    void on_outputBtn_clicked();

    void on_startBtn_clicked();

private:
    Ui::Widget *ui;

    QString inputFile;
    QString inputFileName;
    QString inputFilePath;
    QString outputFilePath;
};

#endif // WIDGET_H
