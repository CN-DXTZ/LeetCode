#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
	stack<int> s;
	stack<int> min;
public:
	void push(int x) {
		s.push(x);
		if (min.empty() || x <= getMin())
			min.push(x);
	}
	void pop() {
		if (s.top() == min.top())
			min.pop();
		s.pop();
	}
	int top() {
		return s.top();
	}
	int getMin() {
		return min.top();
	}
};

int main()
{
	MinStack* obj = new MinStack();
	obj->push(7);
	obj->push(3);
	obj->push(10);
	obj->push(1);
	cout << obj->top() << endl;
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->top() << endl;
	cout << obj->getMin() << endl;
	system("pause");
	return 0;
}