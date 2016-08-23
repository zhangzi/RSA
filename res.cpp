/*
 *  Created on: 2016-8-19
 *  Author:张 紫 琪
 *  经典对称密钥加密RES算法
 */
#include <iostream>
#include <string>
#include "res.h"
using namespace std;

int main() {
	cout << "implementation of RSA algorithm:" << endl;

	int p, q, n, r, e, d;
	cout << "\n enter the value of p: ";
	cin >> p;
	cout << "\n enter the value of q: ";
	cin >> q;

	initialization(p, q, n, r, e, d);

	string s;
	cout << "\n please enter the message need to encrypt:";
	//cin.clear();  // 清除错误标志
	cin.ignore(); //清除缓冲区的当前行
	getline(cin,s);
	cout<<"\n what you enter is:"<<s<<endl;

	cout << "\n ASCII Code of the entered Message:";
	int len = s.length();
	int m[len];
	for (int i = 0; i < len; i++) {
		m[i] = (int) s[i];
		cout << m[i] << " ";
	}

	//Encryption
	cout << "\n Cipher ASCII of the Message:";
	int ciphertext[len];
	for (int i = 0; i < len; i++) {
		ciphertext[i] = mod(m[i], e, n);
		cout << ciphertext[i] << " ";
	}

	//ciphertext:
	cout << "\n ciphertext is: ";
	for (int i = 0; i < len; i++) {
		cout << (char) ciphertext[i];
	}

	//Decryption
	cout << "\n\n Decrypted ASCII of Message:";
	int plaintext[len];
	for (int i = 0; i < len; i++) {
		plaintext[i] = mod(ciphertext[i], d, n);
		cout << plaintext[i] << " ";
	}

	//plaintext:
	cout << "\n plaintext is: ";
	for (int i = 0; i < len; i++) {
		cout << (char) plaintext[i];
	}
	return 0;
}

