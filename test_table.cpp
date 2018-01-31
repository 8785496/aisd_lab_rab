//main.cpp
#include <iostream>
#include <string>
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
	setlocale(LC_CTYPE, "ru-RU");
	int n, m, k;
	float alpha;
	cout << "Введите количество элементов (n): ";
	cin >> n;
	cout << "Введите коэффициент заполнения (alpha): ";
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

	int countRemove = 0;
	int countInsert = 0;
	int countSearch = 0;
	int value;

	for (int i = 0; i < k / 2; i++)
	{
		if (i % 10 == 0) // промахи
		{
			table.remove(keyGen());
			countRemove += table.getCountIteration();

			table.insert(data[rand() % k], 1);
			countInsert += table.getCountIteration();

			table.search(keyGen(), value);
			countSearch += table.getCountIteration();
		}
		else // попадания
		{
			int index = rand() % k;
			float key = keyGen() / 10000;

			table.remove(data[index]);
			countRemove += table.getCountIteration();

			table.insert(key, 1);
			countInsert += table.getCountIteration();

			data[index] = key;

			table.search(data[rand() % k], value);
			countSearch += table.getCountIteration();
		}
	}
	alpha = 1.0f * table.getCount() / table.getSize();
	cout << "Alpha = " << alpha << endl;
	cout << "Среднее количество операций на удаление: " << 1.0f * countRemove / (k / 2) << endl;
	cout << "Среднее количество операций на вставку: " << 1.0f * countInsert / (k / 2) << endl;
	cout << "Среднее количество операций на поиск: " << 1.0f * countSearch / (k / 2) << endl;

	system("pause");
}