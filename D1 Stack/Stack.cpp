#include<iostream>
using namespace std;

class Stack
{
    int size,top;
    int *pstack;    //for dynamaic memory allocation
public:
    Stack() //construcotr
    {
        top=-1;
        size=0;        
        pstack=NULL;
    }

    Stack(int s)//para- construcotr
    {
        top=-1;
        size=s;
        pstack=new int[size];
    }

    bool push(int data)  //insert elelment
    {  
         if(isfull())
        {
            return false; //not insert 
        }
        else
        { 
            pstack[++top]=data;
            return true;  //add insert 
        }
        
    }
    bool isempty()  //check stack is empty?
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isfull()   //check stack is full?
    {
        if(top==size-1)
        {
            return true;

        }
        else
        {
            return false;
        }

    }

    void Display()  //display all element 
    {
        if(isempty())
        {
            cout<<"\n No Element to display \n "; //if stack is empty!!!!
        }       
        else
        {
            cout<<"\n Element is : ";
            for(int i=top;i>=0;i--)
            {
                cout<<"\t"<<pstack[i];
            }

            cout<<"\n \n \tEnd of Display \n\n ";
        } 
    }

    bool pop(int &x)  //delete element  (x= pstar)
    {
         if(isempty())
        {
            return false;   
        }  
        else
        {
            
          //  cout<<"Element "<<x<<" Deleted ";
            return true;
            
        }
    }

    bool peek(int &t) // check what on top...
    {
        if(isempty())
        {
            return false;
        }
        else
        {   
            t = pstack[top];
            return true;

        }
    }



    ~Stack()// free the memeory on heap 
    {
       if(pstack!=NULL)
       {
            delete[] pstack;
            cout<<"Memory free now ";
       }

    }

};

int main () /main function 
{ 
    int choice; //for menu
    Stack st(5);

    while(choice!=4)
    {
        cout<<"\n\t***********Menu***********";
        cout<<"\n\t\t1.Push ";
        cout<<"\n\t\t2.Pop ";
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
                    if(st.push(data))
                    {
                        cout<<"\nSuccessfully insert Data..";
                    }
                    else
                    {
                        cout<<"\nStack is Full..";
                    }
                }
            break;
        case 2:
            {
                int data;
                    cout<<"\nEnter the data you want to popped:   ";
                    cin>>data;
                    if(st.pop(data))
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
            st.Display();
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
