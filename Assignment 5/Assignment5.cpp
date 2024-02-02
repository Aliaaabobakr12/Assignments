/*
Aliaa Abobakr Elshiekh
120210151
CSE 3
Assignment 5
*/

#include <iostream>

using namespace std;

struct Stack {
    int top;
    int size;
    int* array;
};

Stack* createStack(int size) {
    Stack* stack = new Stack;
    stack->size = size;
    stack->top = -1;
    stack->array = new int[size];
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return stack->array[stack->top--];
}
void moveDisk(char source, char destination, Stack* sourceStack, Stack* destStack) {
    int disk = pop(sourceStack);
    push(destStack, disk);
    cout << "Move disk " << disk << " from " << source << " to " << destination << endl;
}
void towerOfHanoi(int numDisks, char a, char b, char c, Stack* sourceStack, Stack* auxStack, Stack* destStack) {
    if (numDisks > 0) {
        towerOfHanoi(numDisks - 1, a, c, b, sourceStack, destStack, auxStack);
        moveDisk(a, c, sourceStack, destStack);
        towerOfHanoi(numDisks - 1, b, a, c, auxStack, sourceStack, destStack);
    }
}
int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    Stack* stackA = createStack(numDisks);
    Stack* stackB = createStack(numDisks);
    Stack* stackC = createStack(numDisks);

    for (int i = numDisks; i > 0; --i) {
        push(stackA, i);
    }

    cout << "Tower of Hanoi moves: " << endl;
    towerOfHanoi(numDisks, 'A', 'B', 'C', stackA, stackB, stackC);


    return 0;
}
