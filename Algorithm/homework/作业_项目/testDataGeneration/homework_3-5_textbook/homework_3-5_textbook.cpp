#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
using namespace std;

class testData {
private:
	string numListToString(vector<int>arr) {
		string temp = "";
		char tt[10] = "";
		int s = arr.size();
		for (int i = 0; i < s; i++) {
			temp+=_itoa(arr[i],tt,10);
			temp.push_back(' ');
		}
		return temp;
	}
	vector<int> randomNumList(const int n){
		vector<int>temp(n);
		int pos = 0;
		for (int i = 1; i <= n; i++) {
			pos = randomNumberGeneration(1, n);
			if (temp[pos - 1] == 0)
				temp[pos - 1] = i;
			else {
				int j = 0;
				while (temp[(pos + j) % n]&&j<=n)
					j++;
				temp[(pos + j)%n] = i;
			}
		}
		return temp;
	}
	int randomNumberGeneration(const int left, const int right) {
		srand(time(0));
		int r = rand() % (right - left + 1) + left;
		return r;
	}
	string dictionaryOrderTestDataGeneration() {
		string result = "";
		for (int i = 0; i < 5; i++) {
			int n = randomNumberGeneration(1, 10*(i+1));
			char temp1[3] = "";
			result += _itoa(n, temp1, 10);
			result += '\n';
			vector<int>numList(randomNumList(n));
			result += numListToString(numList);
			result += '\n';
		}
		return result;
	}
public:
	void dictionaryOrder() {
		fstream dicOrder;
		const char* file_src = "input_dictionaryOrder.txt";
		dicOrder.open(file_src,ios::out);
		dicOrder << dictionaryOrderTestDataGeneration();
		dicOrder.close();
	}
};

int main()
{
	testData test;
	test.dictionaryOrder();
	return 0;
}