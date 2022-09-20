#include<iostream>
using namespace std;

int main(){

    int n;

    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        int b[a];
        for ( int j = 0; j<a; j++)
        {
            cin>>b[j];

        }
        if (a%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    

    return 0;

}