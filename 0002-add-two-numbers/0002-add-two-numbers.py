# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
        dummy = ListNode(-1)
        curr = dummy
        carry = 0

        while l1 is not None or l2 is not None or carry != 0:
            total = carry

            if l1 is not None:
                total += l1.val
                l1 = l1.next
            
            if l2 is not None:
                total += l2.val
                l2 = l2.next

            curr.next = ListNode(total % 10)
            carry = total // 10

            curr = curr.next
        
        return dummy.next