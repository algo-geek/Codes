// 1
#include <bits/stdc++.h> 
using namespace std;

bool myCmp(pair <int, int> a, pair <int, int> b)
{
	return (a.second < b.second);
}

int maxActivities(pair <int, int> arr[], int n)
{
	sort(arr, arr + n, myCmp);

	int prev = 0;
	int res = 1;

	for(int curr = 1; curr < n; curr++)
	{
	 
		if(arr[curr].first >= arr[prev].second)
		{
			res++;

			prev = curr;
		}
	}

	return res;
}
int main()
{
	pair <int, int> arr[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};

	int n = 3;

	cout<<maxActivities(arr, n); 

	return 0;
}

// 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>>v;
    
    int s, e;
        
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)// sort by end time
    {
        return a[1]<b[1];
    });
    
    int r=1;
    int end=v[0][1];// end of 1st activity
    
    for(int i=1;i<n;i++)
    {
        if(v[i][0]>=end)
        {
            r++;
            end=v[i][1];
        }
    }
    
    cout<<r<<endl;
}