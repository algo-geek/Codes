//naive
int getWater(int arr[], int n)
{
	int res = 0;
	for(int i = 1; i < n - 1; i++)
	{
		int lMax = arr[i];
		for(int j = 0; j < i; j++)
			lMax = max(lMax, arr[j]);

		int rMax = arr[i];
		for(int j = i + 1; j < n; j++)
			rMax = max(rMax, arr[j]);

		res = res + (min(lMax, rMax) - arr[i]);
	}
	return res;
}

//efficient //space: O(n)
int getWater(int arr[], int n)
{
    int left[n];
    int right[n];
 
    int water = 0;
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 

    for (int i = 1; i < n-1; i++)
    {
      int var=min(left[i-1],right[i+1]);
      if(var > arr[i])
      {
        water += var - arr[i];
      }
    }
    return water;
}

// O(1) space
	int trap(vector<int>& height) {
        int n=height.size(), i=1, j=n-2, prefixmax=height[0], suffixmax=height[n-1];
        int ans=0;
        while(i<=j){
            if(prefixmax<=suffixmax){
                if(height[i]<=prefixmax){
                    ans+=prefixmax-height[i];
                }
                else{
                    prefixmax=height[i];
                }
                i++;
            }
            else{
                if(height[j]<suffixmax){
                    ans+=suffixmax-height[j];
                }
                else{
                    suffixmax=height[j];
                }
                j--;
            }
        }
        return ans;
    }
