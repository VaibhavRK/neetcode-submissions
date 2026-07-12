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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        int ct1 = 0, ct2 = 0;
        ListNode* temp = l1;

        while(temp != NULL){
            ct1++;
            temp = temp->next;
        }
        
        temp = l2;
        while(temp != NULL){
            ct2++;
            temp = temp->next;
        }

        if(ct1 < ct2) return addTwoNumbers(l2, l1);

        temp = l1;
        while(temp != NULL && l2 != NULL){
            int sum = temp->val + l2->val+carry;
            temp->val = sum%10;
            carry = sum/10;
            temp = temp->next;
            l2 = l2->next;
        }

        while(temp != NULL){
            int sum = temp->val + carry;
            temp->val = sum%10;
            carry = sum/10;
            temp = temp->next;
        }

        if(carry != 0){
            temp = l1;
            while(temp->next != NULL) temp = temp->next;
            temp->next = new ListNode(carry);
        }

        return l1;
    }
};
