/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// https://stackoverflow.com/questions/184710/what-is-the-difference-between-a-deep-copy-and-a-shallow-copy

//https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1059181/C%2B%2B-or-Three-Pass-or-O(n)-0ms-Beats-100-or-Explanation-(with-example)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *node = head;
        
        // STEP-1 
        while(node)
        {
            Node *temp = node->next;
            node->next = new Node(node->val);
            node->next->next = temp;
            node = temp;
        }
        
        // STEP-2
        node = head;
        while(node)
        {
            if(node->random) node->next->random = node->random->next;
            node = node->next->next;
        }
        
        Node *ans = new Node(0);
        Node *helper = ans;
        node = head;
        
        // STEP-3
        while(node)
        {
            helper->next = node->next;
            helper = helper->next;
            node->next = node->next->next;
            node = node->next;
        }
        
        return ans->next;
    }
};