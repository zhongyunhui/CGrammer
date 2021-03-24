#include "heapsort.h"
#include "people.h"
#include <vector>
using namespace std;

//类外成员函数定义：
template<typename T,typename U >
void HeapSort<T,U>::sort(){
	int sz=_data.size();
	for(int i=sz/2-1;i>=0;i--){
		heapAdjust(i,sz);
	}
	for(--sz;sz>=0;sz--){
		swap(_data[sz],_data[0]);
		heapAdjust(0,sz);
	}
}
template<typename T, typename U>
HeapSort<T,U>::HeapSort(const vector<T> &data){
	_data=data;
}

template<typename T, typename U>
HeapSort<T,U>::HeapSort(T *arr, int size){
	for(int i=0;i<size;i++){
		_data.push_back(arr[i]);
	}
}

template<typename T, typename U>
void HeapSort<T, U>::heapAdjust(int parent, int size){
	int left=parent*2+1;
	while(left<size){
		if(left+1<size&&_data[left]<_data[left+1]){
			left++;
		}
		if(_data[left]>_data[parent]){
			swap(_data[parent],_data[left]);
			parent=left;
			left=parent*2+1;
		}else{
			break;
		}
	}
}

template<typename T, typename U>
void HeapSort<T, U>::display()const{
	for(int i=0;i<_data.size();i++){
		cout<<_data[i]<<" ";
	}
	cout<<endl;
}

int main(){
	People peo[5];
	peo[0].setAge(5);
	peo[1].setAge(7);
	peo[2].setAge(4);
	peo[3].setAge(8);
	peo[4].setAge(3);
	HeapSort<People> heap(peo,5);
	heap.sort();
	heap.display();
}

