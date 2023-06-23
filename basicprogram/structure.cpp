#include<iostream>
struct Rect {
    int len;
    int bre;
};

int initalize(struct Rect *r,int l,int b){
    r->len = l;
    r->bre = b;
    return 0;
}

int cal(struct Rect *r){
    return r->len * r->bre;
}

int override_struct(struct Rect *r, int a, int b){
    r->len = a;
    r->bre = b;
    return 0;
}

int main(){
    struct Rect r;
    initalize(&r,10,20);
    std::cout<<cal(&r)<<" ";
    override_struct(&r,10,30);
    std::cout<<cal(&r)<<" ";
}