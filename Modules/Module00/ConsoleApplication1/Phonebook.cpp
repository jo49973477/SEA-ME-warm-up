#include <iostream>
#include <vector>
#include "Contact.h"
#include "Phonebook.h"
using namespace std;


Phonebook::Phonebook() {
}

Phonebook::~Phonebook() {

}

void Phonebook::add(string name, string number, string nickname) {
	Contact new_contact = {name, number, nickname, false};
	new_contact.bookmark = false;

	contacts.emplace_back(new_contact);
	cout << name << "is added to Phonebook!\n";
}


void Phonebook::show() {
	cout << "----------------------\n";
	for (int i = 0; i < contacts.size(); i++) {
		cout << i + 1 << ":  " << contacts[i].name << '\n';
	}
	cout << "----------------------\n";
}


int Phonebook::search(string number) {
	int index = -1;

	for (int i = 0; i < contacts.size(); i++) {
		if (contacts[i].number == number) {
			index = i;
			break;
		}
	}

	return index;
}


void Phonebook::detail_show(int index){
	if (index < 1 or index > contacts.size()) {
		cout << "List out of the range! \n";
		return;
	}

	index--;

	cout << "----------------------\n";
	cout << "NAME:     " << contacts[index].name << '\n';
	cout << "NUMBER:   " << contacts[index].number << '\n';
	cout << "NICKNMAE: " << contacts[index].nickname << '\n';
	string bookmarked = contacts[index].bookmark ? "Y" : "N";
	cout << "BOOKMARK: " << bookmarked << '\n';
	cout << "----------------------\n";
}

void Phonebook::remove(int index) {
	if (index < 1 or index > contacts.size()) {
		cout << "List out of the range! \n";
		return;
	}

	cout << contacts[index - 1].name << " is removed!\n";
	contacts.erase(contacts.begin() + index - 1);
}


void Phonebook::remove(string number) {
	int idx = search(number);


	if (idx == -1) {
		cout << "There is no number " << number << '\n';
	}
	else {
		cout << contacts[idx].name << " is removed!\n";
		contacts.erase(contacts.begin() + idx);
	}
}


void Phonebook::bookmark_add(int index) {
	if (index < 1 or index > contacts.size()) {
		cout << "List out of the range! \n";
		return;
	}
	contacts[index-1].bookmark = true;
	cout << contacts[index-1].name << " is bookmarked!\n";
}


void Phonebook::bookmark_add(string number) {
	int idx = search(number);
	contacts[idx].bookmark = true;
	cout << contacts[idx].name << " is bookmarked!\n";
}


void Phonebook::bookmark_show() {
	cout << "----------------------\n";
	for (int i = 0; i < contacts.size(); i++) {
		if (contacts[i].bookmark) {
			cout << i + 1 << ":  " << contacts[i].name << '\n';
		}
	}
	cout << "----------------------\n";
}
