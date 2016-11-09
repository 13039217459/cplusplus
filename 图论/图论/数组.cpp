//#include<iostream>
//using namespace std;
//
//#ifndef SHUZHU_CPP
//#define SHUZHU_CPP
//
//class shuzhu{
//public:
//	int     **a;
//	int     x, y;
//	shuzhu(int x1,int y1){
//		x = x1;
//		y = y1;
//		a = (int **)malloc(sizeof(int *)*x);
//
//		for (int i = 0; i < x; i++)
//		{
//			*(a + i) = (int  *)malloc(sizeof(int)*y);
//		}
//		for (int i = 0; i < x; i++)
//		{
//			for (int j = 0; j < y; j++){
//				a[i][j] = 0;
//			}
//
//		}
//	}
//	template<int Fuck>
//	int  set(int (&p)[Fuck]){                                    //想要获取传进来的数组的长度只有这种方法
//																//当这个数组名作为参数传递给print这个函数的时候，函数中得到的是一个int的指针。
//																//而数组名其实是一个常量指针。sizeof对待这两者是不一样的。
//		int len = sizeof(p) / sizeof(p[0]);
//		/*cout << "sizeof(p):" << sizeof(p) << endl;
//		cout << "sizeof(p[0])" << sizeof(p[0]) << endl;
//		cout << "  len2："<<len << endl;*/
//		int ii = 0;
//		if (len%x == 0){
//			for (int i = 0; i < len / x; i++){
//				for (int j = 0; j < y; j++){
//					a[i][j] = p[i*y + j];
//					ii++;
//					if (ii == len ){
//						return 0;
//					}
//				}
//				//cout << "执行了shang" << endl;
//			}
//		}
//		else{
//			for (int i = 0; i < (len / x)+1; i++){
//				for (int j = 0; j < y; j++){
//					a[i][j] = p[i*y + j];
//					ii++;
//					if (ii == len ){
//						return 0;
//					}
//				}
//				//cout << "执行了xia" << endl;
//			}
//		}
//		return 0;
//	}
//	void show(){
//		for (int i = 0; i < x; i++){
//			for (int j = 0; j < y; j++){
//				cout << a[i][j] << "\t";
//			}
//			cout << endl;
//		}
//	}
//};
//
//
//
////void main()
////{
////	int rs = 7 / 4;
////	//cout << rs;
////	int x, y;
////	cin >> x >> y;
////	shuzhu s(x,y);
////	
////	
////
////	int p[] = {1,2,3,4,5,6,7,8};
////	int len = sizeof(p) / sizeof(p[0]);
////	//cout << "  len1：" << len << endl;
////	s.set(p);
////	s.show();
////	
////}
//
//
//#endif