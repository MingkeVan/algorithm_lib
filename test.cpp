#include <iostream>
using namespace std;
struct node{
    int val;
    int b;
    node(int v = 0){ val = v; b = 1;}
};
int main(){
    node a = node(1);
    node b = node(2);
    cout << a.val << " " << b.val << endl;
    cout << a.b << " " << b.b << endl;
    cout << &a << " " << &b << endl;
    swap(a, b);
    cout << a.val << " " << b.val << endl;
    cout << a.b << " " << b.b << endl;
    cout << &a << " " << &b << endl;
}
