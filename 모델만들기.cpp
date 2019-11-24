#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace cv;
using namespace std;


Mat image;
Mat image_data;
Mat image_rot;
Mat image_rotcopy;

int main()
{
	int i = 0;
	for (int j = 1; j < 30; j++)
	{
		String image_name = "C:\\Users\\oh___\\OneDrive\\¹ÙÅÁ È­¸é\\¾ó±¼»çÁø\\" + to_string(j) + ".jpg";
		image = imread(image_name, IMREAD_COLOR);
		resize(image, image_data, Size(512, 512));
		Point2f point(image_data.cols / 2.0, image_data.rows / 2.0);
		

		//imwrite("C:\\Users\\oh___\\OneDrive\\¹ÙÅÁ È­¸é\\¾ó±¼»çÁø\\µ¥ÀÌÅÍ\\d1.jpg", image_data);
		for (int r = -22; r < 22; r++)
		{
			String data_name = "C:\\Users\\oh___\\OneDrive\\¹ÙÅÁ È­¸é\\¾ó±¼»çÁø\\µ¥ÀÌÅÍ\\d" + to_string(i) + ".jpg";
			image_rot = getRotationMatrix2D(point, r * 2, 1);
			warpAffine(image_data, image_rotcopy, image_rot, Size(512, 512));
			imwrite(data_name, image_rotcopy);
			i++;
			printf("%d", r);
		}
		
	}
	i = 0;
	printf("complite");
	waitKey(0);

	return 0;

}
