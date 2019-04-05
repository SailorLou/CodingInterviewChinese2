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

        //创建空栈的函数
        Stack* CreateStack();
        //入栈函数
        void PushStack(Stack*,BTree);
        //遍历栈
        void TraverseStack(Stack*);
        //出栈函数
        bool PopStack(Stack*,BTree *);
        //判断栈空函数 
        bool IsEmpty(Stack*);
        //清空栈
        void ClearStack(Stack*);
        //取栈顶元素
        BTree GetTop(Stack*);
     }

     //Queue 
     namespace BTQueue
     {
         //单向链表
         typedef struct LinkQueueNode
         {
             struct LinkQueueNode *next;
             BTNode *data;
         }LinkQueueNode;

         typedef struct LinkQueue
         {//形成队列  
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
             在指针pTree所指的二叉排序树中递归查找关键字为key的元素，
             若查找成功，则返回指向该元素节点的指针，否则返回NULL
         */
         BSTree search(BSTree pTree,int key);
         //BSTree searchMin(BSTree pTree);
         //BSTree searchMax(BSTree pTree);
         /*
             在指针pTree所指的二叉排序树中递归查找关键字为key的元素，
             若查找成功，则返回ture，并查找到的数据对应的节点指针保存在p中，
             否则返回false，并将查找路径上访问的最后一个节点指针保存在p中。
             这里的参数parent指向每次递归遍历的子树的根节点的父节点，即始终是参数pTree的父     节       点 ，
             它的初始值为NULL，其目的是跟踪查找路径上访问的当前节点的父节点（即上一个访问节           点  ）
             该函数用来被后面的插入函数调用。
         */
         bool search_BSTree(BSTree pTree,int key,BSTree parent,BSTree &p);

         /*
         当在pTree所指向的二叉排序树中查找不到关键字为key的数据元素时，
         将其插入该二叉排序树，并返回ture，否则返回false。
         树空时插入会改变根节点的值，因此要传入引用。
         */
         // no recursion
         bool insert(BSTree &pTree,int key);
         BSTree InsertWithRecursion(BSTree &pTree,int key);

         /*
         采用第一种算法从二叉排序树中删除指针p所指向的节点,
         并在保持二叉排序树有序的情况下，将其左右子树重接到该二叉排序树中.
         该函数主要用来被后面的删除函数调用
         */
         void delete_Node1(BSTree &p);
         /*
          采用第二种算法从二叉排序树中删除指针p所指向的节点,
          并在保持二叉排序树有序的情况下，将其左右子树重接到该二叉排序树中.
          该函数主要用来被后面的删除函数调用
          */
        void delete_Node2(BSTree &p);
        /*
        若pTree所指向的二叉排序树中查找到关键字为key的数据元素，
        则删除该元素对应的节点，并返回true，否则返回false
        如果要删除的恰好是根节点，则会改变根节点的值，因此要传入引用
        */
        bool delete_BSTree(BSTree &pTree,int key);

        /*
        根据所给的长为len的arr数组，按数组中元素的顺序构建一棵二叉排序树
        */
        BSTree create_BSTree(int *arr,int len);

        /*
        递归中序遍历二叉排序树，得到元素从小到大有序排列的序列
        */
        void in_traverse(BSTree pTree);

        void Test();
     }
     
}
