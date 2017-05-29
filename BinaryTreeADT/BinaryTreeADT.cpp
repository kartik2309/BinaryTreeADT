// BinaryTreeADT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Associative.h"

int main()
{
	//To Access tree functions "BinaryTree.Yourfunction"
	BinaryTree.Addnode(5);
	BinaryTree.Addnode(9);
	BinaryTree.Addnode(0);
	BinaryTree.Addnode(89);
	BinaryTree.Addnode(8);
	BinaryTree.Addnode(23);
	BinaryTree.Addnode(6);
	BinaryTree.Addnode(2);
	BinaryTree.Addnode(4);
	BinaryTree.Addnode(1);
	BinaryTree.Addnode(6);
	BinaryTree.Addnode(17);
	cout << BinaryTree.Depth() << endl;
	system("pause");
    return 0;
}

