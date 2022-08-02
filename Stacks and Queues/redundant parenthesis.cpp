#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    stack<char>st;
    
    bool ans=false;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='(')
            {
                ans=true;
            }
            while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/')
            {
                st.pop();
            }
            st.pop();
        }
    }
    
    cout<<ans<<endl;
}

// ((a+b)) -> redundant (1)
// (a+(b-c))  -> not redundant (0)

// O(n) & O(1)
#include <bits/stdc++.h>
using namespace std;

bool IsRedundantBraces(string A)
{
	int a = 0, b = 0;
	for (int i = 0; i < A.size(); i++) {
		if (i + 2 < A.size() && A[i] == '(' && A[i + 2] == ')')
			return 1;
		if (A[i] == '*' || A[i] == '+' || A[i] == '-' || A[i] == '/')
			a++;
		if (A[i] == '(')
			b++;
	}
	if (b > a)
		return 1;
	return 0;
}

int main()
{
	string A = "(((a+b) + c) + d)";
	if (IsRedundantBraces(A)) {
		cout << "YES\n";
	}
	else {
		cout << "NO";
	}
}
