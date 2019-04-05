#include"Tree.h"
namespace Tree
{
    namespace BTQueue
    {
        //��ʼ������
         LinkQueue * CreateLinkQueue()
         {
             LinkQueue *queue = (LinkQueue*)malloc(sizeof(LinkQueue));
             LinkQueueNode *p;
             p = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));

             queue->rear = queue->front = p;
             queue->front = p;
             queue->rear = p;
             queue->front->next = nullptr;

             return queue;
         }
         
         
         //�ж϶����Ƿ�Ϊ��
         bool IsEmptyQueue(LinkQueue *queue)
         {
             if(queue->front == queue->rear)
                 return true;
             else 
                return false;
         }
         
         
         //�����
         void EnQueue(LinkQueue *queue,BTNode*  node)
         {
             // todo:check if the queue is full for sequence list
             LinkQueueNode *p;
             p = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
             p->data = node;
             p->next = NULL;

             queue->rear->next = p;
             queue->rear = p;
         }
         
         
         //������
         BTNode* DeleteQueue(LinkQueue *queue)
         {
             LinkQueueNode *s;
             if ( IsEmptyQueue(queue))
             {
                 exit(0);
                 return nullptr;
             }
             else
             {
                 s = queue->front->next;
                 BTNode* node = s->data;

                 queue->front->next = s->next;
                 if(s->next == NULL)//if there is only one element
                     queue->rear = queue->front;
                 free(s);

                 return node;
             }
        }
         
         
         //ȡ������Ԫ��
         BTNode* GetHead(LinkQueue *queue)
         {
              LinkQueueNode *p;
              BTNode *q;
              if(IsEmptyQueue(queue))
                  return q;
              else 
              {
                  p = queue->front->next;
                  return p->data;
              }
         } 
    }
}