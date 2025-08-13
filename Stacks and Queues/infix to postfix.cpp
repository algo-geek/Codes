// infix:	  (A + B) * C	
// postfix:   A B + C *	
// prefix:    * + A B C

#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prec(char c)
{
    if(c=='^')
    return 3;
    
    else if(c=='*' || c=='/')
    return 2;
    
    else if(c=='+' || c=='-')
    return 1;
    
    else
    return -1;
}

// Operands (letters):
// ➜ Directly added to the result (res).

// Left Parenthesis (:
// ➜ Pushed to the stack.

// Right Parenthesis ):
// ➜ Pop from the stack to the result until ( is found -then discard (.

// Operators (+, -, *, /, etc.):
// ➜ While the top of the stack has higher or equal precedence, pop it to the result.
// ➜ Then push the current operator.

// End of expression:
// ➜ Pop all remaining operators from the stack to the result.
string infixToPostfix(string s)
{
    stack<char> st;
    string res;
    
    for(int i=0;i<s.size();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        res+=s[i];
        
        else if(s[i]=='(')
        st.push(s[i]);
        
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        
        else
        {
            while(!st.empty() && prec(st.top())>=prec(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    
    return res;
}


int main()
{
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
}
