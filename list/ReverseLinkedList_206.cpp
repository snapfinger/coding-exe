// TODO: recursive

// 1: Iterative sol
// TC: O(n)
// SC: O(1)
ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while(cur != nullptr){
        ListNode *next = cur->next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}