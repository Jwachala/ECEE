#include <iostream>

struct Person {
    // informaaion of the person
    std::string name;
    int age;
    // An automatically assigned index of each person
    int id;
	
    // pointer to next person in list
    Person *next;
};

struct List {
    // first Person in hte list. nullptr indicates the list is empty
    Person *head;

    // current person in list. nullptr indicates 'past the end' position
    Person *current;

    // points to element before 'current.' Can be null if
    //'current' is the first element in the list, or if the list is empty
    Person *previous;
};

void ListInitialize(List *list) {
    list->head = nullptr;
    list->current = nullptr;
    list->previous = nullptr;
}

void ListNext(List *list) {
    if (list->current) {
        list->previous = list->current;
        list->current = list->current->next;
    }
}

void ListHead(List *list) {
    list->current = list->head;
    list->previous = nullptr;
}

// set the current position to the person with the given name
// if no person exists with that name, the current person is set to past-the-end
void ListFind(List *list, int usrId) {
    ListHead(list);
    while (list->current && list->current->id != usrId) {
        ListNext(list);
    }
}

// insert a person before the element at the current position in the list
// if the current position is past-the-end, the person is inserted at the
// end of the list. The new person is made the new current element of the list
void ListInsert(List *list, Person *person) {
    // set the 'next' pointer of the new element
    person->next = list->current;

    // set 'next' pointer of the previous element. Treat the special case
    // where the current element is the head of the list.
    if (list->current == list->head) {
        list->head = person;
    } else {
        list->previous->next = person;
    }
    // set the current element to the new person
    list->current = person;
}
// remove the current element in the list. if the current element is
// past-the-end, this call is ignored. the next element will be the element that
// appeared right after the removed element
void ListRemove(List *list) {
    // ignore if current element is past-the-end
    if (!list->current) {
        return;
    }
    // remove. consider special case where current element is head of the list
    if (list->current == list->head) {
        list->head = list->current->next;
    } else {
        list->previous->next = list->current->next;
    }
    // save pointer to the 'next' element
    Person *next = list->current->next;
    // free memory
    delete list->current;
    // update current element
    list->current = next;
}

void PrintPerson(Person *person) {
    std::cout << "ID: " << person->id << '\n';
    std::cout << "Name: " << person->name << '\n';
    std::cout << "Age: " << person->age << '\n';
}

int main() {
    List list;
	ListInitialize(&list);
    std::string menu = "\nMain Menu: \n1. Add a person \n2. Find a person "
                       " \n3. Remove a person \n4. Print the list "
                       "\n5. Exit\n\nSelect an option: ";
    bool running = true;
    int idNum = 1;
    while (running) {
        int option;
        std::cout << menu;
        std::cin >> option;
        switch (option) {
        case 1:{
            std::cout << "You selected \"Add a person\"\n";
            //Adds a new person
			Person *newPerp = new Person;
            std::cout << "Enter Person name: ";
            std::cin >> newPerp->name;
            std::cout << "Enter Person age: ";
			std::cin >> newPerp->age;
			newPerp -> id = idNum;										
			ListInsert(&list, newPerp);
            idNum ++;
			break;
        }            
        case 2:{
            std::cout << "You selected \"find a person\"\n";
            //Prompt user for the id to find the person
			std::cout << "Enter the person's ID #: ";
			int usrNum;
			std::cin >>  usrNum;
            ListFind(&list, usrNum);
            if(!list.current){
				std::cout << "Person not found! \n";
            }
			else {
			    PrintPerson(list.current);
            }
            ListHead(&list);
			break;
        }
        case 3:{
            std::cout << "You selected \"Remove a person\"\n";
            std::cout << "Enter the person's ID #: ";
            int usrNum;
			std::cin >>  usrNum;
            ListFind(&list, usrNum);
			if(!list.current){
				std::cout << "Person not found! \n";
            }
			else{
            	ListRemove(&list);
            }
            ListHead(&list);
            break;
        }
        case 4:{
            std::cout << "You selected \"Print the list\"\n";
            ListHead(&list); //Navigates to beginning of list
			while(list.current){ //Prints each person and prints a newline
				PrintPerson(list.current);
				ListNext(&list);
				std::cout << "\n";										
			}
			break;
        }
        case 5:{
            std::cout << "You selected \"Exit\"\n";
            return 0;
            break;
        }
        default:{
            std::cout << "Invalid! Try again\n";
            break;
        }
        }
    }
}
