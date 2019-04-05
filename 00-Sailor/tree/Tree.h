#pragma once
#include<stdio.h>
#include<stdlib.h>

namespace Tree
{
    // binary tree node
     typedef struct BTNode
     {
         char data;
         struct BTNode *pLchild;
         struct BTNode *pRchild;
     }BTNode, *BTree;
     
     //stack node
     namespace BTStack
     {
         typedef struct StackNode
         {
             BTree data;
             struct StackNode *pNext;
         };

        typedef struct Stack
        {
            StackNode* pTop;
            StackNode* pBottom;
        };

        //������ջ�ĺ���
        Stack* CreateStack();
        //��ջ����
        void PushStack(Stack*,BTree);
        //����ջ
        void TraverseStack(Stack*);
        //��ջ����
        bool PopStack(Stack*,BTree *);
        //�ж�ջ�պ��� 
        bool IsEmpty(Stack*);
        //���ջ
        void ClearStack(Stack*);
        //ȡջ��Ԫ��
        BTree GetTop(Stack*);
     }

     //Queue 
     namespace BTQueue
     {
         //��������
         typedef struct LinkQueueNode
         {
             struct LinkQueueNode *next;
             BTNode *data;
         }LinkQueueNode;

         typedef struct LinkQueue
         {//�γɶ���  
             LinkQueueNode *front;
             LinkQueueNode *rear;
         };

         LinkQueue* CreateLinkQueue();
         bool IsEmptyQueue(LinkQueue*);
         void EnQueue(LinkQueue *queue,BTNode* node);
         BTNode* DeleteQueue(LinkQueue *queue);
         BTNode* GetHead(LinkQueue *queue);
     }

     namespace BinaryTreeWithRecursiveTraversal
     {
        BTree CreatBinTree();
        void PreOrderTraversal(BTree);
        void InOrderTraversal(BTree);
        void PostOrderTraversal(BTree);
        //bool IsEmpty( BTree);
    }

     namespace BinaryTreeWithoutRecursiveTraversal
     {
        //BTree CreatBinTree();
        void PreOrderTraversal(BTree);
        void InOrderTraversal(BTree);
        void PostOrderTraversal(BTree);
        void LevelOrderTraversal(BTree);// based on layer
        //bool IsEmpty( BTree);
    }
     //BST
     namespace BinarySearchTree
     {
         typedef struct BSTNode
        {
             int data;
             struct BSTNode *lchild;
             struct BSTNode *rchild;
        }BSTNode,*BSTree;

         /*
             ��ָ��pTree��ָ�Ķ����������еݹ���ҹؼ���Ϊkey��Ԫ�أ�
             �����ҳɹ����򷵻�ָ���Ԫ�ؽڵ��ָ�룬���򷵻�NULL
         */
         BSTree search(BSTree pTree,int key);
         //BSTree searchMin(BSTree pTree);
         //BSTree searchMax(BSTree pTree);
         /*
             ��ָ��pTree��ָ�Ķ����������еݹ���ҹؼ���Ϊkey��Ԫ�أ�
             �����ҳɹ����򷵻�ture�������ҵ������ݶ�Ӧ�Ľڵ�ָ�뱣����p�У�
             ���򷵻�false����������·���Ϸ��ʵ����һ���ڵ�ָ�뱣����p�С�
             ����Ĳ���parentָ��ÿ�εݹ�����������ĸ��ڵ�ĸ��ڵ㣬��ʼ���ǲ���pTree�ĸ�     ��       �� ��
             ���ĳ�ʼֵΪNULL����Ŀ���Ǹ��ٲ���·���Ϸ��ʵĵ�ǰ�ڵ�ĸ��ڵ㣨����һ�����ʽ�           ��  ��
             �ú�������������Ĳ��뺯�����á�
         */
         bool search_BSTree(BSTree pTree,int key,BSTree parent,BSTree &p);

         /*
         ����pTree��ָ��Ķ����������в��Ҳ����ؼ���Ϊkey������Ԫ��ʱ��
         �������ö�����������������ture�����򷵻�false��
         ����ʱ�����ı���ڵ��ֵ�����Ҫ�������á�
         */
         // no recursion
         bool insert(BSTree &pTree,int key);
         BSTree InsertWithRecursion(BSTree &pTree,int key);

         /*
         ���õ�һ���㷨�Ӷ�����������ɾ��ָ��p��ָ��Ľڵ�,
         ���ڱ��ֶ������������������£��������������ؽӵ��ö�����������.
         �ú�����Ҫ�����������ɾ����������
         */
         void delete_Node1(BSTree &p);
         /*
          ���õڶ����㷨�Ӷ�����������ɾ��ָ��p��ָ��Ľڵ�,
          ���ڱ��ֶ������������������£��������������ؽӵ��ö�����������.
          �ú�����Ҫ�����������ɾ����������
          */
        void delete_Node2(BSTree &p);
        /*
        ��pTree��ָ��Ķ����������в��ҵ��ؼ���Ϊkey������Ԫ�أ�
        ��ɾ����Ԫ�ض�Ӧ�Ľڵ㣬������true�����򷵻�false
        ���Ҫɾ����ǡ���Ǹ��ڵ㣬���ı���ڵ��ֵ�����Ҫ��������
        */
        bool delete_BSTree(BSTree &pTree,int key);

        /*
        ���������ĳ�Ϊlen��arr���飬��������Ԫ�ص�˳�򹹽�һ�ö���������
        */
        BSTree create_BSTree(int *arr,int len);

        /*
        �ݹ���������������������õ�Ԫ�ش�С�����������е�����
        */
        void in_traverse(BSTree pTree);

        void Test();
     }
     
}
