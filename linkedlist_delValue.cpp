/*
author: kshruti
Description: Merge two sorted linked lists, in the ascending order
Time: 8ms
Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
*/
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
 };

class Solution {
    /*
    Defines functions to create, print and merge linked lists
    */
public:
    ListNode* newNode(int val);
    ListNode* removeElements(ListNode* head, int val);
    void printList(ListNode *node);
};

ListNode* Solution::newNode(int val) {
    /*
    Creates a linked list node
    @param "val": Value to be added to the linked list
    @return "n": Linked list node with value equal to argument
        specified and pointing to NULL
    */
    ListNode *n = new ListNode;
    n->val = val;
    n->next = NULL;
    return n;
}

ListNode* Solution::removeElements(ListNode* head, int val) {
    /*
    Removes all elements of a particular value from the linked list. Can
    handle if the element is the head itself, null lists, if the list contains
    only the value to be removed.
    @param "head": Head of the linked list
    @param "val": Value to be removed from the list
    @return "head": Head of the linked list with the value removed
    */
    ListNode *prev = head, *curr = head;

    if (head == NULL) return head;
    
    while (head->val == val) {
        head = head->next;
        if (!head) return head;
    }        
    
    while(curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
            curr = curr->next;
        }
        else {
            prev = curr;
            curr = curr->next;                   
        }
    }
    return head;
}

void Solution::printList(ListNode *node) {
    /*
    Prints linked list starting from the input node
    @param "node": The node from where the linked list is to be printed
    @return None: Displays the linked list.
    */
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}

int main () {
    Solution s;
    ListNode *l1, *head;

    l1 = s.newNode(1);
    head = l1;
    l1->next = s.newNode(1);
    l1 = l1->next;
    l1->next = s.newNode(3);
    l1 = l1->next;
    l1->next = s.newNode(4);
    s.printList(head);
    head = s.removeElements(head, 1);
    s.printList(head);

    l1 = s.newNode(1);
    head = l1;
    l1->next = s.newNode(2);
    l1 = l1->next;
    l1->next = s.newNode(3);
    l1 = l1->next;
    l1->next = s.newNode(3);
    s.printList(head);
    head = s.removeElements(head, 3);
    s.printList(head);
 
    l1 = s.newNode(1);
    head = l1;
    l1->next = s.newNode(1);
    l1 = l1->next;
    l1->next = s.newNode(1);
    l1 = l1->next;
    l1->next = s.newNode(1);
    s.printList(head);
    head = s.removeElements(head, 1);
    s.printList(head);
}