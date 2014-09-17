#include <cstring>
#define CMAX 128
#define N 1005
struct Node{
    Node* child[CMAX], fa;
    int count, no;
    char ch;
    Node(){
        memset(child, NULL, sizeof(child));
        count=no=_no;
    }
};
struct DictTree{
    Node* root;
    int size;
    Node* idx2node[N];
    Node* alloc(){ Node* tmp = new Node(); return tmp; }
    int char2c(char c){ return c;}
    DictTree(){size = 0; root = alloc();}
    void modify(char* target, int& no, int& count){
        Node* iter = root;
        while(target != '\0'){
            int cn = char2c(*target);
            if(iter->child[cn] == NULL){
                Node* child = alloc(++size);
                iter->child[cn] = child;
                child->fa = iter;
            }
            target++;
            if(target == '\0') {iter->count++; no = iter->no = size; idx2node[size++] = iter; count = iter->count; break;}
            iter = iter->child[cn];
        }
    }
    void query(int idx, char* res){
        Node* iter = idx2node[idx];
        while(iter->fa){
            *res = iter->ch;
            iter = iter->fa;
        }
    }
};
