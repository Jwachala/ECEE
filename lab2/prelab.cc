#include <iostream>
void Initialize(){}
void Finalize(){}
int main(){
Initialize();
	std::string menu = "Main Menu: \n1. Print the array \n2. Append element at the end \n3. Remove last element \n4. Insert one element\n5. Exit\n\nSelect an option: ";
	bool running = true;
	while(running){
		int option;
		std::cout << menu;
		std::cin >> option;
		switch(option){
			case 1: std::cout << "You selected \"Print the array\"\n";
				break;
			case 2: std::cout << "You selected \"Append element at the end\"\n";
				break;
			case 3: std::cout << "You selected \"Remove last element\"\n";
				break;
			case 4: std::cout << "You selected \"Insert one element\"\n";
				break;
			case 5: std::cout << "You selected \"Exit\"\n";
				Finalize();
				return 0;
				break;
			default: std::cout << "Invalid! Try again\n";
				break;
		}	
	}
}
