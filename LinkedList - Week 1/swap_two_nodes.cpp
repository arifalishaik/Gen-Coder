/* Given a Linked List you are supposed to swap two nodes
The values of two nodes are say i and j */

#include<bits/stdc++.h>
using namespace std;

// structure for a singly List Node
struct node{
    int value;
    struct node *next;
};

struct node * swap( struct node *head, int i, int j ){
    if( head == NULL ){
        cout << "Cannot be swapped" << endl;
    }
    else if( i == j ){
        cout << "Both the elements are same. No Need to Swap" << endl;
    }
    else{
        struct node *x = head;
        struct node *prevX = NULL;

        while( x != NULL && x -> value != i ){
            prevX = x;
            x = x -> next;
        }
        // cout<<x->value;
        
        struct node *y = head;
        struct node *prevY = NULL;
        while( y != NULL && y -> value != j ){
            prevY = y;
            y = y -> next;
        }
        // cout<<y->value;

        // If either of i and j are not present
        if( x == NULL || y == NULL ){
            cout << "Cannot Swap!! One element not found in the Linked List" << endl;
            exit(0);
        }
        // If x is not the head node
        if( prevX != NULL ){
            prevX -> next = y;
        }else{
            head = y;
        }

        // If y is not the head node
        if( prevY != NULL ){
            prevY -> next = x;
        }else{
            head = x;
        }

        struct node *temp = y -> next;
        y -> next = x -> next;
        x -> next = temp;
   
    }
    return head;
}

// function definition for head node of the LL
node *CreateHeadNode(int data){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->value = data;
    head->next = NULL;
    return head;
}

// function definition for other nodes of the LL
node *CreateNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = data;
    temp->next = NULL;
    return temp;
}

// print the Linked List
void printLL(struct node *head){
    struct node *temp = head;
    while (temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// main function
int main(void){
    int n; // No. of elements of LinkedList
    cout << "Enter the no. of elements of LinkedList";
    cin >> n;

    // declaring an array
    int arr[n];
    // reading array elements
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    // creating head node
    struct node *head = CreateHeadNode( arr[0] );
    /* A temporary pointer pointing to start of the LL i.e head position. It is a general assumption that 
    we are not supposed to alter the head pointer of the LL as we may loose the track of the starting address of the Linkedlist
    */
    struct node *temp = head;
    // creating the further LL
    for (int i = 1; i < n; ++i){
        struct node *ptr = CreateNode(arr[i]);
        temp->next = ptr;
        temp = ptr;
    }

    cout << "Before Swapping nodes: ";
    printLL(head);

    head = swap( head, 1, 2 );

    cout << "After Swapping Nodes: ";
    printLL(head);
}