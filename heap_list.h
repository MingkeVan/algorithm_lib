#include <stdio.h>
#include <string.h>
#include "def.h"
struct hNode{
    hNode *child[2], *fa;  
    ll val;
    char* msg;
	void* rbNode;
    hNode(ll v=0){
        val = v; rbNode = child[0] = child[1] = fa = NULL;
    }
};
void swap(hNode* fa, hNode* ch){
//	printf("swap %lld %lld\n", fa->val, ch->val);
	if(fa->child[0] == ch){
		hNode* tmpc = fa->child[1], *tmpf = fa->fa;
		fa->child[0] = ch->child[0]; if(fa->child[0]) fa->child[0]->fa = fa;
		fa->child[1] = ch->child[1]; if(fa->child[1]) fa->child[1]->fa = fa;
		ch->child[0] = fa; fa->fa = ch;
		ch->child[1] = tmpc; if(tmpc) tmpc->fa = ch;
		ch->fa = tmpf;
		if(tmpf->child[0] == fa) tmpf->child[0] = ch;
		else tmpf->child[1] = ch;
	}
	else if(fa->child[1] == ch){
		hNode* tmpc = fa->child[0], *tmpf = fa->fa;
		fa->child[1] = ch->child[1]; if(ch->child[1]) ch->child[1]->fa = fa;
		fa->child[0] = ch->child[0]; if(ch->child[0]) ch->child[0]->fa = fa;
		ch->child[1] = fa; fa->fa = ch;
		ch->child[0] = tmpc; if(tmpc) tmpc->fa = ch;
		ch->fa = tmpf; 
		if(tmpf->child[1] == fa) tmpf->child[1] = ch;
		else tmpf->child[0] = ch;
	}
	else{
		hNode* tmp = fa->fa;
		if(tmp->child[0] == fa) tmp->child[0] = ch;
		if(tmp->child[1] == fa) tmp->child[1] = ch;
		
		tmp = ch->fa;
		if(tmp->child[0] == ch) tmp->child[0] = fa;
		if(tmp->child[1] == ch) tmp->child[1] = fa;

		tmp = fa->fa; fa->fa = ch->fa; ch->fa = tmp;
		tmp = fa->child[0]; fa->child[0] = ch->child[0]; ch->child[0] = tmp;
		if(fa->child[0]) fa->child[0]->fa = fa;
		if(ch->child[0]) ch->child[0]->fa = ch;
		tmp = fa->child[1]; fa->child[1] = ch->child[1]; ch->child[1] = tmp;
		if(fa->child[1]) fa->child[1]->fa = fa;
		if(ch->child[1]) ch->child[1]->fa = ch;
	}
}
struct Heap{
    hNode* root;  
    int size;
    Heap(){ size = 0; root = new hNode();}
    void down(hNode *ptr){
        while(ptr){
            ll v = ptr->val;
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
				continue;
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
    void upon(hNode *ptr){
        while(ptr->fa != root){
            hNode* fa = ptr->fa;
            if(fa->val > ptr->val){
                swap(fa, ptr);
            }
            else return;
        }
    }
    hNode* bfs(hNode *rt, int id){
        hNode* queue[TOP];
        int head = 0, tail = 0;
        if(tail == id) return rt;
        queue[tail++] = rt;
        while(head < tail){
            hNode* top = queue[head]; head++;
            if(id == -1){
                printf("%lld\n", top->val);
            }
            if(top->child[0]) {
                if(tail == id) return top->child[0];
                queue[tail++] = top->child[0]; 
            }
            if(top->child[1]) {
                if(tail == id) return top->child[1];
                queue[tail++] = top->child[1];
            }
        }
        return NULL;
    }
    hNode* insert(int x, char* msg){
		unsigned int len = strlen(msg);
        if(size >= TOP){
            if(root->child[0]->val < x){
                root->child[0]->val = x; // Mark
				memcpy(root->child[0]->msg, msg, len+1);
                down(root->child[0]);
                return root->child[0];
            }
            return NULL;
        }
        hNode* newptr = new hNode(x); size++;
		newptr->msg = (char*)malloc(STRMAX);
		memcpy(newptr->msg, msg, len+1);
        if(size == 1){
            newptr->fa = root; root->child[0] = newptr; return newptr;
        }
        hNode* fa = bfs(root->child[0], size/2-1); 
        newptr->fa = fa;
        fa->child[size&1] = newptr;
        upon(newptr);
        return newptr;
    }
	void sort(){
		int count = 0;
		while(size){
			count++;
			printf("[TOP %d] %lld %s\n", TOP-count+1, root->child[0]->val, root->child[0]->msg);
			hNode* last = bfs(root->child[0], size-1);
			hNode* top = root->child[0];
			swap(top, last);
			if(top->fa->child[0] == top) top->fa->child[0] = NULL;
			else top->fa->child[1] = NULL;
			top->fa = NULL;
			down(root->child[0]);
			size--;
		}
	}
    void display(){
        printf("##################\n");
        bfs(root->child[0], -1);       
    }
};
