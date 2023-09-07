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
        if(!head)
            return NULL;

        unordered_map<Node*, Node*> aux;

        Node* current = head;
        while(current) {
            aux[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        while(current) {
            aux[current]->next = aux[current->next];
            aux[current]->random = aux[current->random];
            current = current->next;
        }

        return aux[head];
    }
};