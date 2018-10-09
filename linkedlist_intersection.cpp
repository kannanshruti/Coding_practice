/*
Author: kshruti
Description: Returns node where 2 linked lists intersect, otherwise returns NULL
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
Time: 24 ms
*/

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
 };

class Solution {
    /*
    Defines functions to create, print and run operations in linkedlists
    */
public:
    ListNode* newNode(int val);
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);
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

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
	/*
	Returns the node of intersection between two linked lists, NULL if no
	intersection
	@param "headA": Head node of the first list
	@param "headB": Head node of the second list
	@return "temp1"/ NULL: Node of intersection/ NULL pointer in case of no
		intersection
	*/
    if (!headA || !headB) return NULL;
    ListNode *temp1 = headA, *temp2 = headB;
    
    while (temp1 && temp2 && temp1 != temp2) {
    	// If both lists are at the end and no intersection has been found
        if (!temp1->next && !temp2->next) return NULL;
        
        // If one list has ended, init it to the head of the other list
        if (temp1->next) temp1 = temp1->next;
        else temp1 = headB;
        if (temp2->next) temp2 = temp2->next;
        else temp2 = headA;
    }
    return temp1;
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
    ListNode *l1, *head1, *l2, *head2;
    ListNode *inter_node, *common_node1;

    l1 = s.newNode(1);
    head1 = l1;
    l1->next = s.newNode(2);
    l1 = l1->next;
    inter_node = s.newNode(9);
    l1->next = inter_node;
    common_node1 = s.newNode(4) ;
    l1 = l1->next;
    l1->next = common_node1;
    s.printList(head1);

    l2 = s.newNode(6);
    head2 = l2;
    l2->next = s.newNode(5);
    l2 = l2->next;
    l2->next = inter_node;
    l2 = l2->next;
    l2->next = common_node1;
    s.printList(head2);

    ListNode *node = s.getIntersectionNode(head1, head2);
    if (node) cout << "Node of intersection:" << node->val << "\n";
    else cout << "No intersection.\n";

    l1 = s.newNode(1);
    head1 = l1;
    inter_node = s.newNode(9);
    l1->next = inter_node;
    common_node1 = s.newNode(4) ;
    l1 = l1->next;
    l1->next = common_node1;
    s.printList(head1);

    l2 = s.newNode(6);
    head2 = l2;
    l2->next = s.newNode(5);
    l2 = l2->next;
    l2->next = inter_node;
    l2 = l2->next;
    l2->next = common_node1;
    s.printList(head2);

    node = s.getIntersectionNode(head1, head2);
    if (node) cout << "Node of intersection:" << node->val << "\n";
    else cout << "No intersection.\n";

    inter_node = s.newNode(9);
    head1 = inter_node;
    l1->next = inter_node;
    common_node1 = s.newNode(4) ;
    l1 = l1->next;
    l1->next = common_node1;
    s.printList(head1);

    l2 = s.newNode(6);
    head2 = l2;
    l2->next = s.newNode(5);
    l2 = l2->next;
    l2->next = inter_node;
    l2 = l2->next;
    l2->next = common_node1;
    s.printList(head2);

    node = s.getIntersectionNode(head1, head2);
    if (node) cout << "Node of intersection:" << node->val << "\n";
    else cout << "No intersection.\n";
}
