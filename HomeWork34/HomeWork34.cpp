#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
void show_arr(T arr[], const int length) {
	if (length <= 0)
		throw invalid_argument("обаружена отрицательная длинна массива");
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";

}
//Задача 34.1
template <typename T>
void uniq(T arr1[], const int length1, T arr2[], const int length2) {
	int tmp_length = 0;
	T* arr = new T[tmp_length];
	
	//добавляем элементы из первого массива
	for (int i = 0; i < length1; i++)
	{
		bool from_arr = false;
		for (int j = 0; j < length2; j++)
		{
			if (arr1[i] == arr2[j]) 
			{
				from_arr = true;
				break;
			}				
		}
		if (!from_arr)
		{
			arr[tmp_length] = arr1[i];
			tmp_length++;
		}		
	}
		
	//добавляем элементы из второго массива
	for (int i = 0; i < length2; i++)
	{
		bool from_arr = false;
		for (int j = 0; j < length1; j++)
		{
			if (arr2[i] == arr1[j])
			{
				from_arr = true;
				break;
			}
		}
		if (!from_arr)
		{
			arr[tmp_length] = arr2[i];
			tmp_length++;
		}
	}
	
	//выводим итоговый массив
	cout << "Массив уникальных значений:\n";
	cout << '[';
	for (int i = 0; i < tmp_length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Задача 34.2
double fract(double num) {
	int whole_num = num;
	return num - whole_num;
}
//Задача 34.3	
double double_rand(double begin = 0.0, double end = 1.0) {
	
	return begin + (double)rand() / RAND_MAX * (end - begin);
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	//Задача 34.1. Напишите функцию uniq, которая принимает два массива и их длины, после чего выводит массив значений, которые являются уникальными для обоих переданных массивов.

	cout << "Задача 34.1. Массив уникальных значений из двух массивов.\n";
	
	const int size1 = 5;
	int mass1[size1];
	try {
		fill_arr(mass1, size1, 1, 11);
		cout << "Массив 1:\n";
		show_arr(mass1, size1);
	}
	catch (const exception& ex) {
		cout << "Ошибка: " << ex.what() << '\n';
	}
	const int size2 = 5;
	int mass2[size2];
	try {
		fill_arr(mass2, size2, 2, 10);
		cout << "Массив 2:\n";
		show_arr(mass2, size2);
	}
	catch (const exception& ex) {
		cout << "Ошибка: " << ex.what() << '\n';
	}

	uniq(mass1, size1, mass2, size2);


	//Задача 34.2. Создайте функцию fract, которая принимает вещественное число и возвращает его дробную часть (например, в числе 3.14 дробная часть равна 0.14).
	cout << "\nЗадача 34.2. Дробная часть.\n";
	cout << "Введите вещественное число: ";
	double k;
	cin >> k;
	cout << "\nДробная часть вещественного числа: " << fract(k) << "\n\n";

	//Задача 34.3. Создайте функцию double_rand, возвращающую случайное число в диапазоне от 0 до 1 невключительно.
	cout << "Задача 34.3. Случайное число в диапазоне от 0 до 1 невключительно.\n";

	cout << "Случайное число в диапазоне от 0 до 1 невключительно " << double_rand() << "\n\n";




	return 0;
}