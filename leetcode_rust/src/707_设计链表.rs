// 写不出来！！！！！！

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
        } else {
            let mut cur_index = 0;
            let mut cur = &mut self.next;


            // 一直遍历到index的前一个节点
            while let Some(nxt) = cur{
                if cur_index != index - 1 {
                    let mut new_node = Box::new(MyLinkedList { val: val, next: None});
                    new_node.next = nxt.next.take();
                    nxt.next = Some(new_node);
                }
                cur = &mut nxt.next;
                cur_index += 1;
            }
        }
    }

    fn delete_at_index(&mut self, index: i32) {
        if index < 0 {
            return;
        }

        let mut i = 0;
        let mut cur = self;
        while let Some(node) = cur.next.take() {
            if i == index {
                cur.next = node.next;
                break;
            }
            i += 1;
            cur.next = Some(node);
            cur = cur.next.as_mut().unwrap();
        }
    }
}