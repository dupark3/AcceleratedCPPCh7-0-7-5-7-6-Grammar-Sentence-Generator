#ifndef GUARD_gen_sentence_h
#define GUARD_gen_sentence_h

#include <string>
#include <vector>

#include "grammar_typedef.h"

bool bracketed(const std::string&);
std::vector<std::string> gen_sentence (const Grammar&);
void gen_aux (const Grammar&, const std::string&, std::vector<std::string>&);

#endif // GUARD_gen_sentence_h
