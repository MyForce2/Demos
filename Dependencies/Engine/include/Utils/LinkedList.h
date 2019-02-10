#pragma once


namespace Engine {
	namespace Utils {

		template<typename Type>
		struct Node {
			Node<Type>* next;
			Node<Type>* prev;
			Type value;

			Node(Type value) : value(value), next(nullptr), prev(nullptr) {

			}

			Node() : value(), next(nullptr), prev(nullptr) {

			}

		};




		template<typename Type>
		class ListIterator {
		private:
			Node<Type>* current;

			template<class T>
			class LinkedList;
			friend class LinkedList<Type>;

		public:
			ListIterator(Node<Type>* node) : current(node) {

			}

			ListIterator(const ListIterator& iter) : current(iter.current) {

			}

			Type& operator*() const {
				return current->value;
			}


			bool operator!=(const ListIterator<Type>& iter) const {
				return iter.current != current;
			}

			bool operator==(const ListIterator<Type>& iter) const {
				return iter.current == current;
			}


			ListIterator<Type>& operator++() {
				current = current->next;
				return (*this);
			}

			ListIterator<Type> operator++(int) {
				current = current->next;
				return (*this);
			}



			void operator--() {
				current = current->prev;
			}


		};


		template<typename Type>
		class LinkedList {
		private:
			Node<Type>* first;
			Node<Type>* last;


		public:
			LinkedList() : first(nullptr), last(nullptr) {

			}

			LinkedList(Type& value) {
				first = new Node<Type>(value);
				last = first;
			}

			LinkedList(Type&& value) {
				first = new Node<Type>(value);
				last = first;
			}

			LinkedList(const LinkedList<Type>& list) {
				if (!list.isEmpty()) {
					for (Type& val : list)
						addLast(val);
				}
			}

			LinkedList(const std::initializer_list<Type>& list) {
				for (Type val : list)
					addLast(val);
			}

			~LinkedList() {
				if (!isEmpty()) {
					Node<Type>* iter = first;
					while (iter->next != nullptr) {
						iter = iter->next;
						delete iter->prev;
					}
					delete iter;
				}
			}

			void addFirst(Type& value) {
				Node<Type>* node = new Node<Type>(value);
				if (isEmpty()) {
					first = node;
					last = first;
				} else {
					node->next = first;
					first->prev = node;
					first = node;
				}
			}

			void addFirst(Type&& value) {
				Node<Type>* node = new Node<Type>(value);
				if (isEmpty()) {
					first = node;
					last = first;
				} else {
					node->next = first;
					first->prev = node;
					first = node;
				}
			}

			void addLast(Type& value) {
				Node<Type>* node = new Node<Type>(value);
				if (isEmpty()) {
					first = node;
					last = first;
				} else {
					last->next = node;
					node->prev = last;
					last = node;
				}
			}

			void addLast(Type&& value) {
				Node<Type>* node = new Node<Type>(value);
				if (isEmpty()) {
					first = node;
					last = first;
				} else {
					last->next = node;
					node->prev = last;
					last = node;
				}
			}

			void insert(const ListIterator<Type>& where, Type& value) {
				Node<Type>* node = new Node<Type>(value);
				Node<Type>* current = where.current;
				if (current == nullptr) {
					addLast(value);
					return;
				}
				if (current->next == nullptr) {
					current->next = node;
					node->prev = current;
					return;
				}
				if (current->prev == nullptr) {
					current->prev = node;
					node->next = current;
					return;
				}
				node->next = current->next;
				node->next->prev = node;
				current->next = node;
				node->prev = current;
			}

			void insert(const ListIterator<Type>& where, Type&& value) {
				Node<Type>* node = new Node<Type>(value);
				Node<Type>* current = where.current;
				if (current == nullptr) {
					addLast(value);
					return;
				}
				if (current->next == nullptr) {
					current->next = node;
					node->prev = current;
					return;
				}
				if (current->prev == nullptr) {
					current->prev = node;
					node->next = current;
					return;
				}
				node->next = current->next;
				node->next->prev = node;
				current->next = node;
				node->prev = current;
			}


			void remove(Type& value) {
				Node<Type>* iter = first;
				while (iter != nullptr) {
					if (iter->value == value) {
						if (iter == first) {
							first = first->next;
							first->prev = nullptr;
							delete iter;
							return;
						}
						if (iter == last) {
							last = last->prev;
							last->next = nullptr;
							delete iter;
							return;
						}
						iter->prev->next = iter->next;
						iter->next->prev = iter->prev;
						delete iter;
						return;
					}
					iter = iter->next;
				}
			}

