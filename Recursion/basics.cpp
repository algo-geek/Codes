// 1
#include <iostream>
using namespace std;


void fun(int n)
{
	if(n == 0)
		return;

	cout<<n<<endl;

	fun(n - 1);
	
	cout<<n<<endl;
}
int main() {
	
	fun(3);
	
	return 0;
}
// 1 2 3

//2
#include <iostream>
using namespace std;


void fun(int n)
{
	if(n == 0)
		return;

	fun(n - 1);
	
	cout<<n<<endl;
	
	fun(n - 1);
}
int main() {
	
	fun(3);
	
	return 0;
}
// 1 2 2 3 1 2 1