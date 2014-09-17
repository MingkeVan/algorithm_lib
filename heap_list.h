#include <stdio.h>
#define TOP 1000
#define ll long long
struct Node{
    Node *child[2], *fa;  
    ll val;
    Node(ll v=0){
        val = v; child[0] = child[1] = fa = NULL;
    }
};
void swap(Node* fa, Node* ch){
    Node* pnt;
    pnt[0] = fa->fa; pnt[1] = fa->child[0]; pnt[2] = fa->child[1];
    fa->fa = ch->fa; fa->child[0] = ch->child[0]; fa->child[1] = ch->child[1];
    ch->fa = pnt[0]; ch->child[0] = pnt[1]; ch->child[1] = pnt[2];
}
struct Heap{
    Node* root;  
    int size;
    Heap(){ size = 0; root = new Node();}
    void down(Node *ptr){
        while(ptr){
            ll v = ptr->child[1]->val;
            if(ptr->child[0] && ptr->child[1]){
                ll x = ptr->child[0]->val, y = ptr->child[1]->val;
                if(x > y){
                    if(y < v){
                        swap(ptr, ptr->child[1]);
                    }
                    else return;
                }
                else{
                    if(x < v){
                        swap(ptr, ptr->child[0]);
                    }
                    else return;
                }
            }
            if(ptr->child[0]){
                ll x = ptr->child[0]->val;
                if(x < v){
                    swap(ptr, ptr->child[0]);
                }
                else return;
            }
            return;
        }
    }
    void upon(Node *ptr){
        while(ptr->fa != root){
            Node* fa = ptr->fa;
            if(fa->val > ptr->val){
                printf("swap %lld %lld\n", fa->val, ptr->val);
                swap(fa, ptr);
                printf("swap %lld %lld\n", fa->val, ptr->val);
            }
            else return;
        }
    }
    Node* bfs(Node *rt, int id){
        puts("BFS");
        printf("%d\n", id);
        Node* queue[TOP];
        int head = 0, tail = 0;
        if(tail == id) return rt;
        queue[tail++] = rt;
        while(head < tail){
            Node* top = queue[head]; head++;
            printf("%d %lld\n", tail, top->val);
//            if(id == -1){
//                printf("%lld\n", top->val);
//            }
            if(top->child[0]) {
                if(tail == id) return top->child[0];
                queue[tail++] = top->child[0]; 
            }
            if(top->child[1]) {
                if(tail == id) return top->child[0];
                queue[tail++] = top->child[1];
            }
        }
        return NULL;
    }
    Node* insert(int x){
        if(size >= TOP){
            if(root->child[0]->val < x){
                root->child[0]->val = x; // Mark
                down(root->child[0]);
                return root->child[0];
            }
            return NULL;
        }
        Node* newptr = new Node(x); size++;
        if(size == 1){
            newptr->fa = root; root->child[0] = newptr; return newptr;
        }
        puts("INSERT");
        Node* fa = bfs(root->child[0], size/2-1); 
        newptr->fa = fa;
        fa->child[size&1] = newptr;
        upon(newptr);
        return newptr;
    }
    void display(){
        printf("##################\n");
        bfs(root->child[0], -1);       
    }
};
