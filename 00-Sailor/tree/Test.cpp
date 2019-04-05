#include"Tree.h"

void TestBinaryTreeTraversal();

void main()
{
    TestBinaryTreeTraversal();
    Tree::BinarySearchTree::Test();

    getchar();
}

void TestBinaryTreeTraversal()
{
     printf("=======begin to traverse binary tree =================\n");
     Tree::BTree pTree = Tree::BinaryTreeWithRecursiveTraversal::CreatBinTree();
     
     printf("递归实现前序遍历结果：");
     Tree::BinaryTreeWithRecursiveTraversal::PreOrderTraversal(pTree);
     printf("\n");
     printf("递归实现zhong序遍历结果：");
     Tree::BinaryTreeWithRecursiveTraversal::InOrderTraversal(pTree);
     printf("\n");
     printf("递归实现hou序遍历结果：");
     Tree::BinaryTreeWithRecursiveTraversal::PostOrderTraversal(pTree);
     printf("\n");
     //BinaryTreeWithRecursiveTraversal::LevelOrderTraversal(pTree);
      printf("非递归实现前序遍历结果：");
     Tree::BinaryTreeWithoutRecursiveTraversal::PreOrderTraversal(pTree);
     printf("\n");
      printf("非递归实现中序遍历结果：");
     Tree::BinaryTreeWithoutRecursiveTraversal::InOrderTraversal(pTree);
     printf("\n");
     printf("非递归实现后序遍历结果：");
     Tree::BinaryTreeWithoutRecursiveTraversal::PostOrderTraversal(pTree);
     printf("\n");
     printf("非递归Based on Layer序遍历结果：");
     Tree::BinaryTreeWithoutRecursiveTraversal::LevelOrderTraversal(pTree);
     printf("\n");
     printf("=======end to traverse binary tree =================\n");
}