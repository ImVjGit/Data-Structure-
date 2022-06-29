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
    void setData(int d)
    {
        this->Data = d;
    }

    void setnext(Node *n)
    {
        this->next = n;
    }
};

class CircularLinkList
{
    Node *start;

public:
    CircularLinkList()
    {
        start = NULL;
    }

    void InsertAtPostiom(int pos, int Data)
    {
        Node *temp = new Node(Data);
        if (start == NULL)
        {
            start = temp;
            start->setnext(start);
            return;
        }
        Node *p = start;
        if (pos == 1)
        {
            while (p->getnext() != start)
            {
                p = p->getnext();
            }
            p->setnext(temp);
            temp->setnext(start);
            start = temp;
            return;
        }
        int i = 1;
        while (i != pos - 1 && p->getnext() != start)
        {
            p = p->getnext();
            i++;
        }
        temp->setnext(p->getnext());
        p->setnext(temp);
    }

    void DeleteAtPostion(int pos)
    {
        if (start == NULL)
        {
            cout << "no node to delte !!";
            return;
        }
        Node *p = start;
        if (pos == 1)
        {

            if (start->getnext() == start)
            {
                delete start;
                start = NULL;
                return;
            }
            else
            {
                while (p->getnext() != start)
                {
                    p = p->getnext();
                }
                p->setnext(start->getnext());
                cout << "\n " << p->getData() << " is delelted ";
                delete start;
                start = p->getnext();
            }
        }
        else
        {
            int i = 1;
            while (i != pos - 1 && p->getnext() != start)
            {
                p = p->getnext();
                i++;
            }
            if (i == pos - 1)
            {
                Node *q = p->getnext();
                cout << "\t" << p->getData() << "is Deleted Now ";
                p->setnext(q->getnext());
                delete q;
            }
            else
            {
                cout << "invalid position ";
            }
        }
    }

    void Display()
    {
        if (start == NULL)
        {
            cout << "\n No node to present to Display ";
            return;
        }

        Node *p = start;
        while (p->getnext() != start)
        {
            cout << "\t " << p->getData();
            p = p->getnext();
        }
        cout << "\t" << p->getData();
    }
};

int main()
{
    int ch = 0;
    CircularLinkList ct;
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
            ct.InsertAtPostiom(pos, Data);
        }
        break;
        case 2:
        {
            int pos;
            cout << "\nenter the postion : ";
            cin >> pos;
            ct.DeleteAtPostion(pos);
        }
        break;
        case 3:
            ct.Display();
            break;
        case 4:
            cout << "\n exit..";
            break;

        default:
            break;
        }
    }
}