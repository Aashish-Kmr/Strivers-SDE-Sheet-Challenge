#include <bits/stdc++.h> 
void addInSortedStack(stack<int> &stack, int x){
	// Base Case
	if(stack.empty()){
		stack.push(x);
		return;
	}
	else if(stack.top() <= x){
		stack.push(x);
		return;
	}
	int y = stack.top();
	stack.pop();
	addInSortedStack(stack, x);
	stack.push(y);
}

void sortStack(stack<int> &stack)
{
	// Using Recursion: Intuition Insert Sort
	//Base Case
	if(stack.empty()) return;
	int store = stack.top();
	stack.pop();
	sortStack(stack);
	addInSortedStack(stack, store);
}