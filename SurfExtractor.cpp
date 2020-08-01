#include "SurfExtractor.hpp"

SurfExtractor::SurfExtractor() {
    cout << "Ok" << endl;
}

void SurfExtractor::readImage() {
    cara = imread("cara.png", IMREAD_GRAYSCALE);
    iphone = imread("iphonex.png", IMREAD_GRAYSCALE);
    tarjeta = imread("tarjeta.png", IMREAD_GRAYSCALE);
}

void SurfExtractor::convertColorToGrayScale() {

    medianBlur(tarjeta, tarjeta, 13);
    medianBlur(cara, cara, 13);
    medianBlur(iphone, iphone, 13);
    surf->detect(tarjeta, pointsTarjeta);
    surf->detect(cara, pointsCara);
    surf->detect(iphone, pointsIphone);

    surf->compute(tarjeta, pointsTarjeta, descriptorsTarjeta);
    surf->compute(cara, pointsCara, descriptorsCara);
    surf->compute(iphone, pointsIphone, descriptorsIphone);
}

void SurfExtractor::detectAndCompute(Mat grisVideo) {
    medianBlur(grisVideo, grisVideo, 13);
    surf->detect(grisVideo, pointsVideo);//para el video
    surf->compute(grisVideo, pointsVideo, descriptorsVideo);
}

void SurfExtractor::makeMatches() {
    matcherTarjeta.knnMatch(descriptorsTarjeta, descriptorsVideo, matchesTarjeta, 2);
    matcherCara.knnMatch(descriptorsCara, descriptorsVideo, matchesCara, 2);
    matcherIphone.knnMatch(descriptorsIphone, descriptorsVideo, matchesIphone, 2);

    float ratio = 0.8;

    for (int i = 0; i < min(descriptorsVideo.rows - 1, (int) matchesTarjeta.size()); ++i) {
        if ((matchesTarjeta[i][0].distance < ratio * (matchesTarjeta[i][1].distance)) and
            ((int) matchesTarjeta[i].size() <= 2 and (int) matchesTarjeta[i].size() > 0)) {
            okMatchesTarjeta.push_back(matchesTarjeta[i][0]);
        }
    }

    for (int i = 0; i < min(descriptorsVideo.rows - 1, (int) matchesCara.size()); ++i) {
        if ((matchesCara[i][0].distance < ratio * (matchesCara[i][1].distance)) and
            ((int) matchesCara[i].size() <= 2 and (int) matchesCara[i].size() > 0)) {
            okMatchesCara.push_back(matchesCara[i][0]);
        }
    }

    for (int i = 0; i < min(descriptorsVideo.rows - 1, (int) matchesIphone.size()); ++i) {
        if ((matchesIphone[i][0].distance < ratio * (matchesIphone[i][1].distance)) and
            ((int) matchesIphone[i].size() <= 2 and (int) matchesIphone[i].size() > 0)) {
            okMatchesIphone.push_back(matchesIphone[i][0]);
        }
    }

    cout << "Matches: Tarjeta: " << okMatchesTarjeta.size() << " - Cara: " << okMatchesCara.size() << " - Iphone: " << okMatchesIphone.size() << endl;

}

void SurfExtractor::paintMatches(Mat video) {
//    drawMatches(tarjeta, pointsTarjeta, video, pointsVideo, okMatchesTarjeta, img_matches);
//    drawMatches(audifonos, pointsAudifonos, video, pointsVideo, okMatchesAudifonos, img_matches);
//    drawMatches(iphone, pointsIphone, video, pointsVideo, okMatchesIphone, img_matches);
//
//    drawKeypoints(tarjeta, pointsTarjeta, tarjeta);
//    drawKeypoints(audifonos, pointsAudifonos, audifonos);
//    drawKeypoints(iphone, pointsIphone, iphone);
//    drawKeypoints(video, pointsVideo, video);
//    namedWindow("resultado", WINDOW_AUTOSIZE);
//    imshow("resultado", img_matches);
}

void SurfExtractor::clearVectors() {
    okMatchesIphone.clear();
    okMatchesCara.clear();
    okMatchesTarjeta.clear();

}


