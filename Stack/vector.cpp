/***
    Implement stack / std::vector with fixed capacity known during constructors.
        1. push_back()
        2. pop_back()
        3. back()
        4. front()
        5. Vec[0]
        6. vec.size()
***/

#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;

void push(int n){
    stack.push_back(n);
}

void pop(){
    stack.pop_back();
}

int peek(){
    return stack.back();
}

bool isEmpty(){
    return stack.empty();
}

int size(){
    return stack.size();
}

void print(){
    for (int i = 0; i < stack.size(); i++){
        printf("%d ", stack[i]);
        printf("\n");
    }
}

int main(){
    push(5);
    push(6);
    push(7);
    pop();
    print();
}
   