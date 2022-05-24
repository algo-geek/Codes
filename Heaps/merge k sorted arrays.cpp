//naive
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeArrays( vector<int> arr1, vector<int> arr2) 
{ 
    int i = 0, j = 0; vector<int> arr3;
  
    while (i<arr1.size() && j <arr2.size()) 
    { 
        if (arr1[i] < arr2[j]) 
            arr3.push_back(arr1[i++]); 
        else
            arr3.push_back(arr2[j++]); 
    } 
   
    while (i < arr1.size()) 
        arr3.push_back(arr1[i++]); 
  
    while (j < arr2.size()) 
        arr3.push_back(arr2[j++]);
        
    return arr3;
}

vector<int> mergeKArrays(vector<vector<int> > arr) 
{ 
    vector<int> res=arr[0]; 
      
    for(int i=1;i<arr.size();i++) 
    { 
        res=mergeArrays(res,arr[i]); 
    } 

    return res;
}

int main()
{

	vector<vector<int> > arr{ { 10, 20, 30 }, 
                              { 5, 15 }, 
                              { 1, 9, 11, 18 } }; 
  
    vector<int> res = mergeKArrays(arr); 
  
    cout << "Merged array is " << endl; 
    for (auto x : res) 
        cout << x << " "; 
  
    return 0; 
}

//optimised(minheap)
#include <bits/stdc++.h>
using namespace std;

struct Triplet{
    int val,aPos,vPos;
    Triplet(int v,int ap, int vp){
        val=v;aPos=ap;vPos=vp;
    }
};

struct MyComp{
    bool operator()(Triplet &t1,Triplet &t2){
        return t1.val>t2.val;
    }
};

vector<int> mergeArr(vector<vector<int> > &arr) 
{ 
    vector<int> res; 
      
    priority_queue <Triplet, vector<Triplet>,MyComp> pq;
    
    for(int i=0;i<arr.size();i++){
        Triplet t(arr[i][0],i,0);
        pq.push(t);
    }
    
    while(pq.empty()==false){
        Triplet curr=pq.top();pq.pop();
        res.push_back(curr.val);
        int ap=curr.aPos;int vp=curr.vPos;
        if(vp+1<arr[ap].size()){
            Triplet t(arr[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
    }

    return res;
}

int main()
{

	vector<vector<int> > arr{ { 10, 20, 30 }, 
                              { 5, 15 }, 
                              { 1, 9, 11, 18 } }; 
  
    vector<int> res=mergeArr(arr);  
    cout << "Merged array is " << endl; 
    for (auto x : res) 
        cout << x << " "; 
  
    return 0; 
}
