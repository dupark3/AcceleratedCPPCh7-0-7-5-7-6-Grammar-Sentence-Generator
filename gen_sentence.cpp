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

    // if word is not bracketed, we can return the word itself as it is not a rule
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate the rule that corresponds to bracketed rule word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw std::logic_error("emtpy rule");

        // fetch the set of possible rules
        const Rule_collection& c = it->second;

        // from which we select one at random
        const Rule& r = c[nrand(c.size())];

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}
