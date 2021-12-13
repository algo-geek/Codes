#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int postfix(string r)
{
    stack<int>s;
    
    for(int i=0;i<r.size();i++)
    {
        if(r[i]>='0' && r[i]<='9')
        {
            s.push(r[i]-'0');
        }
        else
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            
            switch(r[i])
            {
                case '+':
                s.push(op1+op2);
                break;
                
                case '-':
                s.push(op1-op2);
                break;
                
                case '*':
                s.push(op1*op2);
                break;
                
                case '/':
                s.push(op1/op2);
                break;
                
                case '^':
                s.push(pow(op1,op2));
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    cout<<postfix("46+2/5*7+")<<endl;
}