#include<iostream>
using namespace std;

class Solution {
private:
    int mul(const int A, const int B) {
        if (!A)
            return 0;
        if (!(A - 1))
            return B;
        if (A & 1)
            return B + ((mul(A >> 1, B)) << 1);
        else
            return mul(A >> 1, B) << 1;
    }
public:
    int multiply(int A, int B) {
        return mul(A, B);
    }
};
int main() {
    Solution test;
    cout << "The result of 3 multiply 4 is: " << test.multiply(4, 3) << endl;
    return 0;
}