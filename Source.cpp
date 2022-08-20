#include <iostream>
#include <stdio.h>
#include <opencv2\highgui\highgui.hpp>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2\opencv.hpp>


using namespace std;
using namespace cv;


void detector(int a) {
	VideoCapture videox;
	videox.open(a);
	Mat frame;
	int fps = 1;
	namedWindow("gate");

	CascadeClassifier facedetect;
	facedetect.load("C:/Users/Okaman/Desktop/OpenCv4/opencv/build/etc/haarcascades/haarcascade_frontalface_default.xml");
	

	while (videox.grab()) {

		videox.read(frame); //gets into frame

		Mat detector;
		cvtColor(frame, detector,COLOR_BGR2GRAY);
		vector <Rect> faces;
		facedetect.detectMultiScale(detector, faces, 1.1, 3, 0, Size(40, 40));  // copying detector into faces

		for (int i = 0; i < faces.size(); i++) {
			rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			rectangle(frame, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
		    putText(frame, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 45, 255), 1);
		} // that is a unofied function works to analyze and cout in screen that how many faces have been detected


		imshow("gate",frame); // showing the final result
		waitKey(fps);

		if (waitKey(fps) == 27)
		{
			break; // if you write esc, it'll be closed
		}
	}
}



int main() {

	detector(0); // 0 is usually your camera path as an intiger
	
}