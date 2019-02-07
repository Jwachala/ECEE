# 2160 Lab 3

Patrick Taylor and James Wachala

Section Number: 1

January 31st, 2019

## 1

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

Each line of `print 'variable'` prints the type of each variable.

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

```terminal
c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160 Embedded Design\ECEE\lab3>gdb
GNU gdb (GDB) 7.8.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
---Type <return> to continue, or q <return> to quit---
Type "apropos word" to search for commands related to "word".
(gdb) file q2
Reading symbols from q2...done.
(gdb) break q2.cc:188
Breakpoint 1 at 0x401a8e: file q2.cc, line 188.
(gdb) run
Starting program: c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160 Embedded Design\ECEE\lab3\q2.exe
[New Thread 21288.0x25f8]
[New Thread 21288.0x3cac]

Main Menu:
1. Add a person
2. Find a person
3. Remove a person
4. Print the list
5. Exit

Select an option: 1
You selected "Add a person"
Enter Person name: Jeff
Enter Person age: 23

Breakpoint 1, main () at q2.cc:188
188         int test = 0;
(gdb) print list
$1 = {head = 0x853e80, current = 0x853e80, previous = 0x0}
(gdb) print list.head
$2 = (Person *) 0x853e80
(gdb) print list.head->next
$3 = (Person *) 0x0
(gdb)
```

The command `print list` is giving the memory addresses of the list's at that point. `print list.head` give the memory address of the head of the list. `print list.head->next` gives the memory address of the next item of the list, because the first person becomes the head of the list (as was written when ListInsert was written in class on Wednesday, the 30th). As there is no person after the list, there is no next person (0x0).

## 5

```terminal
c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160 Embedded Design\ECEE\lab3>g++ q
2.cc -o q2 -g -std=c++11

c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160 Embedded Design\ECEE\lab3>gdb
GNU gdb (GDB) 7.8.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
---Type <return> to continue, or q <return> to quit---
Type "apropos word" to search for commands related to "word".
(gdb) file q2
Reading symbols from q2...done.
(gdb) run
Starting program: c:\Users\Patrick\OneDrive - Northeastern University\School\EECE 2160 Embedded Desi
gn\ECEE\lab3\q2.exe
[New Thread 16940.0x3bf4]
[New Thread 16940.0x2ad8]

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

Program received signal SIGSEGV, Segmentation fault.
0x00000000004015a4 in ListHead (list=0x0) at q2.cc:40
40          list->current = list->head;
(gdb) backtrace
#0  0x00000000004015a4 in ListHead (list=0x0) at q2.cc:40
#1  0x00000000004019fc in main () at q2.cc:151
(gdb)
```

We see in the original break is from a nullptr being passed to ListHead, we just don't know where, from the segmentation fault. Then, with backtrace, we can see that the call is from line 151, where the actual error occurs.
