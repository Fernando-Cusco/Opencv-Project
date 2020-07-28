#include "HuMomentsExtractor.hpp"
#include "SurfExtractor.hpp"
void changeMode(int v, void *p) {
    cout << v << endl;
}
HuMomentsExtractor::HuMomentsExtractor(string outDir) {
    this->outDir = outDir;
    this->operationMode = 1;
    this->aMax = 255;
    this->lMax = 255;
    this->bMax = 255;
    this->aMin = 255;
    this->bMin = 255;
    this->lMin = 255;


}

Mat HuMomentsExtractor::applyClahe(Mat imgLab) {
    Mat imageClahe;
    Mat dst;
    cvtColor(imgLab, imageClahe, COLOR_BGR2Lab);
    vector<Mat> canales(3);
    split(imageClahe, canales);
    Ptr<CLAHE> clahe = createCLAHE();
    clahe->setClipLimit(7);
    clahe->apply(canales[0], dst);
    dst.copyTo(canales[0]);
    merge(canales, imageClahe);
//    cvtColor(imageLab, imageClahe, COLOR_Lab2BGR);
//    imshow("video-clahe", imageClahe);
    return imageClahe;
}

vector<double> HuMomentsExtractor::extractHuMoments(Mat imageO) {


    Moments _moments;
    double huMoments[7];
    vector<double> huMomentsV;
    Mat clahe = applyClahe(imageO);
    inRange(clahe, Scalar(lMin, aMin, bMin), Scalar(lMax, aMax, bMax), imageThreshold);
    _moments = moments(imageThreshold, true);
    HuMoments(_moments, huMoments);

    for (int i = 0; i < 7; i++) {
        huMomentsV.push_back(0);
        huMomentsV[i] = huMoments[i];
        cout << huMoments[i] << ",";
    }
    cout << endl;

    return huMomentsV;
}

vector<double>
HuMomentsExtractor::extractHuMoments(Mat imageO, int lmin, int amin, int bmin, int lmax, int amax, int bmax) {


    Moments _moments;
    double huMoments[7];
    vector<double> huMomentsV;
    Mat clahe = applyClahe(imageO);
    inRange(clahe, Scalar(lmin, amin, bmin), Scalar(lmax, amax, bmax), imageThreshold);
    _moments = moments(imageThreshold, true);

    HuMoments(_moments, huMoments);

    for (int i = 0; i < 7; i++) {
        huMomentsV.push_back(0);
        huMomentsV[i] = huMoments[i];
        cout << huMoments[i] << "@";
    }
    huMomentsV.push_back(_moments.m10 / _moments.m00);
    huMomentsV.push_back(_moments.m01 / _moments.m00);
    cout << endl;

    return huMomentsV;
}

void HuMomentsExtractor::huFunc(int v, void *p) {
    HuMomentsExtractor *hu = reinterpret_cast<HuMomentsExtractor *> (p);
    hu->refreshImg();
}

void HuMomentsExtractor::refreshImg() {
    imshow("threshold", imageThreshold);
    printLAB();
}

void HuMomentsExtractor::printLAB() {
    cout << "lab-min (" << lMin << "," << aMin << "," << bMin << ")" << "lab-max (" << lMax << "," << aMax << ","
         << bMax << ")" <<
         endl;
}

int HuMomentsExtractor::euclideanDistance(vector<double> moms, int i) {
    double d = 0.0;
    int index = -1;

    double thresholdm = 0.3;

    for (int j = 0; j < 7; j++) {
        //cout << "m: " << moms[j] << " humoments: " << basehumoments[i][j] << ",";
        d += ((moms[j] - basehumoments[i][j]) * (moms[j] - basehumoments[i][j]));
    }
    cout << endl;
    d = sqrt(d);
    //cout << "Distance: " << " i: " << i << " :: " << d << endl;

    if (i == 2)
        thresholdm = 0.41;

    if (d < thresholdm)
        return i;

    return -1;
}

void HuMomentsExtractor::setOperationMode(int m) {
    this->operationMode = m;
}

