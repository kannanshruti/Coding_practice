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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
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

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    /*
    Merges two sorted lists in the ascending order. Can handle uneven
       length lists.
    @param "l1": First list (sorted in ascending order)
    @param "l2": Second list (sorted in ascending order)
    @return "head": Head of the combined sorted linked list
    */
    ListNode *head, *tail, *temp1 = l1, *temp2 = l2;
    int flag = 0;
    
    // If either list is empty
    if (!l1) return l2;
    if (!l2) return l1;

    // Defining the head of the combined linked list
    if (l1->val <= l2->val) {
        head = l1;
        l1 = l1->next;
    }
    else {
        head = l2;
        l2 = l2->next;
    }
    tail = head;

    // Combining the lists
    while (l1 || l2) {
        // If neither list is empty
        if(l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        // If l2 is empty, adding the remaining elements of l1
        else if (l1 != NULL) {
            while (l1 != NULL) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
        }
        // If l1 is empty, adding the remaining elements of l2
        else if (l2 != NULL) {
            while (l2 != NULL) {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
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
    ListNode *l1, *l2, *head1, *head2, *head;

    l1 = s.newNode(1);
    head1 = l1;
    l1->next = s.newNode(2);
    l1 = l1->next;
    l1->next = s.newNode(4);
    s.printList(head1);

    l2 = s.newNode(1);
    head2 = l2;
    l2->next = s.newNode(3);
    l2 = l2->next;
    l2->next = s.newNode(4);
    s.printList(head2);

    head = s.mergeTwoLists(head1, head2);
    s.printList(head);
}