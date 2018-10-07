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
    ListNode* deleteDuplicates(ListNode* head);
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

ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode *curr = head, *prev = head, *next;

    if (head == NULL || head->next == NULL) {
        return head;
    }
    while (curr->next != NULL) {
        if (curr->next->val == curr->val) {
            curr->next = curr->next->next;
        }
        else {
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

    head = s.deleteDuplicates(head);
    s.printList(head);
}