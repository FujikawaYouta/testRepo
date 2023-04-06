#include<iostream>
using namespace std;

int divide(int n, int m){
	if(n<1 || m<1)
		return 0;
    if(n==1 || m==1)
        return 1;
    if(n<m)
        return divide(n,n);
    if(n==m)
        return 1+divide(n,n-1);
    if(n>m && m>1)
        return divide(n,m-1)+divide(n-m,m);
}
int main()
{
	int n,m;
	cout<<"请输入m，n的值：";
	cin>>n>>m;
	cout<<divide(n,m);
    return 0;
}
