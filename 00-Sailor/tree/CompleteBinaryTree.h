#pragma once

namespace CompleteBinaryTree
{
	const int c_max = 10;
//array
	int tree[c_max];

// root node
	int root = tree[1];

// parent node of non-root node
	int i;//i!=1
	int parentNode = tree[i / 2];
// left node
	int j;
	// if 2*j<c_max
	int leftNode = tree[2 * j];
	// if 2*j+1<c_max
	int rightNode = tree[2 * j+1];

	//else there are not sub-nodes


}