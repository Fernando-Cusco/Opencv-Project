#include <iostream>
#include <cstdlib>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>
#include "HuMomentsExtractor.hpp"

using namespace cv;
using namespace std;




int main(int argc, char *argv[]){

    int mode = 1;
    if (argc>1){
        stringstream ss;
        ss << argv[1];
        ss >> mode;
        mode = (mode!=1 && mode!=2)?1:mode;
    }
    HuMomentsExtractor *huM = new HuMomentsExtractor();
    huM->setOperationMode(1);
    huM->capture();


    delete huM;
    return 0;
}
