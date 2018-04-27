#ifndef SPLITTER_H_ 
#define SPLITTER_H_

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

namespace util {
	template<typename Out>
	void split(const string &s, char delim, Out result) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			*(result++) = item;
		}
	}

	vector<string> split(const string& s, char delim);
}

#endif
