#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int proc(int kod1);
int proc2(int  v, int os);
int main()
{
	int a = 0;
	setlocale(LC_ALL, "rus");

	cout << "\t\tПриветствуем вас в \"ATБ\"\n\n";
	cout << "*********************************************************\n";
	cout << "*\t\tВНИМАНИЕ АКЦИЯ!   \t\t\t*\n";
	cout << "*  При покупке товара на сумму от 200 грн, скидка: 10%  *\n";
	cout << "*  При покупке товара на сумму от 500 грн, скидка: 20%  *\n";
	cout << "*                                                       *\n";
	cout << "*********************************************************\n\n";
	cout << "Товар: \t\tКод товара:\t\tЦена:" << endl;
	cout << "Молоко \t  -\t1\t\t-\t3\n";
	cout << "Хлеб \t  -\t2\t\t-\t6\n";
	cout << "Сыр \t  -\t3\t\t-\t7\n";
	cout << "Вода \t  -\t4\t\t-\t5\n";
	cout << "Манго \t  -\t5\t\t-\t7\n";
	cout << "Бананы \t  -\t6\t\t-\t8\n";
	cout << "Кекс \t  -\t7\t\t-\t2\n";
	cout << "Яблоко \t  -\t8\t\t-\t5\n";
	cout << "Лемон \t  -\t9\t\t-\t5\n";
	cout << "Малина \t  -\t10\t\t-\t6\n\n";
	proc(a);
	system("pause");
	return 0;
}
int proc(int kod1)
{
	int cina, kol, i = 1, suma, kod, v = 0, b = 1, osuma = 0, bb = 0;
	ofstream file3("file.txt");
	file3.clear();
	file3.close();
	string tovar, chek;
	cout << "Введите код товара (1 - 10): ";
	cin >> kod;
	while (kod > 10 || kod < 1)
	{
		cout << "Вы ввели не верный код товара!\nВведите код товара еще раз ( 1 - 10 ):";
		cin >> kod;
	}
	while (i == 1) {
		v++;
		if (bb >= 1)
		{
			cout << "Введите код товара (1 - 10). Если вы хотите увидеть список товара с его кодом, введите 0: ";
			cin >> kod;
			while (kod > 10 || kod < 0)
			{
				cout << "Вы ввели не верный код товара!\nВведите код товара еще раз ( 1 - 10 ). Если вы хотите увидеть список товара с его кодом, введите 0: ";
				cin >> kod;
			}
		}
		bb++;
		if (kod == 0) {
			cout << "\nТовар: \t\tКод товара:" << endl;
			cout << "Молоко \t  -\t1\n";
			cout << "Хлеб \t  -\t2\n";
			cout << "Сыр \t  -\t3\n";
			cout << "Вода \t  -\t4\n";
			cout << "Манго \t  -\t5\n";
			cout << "Бананы \t  -\t6\n";
			cout << "Кекс \t  -\t7\n";
			cout << "Яблоко \t  -\t8\n";
			cout << "Лемон \t  -\t9\n";
			cout << "Малина \t  -\t10\n\n";
			cout << "Введите код товара (1 - 10): ";
			cin >> kod;
			while (kod > 10 || kod < 1)
			{
				cout << "Вы ввели не верный код товара!\nВведите код товара еще раз ( 1 - 10 ):";
				cin >> kod;
			}
		}
		if (kod == 1) {
			cina = 3;
			tovar = "Молоко";
		}
		if (kod == 2) {
			cina = 6;
			tovar = "Хлеб";
		}
		if (kod == 3) {
			cina = 7;
			tovar = "Сыр";
		}
		if (kod == 4) {
			cina = 5;
			tovar = "Вода";
		}
		if (kod == 5) {
			cina = 7;
			tovar = "Манго";
		}
		if (kod == 6) {
			cina = 8;
			tovar = "Бананы";
		}
		if (kod == 8) {
			cina = 2;
			tovar = "Яблоко";
		}
		if (kod == 9) {
			cina = 5;
			tovar = "Лемон";
		}
		if (kod == 10) {
			cina = 5;
			tovar = "Малина";
		}
		if (kod == 7)
		{
			cina = 6;
			tovar = "Кекс";
		}
		cout << "Вы хотите купить " << tovar << ". Цена за 1 товар: " << cina << " грн.\nКакое количество товара вы хотите купить?: ";
		cin >> kol;
		while (kol < 1)
		{
			cout << "Количество товара не может быть меньше 1! Введите количество товара: ";
			cin >> kol;
		}
		suma = cina * kol;
		osuma += suma;
		ofstream file("file.txt", ios::app);
		file << " " << tovar << " " << kol << " " << suma << "\n";
		file.close();
		cout << "Хотите продолжить покупку? ( да - 1 || нет - 0 ): ";
		cin >> i;
		while (i > 1 || i < 0)
		{
			cout << "Вы ввели не верное значение!\nЕсли хотите продолжить покупку, ввдетие 1. Если хотите завершить покупку, введите 0: ";
			cin >> i;
		}
	}
	system("cls");
	proc2(v, osuma);
	return 0;
}
int  proc2(int v, int os)
{
	int b = 1, oplata;
	string chek;
	if (os > 200 && os < 500) {
		os = os * 90 / 100;
		cout << "Общая сумма со скидкой в 10%: " << os << " грн.\n\n";
	}
	else if (os > 500) {
		os = os * 80 / 100;
		cout << "Общая сумма со скидкой в 20%: " << os << " грн.\n\n";
	}
	else
		cout << "Общая сумма: " << os << " грн.\n";
	cout << "Введите сумму, которой будете оплачивать товар: ";
	cin >> oplata;
	while (oplata < os)
	{
		cout << "Сумма не может быть меньше общей стоимости товара! Введите сумму еще раз: ";
		cin >> oplata;
	}
	system("cls");
	cout << "************** ЧЕК *************\n\n";
	cout << " Товар \tКоличество \tЦена\n\n";
	ifstream file("file.txt", ios::in);
	while (b <= v) {
		file >> chek;
		cout << " " << chek << "\t";
		file >> chek;
		cout << " " << chek << "\t\t";
		file >> chek;
		cout << " " << chek << endl;
		b++;
	}
	file.close();
	cout << "\n--------------------------------\n";
	cout << " Общая сумма к оплате: " << os << endl ;
	cout << "--------------------------------\n\n";
	cout << " Наличные: " << oplata << endl;
	cout << " Сдача: " << (oplata - os) << endl;
	cout << " Спасибо за покупку!\n\n";
	cout << "********************************\n";
	return 0;
}
