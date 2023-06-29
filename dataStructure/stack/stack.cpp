#include<bits/stdc++.h>
class Stack{
    private:
        int size;
        int items[100];
        int top;
    public:
        Stack(int len){
            size = len;
            top = -1;
        };
        int is_empty();
        int is_full();
        int push(int);
        int pop();
        int traverse();
};

int Stack::is_empty(){
    if(top == -1){
        std::cout<<"Stack is empty enter some value\n";
        return 0;
    }
    return 1;
}

int Stack::is_full(){
    if(top == size-1){
        std::cout<<"Stack is full pls pop out the value\n";
        return 0;
    }
    return 1;
}

int Stack::push(int val){
    if(!is_full() == 0){
        ++top;
        std::cout<<"Value pushed successfully\n";
        items[top] = val;
        return 0;
    }
    return 1;
}

int Stack::pop(){
    if(!is_empty() == 0){
        std::cout<<"Value poped out successfully\n";
        int temp;
        temp = items[top];
        --top;
        return temp;
    }
    return 1;
}

int Stack::traverse(){
    if(!is_empty() == 0){
        for(int i=top;i>=0;i--){
            std::cout<<items[i]<<" ";
        }
        return 0;
    }
    return 1;
}

int main(){
    std::cout<<"Size of the stack\n";
    int size;
    std::cin>>size;
    Stack stk(size);
    int choose;
    do {
        std::cout<<"\nChoose the option to perform stack operation:\n";
        std::cout<<"1: push Value to stack\n";
        std::cout<<"2: pop the Value from the stack\n";
        std::cout<<"3: Traverse the stack\n";
        std::cout<<"4: Exit fron the operation\n";
        std::cin>>choose;
        switch(choose){
            case 1:
                int val;
                std::cout<<"Enter value to push in stack\n";
                std::cin>>val;
                stk.push(val);
                break;
            case 2:
                stk.pop();
                break;
            case 3:
                stk.traverse();
                break;
            default:
                std::cout<<"Please choose the correct option\n";
                break;
        }
    }while(choose!=4);
    return 0;
}