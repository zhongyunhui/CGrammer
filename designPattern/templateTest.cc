#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template<typename T>
class Array {
public:
    Array(size_t t) : _t(t) {
        _arr = (T*) malloc(_t * sizeof(T));
    }
    ~Array() {
        if (_arr != nullptr) {
            free(_arr);
        }
    }
    T& operator[] (size_t i) {
        if (i >= _t) throw "illigal pos";
        return _arr[i];
    }
    T sum() const {
        T tsum;
        for (int i = 0; i <  _t; i++) {
            tsum += _arr[i];
        }
        return tsum;
    }


private:
    size_t _t;
    T* _arr;
};

// 模板模板参数
template <template <typename> class out_container, 
         template <typename> class in_container, typename T>
out_container<T> resequence (const in_container<T>& incon) {
    out_container<T> outcon;
    for (auto x : incon) {
        outcon.push_back(x);
    }
    return outcon;
}

int main() {
    Array<int> tarr(5);
    tarr[0] = 1;
    tarr[1] = 2;
    //cout << tarr.sum() <<endl;
    vector<int> v{1,2,3,4,5};
    auto deq = resequence<std::deque, std::vector, int>(v);
    for (auto item : deq) {
        cout << item << " ";
    }
    return 0;
}
