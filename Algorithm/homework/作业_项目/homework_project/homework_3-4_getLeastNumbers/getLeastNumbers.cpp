#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    void Merge(vector<int>& a, vector<int>& b, const int left, const int mid, const int right) {
        int i = left,
            j = mid + 1,
            k = left;
        for (; i <= mid && j <= right;)
            if (a[i] < a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        if (i > mid)
            while (j <= right)
                b[k++] = a[j++];
        else
            while (i <= mid)
                b[k++] = a[i++];
    }
    void Copy(vector<int>&dst,vector<int>src,const int left,const int right) {
        for (int i = left; i <= right; i++)
            dst[i] = src[i];

    }
    void MergeSort(vector<int>& arr,const int left,const int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            vector<int> temp(arr.size(),0);
            MergeSort(arr, left, mid);
            MergeSort(arr, mid + 1, right);
            Merge(arr, temp, left, mid, right);
            Copy(arr, temp, left, right);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        MergeSort(arr, 0, arr.size() - 1);
        vector<int>::const_iterator First = arr.begin();
        vector<int>::const_iterator Last = arr.begin() + k;
        vector<int>ans(First, Last);
        return ans;
    }
};
int main()
{
    Solution test;
    int k = 5;
    vector<int> arr = { 8,1,0,9,7,5,0,3,1,0,2,4 };
    vector<int>ans(test.getLeastNumbers(arr, k));
    for (int i=0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}