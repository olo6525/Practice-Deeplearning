#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<Windows.h>

using namespace cv;
using namespace std;

constexpr auto array_size = 512*512;
class Neuron
{
public:
	double w_[array_size]; //weight of ine input
	double b_[array_size]; //bias
	int i = 0;
	double input_, output_; //saved for back prop


	double getAct(const double& x)
	{
		//for linear or identity activation functions

		return x;

		//for ReLU activation functions
		//return MAX2(0.0, x);

	}

	double getActGrad(const double& x)
	{
		return x;
	}

	void propBackward(const double& target, int lot)
	{
		const double alpha = 0.1;


		const double grad = (output_ - target) * getActGrad(output_);

		w_[lot] -= alpha * grad * input_;
		b_[lot] -= alpha * grad * 1.0;

	}

	double feedForward(const double& _input, int lot)
	{

		input_ = _input;
		//output y = f(\sigma)
		//\sinma = w_ * input x +b
		//for multiple inputs,
		//\sigma = w0_ * x0_ + w1_ * x1 + ... +b


		const double sigma = w_[lot] * _input + b_[lot];

		output_ = getAct(sigma);

		return output_;



	}


};


void trainning(Mat& image_model, Mat& trainning_data);

int main()
{
	
	Mat trainning_image;
	Mat model_image;
	printf("trainning start\n");
	for (int i = 0; i < 1; i++)
	{
		String trainning_name = "C:\\Users\\oh___\\OneDrive\\바탕 화면\\얼굴사진\\데이터\\d" + to_string(i) + ".jpg";
		String model_name = "C:\\Users\\oh___\\OneDrive\\바탕 화면\\얼굴사진\\데이터\\d" + to_string(i+1) + ".jpg";
		
		trainning_image = imread(trainning_name, 1);
		model_image = imread(model_name, 1);
		printf("check imread\n");
		if (model_image.empty())
		{
			printf("empty\n");
			break;
		}

		printf("check over if\n");

		trainning(model_image, trainning_image);
	}

	printf("trainning doen\n");

	

	return 0;
}


void trainning(Mat& image_model,Mat& trainning_data) {

	
	int height = trainning_data.rows;
	int width = trainning_data.cols;
	double pix_x, out_y;
	//신경망 구성 변수

	Mat trainning_gray, trainning_array, model_gray  , kernel;

	cvtColor(trainning_data, trainning_gray, COLOR_BGR2GRAY);
	cvtColor(image_model, model_gray, COLOR_BGR2GRAY);
	kernel = Mat::ones(3, 3, CV_32F) / (float)(3 * 3);
	filter2D(trainning_gray, trainning_array, trainning_gray.depth(), kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	
	printf("check filter\n");
	

	for (int i=0;i<height;i++)
	{
		uchar* data_array = trainning_array.data;
		uchar* model_array = model_gray.data;
		printf("check make array\n");

		for(int j=0 ;j<width;j++)
		{
			
				

			
		}
	}
	
	

	
}