#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next, *prev;

public:
    
    Node(int d)
    {
        data = d;
        next = prev = NULL;
    }
    int getdata()
    {
        return data;
    }
    Node *getnext()
    {
        return next;
    }
    Node *getprev()
    {
        return prev;
    }
    void setdata(int d)
    {
        this->data = d;
    }
    void setnext(Node *n)
    {
        this->next = n;
    }

    void setprev(Node *p)
    {
        this->prev = p;
    }
};

class DoublyLL
{
    Node *start;

public:
    void insertatpos(int pos, int data)
    {
        Node *temp = new Node(data);
        if (start == NULL)
        {
            start = temp;
            return;
        }

        if (pos == 1)
        {
            temp->setnext(start);
            start->setprev(temp);
            start = temp;
            return;
        }
        Node *p = start;
        int i = 1;
        while (i != pos - 1 && p->getnext() != NULL)
        {
            i++;
            p = p->getnext();
        }
        temp->setnext(p->getnext());
        p->setnext(temp);
    }

    void DeleteatPOst(int pos)
    {
        if (start == NULL)
        {
            cout << "\n No node Present here!!!!!";
            return;
        }
        Node *p = start;
        if (pos == 1)
        {
            start = start->getnext();
            if (start != NULL)
            {
                start->setprev(NULL);
            }
            cout << "\n " << p->getdata() << "is Delete.";
            delete p;
            return;
        }

        int i = 1;

        while (i != pos - 1 && p->getnext() != NULL)
        {
            i++;
            p = p->getnext();
        }
        if (i == pos)
        {
            p->getprev()->setnext(p->getnext());
            if (p->getnext() != NULL)
            {
                p->getnext()->setprev(p->getprev());
            }
            cout << "\n " << p->getdata() << "  is deleted";
            delete p;
            return;
        }
    }

    void Display()
    {
        if (start == NULL)
        {
            cout << "No Node is here to display";
        }

        Node *p = start;
        while (p != NULL)
        {
            cout << "\t" << p->getdata();
            p = p->getnext();
        }
    }
};

int main()
{

    int ch = 0;
    DoublyLL dl;
    while (ch != 4)
    {
        cout << "\n1.insert at postion";
        cout << "\n2.Delet at postion";
        cout << "\n3.Display ";
        cout << "\n4.Exit";
        cout << "\n Enter you choice:  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int Data, pos;
            cout << "\nenter the postion : ";
            cin >> pos;
            cout << "\nenter the Data";
            cin >> Data;
            dl.insertatpos(pos, Data);
        }
        break;
        case 2:
        {
            int pos;
            cout << "\nenter the postion : ";
            cin >> pos;
            dl.DeleteatPOst(pos);
        }
        break;
        case 3:
            dl.Display();
            break;
        case 4:
            cout << "\n exit..";
            break;

        default:
            break;
        }
    }
}