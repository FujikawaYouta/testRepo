#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	int Partition(vector<int>& arr, const int left, const int right) {
		int i = left+1,
			j = right;
		int key = arr[left];
		while (true) {
			while (arr[i] <= key && i < right)
				i++;
			while (arr[j] > key)
				j--;
			if (i >= j)
				break;
			swap(arr[i], arr[j]);
		}
		arr[left] = arr[j];
		arr[j] = key;
		return j;
	}
public:
	void QuickSort(vector<int>& arr,const int left,const int right) {
		if (left < right) {
			int q = Partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q + 1, right);
		}
	}
};
int main()
{
	Solution test;
	vector<int> arr = { 5,1,1,2,0,0 };
	test.QuickSort(arr,0,arr.size()-1);
	cout << '[';
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i < arr.size() - 1)
			cout << ',';
	}
	cout << ']';
	cout << endl;
	return 0;
}