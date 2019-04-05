#include"Tree.h"
namespace Tree
{
    namespace BinarySearchTree
    {
        /*
        ��ָ��pTree��ָ�Ķ����������еݹ���ҹؼ���Ϊkey��Ԫ�أ�
        �����ҳɹ����򷵻�ָ���Ԫ�ؽڵ��ָ�룬���򷵻�NULL
        */
        BSTree search(BSTree pTree,int key)
        {
            //���ҵ�ʱ���ص�pTreeΪ��Ԫ�ؽڵ㣬û���ҵ�ʱΪNULL
            if(!pTree || pTree->data == key)
            	return pTree;
            else if(key < pTree->data)//���keyС�ڵ�ǰ�ڵ��ֵ���������������еݹ����
            	return search(pTree->lchild,key);
            else                               //���key���ڵ�ǰ�ڵ��ֵ���������������еݹ����
            	return search(pTree->rchild,key);
        }
        
        
        /*
        ��ָ��pTree��ָ�Ķ����������еݹ���ҹؼ���Ϊkey��Ԫ�أ�
        �����ҳɹ����򷵻�ture�������ҵ������ݶ�Ӧ�Ľڵ�ָ�뱣����p�У�
        ���򷵻�false����������·���Ϸ��ʵ����һ���ڵ�ָ�뱣����p�С�
        ����Ĳ���parentָ��ÿ�εݹ�����������ĸ��ڵ�ĸ��ڵ㣬��ʼ���ǲ���pTree�ĸ���       �� ��
        ���ĳ�ʼֵΪNULL����Ŀ���Ǹ��ٲ���·���Ϸ��ʵĵ�ǰ�ڵ�ĸ��ڵ㣨����һ�����ʽ�      ��  ��
        �ú�������������Ĳ��뺯�����á�
        */
        bool search_BSTree(BSTree pTree,int key,BSTree parent,BSTree &p)
        {
            if(!pTree)         //���pTreeΪNULL������Ҳ��ɹ�					
            {	//������������գ���pTreeΪNULL�����
            	p = parent;
            	return false;
            }
            else             //���򣬼�������
            {	
            	if(key == pTree->data)//�����ȣ�����ҳɹ�			             	
                {
            		p = pTree;
            		return true;
            	}
            	else if(key < pTree->data)		//���������еݹ����
            		return search_BSTree(pTree->lchild,key,pTree,p);    
            	else							//���������еݹ����
            		return search_BSTree(pTree->rchild,key,pTree,p);
            }
        }
        
        /*
        ����pTree��ָ��Ķ����������в��Ҳ����ؼ���Ϊkey������Ԫ��ʱ��
        �������ö�����������������ture�����򷵻�false��
        ����ʱ�����ı���ڵ��ֵ�����Ҫ�������á�
        */
        bool insert(BSTree &pTree,int key)
        {
        	BSTree p;
        	if(!search_BSTree(pTree,key,NULL,p))		//�������ʧ�ܣ���ִ�в������      
        	{
        		//Ϊ�½ڵ����ռ䣬���Ը���ֵ
        		BSTree pNew = (BSTree)malloc(sizeof(BSTNode));
        		pNew->data = key;
        		pNew->lchild = pNew->rchild = NULL;
        
        		if(!p)						    //������գ���ֱ����pNewΪ���ڵ�
        			pTree = pNew;
        		else if(key < p->data)			//��Ϊ���Ӳ���p�����
        			p->lchild = pNew;	        //��Ϊ�Һ��Ӳ���p���ұ�	
        		else
        			p->rchild = pNew;
        	}
        	else
        		return false;
        }

        BSTree InsertWithRecursion(BSTree &pTree,int key)
        {
            if(pTree== nullptr)
            {
                // if pTree is null
                pTree = (BSTree)malloc(sizeof( struct BSTNode));
                pTree->data = key;
                pTree->lchild = pTree->rchild = nullptr;
            }
            else
            {
                if(key<pTree->data)
                    pTree->lchild = InsertWithRecursion(pTree->lchild ,key);
                else if(key>pTree->data)
                    pTree->rchild =InsertWithRecursion(pTree->rchild ,key);
                //else;key exists in the tree,so nothing is done.
            }

            return pTree;
        }
        
        /*
        ���õ�һ���㷨�Ӷ�����������ɾ��ָ��p��ָ��Ľڵ�,
        ���ڱ��ֶ������������������£��������������ؽӵ��ö�����������.
        �ú�����Ҫ�����������ɾ����������
        */
        void delete_Node1(BSTree &p)
        { 
        	BSTree q,s;
        	if(!p->lchild)	
        	{	//���������Ϊ�գ���ֻ���ؽ���������
        		//�������������������Ϊ�յ����
        		q = p;
        		p = p->rchild ;
        		free(q);
        	}
        	else if(!p->rchild)
        	{	//���������Ϊ�գ���ֻ���ؽ���������
        		q = p;
        		p = p->lchild;
        		free(q);
        	}
        	else
        	{	//���������������Ϊ�գ����ǲ�ȡ��һ�ַ������ؽ�����������
        		//���������ȡ�޸��������ķ�����Ҳ�����޸�����������������
        		s = p->lchild;		//ȡ��ɾ�ڵ����ڵ�
        
        		//һֱ���ң�����sΪ��ɾ�ڵ��ǰ���ڵ�
        		//��������ڵ�Ԫ�ذ���С����˳�����г�һ�����У�
        		//��ĳ�ڵ��ǰ���ڵ㼴Ϊ�����иýڵ��ǰ��һ���ڵ�
        		while(s->rchild)
        			s = s->rchild;
        		s->rchild = p->rchild;	//��p����������Ϊs��������
        		q = p;
        		p = p->lchild;		//��p��������ֱ�ӽӵ��丸�ڵ����������
        		free(q);
        	}
        }
        
