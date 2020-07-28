#include "SurfExtractor.hpp"

SurfExtractor::SurfExtractor() {
    cout << "Ok" << endl;
}

void SurfExtractor::readImage() {
    audifonos = imread("audifonos.png");
    iphone = imread("iphone.png");
    tarjeta = imread("tarjeta.png");

}

void SurfExtractor::convertColorToGrayScale() {
    audifonos = imread("audifonos.png");
    iphone = imread("iphone.png");
    tarjeta = imread("tarjeta.png");
    cvtColor(audifonos, audifonosGris, COLOR_BGR2GRAY);
    cvtColor(iphone, iphoneGris, COLOR_BGR2GRAY);
    cvtColor(tarjeta, tarjetaGris, COLOR_BGR2GRAY);
}

void SurfExtractor::detectAndCompute(Mat grisVideo, Mat grisObjeto) {
    surf->detect(grisObjeto, points1);
    surf->detect(grisVideo, points2);

    surf->compute(grisVideo, points1, descriptors1);
    surf->compute(grisObjeto, points2, descriptors2);
}

void SurfExtractor::makeMatches() {
    matcher.knnMatch(descriptors1, descriptors2, matches, 2);
    float ratio = 0.8f;
    for (int i = 0; i < matches.size(); ++i) {
        if (matches[i][0].distance < ratio * matches[i][1].distance) {
            okMatches.push_back(matches[i][0]);
        }
    }
}

void SurfExtractor::paintMatches(Mat video, Mat objeto) {
//    drawMatches(objeto, points1, video, points2, okMatches, img_matches);
    drawKeypoints(objeto, points1, objeto);
    drawKeypoints(video, points2, video);
    namedWindow("resultado", WINDOW_AUTOSIZE);
//    imshow("resultado", img_matches);
}


