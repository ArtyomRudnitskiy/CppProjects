#pragma once
#include <iostream>
using namespace std;

template<typename T> //��������� 
class Stack
{
public:
	Stack(); //�����������
	~Stack(); //����������
	void push(T data); //�������� ����
	T pop(); //������� ��������� ����, ���������� �������� ��-�
	int size() { return Size; } //������� ������ �����
	bool empty(); //�������� �� �������
	T peek(int index); //�������� �� ����� (���������� �������� �� ������� � �����)
	void print();


private:

	template<typename T>
	class Node
	{
	public:

		// ���������� ���� � ��������� ������ ��� ������, ������ ��� Node - ���������� �����
		Node* pNext; //��������� �� ��������� ����
		T data; //������

		//����������� ���� �����, �� ��������� ������ = ������������ �� ��������� ���������� ���� ������ (��� ���� � int), � ��������� �� ��������� ���� = �������� ��������� (� �������)
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head; //������ � ����� ������� "�������"
	int Size; //������ �����, ����� �� ������������� ������ ��� ��� ��������, ��� ������� ��������
};

template<typename T>
Stack<T>::Stack() //����������� - ������� ������ ����� ����, ������� "�������" ��� - nullptr
{
	Size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack() //����������, �������� ����� pop, �.�. ������� ��������, ���� ������ �� ����� 0
{
	while (Size)
	{
		pop();
	}
}

template<typename T>
void Stack<T>::push(T data) //���������� ��-�� (������)
{
	//head ����� �� "=" - ��� ������ ������ (����� ���������� ������ ������ "��������"). ��� �������� ������ ������
	head = new Node<T>(data, head);  //����������, ��� �� ������ ����� ����, � ���������� � ������ ������, ��������� head, � ��������� ����� ���� �������
	Size++; //����������� ������ �����
}

template<typename T>
T Stack<T>::pop() //�������� �������� (����������)
{
	if (Size == 0) return T(); //���� ������� ������, �� �������, ��������� ����
	//�����   
	else {
		T temp_data = head->data; //��������� ������ ��������
		Node < T >* temp = head; //����������� ������� "�������", ����� ����� ���������
		head = head->pNext; //������������ �
		delete temp; //������
		Size--; //��������� ������ �����
		return temp_data;
	}
}

template<typename T>
bool Stack<T>::empty()
{
	if (Size) return false; //���� size == 0, �� ������
	return true; //����� ���
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