			template<typename Pred>
			void removeIf(Pred pr) {
				Node<Type>* iter = first;
				while (iter != nullptr) {
					if (pr(iter->value)) {
						if (iter == first) {
							first = first->next;
							first->prev = nullptr;
							delete iter;
							return;
						}
						if (iter == last) {
							last = last->prev;
							last->next = nullptr;
							delete iter;
							return;
						}
						iter->prev->next = iter->next;
						iter->next->prev = iter->prev;
						delete iter;
						return;
					}
					iter = iter->next;
				}
			}

			void remove(Type&& value) {
				Node<Type>* iter = first;
				while (iter != nullptr) {
					if (iter->value == value) {
						if (iter == first) {
							first = first->next;
							first->prev = nullptr;
							delete iter;
							return;
						}
						if (iter == last) {
							last = last->prev;
							last->next = nullptr;
							delete iter;
							return;
						}
						iter->prev->next = iter->next;
						iter->next->prev = iter->prev;
						delete iter;
						return;
					}
					iter = iter->next;
				}
			}

			void clear() {
				Node<Type>* iter = first;
				while (iter->next != nullptr) {
					iter = iter->next;
					delete iter->prev;
				}
				delete iter;
				first = nullptr;
			}

			bool contains(Type& value) const {
				Node<Type>* iter = first;
				while (iter != nullptr) {
					if (iter->value == value)
						return true;
					iter = iter->next;
				}
				return false;
			}


			bool contains(Type&& value) const {
				Node<Type>* iter = first;
				while (iter != nullptr) {
					if (iter->value == value)
						return true;
					iter = iter->next;
				}
				return false;
			}

			bool isEmpty() const {
				return first == nullptr;
			}

			void reverse() {
				Node<Type>* iter = first;
				while (iter != nullptr) {
					Node<Type>* next = iter->next;
					iter->next = iter->prev;
					iter->prev = next;
					iter = next;
				}
				iter = first;
				first = last;
				last = iter;
			}

			ListIterator<Type> begin() const {
				return ListIterator<Type>(first);
			}

			ListIterator<Type> end() const {
				return ListIterator<Type>(nullptr);
			}


			void sort() {
				sort(std::less<Type>());
			}

			template<typename Pred>
			void sort(Pred pred) {
				if (isEmpty() || first == last)
					return;
				first = mergeSort(first, pred);
				Node<Type>* iter = first;
				while (iter->next != nullptr)
					iter = iter->next;
				last = iter;
			}

			template<typename Func>
			void forEach(Func func) {
				forEach(begin(), end(), func);
			}

			template<typename Func>
			void forEach(ListIterator<Type> start, const ListIterator<Type>& end, Func func) {
				for (; start != end; start++)
					func(*start);
			}

			void operator=(const LinkedList<Type>& list) {
				if (!isEmpty()) {
					Node<Type>* iter = first;
					while (iter->next != nullptr) {
						iter = iter->next;
						delete iter->prev;
					}
					delete iter;
				}
				for (Type& val : list)
					addLast(val);
			}

			void operator=(const std::initializer_list<Type>& list) {
				if (!isEmpty()) {
					Node<Type>* iter = first;
					while (iter->next != nullptr) {
						iter = iter->next;
						delete iter->prev;
					}
					delete iter;
				}
				for (Type& val : list)
					addLast(val);
			}

		private:
			template<typename Pred>
			static Node<Type>* mergeSort(Node<Type>* node, Pred pred) {
				if (node == nullptr || node->next == nullptr)
					return node;
				Node<Type>* middle = getMiddle(node);
				Node<Type>* halfTwo = middle->next;
				halfTwo->prev = nullptr;
				middle->next = nullptr;

				return merge(mergeSort(node, pred), mergeSort(halfTwo, pred), pred);
			}

			template<typename Pred>
			static Node<Type>* merge(Node<Type>* node, Node<Type>* nodeTwo, Pred pred) {
				Node<Type> first;
				Node<Type>* head = &first;
				Node<Type>* iter = head;
				while (node != nullptr && nodeTwo != nullptr) {
					if (pred(node->value, nodeTwo->value)) {
						iter->next = node;
						node->prev = iter;
						node = node->next;
					} else {
						iter->next = nodeTwo;
						nodeTwo->prev = iter;
						nodeTwo = nodeTwo->next;
					}
					iter = iter->next;
				}
				iter->next = (node == nullptr) ? nodeTwo : node;
				iter->next->prev = iter;
				iter = head->next;
				iter->prev = nullptr;
				return iter;
			}

			static Node<Type>* getMiddle(Node<Type>* node) {
				Node<Type>* fastIter = node;
				Node<Type>* slowIter = node;
				while (fastIter->next != nullptr && fastIter->next->next != nullptr) {
					slowIter = slowIter->next;
					fastIter = fastIter->next->next;
				}
				return slowIter;
			}

		};


	}
}