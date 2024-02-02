/*
Aliaa Abobakr Elshiekh
120210151
CSE 3
Assignment 4
*/

#include <iostream>
using namespace std;

const int stackSize = 100;

struct Stack {
    int arr[stackSize];
    int top;

    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top < stackSize - 1) {
            arr[++top] = value;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    int topValue() {
        if (this->top >= 0) {
            return arr[this->top];
        }
        else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int postfix(string exp) {
    Stack stack;

    for (int i = 0; i < exp.size(); i++) {
        if (isdigit(exp[i]))
            stack.push(exp[i] - '0');
        else {
            int value2 = stack.pop();
            int value1 = stack.pop();
            switch (exp[i]) {
            case '+':
                stack.push(value1 + value2);
                break;
            case '-':
                stack.push(value1 - value2);
                break;
            case '*':
                stack.push(value1 * value2);
                break;
            case '/':
                stack.push(value1 / value2);
                break;
            }
        }
    }

    return stack.topValue();
}

int main() {
    string exp;
    cout << "Enter a postfix: ";
    cin >> exp;

    int result = postfix(exp);

    if (result != -1) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
