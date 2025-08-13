// pop: O(1)- take 2 queues
// push new item to q2 then move all prev items to q2 
// q1=q2 (using temp queue)
// pop from q1
#include <bits/stdc++.h>
using namespace std;

class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    
    public:
    Stack(){   //stack constructor
        n=0;
    }
    
    void push(int val){
        q2.push(val);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int>temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    void pop(){
        q1.pop();
        n--;
    }
    
    int top(){
        return q1.front();
    }
    
    int size(){
        return n;
    }
    
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
}

// push: O(1)

#include <bits/stdc++.h>
using namespace std;

class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    
    public:
    Stack(){   //stack constructor
        n=0;
    }
    
    void push(int val){
        q1.push(val);
        n++;
    }
    
    void pop(){
        if(q1.empty())
        {
            return;
        }
        
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.pop();
        n--;
        
        queue<int>temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int top(){
        if(q1.empty())
        {
            return -1;
        }
        
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        int ans = q1.front();
        q2.push(ans);
        
        queue<int>temp = q1;
        q1 = q2;
        q2 = temp;
        
        return ans;
    }
    
    int size(){
        return n;
    }
    
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
}

// recursive // pop: O(1)
#include <bits/stdc++.h>
using namespace std;

class Stack2 {

	queue<int> q;

public:
void push(int data)
{
	// Get previous size of queue
	int s = q.size();

	// Push the current element
	q.push(data);

	// Pop all the previous elements and put them after current element
	for (int i = 0; i < s; i++) 
	{
		q.push(q.front());
		q.pop();
	}
}

void pop()
{
	if (q.empty())
		cout << "No elements\n";
	else
		q.pop();
}

int top() 
{
    return (q.empty()) ? -1 : q.front(); 
}

bool empty() 
{ 
    return (q.empty()); 
}
};

int main()
{
	Stack2 st;
	st.push(40);
	st.push(50);
	st.push(70);
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	st.push(80);
	st.push(90);
	st.push(100);
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	return 0;
}
