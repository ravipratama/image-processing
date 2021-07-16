#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp> // digunakan untuk menggunakan fungsi kernel operasi

// fungsi konvolusi prototype
void imageSmoothing(const cv::Mat &image, cv:: Mat &result);

// proses utama
int main()
{
	// deklarasikan citra

	cv::Mat dummy = cv::imread("C:/myRepo/pengolahan-citra-digital/matlab/lenanoise.jpg", CV_LOAD_IMAGE_UNCHANGED); 

	cv::Mat image;

	// force convert RGB image to grey
	cv::cvtColor(dummy,  image, CV_BGR2GRAY);

	cv::Mat hasilSmoothing;

	// check jika data yang diproses tidak ada maka
	if (!image.data) {
		std::cout << "Error  : gambar tidak bisa di baca " << std::endl;
		system("pause");
		return -1;
	}

	// lakukan operasi konvolusi
	imageSmoothing(image, hasilSmoothing);


	// tampilkan hasil
	cv::namedWindow("citra asli");
	cv::imshow("citra asli", image);

	cv::namedWindow("konvolusi gausian filter");
	cv::imshow("konvolusi gausian filter", hasilSmoothing);


	cv::waitKey(0);
	return 0;
}


// bikin fungsinya disini
void imageSmoothing(const cv::Mat &image, cv:: Mat &result) {
	// bikin mask kernel
	cv::Mat kernel(3, 3, CV_32F, cv::Scalar(0));
	// install nilai kernel
	kernel.at<float>(0, 0) = 1/9;
	kernel.at<float>(0, 1) = 1/9;
	kernel.at<float>(0, 2) = 1/9;
	kernel.at<float>(1, 0) = 1/9;
	kernel.at<float>(1, 1) = 1/9;
	kernel.at<float>(1, 2) = 1/9;
	kernel.at<float>(2, 0) = 1/9;
	kernel.at<float>(2, 1) = 1/9;
	kernel.at<float>(2, 2) = 1/9;

	// panggil fungsi filter2D
	cv::filter2D(image, result, image.depth(), kernel);

}
