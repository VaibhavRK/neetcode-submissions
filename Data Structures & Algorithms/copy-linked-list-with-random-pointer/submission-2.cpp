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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*,Node*> mp;

        Node* newHead = new Node(head->val);
        Node* t2 = newHead;
        Node* t1 = head->next;

        mp[head] = newHead;
        while(t1 != NULL){
            Node* node = new Node(t1->val);
            t2->next = node;
            t2 = t2->next;
            mp[t1] = t2;
            t1 = t1->next;
        }

        t1 = head;
        t2 = newHead;

        while(t1 != NULL){
            if (t1->random != NULL) {
                t2->random = mp[t1->random];
            } else {
                t2->random = NULL;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        return newHead;
    }
};
