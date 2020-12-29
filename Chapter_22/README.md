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