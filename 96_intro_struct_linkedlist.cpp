//this class is used to give store the address , it tells us the element stores which address 
// and in linkedin list we create a new data type because no data type till now store the data + address
// through struct class we can tell the address of any variable
#include<bits/stdc++.h>
using namespace std;
struct node{ 
//node is a class (or structure) that defines how one linked-list node looks. it contains data and next pointer reference
    int data;
    node* next;
    // consturctor - same like class name
    node(int data1, node* next1){ // but inme toh data type declare karne pdenge
        data = data1;
        next = next1;
    }
};
int main(){
    vector<int> ls = {2,4,6};
    //basic method 
    node x = node(ls[0],nullptr);
    node* y = &x;
    //advance method using new 
    //new node(...) → creates a new node object in heap memory
    /*
    Every time you write:
new node(...)
a new separate node object is created in memory.
    */
   /node* y = new node(ls[0],nullptr);
    cout << y; //y stores the address 
    return 0;
}
