#include<cstring>
#include<iostream>
class CMyString{
	public:
		//CMyString(char* m):m_pData(m){};
		CMyString(char* m_pData=NULL, int a = 0):m_pData(m_pData), _a(a) {};
		CMyString(const CMyString &str):m_pData(str.m_pData), _a(str._a) {};
		//~CMyString(void);
		char * getString(){
			return m_pData;
		}
		CMyString&operator=(const CMyString&);
        CMyString & operator ++();
        CMyString & operator ++(int);
        int geta() {
            return _a;
        }
	private:
		char * m_pData;
        int _a;
};
/*
CMyString&CMyString::operator=(const CMyString&str)
{
	if(this==&str)return *this;
	delete []m_pData;
	m_pData=NULL;
	m_pData=new char[strlen(str.m_pData)+1];
	strcpy(m_pData,str.m_pData);
	return *this;
}*/

CMyString &CMyString::operator=(const CMyString &str){
	if(this!=&str){	
		CMyString tempStr(str);
		char *stemp=m_pData;
		m_pData=tempStr.m_pData;
		tempStr.m_pData=stemp;
	}
	return *this;
}

CMyString &CMyString::operator ++() {
    this->_a += 2;
    return *this;
}

CMyString &CMyString::operator ++(int) {
    this->_a += 3;
    return *this;
}

int main(){
	char x[7]="hello";
	char y[7]="world";
	CMyString A(x, 1);
	CMyString B(y, 1);
	std::cout<<B.getString()<<std::endl;
    A++;
    ++B;
    std::cout<<"A._a: " << A.geta() << "B._a: " << B.geta()<<std::endl;
    return 0;
}
