/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mpp;

    void dfs(Node* node, Node* cloneNode) {
        for(Node* n : node->neighbors) {
            if(mpp.find(n) == mpp.end()) {
                Node* clone = new Node(n->val);
                mpp[n] = clone;
                cloneNode->neighbors.push_back(clone);
                dfs(n, clone);
            }
            else {
                cloneNode->neighbors.push_back(mpp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) 
            return NULL;
        
        Node* cloneNode = new Node(node->val);
        mpp[node] = cloneNode;

        dfs(node, cloneNode);
        
        return cloneNode;
    }
};