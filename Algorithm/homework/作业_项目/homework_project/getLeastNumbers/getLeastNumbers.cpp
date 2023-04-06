#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<int> vectorGeneration(vector<int>arr, const int k) {
        vector<int>::const_iterator First = arr.begin();
        vector<int>::const_iterator Last = arr.begin() + k;
        vector<int>ans(First, Last);
        return ans;
    }

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
    void Copy(vector<int>& dst, vector<int>src, const int left, const int right) {
        for (int i = left; i <= right; i++)
            dst[i] = src[i];

    }
    void MergeSort(vector<int>& arr, const int left, const int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            vector<int> temp(arr.size(), 0);
            MergeSort(arr, left, mid);
            MergeSort(arr, mid + 1, right);
            Merge(arr, temp, left, mid, right);
            Copy(arr, temp, left, right);
        }
    }

    int Random(const int left, const int right) {
        return rand() % (right - left + 1) + left;
    }
    int Partition(vector<int>& arr, const int left, const int right) {
        int i = left,
            j = right + 1,
            key = arr[left];
        while (true) {
            while (arr[++i] <= key && i < right)
                ;
            while (arr[--j] > key)
                ;
            if (i >= j)
                break;
            swap(arr[i], arr[j]);
        }
        arr[left] = arr[j];
        arr[j] = key;
        return j;
    }
    int RandomizedPartition(vector<int>& arr, const int left, const int right) {
        int r = Random(left, right);
        swap(arr[left], arr[r]);
        return Partition(arr, left, right);
    }
    void RandomizedQuickSort(vector<int>& arr, const int left, const int right) {
        if (left < right) {
            int q = RandomizedPartition(arr, left, right);
            RandomizedQuickSort(arr, left, q - 1);
            RandomizedQuickSort(arr, q + 1, right);
        }
    }

    int Partition(vector<int>& arr, const int left, const int right, const int x) {
        int i = left,
            j = right + 1,
            key = x;
        while (true) {
            while (arr[++i] <= key && i < right)
                ;
            while (arr[--j] > key)
                ;
            if (i >= j)
                break;
            swap(arr[i], arr[j]);
        }
        return j;
    }
    int RandomizedSelect(vector<int>& arr, const int left, const int right, const int k) {
        if (left == right)
            return left;
        int i = RandomizedPartition(arr, left, right);
        int j = i - left + 1;
        if (k == j)
            return k;
        else if (k < j)
            return RandomizedSelect(arr, left, i - 1, k);
        else
            return RandomizedSelect(arr, i + 1, right, k - j);
    }

    int Select(vector<int>& arr, const int left, const int right, const int k) {
        if (right - left < 75) {
            MergeSort(arr, left, right);
            return arr[left + k - 1];
        }
        for (int i = 0; i <= (right - left - 4) / 5; i++) {
            int x = Select(arr, left, left + (right - left - 4) / 5, (right - left - 4) / 10);
            int idx_1 = Partition(arr, left, right, x),
                idx_2 = idx_1 - left + 1;
            if (k <= idx_2)
                return Select(arr, left, idx_1, k);
            else
                return Select(arr, idx_1 + 1, right, k - idx_2);
        }
        return -1;
    }
public:
    /*
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        MergeSort(arr, 0, arr.size() - 1);
        vector<int>ans(vectorGeneration(arr,k));
        return ans;
    }
    */
    /*
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        RandomizedQuickSort(arr,0,arr.size() - 1);
        vector<int>ans(vectorGeneration(arr,k));
        return ans;
    }
    */
    /*
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        RandomizedSelect(arr, 0, arr.size() - 1, k);
        vector<int>ans(vectorGeneration(arr,k));
        return ans;
    }
    */

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            vector<int>ans;
            return ans;
        }
        Select(arr, 0, arr.size() - 1, k);
        vector<int>ans=vectorGeneration(arr, k);
        return ans;
    }
};
int main()
{
    Solution test;
    int k = 75;
    vector<int> arr = { 0,1,1,1,4,5,3,7,7,8,
        10,2,7,8,0,5,2,16,12,1,19,15,5,18,2,
        2,22,15,8,22,17,6,22,6,22,26,32,8,10,
        11,2,26,9,12,9,7,28,33,20,7,2,17,44,
        3,52,27,2,23,19,56,56,58,36,31,1,19,
        19,6,65,49,27,63,29,1,69,47,56,61,40,
        43,10,71,60,66,42,44,10,12,83,69,73,
        2,65,93,92,47,35,39,13,75 };
    vector<int>ans(test.getLeastNumbers(arr, k));
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}