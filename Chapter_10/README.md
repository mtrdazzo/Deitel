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

### Chapter Notes:
* In each class I was explicity defining a destructor and even an assignment operator (for practice) for each class. When building with gcc 9.2.0 I was getting the following warning:  <br />  <br />
<code> implicitly-declared is deprecated because {Class} has user-provided  definition </code> <br />  <br />
This is due to the standard which debuted in C++11 which states: </br><br/>
*The implicit definition of a copy constructor as defaulted is deprecated if the class has a user-declared copy assignment operator or a user-declared destructor. The implicit definition of a copy assignment operator as defaulted is deprecated if the class has a user-declared copy constructor or a user-declared destructor* <br/><br/>
The rationale behind this is the well-known Rule of Three which states: <br/><br/>
*If a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator, it almost certainly requires all three.* <br/><br/>
So, when defining a destrutor, copy constructor, or copy assignment operator, include all three.