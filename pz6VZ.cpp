#include <iostream>

using namespace std;

class DLL 
{
    struct Node
    {
        int id;
        int data;
        int accessСount;
        Node* next;
        Node* prev;
    }; 
    Node* begin = nullptr;
    Node* end = nullptr;

public:
    
    void insertBegin(int data, int id)
    {
        Node* temp = new Node;
        temp->prev = nullptr;
        temp->data = data;
        temp->id = id;
        temp->accessСount = 0;
        if (begin == nullptr)
        {
            temp->next = nullptr;
            end = temp;
        }
        else
        {
            temp->next = begin;
            begin->prev = temp;
        }
        begin = temp;
    }

    void insertEnd(int data, int id)
    {
        Node* temp = new Node;
        temp->data = data;
        temp->id = id;
        temp->accessСount = 0;
        temp->next = nullptr;
        if (end == nullptr)
        {
            temp->prev = nullptr;
            begin = end = temp;
        }
        else
        {
            temp->prev = end;
            end->next = temp;
        }
        end = temp;
    }

    void print()
    {

        if (begin == nullptr)
            cout << "Empty" << endl;
        else
        {
            cout << "id" << '\t' << "data" << '\t' << "accesscount" << endl;
            Node* temp = begin;
            while (temp)
            {
                cout << temp->id << '\t' << temp->data << '\t' << temp->accessСount << '\t' << "->" << endl;
                temp = temp->next;
            } 
            cout << "NULL" << endl;
        }
    }

    void getid(int id)
    {
        if (begin == nullptr)
            cout << "Not found" << endl;
        else
        {
            Node* temp = begin;
            while (temp)
            {
                if (temp->id == id)
                {
                    cout << "id" << '\t' << "data" << '\t' << "accesscount" << endl;
                    cout << temp->id << '\t' << temp->data << '\t' << temp->accessСount << endl;;
                    ++temp->accessСount;
                    return;
                }
                temp = temp->next;
            }
            cout << "Not found" << endl;
        }
    }

    void sortlist()
    {
        Node* node, * nodenext, * temp1, * temp2;
        bool change = true;
        while (change)
        {
            change = false;
            node = temp1 = begin;
            nodenext = node->next;

            while (nodenext)
            {
                if (node->accessСount < nodenext->accessСount)
                {
                    if (node == begin)
                        begin = nodenext;
                    else
                        temp1->next = nodenext;
                    node->next = nodenext->next;
                    nodenext->next = node;
                    temp2 = node;
                    node = nodenext;
                    nodenext = temp2;
                    change = true;
                }
                temp1 = node;
                node = node->next;
                nodenext = nodenext->next;
            }
        }
    }
};

ostream& operator << (ostream& os , DLL a) // зачем он нужен, если можно без него?
{
    os << a;
    
    os << endl;
    return os;
}


int main()
{
    
    DLL node;
    int val, id, ch;
    while (true)
    {
        cout << "1 insertBegin, 2 inseratEnd, 3 getid, 4 print, 5 exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter data \t";
            cin >> val;
            cout << "enter id \t";
            cin >> id;
            node.insertBegin(val, id);
            break;

        case 2:
            cout << "enter data \t ";
            cin >> val;
            cout << "enter id \t";
            cin >> id;
            node.insertEnd(val, id);
            break;
        case 3:
            cout << "enter id \t";
            cin >> id;
            node.getid(id);
            node.sortlist();
            break;
        case 4:
            node.print();
            break;
        case 5:
            exit(0);
        }
    }


}

