#include <iostream>
#include <string>
using namespace std;

string getStr(int x) {
    return to_string(x);
}

int main(){
    const string& s = getStr(111);
    
}
