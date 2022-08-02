
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    for(int i=0;i<n;i++)
    {
        int d=0;
        
        for(int j=i;j>=0;j--)
        {
            if(a[i]>=a[j])
            d++;
            else
            break;
        }
        cout<<d<<endl;
    }
}

//7
// 100 80 60 70 60 75 85

// 1 1 1 2 1 4 6 ------ o/p

// efficient // O(n) time and space
#include <bits/stdc++.h>
using namespace std;

void printSpan(int arr[],int n){
    
    stack<int> s ;
    s.push(0);
    cout<<1<<" ";
    for(int i=1;i<n;i++){
        while(s.empty()==false && arr[s.top()]<=arr[i]){
            s.pop();
        }
        int span=s.empty() ? i+1 : i-s.top();
        cout<<span<<" ";
        s.push(i);
    }
}

int main() 
{ 
    int arr[]={18,12,13,14,11,16};
    int n=6;
    printSpan(arr,n);
    return 0; 
}
