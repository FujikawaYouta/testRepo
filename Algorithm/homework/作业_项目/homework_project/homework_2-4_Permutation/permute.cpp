#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void permute_core(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int idx) {
        if (idx == nums.size()) {//ÖÕÖ¹Ìõ¼ş
            res.push_back(temp);
            return;
        }
        else
            for (int i = idx; i < temp.size(); i++) {//µİ¹éº¯Êı
                swap(temp[idx], temp[i]);
                permute_core(nums, res, temp, idx + 1);
                swap(temp[idx], temp[i]);
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = nums;
        permute_core(nums, res, temp, 0);
        return res;
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