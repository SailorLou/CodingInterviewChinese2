#pragma once

#include"heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

namespace HuffmanTree
{
	/*
	    definition:
	    给定n个权值作为n个叶子结点，构造一棵二叉树，若带权路径长度达到最小，
		称这样的二叉树为最优二叉树，也称为哈夫曼树(Huffman Tree);
		哈夫曼树的特点:
		    没有度为1的结点；
			n个叶子结点的哈夫曼树共有2n-1个结点；
			哈夫曼树的任意非叶节点的左右子树交换后仍是哈夫曼树；
	*/

	/*
	    Creation
		每次把权值最小的两棵二叉树合并成一个树，且其权值为两个子树的和，然后再压入最小堆进行再次合并；

	*/

	/*
	哈夫曼编码
	给定一段字符串，如何对字符进行编码，可以使得该字符串的编码
	存储空间最少；
	用二叉树进行编码：
	    a.左右分支：0、1
		b.字符只在叶结点上
	*/


	/*
	赫夫曼树的存储结构，它也是一种二叉树结构，
	这种存储结构既适合表示树，也适合表示森林。
	*/


//below using min heap to implement Huffman tree
	//整体复杂度为O(N logN)

//	HuffmanTree Huffman(MinHeap H)
//	{ /* 假设H->Size个权值已经存在H->Elements[]->Weight里 */
//		int i; HuffmanTree T;
//		BuildMinHeap(H); /*将H->Elements[]按权值调整为最小堆*/
//		for (i = 1; i < H->Size; i++)
//		{ /*做H->Size-1次合并*/
//			T = malloc(sizeof(struct TreeNode)); /*建立新结点*/
//			T->Left = DeleteMin(H);
//			/*从最小堆中删除一个结点，作为新T的左子结点*/
//			T->Right = DeleteMin(H);
//			/*从最小堆中删除一个结点，作为新T的右子结点*/
//			T->Weight = T->Left->Weight + T->Right->Weight;
//			/*计算新权值*/
//			Insert(H, T); /*将新T插入最小堆*/
//		}
//		T = DeleteMin(H);
//		return T;
//	}return T;
//	}


	
}