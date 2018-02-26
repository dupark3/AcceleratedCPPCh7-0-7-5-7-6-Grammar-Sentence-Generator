#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

// in other words, map<string, vector<vector<string>>>
// because of things like <sentence, ("the", nounphrase, verb, location)
//                        <verb, ("jumps", "sits")>
//                        <nounphrase, (noun, (adjective, nounphrase))>

// read a grammar from a given input stream
Grammar read_grammar(std::istream& in){
    Grammar ret;
    std::string line;

    // read the input
    while (getline(in, line)){

        // split the input into words
        std::vector<std::string> entry = split(line);

        if (!entry,.empty()){
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}
