#include<iostream>
#include<vector>
using namespace std;

struct subSums {
	int lSum, rSum, mSum, iSum;
};

class Solution {
private:
	subSums update(subSums left,subSums right) {
		subSums res;
		res.iSum = left.iSum + right.iSum;
		res.lSum = max(left.lSum, left.iSum + right.lSum);
		res.rSum = max(right.rSum, right.iSum + left.rSum);
		res.mSum = max(max(left.mSum, right.mSum), left.rSum + right.lSum);
		return res;
	}

	subSums get(vector<int>& arr, const int left, const int right) {
		subSums res;
		if (left == right) {
			res.lSum = arr[left];
			res.rSum = arr[left];
			res.mSum = arr[left];
			res.iSum = arr[left];
			return res;
		}
		int mid = (left + right) / 2;
		subSums leftSub=get(arr, left, mid);
		subSums rightSub=get(arr, mid + 1, right);
		return update(leftSub,rightSub);
	}
	int lastNumber(const int n,const int m) {
		if (n == 0)
			return 0;
		return (lastNumber(n - 1, m) + m) % n;
	}

public:
	int maxSubArray(vector<int>& nums) {
		int s = nums.size() - 1;
		subSums ans = get(nums, 0, s);
		return ans.mSum;
	}
	int findTheLastFriend(const int n,const int m) {
		return lastNumber(n, m);
	}


};
int main()
{
	Solution test;
	//vector<int>arr = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int>arr(10000, 1);
	cout << "The max sum of sub string is: " << test.maxSubArray(arr) << endl;
	int friendsNum = 10,
		friendsGap = 3;
	cout << "The last reamaining friend is: " << test.findTheLastFriend(friendsNum, friendsGap) << endl;
	return 0;
}