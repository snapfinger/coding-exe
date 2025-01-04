// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:
// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* pre = head;
    for(int i = 1; i < left - 1; i++){
        pre = pre -> next;
    }

    ListNode* cur = pre -> next;

    for(int i = left; i < right; i++){
        ListNode* cur_head = cur;
        ListNode* next_node = cur -> next;
        if(i == left){
            cur -> next = nullptr;
        }else{
            
        }
        prev -> next = cur_head;
        cur = next_node;
    }

    return head;

}