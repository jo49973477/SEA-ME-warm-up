#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string ud_convert(string ud, string str) {
	if (ud == "up") {
		for (int i = 0; i < str.length(); i++) {
			str[i] = toupper(str[i]);
			}
		return str;
	}
	else if (ud == "down") {
		for (int i = 0; i < str.length(); i++) {
			str[i] = tolower(str[i]);
		}
		return str;
	}
	else {
		return "ERROR";
	}
}

void command_conduct(string command, string ud, string str) {
	if (command == "./convert") {
		cout << ud_convert(ud, str);
	}
	else {
		cout << "There is no command <" << command << ">.";
	}
}

int main()
{
	string content, command, ud, str;
	int com_ud, ud_str;
	getline(cin, content);
	com_ud = content.find(' ', 0);
	ud_str = content.find(' ', com_ud + 1);
	command = content.substr(0, com_ud);
	ud = content.substr(com_ud + 1, ud_str - com_ud - 1);
	str = content.substr(ud_str + 1);
	command_conduct(command, ud, str);

	return 0;
}