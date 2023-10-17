#include <iostream>
using namespace std;

/* Node Single Linked List */
/*struct Node
{
    int value;
    Node *next;
};*/

/* Single Linked List */
/*class SLL
{
    Node *head;
    int length;
public:
    SLL()
    {
        length= 0;
        head=NULL;
    }
    void insert_first(int val)
    {
        // create Node
        Node* newNode = new Node(); // in heap
        newNode->value=val;
        if(head == NULL)
        {
            head = newNode;
            newNode->next=NULL;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }
        ++length;
    }
    void insert_back(int val)
    {
        // create Node
        Node* newNode = new Node(); // in heap
        newNode->value=val;
        if(head == NULL)
        {
            head = newNode;
            newNode->next=NULL;
        }
        else
        {
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            temp=newNode;
            newNode->next=NULL;
        }
        ++length;
    }
    void popFirst()
    {
        if(length == 0)
            cout<<"The List is Empty :)"<<endl;
        else if(length == 1)
        {
            delete head;
            head = NULL;
            --length;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            temp=NULL;
            --length;
        }

    }
    void popBack()
    {
        if(length == 0)
            cout<<"The List is Empty :)"<<endl;
        else if(length == 1)
        {
            delete head;
            head = NULL;
            --length;
        }
        else
        {
            Node* temp = head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next=NULL;
            --length;
        }

    }
    void popValue(int val)
    {
        if(length == 0)
            cout<<"The List is Empty :)"<<endl;
        else if(length == 1)
        {
            delete head;
            head = NULL;
            --length;
        }
        else if(head->value == val)
        {
            Node* current = head;
            head = head->next;
            delete current;
            current = NULL;
            --length;
        }
        else
        {
            Node* current = head->next;
            Node* prev = head;
            while(current != NULL)
            {
                if(current->value == val)break;
                else
                {
                    prev=current;
                    current=current->next;
                }
            }
            prev->next=current->next;
            delete current;
            current = NULL;
            --length;
        }

    }
    void Reverse()
    {
        Node *curr,*pre,*next;
        pre=NULL;
        curr=head;
        next=curr->next;
        while(next != NULL)
        {
            next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        head=pre;
        pre=NULL;

    }
    int getLength()
    {
        return length;
    }
    void print()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int Search(int key)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->value == key)
                return 1;
            temp=temp->next;
        }
        return 0;
        cout<<endl;
    }
};*/


/* Node Doubly Linked List */
struct Node2
{
    int value;
    Node2 *prev;
    Node2 *next;
};

/* Doubly Linked List */
class DLL
{
private:
    Node2* first;
    Node2* last;
    int counter;
public:
    DLL()
    {
        first = last = NULL;
        counter = 0;
    }
    void insert_first(int val)
    {
        Node2* newNode = new Node2();
        newNode->value = val;
        if(counter == 0)
        {
            first = last = newNode;
            newNode->next = newNode->prev =NULL;
            counter++;
        }
        else
        {
            newNode->next = first;
            newNode->prev=NULL;
            first->prev = newNode;
            first=newNode;
            counter++;
        }
    }
    void insert_last(int val)
    {
        Node2* newNode = new Node2();
        newNode->value = val;
        if(counter == 0)
        {
            first = last = newNode;
            newNode->next = newNode->prev =NULL;
        }
        else
        {
            newNode->prev = last;
            newNode->next = NULL;
            last->next=newNode;
            last=newNode;
            counter++;
        }
    }
    void insert_index(int index,int val)
    {
        if(index<0||index>counter)
            cout<<"out of Range :) "<<endl;
        else
        {

            if(index == 0)
                insert_first(val);
            else if (index == counter)
                insert_last(val);
            else
            {
                Node2* newNode = new Node2();
                newNode->value = val;
                Node2* curr = first;
                for(int i = 1; i<index; ++i)
                {
                    curr = curr->next;
                }

                newNode->prev = curr;
                newNode->next = curr->next;
                curr->next->prev=newNode;
                curr->next=newNode;
                counter++;
            }
        }
    }
    void delete_first()
    {
        if(counter == 0)
            cout<<"is Empty :)" <<endl;
        else if(counter == 1)
        {
            delete first;
            first = last = NULL;
            counter--;
        }
        else
        {
            Node2* curr = first;
            first = first->next;
            first->prev = NULL;
            delete curr;
            counter--;
        }
    }
    void delete_last()
    {
        if(counter == 0)
            cout<<"is Empty :)" <<endl;
        else if(counter == 1)
        {
            delete first;
            first = last = NULL;
            counter--;
        }
        else
        {
            Node2* curr = last;
            last = last->prev;
            last->next = NULL;
            delete curr;
            counter--;
        }
    }
    void delete_value(int val)
    {
        if(counter == 0)
            cout<<"is Empty :)" <<endl;
        else if(first->value == val)
            delete_first();
        else if(last->value == val)
            delete_last();
        else
        {
            Node2* curr = first->next;
            while(curr->next->next != NULL)
            {
                if(curr->value == val)
                    break;
                curr = curr->next;
            }
            if(curr->value == val)
            {
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                delete curr;
                counter--;
            }
            else
            {
                cout<<"Not Found Element :("<<endl;
            }
        }
    }
    int getLength()
    {
        return counter;
    }
    void print()
    {
        Node2* temp = first;
        while(temp != NULL)
        {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int Search(int key)
    {
        Node2* temp = first;
        while(temp != NULL)
        {
            if(temp->value == key)
                return 1;
            temp=temp->next;
        }
        return 0;
        cout<<endl;
    }

};
int main()
{
    /* Single Linked List */
    /*    SLL node;
    node.insert_first(15);
    node.insert_first(20);
    node.insert_first(30);
    node.insert_first(40);
    node.insert_first(65);
    node.insert_first(100);
    node.insert_back(333);
    node.print();
    // cout<<node.getLength()<<endl;
    //node.Reverse();
    node.print();
    // cout<<node.getLength()<<endl;
    if(node.Search(400)==0)
        cout<<"Not Found element"<<endl;
    else
        cout<<"Found element"<<endl;
    */

    /*Doubly Linked List*/
    DLL node;
    node.insert_first(15);
    node.insert_first(20);
    node.insert_first(30);
    node.insert_first(40);
    node.insert_first(65);
    node.insert_first(100);
    node.insert_last(333);
    node.insert_index(2,9999);
    cout<<node.getLength()<<endl;
    node.print();
    node.delete_first();
    node.delete_last();
    node.delete_value(15);
    cout<<node.getLength()<<endl;
    node.print();

    /* if(node.Search(100)==0)
         cout<<"Not Found element"<<endl;
     else
         cout<<"Found element"<<endl;*/
    return 0;
}
