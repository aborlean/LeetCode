/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* aux = head;

        while(aux) {
            v.push_back(aux);
            aux = aux->next;
        }

        int i = 0, j = v.size() - 1;

        head = v[i];
        i++;
        head->next = v[j];
        aux = head->next;

        while(i < j) {
            aux->next = v[i];
            aux = aux->next;
            j--;
            aux->next = v[j];
            aux = aux->next;
            i++;
        }
        aux->next = NULL;
    }
};