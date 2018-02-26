#include <iostream>
#include <list>
#include <stdexcept> // logic_error
#include <string>
#include <vector>

#include "gen_sentence.h"
#include "grammar_typedef.h"
#include "nrand.h"

bool bracketed(const std::string& s){
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

std::list<std::string> gen_sentence (const Grammar& g){
    std::list<std::string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

void gen_aux (const Grammar& g, const std::string& word, std::list<std::string>& ret){
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
        Rule_collection::const_iterator randomIt = c.begin();
        int randomInt = nrand(c.size());
        for (int i = 0; i != randomInt; ++i)
            ++randomIt;
        const Rule& r = *randomIt; // list version
        // const Rule& r = c[nrand(c.size())]; vector version

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}
