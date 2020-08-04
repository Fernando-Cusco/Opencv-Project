#include "SurfExtractor.hpp"

SurfExtractor::SurfExtractor() {
    cout << "Ok" << endl;
}

void SurfExtractor::readImage() {

    logo = imread("logo.png", IMREAD_GRAYSCALE);
    disco = imread("disco.png", IMREAD_GRAYSCALE);
    tarjeta = imread("tarjeta.png", IMREAD_GRAYSCALE);
    normalize(logo, logo, 0, 255, NORM_MINMAX);
    normalize(tarjeta, tarjeta, 0, 255, NORM_MINMAX);
    normalize(disco, disco, 0, 255, NORM_MINMAX);
    GaussianBlur(tarjeta, tarjeta, Size(3, 3), 7);
    GaussianBlur(logo, logo, Size(3, 3), 7);
    GaussianBlur(disco, disco, Size(3, 3), 7);

    detector->detect(tarjeta, pointsTarjeta);
    detector->detect(logo, pointsLogo);
    detector->detect(disco, pointsDisco);

    extractor->compute(tarjeta, pointsTarjeta, descriptorsTarjeta);
    extractor->compute(logo, pointsLogo, descriptorsDisco);
    extractor->compute(disco, pointsDisco, descriptorsDisco);

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

    normalize(frame, frame, 0, 255, NORM_MINMAX);
    GaussianBlur(frame, frame, Size(3, 3), 7);
    detector->detect(frame, pointsVideo);//para el video
    extractor->compute(frame, pointsVideo, descriptorsVideo);

    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
    matcher->knnMatch(descriptorsTarjeta, descriptorsVideo, matchesTarjeta, 2);
    matcher->knnMatch(descriptorsLogo, descriptorsVideo, matchesLogo, 2);
    matcher->knnMatch(descriptorsDisco, descriptorsVideo, matchesDisco, 2);

    float ratio = 0.6f;

    for (int i = 0; i < matchesTarjeta.size(); i++) {
        if (matchesTarjeta[i][0].distance < ratio * matchesTarjeta[i][1].distance)
            okMatchesTarjeta.push_back(matchesTarjeta[i][0]);
    }

    for (int i = 0; i < matchesLogo.size(); i++) {
        if (matchesLogo[i][0].distance < ratio * matchesLogo[i][1].distance)
            okMatchesLogo.push_back(matchesLogo[i][0]);
    }

    for (int i = 0; i < matchesDisco.size(); i++) {
        if (matchesDisco[i][0].distance < ratio * matchesDisco[i][1].distance)
            okMatchesDisco.push_back(matchesDisco[i][0]);
    }

    cout << "Matches: Tarjeta: " << okMatchesTarjeta.size() << " - Logo: " << okMatchesLogo.size() << " - Disco Duro: "
         << okMatchesDisco.size() << endl;
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
    okMatchesTarjeta.clear();
    okMatchesLogo.clear();
    okMatchesDisco.clear();


}


