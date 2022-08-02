// backtracking
// time: O(2n) // Because there are 2n combinations in The Worst Case.
// space: O(n2) // Because of the Recursive Stack of wordBreakUtil(…) function in The Worst Case.
#include <bits/stdc++.h>
using namespace std;


int dictionaryContains(string &word)
{
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango", "icecream","and",	"go","i","love","ice","cream"};
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

// check if word breaks is possible for given string

// bool wordBreak(string str)
// {
//     int size = str.size();
//      if (size == 0)  return true;
 
//     for (int i=1; i<=size; i++)
//     {
//         if (dictionaryContains( str.substr(0, i) ) &&
//             wordBreak( str.substr(i, size-i) ))
//             return true;
//     }
 
//     return false;
// }


// printing possible word breaks
void wordBreak(string str, int n, string result)
{
	for (int i=1; i<=n; i++)
	{
		string prefix = str.substr(0, i);

		if (dictionaryContains(prefix))
		{
			if (i == n)
			{
				result += prefix;
				cout << result << endl;
				return;
			}
			wordBreak(str.substr(i, n-i), n-i, result + prefix + " ");
		}
	}	
}

int main()
{

	cout << "First Test:\n";
	string s="iloveicecreamandmango";
	wordBreak(s, s.size(), "");

	cout << "\nSecond Test:\n";
	string t="ilovesamsungmobile";
	wordBreak(t, t.size(), "");
	return 0;
}


// DP // O(n^2) time // O(n) space

// check if solution exists
bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(wordDict.begin(), wordDict.end()); // store the wordDict in a set
        int n = s.length();
        vector<bool> dp(n + 1, false); // dp[i] = whether a valid word ends at index i-1 or not
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--) // move back from i
            {
                if (dp[j] == true) // a valid word ends at j-1
                {
                    string k = s.substr(j, i - j); // substring from index=j to index=i-1
                    // k = new invalid word sequence (s[j..i-1]), if we find it in st we declare it as a valid word
                    if (st.find(k) != st.end())
                    {
                        dp[i] = true;
                        break; // move to the next i
                    }
                }
            }
        }
        return dp[n]; // whether a valid word ends at n-1 or not
    }