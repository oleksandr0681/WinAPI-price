// price.cpp.
// ��������� ��������� price, ��� ��������� ���� ���������, ���.

#include <math.h>
#include "struct_price.h"
// �� ���������� ������� �� ���� �������� ���� ����� price.h.

price::price
// ����������� ��������� price.
(
	float initial_prime_cost,
	// ����������� ���������� ���������, ���.
	float initial_profit,
	// ����������� ��������, ���.
	float initial_TAC,
	// ����������� ������� �� ������ ������� (���), ���.
	float initial_tax,
	// ����������� ����� ������� �� ������ � ��������, ���.
	float initial_excise,
	// ����������� ��������� �����, ���.
	float initial_sale_increase,
	// ����������� �������-������� ��������, ���.
	float initial_trade_increase
	// ����������� ���������� ��������, ���.
)
{
	float object_prime_cost=initial_prime_cost;
	// ��������� ����� �������-����� ���������� ���������, ���.
	float object_profit=initial_profit;
	// ��������� ����� �������-����� ��������, ���.
	float object_TAC=initial_TAC;
	// ��������� ����� �������-����� ������� �� ������ �������
	// (���), ���.
	float object_tax=initial_tax;
	// ��������� ����� �������-����� ����� ������� �� ������
	// � ��������, ���.
	float object_excise=initial_excise;
	// ��������� ����� �������-����� ��������� �����, ���.
	float object_sale_increase=initial_sale_increase;
	// ��������� ����� �������-����� �������-������� ��������, ���.
	float object_trade_increase=initial_trade_increase;
	// ��������� ����� �������-����� ���������� ��������, ���.
}

price::~price()
// ���������� ��������� price.
{
}

void price::set_prime_cost(float prime_cost)
// ��������� ������� ������� set_prime_cost().
{
	object_prime_cost=prime_cost;
	// ��������� ����� �������-����� object_prime_cost ��������,
	// ���������� ����� �������� prime_cost.
}

float price::get_prime_cost() const
// ��������� ������� ������� get_prime_cost().
{
	return object_prime_cost;
	// �������� �������� ����� ��������-����� object_prime_cost.
}

void price::set_profit(float profit)
// ��������� ������� ������� set_profit().
{
	object_profit=profit;
	// ��������� ����� �������-����� object_profit ��������,
	// ���������� ����� �������� profit.
}

float price::get_profit() const
// ��������� ������� ������� get_profit().
{
	return object_profit;
	// �������� �������� ����� ��������-����� object_profit.
}

void price::set_TAC(float TAC)
// ��������� ������� ������� set_TAC().
{
	object_TAC=TAC;
	// ��������� ����� �������-����� object_TAC ��������,
	// ���������� ����� �������� TAC.
}

float price::get_TAC() const
// ��������� ������� ������� get_TAC().
{
	return object_TAC;
	// �������� �������� ����� ��������-����� object_TAC.
}

void price::set_tax(float tax)
// ��������� ������� ������� set_tax().
{
	object_tax=tax;
	// ��������� ����� �������-����� object_tax ��������,
	// ���������� ����� �������� tax.
}

float price::get_tax() const
// ��������� ������� ������� get_tax().
{
	return object_tax;
	// �������� �������� ����� ��������-����� object_tax.
}

void price::set_excise(float excise)
// ��������� ������� ������� set_tax().
{
	object_excise=excise;
	// ��������� ����� �������-����� object_excise ��������,
	// ���������� ����� �������� excise.
}

float price::get_excise() const
// ��������� ������� ������� get_excise().
{
	return object_excise;
	// �������� �������� ����� ��������-����� object_excise.
}

void price::set_sale_increase(float sale_increase)
// ��������� ������� ������� set_sale_increase().
{
	object_sale_increase=sale_increase;
	// ��������� ����� �������-����� object_sale_increase ��������,
	// ���������� ����� �������� sale_increase.
}

float price::get_sale_increase() const
// ��������� ������� ������� get_sale_increase().
{
	return object_sale_increase;
	// �������� �������� ����� ��������-����� object_sale_increase.
}

void price::set_trade_increase(float trade_increase)
// ��������� ������� ������� set_trade_increase().
{
	object_trade_increase=trade_increase;
	// ��������� ����� �������-����� object_trade_increase ��������,
	// ���������� ����� �������� trade_increase.
}

float price::get_trade_increase() const
// ��������� ������� ������� get_trade_increase().
{
	return object_trade_increase;
	// �������� �������� ����� ��������-����� object_trade_increase.
}

float price::calculation()
// ��������� �������-����� calculation().
{
	object_price=object_prime_cost+object_profit+object_TAC+object_tax+object_excise+object_sale_increase+object_trade_increase;
	// ���������� ���� ���������, ���.
	return object_price;
	// �������� �������� ����� ��������-����� object_price.
}

float price::get_price() const
// ��������� ������� ������� get_price().
{
	return object_price;
	// �������� �������� ����� ��������-����� object_price.
}

/*
							 ������ ������ ����������

1	����� �������, ������ �����. ����� �������������� �++ �� 21 ����, 5-�
	�������.: ���. � ����. - �.: ������������ ��� "�������", 2008. - 768 �.:
	��.- �����. ���. ����.
2	����� �. �. Win32 API. ���������� ���������� ��� Windows. � ���.: �����,
	2008. � 592 �.: ��.
3	���������� �.�. ���������� C++ Builder. ���������� ���������� ��� �������.
	������� ����. � ���.: �����, 2007.
4	����� �. ����������� ������������. ������ 2.0. ������, 1989.
5	������� �.�. ������ ���������������� � Turbo C++. - ���.:
	"��� - ���������", 2007., 464 �.: ��. + CD-ROM.      http://tid.com.ua
6	�������� ����������: ϳ������� / �� ���. ���. �-�� ����. ����, ����.
	�.�. ������������. - �.: ����, 2003. - 608�. - ���. �����.
7	����������� �. ��������� �����: ������, ���������, �������. - �.:
	������, 2007. - 496�.
8	http://radiofront.narod.ru/htm/prog/htm/indexprog.html
9	http://w32api.narod.ru


	��� �������������� �������, ������ ������������� ������� ����������
���������, ����� ����������� ������������ � ������� �� 10 ���, �.�. 10%
� ���.
	������� ��������� �������������� ������� ����� �� ������ ������������
�� ������. ��������� ���������� �������������� ������� ����� ���������
������� ����������������� ���������.
*/

