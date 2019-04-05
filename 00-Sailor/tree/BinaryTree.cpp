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
         ǰ������ķǵݹ�ʵ��
         */
         void PreOrderTraversal(BTree pTree)
         {
              BTStack::Stack * stack = BTStack::CreateStack();  //����һ����ջ
              BTree node_pop;                 //���������ջ�ڵ�
              BTree pCur = pTree;             //��������ָ��ǰ���ʵĽڵ��ָ��            
              
              //ֱ����ǰ�ڵ�pCurΪNULL��ջ��ʱ��ѭ������
              while(pCur || !BTStack::IsEmpty(stack))
              {
                 //�Ӹ��ڵ㿪ʼ�������ǰ�ڵ㣬��������ջ��
                 //ͬʱ��������Ϊ��ǰ�ڵ㣬ֱ����û�����ӣ�
                 //ֱ��ǰ�ڵ�ΪNULL
                  while(pCur)
                  {
                      printf("%c ", pCur->data);//�����õ�
                      BTStack::PushStack(stack,pCur);
                      pCur = pCur->pLchild;
                  }
              
                 //�����ǰ�ڵ�pCurΪNULL��ջ���գ���ջ���ڵ��ջ��
                 //ͬʱ�����Һ���Ϊ��ǰ�ڵ�,ѭ���жϣ�ֱ��pCur��Ϊ��
                 if(!BTStack::IsEmpty(stack))
                 {
                 	//pCur = BTStack::GetTop(stack);
                 	BTStack::PopStack(stack,&pCur);
                 	pCur = pCur->pRchild;			
                 }
              }
         }
         
         /*
         ��������ķǵݹ�ʵ��
         */
         void InOrderTraversal(BTree pTree)
         {
             BTStack::Stack* stack = BTStack::CreateStack();  //����һ����ջ
             BTree pCur = pTree;             //����ָ��ǰ���ʵĽڵ��ָ��
             
             //ֱ����ǰ�ڵ�pCurΪNULL��ջ��ʱ��ѭ������
             while(pCur || !BTStack::IsEmpty(stack))
             {
                 while(pCur)
                {
                    //���pCur�����Ӳ�Ϊ�գ�������ջ��
                    //����������Ϊ��ǰ�ڵ�
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
         ��������ķǵݹ�ʵ��
         */
         void PostOrderTraversal(BTree pTree)
         {
            BTStack::Stack* stack = BTStack::CreateStack();  //����һ����ջ
            BTree node_pop;          //���������ջ�Ľڵ�
            BTree pCur;              //����ָ�룬ָ��ǰ�ڵ�
            BTree pPre = NULL;       //����ָ�룬ָ����һ�����ʵĽڵ�
            
            //�Ƚ����ĸ��ڵ���ջ
            BTStack::PushStack(stack,pTree);  
            //ֱ��ջ��ʱ������ѭ��
            while(!BTStack::IsEmpty(stack))
            {
                pCur = BTStack::GetTop(stack);   //��ǰ�ڵ���Ϊջ���ڵ�
                if((pCur->pLchild==NULL && pCur->pRchild==NULL) || 
                	(pPre!=NULL && (pCur->pLchild==pPre || pCur->pRchild ==pPre)))
                {
                    //�����ǰ�ڵ�û�����Һ��ӣ�(pCur->pLchild==NULL && pCur->pRchild==NULL)
                    //���������ӻ��к��ӣ����Ѿ������������pPre!=NULL
                    //��ֱ������ýڵ㣬�����ջ��������Ϊ��һ�����ʵĽڵ�
                    printf("%c ", pCur->data);
                    BTStack::PopStack(stack,&node_pop);
                    pPre = pCur;
                }
                else
                {
                    //��������������������,�����Һ�������������ջ
                    if(pCur->pRchild != NULL)
                    	BTStack::PushStack(stack,pCur->pRchild);
                    if(pCur->pLchild != NULL)
                    	BTStack::PushStack(stack,pCur->pLchild);
            	}
            }
         }

/* ����һ���޵ݹ��������ʵ��*/
/*
         void PostOrderTraversal(BTree *root)    //�ǵݹ�������
         {
             BTStack::Stack* stack = BTStack::CreateStack();  //����һ����ջ
             BTree *p=root;
             BTree *temp;
             while(p!=NULL||!s.empty())
             {
                 while(p!=NULL)              //��������һֱ����������ֱ������û���������Ľ�� 
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

                     if(mark==1)     //��ʾ�ǵ�һ�γ�����ջ�� 
                      {
                         BTStack::PushStack(stack,p);
                         StackNode *topStackNode= BTStack::GetTopStackNode(stack);
                         topStackNode->mark =2;
                         p=p->rchild;
                     }
                     else                        //�ڶ��γ�����ջ�� 
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