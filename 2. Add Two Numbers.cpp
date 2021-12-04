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
        int sum,carry=0;
        ListNode *l3= nullptr, *head= nullptr;
        while(l1!=nullptr || l2!=nullptr || carry){
            int x= l1?l1->val:0;
            int y= l2?l2->val:0;
            sum = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            
            if(l3){
                l3->next= new ListNode(sum);
                l3= l3->next;
            } else{
                l3= new ListNode(sum);
                head= l3;
            }
            
            l1= (l1!=NULL)?l1->next:NULL;
            l2= (l2!=NULL)?l2->next:NULL;
        }
        return head;
    }
};