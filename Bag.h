/***************************************************************************
* A generic bag or multiset, implemented using a singly-linked list.
*
* It supports insertion and iterating over the items in arbitrary order.
*
* For additional documentation, see Section 1.3 of Algortithms, 4th Ed.
* by Robert Sedgewick and Kevin Wayne
*
****************************************************************************/

#include <iterator>

template <class T>
class Bag {
	class Node;	
public:
	class Iterator;

	// Constructor
	Bag() : N_(0), first_(NULL) {}

	// Destructor
	~Bag() {
		Node* current = first_;
		while (current != NULL) {
			first_ = first_->next_;
			delete current;
			current = first_;
		}
	}

	// Copy constructor
	Bag(const Bag& other) : N_(0), first_(NULL) {
		std::cout << "Copying" << std::endl;
		Node* current = other.first_;
		while (current != NULL) {
			add(current->item_);
			current = current->next_;
		}
	}

	// Assignment operator
	Bag& operator=(const Bag& other) {
		std::cout << "Assigning" << std::endl;
		if (this == &other) return *this;
		
		// Free memory
		Node* current = first_;
		while (first_ != NULL) {
			first_ = first_->next_;
			delete current;
			current = first_;
		}

		// Copy elements
		current = other.first_;
		while (current != NULL) {
			add(current->item_);
			current = current->next_;
		}
		
		return *this;
	}

	// Methods
	bool isEmpty() { return first_ == NULL; }

	int size() { return N_; }

	void add(T item) {
		Node* oldfirst = first_;
		first_ = new Node(item);
		first_->next_ = oldfirst;
		N_++;
	}

	Iterator begin() { return Iterator(first_); }

	Iterator end() { return Iterator(NULL); }

	// Iterator class
	class Iterator : public std::iterator < std::forward_iterator_tag, T > {
	public:
		Iterator() : ptr_(NULL) {}

		Iterator(Node* ptr) : ptr_(ptr) {}

		~Iterator() {}

		Iterator(const Iterator& other) : ptr_(other.ptr_) {}

		Iterator& operator=(const Iterator& other) { ptr_ = other.ptr_; return *this; }

		Iterator& operator++() { ptr_ = ptr_->next_; return *this; }

		bool operator==(const Iterator& other) { return ptr_ == other.ptr_; }

		bool operator!=(const Iterator& other) { return ptr_ != other.ptr_; }

		T& operator*() { return ptr_->item_; }

		T* operator->() { Iterator tmp = *this; T& value = *tmp; return &value; }

	private:
		Node* ptr_;
	};

private:
	struct Node {
		Node() : next_(NULL) {}
		Node(T item) : item_(item) {}

		T item_;
		Node* next_;
	};

	int N_;
	Node* first_;
};