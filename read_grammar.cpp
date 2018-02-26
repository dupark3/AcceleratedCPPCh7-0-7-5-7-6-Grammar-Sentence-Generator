#include <iostream>
#include <string>
#include <vector>

#include "grammar_typedef.h"
#include "split.h"

Grammar read_grammar(std::istream& in){
    Grammar ret;
    std::string line;

    // read the input
    while (getline(in, line)){

        // split the input into words
        std::vector<std::string> entry = split(line);

        if (!entry.empty()){
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}
