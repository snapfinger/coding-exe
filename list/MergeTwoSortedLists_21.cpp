// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include "../common_headers.h"

// Solution 2: iterative
// Time: O(n)
// Space: O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while(list1 && list2){
        ListNode* next1 = list1->next;
        ListNode* next2 = list2->next;
        if(list1->val < list2->val){
            cur->next = list1;
            list1 = next1;
        }else{
            cur->next = list2;
            list2 = next2;
        }
        cur = cur->next;
    }
    
    if(list1) cur->next = list1;
    if(list2) cur->next = list2;
    return dummy->next;
}


// Solution 1: recursive
// Time: O(n)
// Space: O(log n) ?
ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->val < list2->val){
        list1->next = mergeTwoLists2(list1->next, list2);
        return list1;
    }else{
        list2->next = mergeTwoLists2(list1, list2->next);
        return list2;
    }
}

int main(){
    ListNode p1 = ListNode(1);
    ListNode p2 = ListNode(2);
    ListNode p3 = ListNode(3);
    ListNode p4 = ListNode(4);
    ListNode p5 = ListNode(5);

    p1.next = &p2;
    p2.next = &p3;

    p4.next = &p5;

    ListNode* list1 = &p1;
    ListNode* list2 = &p4;

    ListNode* merged_list = mergeTwoLists(list1, list2);
    ListNode* cur = merged_list;

    while(cur){
        cout << (*cur).val << " ";
        cur = cur->next;
    }

    cout << endl;
}