void HuMomentsExtractor::capture() {
    VideoCapture video(0);
    if (video.isOpened()) {

        Mat frame;

        namedWindow("video", WINDOW_AUTOSIZE);
        namedWindow("lab", WINDOW_AUTOSIZE);
        namedWindow("threshold", WINDOW_AUTOSIZE);
        namedWindow("video-clahe", WINDOW_AUTOSIZE);


        createTrackbar("Lmin", "video", &lMin, 255, HuMomentsExtractor::huFunc, static_cast<void *>(this));
        createTrackbar("Amin", "video", &aMin, 255, HuMomentsExtractor::huFunc, static_cast<void *>(this));
        createTrackbar("Bmin", "video", &bMin, 255, HuMomentsExtractor::huFunc, static_cast<void *>(this));

        createTrackbar("Lmax", "video", &lMax, 255, HuMomentsExtractor::huFunc, static_cast<void *>(this));
        createTrackbar("Amax", "video", &aMax, 255, HuMomentsExtractor::huFunc, static_cast<void *>(this));
        createTrackbar("Bmax", "video", &bMax, 255, HuMomentsExtractor::huFunc, static_cast<void *>(this));
        createTrackbar("modo", "video", &this->operationMode, 3, changeMode);
        vector<double> huMoments;


        int indexVerde = -1;
        int indexAmarillo = -1;
        int indexTomate = -1;
        SurfExtractor *surf = new SurfExtractor();
        while (true) {
            video >> frame;
//            flip(frame, frame, 1);
            resize(frame, frame, Size(640, 480));

            if (this->operationMode == 1) { // In this mode you can use the trackbars to determine the LAB segmentation range
                huMoments = this->extractHuMoments(frame);
            } if (this->operationMode == 2) { // In this mode you can use test the values selected to perform the segmentation and Hu Moments extraction
                huMoments = this->extractHuMoments(frame, 0, 0, 0, 255, 106, 255);
                indexVerde = this->euclideanDistance(huMoments, 2);
                if (indexVerde != -1) {
                    cout << "JoyStick: " << indexVerde << endl;
                    putText(frame, "JoyStick", Point(huMoments[7], huMoments[8]), FONT_HERSHEY_DUPLEX, 1,
                            Scalar(0, 10, 143), 2);
                } else {
                    huMoments = this->extractHuMoments(frame, 0, 165, 0, 255, 255, 255);
                    indexAmarillo = this->euclideanDistance(huMoments, 1);
                    if (indexAmarillo != -1) {
                        cout << "Rojo: " << indexAmarillo << endl;
                        putText(frame, "Rojo", Point(huMoments[7], huMoments[8]),
                                FONT_HERSHEY_DUPLEX, 1, Scalar(143, 10, 0), 2);
                    } else {
                        //0-255-136-255-158-255
                        huMoments = this->extractHuMoments(frame, 0, 146, 0, 255, 255, 88);
                        indexTomate = this->euclideanDistance(huMoments, 0);
                        if (indexTomate != -1) {
                            cout << "Morado: " << indexTomate << endl;
                            putText(frame, "Morado: ", Point(huMoments[7], huMoments[8]),
                                    FONT_HERSHEY_DUPLEX, 1, Scalar(10, 143, 3), 2);
                        }
                    }
                }
            }
            if(this->operationMode == 3) {
                cout << "Modo 3" << endl;


                surf->convertColorToGrayScale();
                cvtColor(frame, surf->captura, COLOR_BGR2GRAY);
                surf->detectAndCompute(surf->captura, surf->iphoneGris);
                surf->detectAndCompute(surf->captura, surf->audifonosGris);
                surf->detectAndCompute(surf->captura, surf->tarjetaGris);
                surf->makeMatches();
                surf->paintMatches(frame, surf->tarjeta);


            }
            imshow("video", frame);

            imshow("threshold", imageThreshold);

            if (waitKey(23) == 27)
                break;
        }
    }

    destroyAllWindows();
}