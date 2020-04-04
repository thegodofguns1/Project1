#include "qgforwardlist.h"
#include<iostream>
using namespace  std;
QGForwardList::QGForwardList()//1��ʼ���������캯������ͬ������û�з������ͣ�C++��Ĭ�Ϸ���ֵ��void��
{
	struct Node  * p, * s;
	int x, cycle = 1;
	head = new Node;
	head->data = 0;
	head->next = NULL;
	p = head;
	while (cycle)
	{
		printf("\nplease input the data:");
		cin >> x;
		if (x != 0)
		{
			s = new Node;
			s->data = x;
			printf("\n%d", s->data);
			p->next = s;
			p = s;
		}
		else
			cycle = 0;
	}
	p->next = NULL;
}

QGForwardList:: ~QGForwardList()//2��������x
{
    struct Node *p1 = head, *p2;
        if (head == nullptr)delete head;
        else
        {
            p2 = p1;
            p1 = p1->next;

            while (p1!= nullptr)
            {
                delete p2;
                p2 = p1;
                p1 = p1->next;
            }
            delete p2;
        }
}


QGForwardList::ElemType&QGForwardList::front()//3���������е�һ��Ԫ�ص�����//
{
	if (head->next == nullptr)
		return (head->data);
	else return (head->next)->data;
}

 
	
QGForwardList::ElemType &QGForwardList::back()//4�������������һ��Ԫ�ص�����(ElemType��ͷ�ļ��ж���)
{
	 struct Node *p=head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	return p->data;
}
 
 bool QGForwardList::push_front(ElemType& e)//5�������һ��Ԫ��ǰ���Ԫ��e
 {

	 struct Node* p = new Node;
	 p->next = head->next;
	 head->next = p;
	 p->data=e;
	 return true;
 }
 
 bool QGForwardList::pop_front()//6ɾ�������һ��Ԫ��
 {
	 struct Node* p = NULL;
	 if (head == nullptr)cout<<"������Ϊ�ձ�"<<endl;
	 else 
	 {
		 p = head;
		 head = head->next;
		 delete p;
	 }
	 return true;
 }
 
 bool QGForwardList::push_back(ElemType& e)//7���������һ��Ԫ�غ����Ԫ��e
 {
	 struct Node* p = NULL;
	 if (head == nullptr)
	 {
		 p = new Node;
		 p->data = e;
		 p->next = NULL;
	 }
	 else
	 {
		 p = head;
		 while (p->next!= nullptr)
		 {
			 p = p->next;
		 }
		 p->next = new Node;
		 p = p->next;
		 p->data = e;
		 p->next = nullptr;
	 }
	 return true;
 }
 
 bool QGForwardList::pop_back()//8ɾ���������һ��Ԫ��
 {
	 struct Node* p = QGForwardList::head;
	 struct Node* p2=nullptr;
	 if (head == nullptr)delete head;
	 while (p->next != nullptr)
	 {
		 p2 = p;
		 p = p->next;
	 }
	 p2->next = nullptr;
	 delete p;
	 return true;
 }

 bool QGForwardList::insert(unsigned int index, ElemType& e)//9������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
 {
	 unsigned int i=0;
	 if (head == nullptr)cout << "������Ϊ������";
	 else
	 {
		 struct Node* p = head;
		 struct Node* q = NULL;
		 if (index == 0)head = new Node;
		 else
		 {
			 while (p->next != nullptr)
			 {
				 if (i == index)
				 {
					 q = p->next;
					 p->next = new Node;
					 (p->next)->next = q;
					 break;
				 }
				 i++;
				 p = p->next;  
			 }
		 }
	 }
	 return true;
 }
 
 bool QGForwardList::erase(unsigned int index)//10ɾ������λ��Ԫ��
 {
	 unsigned int count = 0;
	 struct Node* p = head;
	 unsigned int i = 0;
	 while (p->next && i < (index - 1))		//�ҵ�Ҫɾ��λ�õ�ǰ��
	 {
		 p = p->next;
		 i++;
	 }
	 if (!(p->next) || i > index - 1)//��ֹindex=0,p->next!=nullptr
	 {
		 printf("�������ɾ��ʧ��\n");
	 }
	 else
	 {
		 struct Node* q = p->next;
		 p->next = q->next;
		 delete(q);
	 }
	 return true;
 }

   bool QGForwardList:: clear()//11�������
 {
	 struct Node* p = head;
	 if (p == nullptr)
	 {
		 cout << "������Ϊ�ձ�";
			 return false;
	 }
	 else
	 {
		 p = head->next;
		 while(p != nullptr)
		 {
			head->next = p->next;
			delete p;
			p = head->next;
		 }
		 delete head;
	 }
	 return true;
 }
 
	 bool QGForwardList::contain(ElemType& e) //12����Ԫ���Ƿ����
 {
	 Node * p = head;
	 if (p == NULL) {                           //��Ϊ�ձ�ʱ�����쳣
		 cout << "������Ϊ������" << endl;
		 return false ;
	 }
	 else
	 {
		 while (p->next != NULL)               //ѭ��ÿһ���ڵ�
		 {
			 if (p->data == e) {
		 		 return true;                     //����ָ����
			 }
			 p = p->next;
		 }
		 if (p->data == e)//�ж����һ���ڵ�
		 {
			 return true;
		 }
		 return false;                           //δ��ѯ�����
	 }
 }
 unsigned int QGForwardList::size()//13����������Ԫ�ص�����
 {
	 unsigned int count = 0;
	 struct Node* p = head->next;
	 while (p != nullptr)
	 {
		 count++;
		 p = p->next;
	 }
	 return count;
 }
 
 bool QGForwardList::traverse(void (*visit)(ElemType& e))// 14��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
 {
	 struct Node* p = head;
	 if (head = nullptr) {
		 cout << "������Ϊ�ձ�";
		 return false;
	 }
	 else {
		 
		 while (p->next!=nullptr)
		 {
			 (*visit)(p->data);
			 p = p->next;
		 }
	 }
	 return true;
 }
 
 bool QGForwardList::reverse()//15��ת����1234��ת����4321
 {
	 struct Node* pre = NULL;
	 struct Node* cur = head;
	 struct Node* nxt;
	 while (cur != NULL)
	 {
		 nxt = cur->next;
		 cur->next = pre;
		 pre = cur;
		 cur = nxt;
	 }
	 head =pre;
	 return true;
 }
 
 bool QGForwardList::isLoop()// 16�����л�
 {
	 struct Node* slowPointer, * fastPointer;
	 slowPointer = fastPointer = head;
	 while (fastPointer != nullptr && fastPointer->next != nullptr) {
		 slowPointer = slowPointer->next;
		 fastPointer = (fastPointer->next)->next;

		 //��ָ���������л�
		 if (slowPointer == fastPointer) {
			 return true;
		 }
	 }
	 return false;
 }
 
 bool QGForwardList::reverseEven()//17ż�ڵ㷴ת��1234��ת����2143
 {
	 if (head == nullptr || head->next == nullptr) {
		 cout << "������Ϊ�ձ�";
		 return false;
	 }
 }

 QGForwardList::ElemType& QGForwardList::middleElem()//18�����м�ڵ�
 {
	 if (head == NULL || head->next == NULL)
		 return head->data;
	 struct Node* pslow = head;
	 struct Node* pfast = head;
	 while (1) {
		 pfast = pfast->next;
		 if (pfast == NULL)
			 break;
		 pslow = pslow->next;
		 pfast = pfast->next;
		 if (pfast == NULL)
			 break;
	 }
	 return pslow->data;
 }
