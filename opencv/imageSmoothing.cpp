#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
using namespace std;
int main(){
	int temp;
	Mat img = imread("C:/myRepo/pengolahan-citra-digital/matlab/lenanoise.jpg", CV_LOAD_IMAGE_UNCHANGED); 

	Mat gray;

	// force convert RGB image to grey
	cvtColor(img,  gray, CV_BGR2GRAY);

	Mat img1(gray.size(), gray.type());//create new matrix img1 	
	for(int i=1;i<gray.rows-1; i++){
		for(int j=1;j<gray.cols-1; j++){
			temp=gray.at<uchar>(i-1,j-1)+gray.at<uchar>(i-1,j)+
			gray.at<uchar>(i-1,j+1)+gray.at<uchar>(i,j-1)+
			gray.at<uchar>(i,j)+gray.at<uchar>(i,j+1)+
			gray.at<uchar>(i+1,j-1)+gray.at<uchar>(i+1,j)+
			gray.at<uchar>(i+1,j+1);	   
			
			img1.at<uchar>(i,j)=temp/9;
		}
	}
    
	namedWindow("Original Image", WINDOW_NORMAL);
	resizeWindow("Original Image", 300, 300);
	namedWindow("Image Smoothing", WINDOW_NORMAL);
	resizeWindow("Image Smoothing", 300, 300);
	imshow("Original Image", img); imshow("Image Smoothing", img1);
	waitKey(0); return 0;
}
