

all:
	g++ main.cpp HuMomentsExtractor.cpp SurfExtractor.cpp -I/usr/local/include/opencv4/ -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_video -lopencv_videoio -lopencv_features2d -lopencv_xfeatures2d -std=c++11 -o main.bin


run:
	./main.bin
	
#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/vlarobbyk/aplicaciones/Librerias/opencv-4.0.0/opencv4-installation/lib/
#export LD_LIBRARY_PATH
