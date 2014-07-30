#include <iterator>

template <class T>
class Bag {
	class Node;	
public:
	class Iterator;

	// Constructor, etc.
	Bag() : N_(0), first_(NULL) {}
	~Bag() {
		Node* current = first_;
		while (current != NULL) {
			first_ = first_->next_;
			delete current;
			current = first_;
		}
	}
	Bag(const Bag& other) : N_(0), first_(NULL) {
		Node* current = other.first_;
		while (current != NULL) {
			add(current->item_);
			current = current->next_;
		}
	}
	Bag& operator=(const Bag& other) {
		if (this == &that) return *this;
		
		Node* current = first_;
		while (first_ != NULL) {
			first_ = first_->next_;
			delete current;
			current = first_;
		}


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