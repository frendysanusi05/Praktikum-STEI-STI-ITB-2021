import java.util.HashMap;
import java.util.Map;

public class PageReplacementLRU {
    private final Integer maxPages;
    // Pair<processID, page>
    private Map<Pair<Integer, Integer>, Node> pages;
    private Node head;
    private Node tail;

    private class Node {
        Pair<Integer, Integer> pageID;
        Integer physicalAddr;
        Node prev;
        Node next;

        public Node(Pair<Integer, Integer> pageID, int physicalAddr) {
            // Please provide your solution in the space below
            this.pageID = pageID;
            this.physicalAddr = physicalAddr;
            prev = null;
            next = null;
        }
    }

    private void addNode(Node node) {
        // Please provide your solution in the space below
        // Tambahkan node di depan head
        if (tail == null) tail = head;
		else tail = head.next;
		head.prev = node;
		node.next = head;
		head = node;
		
    }

    private void removeNode(Node node) {
        // Please provide your solution in the space below
		if (node == head) head = head.next;
		else {
			Node temp = head;
			while (temp.next != tail) temp = temp.next;
			tail = temp;
		}
		//else {
		//	Node temp = head;
		//	Node prec = null;
		//	while (temp.next != tail) {
		//		if (temp != node) {
		//			prec.next = temp.next;
		//			Node nt = temp.next;
		//			nt.prev = prec;
		//		}
		//		prec = temp;
		//		temp = temp.next;
		//	}
		//}
    }

    private void moveToHead(Node node) {
        // Please provide your solution in the space below
		Node temp = head;
			if (node != head) {
			if (node == tail) {
				while (temp.next != node) {
					temp = temp.next;
				}
				temp.next = null;	
			}
			else {
				
				while (temp.next != node) {
					temp = temp.next;
				}
				if (node.next == null) temp.next = null;
				else temp.next = node.next;
				Node nt = node.next;
				
				nt.prev = temp;
				
			}
			node.next = head;
			node.prev = null;
			node = head;
		}
    }

    public PageReplacementLRU(Integer maxPages) {
        // Please provide your solution in the space below
        this.maxPages = maxPages;
        head = null;
        tail = null;
    }

    public int accessPage(Pair<Integer, Integer> pageID) {
        // Please provide your solution in the space below
        // print "page fault!" ketika pageID tidak ditemukan dalam LRU
        // lalu kembalikan -1
        Node temp = head;
        boolean found = false;
        while (temp != tail) {
			if (temp.pageID.equals(pageID)) {
				moveToHead(temp);
				return temp.physicalAddr;
			}
			else {
				temp = temp.next;
			}
		}
		if (temp.pageID.equals(pageID)) {
			moveToHead(temp);
			return temp.physicalAddr;
		}
		else {
			System.out.println("page fault!");
			return -1;
		}
    }

    public void addPage(Pair<Integer, Integer> pageID, int physicalAddr) {
        // Please provide your solution in the space below
        Node temp = head;
        int cnt = 0;
        if (temp != null) {
			cnt++;
			while (temp.next != tail) {
				cnt++;
				temp = temp.next;
			}
			cnt++;
		}

		
		if (cnt == maxPages) {
			removeNode(tail);
		}
		
		Node node = new Node(pageID, physicalAddr);
		node.next = head;
		node.prev = null;
		head = node;
    }
}
