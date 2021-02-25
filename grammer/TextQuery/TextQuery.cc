#include "TextQuery.h"
#include "make_plural.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <fstream>
#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cstring>
#include <utility>
using namespace std;

using wmType=map<string, shared_ptr<set<TextQuery::line_no> > >;
using vmIter=wmType::const_iterator;
using lineType=shared_ptr<set<TextQuery::line_no> >;
using lineIter=set<TextQuery::line_no>::const_iterator;

TextQuery::TextQuery(ifstream &is):file(new vector<string>){
	string text;
	while(getline(is,text)){
		file->push_back(text);
		int n=file->size()-1;
		istringstream line(text);
		string word;
		while(line>>word){//逐个处理word
			word=cleanup_str(word);
			lineType &lines=wm[word];
			if(!lines)lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

string TextQuery::cleanup_str(const string &word){
	string ret;
	for(string::const_iterator it=word.begin();it!=word.end();it++){
		if(!ispunct(*it))ret+=tolower(*it);
	}
	return ret;
}

QueryResult
TextQuery::query(const string &sought) const
{
	// we'll return a pointer to this set if we don't find sought
	static lineType nodata(new set<line_no>); 

    // use find and not a subscript to avoid adding words to wm!
    wmIter loc = wm.find(cleanup_str(sought));

	if (loc == wm.end()) 
		return QueryResult(sought, nodata, file);  // not found
	else 
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;

    // print each line in which the word appeared
	// for every element in the set
	for (lineIter num = qr.lines->begin();
				num != qr.lines->end(); ++num)
		// don't confound the user with text lines starting at 0
        os << "\t(line " << *num + 1 << ") "
		   << *(qr.file->begin() + *num) << endl;
	return os;
}

void TextQuery::display_map()
{
    wmIter iter = wm.begin(), iter_end = wm.end();
    // for each word in the map
    for ( ; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";
        // fetch location vector as a const reference to avoid copying it
        lineType text_locs = iter->second;
        lineIter loc_iter = text_locs->begin(),
                        loc_iter_end = text_locs->end();
        // print all line numbers for this word
        while (loc_iter != loc_iter_end)
        {
            cout << *loc_iter;
            if (++loc_iter != loc_iter_end)
                 cout << ", ";
         }
         cout << "}\n";  // end list of output this word
    }
    cout << endl;  // finished printing entire map
}



