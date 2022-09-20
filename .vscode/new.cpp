#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a,b,c,ans;
    for(int i=1; i<=n; i++){
        cin>>a>>b>>c;
        
        ans=a*4+b*2+c*0;

        cout<<ans<<endl;

    }



    return 0;
}