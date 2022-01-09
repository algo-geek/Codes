  
#include <iostream>
using namespace std;
  
int main() 
{
    string s = "@Apara#@xrf";
  
    for (int i = 0;i < s.size(); i++)
    {
        if (ispunct(s[i]))
            s.erase(i--, 1);
 
    }
     cout << s;

}