// pub struct ListNode<T> {
//     pub val: T,
//     pub next: Option<Box<ListNode<T>>>,
// }
//
// impl<T> ListNode<T> {
//     fn new(val: T, node: Option<Box<ListNode<T>>>) -> Self {
//         ListNode {next: node, val}
//     }
// }

use std::arch::x86_64::_mulx_u32;

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
pub struct MyLinkedList {
    val: i32,
    next: Option<Box<MyLinkedList>>
}
/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {
    fn new() -> Self {
        MyLinkedList {val: 0, next: None}
    }

    fn get(&self, index: i32) -> i32 {
        let mut cur_index = 0;
        let mut cur = &self.next;
        while let Some(node) = cur{
            if cur_index != index {
                cur = &node.next;
            }
        }
        if let Some(node) = cur{
            node.val
        } else {
            -1
        }
    }

    fn add_at_head(&mut self, val: i32) {
        let new_node = Box::new(MyLinkedList{val: val, next: self.next.take()});
        self.next = Some(new_node);
    }

    fn add_at_tail(&mut self, val: i32) {
        let mut cur = &mut self.next;
        let new_node = Box::new(MyLinkedList {val: val, next: None});
        // 一直遍历，直到最后节点位置
        while let Some(node) = cur{
            cur = &mut node.next;
        }
        *cur = Some(new_node);
    }

    fn add_at_index(&mut self, index: i32, val: i32) {
        if index == 0 {
            self.add_at_head(val);
            return;
        }
        let mut cur_index = 0;
        let mut cur = &mut self.next;
        let mut new_node = Box::new(MyLinkedList { val: val, next: None});
        // 一直遍历到index的前一个节点
        while let Some(nxt) = cur{
            if cur_index != index - 1 {
                cur = &mut nxt.next;
                cur_index += 1;
            }
        }
        // 从index-1处，增加新节点
        if let Some(nxt) = cur{
            new_node.next = nxt.next;
            nxt.next = Some(new_node);
        }
    }

    fn delete_at_index(&mut self, index: i32) {
        let mut cur = &mut self.next;
        let mut cur_index = 1;

        if index == 0 {
            if let Some(node) = self.next.take() {
                self.next = node.next;
            }
            return;
        } else {
            while let Some(node) = cur.take().as_mut(){
                if cur_index == index {
                    node.next = node.next.unwrap().next;
                    break;
                }
                cur = &mut node.next;
                cur_index += 1;
            }
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList::new();
 * let ret_1: i32 = obj.get(index);
 * obj.add_at_head(val);
 * obj.add_at_tail(val);
 * obj.add_at_index(index, val);
 * obj.delete_at_index(index);
 */


fn main() {

}
