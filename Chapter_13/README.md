# Chapter 13
## Stream Input/Output: A Deeper Look

## Self-Review Exercises

### Exercise 13-1
*(Fill in the Blanks) Answer each of the following:*
1. C++ provides both **formatted (high-level)** and **unformatted (low-level)** I/O capabilities.

1. Addresses are displayed in **hexadecimal** format by default.

1. The **<iostream>** header file declares basic services required for all stream-I/O operations.

1. Formatted and unformatted output and input capabilities are provided by **<ostream>** and **<istream>** respectively.

1. Function that returns the next character from an input stream but does not remove the character from the stream
is called **peak** function.

1. **gcount** reports the number of characters read by the last input operation.

1. Unformatted input/output is performed using the **read** and **write** member functions of istream and ostream, respectively.

1. Precision is a member function of **std::ostream**.

1. To test a stream's state-in conditions, we can use **overloaded** operators.

1. To synchronize the operaton of an <code>istream</code> and <code>ostream</code> we use **tie**.

1. The symbol for the stream insertion operator is **<<**.

1. To determine whether a stream operation has failed, we use the **bad** member function.

1. The symbol for the stream extraction operator is **>>**.

1. If the operation fails in an unrecoverable manner then the stream extraction sets the stream's **badbit** to true.

1. The **showpoint** stream manipulator causes floating point number to display with a decimal point.


### Exercise 13-2
*(True or False) State whether each of the following is true or false. If the answer is false, explain why.

1. Unformatted I/O transfers are fase, but process raw data that is difficult for people to use. **True**

1. Each insertion to clog would cause its output to be held in a buffer (that is, an area of memory) until the buffer is filled or until the buffer is flushed. **True**
1. In output operations, the bytes flow from a device (e.g.,  a keyboard, a disk drive, a network connection) to memory.
<br><br>**False, in output operations bytes flow from memory to a display device (e.g., a command terminal or monitor)**

1. The stream's overloaded bool cast operator eof returns true to indicate end-of-file, when an attempt is made to read past the end of a stream. **False, it returns false to indicate end-of-file**

1. The stream member function <code>rdstate</code> returns the current state of the stream. **True**

1. The cout stream normally is connected to the display screen. **True**

1. Member function <code>clear</code> restores a stream's state to "good", so that I/O may proceeed. **True**

1. The <code>cin</code> stream normally is connected to the display screen
<br><br>**False** this is normally connected to the keyboard.

1. The getline function removes the delimiter from teh stream but does not store it in the character array. **True**

1. Output to <code>cerr</code> is unbuffered and output to <code>clog</code> is buffered. **True**

1. Stream manipulator <code>showpoint</code> forces floating-point values to print with the default six digits of precision unless the precision value has been changed, in which case floating-point values print with the specified precision. **True**

1. When nonleading white space is encountered then the stream extraction is terminated. **True**

1. The <code>fixed</code> stream manipulator causes floating-point numbers to display in fixed-point notation with a specific number of digits to the right of the decimal point. **True**


### Exercise 13-3
*(Write a C++ Statement) For each of the following, write a single statement that performs the indicated task.*

1. Output the string "Enter the two numbers a and b: "
<br><br><code>
std::cout << "Enter the two numbers a and b: ";</code>

1. Use a stream manipulator that causes the exponent in scientific notation and the letters in hexadecimal values to print in capital letters.
<br><br><code>
std::uppercase;</code>

1. Output the address of the variable myString of type myChar *.
<br><br><code>
std::cout << static_cast<const void *>(myChar); </code>

1. Use a stream manipulator to ensure that floating-point values print in scientific notation.
<br><br><code>
std::cout << std::scientific; </code>

1. Output the address in variable integerPtr of type int *.
<br><br><code>
std::cout << static_cast<const void *>(integerPtr); </code>

1. Use a stream manipulator such that, when integer values are output, the integer base for octal and hexadecimal values is displayed.
<br><br><code>
std::cout << std::showbase; </code>

1. Output a floating-point number N with precision 3.
<br><br><code>
std::cout << std::precision(3) << N; </code>

1. Use a stream member function to set the fill character to '*' for printing in field widths larger than the values being output. Repeat this statement with a stream manipulator. <br><br><code> std::cout.fill('\*'); </code> <br> <code> std::cout << std::setfill('\*'); </code>

1. Output the characters 'O' and 'K' in one statement with ostream function put. <br><br><code> std::cout.put('O').put('K'); </code>

1. Get the value of the next character to input without extracting it from the stream.  <br><br><code> std::peek(); </code>

1. Input a single character into variable *charValue* of type *char*, using *istream* member function *get* in two different ways. <br><br> <code> charValue = std::cin.get(); </code> <br>
<code> std::cin.get(charValue, 1); </code> <br>

1. Input and discard the next six characters in the input stream.  <br><br><code> std::cin.ignore(6); </code>

1. Use *istream* member function *read* to input 30 characters into *char* array *address*.  <br><br><code> std::cin.read(address, 30); </code>

1. Read 10 characters into character array *name*. Stop reading characters if the '.' delimiter is encountered. Do not remove the delimiter from the input stream. Write another statement that performs this task and removes the delimiter from the input. <br><br> <code>
std::cin.get(name, 10, '.'); /* not removing delimiter \*/</code> <br> <code>
std::cin.getline(name, 10, '.'); /* removing delimiter */</code>

1. Use the *istream* member function *gcount* to determine the number of characters input into character array *line* by the last call to *istream* member function *read*, and output that number of characters, using *ostream* member function *write*. <br><br> <code> 
std::cout.write(line, std::cin.gcount()) </code>

