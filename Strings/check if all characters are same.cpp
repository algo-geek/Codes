#include <iostream>
using namespace std;
 
bool allCharactersSame(string s)
{
    return (s.find_first_not_of(s[0]) == string::npos);
}
 
// Driver code
int main()
{
    string s = "aaa";
    if (allCharactersSame(s))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}