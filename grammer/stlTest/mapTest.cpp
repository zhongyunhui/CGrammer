#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
void mapTest(){
	map<string,string> mp;
	mp["11"]="shanghai";
	mp["22"]="beijing";
	mp["33"]="guangzhou";
	//mp["44"]="shanghai";
	mp.insert({"11","wuhu"});
	//mp.insert(make_pair("66","xian"));
	cout<<"11: "<<mp["11"]<<endl;
	for(auto pos=mp.begin();pos!=mp.end();pos++){
		cout<<" "<<pos->second;
	}
}

void unordered_mapTest(){
    unordered_map<string,string> mp;
    mp["11"]="shanghai";
    mp["22"]="beijing";
    mp["33"]="guangzhou";
    mp["55"]="wuhu";
    mp.insert(make_pair("44","wuhu"));
    mp.insert(make_pair("66","xian"));
    cout<<"11: "<<mp["11"]<<endl;
    for(auto pos=mp.begin();pos!=mp.end();pos++){
        cout<<" "<<pos->second;
    }
	cout<<endl;
}
void multimapTest(){
	multimap<string,string> mp;
	//multimap不支持这种赋值,也不支持下标访问。但是关键字可以相同，默认按升序排列
	
	//mp["22"]="beijing";
    //mp["33"]="guangzhou";
    mp.insert(make_pair("11","wuhu"));
    mp.insert(make_pair("66","xian"));
    mp.insert(make_pair("11","shanghai"));
	mp.insert(make_pair("00","beijing"));
	//cout<<"11: "<<mp["11"]<<endl;
    for(auto pos=mp.begin();pos!=mp.end();pos++){
        cout<<" "<<pos->second;
    }
	//计数关键字为"11"的元素个数
	cout<<" cnt: "<<mp.count("11");
	//第一个为"11"的元素 
	auto it=mp.find("11");
	for(;it!=mp.end();it++){
		cout<<" "<<it->second;
	}
    cout<<endl;
}

int main(){
	//mapTest();
	//unordered_mapTest();
	multimapTest();
	return 0;
}
	
