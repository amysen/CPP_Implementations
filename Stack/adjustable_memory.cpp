#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Stack {
    int size = 0;
    int *S;
    int capacity;

    Stack(int init_size){
        std::cout << "The size is: " << init_size << ". " << std::endl;
        capacity=init_size;
        S = new int[init_size];
        // S=(int *)malloc(init_size*sizeof(int));
    }

    ~Stack(){
        if (S != nullptr){
            delete[] S;
        }
    }

    void push(int x){
        // stack is full
        if (size == capacity){
            int new_capacity = capacity * 2;
            int *N = new int[new_capacity];

            std::cout << "The NEW size is: " << new_capacity << ". " << std::endl;

            for (int i = 0; i < capacity; i++){
                N[i] = S[i];
            }

            delete[] S;
            S = N;
            capacity = new_capacity;

        }

        S[size] = x;
        size++;
        
    }

    int pop(){
        int popped = -1;
        if(size == 0){
            std::cout << "Stack Underflow\n" << std::endl;
        } else {
            popped = S[size-1];
            size--;
        }
        return popped;
    }

    void peek(){
        std::cout << "Peek: " << S[size-1] << std::endl;
    }

    bool isEmpty(){
        if (size == 0){
            return true;
        }
        return false;
    }

    bool isFull(){
        if (size == capacity){
            return true;
        }
        return false;
    }

    void display(){
        for (int i = size - 1; i >= 0; i--){
            std::cout << S[i] << std::endl;
        }
        std::cout << "\n" << std::endl;
    }

};


int main(){
    Stack st(3);
    // st.create(3);
    if (st.isEmpty()){
        std::cout << "Stack is empty!" << std::endl;
    }
    

    st.push(1);
    st.push(2);
    st.push(3);

    st.display();

    if (st.isFull()){
        std::cout << "Stack is full!" << std::endl;
    }

    st.pop();

    st.peek();

    st.push(4);

    st.display();

    st.push(5);
    st.display();
}