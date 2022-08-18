#include "Stack.h"

void print_instruction(); //прототип функции  печати инструкции

int main()
{
	setlocale(LC_ALL, "ru");

	Stack<int> st; //объявляем целочисленный стек

	cout << "Программа для работы со стеком (int). Добро пожаловать!" << endl;
	print_instruction();
	cout << "Введите: ";
	int choice;
	cin >> choice;

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			int element;
			cout << "Введите элемент: ";
			cin >> element;
			st.push(element);
			cout << "Элемент " << element << " добавлен!";
			break;

		case 2:
			if (st.empty())
			{
				cout << "Стек пустой!";
				break;
			}
			cout << "Элемент " << st.pop() << " удалён!";
			break;

		case 3:
			if (st.empty())
			{
				cout << "Стек пустой!";
				break;
			}
			st.print();
			break;

		case 4:
			print_instruction();
			break;

		default:
			cout << "Ошибка ввода!";
			break;
		}
		cout << endl << endl << "Выберите функцию: ";
		cin >> choice;
	}

	cout << endl << "Завершение работы...";
	return 0;
}

void print_instruction() {

	cout << "Доступные функции : " << endl
		<< "1. Добавить элемент в конец" << endl
		<< "2. Удалить последний элемент" << endl
		<< "3. Напечатать стек" << endl
		<< "4. Напечатать инструкцию" << endl
		<< "5. Завершить работу" << endl;

}