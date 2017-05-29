#include "stdafx.h"
#include "Tree.h"

Tree::nodeptr Tree::createnode(int num, nodeptr curr)
{
	nodeptr n = new node;
	n->parent = curr;
	n->num = num;
	n->left = NULL;
	n->right = NULL;
	return n;
}

Tree::nodeptr Tree::smallestnumberpointer(nodeptr curr)
{
	while (curr->right != NULL)
		curr = curr->right;
	return curr;
}

void Tree::addnodeprivate(int number, nodeptr curr)
{
	if (curr != NULL) {
		if (number > curr->num) {
			if (curr->left != NULL) {
				curr = curr->left;
				addnodeprivate(number, curr);
			}
			else
				curr->left = createnode(number,curr);
		}
		else if (number < curr->num) {
			if (curr->right != NULL) {
				curr = curr->right;
				addnodeprivate(number, curr);
			}
			else
				curr->right = createnode(number,curr);
		}
		else
			cout << "Your number has been added to the tree" << endl;
	}
	else if (curr == NULL)
		root = createnode(number,curr);
	
}

void Tree::searchprivate(int number, nodeptr curr)
{
	if (curr != NULL) {
		if (number > curr->num) {
			if (curr->left != NULL) {
				curr = curr->left;
				searchprivate(number, curr);
			}
			else
				cout << "Number wasn't " << number << " found in the Binary Tree" << endl;
		}
		else if (number < curr->num) {
			if (curr->right != NULL) {
				curr = curr->right;
				searchprivate(number, curr);
			}
			else
				cout << "Number wasn't " << number << " found in the Binary Tree" << endl;
		}
		else
			cout << "Your number " << number << " is found! " << endl;
	}
	else cout << "The Binary tree is empty!" << endl;
}

void Tree::delnodeprivate(int delnum, nodeptr curr)
{
	if (curr != NULL) {
		if (delnum > curr->num) {
			if (curr->left != NULL) {
				curr = curr->left;
				delnodeprivate(delnum, curr);
			}
			else cout << "Your number " << delnum << " wasn't found in the Binary Tree to Delete" << endl;
		}
		else if (delnum < curr->num) {
			if (curr->right != NULL) {
				curr = curr->right;
				delnodeprivate(delnum, curr);
			}
			else cout << "Your number " << delnum << " wasn't found in the Binary Tree to Delete" << endl;
		}
		else {
			if (curr == root) {
				if (curr->left == NULL && curr->right == NULL) {
					root = NULL;
					delete curr;
				}
				else if (curr->left != NULL && curr->right == NULL) {
					root = curr->left;
					curr->left = NULL;
					delete curr;
				}
				else if (curr->left == NULL && curr->right != NULL) {
					root = curr->right;
					curr->right = NULL;
					delete curr;
				}
				else if (curr->left != NULL && curr->right != NULL) {
					root->num = smallestnumberprivate(curr->left);
					nodeptr delptr = smallestnumberpointer(curr->left);
					delete delptr;
				}
			}
			else {
				if (curr->left == NULL && curr->right == NULL) {
					if (curr->parent->num > curr->num) {
						curr->parent->right = NULL;
						delete curr;
					}
					else {
						curr->parent->left = NULL;
						delete curr;
					}
				}
				else if (curr->left == NULL && curr->right!=NULL) {
					curr->parent->left = curr->right;
					curr->right->parent = curr->parent;
					curr->left = NULL; curr->right = NULL; curr->parent = NULL;
					delete curr;
				}
				else if (curr->left != NULL && curr->right == NULL) {
					curr->parent->right = curr->left;
					curr->left->parent = curr->parent;
					curr->left = NULL; curr->right = NULL; curr->parent = NULL;
					delete curr;
				}
				else if (curr->left != NULL && curr->right != NULL) {
					curr->num = smallestnumberprivate(curr->left);
					nodeptr delptr = smallestnumberpointer(curr->left);
					delete delptr;
				}
			}
			cout << "Your number " << delnum << " has been deleted from the Binary Tree" << endl;
		}
	}
	else cout << "The Binary Tree is empty" << endl;
}