1. Output *34.76*, 'A', 98.564424 and "Morning", separated by spaces. <br><br>
<code> std::cout << 34.76 << " A " << 98 << " " << 564424 << " Morning"; </code>

1. Display cout's current precision setting.  <br><br><code> std::cout << std::cout.precision() </code>

1. Input an integer value into *int* variable *months* and a floating-point value into *float* variable *percentageRate*.
<br><br><code>
std::cin >> months >> percentageRate;
</code>

1. Print 1.92, 1.925, and 1.9258 separated by tabs and with 3 digits of precision, using a stream manipulator.
<br><br><code>
std::cout << std::setprecision(3) << 1.92 << '\t' << 1.925 << '\t' << 1.9258;
</code>

1. Print integer 98 in decimal, octal, and hexadecimal separated by tabs, using a stream manipulator to change the base.
<br><br><code>
std::cout << std::dec << 98 << '\t' << std::octal << 98 << '\t' << std::hex 98;
</code>

1. Print integer 100 in decimal, octal, and hexadecimal separated by tabs, using a stream manipulator to change the base.
<br><br><code>
std::cout << std::setbase(10) << 100 << '\t' << std::setbase(8) << 100 << '\t' << std::setbase(16) << 100;
</code>

1. Print 1234 right justified in a 10-digit field.
<br><br><code> std::cout << std::setw(10) << 1234; </code>

1. Read characters into character array *line* until the character 'z' is encountered, up to a limit of 20 characters (including a terminating null character). Do not extract the delimiter character from the screen.
<br><br><code>
std::cin.get(line, 20, 'z'); </code>

1. Use integer variables *x* and *y* to specify the field width and precision used to display the *double* value 87.4573, and display the value.
<br><br><code>
std::cout << std::setw(x) << std::setprecision(y) << 87.4573; </code>

### Exercise 13-4
*(Find and Correct Code Errors) Identify the error in each of the following statements and explain how to correct it.*

1. Incorrect: <code>cout << "Value of x < y is: " << x < y. </code><br>
Corrected: <code>cout << "Value of x < y is: " << boolalpha << x < y. </code>

1. The following statement should print the integer value of 'A':
<br><br>Incorrect: <code>cout << 'A'; </code> <br>
Corrected: <code> cout << static_cast\<int>('A'); </code>

1. Incorrect: <code>cout << 'A string in quotes';</code><br>
Corrected: <code>cout << "\\'A string in quotes\\'"; </code>

### Exercise 13-5
*(Show Outputs) For each of the following, show the output.*

1. <code> cout << "123456789" << endl; <br>
cout.width(5); <br>
cout.fill('$'); <br>
cout << 12 << endl << 12; </code><br><br>
123456789<br>
$$$12<br>
12

1. <code> cout << setw(8) << setfill('#') << 999; </code> <br>
#####999

1. <code> cout << setw(6) << setprecision(2) << 657.347280; </code><br>
657.34

1. <code> cout << showbase << oct << 100 << endl << hex << 100; </code> <br>
0144
0x64

1. <code> cout << 10000 << endl << showpos << 10000; </code> <br>
10000
+10000

1. <code> cout <<  setw(10) << setprecision(2) << scientific << 244.93739; </code> <br>
2.45e+002

### Exercise 13-6
*Write C++ Statements*
* Practice extracting input and formatting output streams
* Remember to account for the <code>null</code> character when extracting from input
* Added an empty Ex_13_6.cpp source file for Makefile process

### Exercise 13-7
*Input Decimal, Octal, and Hexadecimal Values*<br>
* Developed <code>Number</code> class where the value of the object can be changed using an input stream
* Input stream can be in octal, decimal, or hexadecimal format for a positive 32-bit integer
* Can represent positive integers from 0 to 4294967295

### Exercise 13-8
*Type safety of C++ I/O operations* <br>
What do we mean when we say C++ uses type-safe I/O? What is the advantage of this feature?

Type-safe I/O means the each I/O Operation is executed in a manner sensitive to the data type. If there is no match for the data and the function
for handling the data type, the compiler generates an error. The advantage this offers is data cannot "sneak" through the system (can occur in C).

### Exercise 13-9
*Unformatted I/O* <br>
Which member functions are used to perform unformatted I/O: What is the use of <code>gcount</code> member function?

The <code>get</code> and <code>put</code> functions are used to perform unformatted I/O. The member function <code>gcount</code> returns the number of bytes read from the standard input.

### Exercise 13-10
*The advantage of high level I/O* <br>
What is the main advantage and disadvantage of using high-level (formatted) I/O?

Formatted I/O is slower, but more human readable.

### Exercise 13-11
*Length of a String*
* Developed simple function <code>printStringFromKeyboard</code> method which takes in a string of characters into a buffer, and prints the input in a field twice the width.

### Exercise 13-12
*Displaying numbers in different bases*<br>
* Developed <code>dec2octal</code> and <code>dec2hex</code> functions to convert decimal to hex and octal strings, respectively.
* Only functions for positive 32-bit integers from 0 to 4294967295.

### Exercise 13-13
*Dealing with extra input characters*
* Developed <code>uncorrectedInput</code> to not be abe to account for extra characters in steram and <code>correctedInput</code> to account for extra characters in the input stream
* The <code>std::cin.ignore()</code> ignores all input characters until the next <code>\n</code> is found
* The test methods were disabled since user input is not able to be automated with Jenkins

### Exercise 13-14
*Reading Phone Numbers with an Overloaded stream Extraction Operator*
* Developed steam extraction operator which checks input for correct <code>PhoneNumber</code> class

### Exercise 13-15
*Point Class*

## Chapter Notes:
* When using <code>std::fixed</code> to represent a <code>float</code> in fixed-number notation, the value is represented with as many
digits in the decimal part as specified by the *precision field*

