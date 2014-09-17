#include <stdio.h>
#define ll long long
#define N 1005
#define TOP 1000
struct Node{
    ll val;
    void init(int v){val = v;}
}node[N];
void swap(Node& a, Node& b){
    ll tmp = a.val;
    a.val = b.val;
    b.val = tmp;
}
struct Heap{
    int size;
    Heap(){ size = 1; }
    Node* upon(int idx){
        for(int i = idx; i > 1; i >>= 1){
            if(node[i].val < node[i/2].val){
                swap(node[i], node[i/2]);
            }
            else return &node[i];
        }
        return &node[1];
    }
    Node* down(int idx){
        int rev = idx;
        while(2*idx < size){
            if(2*idx + 1 >= size){
                 if(node[2*idx].val < node[idx].val){
                     swap(node[idx], node[2*idx]);
                 }
                 return &node[2*idx];
            }
            if(node[2*idx+1].val > node[2*idx].val){
                if(node[2*idx].val < node[idx].val){
                    swap(node[idx], node[2*idx]);
                    idx *= 2;
                }
                else return &node[idx];
            }
            else{
                if(node[2*idx+1].val < node[idx].val){
                    swap(node[idx], node[2*idx+1]);
                    idx = idx*2 + 1;
                }
                else return &node[idx];
            }
        }
        return &node[idx];
    }
    Node* insert(int v){
        node[size].init(v); 
        if(size >= TOP){
            if(node[1].val < node[size].val){
                swap(node[1], node[size]);
                return down(1);
            }
        }
        size++;
        return upon(size-1);
    }
    void display(){
        while(size > 1){
            printf("\n");
            printf("TOP %lld\n", node[1].val);
            for(int i = 1; i < size; i++){
                printf("%lld\n", node[i].val);
            }
            size--;
            printf("\n");
            swap(node[size], node[1]);
            down(1);
        }
    }
};

