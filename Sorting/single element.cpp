// every ele other than one occurs twice 

// if mid is even, then it's duplicate should be in next index.
// or if mid is odd, then it's duplicate  should be in previous index.
// check these two conditions, 
// if any of the conditions is satisfied,
// then pattern is not missed, 
// so check in next half of the array. i.e, left = mid + 1

// efficient // O(log n)
        int findSingleElement(vector < int > & nums) 
        {
            int n=nums.size();
            int low = 0;
            int high = n - 2;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                
                if (mid % 2 == 0) {
                    if (nums[mid] != nums[mid + 1]) 

                        high = mid - 1; 
                    else
                        low = mid + 1; 
                } else {

                    if (nums[mid] == nums[mid + 1]) 
                        high = mid - 1; 
                    else
                        low = mid + 1; 
                }
            }

            return nums[low];
        }

int main() {
    Solution obj;
    vector < int > v {1,1,2,3,3,4,4,8,8};

    int elem = obj.findSingleElement(v);
    cout << "The single occurring element is " << elem << endl;

}
