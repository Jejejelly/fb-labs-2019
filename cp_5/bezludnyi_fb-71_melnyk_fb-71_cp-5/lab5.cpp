#include <NTL/ZZ.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
NTL_CLIENT

using namespace std;


ZZ e = pow(2, 16) + (ZZ)1;
long o = 0;

ZZ pow(int a, int b) {
	ZZ temp;
	temp = a;
	for (int i = 1; i < b; i++)
		temp = temp * a;
	return temp;
}

ZZ pow(ZZ a, ZZ b) {
	ZZ temp;
	temp = a;
	for (ZZ i = (ZZ)1; i < b; i++)
		temp = temp * a;
	return temp;
}


ZZ rando(ZZ min) {
	return RandomBnd(min) + min;

}

ZZ mod(ZZ k, ZZ m) 
{
	if (k < m)
	{
		if (k < 0) { for (;;) { k += m; if (k > 0) return k; } }
		return k;
	}
	else {
		for (;;)
		{
			k = k - m;
			if (k < m)return k;
		}
		return k;
	}
}


ZZ gcdExtended(ZZ a, ZZ b, ZZ* x, ZZ* y)
{

	if (a == 0)
	{
		*x = 0, * y = 1;
		return b;
	}
	/*Change all data types*/
	ZZ x1, y1;//
	ZZ gcd = gcdExtended(b % a, a, &x1, &y1);//


	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}
ZZ modInverse(ZZ a, ZZ m)
{
	ZZ x, y;
	ZZ g = gcdExtended(a, m, &x, &y);
	if (g != 1)
	{

		return (ZZ)0;
	}
	else
	{

		ZZ res = (x % m + m) % m;
		return res;
	}
}


bool test(/*Change data type*/ZZ p)
{
	
	int count = 0;
	/*Change data type*/ZZ temp = p - 1, x , x1, x2, x0;
	x = 2;
	
	
	while (1)
	{
		if (temp % 2 == 0) { temp = temp / 2; count++; }
		else break;
	}
	


	x = RandomBnd(p);

	
	if (gcdExtended(x, p, &x1, &x2) != 1)return 0;
	ZZ power;
	
	x0 = PowerMod(x, temp,p);
	

	if (x0 == 1 || x0 == -1)return 1;
	for (int i = 1; i < count; i++)
	{
	

		x0 = PowerMod(x0 , (ZZ)2 , p) ;
		if (x0 == -1) return 1;
		if (x0 == 1) return 0;
	}
	return 0;

}


bool find(ZZ &p) {
	ZZ min;
	bool chk = 0;

	min = pow(2, 256);
	p = rando(min);
	

	
	
	//cout << p << "\n";

	int i = 0, k = 4;//your value
	
	ZZ arr[5] = { (ZZ) 2,(ZZ)3, (ZZ)5 , (ZZ)7 , (ZZ)11 };
	for (int i = 0; i < 5; i++)
		if (p % arr[i] == 0) {  return 0; }



	while (i < k) {
		if (test(p) == 1)i++;
		else break;
		
	}
	if (i >= k)chk = 1;
	
	
	if(chk)return 1;
	else  return 0;

}

ZZ GenerateKeyPair(ZZ p, ZZ q, ZZ &n) {
	ZZ d, e;

	n = p * q;
	e = pow(2, 16) + 1;
	d = modInverse(e, (p - 1) * (q - 1));
	return d;
}


ZZ Encrypt(ZZ e, ZZ n, ZZ M)
{
	ZZ C = PowerMod(M, e, n);
	return C;
}

ZZ Decrypt(ZZ C, ZZ d, ZZ n)
{
	ZZ M = PowerMod(C, d, n);
	return M;
}

ZZ Sign(ZZ M, ZZ d, ZZ n)
{
	ZZ S = PowerMod(M, d, n);
	return S;
}
ZZ Verify(ZZ S, ZZ e, ZZ n)
{
	ZZ M;
	M = PowerMod(S, e, n);
	return M;
}


