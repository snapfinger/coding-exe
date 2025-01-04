// Leetcode 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// Example 1:
// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// Example 2:
// Input: head = [], val = 1
// Output: []

// Example 3:
// Input: head = [7,7,7,7], val = 7
// Output: []
 

// Constraints:
// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50

#include "common_headers.h"

// Time complexity: O(n) (n: number of nodes in the list)
// Space complexity: O(1)
ListNode* removeElements(ListNode* head, int val) {
    if(head == nullptr) return head;

    ListNode* to_delete;
    while(head != nullptr && head->val == val){
        to_delete = head;
        head = head -> next;
        delete to_delete;
    }

    ListNode* cur = head;
    while(cur != nullptr && cur->next != nullptr){
        if(cur->next->val == val){
            to_delete = cur->next;
            cur->next = cur->next->next;
            delete to_delete;
        }else{
            cur = cur->next;          
        }
    }

    return head;
}
