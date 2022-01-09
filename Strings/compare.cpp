#include<iostream>
using namespace std;
  
void compareOperation(string s1, string s2)
{
    // Compares 5 characters from index number 3 of s2 with s1
    if((s2.compare(3, 5, s1)) == 0)
        cout << "Here, "<< s1 << " are " << s2;
  
    else
        cout << "Strings didn't match ";
}

int main()
{
    string s1("Geeks");
    string s2("forGeeks");
    compareOperation(s1, s2);

}