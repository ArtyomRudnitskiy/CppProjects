#pragma once
#include <iostream>
using namespace std;

template<typename T> //шаблонный 
class Stack
{
public:
	Stack(); //конструктор
	~Stack(); //деструктор
	void push(T data); //добавить узел
	T pop(); //удалить последний узел, возвращает удалённый эл-т
	int size() { return Size; } //вернуть размер стека
	bool empty(); //проверка на пустоту
	T peek(int index); //итерация по стеку (возвращает значение по индексу с конца)
	void print();


private:

	template<typename T>
	class Node
	{
	public:

		// записывать поля в приватную секцию нет смысла, потому что Node - внутренний класс
		Node* pNext; //указатель на следующий узел
		T data; //данные

		//конструктор узла стека, по умолчанию данные = конструктору по умолчанию шаблонного типа данных (как ноль у int), а указатель на следующий узел = нулевому указателю (в пустоту)
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head; //храним в стеке верхнюю "тарелку"
	int Size; //размер стека, чтобы не итерироваться каждый раз для подсчёта, это слишком затратно
};

template<typename T>
Stack<T>::Stack() //конструктор - сначала размер равен нулю, верхней "тарелки" нет - nullptr
{
	Size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack() //деструктор, вызывает метод pop, т.е. удаляет элементы, пока размер не равен 0
{
	while (Size)
	{
		pop();
	}
}

template<typename T>
void Stack<T>::push(T data) //добавление эл-та (сверху)
{
	//head слева от "=" - это старая голова (после добавления станет второй "тарелкой"). Код читается справа налево
	head = new Node<T>(data, head);  //получается, что мы создаём новый узел, её прицепляем к старой голове, передавая head, и объявляем новый узел головой
	Size++; //увеличиваем размер стека
}

template<typename T>
T Stack<T>::pop() //удаление элемента (последнего)
{
	if (Size == 0) return T(); //если удалять нечего, то выходим, возвращая ноль
	//иначе   
	else {
		T temp_data = head->data; //сохраняем данные элемента
		Node < T >* temp = head; //резервируем верхнюю "тарелку", чтобы потом почистить
		head = head->pNext; //переписываем её
		delete temp; //чистим
		Size--; //уменьшаем размер стека
		return temp_data;
	}
}

template<typename T>
bool Stack<T>::empty()
{
	if (Size) return false; //если size == 0, то пустой
	return true; //иначе нет
}

template<typename T>
T Stack<T>::peek(int index)
{
	if (index < 0) return T();

	Node<T>* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->pNext;
	}
	return temp->data;

}

template<typename T>
void Stack<T>::print()
{
	for (int i = 0; i < size(); i++)
	{
		cout << peek(i) << " ";
	}
}



