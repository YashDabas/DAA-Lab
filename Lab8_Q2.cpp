// Implement DFS algorithm using Adjacency matrix in the undirected graph.
// NAME - YASH DABAS
// CLASS- CSAI-2;
// ROLL NO.- 2021UCA1912
// "I have done this assignment on my own. I have not copied any code from another student or
// any online source. I understand if my code is found similar to somebody else's code, my case can
// be sent to the Disciplinary committee of the institute for appropriate action."


#include<iostream>
using namespace std;
void printdfs(int**matrix,int*check,int node,int vertices)
{   
    if(check[node]==0)
    {
        cout<<node<<" ";
        check[node]=1;
    }
    for(int i=0;i<vertices;i++)
    {
        if(matrix[node][i]!=0 && check[i]==0)
        {
            cout<<i<<" ";
            check[i]=1;
            printdfs(matrix,check,i,vertices);

        }
    }
}
int main(){
cout<<"enter no of vertices "<<endl;
int vertices;
cin>>vertices;
int**matrix=new int*[vertices]; 
for(int i=0;i<vertices;i++)
{
    matrix[i]=new int[vertices];
    for(int j=0;j<vertices;j++)
    {
        matrix[i][j]=0;
    }
}
cout<<"enter pairs"<<endl;
int x;int y;
cin>>x>>y;
while(x !=-1 && y!=-1)
{   
    matrix[x][y]=1;
    matrix[y][x]=1;
    cin>>x>>y;
}
int *check=new int[vertices];
for(int i=0;i<vertices;i++)
{
    check[i]=0;
}

printdfs(matrix,check,0,vertices);
return 0;
}