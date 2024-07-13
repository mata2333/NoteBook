// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}
struct Solution {

}
impl Solution {
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut dummyHead = Box::new(ListNode::new(0));
        dummyHead.next = head;
        let mut cur = dummyHead.as_mut();
        while let Some(nxt) = cur.next.take() {
            if nxt.val == val {
                cur.next = nxt.next;
            } else {
                cur.next = Some(nxt);
                cur = cur.next.as_mut().unwrap();
            }
        }
        dummyHead.next
    }
}
