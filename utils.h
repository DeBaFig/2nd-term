


#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
	extern bool debug; // making sdds::debug variable global to all the files
					   // which include: "utils.h"
	int strCmp(const char*, const char*);
	void strCpy(char* des, const char* src);
	int strLen(const char* s);
	int getTime(); // returns the time of day in minutes
	int getInt(const char* prompt = nullptr);
	int getInt(int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);

	char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');

	template <typename type>
	void removeDynamicElement(type* array[], int index, int& size) {
		delete array[index];
		for (int j = index; j < size; j++) {
			array[j] = array[j + 1];
		}
		size--;
	}
	

}
#endif // !SDDS_UTILS_H_

