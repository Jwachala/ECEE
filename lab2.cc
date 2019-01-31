#include <iostream>
#include <typeinfo>
double *v;
int count = 0;
int size = 2;
bool hasRun = false;
int debug = 1;

void Initialize() { // COMPLETE
    bool hasRun = true;
    v = new double[size];
}
void Finalize() { // COMPLETE
    delete[] v;
}
void Grow() {
    // creates new pointer to point to the larger array
    size *= 2;
    double *nv = new double[size];
    // std::cout << "created nv \n";
    // copies old values into new array
    for (int i = 0; i < size / 2; i++) {
        nv[i] = v[i];
        // std::cout << "cp\n";
    }
    // makes v point to new array
    delete[] v;
    v = nv;
    std::cout << "Vector grown\nPrevious capacity: " << size / 2
              << " elements\nNew capacity: " << size << " elements\n";
}
void AddElement() { // COMPLETE
    if (count < size) {
        double usrNum;
        std::cout << "Enter the new element: ";
        std::cin >> usrNum;
        std::cout << '\n';
        v[count] = usrNum;
        count++;
    } else {
        Grow();
        AddElement();
    }
}
void PrintVector() { // COMPLETE
    for (int i = 0; i < count; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

void Shrink() { // COMPLETE
    // creates new pointer to point to the smaller array
    std::cout << "Vector Utilization below " << ((count / 1.0) / size) * 100
              << "\%. Deleting half of the vector (only empty space).";
    size /= 2;
    double *nv = new double[size];
    // std::cout << "created nv \n";
    // copies old values into new array
    for (int i = 0; i < size / 2; i++) {
        nv[i] = v[i];
        // std::cout << "cp\n";
    }
    // makes v point to new array
    delete[] v;
    v = nv;
    std::cout << "Vector shrunk\nPrevious capacity: " << size * 2
              << " elements\nNew capacity: " << size << " elements\n";
}

void RemoveElement() { // COMPLETE
    if (debug == 1) {
        std::cout << "Count: " << count;
        std::cout << "\nSize: " << size << '\n';
        // std::cout << "Size:" << size;
    }
    if (count == 0) {
        std::cout << "Error: No values in the Array." << '\n';
        std::cout << "Returning to Main Menu..."
                  << "\n\n";
    }

    else {
        count--;
    }
    if (debug == 1) {
        std::cout << "Count: " << count;
        std::cout << "\nSize: " << size << '\n';
        // std::cout << "Size:" << size;
    }
    if ((count / 1.0) / size <= 0.3) // Shrink command
        if (count != 0)
            Shrink();
}

void InsertElement() { // NOT COMPLETE
    int index;
    double usrNum;
    if (debug == 1) {
        std::cout << "Count: " << count;
        std::cout << "\nSize: " << size << '\n';
        // std::cout << "Size:" << size;
    }
    std::cout << "Enter the index of the new element: ";
    std::cin >> index;
    if (index > count) {
        std::cout << "Na fam, u wrong \n";
        InsertElement();
    } else {
        std::cout << "Enter the new element: ";
        std::cin >> usrNum;
    
    if (count == size) {
        Grow();
    }
    for (int i = count - 1; i >= index; i--) {
        v[i + 1] = v[i];
    }
    v[index] = usrNum;
    count++;
    }
}

int main() {
    if (hasRun == false) {
        Initialize();
    }
    std::string menu = "Main Menu: \n1. Print the array \n2. Append element at "
                       "the end \n3. Remove last element \n4. Insert one "
                       "element\n5. Exit\n\nSelect an option: ";
    bool running = true;
    while (running) {
        int option;
        std::cout << menu;
        std::cin >> option;
        /*if (typeid(option).name() != "int") {
            std::cout << "Invalid! Try again";
            option = 8;
        } */
        switch (option) {
        case 1:
            std::cout << "You selected \"Print the array\"\n";
            PrintVector();
            break;
        case 2:
            std::cout << "You selected \"Append element at the end\"\n";
            AddElement();
            break;
        case 3:
            std::cout << "You selected \"Remove last element\"\n";
            RemoveElement();
            break;
        case 4:
            std::cout << "You selected \"Insert one element\"\n";
            InsertElement();
            break;
        case 5:
            std::cout << "You selected \"Exit\"\n";
            Finalize();
            return 0;
            break;
        default:
            std::cout << "Invalid! Try again\n";
            break;
        }
    }
}
