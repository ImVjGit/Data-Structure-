#include<iostream>
using namespace std;

class CircularQueue
{

	int size, front, rear;
	int *pQueue;

public:
	CircularQueue()
	{
		size = 0;
		front = rear = -1;
		pQueue = NULL;
	}

	CircularQueue(int s)
	{
		size = s;
		front = rear = -1;
		pQueue = new int[size];
	}

	~CircularQueue()
	{
		if (pQueue != NULL)
		{
			delete[] pQueue;
		}
	}

	bool isEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull()
	{
		if ((front == 0 && rear == size - 1) || (rear == front - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Enqueue(int data)
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				front = rear = 0;
			}
			else

				if (rear == size - 1)
			{
				rear = 0;
			}
			else
			{
				rear++;
			}
			pQueue[rear] = data;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DeQueue(int &x)
	{
		if (!isEmpty())
		{
			x = pQueue[front]; // store vale in x if we delet that value
			if (front == rear) // if both point one that is means queue is empty so we assign -1
			{
				front = rear = -1;
			}
			else if (front == size - 1) // if front rich on max level then its make front 0 otherwise front increment
			{
				front = 0;
			}
			else
			{
				front++;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	void display()
	{
		if (!isEmpty())
		{
			int i = front;
			while (i != rear)
			{
				cout << "\t" << pQueue[i];
				i++;
				if (i == size)
				{
					i = 0;
				}
			}
			cout << "\t" << pQueue[i]; // bcz last element cant print
		}
	}
};

int main()
{
	int ch = 0;
	CircularQueue qt(5);
	while (ch != 4)
	{
		cout << "\n1.Enqueue.";
		cout << "\n2.Dequeue.";
		cout << "\n3.Display.";
		cout << "\n4.Exit";
		cout << "\nEnter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			int data;
			cout << "\n Enter the data you want to insert :";
			cin >> data;
			if (qt.Enqueue(data))
			{
				cout << "\n Success";
			}
			else
			{
				cout << "\nQueue is Full";
			}
		}
		break;

		case 2:
		{
			int data;
			if (qt.DeQueue(data))
			{
				cout << "\n"
					 << data << "is poped";
			}
			else
			{
				cout << "\n Queue is Empty ";
			}
		}
		break;

		case 3:
			qt.display();
			break;

		case 4:
			cout << "End the Program!!";
			break;
		default:
			cout << "\nInvalid Input !!! ";
			break;
		}
	}
}