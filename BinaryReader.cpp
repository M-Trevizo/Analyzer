#include "BinaryReader.h"
#include <iostream>
#include <fstream>

using namespace std;

const int INT_SIZE = 4;

BinaryReader::BinaryReader(const char* filename) {
	readValues(filename);
}

BinaryReader::~BinaryReader() {
	delete[] pIntArray;
	pIntArray = nullptr;
}

void BinaryReader::readValues(const char* filename) {

	// Open binary input stream
	ifstream inStream;
	inStream.open(filename, ios::in | ios::binary);

	// Check that file was opened
	if (inStream.fail()) {
		cout << "Could not open binary file." << endl;
		return;
	}

	// Create char array
	char* pCharLength = new char[INT_SIZE];

	// Read first 4 bytes into char array
	inStream.read(pCharLength, 4);

	// Calculate each byte
	// int b0 = pCharLength[0] does not work?
	// Seems to be treating byte as a signed int which gives it the wrong value when adding
	// 0xE8 = -24 instead of 0xE8 = 232
	// Made it an unsigned 8 bit int to ensure it doesn't mess up the sign
	// Probably not the best fix but it works
	uint8_t b0 = pCharLength[0];
	int b1 = pCharLength[1] * 256;
	int b2 = pCharLength[2] * pow(256, 2);
	int b3 = pCharLength[3] * pow(256, 3);

	// Calculate arrLength from 4 bytes and create new array
	size = b0 + b1 + b2 + b3;
	pIntArray = new int[size];

	// Loop through char array 4 chars at a time to get ints
	for (int i = 0; i < size; i++) {

		// Create char array to store read calls
		char* pCharValues = new char[INT_SIZE];

		// Read 4 bytes at a time into pCharValues
		inStream.read(pCharValues, INT_SIZE);

		// Calculate each byte as before
		uint8_t b0 = pCharValues[0];
		int b1 = pCharValues[1] * 256;
		int b2 = pCharValues[2] * pow(256, 2);
		int b3 = pCharValues[3] * pow(256, 3);

		int num = b0 + b1 + b2 + b3;

		pIntArray[i] = num;

		delete[] pCharValues;
		pCharValues = nullptr;
	}

	delete[] pCharLength;
	pCharLength = nullptr;

	inStream.close();
}