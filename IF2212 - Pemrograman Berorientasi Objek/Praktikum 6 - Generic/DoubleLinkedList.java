/**
 * LinkedList.java
 * [Jelaskan kegunaan class ini]
 * @author 18221041 Frendy Sanusi
 */

public class DoubleLinkedList<T> {

    private Node<T> head;
    private Node<T> tail;
    private int size;

    /**
     * Konstruktor
     * buat Double linked list dengan size = 0 dan head = tail = null
     */
    public DoubleLinkedList() {
		size = 0;
		head = new Node();
		tail = new Node();
	}

    /**
     * Cari elemen yang terletak pada posisi position
     * @param position
     * @return elemen pada posisi position jika ada, null jika tidak ada
     */
    public Node<T> getNode(int position) {
		int idx = 0;
		Node<T> p = new Node<T>();
		p = head;
		while (idx != position && p != null) {
			p = p.getNext();
			idx++;
		}
		
		if (p.getValue() != null) return p;
		else return null;
	}

    /**
     * Tambah elemen dengan nilai item dengan menambahkan
     * node sebagai elemen paling belakang
     * @param item
     */
    public void add(T item) {
		if (size == 0) {
				head.setValue(item);
				tail.setValue(item);
			}
		else {
			Node<T> p = new Node<T>();
			p = head;
			Node<T> l = new Node<T>();
			while (p.getValue() != tail.getValue()) {
				p = p.getNext();
			};
			
			p.setNext(new Node<T>(item));
			l = p.getNext();
			l.setPrev(p);
			tail = l;
		}
		size++;
	}

    /**
     * Cari nilai elemen pada posisi position
     * @param position
     * @return nilai elemen pada posisi position jika ada, null jika tidak ada
     */
    public T get(int position) {
		Node<T> p = new Node<T>();
		p = head;
		int idx = 0;
		while (idx != position) {
			p = p.getNext();
			idx++;
		}
		return p.getValue();
	}

    /**
     * Ubah nilai elemen pada posisi position menjadi nilai item jika ada
     * @param position
     * @param item
     */
    public void set(int position, T item) {
		Node<T> p = new Node<T>();
		p = head;
		int idx = 0;
		while (idx != position) {
			p = p.getNext();
			idx++;
		}
		
		if (p != null) p.setValue(item);
	}

    /**
     * Hapus elemen pada posisi position jika ada
     * @param position
     */
    public void remove(int position) {
		Node<T> p = new Node<T>();
		p = head;
		Node<T> prev = new Node<T>();
		int idx = 0;
		while (idx != position) {
			prev = p;
			p = p.getNext();
			idx++;
		}
		
		if (p.getValue() != null) {
			prev.setNext(p.getNext());
			p.getNext().setPrev(prev);
			size--;
		}
	}

    /**
     * Hapus semua elemen dari Double Linked List
     */
    public void clear() {
		while (size > 0) {
			remove(size-1);
		}
	}

    /**
     * Getter size
     * @return size
     */
    public int getSize() {
		return size;
	}

    /**
     * Menampilkan keseluruhan isi Double Linked List
     * Format yang dikeluarkan adalah sebagai berikut, misal isi list adalah [1,2,3,4]
     * Maka output yang dihasilkan adalah (dengan enter) :
     * 1 2 3 4
     */
    public void display() {
		if (size == 0) {
			System.out.println("");
		}
		else {
			Node<T> p = new Node<T>();
			p = head;
			while (p != tail) {
				System.out.print(p.getValue());
				System.out.print(" ");
				p = p.getNext();
			}
			System.out.println(p.getValue());
		}
	}

    /**
     * Find element position
     * jika terdapat lebih dari 1 elemen dengan nilai yang sama, maka ambil posisi
     * yang ditemukan pertama kali dari head
     * @return posisi dari sebuah item mulai dari head dengan zero indexing
     */
    public Integer find(T item) {
		Node<T> p = new Node<T>();
		p = head;
		Integer idx = new Integer(0);
		while (p != null) {
			if (p.getValue() == item) return idx;
			else {
				p = p.getNext();
				idx++;
			}
		}
		idx = -1;
		return idx;
	}
}
