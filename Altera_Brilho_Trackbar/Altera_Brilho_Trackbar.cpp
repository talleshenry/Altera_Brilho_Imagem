// Altera_Brilho_Trackbar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Mat img = imread("image.JPEG");

	if (img.empty()){
		cout << "Erro ao carregar a imagem!" << endl;
		return -1;
	}

	namedWindow("Minha Imagem",1);

	//cria trackbar para alterar o brilho
	int iSliderValue1 = 50;
	createTrackbar("Brilho", "Minha Imagem", &iSliderValue1, 100);

	//cria trackbar para alterar contraste
	int iSliderValue2 = 50;
	createTrackbar("Contraste", "Minha Imagem", &iSliderValue2, 100);

	while (true)
	{
		//altera o brilho e o contraste da imagem
		Mat dst;
		int iBrilho = iSliderValue1 - 50;
		double dcontraste = iSliderValue2 / 50;
		img.convertTo(dst, -1, dcontraste, iBrilho);

		imshow("Minha Imagem", dst);

		int iKey = waitKey(50);

		if (iKey == 27){
			break;
		}
	}

	return 0;
}

