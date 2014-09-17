#include "heap_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
ll a[10005];
char ip[100];
char url[100];
char refer[100];
char agent[100];
char status[100];
//int status;
char body[100];

int main(){
	FILE* fp=fopen("test.in", "r");
	while(fscanf(fp, "%[0-9|.] %*[^]]%*c %*s %s %*s %*s %s \"%[^\"]%*c \"%[^\"]%*c%*c", ip, url, body, refer, agent) == 6){
		puts(ip);
		puts(url);
		puts(refer);
		puts(agent);
		puts(status);
//		printf("%d\n", status);
		puts(body);
//		printf("%d\n", len);
	}
//    Heap minheap = Heap();
//    minheap.insert(3);
//    minheap.display();
//    minheap.insert(4);
//    minheap.display();
//    minheap.insert(5);
//    minheap.display();
//    minheap.insert(7);
//    minheap.display();
//    minheap.insert(1);
//    minheap.display();
//	minheap.sort();
}

//  121.229.74.95 - - [14/Sep/2014:00:00:33 +0800] "GET http://img.hb.aicdn.com/28ed13d351d90ca653b56473bc9b91ec64cfb2e9129bc-MBdsQP_sq120 HTTP/1.1" 200 10177 "http://huaban.com/pins/234963329/" "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36"
