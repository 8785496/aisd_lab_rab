//main.cpp
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

long long keyGen()
{
	long long temp = rand();
	temp = temp << 32;
	return  temp | rand();
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
	long long *data = new long long[k];
	//for (int i = 0; i < k; i++)
	//{
	//	data[i] = keyGen();
	//	cout << data[i] << endl;
	//}

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
		else
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

	cout << "Alpha = " << table.getCount() / table.getSize() << endl;
	cout << "Среднее количество операций на удаление: " << countRemove / (k / 2) << endl;
	cout << "Среднее количество операций на вставку: " << countInsert / (k / 2) << endl;
	cout << "Среднее количество операций на поиск: " << countSearch / (k / 2) << endl;

	system("pause");
}