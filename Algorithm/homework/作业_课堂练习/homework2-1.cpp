#include<iostream>
using namespace std;

int Ackerman(int n, int m){
    if(n==1 && m==0)
        return 2;
    if(n==0 && m>=0)
        return 1;
    if(n>=2 && m==0)
        return n+2;
    if(n>=1 && m>=1)
        return Ackerman(Ackerman(n-1,m),m-1);
}
int main()
{
	int n,m;
	cout<<"1234"<<endl;
	cin>>n>>m;
	cout<<Ackerman(n,m);
    return 0;
}