        /*
        ���õڶ����㷨�Ӷ�����������ɾ��ָ��p��ָ��Ľڵ�,
        ���ڱ��ֶ������������������£��������������ؽӵ��ö�����������.
        �ú�����Ҫ�����������ɾ����������
        */
        void delete_Node2(BSTree &p)
        {
        	BSTree q,s;		
        	if(!p->lchild)	
        	{	//���������Ϊ�գ���ֻ���ؽ���������
        		//�������������������Ϊ�յ����
        		q = p;
        		p = p->rchild ;
        		free(q);
        	}
        	else if(!p->rchild)
        	{	//���������Ϊ�գ���ֻ���ؽ���������
        		q = p;
        		p = p->lchild;
        		free(q);
        	}
        	else
        	{	//���������������Ϊ�գ����ǲ�ȡ�ڶ��ַ������ؽ�����������
        		//���������ȡ�޸��������ķ�����Ҳ�����޸�����������������
        		q = p;
        		s = p->lchild;		//ȡ��ɾ�ڵ����ڵ�
        		while(s->rchild)		
        		{	//һֱ���ң�����sΪ��ɾ�ڵ��ǰ���ڵ㡣
        			//��������ڵ�Ԫ�ذ���С����˳�����г�һ�����У�
        			//��ĳ�ڵ��ǰ���ڵ㼴Ϊ�����иýڵ��ǰ��һ���ڵ�
        			q = s;
        			s = s->rchild;
        		}
        		//��s���滻��ɾ�ڵ�p
        		p->data = s->data;  
        		//�����������s���������ؽӵ�q��
        		if(p != q)
        			q->rchild = s->lchild;
        		else
        			q->lchild =s->lchild;
        		free(s);
        	}
        }
        
        /*
        ��pTree��ָ��Ķ����������в��ҵ��ؼ���Ϊkey������Ԫ�أ�
        ��ɾ����Ԫ�ض�Ӧ�Ľڵ㣬������true�����򷵻�false
        ���Ҫɾ����ǡ���Ǹ��ڵ㣬���ı���ڵ��ֵ�����Ҫ��������
        */
        bool delete_BSTree(BSTree &pTree,int key)
        {
        	//�����ڹؼ���Ϊkey�Ľڵ�
        	if(!pTree)
        		return false;
        	else
        	{	
        		if(key == pTree->data)       //���ҵ��ؼ���Ϊkey�Ľڵ�
        		{
        			delete_Node1(pTree);
        //			delete_Node2(pTree);
        			return true;			
        		}
        		else if(key < pTree->data)  //��������������
        			return delete_BSTree(pTree->lchild,key);
        		else                        //��������������
        			return delete_BSTree(pTree->rchild,key);
        	}
        }
        
        /*
        ���������ĳ�Ϊlen��arr���飬��������Ԫ�ص�˳�򹹽�һ�ö���������
        */
        BSTree create_BSTree(int *arr,int len)
        {
        	BSTree pTree = NULL;
        	int i;
        	//��˳������ڵ���뵽������������
        	for(i=0;i<len;i++)
        		insert(pTree,arr[i]);
        	return pTree;	
        }
        
        /*
        �ݹ���������������������õ�Ԫ�ش�С�����������е�����
        */
        void in_traverse(BSTree pTree)
        {
        	if(pTree)
        	{
        		if(pTree->lchild)
        			in_traverse(pTree->lchild);
        		printf("%d ",pTree->data);
        		if(pTree->rchild)
        			in_traverse(pTree->rchild);	
        	}
        }
        
        
        void Test()
        {
        	int i;
        	int num;
        	printf("������ڵ������");
        	scanf("%d",&num);
        
        	//����num������
        	int *arr = (int *)malloc(num*sizeof(int));
        	printf("������������%d�����������뻥����ȣ���",num);
        	for(i=0;i<num;i++)
        		scanf("%d",arr+i);
        
        	//��������ö�����������ʹ���ݰ��մ�С�����˳�����
        	BSTree pTree = create_BSTree(arr,num);
        	printf("��������ö����������Ľ����");
        	in_traverse(pTree);
        	printf("\n");
        
        	//���Ҹ���������
        	int key;
        	printf("������Ҫ���ҵ�������");
        	scanf("%d",&key);
        	if(search(pTree,key))
        		printf("���ҳɹ�\n");
        	else 
        		printf("���Ҳ���������\n");
        
        	//�������������
        	printf("������Ҫ�����������");
        	scanf("%d",&key);
        	if(insert(pTree,key))
        	{
        		printf("����ɹ���������������������");
        		in_traverse(pTree);
        		printf("\n");
        	}
        	else
        		printf("����ʧ�ܣ��ö������������Ѿ���������%d\n",key);
        
        	//ɾ������������
        	printf("������Ҫɾ����������");
        	scanf("%d",&key);
        	if(delete_BSTree(pTree,key))
        	{
        		printf("ɾ���ɹ���������������������");
        		in_traverse(pTree);
        		printf("\n");
        	}
        	else
        		printf("ɾ��ʧ�ܣ��ö����������в���������%d\n",key);
        }
    }
}