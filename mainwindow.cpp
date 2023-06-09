#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QVector>
#include <QQueue>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "image.hpp"
#include "sift.hpp"
#include <string>
using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString imgPath2,imgPath;


void MainWindow::showImg(cv::Mat& img, QLabel* imgLbl, enum QImage::Format imgFormat, int width , int hieght)
{
    cvtColor(img, img, COLOR_BGR2RGB);
    QImage image((uchar*)img.data, img.cols, img.rows, imgFormat);
    QPixmap pix = QPixmap::fromImage(image);
//    imgLbl->resize(img.rows, img.cols);
    imgLbl->setPixmap(pix.scaled(width, hieght, Qt::KeepAspectRatio));
//    imgLbl->setScaledContents(true);
}



//void MainWindow::first_upload()
//{

//    imgPath = QFileDialog::getOpenFileName(this, "Open an Image", "..", "Images (*.png *.xpm *.jpg *.bmb)");

//    if(imgPath.isEmpty())
//        return;

//    cv::Mat img = imread(imgPath.toStdString());
//    showImg(img, ui->imgLbl1, QImage::Format_RGB888, ui->imgLbl1->width(), ui->imgLbl1->height());

//    Image image(imgPath.toStdString());
//    image =  image.channels == 1 ? image : rgb_to_grayscale(image);

//    std::vector<sift::Keypoint> kps = sift::find_keypoints_and_descriptors(image);
//    Image result = sift::draw_keypoints(image, kps);
//    result.save("result.jpg");
//    std::cout << "Found " << kps.size() << " keypoints. Output image is saved as result.jpg\n";
//}


//void MainWindow::second_upload()
//{




//    imgPath2 = QFileDialog::getOpenFileName(this, "Open an Image", "..", "Images (*.png *.xpm *.jpg *.bmb)");

//    if(imgPath2.isEmpty())
//        return;

//    cv::Mat img = imread(imgPath2.toStdString());
//    showImg(img, ui->imgLbl2, QImage::Format_RGB888, ui->imgLbl2->width(), ui->imgLbl2->height());

//    Image image2(imgPath2.toStdString());


//    image2 =  image2.channels == 1 ? image2 : rgb_to_grayscale(image2);

//    std::vector<sift::Keypoint> kps2 = sift::find_keypoints_and_descriptors(image2);
//    Image result = sift::draw_keypoints(image2, kps2);
//    result.save("result.jpg");
//    std::cout << "Found " << kps2.size() << " keypoints. Output image is saved as result.jpg\n";
//}


//void MainWindow::matching_function()
//{

//    Image image(imgPath.toStdString());
//    Image image2(imgPath2.toStdString());

//    image =  image.channels == 1 ? image : rgb_to_grayscale(image);
//    image2 =  image2.channels == 1 ? image2 : rgb_to_grayscale(image2);
//    std::vector<sift::Keypoint> kps = sift::find_keypoints_and_descriptors(image);
//    std::vector<sift::Keypoint> kps2 = sift::find_keypoints_and_descriptors(image2);

//    std::vector<std::pair<int, int>> match= find_keypoint_matches(kps,kps2,10000,10000.9,"SSD");
//    Image result = sift::draw_matches_rect(image, image2, kps, kps2, match);



//    result.save("result.jpg");

//}







// Swapping between the 3 pages
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}











