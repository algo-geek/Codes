// naive
#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i])curr+=arr[i];
            else break;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i])curr+=arr[i];
            else break;
        }
        res=max(res,curr);
    }
    return res;
    
}

int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}

// better
#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[],int n){
    int res=0;
    int ps[n],ns[n];
    
    stack <int> s;
    s.push(0);
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int pse=s.empty()?-1:s.top();
        ps[i]=pse;
        s.push(i);
    }
    
    while(s.empty()==false){
        s.pop();
    }
    
    s.push(n-1);
    for(int i=n-1;i>0;i--){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int nse=s.empty()?n:s.top();
        ns[i]=nse;
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
        int curr=arr[i];
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;
    
}

int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}

// efficient
#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int>& heights) {
        // insert in stack until a next smaller element is found
        // pop elements such that
        // max(nxtSmaller*(next_small_idx-poppedElement+1), poppedElement*(nxtSmallerIdx-poppedElement))
        // pop out elements from stack->poppedElement*(lastPoppedElementIdx-poppedElementIdx+1)

        stack<int>s;
        heights.push_back(0);
        int n=heights.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
        while(!s.empty() && heights[i]<heights[s.top()]){
            int top=heights[s.top()];
            s.pop();
            int w=s.empty()?-1:s.top();
            ans=max(ans,top*(i-w-1));
        }
        s.push(i);
        }
        return ans;
    }

int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}

