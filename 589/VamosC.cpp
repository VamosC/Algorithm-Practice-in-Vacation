/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> sp;
        vector<int> res;
        Node* p;
        sp.push(root);
        while(sp.size() > 0) {
        	p = sp.top();
        	sp.pop();
        	if(p) {
        		res.push_back(p->val);
        		for(vector<Node*>::reverse_iterator it = p->children.rbegin(); it != p->children.rend(); it++) {
        			sp.push(*it);
        		}
        	}
        }
        return res;
    }
};