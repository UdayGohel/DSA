#include<iostream>
using namespace std;

int main(){

    int n,a,b,c,ans;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        cin>>a>>b>>c;

        ans = b-c;

        ans*=a;

        cout<<ans<<endl;
    }
    

    return 0;

}