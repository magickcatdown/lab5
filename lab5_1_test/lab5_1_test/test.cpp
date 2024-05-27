
/**
* @file lab5_1.cpp
* @author Пацалюк А.В., гр. 515-і2
* @date 26 травня 2024
* @brief Лабораторна робота № 5
*
* Застосування вказівників. Завдання 1
*/

#include "pch.h"
#include <stdio.h>
#include <locale.h>

/**
* Отримання року, місяця та дня
*
* @param date цілочисельне значення, що позначає дату у форматі ДДММРРРР
* @param number повертає день через вказівник
* @param month повертає місяць через вказівник
* @param year повертає рік через вказівник
* @return 1, якщо операція успішна, інакше 0
*/
int date(int date, int* number, int* month, int* year);

int date(int date, int* number, int* month, int* year)
{
	// Перевірка, чи дата займає більше однієї цифри
	if (date / 100000 < 10) {
		date += 1000000; // Додавання 1 мільйона до дати для правильного розбиття
		*number = date / 1000000 - 10; // Отримання дня
		*month = date % 1000000 / 10000; // Отримання місяця
		*year = date % 10000; // Отримання року
	}
	else {
		*number = date / 1000000; // Отримання дня
		*month = date % 1000000 / 10000; // Отримання місяця
		*year = date % 10000; // Отримання року
	}

	// Перевірка дня для кожного місяця
	switch (*month)
	{
	case 1: if (*number > 31) return 0; // Січень
	case 2:
		if (*number > 28)
			if (!((*year % 4 == 0) && (*number == 29))) return 0; // Лютий, враховуючи високосний рік
			else return 1;
	case 3: if (*number > 31) return 0; else return 1; // Березень
	case 4: if (*number > 30) return 0; else return 1; // Квітень
	case 5: if (*number > 31) return 0; else return 1; // Травень
	case 6: if (*number > 30) return 0; else return 1; // Червень
	case 7: if (*number > 31) return 0; else return 1; // Липень
	case 8: if (*number > 31) return 0; else return 1; // Серпень
	case 9: if (*number > 30) return 0; else return 1; // Вересень
	case 10: if (*number > 31) return 0; else return 1; // Жовтень
	case 11: if (*number > 30) return 0; else return 1; // Листопад
	case 12: if (*number > 31) return 0; else return 1; // Грудень
	default:
		return 0; // Невірний місяць
	}
}

TEST(Date, DateTest)
{
	int number_test, month_test, year_test;
	EXPECT_EQ(1, date(15062024, &number_test, &month_test, &year_test));
	EXPECT_EQ(1, date(6062024, &number_test, &month_test, &year_test));
	EXPECT_EQ(1, date(29022024, &number_test, &month_test, &year_test));
	EXPECT_EQ(0, date(99062024, &number_test, &month_test, &year_test));
	EXPECT_EQ(0, date(31062024, &number_test, &month_test, &year_test));
	EXPECT_EQ(0, date(29022022, &number_test, &month_test, &year_test));
}