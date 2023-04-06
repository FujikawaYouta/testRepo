#include<iostream>
#include<vector>
using namespace std;


class Solution {
private:
    bool chr_check(vector<int>&a, const char ch, const int k) {
        if (a[ch - 'a'] > 0 && a[ch - 'a'] < k)
            return true;
        return false;
    }
    void substring_search(string s,const int start,const int end, const int k, int& ans) {
        vector<int>alphabet(26, 0);
        int start_temp = start,
            end_temp = -1;
        bool flag = false;
        for (int i = start; i <= end; i++)
            alphabet[s[i] - 'a']++;
        for (int i = start; i <= end; i++) {
            if (chr_check(alphabet, s[i], k)) {
                flag = true;
                if (i - 1 >= start && !chr_check(alphabet, s[i - 1], k)) {
                    end_temp = i - 1;
                    substring_search(s, start_temp, end_temp, k, ans);
                }
                if (i + 1 <= end && !chr_check(alphabet, s[i + 1], k)) {
                    start_temp = i + 1;
                }
            }
        }
        if (flag&&!chr_check(alphabet, s[end], k)) {
            substring_search(s, start_temp, end, k, ans);
        }
        if (!flag && ans < end - start+1)
            ans = end - start + 1;
    }
public:
    int LongestSubstring(string s, int k) {
        int ans = 0;
        substring_search(s,0,s.size()-1, k,ans);
        return ans;
    }
};
int main()
{
    Solution result;
    string str_input="a";
    int k = 1;
    cout << result.LongestSubstring(str_input, k) << endl;
    return 0;
}