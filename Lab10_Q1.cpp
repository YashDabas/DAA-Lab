#include <bits/stdc++.h>
using namespace std;

void BruteForce(string t, string p)
{
    int n,m;
    n= t.length();
    m= p.length();
    bool no = false;
    for(int i=0; i<=n-m; i++)
    {
        int j=0;
        bool check = false;
        while( t[i+j]== p[j])
        {
            if(j == m-1)
            {
                check= true;
                no=true;
                break;
            }
            j++;
            
        }
        if(check==true)
        {
            cout<< "Pattern occurs with shift "<<i<<endl;
        }

    }
    if(!no)
    {
        cout<<"Not Exist";
    }
}

int main()
{
    
    string t;
    cout<<"Enter text string: "<<endl;
    cin>>t;
    string p;
    cout<<"Enter pattern string: "<<endl;
    cin>>p;
    BruteForce(t,p);
}