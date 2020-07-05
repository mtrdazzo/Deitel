# Chapter 10
## Operator Overloading; Class string

### Exercise 10-6
#### Dynamic Memory Allocation
* This exercise shows simple allocation and deallocation of memory on the heap and stack.
* Shows the slight difference between pointers and arrays which at first glance operate the same way:
  * The increment/decrement operators can be used on a pointer, but an array identifier is const and cannot be used
  * The sizeof operator which shows the true size of an array, whereas it only shows the size of the pointer itself


### Exercise 10-7
#### DoubleScriptedArray class
* Represents a 2D array
* Contains equality (=) and inequality (!=) binary operators to compare with other DoubleScriptedArray objects
* Contains set/get accessor operators (*m*, *n*) complete with bounds checking


### Exercise 10-8
#### MotorVehicle class
* Represents a vehicle object containing information about the make, year, color, and fuel type of a vehicle
* Contains equality (=) and inequality (!=) binary operators to compare with other MotorVehicle objects
* Contains setters and getters for vehicle attributes
* Contains a binary greather than operator to compare two MotorVehicle object's years
* Contains an output stream operator to output vehicle information


### Exercise 10-9 
#### HugeInteger Class
* Represents a positive integer value of up to 40 digits.
* Can be instantied using HugeIntegers, strings, and integers.
* Overloaded arithmetic operators (+, -, *, /) enable this class to be used as if it were an integer with other HugeIntegers, strings, and integers.
* Includes a <code>str()</code> method to output the integer to a string.

*Known Limitations*:
  * Can only be used with **positive** integers
  * Integer overflow or underflow is not represented


### Exercise 10-10
#### Enhanced Quadratic Class
* Represents a quadratic equation in the form *ax<sup>2</sup> + bx + c*
* Contains overloaded addition (+) and subtraction (-) binary operators for <code>Quadratic</code> operands.
* an be output to a stream using the <code><<</code> in the form of its quadratic equation.
* Includes a <code>str()</code> method to output the representative quadratic function as a string.


### Exercise 10-11
#### Polynomial Class
* Represents a polynomial of up to 40 positive variables
* Instantiate a Polynomial object with no coefficients or a <code>POLYNOMIAL_ARRAY</code> which is of type <code>std::array<int, 40></code>
* Contains overloaded arithmetic operators for addition (+), subtraction (-), and multiplication (*)
* Contains overloaded operators for assignment (=), addition assignment (+=), subtraction assignment (-=), and multiplication assignment (-=)
* Contains an equality operator (==) (added for testing purposes)

*Known Limitations*:
  * Can only be used with **positive** variables (0-39)
  * Overflow or underflow is ignored

### Exercise 10-12
#### DollarAmount Class
* Represents a monetary value using an integer to store the number of cents
* Overloaded arithmetic operators (+, -, *, /) enable this class to be used as if it were an integer with other DollarAmount objects and integers.
* Contains equality (=) and inequality (!=) binary operators to compare with other DollarAmount objects
* Includes a <code>toString()</code> method to output the DollarAmount to a string in the form: 4.80 for $4.80

### Exercise 10-13
#### Enhanced DollarAmount Class
* Contains additonal overloaded methods to enable <code>DollarAmount</code> and <code>int</code> classes to be used commutatively using addition, subtraction, division, and multiplication operators (+, -, *, /).

### Chapter Notes:
* In each class I was explicity defining a destructor and even an assignment operator (for practice) for each class. When building with gcc 9.2.0 I was getting the following warning:  <br />  <br />
<code> implicitly-declared is deprecated because {Class} has user-provided  definition </code> <br />  <br />
This is due to the standard which debuted in C++11 which states: </br><br/>
*The implicit definition of a copy constructor as defaulted is deprecated if the class has a user-declared copy assignment operator or a user-declared destructor. The implicit definition of a copy assignment operator as defaulted is deprecated if the class has a user-declared copy constructor or a user-declared destructor* <br/><br/>
The rationale behind this is the well-known Rule of Three which states: <br/><br/>
*If a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator, it almost certainly requires all three.* <br/><br/>
So, when defining a destrutor, copy constructor, or copy assignment operator, include all three.