//  return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]

#include <bits/stdc++.h>
using namespace std;

void find3Numbers(vector<int>& nums) 
{
  
  if (nums.size() < 3){
    cout << "No such triplet found";
    return;
  }
  
  // track best sequence length 
  // (not current sequence length)
  int seq = 1;        

  int min_num = nums[0];  
  
  // least max number in best sequence 
  // i.e. track arr[j] (e.g. in 
  // array {1, 5, 3} our best sequence 
  // would be {1, 3} with arr[j] = 3)
  int max_seq = INT_MAX;      
  
  // save arr[i]
  int store_min = min_num;   
  
  // Iterate from 1 to nums.size()
  for (int i = 1; i < nums.size(); i++) 
  {
    if (nums[i] == min_num)
      continue;
    
    else if (nums[i] < min_num) 
    {
      min_num = nums[i];
      continue;
    } 
    
    // this condition is only hit 
    // when current sequence size is 2
    else if (nums[i] < max_seq) {    
      
      // update best sequence max number 
      // to a smaller value 
      // (i.e. we've found a 
      // smaller value for arr[j])
      max_seq = nums[i];       
      
      // store best sequence start value 
      // i.e. arr[i]
      store_min = min_num;            
    } 
    
    // Increase best sequence length & 
    // save next number in our triplet
    else if (nums[i] > max_seq) 
    {
      // We've found our arr[k]    
        cout << "Triplet: " << store_min << 
                 ", " << max_seq << ", " << 
                           nums[i] << endl;
        return;
    }
  }

  cout << "No such triplet found";
}

int main() {
  vector<int> nums {1,2,-1,7,5};
  
  find3Numbers(nums);
}


//complexity- O(n)
