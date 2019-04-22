// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<string> bst;
   
    string s;
    inFile >> s;
    while (inFile) {
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = "tree";
    bst.deleteItem(s);
    print(bst.postOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;
    bst.makeEmpty();

    cout << "number of nodes in tree after clear is " << bst.countNodes() << endl;


    BST_312<char> bst2;
    char input;
    cout<<"enter 10 chars"<<endl;
    while(bst2.countNodes()<10) {
        cin>>input;
        bst2.insertItem(input);
    }
    cout<<"num nodes"<<bst2.countNodes()<<endl;

    cout << "postorder traversal is " << endl;
    print(bst2.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst2.preOrderTraversal());
    cout << endl;


    cout << "inorder traversal is " << endl;
    print(bst2.inOrderTraversal());
    cout << endl;

    while(bst2.countNodes()) {
        print(bst2.inOrderTraversal());
        cout <<endl;
        char del;
        cout<<"enter char to find"<<endl;
        cin>>del;
        cout<<bst2.isItemInTree(del)<<endl;

        cout<<"enter char to delete"<<endl;
        cin>>del;
        bst2.deleteItem(del);
        
    }
    bst2.deleteItem('h');
    cout<<bst2.isItemInTree('d');
}

