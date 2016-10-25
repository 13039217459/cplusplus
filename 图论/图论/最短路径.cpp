#include<vector>
#include<iostream>
#include<string>
using namespace std;
enum  stuats{normal,one};

class D
{
public:
	string name;
	stuats s;
	D()
	{
	}
	D(string name1,stuats s1){
		name = name1;
		s = s1;
	}
};
vector<D> dvec;



class weight{
public:
	D d1;
	D d2;
	int w;
	weight()
	{}
	weight(D d11,D d22,int w1){
		d1 = d11;
		d2 = d22;
		w = w1;

	}
};
vector<weight> wvec;



class path{
public:
	string name1;
	string name2;
	int weight;
	stuats s;
	path(string name11, string name22, int weight1){
		name1 = name11;
		name2 = name22;
		weight = weight1;
		s = normal;
	}
	path(){}
};
vector<path> pvec;



class Tools{
public:
	void static setD(string name){
		
		for (unsigned int i = 0; i < dvec.size(); i++){
			if (dvec.at(i).name == name)
			{
				cout << "�����ظ�" << endl;
				return;
			}
		}
		D d(name,normal);
		dvec.push_back(d);
		dvec.at(0).s = one;

	}
	static void setW(string name1, string name2, int w1){
		int i1;
		int i2;
		for (unsigned int i = 0; i < dvec.size(); i++){
			if (dvec.at(i).name == name1)i1 = i;
			if (dvec.at(i).name == name2)i2 = i;
		}
		
		D shangyige = dvec.at(i1);
		D cur = dvec.at(i2);
		weight w(shangyige, cur, w1);
		wvec.push_back(w);
	}
	static void setP()
	{
		for (unsigned int i = 0; i < dvec.size(); i++){
			if (i == 0){
				path p(dvec.at(0).name, dvec.at(0).name, 0);
				p.s = one;
				pvec.push_back(p);
			}
			else{
				path p(dvec.at(0).name, dvec.at(i).name, 100000);
				pvec.push_back(p);
			}
		}
	}
	static int  begintocur(string cur){
		int btc;
		for (unsigned int i = 0; i < wvec.size(); i++){
			if (pvec.at(i).name2 == cur){
				btc = pvec.at(i).weight;
			}
		}
		return btc;
	}
	static int dnumber(D d){
		for (unsigned int i = 0; i < dvec.size(); i++){
			if (d.name == dvec.at(i).name){
				return i;
			}
		}
	}

	static void get(string name1){

		
		int i1;
		for (unsigned int i = 0; i < dvec.size(); i++){
			if (dvec.at(i).name == name1)i1 = i;
		}
		D d11 = dvec.at(i1);
		
		for (unsigned int i = 0; i < wvec.size(); i++){//ѭ��Ȩ�ر�  ����������Ϊname1�����ĵ�

			/*cout << endl << endl;
			cout << "---------------------------" << endl;
			cout <<"Ȩ��1��"+ wvec.at(i).d1.name << endl;
			cout << "Ȩ��2��" + wvec.at(i).d2.name << endl;
			string zhuantai1; string zhuantai2;
			if (wvec.at(i).d1.s == normal)zhuantai1 = "normal"; else zhuantai1 = "one";
			if (wvec.at(i).d2.s == normal)zhuantai2 = "normal"; else zhuantai2 = "one";

			cout << "Ȩ��1״̬" + zhuantai1 << endl;
			cout << "Ȩ��2״̬" + zhuantai2 << endl;
			cout << "---------------------------" << endl;*/

			cout << endl << endl;
			if (wvec.at(i).d1.name == name1&&wvec.at(i).d2.s!=one){//����㻹�����Ǵ��ǵ�
				int btc = begintocur(wvec.at(i).d1.name);//�㵽ԭ��ľ���
				cout << "�㵽ԭ����룺" << btc << "�㵽���������" << wvec.at(i).w << "�����㵽ԭ�����" << pvec.at(i).weight << endl;
				int index = dnumber(wvec.at(i).d2);
				if (btc + wvec.at(i).w < pvec.at(index).weight)//�㵽ԭ��ľ���ӵ㵽����������������ȹ����㵽ԭ�����С ���滻
				{
					pvec.at(index).name1 = wvec.at(i).d1.name;
					pvec.at(index).name2 = wvec.at(i).d2.name;
					pvec.at(index).weight = btc + wvec.at(i).w;
				}
			}
			if (wvec.at(i).d2.name == name1&&wvec.at(i).d1.s != one)
			{//ֻ�������Ǹ�if����������
				int index = dnumber(wvec.at(i).d1);
				int btc = begintocur(wvec.at(i).d2.name);
				if (btc + wvec.at(i).w < pvec.at(index).weight)
				{
					pvec.at(index).name1 = wvec.at(i).d2.name;
					pvec.at(index).name2 = wvec.at(i).d1.name;
					pvec.at(index).weight = btc + wvec.at(i).w;
				}
			}
			
		}
		int k = 0;
		int ww =100000;
		for (unsigned int i = 0; i < pvec.size(); i++){//����·������������С��·
			string zhuantai;
			if (pvec.at(i).s != one) zhuantai = "normal"; else zhuantai = "one";
			cout << pvec.at(i).weight << " " << zhuantai << endl;
			if (pvec.at(i).s != one){
				if (ww>pvec.at(i).weight)
				{
					ww = pvec.at(i).weight;
					k = i;
					
				}
			}
			
			
		}
		cout <<"k��ֵ"<< k << endl;
		for (unsigned int i = 0; i < dvec.size(); i++){
			if (dvec.at(i).name == pvec.at(k).name2){//�������С��·������
				dvec.at(i).s = one;
				pvec.at(k).s = one;
			}
		}
		
		int one1 = 0;//��һ���ж�����
		for (unsigned int i = 0; i < dvec.size(); i++){
			if (pvec.at(i).s == one){
				one1++;
			}
		}
		cout << "�����У�" << one1 << endl;
		for (int i = 0; i < 500000000; i++);
		if (one1 == dvec.size()){//����Ǻ͵�����ͬ �˳�
			cout << "���" << endl;
		}
		else{
			get(pvec.at(k).name2);
		}
		
	}

	static void show()
	{
		for (unsigned int i = 0; i < pvec.size(); i++){
			cout << dvec.at(0).name + "��" + pvec.at(i).name2 + "�ľ���Ϊ��" << pvec.at(i).weight << endl;
		}
	}

};
void main(){
	
	Tools::setD("A");
	Tools::setD("B");
	Tools::setD("C");
	Tools::setD("D");
	Tools::setD("E");
	Tools::setW("A", "B", 5);
	Tools::setW("A", "E", 1);
	Tools::setW("B","C",5);
	Tools::setW("C","D", 5);
	Tools::setW("D", "E", 5);
	Tools::setP();
	
	Tools::get(dvec.at(0).name);
	Tools::show();
}