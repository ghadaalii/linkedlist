#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
public:
    int data ;
    Node *next ;
};
class linkedlist{
public:
    Node *head ;
    linkedlist() {
        head = NULL;
    }

    bool isEmpty() {
        return (head==NULL);
    }

    void insertFirst(int newvalue)
    {
        Node* newnode= new Node();
        newnode->data = newvalue;
        if (isEmpty())
        {
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }

    }

    void display() {
        Node *temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }

    int count() {
        int counter = 0;
        Node *temp = head;
        while(temp != NULL){
            counter++;
            temp = temp -> next;
        }
        return counter;
    }

    bool isfound(int key) {
        int found = false;
        Node *temp = head;
        while(temp != NULL){
            if(temp -> data == key){
                found = true;
            }
            temp = temp -> next;
        }
        return found;
    }


    void insertbefore(int item, int newvalue)
    {
        if (isEmpty())
            insertFirst(newvalue);

        if (isfound(item))
        {
            Node* newnode = new Node();
            newnode->data = newvalue;
            Node* temp = head;
            while (temp != NULL && temp->next->data != item)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            cout << "Sorry , Item Not Found \n";
        }
    }
    void append(int newvalue)
    {
        if (isEmpty())
            insertFirst(newvalue);
        else
        {
        }
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node* newnode = new Node();
        newnode->data = newvalue;
        temp->next = newnode;
        newnode->next = NULL;
    }


    void deleteStart ()
    {
        Node *temp = head;

        // if there are no nodes in Linked List can't delete
        if (isEmpty())
        {
            printf ("Linked List Empty, nothing to delete");
            return;
        }

        cout << "\nValue Deleted: " << temp->data;

        // move head to next node
        head = head->next;
        free (temp);
    }

    void deleteEnd ()
    {
        Node *temp = head;
        Node *previous;

        // Can't delete from empty Linked List
        if (isEmpty())
        {
            cout << ("Empty List, can't delete");
            return;
        }

        // if Linked List has only 1 node
        if (temp->next == NULL)
        {
            cout << "\nValue Deleted: " << head->data;
            head = NULL;
            return;
        }

        // else traverse to the last node
        while (temp->next != NULL)
        {
            // store previous link node as we need to change its next val
            previous = temp;
            temp = temp->next;
        }

        // Curr assign 2nd last node's next to Null
        previous->next = NULL;

        cout << "\nValue Deleted: " << temp->data;
        // delete the last node
        free (temp);
        // 2nd last now becomes the last node
    }

    void deletePos (int n)
    {
        Node *temp = head;
        Node *previous;


        int size = count();

        if (n < 1 || n > size)
        {
            cout << "\nEnter valid position\n";
            return;
        }

        // if first node has to be deleted
        if (n == 1)
        {
            deleteStart ();
            return;
        }

        //traverse till the nth node
        while (--n)
        {
            // store previous link as we need to change its next val
            previous = temp;
            temp = temp->next;
        }

        // previous node's next changed to nth node's next
        previous->next = temp->next;
        cout << "\nValue deleted: " << temp->data;

        free (temp);
    }
};


int main() {
    linkedlist list;
    if(list.isEmpty()){
        cout << "the list is empty :)"<< endl;
    }else{
        cout << "the list contains "<<list.count()<<endl;
    }
    int numberOfItems;
    cout << "how many items that you want to insert ? \n";
    cin >> numberOfItems;
    for(int i = 0 ; i < numberOfItems ; i++){
        int newValue;
        cout << "Enter to item to insert before the other items in the list\n";
        cin >> newValue;
        list.insertFirst(newValue);
    }
    cout << "the items in list \n";
    list.display();
    int item , newValue;
    cout << "\nEnter the item to insert before it only and new value to add\n";
    cin >> item;
    cin >> newValue;
    list.insertbefore(item,newValue);
    cout << "the items in list \n";
    list.display();
    cout << "\nEnter the value to append"<<endl;
    cin >> item;
    list.append(item);
    cout << "the items in list \n";
    list.display();
    int pos;
    cout << "\nEnter the pos that want to delete value from it\n";
    cin >> pos;
    list.deletePos(pos);
    cout << "the items in list \n";
    list.display();
}
