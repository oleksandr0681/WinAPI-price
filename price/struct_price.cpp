// price.cpp.
// Реалізація структури price, яка розраховує ціну продукції, грн.

#include <math.h>
#include "struct_price.h"
// Ця інструкція підключає до коду програми вміст файла price.h.

price::price
// Конструктор структури price.
(
	float initial_prime_cost,
	// Ініціалізація собівартості продукції, грн.
	float initial_profit,
	// Ініціалізація прибутку, грн.
	float initial_TAC,
	// Ініціалізація податку на додану вартість (ПДВ), грн.
	float initial_tax,
	// Ініціалізація інших податків та взносів у соцфонди, грн.
	float initial_excise,
	// Ініціалізація акцизного збору, грн.
	float initial_sale_increase,
	// Ініціалізація гуртово-збутової надбавки, грн.
	float initial_trade_increase
	// Ініціалізація торгівельної надбавки, грн.
)
{
	float object_prime_cost=initial_prime_cost;
	// Присвоєння змінній величині-члену собівартості продукції, грн.
	float object_profit=initial_profit;
	// Присвоєння змінній величині-члену прибутку, грн.
	float object_TAC=initial_TAC;
	// Присвоєння змінній величині-члену податку на додану вартість
	// (ПДВ), грн.
	float object_tax=initial_tax;
	// Присвоєння змінній величині-члену інших податків та взносів
	// у соцфонди, грн.
	float object_excise=initial_excise;
	// Присвоєння змінній величині-члену акцизного збору, грн.
	float object_sale_increase=initial_sale_increase;
	// Присвоєння змінній величині-члену гуртово-збутової надбавки, грн.
	float object_trade_increase=initial_trade_increase;
	// Присвоєння змінній величині-члену торгівельної надбавки, грн.
}

price::~price()
// Деструктор структури price.
{
}

void price::set_prime_cost(float prime_cost)
// Реалізація функції доступу set_prime_cost().
{
	object_prime_cost=prime_cost;
	// Присвоєння змінній величині-члену object_prime_cost значення,
	// переданого через параметр prime_cost.
}

float price::get_prime_cost() const
// Реалізація функції доступу get_prime_cost().
{
	return object_prime_cost;
	// Вертання значення змінної величини-члена object_prime_cost.
}

void price::set_profit(float profit)
// Реалізація функції доступу set_profit().
{
	object_profit=profit;
	// Присвоєння змінній величині-члену object_profit значення,
	// переданого через параметр profit.
}

float price::get_profit() const
// Реалізація функції доступу get_profit().
{
	return object_profit;
	// Вертання значення змінної величини-члена object_profit.
}

void price::set_TAC(float TAC)
// Реалізація функції доступу set_TAC().
{
	object_TAC=TAC;
	// Присвоєння змінній величині-члену object_TAC значення,
	// переданого через параметр TAC.
}

float price::get_TAC() const
// Реалізація функції доступу get_TAC().
{
	return object_TAC;
	// Вертання значення змінної величини-члена object_TAC.
}

void price::set_tax(float tax)
// Реалізація функції доступу set_tax().
{
	object_tax=tax;
	// Присвоєння змінній величині-члену object_tax значення,
	// переданого через параметр tax.
}

float price::get_tax() const
// Реалізація функції доступу get_tax().
{
	return object_tax;
	// Вертання значення змінної величини-члена object_tax.
}

void price::set_excise(float excise)
// Реалізація функції доступу set_tax().
{
	object_excise=excise;
	// Присвоєння змінній величині-члену object_excise значення,
	// переданого через параметр excise.
}

float price::get_excise() const
// Реалізація функції доступу get_excise().
{
	return object_excise;
	// Вертання значення змінної величини-члена object_excise.
}

void price::set_sale_increase(float sale_increase)
// Реалізація функції доступу set_sale_increase().
{
	object_sale_increase=sale_increase;
	// Присвоєння змінній величині-члену object_sale_increase значення,
	// переданого через параметр sale_increase.
}

float price::get_sale_increase() const
// Реалізація функції доступу get_sale_increase().
{
	return object_sale_increase;
	// Вертання значення змінної величини-члена object_sale_increase.
}

void price::set_trade_increase(float trade_increase)
// Реалізація функції доступу set_trade_increase().
{
	object_trade_increase=trade_increase;
	// Присвоєння змінній величині-члену object_trade_increase значення,
	// переданого через параметр trade_increase.
}

float price::get_trade_increase() const
// Реалізація функції доступу get_trade_increase().
{
	return object_trade_increase;
	// Вертання значення змінної величини-члена object_trade_increase.
}

float price::calculation()
// Реалізація функції-члена calculation().
{
	object_price=object_prime_cost+object_profit+object_TAC+object_tax+object_excise+object_sale_increase+object_trade_increase;
	// Розрахунок ціни продукції, грн.
	return object_price;
	// Вертання значення змінної величини-члена object_price.
}

float price::get_price() const
// Реалізація функції доступу get_price().
{
	return object_price;
	// Вертання значення змінної величини-члена object_price.
}

/*
							 Список джерел інформації

1	Джесс Либерти, Брэдли Джонс. Освой самостоятельно С++ за 21 день, 5-е
	издание.: Пер. с англ. - М.: Издательский дом "Вильямс", 2008. - 768 с.:
	ил.- Парал. тит. англ.
2	Щупак Ю. А. Win32 API. Разработка приложений для Windows. – СПб.: Питер,
	2008. – 592 с.: ил.
3	Бобровский С.И. Технологии C++ Builder. Разработка приложений для бизнеса.
	Учебный курс. — СПб.: Питер, 2007.
4	Турбо С. Руководство пользователя. Версия 2.0. Москва, 1989.
5	Культин Н.Б. Основы программирования в Turbo C++. - СПб.:
	"БХВ - Петербург", 2007., 464 с.: ил. + CD-ROM.      http://tid.com.ua
6	Економіка підприємства: Підручник / За заг. ред. д-ра екон. наук, проф.
	С.Ф. Покропивного. - К.: КНЕУ, 2003. - 608с. - Рос. мовою.
7	Коноваленко В. Авторське право: автору, редактору, видавцю. - Х.:
	Фактор, 2007. - 496с.
8	http://radiofront.narod.ru/htm/prog/htm/indexprog.html
9	http://w32api.narod.ru


	Для нематериальных активов, период использования которых невозможно
установит, норма амортизации определяется в расчёте на 10 лет, т.е. 10%
в год.
	Оценить стоимость нематериальных активов можно по методу освобождения
от роялти. Стоимость уникальных нематериальных активов можно расчитать
методом восстановительной стоимости.
*/

