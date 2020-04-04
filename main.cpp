#include<iostream>
#include"qgforwardlist.h"
using namespace std;
int main() 
{
		int i;
		QGForwardList list;
		cout << "1.初始化单链表(默认构造)" << endl << "2.删除单链表" << endl << "3.返回链表中第一个元素的引用" << endl << "4.4返回链表中最后一个元素的引用" << endl;
		cout << "5.在链表第一个元素前添加元素e" << endl << "6.删除链表第一个元素" << endl << "7在链表最后一个元素后添加元素e" << endl << "8删除链表最后一个元素" << endl;
		cout << "9在链表的第index + 1个元素前插入元素e" << endl << "10删除任意位置元素" << endl << "11清空链表" << endl << "12查找元素是否存在" << endl;
		cout << "13返回链表中元素的数量" << endl << "14遍历链表, 对每个元素调用visit指向的函数" << endl << "15反转链表" << endl << "16链表判环" << endl << "17偶节点反转" << endl << "18返回中间节点" << endl;
		do
		{
			cout << "请输入要执行的操作: ";
			cin >> i;
			switch (i)
			{
			case 1:
				break;
			case 2:
				list.~QGForwardList();

				break;
			case 3:
				cout << list.front()<< endl;
				break;
			case 4:
				cout << list.back() << endl;
				break;
			case 5:
				QGForwardList::ElemType data1;
				cout << "Please input data:" << endl;
				cin >> data1;
				list.push_front(data1);
				break;
			case 6:
				; list.pop_front();
				break;
			case 7:
				QGForwardList::ElemType data2;
				cout << "Please input the data:" << endl;
				cin >> data2;
				list.push_back(data2);
				break;
			case 8:
				list.pop_back();
				break;
			case 9:
				unsigned int i;
				QGForwardList::ElemType data3;
				cout << "Please input the index:"<<endl;
				cin >> i;
				cout << "Please input the data:" << endl;
				cin >> data3;
				list.insert(i,data3);
				break;
			case 10:
				unsigned int position;
				cout << "Please input the position:";
				cin >> position;
				list.erase(position);
				break;
			case 11:
				list.clear();
				break;
			case 12:
				QGForwardList::ElemType data4;
				cout << "Please input the data which you want to seek:";
				cin >> data4;
				list.contain(data4);
				break;
			case 13:
				cout << list.size() << endl;
				break;
			case 14:
				list.traverse(NULL);
				break;
			case 15:
				if (list.reverse());
				else cout << "操作失败" << endl; 
				break;
			case 16:
				if (list.isLoop())cout << "成环"<<endl;
				else cout << "不成环"<<endl;
				break;
			case 17:
				list.reverseEven();
				break;
			case 18:
				cout << "list.middleElem()" << endl;
				break;
			default:
				break;
			}
		} while (i != 0);
		return 0;
	
}