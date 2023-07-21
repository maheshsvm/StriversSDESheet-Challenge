#include <bits/stdc++.h> 

void insert(stack<int>& stack , int val){
	if(stack.empty() || val >= stack.top()){
		stack.push(val);
		return;
	}

	int top = stack.top();
	stack.pop();
	insert(stack , val);
	stack.push(top);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty() || stack.size() == 1) return;
	int top = stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack , top);
}