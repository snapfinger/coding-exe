// DFS iterative
Node* cloneGraph(Node* node) {
    if(node == nullptr) return nullptr;
    unordered_map<Node*, Node*> m;
    Node* new_node = new Node(node->val);
    m[node] = new_node;
    stack<Node*> st;
    st.push(node);
    while(!st.empty()){
        Node* cur = st.top(); st.pop();
        for(auto n: cur->neighbors){
            if(m.find(n) == m.end()){
                m[n] = new Node(n->val);
                st.push(n);
            }
            m[cur]->neighbors.push_back(m[n]);
        }
    }
    return new_node;
}

// DFS recursive
Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> m;
    return helper(m, node);
}

Node* helper(unordered_map<Node*, Node*>& m, Node* node){
    if(node == nullptr) return nullptr;
    if(m.find(node)!= m.end()) return m[node];
    
    Node* new_node = new Node(node->val);
    m[node] = new_node;
    
    for(auto n: node->neighbors){
        new_node->neighbors.push_back(helper(m, n));
    }

return new_node;
}