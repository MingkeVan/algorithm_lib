#include "heap_list.h"
ll a[10005];
int len;
int main(){
    Heap minheap = Heap();
    minheap.insert(3);
    minheap.display();
    minheap.insert(5);
    minheap.display();
    minheap.insert(4);
    minheap.display();
    minheap.insert(7);
    minheap.display();
    minheap.insert(1);
    minheap.display();
}

