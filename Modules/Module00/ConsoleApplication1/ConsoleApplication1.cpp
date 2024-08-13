#include <iostream>
#include <string>
#include "Phonebook.h"
#include <sstream>
using namespace std;


int main()
{
    Phonebook phonebook;

    while (true) {
        string command;
        getline(cin, command);
        istringstream iss(command);

        iss >> command;
        
        if (command == "ADD") {
            string name, number, nickname;
            iss >> name >> number >> nickname;
            phonebook.add(name, number, nickname);
        }
        else if (command == "SEARCH") {
            string value;
            iss >> value;

            if (value.empty()) {
                phonebook.show();
            }
            else if (value == "-b"){
                int index;
                iss >> index;
                phonebook.bookmark_add(index);
            }
            else {
                phonebook.detail_show(stoi(value));
            }
        }
        else if (command == "REMOVE") {
            string value;
            iss >> value;

            if (value == "-n") {
                string number;
                iss >> number;
                phonebook.remove(number);
            }
            else {
                phonebook.remove(stoi(value));
            }

        }
        else if (command == "BOOKMARK") {
            phonebook.bookmark_show();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "ERROR: There is no command like " << command << '\n';
        }
        
    }
}