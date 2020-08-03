#include "SurfExtractor.hpp"

SurfExtractor::SurfExtractor() {
    cout << "Ok" << endl;
}

void SurfExtractor::readImage() {


}

void SurfExtractor::convertColorToGrayScale() {

//    medianBlur(tarjeta, tarjeta, 13);
//    medianBlur(libro, libro, 13);
//    medianBlur(iphone, iphone, 13);

//    dilate(iphone, iphone, 3);
//    dilate(libro, libro, 3);
//    dilate(tarjeta, tarjeta, 3);
//    erode(iphone, iphone, 0);
//    erode(libro, libro, 0);
//    erode(tarjeta, tarjeta, 0);


}

void SurfExtractor::detectAndCompute() {
//    medianBlur(grisVideo, grisVideo, 13);

//    dilate(grisVideo, grisVideo, 3);
//    erode(grisVideo, grisVideo, 0);
//    medianBlur(grisVideo, grisVideo, 17);

}

void SurfExtractor::makeMatches(Mat frame) {
    libro = imread("logo.png", IMREAD_GRAYSCALE);
    iphone = imread("disco.png", IMREAD_GRAYSCALE);
    tarjeta = imread("tarjeta.png", IMREAD_GRAYSCALE);
    GaussianBlur(tarjeta, tarjeta, Size(3, 3), 7);
    GaussianBlur(libro, libro, Size(3, 3), 7);
    GaussianBlur(iphone, iphone, Size(3, 3), 7);

    detector->detect(tarjeta, pointsTarjeta);
    detector->detect(libro, pointsLibro);
    detector->detect(iphone, pointsIphone);

    extractor->compute(tarjeta, pointsTarjeta, descriptorsTarjeta);
    extractor->compute(libro, pointsLibro, descriptorsLibro);
    extractor->compute(iphone, pointsIphone, descriptorsIphone);
    GaussianBlur(frame, frame, Size(3, 3), 7);
    detector->detect(frame, pointsVideo);//para el video
    extractor->compute(frame, pointsVideo, descriptorsVideo);

    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
    matcher->knnMatch(descriptorsTarjeta, descriptorsVideo, matchesTarjeta, 2);
    matcher->knnMatch(descriptorsLibro, descriptorsVideo, matchesLibro, 2);
    matcher->knnMatch(descriptorsIphone, descriptorsVideo, matchesIphone, 2);

    float ratio = 0.8f;

    for (int i = 0; i < matchesTarjeta.size(); i++) {
        if (matchesTarjeta[i][0].distance < ratio * matchesTarjeta[i][1].distance)
            okMatchesTarjeta.push_back(matchesTarjeta[i][0]);
    }

    for (int i = 0; i < matchesLibro.size(); i++) {
        if (matchesLibro[i][0].distance < ratio * matchesLibro[i][1].distance)
            okMatchesLibro.push_back(matchesLibro[i][0]);
    }

    for (int i = 0; i < matchesIphone.size(); i++) {
        if (matchesIphone[i][0].distance < ratio * matchesIphone[i][1].distance)
            okMatchesIphone.push_back(matchesIphone[i][0]);
    }

    cout << "Matches: Tarjeta: " << okMatchesTarjeta.size() << " - Logo: " << okMatchesLibro.size() << " - Disco Duro: " << okMatchesIphone.size() << endl;
//    if (okMatchesTarjeta.size() >= 100) {
//        putText(frame, "Tarjeta", Point(100, 100), FONT_HERSHEY_DUPLEX, 1,
//                Scalar(255, 255, 255), 2);
//    }
//    if (okMatchesLibro.size() >= 140) {
//        putText(frame, "Logo", Point(100, 100), FONT_HERSHEY_DUPLEX, 1,
//                Scalar(255, 255, 255), 2);
//    }
//    if (okMatchesIphone.size() >= 600) {
//        putText(frame, "Disco Duro", Point(100, 100), FONT_HERSHEY_DUPLEX, 1,
//                Scalar(255, 255, 255), 2);
//    }

}

void SurfExtractor::paintMatches() {
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
    okMatchesLibro.clear();
    okMatchesTarjeta.clear();

}


