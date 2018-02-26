#include <algorithm> // find_if
#include <cctype> //isspace
#include <string>
#include <vector>

#include "split.h"

typedef std::string::const_iterator string_iter;

bool notSpace (const char& c){
    return !isspace(c);
}

bool space (const char& c){
    return isspace(c);
}

std::vector<std::string> split(const std::string& line){
    std::vector<std::string> ret;
    string_iter i = line.begin();

    // Use two iterators and space/notspace predicate to delimit a word
    while (i != line.end()){
        // ignore leading spaces. i will point to first non-space char
        i = std::find_if(i, line.end(), notSpace);

        // find the next space. j will point to the first occurrence of space char after i
        string_iter j = std::find_if(i, line.end(), space);

        // now i and j should delimit the word to be stored unless we hit the end of line
        if (i != line.end())
            ret.push_back(std::string(i, j));

        // move iterator i up to the end of current word
        i = j;
    }

    return ret;
}
