#include<iostream>
#include<algorithm>
using namespace std;
#define NUM_MAX 1000000007
class Solution {
public:
    int numWays(int n) {
        /*
        if (n == 0 || n == 1)
            return 1;
        return (numWays(n-1)+numWays(n-2))%NUM_MAX;
        */
        if (n == 0 || n == 1)
            return 1;
        int ans = 0;
        int ans_1 = 1, ans_2 = 1;
        for (int i = 0; i < n-1; i++) {
            ans = (ans_1 + ans_2)%NUM_MAX;
            ans_1 = ans_2;
            ans_2 = ans;
        }
        return ans;
    }
};
int main() {
    Solution result;
    int n = 7;
    cout << result.numWays(n);
}