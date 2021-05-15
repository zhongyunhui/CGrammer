#include <cstddef>
#include <string>
#include <iostream>
#ifndef Make_plural_H
#define Make_plural_H
using namespace std;
inline string make_plural(size_t ctr, const string& word, const string &ending){
	return (ctr>1)? word+ending:word;
}

#endif
