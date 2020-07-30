#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>

#include <dirent.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <math.h>

using namespace std;
using namespace cv;


class SurfExtractor {

public:
    Mat iphone;
    Mat audifonos;
    Mat tarjeta;


    Mat iphoneGris;
    Mat audifonosGris;
    Mat tarjetaGris;

    Mat imagenBase;
    Mat captura;

    Ptr<Feature2D> surf = xfeatures2d::SURF::create();
    vector<KeyPoint> pointsVideo;  //para el video
    vector<KeyPoint> pointsTarjeta;
    vector<KeyPoint> pointsAudifonos;
    vector<KeyPoint> pointsIphone;

    Mat descriptorsVideo;           //para el video

    Mat descriptorsTarjeta;
    Mat descriptorsAudifonos;
    Mat descriptorsIphone;

    BFMatcher matcherTarjeta;
    BFMatcher matcherAudifonos;
    BFMatcher matcherIphone;

    Mat img_matches;
    vector<vector<DMatch>> matchesTarjeta;
    vector<vector<DMatch>> matchesAudifonos;
    vector<vector<DMatch>> matchesIphone;

    vector<DMatch> okMatchesTarjeta;
    vector<DMatch> okMatchesAudifonos;
    vector<DMatch> okMatchesIphone;



    SurfExtractor();
    void readImage();
    void convertColorToGrayScale();
    void detectAndCompute(Mat);
    void makeMatches();
    void paintMatches(Mat, Mat);


};