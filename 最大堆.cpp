/*
	Name: 最大堆 
	Author: Hyacinth 
	Date: 28/11/19 20:31
	Description: 实现一个简单的最大堆以及一个测试程序 
*/

#include<bits/stdc++.h>
using namespace std;

class MyHeap{  
private:
	vector<int> arr;
public:
	void push(int num){
		arr.push_back(num);
		int cur = arr.size();
		while(cur/2 >= 1 && arr[cur/2-1] < arr[cur-1]){
			swap(arr[cur-1], arr[cur/2-1]);
			cur /= 2;
		}
	}
	void pop(){
		if(arr.empty()) {
			cerr<<"empty error"<<endl; 
			return ;
		} 
		swap(arr[0], arr[arr.size()-1]);
		arr.pop_back();
		int cur = 1;
		while(2*cur<=arr.size()){
			int child = (2*cur == arr.size() || arr[2*cur-1] >= arr[2*cur]) ? 2*cur : 2*cur + 1;
			if(arr[child-1] <= arr[cur-1]) break;
			swap(arr[child-1], arr[cur-1]);
		} 
	}
	int top(){
		if(arr.empty()) {
			cerr<<"empty error"<<endl; 
			return 0;
		} 
		return arr[0];
	}
	int size(){
		return arr.size();
	}
}; 

int main(){
	//test 
	MyHeap h;
	h.push(5);
	assert(h.top() == 5);
	h.push(6);
	assert(h.top() == 6);
	h.push(4);
	assert(h.top() == 6);
	h.push(7);
	assert(h.top() == 7);
	h.pop();
	assert(h.top() == 6);
	h.pop();
	assert(h.top() == 5);
	h.pop();
	assert(h.top() == 4);
	h.pop();
	h.pop();
	h.top();
	return 0;
}

