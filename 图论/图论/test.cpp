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
			cout << "线性表创建成功" << endl;
		}
		else{
			cout << "创建失败" << endl;
		}
	}
	Status add(){
		Elemtype v;
		cout << "输入要添加元素" << endl;
		cin >> v;
		*(p + length) = v;
		length++;
		if ((max - length)<10){
			max += ADDMAX;
			p = (Elemtype *)realloc(p, sizeof(Elemtype)*max);
			if (p != NULL)
			{
				cout << "增加成功" << endl;
				return Ok;
			}
			else{
				return Error;
			}
		}
		cout << "增加成功" << endl;
		return Ok;
	}
	Status insert(int key, Elemtype v)
	{
		if (key>length || key<0)
		{
			cout << "数组越界" << endl;
			return Overflow;
		}
		else
		{
			for (int i = length; i>key; i--)
			{
				*(p + i) = *(p + i - 1);
			}
			*(p + key) = v;
			cout << "插入成功" << endl;
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
			cout << "数组越界" << endl;
			return Overflow;
		}
		else
		{
			cout << "查询成功" << endl;
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
		cout << "删除成功" << endl;
		return Ok;
	}

	Status change(int key, Elemtype v){
		if (key>length || key<0)
		{
			return Overflow;
		}
		*(p + key) = v;
		cout << "修改成功" << endl;
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