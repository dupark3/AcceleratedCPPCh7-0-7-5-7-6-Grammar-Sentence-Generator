// Exercise 7-6 Reimplement the gen_sentence program using two vectors: One will hold the fully
// unwound, generated sentence, and the other will hold the rules and will be used as a stack.
// Do not use any recursive calls

#include <iostream>
#include <stdexcept> // logic_error
#include <string>
#include <vector>

#include "gen_sentence.h"
#include "grammar_typedef.h"
#include "nrand.h"

bool bracketed(const std::string& s){
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

std::vector<std::string> gen_sentence (const Grammar& g){
    std::vector<std::string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

void gen_aux (const Grammar& g, const std::string& word, std::vector<std::string>& ret){
    // In order to avoid using recursion here, we will iterate through g.find("<sentence>")
    // g[<sentence>] = the <noun-phrase> <verb> <location>
    // it = *g.begin() = the  --> pushback since !bracketed
    // ++it;
    // next element is <noun-phrase>. g.find(*it)

    Grammar::const_iterator it = g.find(word); // it points to <sentence>
    if (it == g.end())
        throw std::logic_error ("empty rule"); // g did not contain <sentence>
    const Rule_collection& c = it->second; // c is the vector of vectors possible for <sentence> (only one in this case)
    const Rule& r = c[nrand(c.size())]; // r selected a random rule of <sentence>, so now holds "the", <noun-phrase>, <verb>, <location>

    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i){
        if (!bracketed(*i)){
            ret.push_back(*i);
        } else {
            const Rule_collection& c2 = g.find(*i)->second; // c2 holds the vector of vectors if bracketed OR holds vector of strings
            const Rule& r2 = c2[nrand(c2.size())]; // r2 holds the randomly selected vector from the vector of vectors
            Rule::const_iterator j = r2.begin(); // j points to the beginning of the randomly selected vector of strings
            while (bracketed(*j)){
//                if (g.end() == g.find(*j))
//                    throw std::logic_error("empty rule");
                const Rule_collection& c3 = g.find(*j)->second;
                const Rule& r3 = c3[nrand(c3.size())];
                j = r3.begin();
            }
            ret.push_back(*j);
        }
    }
}

