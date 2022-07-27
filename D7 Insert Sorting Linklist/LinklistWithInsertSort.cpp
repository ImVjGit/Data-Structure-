#include <iostream>

using namespace std;

class Node
{
    int Data;
    Node *next; 

public:
    Node(int d)
    {
        Data = d;
        next = NULL;
    }

    int getData()
    {
        return Data;
    }

    Node *getnext()
    {
        return next;
    }

    void setData(int data)
    {
        this->Data = data;
    }
    void setnext(Node *next)
    {
        this->next = next;
    }
}; // node class end

class LinkList
{
    Node *start; // ek pointer ghetla start navcha ya mdhe next node  cha address asl and ani node mdhe data ani next node cha address asl.

public:
    LinkList()
    {
        start = NULL;
    }

    void InsertBeg(int data) // 1
    {
        Node *temp = new Node(data); // creating new node out of list
        temp->setnext(start);        // seting the next address start to temp
        start = temp;                // temp address to start
    }

    void DeleteatBegging() // 4
    {
        if (start == NULL)
        {
            cout << "No Element have list";
        }
        else
        {
            Node *p = start;      // pointer tyar kel ani to fkt starting la point kel ..so o ka data asl staring la to delete hoil
            start = p->getnext(); // p pint hot rahil;
            cout << "\n"
                 << p->getData() << " Delete...\n\n";
            delete p;
        }
    }

    void InsertEnd(int data) // 2
    {
        Node *temp = new Node(data); // el temp nava cha node kel jevha pn usr data input krl to temp mdhe yeil
        if (start == NULL)           // if there is no element the its set temp =s tart
        {
            start = temp;
            return;
        }
        else
        {
            Node *p = start;             // create one pointer at the locating at start
            while (p->getnext() != NULL) // its check the condition at last point  the p next is null
            {
                p = p->getnext(); // next node la janar jo prynt p = null yet nai ...
            }
            p->setnext(temp); // temp address  set in p
        }
    }

    void DeleteatEnd() // Delete from end 
    {
        if (start == NULL)
        {
            cout << "No Elemrnt have list ";
            return;
        }
        else
        {
            if (start->getnext() == NULL)
            {
                cout << "\n " << start->getData() << " is Delete";
                delete start;
                start = NULL;
                return;
            }
            else
            {
                Node *p = start;
                while (p->getnext()->getnext() != NULL)
                {
                    p = p->getnext();
                }
                cout << "\n " << p->getnext()->getData() << " is delete ";
                delete p->getnext();
                p->setnext(NULL);
            }
        }
    }

    void InsertAnyPosition(int pos, int data) // 3
    {
        Node *temp = new Node(data);
        if (start == NULL) // if start null asl the he run hoil
        {
            start = temp; // temp mdhe ji value enter keli ti start mdhe janar
            return;
        }
        else if (pos == 1)
        {
            temp->setnext(start); // temp chi valu ji aahe ti start la assign krnya sathi use kel ;
            start = temp;         // temp cha data start mdhe janar
            return;
        }
        else
        {
            int i = 1;
            Node *p = start;
            while (i != pos - 1 && p->getnext() != NULL)
            {
                p = p->getnext();
                i++; // i value 1,2,3, hoil  o
            }
            temp->setnext(p->getnext());
            p->setnext(temp);
        }
    }

    void DeleteAnyPosition(int pos) // 6
    {
        if (start == NULL)
        {
            cout << "No Element have list";
        }

        else if (pos == 1)
        {
            Node *p = start;
            cout << "\n " << start->getData() << "  is delete now ";
            start = p->getnext();
            delete p;
            return;
        }
        else
        {
            if (start->getnext() == NULL)
            {
                cout << "Invalid Postion!!!";
                return;
            }
            Node *p = start;
            int i = 1;
            while (i != pos - 1 && p->getnext()->getnext() != NULL)
            {
                p = p->getnext();
                i++;
            }
            if (i == pos - 1)
            {
                Node *q = p->getnext();
                p->setnext(q->getnext());
                cout << "\n " << q->getData() << " is Delete ";
                delete q;
            }
            else
            {
                cout << "Invalid option";
            }
        }
    }

    void InsertInSortedOrder(int data)
    {
        Node *temp = new Node(data);
        if (start==NULL)
        {
            start=temp;
            return;
        }
        Node *p=start;
        if(temp->getData()<p->getData())
        {
            temp->setnext(start);
            start=temp;
            return;
        }
        else if(p->getData()==NULL)
        {
            p->setnext(temp);
            return;
        }
        else{
            while(p->getnext()!=NULL)
            {
                if(temp->getData()>p->getData()&&temp->getData()<p->getnext()->getData())
                {
                    temp->setnext(p->getnext());
                    p->setnext(temp);
                    return;
                }
                else
                {
                    p=p->getnext();
                }
            }
        }
    }

    void Display() // 7
    {
        if (start == NULL)
        {
            cout << "No element have in list";
            return;
        }
        else
        {
            Node *p = start; // ek arror p nav gheun tte start la point kel
            cout << "\n Element in list : \n\n ";

            while (p != NULL) // jevha pn p ha point data la the tycha nextnode null asla ki stop hoil
            {
                cout << "\t" << p->getData(); // print data
                p = p->getnext();             // next node la janar jo prynt p = null yet nai ...
            }
            cout << "\n\t ___________________________\n\n ";
        }
    }
}; // end LL class

int main()
{
    LinkList lt;    // objeck kela tyar "lt " nav cha
    int ch = 0;     // menu mmdhe nivd krychi asle tr use kel
    while (ch != 9) // jo prynt 8 yet nai to prynt loop running hot rahil
    {
        cout << "\n\t******************** MENU ******************** ";
        cout << "\n\t\t1.Insert at Begging.";
        cout << "\n\t\t2.Insert at End.";
        cout << "\n\t\t3.Insert at Any Position.";
        cout << "\n\t\t4.Delete at Begging.";
        cout << "\n\t\t5.Delete at End.";
        cout << "\n\t\t6.Delete at any Position.";
        cout << "\n\t\t7.Display.";
        cout << "\n\t\t8.Insertinsorting  order.";
        cout<<"\n\t\t9.Exit.";
        cout << "\n\t******************** END ******************** ";
        cout << "\n\nEnter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int data;
            cout << "\n Enter the data: ";
            cin >> data;
            lt.InsertBeg(data); // object ne function call kel the on data send kel
        }
        break;
        case 2:
        {
            int data;
            cout << "\nEnter the data to add last :";
            cin >> data;
            lt.InsertEnd(data);
        }

        break;
        case 3:
        {
            lt.Display();
            int data;
            int pos;
            cout << "\nEnter the postion  :";
            cin >> pos;
            cout << "\nEnter the data to add last :";
            cin >> data;
            lt.InsertAnyPosition(pos, data);
            lt.Display();
        }

        break;
        case 4:
            lt.Display();
            lt.DeleteatBegging();

            break;
        case 5:
            lt.Display();
            lt.DeleteatEnd();

            break;
        case 6:
        {
            lt.Display();
            int data;
            int pos;
            cout << "\nEnter the postion  :";
            cin >> pos;
            lt.DeleteAnyPosition(pos);
            lt.Display();
        }

        break;
        case 7:
            lt.Display();
            break;
        case 8:
            {
                 int data;
            cout << "\nEnter the data  :";
            cin >> data;
            lt.InsertInSortedOrder(data);
            lt.Display();
            }
            break;    
        case 9:
            cout << "\n\t\t End the Program!!!\n\n";
            break;
        default:
            cout << "\nInvalid Input !!! ";
            break;
        }
    }
}
