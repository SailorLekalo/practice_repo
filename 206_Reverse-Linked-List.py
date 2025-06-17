# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        prev = None
        curr = head

        # make nodes to point on prev elements instead of next
        while curr is not None:
            new = curr.next
            curr.next = prev
            prev = curr
            curr = new

        return prev

# Runtime: O(N)
# Memory: O(1)
