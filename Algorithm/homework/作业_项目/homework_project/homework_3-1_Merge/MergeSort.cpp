#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_SIZE 100
int b[MAX_SIZE];

template <class Type>
void display(Type a[]) {
    for (int i = 0; i < 8; i++)
        cout << a[i] << ' ';
    cout << endl;
}

template <class Type>
void Merge(Type a[], Type b[], int left, int mid, int right) {
    int i = left,
        j = mid + 1,
        k = left;
    for (; i <= mid && j <= right;) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
        if (i > mid) {
            for (int p = j; p <= right; p++)
                b[k++] = a[p];
        }
        if (j > right) {
            for (int p = i; p <= mid; p++)
                b[k++] = a[p];
        }
    }
}

template <class Type>
void Copy(Type a[], Type b[], int left, int right) {
    int i = left;
    for (; i <= right; i++)
        a[i] = b[i];
}

template <class Type>
void MergeSort(Type a[], int left, int right) {
    if (left < right) {
        int i = (left + right) / 2;
        MergeSort(a, left, i);
        MergeSort(a, i + 1, right);
        Merge(a, b, left, i, right);
        Copy(a, b, left, right);
        cout << "a=";
        display(a);
        cout << "b=";
        display(b);
    }
}


int main() {
    int a[] = { 6,5,3,1,8,7,2,4 };
    MergeSort(a, 0, 7);
    for (int i = 0; i < 8; i++)
        cout << a[i] << ' ';
    return 0;
}