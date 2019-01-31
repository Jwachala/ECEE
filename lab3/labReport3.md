# 2160 Lab 3

Patrick Taylor and James Wachala

Section Number: 1

January 31st, 2019

## 1:

```terminal
(gdb) break PrintPerson
Breakpoint 1 at 0x400a8a: file person.cc, line 7.
(gdb) run
Starting program: /Users/Student/ptaylor/embedded-design/unit2/person

Breakpoint 1, PrintPerson (p=0x7fffffffe300) at person.cc:7
7               std::cout << p->name << " is " << p->age << " years old.\n";
(gdb) print p
$1 = (Person *) 0x7fffffffe300
(gdb) print *p
$2 = {name = "John", age = 10}
(gdb) print p->name
$3 = "John"
(gdb) print p->age
$4 = 10
(gdb)
```

Each line of `print 'variable' ` prints the type of each variable.
- p is of type person and a pointer. It prints the type of p and the memory address it points to.
- *p prints the information that p points to which is the Person John, Age 10.
- p->name prints the membertype name of data structure Person (p) which is tge string John.
- p->age prints the membertype age of data structure Person (p) which is the int 10.

## 2

See Submission for q2.cc.

## 3

All behave as intended

## A

```terminal
Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: ben
Enter Person age: 4

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit
```

## B

```terminal
Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: ben
Enter Person age: 4

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: dave
Enter Person age: 2

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 2
You selected "find a person"
Enter the person's ID #: 2
ID: 2
Name: dave
Age: 2

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 5
You selected "Exit"
```

## C

```terminal

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: dave
Enter Person age: 3

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 3
You selected "Remove a person"
Enter the person's ID #: 1

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 3
You selected "Remove a person"
Enter the person's ID #: 1
Person not found!

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 5
You selected "Exit"
```

## D

```terminal
Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: dave
Enter Person age: 3

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 3
You selected "Remove a person"
Enter the person's ID #: 1

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 3
You selected "Remove a person"
Enter the person's ID #: 1
Person not found!

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 5
You selected "Exit"

c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160 Embedded Design\ECEE\lab3>cd "c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160
Embedded Design\ECEE\lab3\" && g++ q2.cc -o q2 -std=c++11 && "c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160 Embedded Design\ECEE\lab3\"q2

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: dave
Enter Person age: 3

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: g
Enter Person age: 3

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 4
You selected "Print the list"
ID: 2
Name: g
Age: 3

ID: 1
Name: dave
Age: 3


Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 5
You selected "Exit"
```

## E

```terminal
Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 5
You selected "Exit"
```

## 4

GDB!!!

## 5

GDB Crash

## Extra Credit