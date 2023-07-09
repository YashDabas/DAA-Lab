#include <bits/stdc++.h>
using namespace std;
void helper(char p,unordered_map<char,vector<char>>a,unordered_map<char,int>&v,vector<char>&ans){
    v[p]=1;
    for(int i=0;i<a[p].size();i++){
        if(v[a[p][i]]==0){
            helper(a[p][i],a,v,ans);
        }
    }
    ans.push_back(p);
}
int main(){
    int n;
    int e;
    cin>>n;
    cin>>e;
    unordered_map<char,vector<char>>a;
    for(int i=0;i<e;i++){
        char p;
        char q;
        cin>>p;
        cin>>q;
        a[p].push_back(q);
    }
    
    vector<char>ans;
    unordered_map<char,int>v;
    for(auto i=a.begin();i!=a.end();i++){
        if(v[i->first]==0){
            helper(i->first,a,v,ans);
        }
    }
}