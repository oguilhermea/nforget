#include <iostream>
#include <fstream>
#include <string>

void store_pass(std::string);

int main() {
    std::string password;
    int option;
    std::cout << "nforget\n1:Store\n2:Read\n3:Exit\n";
    do {
	std::cout << "Option: ";
	std::cin >> option;
	if(option == 1) {
	    std::cout << "Your password: ";
	    std::cin >> password;
	    store_pass(password);
	    std::cout << "Password saved on file <Pass>\n";
	}
    } while(option != 3);
}

void store_pass(std::string password) {
    std::ofstream file;
    file.open("Pass", std::ios::app);
    file << password << std::endl;
    file.close();
}
