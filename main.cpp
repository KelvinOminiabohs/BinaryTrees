/*
 
 Binary Search Trees
 1. Write the definition of the function nodeCount that returns the number of nodes in the binary tree. Add this function to the class binaryTreeType and create a program to test this function.
 2. Write the definition of the function leavesCount that takes as a parameter a pointer to the root node of a binary tree and returns the number of leaves in a binary tree. Add this function to the class binaryTreeType and create a program to test this function.
 
 */

#include <iostream>
#include <string>
#include "binaryTreeType.h"



using namespace std;



int main()

{
    binaryTreeType tree;
    
    
    tree.insert();
    cout<<endl;
    tree.insert();
    cout<<endl;
    tree.insert();
    cout<<endl;
    tree.insert();
    
    
    cout<<endl;
    
    
    
    cout<<endl;
    
    
    
    tree.postorderTrav();
    
    tree.deletenode();
    
    cout<<endl<<endl;
    
    tree.postorderTrav();
    
    cout << endl;
    
    int nodet =  tree.treenodecount();
    cout<<"Number of Nodes: "<<nodet<<endl;
    
    
    
    int leavess=tree.treeleavecount();
    cout<<"Number of Leaves: "<< leavess<<endl;
    
    
    system("PAUSE");
    return 0;
}


