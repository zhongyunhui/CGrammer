#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"
using namespace std;
QueryResult NotQuery::eval(const TextQuery &text)const{
	QueryResult result=query.eval(text);
	shared_ptr<set<line_no> >ret_lines(new set<line_no>);
	QueryResult::line_it beg=result.begin(),end=result.end();
	vector<string>::size_type sz=result.get_file()->size();
	for(size_t n=0;n!=sz;n++){
		if(beg==end||*beg!=n)ret_lines->insert(n);
		else if(beg!=end)++beg;
	}
	return QueryResult(rep(),ret_lines,result.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text)const{
	QueryResult left=lhs.eval(text), right=rhs.eval(text);
	shared_ptr<set<line_no> >ret_lines(new set<line_no>);
	set_intersection(left.begin(),left.end(),right.begin(),right.end(),insert(*ret_lines,ret_lines->begin()));
	return QueryResult(rep(),ret_lines, left.get_file());
}

QueryResult OrQuery::eval(const TextQuery& text)const{
	QueryResult right=rhs.eval(text), left=lhs.eval(text);
	shared_ptr<set<line_no> >ret_lines(new set<line_no>(left.begin(),left.end()));
	ret_lines->insert(right.begin(),right.end());
	return QueryResult(rep(),ret_lines,left.get_file());
}
