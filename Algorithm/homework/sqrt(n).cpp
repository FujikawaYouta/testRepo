#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"请输入一个正整数："; 
    cin>>n;
    if(cin.fail()){
        cout<<"输入错误"<<endl;
    }
    else if(n<0){
        cout<<"输入的不是正数"<<endl;
    }
    else{
        int mx=n;
        int mn=1;
        int ans=(mx+mn)/2;
        while(mx-mn>1){
            if(ans*ans>n)
                mx=ans;
            else
                mn=ans;
            ans=(mx+mn)/2;
        }
        if(mx*mx==n)
            cout<<"向下取整的平方根为："<<mx<<endl;
        else
            cout<<"向下取整的平方根为："<<mn<<endl;
    }
    return 0;
}
