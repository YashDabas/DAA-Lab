#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        string s;
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
        }
        
        bool ans= true;
        for (int i = 0; i < n; i++)
        {
        
            for (int j = 0; j < n; j++)
            {
                if(arr[i]== arr[j])
                {
                    if(s[j] != s[i])
                    {
                        ans= false;
                        break;
                    }
                }
            }
            if(!ans)
            {
                break;
            }

        }
        if(ans)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
   
    return 0;
}