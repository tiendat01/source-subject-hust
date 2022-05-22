#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// bien toan cuc
int top = -1; // bien nay luu chi so cua phan tu top cua ngan xep, phan tu cuoi cung cua stack
 
bool IsFull(int capacity){
    if(top >= capacity - 1){
        return true;
    }else{
        return false;
    }
}
 
bool IsEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}
 
void Push(int stack[], int value, int capacity){
    if(IsFull(capacity) == true){
        printf("\nStack is full. Overflow condition!");
    }else{
        ++top;
        stack[top] = value;
    }
}
 
void Pop(){
    if(IsEmpty() == true){
        printf("\nStack is empty. Underflow condition!");
    }else{
        --top;
    }
}
 
 
int Top(int stack[]){
    return stack[top];
} // tra ve gia tri cuoi cung cua mang
 
int Size(){
    return top + 1;
}
 
int main(){
    int capacity = 3; // size of stack
    int top = -1; 
    int stack[capacity];
    
    // pushing element 5 in the stack .
    Push(stack, 5, capacity); 
    
    printf("\nCurrent size of stack is %d", Size());
    
    Push(stack, 10, capacity);
    Push(stack, 24, capacity);
    
    printf("\nCurrent size of stack is %d", Size());
    
    // As the stack is full, further pushing will show an overflow condition.
    Push(stack, 12, capacity); 
    
    //Accessing the top element
    printf("\nThe current top element in stack is %d", Top(stack));
    
    //Removing all the elements from the stack
    for(int i = 0 ; i < 3;i++)
        Pop();
    printf("\nCurrent size of stack is %d", Size());
    
    //As the stack is empty , further popping will show an underflow condition.
    Pop();  
}