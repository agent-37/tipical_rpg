#include "stack.h"

#define  MAX_SIZE_STACK 10
//процедура задает характеристики кому-то
template <class new_type>
int stack<new_type>::size() {
	return size_stack;
}
template <class new_type>
void stack<new_type>::push(new_type new_el) {
	if (size_stack < MAX_SIZE_STACK)
		size_stack++;
	ind = (ind + 1) % MAX_SIZE_STACK;
	elements[ind] = new_el;
}
template <class new_type>
int stack<new_type>::pop(new_type& new_el) {
	if (size_stack == 0)
		return 0;
	new_el = elements[ind];
	ind = (ind + MAX_SIZE_STACK - 1) % MAX_SIZE_STACK;
	return 1;
}
template <class new_type>
int stack<new_type>::front(new_type& new_el) {
	if (size_stack == 0)
		return 0;
	new_el = elements[ind];
	return 1;
}