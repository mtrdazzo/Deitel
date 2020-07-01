# Chapter 10
## Operator Overloading; Class string

### Exercise 10-9 
#### HugeInteger Class
* This class represents an positive integer value of up to 40 digits.
* Objects can be instantied by using other HugeInteger's, strings, and integers.
* Overloaded arithmetic operators (+, -, *, /) enable this class to be used as if it were an integer with other HugeIntegers, strings, and integers.
* Added a class method to output the integer to a string.

***Known Limitations***:
  * Can only be used with positive integers
  * Integer overflow or underflow is not represented


### Exercise 10-10
#### **Enhanced Quadratic Class**
* This class constructs class to represent a quadratic equation in the form ax^2 + bx + c. 
* Contains overloaded operators for addition (+) and subtraction (-) between Quadratic objects.
* Objects can be output to a stream using the << operator.
* Added a method to outputting the representative quadratic function string for testing purposes.