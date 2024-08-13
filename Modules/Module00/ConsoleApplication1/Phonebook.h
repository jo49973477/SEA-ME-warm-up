#pragma once
#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#include <iostream>
#include <vector>
#include "Contact.h"
using namespace std;

class Phonebook
{
	vector<Contact> contacts;

public:
	Phonebook();
	~Phonebook();
	void add(string name, string number, string nickname);
	void show();
	int search(string number);
	void detail_show(int index);
	void remove(int index);
	void remove(string number);
	void bookmark_add(int index);
	void bookmark_add(string number);
	void bookmark_show();
};

#endif
