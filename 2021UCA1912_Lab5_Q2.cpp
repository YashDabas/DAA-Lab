#include<iostream>
#include<bits/stdc++.h>
using namespace std;    
int main()
{
    int r1;
    int c1;
    int r2;
    int c2;
    cout<<"Number of rows in first Matrix"<<endl;    
    cin>>r1;    
    cout<<"Enter number of columns for First Matrix:"<<endl;     
    cin>>c1; 
    cout<<"Enter number of rows for Second Matrix:"<<endl;    
    cin>>r2;    
    cout<<"Enter number of columns for Second Matrix:"<<endl;     
    cin>>c2;
    if(c1!=r2)
    {
        cout<<"Matrices Cannot be multiplied";
    }
    else
    {
        int m1[r1][c1],m2[r2][c2];
        cout<<"Enter first matrix elements "<<endl;    
        for(int i=0;i<r1;i++)    
        {    
            for(int j=0;j<c1;j++)    
            {    
                cin>>m1[i][j];    
            }    
        }    
        cout<<"Enter Second matrix elements"<<endl;    
        for(int i=0;i<r2;i++)    
        {    
            for(int j=0;j<c2;j++)    
            {    
                cin>>m2[i][j];    
            }    
        }    
        int ans[r1][c2];
        for(int i=0;i<r1;i++)    
        {    
            for(int j=0;j<c2;j++)    
            {    
                ans[i][j]=0; 
                for(int k=0;k<c1;k++)    
                {    
                    ans[i][j]+=m1[i][k]*m2[k][j];    
                } 
            }    
        }    
        cout<<"Multiplied matrix"<<endl;     
        for(int i=0;i<r1;i++)    
        {    
            for(int j=0;j<c2;j++)    
            {    
                cout<<ans[i][j]<<" ";    
            }    
            cout<<endl;
        } 
    }
    return 0;  
}