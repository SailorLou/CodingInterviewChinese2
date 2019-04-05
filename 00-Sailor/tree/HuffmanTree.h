#pragma once

#include"heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

namespace HuffmanTree
{
	/*
	    definition:
	    ����n��Ȩֵ��Ϊn��Ҷ�ӽ�㣬����һ�ö�����������Ȩ·�����ȴﵽ��С��
		�������Ķ�����Ϊ���Ŷ�������Ҳ��Ϊ��������(Huffman Tree);
		�����������ص�:
		    û�ж�Ϊ1�Ľ�㣻
			n��Ҷ�ӽ��Ĺ�����������2n-1����㣻
			���������������Ҷ�ڵ�������������������ǹ���������
	*/

	/*
	    Creation
		ÿ�ΰ�Ȩֵ��С�����ö������ϲ���һ����������ȨֵΪ���������ĺͣ�Ȼ����ѹ����С�ѽ����ٴκϲ���

	*/

	/*
	����������
	����һ���ַ�������ζ��ַ����б��룬����ʹ�ø��ַ����ı���
	�洢�ռ����٣�
	�ö��������б��룺
	    a.���ҷ�֧��0��1
		b.�ַ�ֻ��Ҷ�����
	*/


	/*
	�շ������Ĵ洢�ṹ����Ҳ��һ�ֶ������ṹ��
	���ִ洢�ṹ���ʺϱ�ʾ����Ҳ�ʺϱ�ʾɭ�֡�
	*/


//below using min heap to implement Huffman tree
	//���帴�Ӷ�ΪO(N logN)

//	HuffmanTree Huffman(MinHeap H)
//	{ /* ����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight�� */
//		int i; HuffmanTree T;
//		BuildMinHeap(H); /*��H->Elements[]��Ȩֵ����Ϊ��С��*/
//		for (i = 1; i < H->Size; i++)
//		{ /*��H->Size-1�κϲ�*/
//			T = malloc(sizeof(struct TreeNode)); /*�����½��*/
//			T->Left = DeleteMin(H);
//			/*����С����ɾ��һ����㣬��Ϊ��T�����ӽ��*/
//			T->Right = DeleteMin(H);
//			/*����С����ɾ��һ����㣬��Ϊ��T�����ӽ��*/
//			T->Weight = T->Left->Weight + T->Right->Weight;
//			/*������Ȩֵ*/
//			Insert(H, T); /*����T������С��*/
//		}
//		T = DeleteMin(H);
//		return T;
//	}return T;
//	}


	
}