# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode | None) -> ListNode | None:
        if head is None:
            return None

        odd_dummy = ListNode(-1)
        odd = odd_dummy

        even_dummy = ListNode(-1)
        even = even_dummy

        temp = head
        ind = 1

        while temp is not None:
            if ind % 2 != 0:
                odd.next = temp
                odd = odd.next
            else:
                even.next = temp
                even = even.next

            temp = temp.next
            ind += 1

        even.next = None
        odd.next = even_dummy.next

        return odd_dummy.next