#include<iostream>
#include<vector>
using namespace std;

int upper_bound(vector<int>nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (right < 0 || nums[right] != target) return -1;
    return right;
}

int lower_bound(vector<int>nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (left >= nums.size() || nums[left] != target) return -1;
    return left;
}

int main(){
    int searchVal;
    cin >> searchVal;
    vector<int>arr = {0, 1, 1, 3, 4, 5, 6};
    auto res = upper_bound(arr, searchVal);
    cout<<"res : "<< res << endl;
    return 0;
}


