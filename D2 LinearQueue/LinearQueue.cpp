#include<iostream>

using namespace std;

class LQueue  //(liner queue)(LILO)
{
    int size,front,rear;
    int *pQueue;

public:
    LQueue()
    {
        size=0;
        pQueue=NULL;
        front=rear=-1;
    }
    
    LQueue(int s)
    {
        front=rear=-1;
        size=s;
        pQueue=new int[size];
    }

    bool isEmpty()
    {
        
        if(rear==-1 && front==-1)
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
        if(rear==size-1)
        {
            cout<<"Queue is full so can't insert element!!!!!";
            return true;
        }
        else
        {
            return false;
        }
    }

    bool enQueue(int data)
    {
        if(!isFull())
        {
                if(isEmpty())
                {
                    front=rear=0;//set zero
                }else
                {
                    rear++;
                }
                pQueue[rear]=data;
                return true;

        }
        else
        {
            return false;
        }

    }

    bool deQueue(int &x)
    {
        if(!isEmpty())
        {
            x = pQueue[front]; // queue madla front data remove hoil
            if(front == rear) //jr front and rear same aale tr tyne -1 set krych mhnje enmpty set hoil
            {
		    front=rear=-1;
                
            } 
            else
            {
                front++; //pudha jaun fornt delete honar 
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
        if(!isEmpty())
        {
		for(int i=front;i<=rear;i++)
            {
                cout<<"\t"<<pQueue[i];
            }	
             
        }else
        {
            
             cout<<"\n No Element to display \n "; 
        }
    }
    
    
    
    ~LQueue()
    {
         if(pQueue!=NULL)
       {
            delete[] pQueue;
            cout<<"Memory free now ";
       }
    }
    

};


int main()
{
    LQueue st(5);
int choice;
int data;

 while(choice!=4)
    {
        cout<<"\n\t***********Menu***********";
        cout<<"\n\t\t1.Enqueue ";
        cout<<"\n\t\t2.Dequeue";
        cout<<"\n\t\t3.Display ";
        cout<<"\n\t\t4.Exit ";
         cout<<"\n\t***********End***********";
         cout<<"\n\n";
        cout<<"\nEnter Your choice :";
        cin>>choice;
        switch (choice)
        {
        case 1:
                {
                    int data;
                    cout<<"\nEnter the data you want to insert :   ";
                    cin>>data;
                    if(st.enQueue(data))
                    {
                        cout<<"\nSuccessfully insert Data..";
                    }
                    else
                    {
                        cout<<"\nQueue is Full..";
                    }
                }
            break;
        case 2:
            {
                int data;
                    cout<<"\nEnter the data you want to popped:   ";
                    cin>>data;
                    if(st.deQueue(data))
                    {
                        cout<<"\nElement "<<data<<" is Deleted or popped..Successfully.\n\n";
                    }
                    else
                    {
                        cout<<"\nStack is Empty so can't popped";
                    }
            }
            
            break;
        case 3:
            st.display();
            break;
        case 4:
                cout<<"\nEnd the Program !!!";
            break; 
        
        default:
        cout<<"\n Invalid choice!!!! plz try again";
            break;
        }
    }




}