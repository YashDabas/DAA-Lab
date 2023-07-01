#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
        int count=0;
        int j=1;
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" ";
        count++;
        if(count==j)
        {
            cout<<endl;
            count=0;
            j++;
        }
    }
   
    return 0;
}