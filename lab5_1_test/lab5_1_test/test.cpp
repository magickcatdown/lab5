
/**
* @file lab5_1.cpp
* @author ������� �.�., ��. 515-�2
* @date 26 ������ 2024
* @brief ����������� ������ � 5
*
* ������������ ���������. �������� 1
*/

#include "pch.h"
#include <stdio.h>
#include <locale.h>

/**
* ��������� ����, ����� �� ���
*
* @param date ������������ ��������, �� ������� ���� � ������ ��������
* @param number ������� ���� ����� ��������
* @param month ������� ����� ����� ��������
* @param year ������� �� ����� ��������
* @return 1, ���� �������� ������, ������ 0
*/
int date(int date, int* number, int* month, int* year);

int date(int date, int* number, int* month, int* year)
{
	// ��������, �� ���� ����� ����� ���� �����
	if (date / 100000 < 10) {
		date += 1000000; // ��������� 1 ������� �� ���� ��� ����������� ��������
		*number = date / 1000000 - 10; // ��������� ���
		*month = date % 1000000 / 10000; // ��������� �����
		*year = date % 10000; // ��������� ����
	}
	else {
		*number = date / 1000000; // ��������� ���
		*month = date % 1000000 / 10000; // ��������� �����
		*year = date % 10000; // ��������� ����
	}

	// �������� ��� ��� ������� �����
	switch (*month)
	{
	case 1: if (*number > 31) return 0; // ѳ����
	case 2:
		if (*number > 28)
			if (!((*year % 4 == 0) && (*number == 29))) return 0; // �����, ���������� ���������� ��
			else return 1;
	case 3: if (*number > 31) return 0; else return 1; // ��������
	case 4: if (*number > 30) return 0; else return 1; // ������
	case 5: if (*number > 31) return 0; else return 1; // �������
	case 6: if (*number > 30) return 0; else return 1; // �������
	case 7: if (*number > 31) return 0; else return 1; // ������
	case 8: if (*number > 31) return 0; else return 1; // �������
	case 9: if (*number > 30) return 0; else return 1; // ��������
	case 10: if (*number > 31) return 0; else return 1; // �������
	case 11: if (*number > 30) return 0; else return 1; // ��������
	case 12: if (*number > 31) return 0; else return 1; // �������
	default:
		return 0; // ������� �����
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