#pragma once
#include<iostream>
using namespace std;

class Tree
{
protected:
	typedef struct node{
		node* parent;
		int num;
		node* left;
		node* right;
	}*nodeptr;
	nodeptr root;
	nodeptr createnode(int,nodeptr);
	nodeptr smallestnumberpointer(nodeptr);
	void addnodeprivate(int,nodeptr);
	void searchprivate(int, nodeptr);
	void delnodeprivate(int,nodeptr);
	int smallestnumberprivate(nodeptr);
	int parentprivate(int, nodeptr);
	int leftprivate(int, nodeptr);
	int rightprivate(int, nodeptr);
	int depthprivate(nodeptr, int);
	bool isexternalprivate(int, nodeptr);
public:
	Tree();
	~Tree();
	void Addnode(int);
	void Delnode(int);
	void Search(int);
	int Smallestnumber();
	int Root();
	int Parent(int);
	int Left(int);
	int Right(int);
	int Depth();
	bool isEmpty();
	bool isExternal(int);
};

