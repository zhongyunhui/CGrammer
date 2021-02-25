#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
class String{
private:
	char *_pstr;
	void initRefcount(){
		*reinterpret_cast<int *>(_pstr-4)=1;
	}
	void increaseRefcount(){
		++*reinterpret_cast<int *>(_pstr-4);
	}
	void decreaseRedcount(){
		--*reinterpret_cast<int *>(_pstr-4);
	}
	class CharProxy{
	private:
		String &_self;
		int _idx;
	public:
		CharProxy(String &self, int idx):_self(self),_idx(idx){}
		char &operator =(char ch);
		friend std::ostream &operator <<(std::ostream &os, const String::CharProxy &rhs);
	};
	//对<< >>操作符重载
	friend std::ostream &operator <<(std::ostream &os, const String::CharProxy &rhs);
	friend std::ostream &operator <<(std::ostream &os, const String& rhs);
public:
	String():_pstr(new char[5]()+4){
		initRefcount();
	}
	String(const char* pstr):_pstr(new char[strlen(pstr)+5]()+4){
		strcpy(_pstr,pstr);
		initRefcount();
	}
	String(const String &rhs):_pstr(rhs._pstr){
		increaseRefcount();
	}
	void release(){
		decreaseRedcount();
		if(refcount()==0){
			delete[] (_pstr-4);
			cout<<"delete data"<<endl;
		}
	}
	int refcount()const{
		return *reinterpret_cast<int*>(_pstr-4);
	}
	const char *c_str()const{
		return _pstr;
	}
	int size()const{
		return strlen(_pstr);
	}
	//使用CharProxy对下标运算符特殊处理
	CharProxy operator[] (int idx){
		return CharProxy(*this,idx);
	}
public:
	//移动构造函数
	String(String &&rhs){
		_pstr=rhs._pstr;
		rhs._pstr=nullptr;
	}
	//移动复制赋值运算符
	String& operator=(String &&rhs){
		if(this!=&rhs){
			delete[] _pstr;
			_pstr=rhs._pstr;
			rhs._pstr=nullptr;
		}
		return *this;
	}
};
//重载<<符号
std::ostream & operator <<(std::ostream &os, const String & rhs){
	os<<rhs._pstr;
	return os;
}
char &String::CharProxy::operator=(char ch){
	static char nullchar='\0';
	if(_idx<0||_idx>=_self.size()){
		cout<<"idx越界"<<endl;
		return nullchar;
	}else{
		if(_self.refcount()>1){
			//新建一个String
			_self.decreaseRedcount();
			char *ptemp=new char[_self.size()+5]()+4;
			strcpy(ptemp,_self._pstr);
			_self._pstr=ptemp;
			_self.initRefcount();
		}
		_self._pstr[_idx]=ch;
		return _self._pstr[_idx];
	}
}
std::ostream &operator <<(std::ostream &os,const String::CharProxy &rhs){
	os<<rhs._self._pstr[rhs._idx];
	return os;
}

int main(){
	String s1="Hello,World!";
	String s2=s1;
	cout<<"s2= "<<s2<<endl;
	printf("s1 address %p\n",s1.c_str());
	printf("s2 address %p\n",s2.c_str());
	s2[2]='f';
	printf("s1 address %p\n",s1.c_str());
	printf("s2 address %p\n",s2.c_str());
}











