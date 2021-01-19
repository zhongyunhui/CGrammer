#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename Compare =std::less<T> >
class HeapSort
{
public:
	HeapSort(T * arr, int size);
	HeapSort(const vector<T> &data);
	void heapAdjust(int parent,int size);
	void sort();
	void display()const;
private:
	vector<T> _data;
};


