#ifndef GUARD_grammar_typedef_h
#define GUARD_grammar_typedef_h

#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

#endif // GUARD_grammar_typedef_h
