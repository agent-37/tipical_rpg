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
	int pop(new_type& new_el);
	int front(new_type& new_el);
	void push(new_type new_el);
	int size();
};

#endif // _STACK_H_


