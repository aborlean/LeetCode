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

    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;

        while(head) {
            ListNode* current = head->next;
            head->next = previous;
            previous = head;
            head = current;
        }

        return previous;
    }

    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* last = head;
        int sum, carry = 0;

        while(l1 || l2 || carry) {
            int first, second;
            if(l1)
                first = l1->val;
            else
                first = 0;

            if(l2)
                second = l2->val;
            else
                second = 0;

            sum = first + second + carry;
            carry = sum / 10;

            ListNode* newnode = new ListNode(sum % 10);
            last->next = newnode;
            last = last->next;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        ListNode* result = head->next;
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* result = add(l1, l2);

        return reverseList(result);
    }
};

