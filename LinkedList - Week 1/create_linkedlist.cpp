/* Create a Simple Linkedlist for a given list of numbers. 
Hint: Assume these numbers are in a array or a list
 */

#include<bits/stdc++.h>
using namespace std;

// strcuture for a singly List Node
struct node{
    int value;
    struct node *next;
};

// function definition for head node of the LL
node * CreateHeadNode( int data ){
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head -> value = data;
    head -> next = NULL;
    return head;
}

// function definition for other nodes of the LL
node * CreateNode( int data ){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> value = data;
    temp -> next = NULL;
    return temp;
}

// print the Linked List
void printLL( struct node *head ){
    struct node *temp = head;
    while( temp != NULL ){
        cout << temp -> value << " ";
        temp = temp -> next;
    }
}

// // main function
// int main(void){
//     int n; // No. of elements of LinkedList
//     cout << "Enter the no. of elements of LinkedList";
//     cin >> n;

//     // declaring an array
//     int arr[n];
//     // reading array elements
//     for ( int i = 0; i < n; ++i ){
//         cin >> arr[i];
//     }
    
//     // creating head node
//     struct node *head = CreateHeadNode( arr[0] );
//     /* A temporary pointer pointing to start of the LL i.e head position. It is a general assumption that 
//     we are not supposed to alter the head pointer of the LL as we may loose the track of the starting address of the Linkedlist
//     */
//     struct node *temp = head;
//     // creating the further LL
//     for ( int i = 1; i < n; ++i ){
//         struct node *ptr = CreateNode( arr[i] );
//         temp -> next = ptr;
//         temp = ptr;
//     }

//     printLL( head );
// }