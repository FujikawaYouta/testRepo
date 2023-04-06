#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
private:
	bool num_comp(vector<int>num1, vector<int>num2) {
		for (int i = num1.size() - 1; i >= 1; i--) {
			if (num1[i] == num2[i])
				continue;
			else if (num1[i] > num2[i])
				return true;
			else
				return false;
		}
		return true;
	}
	void subtraction_core(vector<int>& num1, vector<int>num2) {//num1>=num2
		for (int i = num1.size() - 1; i >= 1; i--) {
			num1[i] -= num2[i];
		}
		for (int i = 1; i < num1.size() - 1; i++) {
			if (num1[i] < 0) {
				num1[i] += 10;
				num1[i]--;
			}
		}
	}
	void addition_core(vector<int>&num1, vector<int>num2) {
		if (!(num1[0] ^ num2[0])) {
			for (int i = 1; i < num1.size(); i++) {
				num1[i] += num2[i];
			}
			for (int i = 1; i < num1.size()-1; i++) {
				num1[i + 1] += num1[i] / 10;
				num1[i] %= 10;
			}
			if (num1[num1.size() - 1] > 10) {
				num1.push_back(num1[num1.size() - 1] / 10);
				num1[num1.size() - 2] %= 10;
			}
		}
		else{
			if (num_comp(num1, num2)) {
				subtraction_core(num1, num2);
			}
			else {
				subtraction_core(num2, num1);
				num1 = num2;
			}
			while (num1.size() > 2&&num1[num1.size() - 1] == 0)
				num1.pop_back();
			if (num1.size() == 2 && num1[1] == 0)
				num1[0] = 0;
		}
		return;
	}
	void multiply_core(vector<int>&num1, vector<int>num2) {
		num1[0] ^= num2[0];
		if (num1.size() == 2 && num2.size() == 2) {
			num1[1] *= num2[1];
			return;
		}
		else {
			vector<int> num_A(num1.begin() + (num1.size() - 1) / 2+1,num1.begin()+num1.size());
			vector<int> num_B(num1.begin()+1,num1.begin()+(num1.size())/2);
		}
		return;
	}
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		int pos_neg = false;
		if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-'))
			pos_neg=true;
		if (num1[0] == '-')
			num1.erase(0, 1);
		if (num2[0] == '-')
			num2.erase(0, 1);
		vector<int> n1, n2;
		n1.push_back(0);
		n2.push_back(0);
		for (int i = num1.size()-1;i>=0; i--) {
			n1.push_back(num1[i]-'0');
		}
		for (int j = num2.size()-1;j>=0; j--) {
			n2.push_back(num2[j]-'0');
		}
		while (n1.size() > n2.size())
			n2.push_back(0);
		while (n1.size() < n2.size())
			n1.push_back(0);
		multiply_core(n1,n2);
		string ans = "";
		if (pos_neg)
			ans += '-';
		return ans;
	}
	string addition(string num1, string num2) {
		vector<int> n1, n2;
		if (num1[0] == '-') {
			num1.erase(0, 1);
			n1.push_back(1);
		}
		else
			n1.push_back(0);
		if (num2[0] == '-') {
			num2.erase(0, 1);
			n2.push_back(1);
		}
		else
			n2.push_back(0);
		for (int i = num1.size() - 1; i >= 0; i--) {
			n1.push_back(num1[i] - '0');
		}
		for (int j = num2.size() - 1; j >= 0; j--) {
			n2.push_back(num2[j] - '0');
		}
		while (n1.size() > n2.size())
			n2.push_back(0);
		while (n1.size() < n2.size())
			n1.push_back(0);
		addition_core(n1, n2);
		string ans;
		if (n1[0] == 1)
			ans += '-';
		for (int i = n1.size() - 1; i >= 1; i--)
			ans += n1[i] + '0';
		return ans;
	}
};

int main()
{
	Solution test;
	string num1 = "-1234",
		num2 = "5678";
	cout << "the result of num1 multiply num2 is : " << test.multiply(num1,num2) << endl;
	//cout << "the result of num1 addition num2 is : " << test.addition(num1,num2) << endl;
	return 0;
}