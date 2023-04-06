#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void my_permute(vector<int>& nums,vector<vector<int>>&ans, int k) {
        int nums_size = nums.size();
        if (nums_size - k == 1) {
            ans.push_back(nums);
            return;
        }
        else {
            for (int i = k; i < nums_size; i++) {
                swap(nums[k], nums[i]);
                my_permute(nums, ans, k + 1);
                swap(nums[k], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        my_permute(nums,ans, 0);
        return ans;
    }
};

int main()
{
    Solution test;
    vector<int> insert_nums = { 1,2,3,4 };
    vector<vector<int>> result = test.permute(insert_nums);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        if (i > 0)
            cout << ',';
        cout << '[';
        for (int j = 0; j < result[0].size(); j++) {
            if (j > 0)
                cout << ',';
            cout << result[i][j];
        }
        cout << ']';
    }
    cout << ']' << endl;
    return 0;
}