int Tree::smallestnumberprivate(nodeptr curr)
{
	while (curr->right != NULL)
		curr = curr->right;
	return curr->num;
}

int Tree::parentprivate(int number, nodeptr curr)
{
	if (curr != NULL ) {
		if (number > curr->num) {
			if (curr->left != NULL) {
				curr = curr->left;
				parentprivate(number, curr);
			}
			else return NULL;
		}
		else if (number < curr->num) {
			if (curr->right != NULL) {
				curr = curr->right;
				parentprivate(number, curr);
			}
			else return NULL;
		}
		else {
			if (curr != root) {
				return curr->parent->num;
			}
			else return NULL;
		}
	}
	else return NULL;
}

int Tree::leftprivate(int number, nodeptr curr)
{
	if (curr != NULL) {
		if (number > curr->num) {
			if (curr->left != NULL) {
				curr = curr->left;
				leftprivate(number, curr);
			}
			else return NULL;
		}
		else if (number < curr->num) {
			if (curr->right != NULL) {
				curr = curr->right;
				leftprivate(number, curr);
			}
			else return NULL;
		}
		else {
			if (curr->left != NULL)
				return curr->left->num;
			else return NULL;
		}
	}
	else return NULL;
}

int Tree::rightprivate(int number, nodeptr curr)
{
	if (curr != NULL) {
		if (number > curr->num) {
			if (curr->left != NULL) {
				curr = curr->left;
				leftprivate(number, curr);
			}
			else return NULL;
		}
		else if (number < curr->num) {
			if (curr->right != NULL) {
				curr = curr->right;
				leftprivate(number, curr);
			}
			else return NULL;
		}
		else {
			if (curr->left != NULL)
				return curr->left->num;
			else return NULL;
		}
	}
	else return NULL;
}

int Tree::depthprivate(nodeptr curr,int i)
{
	if (curr != NULL) {
		if(curr->left == NULL & curr->right == NULL) {
			return i;
		}
		else if (curr->left != NULL && curr->right == NULL) {
			curr = curr->left;
			i++;
			depthprivate(curr, i);
		}
		else if (curr->left == NULL && curr->right != NULL) {
			curr = curr->right;
			i++;
			depthprivate(curr, i);
		}
		else if (curr->left != NULL && curr->right != NULL) {
			curr = curr->left;
			i++;
			depthprivate(curr, i);
		}
	}
	else return i;
}

bool Tree::isexternalprivate(int number, nodeptr curr)
{
	if (curr != NULL) {
		if (number > curr->num) {
			if (curr->left != NULL) {
				curr = curr->left;
				isexternalprivate(number, curr);
			}
			return false;
		}
		else if (number < curr->num) {
			if (curr->right != NULL) {
				curr = curr->right;
				isexternalprivate(number, curr);
			}
			return false;
		}
		else {
			if (curr->left == NULL&&curr->right == NULL)
				return true;
			else return false;
		}
	}
	else return true;
}


Tree::Tree():root(NULL)
{
}

Tree::~Tree()
{
}

void Tree::Addnode(int number)
{
	nodeptr pointer = root;
	addnodeprivate(number,pointer);
}

void Tree::Delnode(int delnum)
{
	nodeptr pointer = root;
	delnodeprivate(delnum, pointer);
}


void Tree::Search(int searchnum)
{
	nodeptr pointer = root;
	searchprivate(searchnum, pointer);
}

int Tree::Smallestnumber()
{
	nodeptr pointer = root;
	return smallestnumberprivate(pointer);
}

int Tree::Root()
{
	return root->num;
}

int Tree::Parent(int number)
{
	nodeptr pointer = root;
	return parentprivate(number, pointer);
}

int Tree::Left(int number)
{
	nodeptr pointer = root;
	return leftprivate(number, pointer);
}

int Tree::Right(int number)
{
	nodeptr pointer = root;
	return rightprivate(number, pointer);
}

int Tree::Depth()
{
	nodeptr pointer = root;
	int index = 0;
	return depthprivate(pointer,index);
}

bool Tree::isEmpty()
{
	if (root == NULL)
		return true;
	else return false;
}

bool Tree::isExternal(int number)
{
	nodeptr pointer = root;
	return isexternalprivate(number, pointer);
}



