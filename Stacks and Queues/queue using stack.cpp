// push: O(1)- always push new item to s1
// pop: if s2 is empty, put all from s1 to s2, return s2 top

#include <bits/stdc++.h>
using namespace std;

class que{
    stack<int>s1;
    stack<int>s2;
    
    public:
    
    void push(int x){
        s1.push(x);
    }
    
    int pop(){
        if(s1.empty() && s2.empty())
        {
            cout<<"error"<<endl;
            return -1;
        }
        
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            
           
        }
        
         int topval=s2.top();
            s2.pop();
            return topval;
    }
    
     bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};

int main()
{
    que s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout<<s.pop()<<endl;
    
    s.push(5);
    
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
}

// pop: O(1)
#include <bits/stdc++.h>
using namespace std;

struct Queue {
	stack<int> s1, s2;

	void enQueue(int x)
	{
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(x);

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	int deQueue()
	{
		if (s1.empty()) {
			cout << "Q is Empty";
			exit(0);
		}

		int x = s1.top();
		s1.pop();
		return x;
	}
};

int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}


// recursive // push: O(1)
#include <bits/stdc++.h>
using namespace std;

class que{
    stack<int>s1;
    
    public:
    
    void push(int x){
        s1.push(x);
    }
    
    int pop(){
        if(s1.empty())
        {
            cout<<"error"<<endl;
            return -1;
        }
        
        int x=s1.top();
        s1.pop();
        
        if(s1.empty())//if only 1 element
        {
            return x;
        }
        
        int item=pop();//recursively pop all items until there is only 1 element left
        s1.push(x);// after we get result push all items popped earlier
        return item;
        
    }
    
     bool empty()
    {
        return (s1.empty());
    }
};

int main()
{
    que s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout<<s.pop()<<endl;
    
    s.push(5);
    
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
}
