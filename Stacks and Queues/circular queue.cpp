// array implementation

#include<bits/stdc++.h>
using namespace std;

class Queue
{
	int rear, front;
	int size;
	int *arr;
public:

	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}


void enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||
			(rear == (front-1)%(size-1)))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) /* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

int deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

void displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

};

int main()
{
	Queue q(5);

	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	q.displayQueue();

	printf("\nDeleted value = %d", q.deQueue());
	printf("\nDeleted value = %d", q.deQueue());

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}

// linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* link;
};

struct Queue2 {
	struct Node *front, *rear;
};

void enQueue(Queue2* q, int value)
{
	struct Node* temp = new Node;
	temp->data = value;
	if (q->front == NULL)
		q->front = temp;
	else
		q->rear->link = temp;

	q->rear = temp;
	q->rear->link = q->front;
}

int deQueue(Queue2* q)
{
	if (q->front == NULL) {
		printf("Queue is empty");
		return INT_MIN;
	}

	// If this is the last node to be deleted
	int value; // Value to be dequeued
	if (q->front == q->rear) {
		value = q->front->data;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else // There are more than one nodes
	{
		struct Node* temp = q->front;
		value = temp->data;
		q->front = q->front->link;
		q->rear->link = q->front;
		free(temp);
	}

	return value;
}

void displayQueue(struct Queue2* q)
{
	struct Node* temp = q->front;
	printf("\nElements in Circular Queue are: ");
	while (temp->link != q->front) {
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("%d", temp->data);
}


int main()
{
	Queue2* q = new Queue2;
	q->front = q->rear = NULL;

	enQueue(q, 14);
	enQueue(q, 22);
	enQueue(q, 6);

	displayQueue(q);

	printf("\nDeleted value = %d", deQueue(q));
	printf("\nDeleted value = %d", deQueue(q));

	displayQueue(q);

	enQueue(q, 9);
	enQueue(q, 20);
	displayQueue(q);

	return 0;
}
