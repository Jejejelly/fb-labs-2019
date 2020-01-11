#include "windows.h"
#include <iostream>
#include <fstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <char, int> alf{ {'�',0},{'�',1},{'�',2},{'�',3},{'�',4},{'�',5},{'�',6},{'�',7},{'�',8},{'�',9},{'�',10},{'�',11},{'�',12},{'�',13},{'�',14},{'�',15},{'�',16},{'�',17},{'�',18},{'�',19},{'�',20},{'�',21},{'�',22},{'�',23},{'�',24},{'�',25},{'�',26},{'�',27},{'�',28},{'�',29},{'�',30} };
	map <char, int> keyy;
	map <int, char> alf2{ { 0, '�'},{1, '�'},{2, '�'},{3, '�'},{4, '�'},{5, '�'},{6, '�'},{7, '�'},{8, '�'},{9, '�'},{10, '�'},{11, '�'},{12, '�'},{13, '�'},{14, '�'},{15, '�'},{16, '�'},{17, '�'},{18,'�'},{19, '�'},{20, '�'},{21, '�'},{22, '�'},{23, '�'},{24, '�'},{25, '�'},{26, '�'},{27, '�'},{28, '�'},{29, '�'},{30, '�'} };
	map <char, float> index_sovpadeniy{ {'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0} };
	map <int, string> shifro_text{ {2, ""},{3,""},{4,""},{5,""},{10,""},{11,""},{12,""},{13,""},{14,""},{15,""},{16,""},{17,""},{18,""},{19,""},{20,""} };
	setlocale(LC_ALL, "Rus");
	ifstream text("D:\\VISUAL STUDIO 4\\Project4\\text.txt");
	//ofstream texts_after_shifr("D:\\VISUAL STUDIO 4\\Project4\\texts_after_shifr.txt");
	vector <string> keys{ "","","��","���","����","�����","","","","","����������","�����������" ,"������������","�������������" ,"��������������","���������������", "����������������", "�����������������", "������������������", "�������������������", "��������������������" };
	vector <string> text_r{ "","","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"","","","" };
	vector <string> blocks{ "","","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"","","" };
	if (!text)
	{
		cout << "����1 �� ������\n\n";

	}
	else
	{
		cout << "��� ��! ����1 ������!\n\n";
	}
	string key = " ";
	int x;
	char ch;
	int k;
	int y;

	const int m = 31;
	for (int r = 2; r <= 20; r++)
	{
		text.close();
		ifstream text("D:\\VISUAL STUDIO 4\\Project4\\text.txt");
		if (r < 6 || r >9)
		{
			cout << "���� �������: " << r << endl;
			//cin >> key;
			key = keys[r];
			if (key.length() != r)
			{
				cout << "������������ ����� �����, ������� ��� ���" << endl;
				cin >> key;
			}
			int z = 0;
			while (text.get(ch)) {
				auto iterator_text = alf.find(ch);
				auto iterator_key = alf.find(key[z]);
				if (iterator_text != alf.end() && iterator_key != alf.end())
				{
					x = iterator_text->second;
					k = iterator_key->second;
					y = (x + k) % m;
					if (z < key.length() - 1)
					{
						z++;
					}
					else
					{
						z = 0;
					}

					//auto iterator_shifr = alf.find();
					auto iterator_y = alf2.find(y);
					cout << iterator_y->second;
					auto iterator_r = shifro_text.find(r);
					iterator_r->second += iterator_y->second;
				}
				else { cout << "bl"; }
			}
			cout << endl;
			text.close();
			ifstream text("D:\\VISUAL STUDIO 4\\Project4\\text.txt");
		}
	}

	text.close();

	int L = 0;
	ifstream text2("D:\\VISUAL STUDIO 4\\Project4\\text.txt");
	while (text2.get(ch)) {
		auto iterator_text = index_sovpadeniy.find(ch);
		if (iterator_text != index_sovpadeniy.end())
		{
			iterator_text->second++;
		}
		L++;
	}
	float INDEX_SOVPADENIY = 0;
	for (auto&& pair : index_sovpadeniy) {
		pair.second = pair.second * (pair.second - 1) / (L * (L - 1));
		cout << pair.second << endl;
		INDEX_SOVPADENIY = INDEX_SOVPADENIY + pair.second;
	}
	cout << "������ ����������� ��������� ������:" << INDEX_SOVPADENIY << endl;

	index_sovpadeniy.clear();
	map <char, float> index_sovpadeniy2{ {'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0} };
	L = 0;
	for (int r = 2; r <= 20; r++)
	{
		if (r < 6 || r >9)
		{
			auto iterator_shifro_text = shifro_text.find(r);
			for (auto ch : iterator_shifro_text->second)
			{
				auto iterator_text = index_sovpadeniy2.find(ch);
				if (iterator_text != index_sovpadeniy2.end())
				{
					iterator_text->second++;
				}
				L++;
			}
			float INDEX_SOVPADENIY = 0;
			for (auto&& pair : index_sovpadeniy2) {
				pair.second = pair.second * (pair.second - 1) / (L * (L - 1));
				//cout << pair.second << endl;
				INDEX_SOVPADENIY = INDEX_SOVPADENIY + pair.second;
			}
			cout << "������ ���������� ��������� ������ ��� r=" << r << " : " << INDEX_SOVPADENIY << endl;
			L = 0;
			for (auto&& pair : index_sovpadeniy2) {
				pair.second = 0;
			}
		}
	}
	alf.clear();
	alf2.clear();
	map <char, int> alf3{ {'�',0},{'�',1},{'�',2},{'�',3},{'�',4},{'�',5},{'�',6},{'�',7},{'�',8},{'�',9},{'�',10},{'�',11},{'�',12},{'�',13},{'�',14},{'�',15},{'�',16},{'�',17},{'�',18},{'�',19},{'�',20},{'�',21},{'�',22},{'�',23},{'�',24},{'�',25},{'�',26} ,{'�',27},{'�',28},{'�',29},{'�',30},{'�',31} };
	map <int, char> alf4{ { 0, '�'},{1, '�'},{2, '�'},{3, '�'},{4, '�'},{5, '�'},{6, '�'},{7, '�'},{8, '�'},{9, '�'},{10, '�'},{11, '�'},{12, '�'},{13, '�'},{14, '�'},{15, '�'},{16, '�'},{17, '�'},{18,'�'},{19, '�'},{20, '�'},{21, '�'},{22, '�'},{23, '�'},{24, '�'},{25, '�'},{26,'�'} ,{27, '�'},{28, '�'},{29, '�'},{30, '�'},{31, '�'} };
	cout << endl;
	ifstream sht("D:\\VISUAL STUDIO 4\\Project4\\��.txt");
	k = 0;
	int b = 0;
	//string stroka = "";
	for (int r = 2; r <= 30; r++)
	{
		b = 0;
		while (sht.get(ch))
		{
			if (!b == 0)k++;

			if (r == k || b == 0)
			{
				text_r[r].push_back(ch);
				k = 0;
				b = 1;
			}
		}
		sht.clear();
		sht.seekg(0, ios::beg);
	}
	map <char, float> index_sovpadeniy3{ {'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�', 0} ,{'�',0},{'�',0},{'�',0},{'�',0},{'�',0} };
	L = 0;
	for (int r = 2; r <= 30; r++)
	{
		for (auto ch : text_r[r])
		{
			auto iterator_text = index_sovpadeniy3.find(ch);
			if (iterator_text != index_sovpadeniy3.end())
			{
				iterator_text->second++;
			}
			L++;
		}
		float INDEX_SOVPADENIY = 0;
		for (auto&& pair : index_sovpadeniy3) {
			pair.second = pair.second * (pair.second - 1) / (L * (L - 1));
			//cout << pair.second << endl;
			INDEX_SOVPADENIY = INDEX_SOVPADENIY + pair.second;
		}
		cout << "������ ���������� ��������� ������ ��� r=" << r << " : " << INDEX_SOVPADENIY << endl;
		L = 0;
		for (auto&& pair : index_sovpadeniy3) {
			pair.second = 0;
		}
	}
	int R;
	cout << "B������ ����� ��������������� �����:" << endl;
	cin >> R;
	//R = 30;
	sht.close();
	ifstream sht2("D:\\VISUAL STUDIO 4\\Project4\\��.txt");
	int r = 0;
	while (sht2.get(ch))
	{
		blocks[r].push_back(ch);
		r++;
		if (r == R)
		{
			r = 0;
		}
	}
	vector <char> most_frequent_bukva_of_block_r;
	map <char, float> index_sovpadeniy4{ {'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0} ,{'�',0},{'�',0},{'�',0},{'�',0},{'�',0} };
	int max;
	char max_b;
	bool boo = true;
	int kk = 0;
	//vector <int> kkkkkk;
	for (int r = 0; r < R; r++)
	{
		for (auto ch : blocks[r])
		{	
			
			auto iterator_text = index_sovpadeniy4.find(ch);
			if (iterator_text != index_sovpadeniy4.end())
			{
				iterator_text->second++;
				kk++;
			}
			//L++;
		}
		if(r==1 || r==12 || r==15 || r==23 || r==26)
		{
		
				for (auto& item : index_sovpadeniy4)
				{
					cout << item.first << " : " <<setprecision(2)<<(double) item.second/kk*100 <<" "; //����� ������ � ��������
				}
				cout << endl;
		}
		
		for (auto&& pair : index_sovpadeniy4) {
			if (boo) { max = pair.second; }
			boo = false;
			if (pair.second >= max)
			{
				max = pair.second;
				max_b = pair.first;
			}
		}
		
		most_frequent_bukva_of_block_r.push_back(max_b);
		//L = 0;
		for (auto&& pair : index_sovpadeniy4) {
			pair.second = 0;
		}
		boo = true;
		kk = 0;
	}
	int chislo_bukvi = 0;
	

	vector <int> sdvigaem_na;
	int buf = 0;
	for (auto x: most_frequent_bukva_of_block_r)
	{
		buf = 0;
		auto iterator = alf3.find(x);
		buf = iterator->second - 14;
		if (buf < 0) { buf += 32; }

		sdvigaem_na.push_back(buf);
	}
	sht.close();
	
	for (auto x : sdvigaem_na)
	{
		auto iterator_key = alf4.find(x);
		if (iterator_key == alf4.end()) { cout << iterator_key->second; cout << " blyyaaa"; }
		cout << iterator_key->second;
	}
	cout << endl;
	cout << "������� �������������� ����:" << endl;
	string key0;
	cin >> key0;
	vector<int> keyyyy;
	for (int i = 0; i < key0.length(); i++) {
		auto iterator = alf3.find(key0[i]);
		keyyyy.push_back(iterator->second);
	}

	ifstream shttt("D:\\VISUAL STUDIO 4\\Project4\\��.txt");
	
	int q = 0;
	int i = 0;
	cout << "�������������� �����:" << endl;
	map <char, float> index_sovpadeniy5{ {'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�',0},{'�', 0} ,{'�',0},{'�',0},{'�',0},{'�',0},{'�',0} };
	

	vector <string> blocks2{ "","","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"","","" };
	r = 0;
	while (shttt.get(ch))
	{
		auto iterator_ch = alf3.find(ch);
		//auto iterator_key = alf3.find(q);
			
		if (iterator_ch->second >= keyyyy[i]) { chislo_bukvi=iterator_ch->second - keyyyy[i]; }
		else{ chislo_bukvi=iterator_ch->second - keyyyy[i] +32; }
		i++;
		if (i == 28) { i = 0; }
		

		auto iterator_bukvi = alf4.find(chislo_bukvi);

		/*
		auto iter_index_sovp = alf4.find(chislo_bukvi);
		if (iter_index_sovp != index_sovpadeniy2.end())
		{	
			if(iter_index_sovp->second==0)
			{
				iter_index_sovp.push
			}
			iterator_text->second++;

		}
		*/
		cout << iterator_bukvi->second;
		blocks2[r].push_back(iterator_bukvi->second);
		r++;
		if (r == 28)
		{
			r = 0;
		}
		
	}
	int k_vo_bukv = 0;
	cout << endl;
	for (int r = 0; r < 28; r++)
	{


		for (auto ch : blocks2[r])
		{

			auto iterator = index_sovpadeniy5.find(ch);
			if (iterator != index_sovpadeniy5.end())
			{
				iterator->second++;
				k_vo_bukv++;
			}

		}
		cout << r+1 << ":" << endl;
		for (auto& item : index_sovpadeniy5)
		{
			cout << item.first << " : " << setprecision(2) << (double)item.second / k_vo_bukv * 100 <<endl; //����� ������ � ��������
		}
		cout << endl;

		for (auto& item : index_sovpadeniy5)
		{
			item.second = 0;
		}
		k_vo_bukv = 0;
	}
	/*
	ifstream vt2("D:\\VISUAL STUDIO 4\\Project4\\��.txt");
	int r = 0;
	while (sht2.get(ch))
	{
		blocks[r].push_back(ch);
		r++;
		if (r == 28)
		{
			r = 0;
		}
	}
	*/

}

	
