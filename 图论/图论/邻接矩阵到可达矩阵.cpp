//#include<iostream>
//#include"矩阵.cpp"
//using namespace std;
//
//
////关联矩阵转化为邻接矩阵（有向图）
//
////扫描每一行中  如果为正 取这一列中正数的行数为行数  取那一列中负数的行数为列数  加一
//class Tools{
//public :
//
//	static shuzhu lintoke(shuzhu linjie){
//		int x = linjie.x;
//		shuzhu R = juzhen::R(x);
//		shuzhu A0 = juzhen::add(R, linjie);
//		while (juzhen::comp(juzhen::chen(A0, A0), A0)){
//			A0 = juzhen::chen(A0, A0);
//		}
//		return A0;
//	}
//	static shuzhu guantolin(shuzhu guanlian){
//		int a, b;
//		shuzhu linjie(guanlian.x, guanlian.x);
//		for (int i = 0; i < guanlian.y; i++){
//			for (int j = 0; j < guanlian.x; j++){
//				if (guanlian.a[j][i] == 1){
//					a = j;;
//				}
//				if (guanlian.a[j][i] == -1){
//					b = j;
//				}
//
//			}
//			linjie.a[a][b]++;
//		}
//		return linjie;
//	}
//};
//
//////void main(){
////	
////	int s[]= { -1, 1, 0, 0, 0, 1, -1, 1, 0, 0,0, 0, 0, 1, 1, 0, 0, -1, -1, -1};
////	shuzhu guanlian(4, 5);
////	guanlian.set(s);
////	//shuzhu linjie=Tools::guantolin(guanlian);
////	////linjie.show();
////	//shuzhu keda = Tools::lintoke(linjie);
////	//keda.show();
////	guanlian.show();
////	shuzhu z=juzhen::zhuanzhi(guanlian);
////	z.show();
////
////
////
////}