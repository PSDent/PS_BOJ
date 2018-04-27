#include<iostream>

using namespace std;

int stack[100000];
int top = -1, index = 0, stepIndex = 0;
int num, arr[100000];
char step[200000];

void push(int val);
void pop();
	
int main(void)
{
	cin >> num;
	for(int i = 0; i < num; ++i)
		cin >> arr[i];	
	
	for(int i = 1; index < num;)	
	{
		if(stack[top] == arr[index]) {
			pop();
			continue;
		}
		
		else if(top == num - 1) {
			cout << "NO";
			return 0;
		}
			
		push(i++);
	}
	
	for(int i = 0; i < stepIndex; i++)
	cout << step[i] << '\n';
	
	return 0;
}

void push(int val)
{
	stack[++top] = val;
	step[stepIndex++] = '+';
	return;
}

void pop()
{
	--top; ++index;
	step[stepIndex++] = '-';
	return;
}

