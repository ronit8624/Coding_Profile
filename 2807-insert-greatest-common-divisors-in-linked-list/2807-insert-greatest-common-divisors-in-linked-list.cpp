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
    int getGCD(int a, int b) {
        if(b == 0) return a;
        return getGCD(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* temp = head;

        while(temp->next->next != nullptr) {
            ListNode* nextNode = temp->next;
            int gcd = getGCD(temp->val, nextNode->val);
            ListNode* newNode = new ListNode(gcd);

            temp->next = newNode;
            newNode->next = nextNode;

            temp = nextNode;
        }

        ListNode* nextNode = temp->next;
        int gcd = getGCD(temp->val, nextNode->val);
        ListNode* newNode = new ListNode(gcd);

        temp->next = newNode;
        newNode->next = nextNode;

        temp = nextNode;

        return head;
    }
};