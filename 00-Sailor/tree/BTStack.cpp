#include"Tree.h"
namespace Tree
{
    namespace BTStack
    {
        //����һ����ջ,������ָ���ջ��ָ��   
        BTStack::Stack* CreateStack()  
        {
            BTStack::Stack* pS = (BTStack::Stack*)malloc(sizeof(BTStack::Stack));
            pS->pTop = (StackNode*)malloc(sizeof(StackNode));
            if(NULL==pS || NULL==pS->pTop)
            {
               printf("malloc failed");
               exit(-1);
            }
            else
            {
                pS->pBottom = pS->pTop;  
                pS->pBottom->pNext = NULL;  
            }
            return pS;
        }
        
        //�жϸ�ջ�Ƿ�Ϊ��     
        bool IsEmpty(BTStack::Stack* pS)  
        {  
            if(pS->pTop == pS->pBottom)  
               return true;  
            else  
               return false;  
        }  
          
        //��pSָ��ָ���ջ��ѹ������val  
        void PushStack(BTStack::Stack* pS,BTree val)  
        {  
            StackNode* pNew = (StackNode*)malloc(sizeof(StackNode));  
            if(NULL==pNew)  
            {  
                printf("malloc failed");  
                exit(-1);  
            }  
            else  
            {  
                pNew->data = val;  
                pNew->pNext = pS->pTop;  
                pS->pTop = pNew;  
            }  
            return ;
        }  
           
        //��ջ���Ƴ����ݣ������Ƴ������ݱ�����pDataָ����ָ���λ��  
        bool BTStack::PopStack(BTStack::Stack* pS,BTree *pData)  
        {  
             if(IsEmpty(pS))
             {
                 printf("stack is empty");
                 return false;
             }
             else  
             {  
                 StackNode* p = pS->pTop;  
                 *pData = p->data;  
                 pS->pTop = p->pNext;  
                 free(p);  
                 p = NULL;  
                 return true;  
             }  
        }  
          
        //����ջ������ջ����ջ�����ջ�е�����  
        void TraverseStack(BTStack::Stack* pS)  
        {  
            StackNode* pCurrent = pS->pTop;   
            printf("Now datas int the stack are:\n");  
            while(pCurrent != pS->pBottom)  
            {  
            	printf("%d ",pCurrent->data);  
            	pCurrent = pCurrent->pNext;  
            }  
            printf("\n");  
            return ;  
        }  
           
        //���ջ�������仹ԭΪ��ջ  
        void ClearStack(BTStack::Stack* pS)  
        {  
            if(IsEmpty(pS))  
            	return ;  
            else  
            {  
                StackNode* p = pS->pTop;  
                StackNode* r = NULL;  
                while(p != pS->pBottom)  
                {  
                    r = p->pNext;  
                    free(p);  
                    p = r;  
                }  
                pS->pTop = pS->pBottom;  
            }  
        }  
        
        //���ջ���գ�����ջ��Ԫ��,���ջ�գ����ؿ�ָ��
        BTree BTStack::GetTop(BTStack::Stack* pS)
        {
            if(!IsEmpty(pS))
                return pS->pTop->data;
            else
                return NULL;
        }
    }
}