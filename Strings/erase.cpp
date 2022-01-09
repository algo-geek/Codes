#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1 = "abcdefghijklmnop";

    s1.erase(4, 3);
    cout<<s1<<endl;
}