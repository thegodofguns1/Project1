#include<iostream>
#include"qgforwardlist.h"
using namespace std;
int main() 
{
		int i;
		QGForwardList list;
		cout << "1.��ʼ��������(Ĭ�Ϲ���)" << endl << "2.ɾ��������" << endl << "3.���������е�һ��Ԫ�ص�����" << endl << "4.4�������������һ��Ԫ�ص�����" << endl;
		cout << "5.�������һ��Ԫ��ǰ���Ԫ��e" << endl << "6.ɾ�������һ��Ԫ��" << endl << "7���������һ��Ԫ�غ����Ԫ��e" << endl << "8ɾ���������һ��Ԫ��" << endl;
		cout << "9������ĵ�index + 1��Ԫ��ǰ����Ԫ��e" << endl << "10ɾ������λ��Ԫ��" << endl << "11�������" << endl << "12����Ԫ���Ƿ����" << endl;
		cout << "13����������Ԫ�ص�����" << endl << "14��������, ��ÿ��Ԫ�ص���visitָ��ĺ���" << endl << "15��ת����" << endl << "16�����л�" << endl << "17ż�ڵ㷴ת" << endl << "18�����м�ڵ�" << endl;
		do
		{
			cout << "������Ҫִ�еĲ���: ";
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
				else cout << "����ʧ��" << endl; 
				break;
			case 16:
				if (list.isLoop())cout << "�ɻ�"<<endl;
				else cout << "���ɻ�"<<endl;
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