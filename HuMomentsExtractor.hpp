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

#include <math.h>

using namespace std;
using namespace cv;

class HuMomentsExtractor{

private:
    string outDir;


    int lMin, aMin, bMin;
    int lMax, aMax, bMax;
    int operationMode;

    Mat imageThreshold;
    Mat imageLab;

    // Hu Moments previously extracted for morado, rojo, and verde colors:
    double basehumoments[3][7] = {{0.169647,0.00323353,2.32986e-06,3.10989e-08,-2.7418e-15,5.84071e-10,-7.90936e-15},
                                  {0.255447,0.0197313,0.00299272,0.000122521,-1.62939e-08,-1.25427e-05,-7.23796e-08},
                                  {0.173611,0.00236304,9.17183e-33,2.72323e-33,8.12791e-66,-7.94275e-35,-1.09163e-65}};

    // Red: hsv-min (0,53,162)    hsv-max (12,192,244)
    // Blue: hsv-min (83,125,183)   hsv-max (137,186,232)
    // Green: hsv-min (36,85,134) hsv-max (53,196,201)


    //0.231082,0.0157393,5.06301e-05,1.18537e-05,2.09701e-10,9.66472e-07,-2.00879e-10



    static void huFunc(int,void*);


    void printLAB();


    int euclideanDistance(vector<double>,int);

    void refreshImg();


public:
    HuMomentsExtractor(string = "fichero.txt");
    vector<double> extractHuMoments(Mat);
    vector<double> extractHuMoments(Mat,int,int,int,int,int,int);
    void capture();
    void setOperationMode(int);
};