#pragma once
#include <iostream>


using namespace std;

template <class T>
class clsDblLinkedList
{

protected:

	int _Size = 0;

public:

	class Node {

	public:

		T Value = 0;
		Node* next;
		Node* prevs;
	};

	Node* head = NULL;

	void InsertAtBeginning(T Value) {

		Node* newNode = new Node();
		newNode->Value = Value;
		newNode->next = head;
		newNode->prevs = NULL;

		if (head != NULL) {

			head->prevs = newNode;
		}

		head = newNode;
		_Size++;
	}

	void PrintList() {

		Node* Current = head;

		while (Current != NULL) {

			cout << Current->Value << " ";
			Current = Current->next;
		}

		cout << "\n";


	}

	Node* Find(T value) {

		Node* Current = head;

		while (Current != NULL)
		{
			if (Current->Value == value)
				return Current;

			Current = Current->next;
		}

		return NULL;
	}

	void InsertAfter(Node* Current, T value) {

		Node* newNode = new Node();
		newNode->Value = value;
		newNode->next = Current->next;
		newNode->prevs = Current;

		if (Current->next != NULL) {

			Current->next->prevs = newNode;
		}

		Current->next = newNode;

		_Size++;
	}

	void InsertAtEnd(T value) {

		Node* newNode = new Node();
		newNode->Value = value;
		newNode->next = NULL;

		if (head == NULL) {

			newNode->prevs = NULL;
			head = newNode;
		}
		else {

			Node* current = head;

			while (current->next != NULL) {

				current = current->next;
			}

			current->next = newNode;
			newNode->prevs = current;
		}

		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete) {

		if (head == NULL || NodeToDelete == NULL) {
			return;
		}

		if (head == NodeToDelete) {

			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL) {

			NodeToDelete->next->prevs = NodeToDelete->prevs;
		}

		delete NodeToDelete;

		_Size--;
	}

	void DeleteFirstNode() {

		if (head == NULL) {

			return;
		}

		Node* temp = head;
		head = head->next;
		if (head != NULL) {

			head->prevs = NULL;
		}

		delete temp;

		_Size--;
	}

	void DeleteLastNode() {

		if (head == NULL) {
			return;
		}

		if (head->next == NULL) {

			delete head;
			head = NULL;
			return;
		}

		Node* current = head;

		while (current->next->next != NULL) {

			current = current->next;
		}

		_Size--;
	}

	int Size() {

		return _Size;
	}

	bool IsEmpty() {

		return (_Size == 0 ? true : false);
	}

	void Clear() {

		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse() {

		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prevs;
			current->prevs = current->next;
			current->next = temp;
			current = current->prevs;

		}

		if (temp != nullptr) {

			head = temp->prevs;
		}
	}

	Node* GetNode(int Index) {

		int Counter = 0;

		if (Index > _Size - 1 || Index < 0)
			return NULL;

		Node* Current = head;

		while (Current != NULL && (Current->next != NULL)) {

			if (Counter == Index)
				break;

			Current = Current->next;
			Counter++;
		}

		return Current;
	}

	T GetItem(int Index) {

		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return NULL;
		else

			return ItemNode->Value;
	}

	bool UpdateItem(int Index, T NewValue) {

		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL) {

			ItemNode->Value = NewValue;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int Index, T value) {

		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL) {

			InsertAfter(ItemNode, value);
			return true;
		}
		else {

			return false;
		}

	}


};