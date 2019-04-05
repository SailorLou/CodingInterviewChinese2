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
     
     printf("�ݹ�ʵ��ǰ����������");
     Tree::BinaryTreeWithRecursiveTraversal::PreOrderTraversal(pTree);
     printf("\n");
     printf("�ݹ�ʵ��zhong����������");
     Tree::BinaryTreeWithRecursiveTraversal::InOrderTraversal(pTree);
     printf("\n");
     printf("�ݹ�ʵ��hou����������");
     Tree::BinaryTreeWithRecursiveTraversal::PostOrderTraversal(pTree);
     printf("\n");
     //BinaryTreeWithRecursiveTraversal::LevelOrderTraversal(pTree);
      printf("�ǵݹ�ʵ��ǰ����������");
     Tree::BinaryTreeWithoutRecursiveTraversal::PreOrderTraversal(pTree);
     printf("\n");
      printf("�ǵݹ�ʵ��������������");
     Tree::BinaryTreeWithoutRecursiveTraversal::InOrderTraversal(pTree);
     printf("\n");
     printf("�ǵݹ�ʵ�ֺ�����������");
     Tree::BinaryTreeWithoutRecursiveTraversal::PostOrderTraversal(pTree);
     printf("\n");
     printf("�ǵݹ�Based on Layer����������");
     Tree::BinaryTreeWithoutRecursiveTraversal::LevelOrderTraversal(pTree);
     printf("\n");
     printf("=======end to traverse binary tree =================\n");
}