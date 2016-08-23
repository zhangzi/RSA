/*
 *  Created on: 2016-8-19
 *  Author:张 紫 琪
 */
#include <iostream>
using namespace std;

#ifndef RES_H_
#define RES_H_

//欧几里德算法又称辗转相除法，用于计算两个整数a,b的最大公约数。其计算原理依赖于下面的定理： 定理：gcd(a,b) = gcd(b,a mod b)
int gcd(int m, int n) {
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	if (m < n) {
		int tmp = m;
		m = n;
		n = tmp;
	}
	while (n != 0) {
		int tmp = m % n;
		m = n;
		n = tmp;
	}
	return m;
}

void initialization(int& p, int& q, int& n, int& r, int& e, int& d) {
	n = p * q;
	r = (p-1)*(q-1);

	//Calculate the value of e
	int x = 2;
	e = 1;
	while (x > 1) {
		e = e + 1;
		x = gcd(r, e);
	}

	//Calculate the value of d
	d = 1;
	while ((e * d) % r != 1) {
		d++;
	}

	cout << "================\n result: \n";
	cout << "p=" << p << endl;
	cout << "q=" << q << endl;
	cout << "the value of n=" << n << endl;
	cout << "the value of r=" << r << endl;
	cout << "the public key e=" << e << endl;
	cout << "the private key d=" << d << endl;
	cout << "==============\n";
}

//(a^b) % m
int mod(int a,int b,int m){
    int result = 1;
    for(int i=0;i<b;i++) {
        result = (result*a) %m;
    }
    return result;
}

#endif /* RES_H_ */
