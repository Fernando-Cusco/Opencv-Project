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

void SurfExtractor::detectAndCompute(Mat grisVideo) {
    surf->detect(tarjetaGris, pointsTarjeta);
    surf->detect(audifonosGris, pointsAudifonos);
    surf->detect(iphoneGris, pointsIphone);

    surf->detect(grisVideo, pointsVideo);//para el video

    surf->compute(grisVideo, pointsVideo, descriptorsVideo);
    surf->compute(tarjetaGris, pointsTarjeta, descriptorsTarjeta);
    surf->compute(audifonosGris, pointsAudifonos, descriptorsAudifonos);
    surf->compute(iphoneGris, pointsIphone, descriptorsIphone);

}

void SurfExtractor::makeMatches() {
    matcherTarjeta.knnMatch(descriptorsTarjeta, descriptorsVideo, matchesTarjeta, 2);
    matcherAudifonos.knnMatch(descriptorsAudifonos, descriptorsVideo, matchesAudifonos, 2);
    matcherIphone.knnMatch(descriptorsIphone, descriptorsVideo, matchesIphone, 2);
    float ratio = 0.8f;
    for (int i = 0; i < matchesTarjeta.size(); ++i) {
        if (matchesTarjeta[i][0].distance < ratio * matchesTarjeta[i][1].distance) {
            okMatchesTarjeta.push_back(matchesTarjeta[i][0]);
        }
    }
    for (int i = 0; i < matchesAudifonos.size(); ++i) {
        if (matchesAudifonos[i][0].distance < ratio * matchesAudifonos[i][1].distance) {
            okMatchesAudifonos.push_back(matchesAudifonos[i][0]);
        }
    }
    for (int i = 0; i < matchesIphone.size(); ++i) {
        if (matchesIphone[i][0].distance < ratio * matchesIphone[i][1].distance) {
            okMatchesIphone.push_back(matchesIphone[i][0]);
        }
    }

    cout << "Matches: " << okMatchesTarjeta.size() << " - " << okMatchesAudifonos.size() << " - " << okMatchesIphone.size() << endl;

}

void SurfExtractor::paintMatches(Mat video, Mat objeto) {
//    drawMatches(objeto, points1, video, points2, okMatches, img_matches);
//    drawKeypoints(objeto, points1, objeto);
//    drawKeypoints(video, points2, video);
//    namedWindow("resultado", WINDOW_AUTOSIZE);
//    imshow("resultado", img_matches);
}


