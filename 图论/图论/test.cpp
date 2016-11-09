#include<iostream>
#define Elemtype int
using namespace std;
#define MAX 1000
#define ADDMAX 100


#define True  1
#define False 0
#define Ok    1
#define Error 0
#define Infeasible -1
#define Overflow   -2
typedef int Status;
class Arraylist
{
public:
	int max;
	int length;
	int *p;
	Arraylist(){
		length = 0;
		max = MAX;
		p = (Elemtype *)malloc(sizeof(Elemtype)*max);
		if (p != NULL)
		{
			cout << "���Ա����ɹ�" << endl;
		}
		else{
			cout << "����ʧ��" << endl;
		}
	}
	Status add(){
		Elemtype v;
		cout << "����Ҫ���Ԫ��" << endl;
		cin >> v;
		*(p + length) = v;
		length++;
		if ((max - length)<10){
			max += ADDMAX;
			p = (Elemtype *)realloc(p, sizeof(Elemtype)*max);
			if (p != NULL)
			{
				cout << "���ӳɹ�" << endl;
				return Ok;
			}
			else{
				return Error;
			}
		}
		cout << "���ӳɹ�" << endl;
		return Ok;
	}
	Status insert(int key, Elemtype v)
	{
		if (key>length || key<0)
		{
			cout << "����Խ��" << endl;
			return Overflow;
		}
		else
		{
			for (int i = length; i>key; i--)
			{
				*(p + i) = *(p + i - 1);
			}
			*(p + key) = v;
			cout << "����ɹ�" << endl;
			length++;
			return Ok;
		}
	}
	Status show()
	{
		for (int i = 0; i<length; i++)
		{
			cout << *(p + i) << endl;
		}
		return Ok;
	}
	Elemtype select(int key)
	{
		if (key>length || key<0)
		{
			cout << "����Խ��" << endl;
			return Overflow;
		}
		else
		{
			cout << "��ѯ�ɹ�" << endl;
			return *(p + key);

		}

	}
	Status deletee(int key){
		if (key>length || key<0)
		{
			return Overflow;
		}
		for (int i = key; i<length; i++)
		{
			*(p + i - 1) = *(p + i);
		}
		*(p + length - 1) = NULL;
		length--;
		cout << "ɾ���ɹ�" << endl;
		return Ok;
	}

	Status change(int key, Elemtype v){
		if (key>length || key<0)
		{
			return Overflow;
		}
		*(p + key) = v;
		cout << "�޸ĳɹ�" << endl;
		return Ok;
	}

};
void main()
{
	Arraylist list;
	list.add();
	list.add();
	list.add();
	list.add();
	list.add();
	list.show();
	list.deletee(0);
	list.show();
	list.change(0, 1231245);
	list.show();
	cout << list.select(0) << endl;
	list.insert(-1, 66666);
	list.show();

}