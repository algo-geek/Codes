//stack 
#include<bits/stdc++.h>
using namespace std;

void reverse(string s)
{
stack<string> stc;
string temp="";

for(int i=0;i<s.length();i++)
{
	if(s[i]==' ')
	{
		stc.push(temp);
	    temp="";		
	}
	else
	{
	    temp=temp+s[i];
	}

}

//for the last word of the string
stc.push(temp);

while(!stc.empty()) 
{
	temp=stc.top();
	cout<<temp<<" ";
	stc.pop();
}
cout<<endl;
}

int main()
{
string s="This is a Code";
reverse(s);
return 0;
}

// recursion
#include <bits/stdc++.h> 
using namespace std; 

void reverse(char str[],int low, int high){
    while(low<=high){
        swap(str[low],str[high]);
        low++;
        high--;
    }
}

void reverseWords(char str[],int n){
    int start=0;
    for(int end=0;end<n;end++){
        if(str[end]==' '){
            reverse(str,start,end-1);
            start=end+1;
        }
    }
    // for last word
    reverse(str,start,n-1);
    // whole string reverse
    reverse(str,0,n-1);
}
 
int main() 
{ 
    string s = "This is a Code";int n=s.length();char str[n];
    strcpy(str, s.c_str());
    cout<<"After reversing words in the string:"<<endl;
    reverseWords(str,n);
    for (int i = 0; i < n; i++) 
        cout << str[i];
    
    return 0; 
} 

// o/p: Code a is This