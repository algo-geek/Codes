
#include<iostream>
#include<climits>
using namespace std;

class kQueues
{
	int *arr;
	int *front;
	int *rear;
	int *next;
	int n, k;
    int top;

	bool isFull() { return (top == -1); }

	bool isEmpty(int qn) { return (front[qn] == -1); }

public:
kQueues(int k1, int n1)
{
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

	for (int i = 0; i < k; i++)
		front[i] = -1;

	top = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 to indicate end of free list
}

void enqueue(int item, int qn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nQueue Overflow\n";
		return;
	}

	int i = top;	 // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	top = next[i];

	if (isEmpty(qn))
		front[qn] = i;
	else
		next[rear[qn]] = i;

	next[i] = -1;

	// Update next of rear and then rear for queue number 'qn'
	rear[qn] = i;

	// Put the item in array
	arr[i] = item;
}

int  dequeue(int qn)
{
	if (isEmpty(qn))
	{
		cout << "\nQueue Underflow\n";
		return INT_MAX;
	}

	// Find index of front item in queue number 'qn'
	int i = front[qn];

	front[qn] = next[i]; // Change top to store next of previous top

	// Attach the previous front to the beginning of free list
	next[i] = top;
	top = i;

	// Return the previous front item
	return arr[i];
}
};

int main()
{
	// create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// items in queue number 2
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);

	// items in queue number 1
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);

	// items in queue number 0
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

	return 0;
}
