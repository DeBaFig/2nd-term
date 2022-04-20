


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<sstream>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
	bool debug = false;  

	int strCmp(const char* s1, const char* s2) {
		int a = 0, dif = 0, b = 0;
		while (dif == 0) {
			if (s1[a] == s2[a])
				a++;
			else
				dif = 1;
		}
		if (dif == 1 && s1[a] > s2[a])
			b = 1;
		if (dif == 1 && s1[a] < s2[a])
			b = -1;
		if (dif == 0 && s1[a] == s2[a])
			b = 0;
		return b;
	}

	void strCpy(char* des, const char* src) {
		int a = 0;
		while (src[a] != '\0') {
			des[a] = src[a];
			a++;
		}
		des[a] = '\0';
	}
	int strLen(const char* s) {
		int a;
		for (a = 0; s[a] != '\0'; a++);
		return a;
	}

	int getTime() {
		int mins = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do {
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin) {
					cout << "Invlid time, try again (HH:MM): ";
					cin.clear();
				}
				else {
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}


	int getInt(const char* prompt)
	{
		int num;
		if (prompt != NULL) cout << prompt;
		while (true)
		{
			bool intOk = false, strOk = false;
			string temp, str;
			getline(cin, temp, '\n');
			istringstream ss(temp);
			if (ss >> num) intOk = true;
			if (!isdigit(temp[temp.size() - 1])) strOk = true;
			if (intOk && !strOk)
				break;
			if (strOk && intOk)
				cout << "Enter only an integer, try again: ";
			else
				cout << "Bad integer value, try again: ";
		}
		return num;
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		int num;
		if (prompt != NULL)	cout << prompt;
		while (true)
		{
			bool intOk = false, strOk = false;
			string temp, str;
			getline(cin, temp, '\n');
			istringstream ss(temp);

			if (ss >> num) intOk = true;
			if (!isdigit(temp[temp.size() - 1])) strOk = true;
			if (intOk && !strOk && num >= min && num <= max)
				break;
			if (showRangeAtError && !strOk)
				cout << "Invalid OHIP Number, [" << min << " <= value <= " << max << "]: ";
			else {
				if (errorMessage && intOk && !showRangeAtError)
					cout << errorMessage;
				else {
					if (strOk && intOk)
						cout << "Enter only an integer, try again: ";
					else
						cout << "Bad integer value, try again: ";

				}
			}
		}
		return num;
	}

	char* getcstr(const char* prompt, istream& istr, char delimiter)
	{
		if (prompt != NULL)	cout << prompt;
		char* str{};
		string strS;
		if (getline(istr, strS, delimiter)) {
			str = new char[strS.size() + 1];
			strCpy(str, strS.c_str());
		}
		return str;
	}
	
}