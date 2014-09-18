#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "heap_list.h"
#include "rbtree.h"
#include "def.h"
#include "hash.h"
char ip[STRMAX];
char refer[STRMAX];
char agent[STRMAX];
char code[STRMAX];
char url[STRMAX];

//int status;
int body;
Heap urlMinHeap;
RBRoot* urlRoot;

void init(){
	urlMinHeap = Heap();
	urlRoot = create_rbtree();
}

int main(){
	init();
  	FILE* fp=fopen("big.in", "r");
	int count = 0;
	while(fscanf(fp, "%[0-9|.] %*[^]]%*c %*s %s %*s %s %d \"%[^\"]%*c \"%[^\"]%*c%*c%*c", ip, url, code, &body, refer, agent) == 6){
		count++;
//	while(fscanf(fp, "%s %d", url, &body)==2){
//		printf("%d\n", body);
		ull key1 = hashval(url, 0);
		ull key2 = hashval(url, 1);
//		printf("%llu %llu\n", key1, key2);
		Node* ptr = iterative_search(urlRoot->node, key1, key2);
		if(ptr == NULL){
			ptr = create_rbtree_node(key1, key2, NULL, NULL, NULL, NULL);
			rbtree_insert(urlRoot, ptr);
		}
		ptr->val += (ull)body;
		if(ptr->hNode == NULL){
			ptr->hNode = urlMinHeap.insert(ptr->val, url);
			if(ptr->hNode) {
				if(((hNode*)ptr->hNode)->rbNode){
					((Node*)((hNode*)ptr->hNode)->rbNode)->hNode=NULL;
				}
				((hNode*)ptr->hNode)->rbNode = ptr;
			}
		}
		else{
			((hNode*)ptr->hNode)->val = ptr->val; urlMinHeap.down((hNode*)ptr->hNode);
		}
	}
	printf("totel %d\n", count);
	urlMinHeap.sort();
//    Heap minheap = Heap();
//	url[0] = 'x'; url[1] = '\0';
//	int cnt = 9;
//	while(cnt-- && fscanf(fp, "%d", &body) == 1){
//		minheap.insert(body, url);
//	}
//	minheap.display();
//	minheap.sort();
}

//  121.229.74.95 - - [14/Sep/2014:00:00:33 +0800] "GET http://img.hb.aicdn.com/28ed13d351d90ca653b56473bc9b91ec64cfb2e9129bc-MBdsQP_sq120 HTTP/1.1" 200 10177 "http://huaban.com/pins/234963329/" "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36"
