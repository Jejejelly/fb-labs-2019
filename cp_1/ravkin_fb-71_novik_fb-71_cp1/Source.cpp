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
	map<char, int> m = { {'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{'�', 0},{' ',0} };
	vector <pair<string, int>> vector_b;
	setlocale(LC_ALL, "Rus");

	ifstream file("D:\\VISUAL STUDIO 4\\Project3\\text.txt");
	ofstream file_after_filter_with_space("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space.txt");
	ofstream file_after_filter_without_space("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");
	ofstream file_after_filter_with_space2("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");

	if (!file) { cout << "���� �� ������\n\n"; }
	else { cout << "��� ��! ���� ������!\n\n"; }

	int n = 0;
	char ch = '�';
	while (file.get(ch)) {

		auto it = m.find(ch);
		if (it != m.end()) {

			if (((it->first) >= '�') && ((it->first) <= '�'))
			{
				ch = it->first + ('�' - '�');
			}
			else { ch = it->first; }
			file_after_filter_with_space << ch;

		}
	}
	file.close();
	file_after_filter_with_space.close();

	ifstream file_with_space("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space.txt");

	if (!file_with_space) { cout << "����2 �� ������\n\n"; }
	else { cout << "��� ��! ���� ������!\n\n"; }
	char pred = '!';
	while (file_with_space.get(ch)) {

		if (!(pred == ' ' && ch == ' ')) {
			if (ch == '�' || ch == '�')ch = '�';
			if (ch == '�' || ch == '�')ch = '�';
			auto iter = m.find(ch);
			if (iter != m.end()) { iter->second++; }
			file_after_filter_with_space2 << ch;
			n++;
		}
		pred = ch;
	}
	file_with_space.close();
	file_after_filter_with_space2.close();
	ifstream file3("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");
	while (file3.get(ch))
	{
		if ((ch != ' ')) {
			file_after_filter_without_space << ch;
		}
	}
	map<unsigned, string>::iterator it;
	//������� ����

	vector<pair<int, char>> vector;
	for (auto it = m.begin(); it != m.end(); it++) {
		vector.push_back(make_pair(it->second, it->first));
	}
	sort(vector.rbegin(), vector.rend());
	float buff0 = 0;
	cout << "������� ���� � ��������" << endl;
	for (int i = 0; i < 32; i++) {
		cout << vector[i].second << ":" << ((float)(vector[i].first) / n * 100) << " %" << endl;
		buff0 += ((float)(vector[i].first) / n * 100);
	}
	cout << buff0 << endl;
	cout << "����� ��������: " << n << endl<<endl;
	file3.close();

	//������� �������
	ifstream file4("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");
	
	map <string, int> bigram;
	char ch1, ch2;
	string ch3;
	int nn = 0;
	while (!file4.eof()) {
		file4.get(ch1);
		file4.get(ch2);
		ch3.push_back(ch1);
		ch3.push_back(ch2);

		auto it = bigram.find(ch3);
		if (it == bigram.end())
		{
			bigram.emplace(ch3, 1);
		}
		else 
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	double buff=0;
	cout << "������� ������� � ������ � ����� 2 � ���������:" << endl;
	int l = 0;
	for (auto it = bigram.begin(); it != bigram.end(); it++) {

		cout<< it->first<<":"<<(double)it->second/nn*100<<" ";
		buff += (double)it->second / nn * 100;
	}
	cout << buff << endl;
	file4.close();

	//�������� ��� ��������� � ���������
	double H = 0;
	double p;
	for (int i = 0; i < 32; i++) {
		p = (double)vector[i].first / n;
		H += p * (log(1 / p)/log(2));
	}
	cout << endl;
	cout <<"�������� ��� ���������� c ���������:\t\t" << H << endl;
	cout << "R ��� ���������� c ���������:\t\t\t" << 1 - (H / 5) <<endl;
	cout << endl;
	//�������� ��� ���������� ��� �������� 1 �������
	/*cout << vector[0].first << "probel" << endl;
	H = 0;
	p = 0;
	for (int i = 1; i < 32; i++) {
		
			p = (float)vector[i].first / (n-vector[0].first);
			H += p * log(1 / p);
		
	}
	
	cout << "�������� ��� ���������� ��� ��������:" << H << endl;
	cout << n - vector[0].first << endl;
	*/
	//�������� ��� ���������� ��� �������� 2 �������
	ifstream file5("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");
	n = 0;
	H = 0;
	p = 0;
	vector.clear();
	for (auto it = m.begin(); it != m.end(); it++)
	{
		it->second = 0;
	}
	while (file5.get(ch)) {
		n++;
		auto it = m.find(ch);
		if (it != m.end()) { it->second++; }	
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		vector.push_back(make_pair(it->second, it->first));
	}
	sort(vector.rbegin(), vector.rend());
	buff0 = 0;
	cout << "������� ���� ��� �������:" << endl;
	for (int i = 0; i < 31; i++) {
		cout << vector[i].second << ":" << ((float)(vector[i].first) / n * 100) << " %" << endl;
		buff0 += ((float)(vector[i].first) / n * 100);
		p = (float)vector[i].first / n;
		H += p * (log(1 / p)/log(2));
	}

	cout << buff0 << endl;
	cout << endl;
	cout <<"�������� ��� ����������� ��� ��������:\t\t"<< H << endl;
	cout << "R ��� ���������� ��� ��������:\t\t\t" << 1-(H / 5) << endl;
	//cout << n << endl;
	//�������� ��� �������� � ��������� � ����� 2
	H = 0;
	p = 0;
	for (auto it = bigram.begin(); it != bigram.end(); it++)
	{
		p = (double)it->second / nn;
		H += (p * (log(1 / p) / log(2)))/2;
	}
	/*for (int i = 0; i < vector_b.size(); i++)
	{
		p = (float)vector_b[i].second / nn;
		H += p * (log(1 / p) / log(2));
	}
	*/
	cout << "�������� ��� �������� c ��������� � ����� 2:\t" << H << endl;
	cout << "R ��� �������� c ��������� � ����� 2::\t\t" << 1-(H / 5) << endl;
	//�������� ��� �������� ��� �������� � ����� 2
	ifstream file6("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");

	map <string, int> bigram2;
	H = 0;
	p = 0;
	nn = 0;
	while (!file6.eof()) {
		file6.get(ch1);
		file6.get(ch2);
		ch3.push_back(ch1);
		ch3.push_back(ch2);

		auto it = bigram2.find(ch3);
		if (it == bigram2.end())
		{
			bigram2.emplace(ch3, 1);
		}
		else
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	vector_b.clear();
	cout << endl;
	cout << "������� ������� ��� �������� � ����� 2:" << endl;
	cout << endl;
	for (auto it = bigram2.begin(); it != bigram2.end(); it++)
	{
		cout << it->first << ":" << (double)it->second / nn * 100 << "  ";
		p = (float)it->second / nn;
		H += p * (log(1 / p) / log(2));
	}
	cout << endl << endl;
	cout << "�������� ��� ������� ��� �������� � ����� 2:\t" << H/2 << endl;
	cout << "R ��� �������� ��� �������� � ����� 2:\t\t" <<1 - H / 10 << endl;
	file6.close();
	file4.close();
	//�������� ��� �������� � ��������� � ����� 1
	//
	ifstream file7("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_with_space2.txt");
	bigram.clear();
	ch3.clear();
	nn = 0;
	H = 0;
	ch1 = '!';
	while (!file7.eof()) {
		if(ch1!='!')
		ch1 = ch2;
		else
		file7.get(ch1);

		file7.get(ch2);
		
		ch3.push_back(ch1);
		ch3.push_back(ch2);
		auto it = bigram.find(ch3);
		if (it == bigram.end())
		{
			bigram.emplace(ch3, 1);
		}
		else
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	cout << endl;
	cout << "������� ������� � ������ � ����� 1 � ���������:" << endl;
	cout << endl;
	for (auto it = bigram.begin(); it != bigram.end(); it++)
	{
		cout << it->first << ":" << (double)it->second / nn * 100 <<"  ";
		p = (float)it->second / nn;
		H += p * (log(1 / p) / log(2));
	}
	cout << endl;
	cout << endl;
	cout << "�������� ��� �������� � ��������� � ����� 1:\t" << H/2  << endl;
	cout << "R ��� �������� � ��������� � ����� 1:\t\t" << 1 - (H / 10) << endl;
	file7.close();
	//�������� ��� �������� ��� �������� � ����� 1
	ifstream file8("D:\\VISUAL STUDIO 4\\Project3\\text_after_filter_without_space.txt");

	bigram.clear();
	H = 0;
	p = 0;
	nn = 0;
	ch3.clear();
	ch1 = '!';
	while (!file8.eof()) {
		if (ch1 != '!')
			ch1 = ch2;
		else
			file8.get(ch1);
			
		file8.get(ch2);

		ch3.push_back(ch1);
		ch3.push_back(ch2);

		auto it = bigram.find(ch3);
		if (it == bigram.end())
		{
			bigram.emplace(ch3, 1);
		}
		else
		{
			it->second++;
		}
		ch3.clear();
		nn++;
	}
	cout << endl;
	cout << "������� ������� ��� �������� � ����� 1:" << endl;
	cout << endl;
	for (auto it = bigram.begin(); it != bigram.end(); it++)
	{
		cout << it->first << ":" << (double)it->second / nn * 100 << "  ";
		p = (float)it->second / nn;
		H += p * (log(1 / p) / log(2));
	}
	cout << endl;
	cout << endl;
	cout << "�������� ��� ������� ��� �������� c ����� 1:\t" << H / 2 << endl;
	cout << "R ��� �������� ��� �������� � ����� 1:\t\t" << 1-(H / 10) << endl;
	cout << endl;
	return 0;
}