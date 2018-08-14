#include<bits/stdc++.h>
#include "create_linkedlist.cpp"
using namespace std;

// reverse the Linked List
node * reverseLL( struct node *head ){
    if( head == NULL ) return NULL;
    else{
        node *prev = NULL;
        node *curr = head;
        node *temp = head -> next;

        while( temp != NULL ){
            curr -> next = prev;
            prev = curr;
            curr = temp;
            temp = temp -> next;
        }

        curr -> next = prev;
        head = curr;
        return head;
    }
}

// main function
int main(void)
{
    int n; // No. of elements of LinkedList
    cout << "Enter the no. of elements of LinkedList";
    cin >> n;

    // declaring an array
    int arr[n];
    // reading array elements
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // creating head node
    struct node *head = CreateHeadNode(arr[0]);
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

    cout << "Before Reversing the LinkedList :" << endl;
    printLL(head);
    cout << endl;
    cout << "After Reversing the LinkedList :" << endl;
    node *ptr = reverseLL(head);
    printLL(ptr);
    cout << endl;
}