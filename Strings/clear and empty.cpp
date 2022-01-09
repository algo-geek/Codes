#include<iostream>
#include<string>

using namespace std;

int main()
{
    string abc = "Harry Potter";
    abc.clear();
    cout<<abc;

    if(abc.empty())
    cout<<"string is empty";
}