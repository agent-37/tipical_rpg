#ifndef _STACK_H_
#define _STACK_H_

#define  MAX_SIZE_STACK 10
    
template <class new_type>
class stack {
public:
	int size_stack;
	int ind;
	new_type elements[MAX_SIZE_STACK];
	stack() {
		ind = 0;
		size_stack = 0;
	}
	~stack() {}
public:
	template <class new_type>
	int pop(new_type& new_el) {
		if (size_stack == 0)
			return 0;
		new_el = elements[ind];
		ind = (ind + MAX_SIZE_STACK - 1) % MAX_SIZE_STACK;
		size_stack--;
		return 1;
	}
	template <class new_type>
	int front(new_type& new_el) {
		if (size_stack == 0)
			return 0;
		new_el = elements[ind];
		return 1;
	}
	template <class new_type>
	void push(new_type new_el) {
		if (size_stack < MAX_SIZE_STACK)
			size_stack++;
		ind = (ind + 1) % MAX_SIZE_STACK;
		elements[ind] = new_el;
	}
	int size() {
		return size_stack;
	}
};

#endif // _STACK_H_


