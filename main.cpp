//============================================================================
// Name        : ScalarQuantizer.cpp
// Author      : Jigar Gada
// Last Updated: Feb 22 2014
// Copyright   : Your copyright notice
// Description : Lloyd max quantizer

// ***** Instructions for using this file *********

// 1. All the functions related to Lloyd Max Quantizer are stored in Lloyd folder.

// - Initially prepare the training data. By default I have used 3 files which I
// have merged and prepared a single dataset.You can use any number of files for
// preparing the data. (Make changes in the function prepareTrainingFile accordingly.

// - the variable n takes the number of bits. n = 3 for 3 bit quantizer
// n should not be greater than 8.

// -  train the quantizer by calling the train function

// - For testing the file, Enter the fileName in the test section of this file.

// - Quantized output of the file is stored in *quantizedOutput.dat* file.

// - MATLAB files have been provided for plotting and comparing the quantized and
// original file

//============================================================================

#include <iostream>
#include <math.h>
#include "fileIO.h"
#include "lloyd.h"
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
	char filename1[] = "./resources/chem.256";
	char filename2[] = "./resources/house.256";
	char filename3[] = "./resources/moon.256";

	// No of bits
	int n = 3;

	//--------Train for the quantization levels------------//
	train(memblock, n);

	//------Test the file--------------------------------//
	char testFile[] = "resources/moon.256";
	memblock = readFileByBytes(testFile);
	char outputFile[] = "quantizedOutput.dat";
	// Prepare the output file
	writePrepare(outputFile);
	// Get the quantized value of the file.
	unsigned char *output = test(memblock, FileSizeinBytes);
	// write the data to the file
	for (int i = 0; i < FileSizeinBytes; i++)
	{
		writeFileByBytes(output[i]);
	}

	closeFile();

	cout << "End of program";
	return 0;
}
