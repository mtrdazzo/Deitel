# Chapter 22
## Bits, Characters, C Strings and structs

## Self-Review Exercises

### Exercise 22-1
*Fill in the blanks in each of the following:*

1. The **bitwise AND (&)** operator sets a bit in the result to one if the corresponding bits in each of the operands are one.
1. The **bitwise exclusive OR (^)** operator sets a bit in the result to one if exactly one of the corresponding bits in the two operands-but not both-is true.
1. Keyword **struct** introduces a structure declaration.
1. The **bitwise complement (~)** operator produces the one's complement of the operand.
1. The **bitwise inclusive OR (|)** operator set a bit in the result to one if the corresponding bit in either (or both) operand(s) is one.
1. The bitwise AND operator & is often used to **mask** bits. (i.e., to select certain bits from a bit string while zeroing others).
1. The **left-shift operator (<<)** and **right-shift operator (>>)** operators are used to shift the bits of a value to the left of to the right, respectively.

### Exercise 22-2
*Write a single statement or a set of statements to accomplish each of the following:*
1. Define a structure called <code>Item</code> containing <code>int</code> variable <code>itemNumber</code>, <code>double</code> variable <code>itemPrice</code>, and <code>char</code> array <code>itemName</code> (whose value may be as long as 30 characters).
```cpp
    struct Item {
        int itemNumber;
        double itemPrice;
        char itemName[30];
    };
```
2. Define <code>ItemPtr</code> to be a synonym for the type <code>Item*</code>.
```cpp
    typedef Item* ItemPtr;
```
3. In separate statements, declare a variable <code>x</code> to be of type <code>Item</code>, declare array <code>x[5]</code> to be of type <code>Item</code> and declare variable <code>ptr</code> to be of type pointer to <code>Item</code>.
```cpp
    Item x;
    Item y[5];
    ItemPtr ptr; // declared in previous exercise
```
4. Read item number, item name, and item price from the keyboard into the members of variable x.
```cpp
        std::cin >> x.itemNumber >> x.itemPrice >> x.itemName;
```
5. Assign the member values of variable <code>x</code> to element two of array <code>y</code>.
```cpp
    y[2] = x;
```
6. Assign the address of array <code>y</code> to the pointer variable <code>ptr</code>.
```cpp
    ptr = y;
```
7. Print the member values of element two of array <code>y</code>, using the variable <code>ptr</code> and the structure pointer operator to refer to the members.
```cpp
    std::cout << "Item Number: " << (ptr + 2)->itemNumber
        << "\nItem Name: " << (ptr + 2)->itemName
        << "\nItem Price: " << (ptr + 2)->itemPrice << std::endl;
```

### Exercise 22-3
*Write a single statement to accomplish each of the following. Assume that variables <code>c</code> (which stores a character), <code>x</code>, <code>y</code>, and <code>z</code> are of type <code>int</code>; variables <code>d</code>, <code>e</code>, and <code>f</code> are of type <code>double</code>; variable <code>ptr</code> is of type <code>char\*</code> and arrays <code>s1[100]</code> and <code>s2[100]</code> are of type <code>char</code>.*

1. Convert the character stored in <code>c</code> to an uppercase letter. Assign the result to variable <code>c</code>
```cpp
    c = toupper(c);
```
2. Determine if the value of variable <code>c</code> is a digit. Use the conditional operator as shown in Figs. 22.18-22.20 to print " is a " or " is not a " when the result is displayed.
```cpp
    std::cout << "c " << (isdigit(c) ? " is a " : " is not a ") << "digit" << std::endl;
```

3. Convert the string "1234567" to <code>long</code>, and print the value.

```cpp
    std::cout << atol("1234567") << std::endl;
```

4. Determine whether the value of variable <code>c</code> is a control character. Use the conditional operator to print  " is a " or " is not a " when the result is displayed.

```cpp
    std::cout << "c " << (iscntrl(c) ? " is a " : " is not a " ) << "control character" << std::endl;
```

5. Assign to <code>ptr</code> the location of the last occurence of <code>c</code> in <code>s1</code>.

```cpp
    ptr = strrchr(s1, c);
```

6. Convert the string "8.63582" to <code>double</code>, and print the value.

```cpp
    std::cout << atof("8.63582") << std::endl;
```

7. Determine whether the value of variable <code>c</code> is a letter. Use the conditional operator to print " is a " or " is not a " when the result is displayed.

```cpp
    std::cout << "c" << (isalpha(c) ? " is a " : " is not a ") << "letter" << std::endl;
```

8. Assign to <code>ptr</code> the location of the first occurrence of <code>s2</code> in <code>s1</code>.

```cpp
    ptr = strstr(s1, s2);
```

9. Determine whether the value of variable <code>c</code> is a printing character. Use the conditional operator to print " is a " or " is not a " when the result is displayed.

```cpp
    std::cout << "c" << (isprint(c) ? " is a " : " is not a ") << "printing character" << std::endl;
```

10. Assign to <code>ptr</code> the location of the first occurrence in <code>s1</code> of any character from <code>s2</code>.

```cpp
    ptr = strpbrk(s1, s2);
```

11. Assign to <code>ptr</code> the location of the first occurence of <code>c</code> in <code>s1</code>.

```cpp
    ptr = strchr(s1, c);
```

12. Convert the string "-21" to <code>int</code>, and print the value.

```cpp
    std::cout << atoi("-21") << std::endl;
```

### Exercise 22-4
*(Structures)* How is C++ structure different from C structure?
* C++ structures behave just like classes, with inheritance, methods, constructors, destructors, whereas in C they are just simply a collection of data types.
* In C, you cannot directly initialize structure data members, but is allowed in C++.
* In C, we need to use <code>struct</code> to declare a struct (e.g., <code>struct Point</code> variable. In C++, <code>struct</code> is not necessary, you can declare a <code>Point</code> variable directly with the <code>struct</code> keyword.
* C structures cannot have static members
* C++ structures can have user-defined access types (encapsulation)

### Exercise 22-6
*(Type aliases)* What are the different ways of creating type aliases?
1. Using keyword <code>typedef</code>
1. Using preprocessor <code>#define</code>