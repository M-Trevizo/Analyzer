#pragma once
class BinaryReader {
public:
	BinaryReader(const char* filename);
	~BinaryReader();
	int* getValues() const { return pIntArray; }
	int getSize() const { return size; }

private:
	int* pIntArray;
	int size;

	void readValues(const char* filename);
};