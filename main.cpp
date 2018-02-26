/*
Accelerated C++ by Koenig
Exercise 7-5 Page 138

Reimplement the grammar program using a list as the data structure in which we build the sentence.
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "gen_sentence.h"
#include "grammar_typedef.h"
#include "read_grammar.h"

int main() {
	// generate the sentence
	std::list<std::string> sentence = gen_sentence(read_grammar(std::cin));

	// write the first word, if any
	std::list<std::string>::const_iterator it = sentence.begin();
	if (!sentence.empty()){
		std::cout << *it;
		++it;
	}

	// write the rest of the words, each rpeceded by a space
	while(it != sentence.end()){
		std::cout << " " << *it;
		++it;
	}

	std::cout << std::endl;

	return 0;
}
