#include "BinaryReader.h"
#include "Analyzer.h"
#include "StatisticsAnalyzer.h"
#include "DuplicatesAnalyzer.h"
#include "MissingAnalyzer.h"
#include "SearchAnalyzer.h"
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 1000;
const int INT_SIZE = sizeof(int);

void writeBinary(string filename, int* values, int length) {
	
	// Open binary output stream
	ofstream outStream;
	outStream.open(filename, ios::out | ios::binary);
	
	// Check that stream opened
	if (outStream.fail()) {
		cout << "Could not open file for writing." << endl;
		return;
	}

	/*
	* 
	* The Below code should also work to write ints 
	* First create buffer to hold individul bytes
	* Next, use byte masks and bit shifts to put bytes into buffer
	* Then write buffer to output
	* 
	* uint32_t BYTE_MASK0 = 0x000000FF;
	* uint32_t BYTE_MASK1 = 0x0000FF00;
	* uint32_t BYTE_MASK2 = 0x00FF0000;
	* uint32_t BYTE_MASK3 = 0xFF000000;
	* char* pLengthBuffer = new char[INT_SIZE];
	* pLengthBuffer[0] = length & BYTE_MASK0;
	* pLengthBuffer[1] = (length & BYTE_MASK1) >> 8;
	* pLengthBuffer[2] = (length & BYTE_MASK2) >> 16;
	* pLengthBuffer[3] = (length & BYTE_MASK3) >> 32;
	* cout << pLengthBuffer[0] << endl;
	* cout << pLengthBuffer[1] << endl;
	* outStream.write(pLengthBuffer, sizeof length);
	* 
	*/

	// Write binary data to file starting with the length of the array
	// Tried static cast but after that didn't work some online research yeilded this method
	const char* pCharLength = reinterpret_cast<const char*>(&length);
	outStream.write(pCharLength, INT_SIZE);

	// Write array to the file
	for (int i = 0; i < length; i++) {
		const char* pCharValue = reinterpret_cast<const char*>(&values[i]);
		outStream.write(pCharValue, INT_SIZE);
	}

	outStream.close();
}

void createBinaryFile(string filename) {

	// Create array of given length
	int* pArray = new int[SIZE];

	// Use system clock to seed RNG
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	minstd_rand0 generator(seed);

	// Generate random numbers to fill array
	for (int i = 0; i < SIZE; i++) {
		pArray[i] = generator() % 1000;
	}

	writeBinary(filename, pArray, SIZE);
}

/*
* This version of the selectionSort function is not used
* I added it the the base Analyzer class
* This is because I've kept all classes as seperate files with there own header files
* 
*  
void selectionSort(int* values, int size) {
	
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (values[j] < values[minIndex]) {
				minIndex = j;
			}
		}
		int temp = values[i];
		values[i] = values[minIndex];
		values[minIndex] = temp;
	}

}
* 
*/


int main() {
	
	const char* filename = "binary.dat";
	string strName = filename;
	createBinaryFile(strName);
	BinaryReader binaryReader(filename);
	int* pIntArray = binaryReader.getValues();
	int size = binaryReader.getSize();

	StatisticsAnalyzer statsAnalyzer(pIntArray, size);
	DuplicatesAnalyzer dupesAnalyzer(pIntArray, size);
	MissingAnalyzer missingAnalyzer(pIntArray, size);
	SearchAnalyzer searchAnalyzer(pIntArray, size);

	cout << statsAnalyzer.analyze() << endl;
	cout << dupesAnalyzer.analyze() << endl;
	cout << missingAnalyzer.analyze() << endl;
	cout << searchAnalyzer.analyze() << endl;
	
	return 0;
}