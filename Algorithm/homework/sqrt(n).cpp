#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"������һ����������"; 
    cin>>n;
    if(cin.fail()){
        cout<<"�������"<<endl;
    }
    else if(n<0){
        cout<<"����Ĳ�������"<<endl;
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
            cout<<"����ȡ����ƽ����Ϊ��"<<mx<<endl;
        else
            cout<<"����ȡ����ƽ����Ϊ��"<<mn<<endl;
    }
    return 0;
}
