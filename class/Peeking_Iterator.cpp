/*
问题描述：
给一个Iterator类，拥有next()和hasNext()方法，next()返回指针指向的下一个元素，并进行指针移动，hasNext()返回是否有下一个元素
现要求实现一个PeekingIterator类，除了next()和hasNext()方法，还要有一个peek()方法，返回指针指向的下一个元素，但是指针不移动


解决方法：
peek()中拷贝构造一个Iterator新对象，调用新对象的next()，新对象指针移动，但是旧对象不移动
*/

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		//这里利用拷贝构造函数，新定义了个对象，并将内容进行了拷贝，对新对象的next()，不会影响本对象的next()
		return Iterator(*this).next();

	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {

		return Iterator::next();
	}

	bool hasNext() const {
		return Iterator::hasNext();
	}
};