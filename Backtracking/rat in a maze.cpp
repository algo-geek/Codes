// 1 denotes free path....0 denotes blocked in that particular blocked
// input
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** a, int x, int y, int n)
{
    if(x<n && y<n && a[x][y]==1)// checking if path is blocked or free
    {
        return true;
    }
    return false;
}

bool ratinMaze(int** a, int x, int y, int n, int** solnArray)
{
    if(x==n-1 && y==n-1)// base condition
    {
        solnArray[x][y]=1;
        return true;
    }
    
    if(isSafe(a, x, y, n))
    {
        solnArray[x][y]=1;
        if(ratinMaze(a, x+1, y, n, solnArray))
      {
          return true;
      }
        if(ratinMaze(a, x, y+1, n, solnArray))
      {
          return true;
      }
        solnArray[x][y]=0; //backtracking // if both if conditions are not satisfied
        return false;// rat will move back to previous position
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    
    int** a=new int*[n];
    for(int i=0;i<n;i++)
    a[i]=new int[n];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    
    int** solnArray=new int*[n];
    for(int i=0;i<n;i++)
    {
        solnArray[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            solnArray[i][j]=0;
        }
    }
    
    if(ratinMaze(a, 0, 0, n, solnArray))
    {
        for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            cout<<solnArray[i][j]<<" ";
        }
        cout<<endl;
       }
      
    }
}