// 1
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int>dq;
    
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    
    for(auto i: dq)
    cout<<i<<" ";
    
    cout<<endl;
    
    dq.pop_back();
    dq.pop_front();
    
    for(auto i: dq)
    cout<<i<<" ";
    
    cout<<endl;
    
    cout<<dq.size()<<endl;
    
}

// 2
#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
#include <deque>
using namespace std;


int main()
{
	deque<int> dq = {10, 15, 30, 5, 12};

	auto it = dq.begin();

	it++;

	dq.insert(it, 20);

	dq.pop_front();
	dq.pop_back();

	cout<<dq.size();


	return 0;
}

// 3
#include <bits/stdc++.h> 
using namespace std;


int main()
{
	deque<int> dq = {10, 20, 5, 30};

	auto it = dq.begin();

	it = dq.insert(it, 7);

	it = dq.insert(it, 2, 3);

	it = dq.erase(it + 1);

	cout << (*it) << endl;

	for(int i = 0; i < dq.size(); i++)
		cout<<dq[i]<<" ";


	return 0;
}