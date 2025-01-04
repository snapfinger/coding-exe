Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;
    Node* ptr = head;
    while(ptr){
        m[ptr] = new Node(ptr->val);
        ptr = ptr->next;
    }
    
    ptr = head;
    while(ptr){
        m[ptr]->next = m[ptr->next];
        m[ptr]->random = m[ptr->random];
        ptr = ptr->next;
    }
    
    return m[head];

}