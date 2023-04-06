

#include<iostream>
#include<vector>
using namespace std;
struct Sum {
	int iSum;
	int lSum;
	int rSum;
	int mSum;
};

class Solution {
private:
	Sum update(Sum left, Sum right) {
		Sum res;
		res.iSum = left.iSum + right.iSum;
		res.lSum = max(left.lSum, left.iSum + right.lSum);
		res.rSum = max(right.rSum, right.iSum + left.rSum);
		res.mSum = max(max(left.mSum, right.mSum), left.rSum + right.lSum);
		return res;
	}
	Sum summation(vector<int> nums, int left, int right)
	{
		if (left == right) {
			Sum sum;
			sum.iSum = nums[left];
			sum.lSum = nums[left];
			sum.rSum = nums[left];
			sum.mSum = nums[left];
			return sum;
		}

		int medium = (left + right) / 2;
		Sum left_sum = summation(nums, left, medium);
		Sum right_sum = summation(nums, medium + 1, right);
		return update(left_sum, right_sum);
	}

public:

	int maxSubArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		Sum sum = summation(nums, left, right);
		return sum.mSum;
	}
};

int main()
{
	Solution test;
	//vector<int>arr = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int>arr(1000000,1);
	cout << "The max sum of sub string is: " << test.maxSubArray(arr) << endl;
	return 0;
}