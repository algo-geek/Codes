#include <iostream>
using namespace std;

#define n 100

class queuee{
    
    int* a;
    int front;
    int back;
    
    public:
    
    queuee()
    {
        a=new int[n];
        front=-1;
        back=-1;
    }
    
    void push(int x)
    {
        if(back==n-1)
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        back++;
        a[back]=x;
        
        if(front==-1)
        front++;
    }
    
    void pop()
    {
        if(front==-1 || front>back)
        {
            cout<<"no element to pop"<<endl;
            return;
        }
        front++;
    }
    
    int peek()
    {
        if(front==-1 || front>back)
        {
            cout<<"no element in queue"<<endl;
            return -1;
        }
        
        return a[front];
    }
    
    bool empty()
    {
        return (front==-1 || front>back);
    }
};

int main()
{
    queuee s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout<<s.peek()<<endl;
    s.pop();
    
    cout<<s.peek()<<endl;
    s.pop();
    
    cout<<s.peek()<<endl;
    s.pop();

    cout<<s.empty()<<endl;
    
     s.pop();
    
    cout<<s.peek()<<endl;
}

// array
#include <bits/stdc++.h> 
using namespace std; 

 
class Queue { 
public: 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 

 
Queue* createQueue(unsigned capacity) 
{ 
	Queue* queue = new Queue(); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 

	 
	queue->rear = capacity - 1; 
	queue->array = new int[( 
		queue->capacity * sizeof(int))]; 
	return queue; 
} 

 
int isFull(Queue* queue) 
{ 
	return (queue->size == queue->capacity); 
} 


int isEmpty(Queue* queue) 
{ 
	return (queue->size == 0); 
} 


void enqueue(Queue* queue, int item) 
{ 
	if (isFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) 
				% queue->capacity; 
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	cout << item << " enqueued to queue\n"; 
} 

 
int dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) 
				% queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
} 


int front(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
} 

 
int rear(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
} 

 
int main() 
{ 
	Queue* queue = createQueue(1000); 

	enqueue(queue, 10); 
	enqueue(queue, 20); 
	enqueue(queue, 30); 
	enqueue(queue, 40); 

	cout << dequeue(queue) 
		<< " dequeued from queue\n"; 

	cout << "Front item is "
		<< front(queue) << endl; 
	cout << "Rear item is "
		<< rear(queue) << endl; 

	return 0; 
} 


// linked list implementation
#include <bits/stdc++.h> 
using namespace std; 

struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue2 { 
	QNode *front, *rear; 
	Queue2() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 

		 
		QNode* temp = new QNode(x); 

		 
		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 

		 
		rear->next = temp; 
		rear = temp; 
	} 

	 
	void deQueue() 
	{ 
		 
		if (front == NULL) 
			return; 

	 
		QNode* temp = front; 
		front = front->next; 

	// last node deletion
		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
}; 


int main() 
{ 

	Queue2 q; 
	q.enQueue(10); 
	q.enQueue(20); 
	q.deQueue(); 
	q.deQueue(); 
	q.enQueue(30); 
	q.enQueue(40); 
	q.enQueue(50); 
	q.deQueue(); 
	cout << "Queue Front : " << (q.front)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data; 
} 
