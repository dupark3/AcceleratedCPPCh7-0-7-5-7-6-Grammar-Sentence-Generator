#ifndef GUARD_grammar_typedef_h
#define GUARD_grammar_typedef_h

#include <map>
#include <string>
#include <vector>
#include <list>

typedef std::list<std::string> Rule;
typedef std::list<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

#endif // GUARD_grammar_typedef_h
