# Chapter 10
## Operator Overloading; Class string

### Exercise 10-9 
#### HugeInteger Class
* HugeInteger class represents an positive integer value of up to 40 digits.
* Objects can be instantied using other HugeInteger's, strings, and integers.
* Overloaded arithmetic operators (+, -, *, /) enable this class to be used as if it were an integer with other HugeIntegers, strings, and integers.
* Added a <code>str()</code> class method to output the integer to a string.

*Known Limitations*:
  * Can only be used with **positive** integers
  * Integer overflow or underflow is not represented


### Exercise 10-10
#### **Enhanced Quadratic Class**
* Constructs a class to represent a quadratic equation in the form *ax<sup>2</sup> + bx + c*
* Contains overloaded addition (+) and subtraction (-) binary operators for <code>Quadratic</code> operands.
* Quadratic objects can be output to a stream using the <code><<</code> operator.
* Added a <code>str()</code> method to output the representative quadratic function as a string.

### Exercise 10-11
#### **Polynomial Class**
* Constructs a class to represent a polynomial of up to 40 orders
* Instantiate a Polynomial object with no coefficients or a <code>POLYNOMIAL_ARRAY</code> which is of type <code>std::array<int, 40></code>
* Contains overloaded arithmetic operators for addition (+), subtraction (-), and multiplication (*)
* Contains overloaded operators for assignment (=), addition assignment (+=), subtraction assignment (-=), and multiplication assignment (-=)
* Contains an equality operator (==) (added for testing purposes)