// recursive
#include <bits/stdc++.h> 
#include <queue>
using namespace std; 


void Print(queue<int>& Queue) 
{ 
	while (!Queue.empty()) { 
		cout << Queue.front() << " "; 
		Queue.pop(); 
	} 
} 


void reverse(queue<int>& q) 
{ 
	if(q.empty())
	   return;
	   
	int x = q.front();
	 q.pop();
	   
   reverse(q);
   q.push(x);
} 

 
int main() 
{ 
	queue<int> q; 
	q.push(12); 
	q.push(5); 
	q.push(15);
	q.push(20); 

	reverse(q); 
	Print(q); 
} 


// iterative // stack // O(n)
#include <bits/stdc++.h> 
#include <queue>
using namespace std; 


void Print(queue<int>& Queue) 
{ 
	while (!Queue.empty()) { 
		cout << Queue.front() << " "; 
		Queue.pop(); 
	} 
} 


void reverseQueue(queue<int>& Queue) 
{ 
	stack<int> Stack; 
	while (!Queue.empty()) { 
		Stack.push(Queue.front()); 
		Queue.pop(); 
	} 
	while (!Stack.empty()) { 
		Queue.push(Stack.top()); 
		Stack.pop(); 
	} 
} 

 
int main() 
{ 
	queue<int> q; 
	q.push(12); 
	q.push(5); 
	q.push(15);
	q.push(20); 

	reverseQueue(q); 
	Print(q); 
} 

// queue // O(n^2)
#include <bits/stdc++.h>
using namespace std;

queue<int> reverse2(queue<int> q)
{
	int s = q.size();
	queue<int> ans;

	for (int i = 0; i < s; i++) {

		for (int j = 0; j < q.size() - 1; j++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}

		// Get the last element and
		// add it to the new queue
		ans.push(q.front());
		q.pop();
	}
	return ans;
}

int main()
{
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	q = reverse2(q);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}
