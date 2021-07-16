#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
using namespace std;
typedef int larik[9];

void sort(larik a, int n)
{
int i,j;
for(i=1;i<n;i++) //bubble sort
   for(j=0;j<n-1;j++)
   if(a[j] > a[j+1])
         swap(a[j], a[j+1]);
}
void swap(int &a, int &b)
{
	int tmp;
   	tmp = a; a = b; b = tmp;
}

int median(larik x, int n){
	int h,k,med;
	h=n%2;
	if(h==1){
		k=(n-1)/2; //jumlah data ganjil
		med=x[k];
	}
	else {
		k=n/2; //jumlah data genap
		med=(x[k-1]+x[k])/2;
	}
	return med;
}

int main(){
	larik data;

	Mat dummy = imread("C:/myRepo/pengolahan-citra-digital/matlab/lenanoise.jpg", CV_LOAD_IMAGE_UNCHANGED); 

	Mat img;

	// force convert RGB image to grey
	cvtColor(dummy,  img, CV_BGR2GRAY);

	Mat img1;
	blur(img, img1, Size(3, 3));

    namedWindow("Original Image", WINDOW_NORMAL);
	resizeWindow("Original Image", 300, 300);
	namedWindow("image smoothing", WINDOW_NORMAL);
	resizeWindow("image smoothing", 300, 300);
	imshow("Original Image", img); imshow("image smoothing", img1);
	waitKey(0);
    return 0;
}


