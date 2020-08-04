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
#include <opencv2/calib3d/calib3d.hpp>
#include <math.h>

using namespace std;
using namespace cv;


class SurfExtractor {

public:
    int estado =  0;
    Mat disco;
    Mat logo;
    Mat tarjeta;


    Mat iphoneGris;
    Mat libroGris;
    Mat tarjetaGris;

    Mat imagenBase;
    Mat captura;

    Ptr<Feature2D> surf = xfeatures2d::SURF::create();
    Ptr<FeatureDetector> detector =  xfeatures2d::SurfFeatureDetector::create();
    Ptr<DescriptorExtractor> extractor = xfeatures2d::SurfDescriptorExtractor::create();
    vector<KeyPoint> pointsVideo;  //para el video
    vector<KeyPoint> pointsTarjeta;
    vector<KeyPoint> pointsLogo;
    vector<KeyPoint> pointsDisco;

    Mat descriptorsVideo;           //para el video
    Mat descriptorsTarjeta;
    Mat descriptorsLogo;
    Mat descriptorsDisco;

    BFMatcher matcherTarjeta;
    BFMatcher matcherLibro;
    BFMatcher matcherIphone;
    BFMatcher mct;

    Mat img_matches;
    vector<vector<DMatch>> matchesTarjeta;
    vector<vector<DMatch>> matchesLogo;
    vector<vector<DMatch>> matchesDisco;

    vector<DMatch> okMatchesTarjeta;
    vector<DMatch> okMatchesLogo;
    vector<DMatch> okMatchesDisco;



    SurfExtractor();
    void readImage();
    void convertColorToGrayScale();
    void detectAndCompute();
    void makeMatches(Mat);
    void paintMatches();
    void clearVectors();



};