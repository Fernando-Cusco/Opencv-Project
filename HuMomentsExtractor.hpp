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
    vector<double> huMomentsPurple;
    vector<double> huMomentsRed;
    vector<double> huMomentsGreen;

    // Hu Moments previously extracted for morado, rojo, and verde colors:
    double basehumoments[3][7] = {{0.231956,0.025414,0.000159526,1.39677e-05,-6.55154e-10,-2.21141e-06,7.40665e-11},
                                  {0.245572,0.0192027,0.00244654,0.000109615,-3.13255e-08,-9.91094e-06,4.73388e-08},
                                  {0.231082,0.0157393,5.06301e-05,1.18537e-05,2.09701e-10,9.66472e-07,-2.00879e-10}};

    // Red: hsv-min (0,53,162)    hsv-max (12,192,244)
    // Blue: hsv-min (83,125,183)   hsv-max (137,186,232)
    // Green: hsv-min (36,85,134) hsv-max (53,196,201)


    //0.231082,0.0157393,5.06301e-05,1.18537e-05,2.09701e-10,9.66472e-07,-2.00879e-10



    static void huFunc(int,void*);


    void printLAB();


    int euclideanDistance(vector<double>,int);

    void refreshImg();

    Mat applyClahe(Mat);

public:
    HuMomentsExtractor(string = "fichero.txt");

    vector<double> extractHuMoments(Mat);
    vector<double> extractHuMoments(Mat,int,int,int,int,int,int);
    void capture();
    void setOperationMode(int);
};
