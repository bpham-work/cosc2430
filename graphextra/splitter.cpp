#include "splitter.h"

#include <string>
#include <vector>
#include <iterator>

namespace util {
    vector<string> split(const string& s, char delim) {
        vector<string> elems;
        util::split(s, delim, back_inserter(elems));
        return elems;
    }
}
