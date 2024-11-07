﻿#include <iostream>
#include <chrono>

int main()
{
	/*--------------------------------------------------------------- пункт 3  ------------------------------------------------------------------------------------------------------*/

	int arr[4][3] = {
				1, 2, 3,
				4, 5, 6,
				7, 8, 9,
				10, 11, 12
	};

	int replaceDig = 0; // число, на которое будем заменять

	std::cout << "\narray before:\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}

	__asm {
		cld // сбрасываем флаги
		mov ebx, 2 // 2 - колво четных строк в массиве
		lea edi, [arr + 12] // загружаем начало на вторую строку (четную). один элемент занимает 4 байта, по этому начало 2й строки = 12

	loop1:
		mov eax, replaceDig
		mov ecx, 3 // подсчет кол-ва элементов в строке
		rep stosd // кладет из eax -> edi. т.е. заменяет число в строке, на которое указывает edi (повторяем 3 раза, для трех элементов в стрроке)

		add edi, 12 // переход к следующей строке. прыгаем от 12го к 24му
		dec ebx // уменьшили счетчик кол-ва четных строк в массиве
		cmp ebx, 0 // сравниваем с нулем. если не ноль => повторяем
		jne loop1 // ну и прыг-скок к началу для замену
	}

	std::cout << "array after:\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}

	return 0;
}
