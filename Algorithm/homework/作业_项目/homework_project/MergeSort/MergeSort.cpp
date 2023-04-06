#include<iostream>
#include<vector>
using namespace std;
#define NUM_MAX 1000
vector<int>b(NUM_MAX);
void display_vector(vector<int> a, const int a_size) {
	for (int i = 0; i < a_size; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void Copy(vector<int>& a, vector<int>& temp, const int left, const int right) {
	for (int i = left; i <= right; i++)
		a[i] = temp[i];
}

void Merge(vector<int>&a,vector<int>&temp,const int left,const int mid,const int right) {
	int i = left,
		j = mid + 1,
		k = left;
	for (; i <= mid && j <= right;)
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	if (i > mid)
		while (j <= right)
			temp[k++] = a[j++];
	else
		while (i <= mid)
			temp[k++] = a[i++];
}

void MergeSort(vector<int>& a, const int left, const int right) {
	if (left < right) {
		int mid = (left+right) / 2;
		MergeSort(a,left,mid);
		MergeSort(a, mid + 1, right);
		vector<int>temp(NUM_MAX);
		Merge(a,temp,left,mid,right);
		Copy(a,temp,left,right);
	}
}

int main()
{
	vector<int> a = { 6,5,3,1,8,7,2,4 };
	MergeSort(a,0,a.size()-1);
	display_vector(a, a.size());
	return 0;
}