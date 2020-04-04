#include "qgforwardlist.h"
#include<iostream>
using namespace  std;
QGForwardList::QGForwardList()//1初始化链表（构造函数与类同名而且没有返回类型，C++中默认返回值是void）
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

QGForwardList:: ~QGForwardList()//2销毁链表x
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


QGForwardList::ElemType&QGForwardList::front()//3返回链表中第一个元素的引用//
{
	if (head->next == nullptr)
		return (head->data);
	else return (head->next)->data;
}

 
	
QGForwardList::ElemType &QGForwardList::back()//4返回链表中最后一个元素的引用(ElemType在头文件中定义)
{
	 struct Node *p=head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	return p->data;
}
 
 bool QGForwardList::push_front(ElemType& e)//5在链表第一个元素前添加元素e
 {

	 struct Node* p = new Node;
	 p->next = head->next;
	 head->next = p;
	 p->data=e;
	 return true;
 }
 
 bool QGForwardList::pop_front()//6删除链表第一个元素
 {
	 struct Node* p = NULL;
	 if (head == nullptr)cout<<"该链表为空表"<<endl;
	 else 
	 {
		 p = head;
		 head = head->next;
		 delete p;
	 }
	 return true;
 }
 
 bool QGForwardList::push_back(ElemType& e)//7在链表最后一个元素后添加元素e
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
 
 bool QGForwardList::pop_back()//8删除链表最后一个元素
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

 bool QGForwardList::insert(unsigned int index, ElemType& e)//9在链表的第index + 1个元素前插入元素e
 {
	 unsigned int i=0;
	 if (head == nullptr)cout << "此链表为空链表";
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
 
 bool QGForwardList::erase(unsigned int index)//10删除任意位置元素
 {
	 unsigned int count = 0;
	 struct Node* p = head;
	 unsigned int i = 0;
	 while (p->next && i < (index - 1))		//找到要删除位置的前驱
	 {
		 p = p->next;
		 i++;
	 }
	 if (!(p->next) || i > index - 1)//防止index=0,p->next!=nullptr
	 {
		 printf("输入错误，删除失败\n");
	 }
	 else
	 {
		 struct Node* q = p->next;
		 p->next = q->next;
		 delete(q);
	 }
	 return true;
 }

   bool QGForwardList:: clear()//11清空链表
 {
	 struct Node* p = head;
	 if (p == nullptr)
	 {
		 cout << "此链表为空表";
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
 
	 bool QGForwardList::contain(ElemType& e) //12查找元素是否存在
 {
	 Node * p = head;
	 if (p == NULL) {                           //当为空表时，报异常
		 cout << "此链表为空链表" << endl;
		 return false ;
	 }
	 else
	 {
		 while (p->next != NULL)               //循环每一个节点
		 {
			 if (p->data == e) {
		 		 return true;                     //返回指针域
			 }
			 p = p->next;
		 }
		 if (p->data == e)//判断最后一个节点
		 {
			 return true;
		 }
		 return false;                           //未查询到结果
	 }
 }
 unsigned int QGForwardList::size()//13返回链表中元素的数量
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
 
 bool QGForwardList::traverse(void (*visit)(ElemType& e))// 14遍历链表, 对每个元素调用visit指向的函数
 {
	 struct Node* p = head;
	 if (head = nullptr) {
		 cout << "此链表为空表";
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
 
 bool QGForwardList::reverse()//15反转链表，1234反转后变成4321
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
 
 bool QGForwardList::isLoop()// 16链表判环
 {
	 struct Node* slowPointer, * fastPointer;
	 slowPointer = fastPointer = head;
	 while (fastPointer != nullptr && fastPointer->next != nullptr) {
		 slowPointer = slowPointer->next;
		 fastPointer = (fastPointer->next)->next;

		 //两指针相遇则有环
		 if (slowPointer == fastPointer) {
			 return true;
		 }
	 }
	 return false;
 }
 
 bool QGForwardList::reverseEven()//17偶节点反转，1234反转后变成2143
 {
	 if (head == nullptr || head->next == nullptr) {
		 cout << "此链表为空表";
		 return false;
	 }
 }

 QGForwardList::ElemType& QGForwardList::middleElem()//18返回中间节点
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
