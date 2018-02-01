// test_ksi.cpp
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include "HashTable.h"

using namespace std;

float keyGen()
{
	long long temp = rand();
	temp = temp << 32;
	temp = temp | rand();
	temp = temp % 100000000;
	return (float)(temp / 10000.0);
}

int main()
{
	
	srand(time(0));
	setlocale(LC_CTYPE, "ru-RU");
	int n, m, k;
	float alpha;
	cout << "������������ ��� �������" << endl;
	cout << "������� ���������� ��������� (n): ";
	cin >> n;
	cout << "������� ����������� ���������� (alpha): ";
	cin >> alpha;
	HashTable<float, int> table(n);
	m = table.getSize();
	k = (int)(m * alpha);
	float *data = new float[k];
	for (int i = 0; i < k; i++)
	{
		data[i] = keyGen();
		table.insert(data[i], 1);
	}
	
	cout << "m - sqrt(m): " << n - sqrt(n) << endl;
	cout << "������� ��� �������: " << table.getKsiSqrAvg(n, alpha) << endl;
	cout << "m + sqrt(m): " << n + sqrt(n) << endl;

	system("pause");
}