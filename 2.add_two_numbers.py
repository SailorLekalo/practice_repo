# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        l3 = ListNode()
        res = l3
        while(l1 != None or l2 != None or carry == 1):
            l1val = 0 if l1 == None else l1.val
            l2val = 0 if l2 == None else l2.val
            sum = l1val + l2val + carry
            if sum >= 10:
                carry = 1
                sum -= 10
            else:
                carry = 0
            l3.val = sum
            if l1 != None:
                l1 = l1.next
            if l2 != None:
                l2 = l2.next
            if l1 != None or l2 != None or carry == 1:
                l3.next = ListNode()
            l3 = l3.next
        return res
