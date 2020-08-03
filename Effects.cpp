#include "Effects.hpp"

void Effects::effectMirror(Mat frame) {

    int width = frame.cols/2;
    int height = frame.rows/2;
    Mat cop =  frame.clone();
    flip(frame, frame, 1);
    Mat display = Mat::zeros ( MAX ( frame.rows, cop.rows ), frame.cols + 1 + cop.cols, frame.type() );
    frame.copyTo(Mat(display, Rect(0, 0, frame.cols, frame.rows)));
    cop.copyTo(Mat(display, Rect(frame.cols + 1, 0, cop.cols, cop.rows)));
    imshow("Espejo", display);
}

void Effects::effectPaint(Mat frame) {
    Mat imageColor =frame.clone();
    int numDown=1;
    int numBilateral=5;
    for (int i=0;i < numDown;i++){
        pyrDown(imageColor,imageColor);
    }
    Mat dst;
    for (int i=0;i < numBilateral;i++){
        bilateralFilter(imageColor,dst,9,9,7);
        imageColor=dst.clone();
    }
    for(int i=0;i<numDown;i++){
        pyrUp(imageColor,imageColor);
    }

    Mat gris, medianaB,adap;
    cvtColor(imageColor, gris, COLOR_BGR2GRAY);
    medianBlur(gris, medianaB,5);

    adaptiveThreshold(medianaB, adap, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,5, 1.5);
    cvtColor(adap,adap,COLOR_GRAY2RGB);

    Mat cartoon;
    bitwise_and(imageColor,adap,cartoon);
    imshow("Cartoon",cartoon);

}

void Effects::effectOilPainting(Mat frame) {
    Mat oilPainting;
    xphoto::oilPainting(frame, oilPainting, 10, 1, COLOR_BGR2Lab);
    imshow("Oil", oilPainting);
}




