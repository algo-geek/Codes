// check if s2 is a subsequence of s1

// naive time: O(n* 2^n)

// efficient iterative // O(n+m)
#include <bits/stdc++.h>
using namespace std;

bool isSubSeq(string s1, string s2, int n, int m)
{
    int j = 0;
    
    for(int i = 0; i < n && j < m; i++){
        if(s1[i] == s2[j])
        j++;
    }
    
    return j == m;
}

int main() {
	int n,m;
	string s1, s2;
	cin>>n>>m;
	cin>>s1>>s2;
	
	cout<<boolalpha<<isSubSeq(s1, s2, n, m);
	
	return 0;
}

// recursive // O(n+m)
#include <bits/stdc++.h>
using namespace std;

bool isSubSeq(string s1, string s2, int n, int m){
    if ( n == 0 )
        return true;
        
    if ( m == 0 )
        return false;
    
    if ( s1[n-1] == s2[m-1] )
        return isSubSeq(s1, s2, n-1, m-1);
    
    else
        return isSubSeq(s1, s2, n, m-1);
}

int main() {
	int n,m;
	string s1, s2;
	cin>>n>>m;
	cin>>s1>>s2;
	
	cout<<boolalpha<<isSubSeq(s1, s2, n, m);
	
	return 0;
}