void Send(ZZ &S,ZZ &S1, ZZ &k1,ZZ k,ZZ d, ZZ n, ZZ n1, ZZ e1)
{
	S = PowerMod(k, d, n);
	S1 = PowerMod(S, e1, n1);
	k1 = PowerMod(k, e1, n1);
	cout << "S:" << S << endl;
	cout << "S1:" << S1 << endl;
	cout << "k1:" << k1 << endl;
}

void Recieve(ZZ &S, ZZ &S1,ZZ k1,ZZ d1, ZZ n1 ,ZZ k, ZZ e, ZZ n)
{
	S = PowerMod(S1, d1, n1);
	k = PowerMod(k1, d1, n1);
	if(k == PowerMod(S , e, n))cout<<"\nOk";
	else cout<< "\nNot ok";
	cout << "\nk:: "<<k<<endl;
}


int main()
{
	
	ZZ p, q,p1, q1, e1 ,e2, n1 ,n2, d1, d2, C1 , M1, C2, M2, k1, S1, k ,S;
	while (1) {
		if (find(p)) {
			cout << endl << p << "\nPRIME(p)!!"; break;
		}
	}
	while (1) {
		if (find(q)) {
			cout << endl << q << "\nPRIME!!(q)"; break;
		}
	}
	while (1) {
		if (find(p1)) {
			cout << endl << p1 << "\nPRIME!!(p1)"; break;
		}
	}
	while (1) {
		if (find(q1)) {
			cout <<endl<< q1 << "\nPRIME!!(q1)\n"; break;
		}
	}
	e1 = ::e;
	e2 = ::e;

	d1 = GenerateKeyPair(p, q, n1);
	d2 = GenerateKeyPair(p1, q1, n2);
	
	cout << "\nn1:: " << n1;
	cout << "\nn2:: " << n2;
	cout << "\ne1:: " << e1;
	cout << "\ne2:: " << e2;
	cout << "\nd1:: " << d1;
	cout << "\nd2:: " << d2;

	M1 = (ZZ)RandomBnd(n2 - 1);
	C1 = Encrypt(e2, n2, M1);
	M2 = (ZZ)RandomBnd(n1 - 1);
	C2 = Encrypt(e1, n1, M2);


	//User2
	cout << "\nM1: " << M1 << endl;
	cout << "C1 deciphered: " << Decrypt(C1, d2, n2);

	//User1
	cout << "\nM2: " << M2 << endl;
	cout << "C2 deciphered: " << Decrypt(C2, d1, n1);

//-----------------------------

	while (n2 > n1)
	{
		
		while (1) {
			if (find(p)) {
				cout << endl << p << "\nPRIME(p)!!"; break;
			}
		}
		while (1) {
			if (find(q)) {
				cout << endl << q << "\nPRIME!!(q)"; break;
			}
		}
		while (1) {
			if (find(p1)) {
				cout << endl << p1 << "\nPRIME!!(p1)"; break;
			}
		}
		while (1) {
			if (find(q1)) {
				cout << endl << q1 << "\nPRIME!!(q1)\n"; break;
			}
		}
		d1 = GenerateKeyPair(p, q, n1);
		d2 = GenerateKeyPair(p1, q1, n2);
	}
	cout << "------------------------" << endl;
	k = RandomBnd(n1 - 2) + (ZZ)1;// Нехай
	cout << endl << "k::" << k << endl;
	
	S = Sign(M1, d1, n1);

	if (M1 == Verify(S, e1, n1)) {cout << "Verified\n"; cout << Verify(S, e1, n1) << endl;}
	else{ cout << "Not verified\n" << Verify(S, e1, n1) << endl;}
	
	///////
	cout << "\nn1::"<<n1<<endl;
	cout << "\nn2::" << n2 << endl;


	
	cout << "\nSend..\n";
	Send(S, S1, k1, k, d1, n1, n2, e2);
	cout << "\nRecieve..";
	Recieve(S, S1, k1, d2, n2, k, e1, n1);
	
	


	system("pause");
	return 0;
}