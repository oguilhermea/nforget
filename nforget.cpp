#include <iostream>
#include <fstream>
#include <string>

void store_pass(std::string);
void read_pass();

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
	if(option == 2) {
	    std::cout << "Registered Password:\n";
	    std::cout << "-------------------\n";
	    read_pass();
	    std::cout << "-------------------\n";
	}
    } while(option != 3);
}

void store_pass(std::string password) {
    std::ofstream file;
    file.open("Pass", std::ios::app);
    if(file.is_open()) {
	file << password << std::endl;
	file.close();
    } else {
	std::cout << "Unable to open file\n";
    }
}

void read_pass() {
    std::ifstream file;
    std::string line;
    file.open("Pass");
    if(file.is_open()) {
	while(std::getline(file, line)) {
	    std::cout << line << "\n";
	}
	file.close();
    } else {
	std::cout << "Unable to open file\n";
    }
}
