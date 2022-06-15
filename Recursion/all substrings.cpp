// 1
#include <bits/stdc++.h>
using namespace std;

void subseq(string s, string ans)
{
    if(s.size()==0)
    {cout<<ans<<endl;// c "" //
    return;}
    
    char ch=s[0];//a b c
    string ros=s.substr(1);//bc c
    
    subseq(ros, ans);
    subseq(ros, ans+ch);
}

int main()
{
    subseq("ABC", "");
}

// 2
#include <iostream>
using namespace std;


void printSub(string str, string curr, int index)
{
	if(index == str.length())
	{
		cout<<curr<<" ";
		return;
	}

	printSub(str, curr, index + 1);
	printSub(str, curr+str[index], index + 1);
}
	
int main() {
	
	string str = "ABC";
    	
    printSub(str, "", 0);
	
	return 0;
}