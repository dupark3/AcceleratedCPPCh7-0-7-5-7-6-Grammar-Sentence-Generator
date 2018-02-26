#ifndef GUARD_grammar_typedef_h
#define GUARD_grammar_typedef_h

#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

// in other words, map<string, vector<vector<string>>>
// because of things like <sentence, ("the", nounphrase, verb, location)
//                        <verb, ("jumps", "sits")>
//                        <nounphrase, (noun, (adjective, nounphrase))>

#endif // GUARD_grammar_typedef_h
