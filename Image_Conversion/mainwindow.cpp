#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Image Convert");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.webp *.bmp)");

    ui->filePathLineEdit->setText(fileName);
}

void MainWindow::on_convertButton_clicked()
{
    QString fileName = ui->filePathLineEdit->text();

    if (fileName != "")
    {
        QFileInfo fileInfo    = QFile(fileName);
        QString   newFileName = fileInfo.path() + "/" + fileInfo.completeBaseName();
        QImage    image       = QImage(ui->filePathLineEdit->text());

        if (!image.isNull())
        {
            // 0 - PNG
            // 1 - JPG
            // 2 - BMP
            // 3 - webp
            int format = ui->fileFormatComboBox->currentIndex();
            if (format == 0)
                newFileName += ".png";
            else if (format == 1)
                newFileName += ".jpg";
            else if (format == 2)
                newFileName += ".bmp";
            else if (format == 3)
                newFileName += ".webp";

            qDebug() << newFileName << format;

            /**
             * @param newFileName: fileName
             * @param 0:    Figure out the format by checking at fileName's suffix
             * @param -1:   Saves the image at the highest quality
             */
            if (image.save(newFileName, 0, -1))
                QMessageBox::information(this, "Success", "Image successfully converted.");
            else
                QMessageBox::warning(this, "Failed", "Failed to convert image.");
        }
        else
            QMessageBox::warning(this, "Failed", "Failed to open image file.");
    }
    else
        QMessageBox::warning(this, "Failed", "No file is selected.");
}
