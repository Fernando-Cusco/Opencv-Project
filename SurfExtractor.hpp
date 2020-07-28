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
    vector<KeyPoint> points1;
    vector<KeyPoint> points2;

    Mat descriptors1;
    Mat descriptors2;

    BFMatcher matcher;
    Mat img_matches;
    vector<vector<DMatch>> matches;
    vector<DMatch> okMatches;



    SurfExtractor();
    void readImage();
    void convertColorToGrayScale();
    void detectAndCompute(Mat, Mat);
    void makeMatches();
    void paintMatches(Mat, Mat);


};