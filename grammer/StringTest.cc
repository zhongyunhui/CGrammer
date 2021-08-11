#include<cstring>
#include<iostream>
class CMyString{
	public:
		//CMyString(char* m):m_pData(m){};
		CMyString(char* m_pData=NULL):m_pData(m_pData){};
		CMyString(const CMyString &str):m_pData(str.m_pData){};
		//~CMyString(void);
		char * getString(){
			return m_pData;
		}
		CMyString&operator=(const CMyString&);
	private:
		char * m_pData;
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

int main(){
	char x[7]="hello";
	char y[7]="world";
	CMyString A(x);
	CMyString B(y);
	B=A;
	std::cout<<B.getString()<<std::endl;
}
