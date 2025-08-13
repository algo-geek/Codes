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

