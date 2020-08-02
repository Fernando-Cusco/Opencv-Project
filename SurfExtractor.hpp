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
    int estado =  0;
    Mat iphone;
    Mat cara;
    Mat tarjeta;


    Mat iphoneGris;
    Mat caraGris;
    Mat tarjetaGris;

    Mat imagenBase;
    Mat captura;

    Ptr<Feature2D> surf = xfeatures2d::SURF::create();
    vector<KeyPoint> pointsVideo;  //para el video
    vector<KeyPoint> pointsTarjeta;
    vector<KeyPoint> pointsCara;
    vector<KeyPoint> pointsIphone;

    Mat descriptorsVideo;           //para el video

    Mat descriptorsTarjeta;
    Mat descriptorsCara;
    Mat descriptorsIphone;

    BFMatcher matcherTarjeta;
    BFMatcher matcherCara;
    BFMatcher matcherIphone;

    Mat img_matches;
    vector<vector<DMatch>> matchesTarjeta;
    vector<vector<DMatch>> matchesCara;
    vector<vector<DMatch>> matchesIphone;

    vector<DMatch> okMatchesTarjeta;
    vector<DMatch> okMatchesCara;
    vector<DMatch> okMatchesIphone;



    SurfExtractor();
    void readImage();
    void convertColorToGrayScale();
    void detectAndCompute(Mat);
    void makeMatches(Mat);
    void paintMatches(Mat);
    void clearVectors();



};