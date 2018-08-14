#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    struct node *next;
};

// function definition for head node
node * createHeadNode( int data ){
    struct node *head = (struct node *) malloc( sizeof(struct node) );
    head -> value = data;
    head -> next = NULL;
    return head;
}

// function defintion for a linked list node
node * createLLNode( int data ){
    struct node *temp = (struct node *) malloc( sizeof(struct node) );
    temp -> value = data;
    temp -> next = NULL;
    return temp;
}

// print entire LinkedList
void printLL( struct node *head ){
    struct node *temp = head;
    while( temp != NULL ){
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// print middle element
void middleElem( struct node *head ){
    struct node *slow = head;
    struct node *fast = head;

    while( fast != NULL && fast -> next != NULL ){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    cout << slow -> value;
}

// main function
int main( void ){
    cout << "Enter the size of Linked List :" << endl;
    int n; // linked list size
    cin >> n; // read n

    cout << "Enter the elements of the Linked List :" << endl;
    int arr[n];
    
    for( int i = 0; i < n; ++i ){
        cin >> arr[i];
    }

    struct node *head = createHeadNode( arr[0] );
    struct node *temp = head;

    for ( int i = 1; i < n; ++i ){
        struct node *ptr = createLLNode( arr[i] );
        temp -> next = ptr;
        temp = ptr;
    }

    cout << "Linked List Formed :" << endl;

    printLL(head);
    middleElem(head);
}