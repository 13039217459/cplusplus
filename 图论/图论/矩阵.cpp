#include<iostream>
#include"数组.cpp"
class juzhen{
public :
	static bool comp(shuzhu s1, shuzhu s2){
		if (s1.x != s2.x || s1.y != s2.y){
			cout << "矩阵无法相加" << endl;
			return false;
		}
		else{
			shuzhu rs(s1.x, s2.y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					if (s1.a[i][j] != s2.a[i][j])return false;
				}
			}	
		}
		return true;
	}
	static shuzhu R(int x){
		shuzhu rs(x, x);
		for (int i = 0; i < x; i++){
			rs.a[i][i] = 1;
		}
		return rs ;
	}
	static shuzhu add(shuzhu s1, shuzhu s2){
		if (s1.x != s2.x || s1.y != s2.y){
			cout << "矩阵无法相加"<<endl;
			return shuzhu(0, 0);
		}
		else{
			shuzhu rs(s1.x, s2.y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					rs.a[i][j] = s1.a[i][j] + s2.a[i][j];
				}
			}
			return rs;
		}
	}
	static shuzhu jian(shuzhu s1, shuzhu s2){
		if (s1.x != s2.x || s1.y != s2.y){
			cout << "矩阵无法相加" << endl;
			return shuzhu(0, 0);
		}
		else{
			shuzhu rs(s1.x, s2.y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s1.y; j++){
					rs.a[i][j] = s1.a[i][j] - s2.a[i][j];
				}
			}
			return rs;
		}
	}
	static shuzhu chen(shuzhu s1, shuzhu s2){
		if (s1.y != s2.x){
			cout << "矩阵无法相乘" << endl;
			return shuzhu(0,0);
		}
		else{
			shuzhu rs(s1.x, s2.y);
			for (int i = 0; i < s1.x; i++){
				for (int j = 0; j < s2.y; j++){
					int q = 0;
					for (int k = 0; k < s1.y; k++){
						q += s1.a[i][j] * s2.a[j][i];
					}
					if (q != 0)q = 1;
					rs.a[i][j] = q;
				}
			}
			return rs;
		}
	}
};