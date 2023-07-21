#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> st;
	for(int i = 0; i < n; i++) st.push(i);
	int celebrity = st.top();
	st.pop();
	while(!st.empty()){
		if(!st.empty() && knows(st.top() , celebrity)){
			st.pop();
		}
		else{
			celebrity = st.top();
			st.pop();
		}
	}

	for(int i = 0; i < n; i++){
		if(i != celebrity && (!knows(i , celebrity) || knows(celebrity , i))){
			return -1;
		}
	}
	return celebrity;
}