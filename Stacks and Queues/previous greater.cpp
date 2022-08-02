// naive // O(n^2)
#include <bits/stdc++.h>
using namespace std;

void printPrevGreater(int arr[],int n){
    
    for(int i=0;i<n;i++){
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==-1)
            cout<<-1<<" ";
    }
}

int main() 
{ 
    int arr[]={20,30,10,5,15};
    int n=5;
    printPrevGreater(arr,n);
    return 0; 
}

// O(n)
#include <bits/stdc++.h>
using namespace std;

void printPrevGreater(int arr[],int n){
    stack<int>s;
    s.push(arr[0]);
    for(int i=0;i<n;i++){
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        int pg=s.empty()?-1:s.top();
        cout<<pg<<" ";
        s.push(arr[i]);
    }
}

int main() 
{ 
    int arr[]={20,30,10,5,15};
    int n=5;
    printPrevGreater(arr,n);
    return 0; 
}
