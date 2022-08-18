#include "Stack.h"

void print_instruction(); //�������� �������  ������ ����������

int main()
{
	setlocale(LC_ALL, "ru");

	Stack<int> st; //��������� ������������� ����

	cout << "��������� ��� ������ �� ������ (int). ����� ����������!" << endl;
	print_instruction();
	cout << "�������: ";
	int choice;
	cin >> choice;

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			int element;
			cout << "������� �������: ";
			cin >> element;
			st.push(element);
			cout << "������� " << element << " ��������!";
			break;

		case 2:
			if (st.empty())
			{
				cout << "���� ������!";
				break;
			}
			cout << "������� " << st.pop() << " �����!";
			break;

		case 3:
			if (st.empty())
			{
				cout << "���� ������!";
				break;
			}
			st.print();
			break;

		case 4:
			print_instruction();
			break;

		default:
			cout << "������ �����!";
			break;
		}
		cout << endl << endl << "�������� �������: ";
		cin >> choice;
	}

	cout << endl << "���������� ������...";
	return 0;
}

void print_instruction() {

	cout << "��������� ������� : " << endl
		<< "1. �������� ������� � �����" << endl
		<< "2. ������� ��������� �������" << endl
		<< "3. ���������� ����" << endl
		<< "4. ���������� ����������" << endl
		<< "5. ��������� ������" << endl;

}