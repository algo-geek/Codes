// naive // time: theta(n^2) // space: o(n)
#include <bits/stdc++.h> 
using namespace std; 

bool areRotations(string s1,string s2){
    if(s1.length()!=s2.length())return false;
    return ((s1+s1).find(s2)!=string::npos);
}
 
int main() 
{ 
    string s1 = "ABCD";string s2="CDAB";
    if(areRotations(s1,s2)){cout<<"Strings are rotations of each other"<<endl;}
    else{cout<<"Strings are not rotations of each other"<<endl;}
    
    return 0; 
} 

// efficient // time & space: O(n)
#include <bits/stdc++.h>
using namespace std;
bool check_rotation(string s, string goal)
{
	if (s.size() != goal.size())
		return false;

	queue<char> q1;
	for (int i = 0; i < s.size(); i++) {
		q1.push(s[i]);
	}

	queue<char> q2;
	for (int i = 0; i < goal.size(); i++) {
		q2.push(goal[i]);
	}

	int k = goal.size();
	while (k--) 
    {
		char ch = q2.front();
		q2.pop();
		q2.push(ch);
		if (q2 == q1)
			return true;
	}
	return false;
}
int main()
{
	string s1 = "ABCD";
	string s2 = "CDAB";
	if (check_rotation(s1, s2))
		cout << s2 << " is a rotated form of " << s1
			<< endl;
	else
		cout << s2 << " is not a rotated form of " << s1
			<< endl;
	string s3 = "ACBD";
	if (check_rotation(s1, s3))
		cout << s3 << " is a rotated form of " << s1
			<< endl;
	else
		cout << s3 << " is not a rotated form of " << s1
			<< endl;
	return 0;
}

