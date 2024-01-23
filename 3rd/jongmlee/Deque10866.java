import java.io.*;
import java.util.*;

class Deque10866 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		MyDeque<Integer> deque = new MyDeque<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();
			if (cmd.equals("push_back")) {
				deque.push_back(Integer.parseInt(st.nextToken()));
			} else if (cmd.equals("push_front")) {
				deque.push_front(Integer.parseInt(st.nextToken()));
			} else if (cmd.equals("pop_front")) {
				Integer ret = deque.pop_front();
				System.out.println(ret == null ? -1 : ret);
			} else if (cmd.equals("pop_back")) {
				Integer ret = deque.pop_back();
				System.out.println(ret == null ? -1 : ret);
			} else if (cmd.equals("size")) {
				System.out.println(deque.size());
			} else if (cmd.equals("empty")) {
				boolean ret = deque.isEmpty();
				System.out.println(ret == true ? 1 : 0);
			} else if (cmd.equals("front")) {
				Integer ret = deque.front();
				System.out.println(ret == null ? -1 : ret);
			} else if (cmd.equals("back")) {
				Integer ret = deque.back();
				System.out.println(ret == null ? -1 : ret);
			}
		}
	}
	static class MyDeque<T> {
		int	size;
		Node<T> first;
		Node<T> last;

		MyDeque() {
		}

		public void push_front(T input) {
			Node<T> newNode = new Node(input, null, this.first);
			newNode.prev = newNode;
			if (first == null) {
				this.first = newNode;
				this.last = newNode;
			} else {
				this.first.prev = newNode;
				this.first = newNode;
			}
			this.size++;
		}

		public void push_back(T input) {
			Node<T> newNode = new Node(input, this.last, null);
			newNode.next = newNode;
			if (last == null) {
				this.first = newNode;
				this.last = newNode;
			} else {
				this.last.next = newNode;
				this.last = newNode;
			}
			this.size++;
		}

		public T pop_front() {
			if (size == 0) {
				return null;
			}
			T ret = this.first.data;
			if (size == 1) {
				this.first = null;
				this.last = null;
			} else {
				this.first = this.first.next;
			}
			size--;
			return ret;
		}

		public T pop_back() {
			if (size == 0) {
				return null;
			}
			T ret = this.last.data;
			if (size == 1) {
				this.first = null;
				this.last = null;
			} else {
				this.last = this.last.prev;
			}
			size--;
			return ret;
		}

		public int size() {
			return size;
		}

		public boolean isEmpty() {
			return (size == 0) ? true : false;
		}

		public T front() {
			if (size == 0) {
				return null;
			}
			return this.first.data;
		}
	
		public T back() {
			if (size == 0) {
				return null;
			}
			return this.last.data;
		}

		static class Node<T> {
			T data;
			Node<T> prev;
			Node<T> next;
			public Node(T data, Node<T> prev, Node<T> next) {
				this.data = data;
				this.prev = prev;
				this.next = next;
			}
		}
	}
}
