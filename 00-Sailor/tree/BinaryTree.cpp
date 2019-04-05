#include "Tree.h"

namespace Tree
{
    namespace BinaryTreeWithRecursiveTraversal
    {
        BTree CreatBinTree()
        {
            BTree pA = (BTree)malloc(sizeof(BTNode));
            BTree pB = (BTree)malloc(sizeof(BTNode));
            BTree pD = (BTree)malloc(sizeof(BTNode));
            BTree pE = (BTree)malloc(sizeof(BTNode));
            BTree pC = (BTree)malloc(sizeof(BTNode));
            BTree pF = (BTree)malloc(sizeof(BTNode));
            
            pA->data = 'A';
            pB->data = 'B';
            pD->data = 'D';
            pE->data = 'E';
            pC->data = 'C';
            pF->data = 'F';
            
            pA->pLchild = pB;
            pA->pRchild = pC;
            pB->pLchild = pD;
            pB->pRchild = pE;
            pD->pLchild = pD->pRchild = NULL;
            pE->pLchild = pE->pRchild = NULL;
            pC->pLchild = pF;
            pC->pRchild = NULL;
            pF->pLchild = pF->pRchild = NULL;	
            
            return pA;
        }
        void PreOrderTraversal(BTree pTree)
        {
            if(pTree)
            {
                printf("%c ",pTree->data);
                PreOrderTraversal(pTree->pLchild);
                PreOrderTraversal(pTree->pRchild);
            }
        }
        void InOrderTraversal(BTree pTree)
        {
            if(pTree)
            {
                InOrderTraversal(pTree->pLchild);
                printf("%c ",pTree->data);
                InOrderTraversal(pTree->pRchild);
            }
        }
        void PostOrderTraversal(BTree pTree)
        {
             if(pTree)
            {
                PostOrderTraversal(pTree->pLchild);
                PostOrderTraversal(pTree->pRchild);
                printf("%c ",pTree->data);
            }
        }
    }

    namespace BinaryTreeWithoutRecursiveTraversal
    {
        /*
         前序遍历的非递归实现
         */
         void PreOrderTraversal(BTree pTree)
         {
              BTStack::Stack * stack = BTStack::CreateStack();  //创建一个空栈
              BTree node_pop;                 //用来保存出栈节点
              BTree pCur = pTree;             //定义用来指向当前访问的节点的指针            
              
              //直到当前节点pCur为NULL且栈空时，循环结束
              while(pCur || !BTStack::IsEmpty(stack))
              {
                 //从根节点开始，输出当前节点，并将其入栈，
                 //同时置其左孩子为当前节点，直至其没有左孩子，
                 //直到前节点为NULL
                  while(pCur)
                  {
                      printf("%c ", pCur->data);//遍历该点
                      BTStack::PushStack(stack,pCur);
                      pCur = pCur->pLchild;
                  }
              
                 //如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈，
                 //同时置其右孩子为当前节点,循环判断，直至pCur不为空
                 if(!BTStack::IsEmpty(stack))
                 {
                 	//pCur = BTStack::GetTop(stack);
                 	BTStack::PopStack(stack,&pCur);
                 	pCur = pCur->pRchild;			
                 }
              }
         }
         
         /*
         中序遍历的非递归实现
         */
         void InOrderTraversal(BTree pTree)
         {
             BTStack::Stack* stack = BTStack::CreateStack();  //创建一个空栈
             BTree pCur = pTree;             //定义指向当前访问的节点的指针
             
             //直到当前节点pCur为NULL且栈空时，循环结束
             while(pCur || !BTStack::IsEmpty(stack))
             {
                 while(pCur)
                {
                    //如果pCur的左孩子不为空，则将其入栈，
                    //并置其左孩子为当前节点
                    BTStack::PushStack(stack,pCur);
                    pCur = pCur->pLchild;
                }

                if(!BTStack::IsEmpty(stack))
                {
                    //pCur = BTStack::GetTop(stack);
                    BTStack::PopStack(stack,&pCur);
                    printf("%c ",pCur->data);
                    pCur = pCur->pRchild;
                }
           }
         }
         
         /*
         后序遍历的非递归实现
         */
         void PostOrderTraversal(BTree pTree)
         {
            BTStack::Stack* stack = BTStack::CreateStack();  //创建一个空栈
            BTree node_pop;          //用来保存出栈的节点
            BTree pCur;              //定义指针，指向当前节点
            BTree pPre = NULL;       //定义指针，指向上一各访问的节点
            
            //先将树的根节点入栈
            BTStack::PushStack(stack,pTree);  
            //直到栈空时，结束循环
            while(!BTStack::IsEmpty(stack))
            {
                pCur = BTStack::GetTop(stack);   //当前节点置为栈顶节点
                if((pCur->pLchild==NULL && pCur->pRchild==NULL) || 
                	(pPre!=NULL && (pCur->pLchild==pPre || pCur->pRchild ==pPre)))
                {
                    //如果当前节点没有左右孩子，(pCur->pLchild==NULL && pCur->pRchild==NULL)
                    //或者有左孩子或有孩子，但已经被访问输出，pPre!=NULL
                    //则直接输出该节点，将其出栈，将其设为上一个访问的节点
                    printf("%c ", pCur->data);
                    BTStack::PopStack(stack,&node_pop);
                    pPre = pCur;
                }
                else
                {
                    //如果不满足上面两种情况,则将其右孩子左孩子依次入栈
                    if(pCur->pRchild != NULL)
                    	BTStack::PushStack(stack,pCur->pRchild);
                    if(pCur->pLchild != NULL)
                    	BTStack::PushStack(stack,pCur->pLchild);
            	}
            }
         }

/* 另外一种无递归后续遍历实现*/
/*
         void PostOrderTraversal(BTree *root)    //非递归后序遍历
         {
             BTStack::Stack* stack = BTStack::CreateStack();  //创建一个空栈
             BTree *p=root;
             BTree *temp;
             while(p!=NULL||!s.empty())
             {
                 while(p!=NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点 
                  {
                     BTStack::PushStack(stack,p);
                     StackNode *topStackNode= BTStack::GetTopStackNode(stack);
                     topStackNode->mark =1;

                     p=p->pLchild;
                 }

                 if(!s.empty())
                 {
                     p = BTStack::GetTop(stack);
                     StackNode *topStackNode= BTStack::GetTopStackNode(stack);
                     int mark = topStackNode->mark;
                     BTStack::PopStack(stack);

                     if(mark==1)     //表示是第一次出现在栈顶 
                      {
                         BTStack::PushStack(stack,p);
                         StackNode *topStackNode= BTStack::GetTopStackNode(stack);
                         topStackNode->mark =2;
                         p=p->rchild;
                     }
                     else                        //第二次出现在栈顶 
                      {
                         printf("%c ", p->data);
                         p=NULL;
                     }
                 }
             }    
         }
*/

         void LevelOrderTraversal(BTree pTree)
         {
             if(pTree == nullptr)
                 return;

             BTQueue::LinkQueue * queue = BTQueue::CreateLinkQueue();
             BTQueue::EnQueue(queue,pTree);
             BTree tree;
             
             while(!BTQueue::IsEmptyQueue(queue))
             {
                 tree = BTQueue::DeleteQueue(queue);

                 printf("%c ", tree->data); // access this node

                 if(tree->pLchild)
                     BTQueue::EnQueue(queue,tree->pLchild);

                 if(tree->pRchild)
                     BTQueue::EnQueue(queue,tree->pRchild);
             }
         }
    }
}