# Deitel
C++ How to Program 10th Edition Solutions to Exercises

This started out as personal goal for myself to learn C++ to increase my skillset and grow as a software developer. My goal was to complete every exercise in this book and throughly test each solution. To accomplish this, I had to venture into other realms of software engineering to which I had little experience or exposure. First was to learn how to effectively use Git, and stick to tried and true branching model. Next was to construct a build system to easily compile my C++ code. I chose Make (this may be changed to CMake in the future) since I have been meaning to learn the syntax and its functionality. Next was to actually test my code, and I researched standard industry practices, and google test seemed like the most complete solution. And finally to round out testing, I was tired of building and reading results manually, so I started using Jenkins to automate a testing pipeline. At first I just installed Jenkins as an application, but when I learned about Docker I decided to experiment and run the Jenkins instance in a container! The containerized Jenkins now creates new Docker instances to compile all the code and run the tests. What started out as a way to force myself to learn C++ morphed into a journey that included Make, Jenkins, Docker, and Google Test!

This journey has been a learning experience, and it's quite evident my code and programming practices has improved as the Chapters increase.

## Chapter 1
## Chapter 2
## Chapter 3
## Chapter 4
## Chapter 5
## Chapter 6
## Chapter 7
## Chapter 8
## Chapter 9
## Chapter 10 - Operator Overloading (class string)
* This chapter introduces the concept of overloading both unary and binary operators for user defined classes.
* From compiler warnings, I learned about concept of [The Rule of Three](https://en.cppreference.com/w/cpp/language/rule_of_three) when implementing user-defined constructors, destructors, and copy assignment operators.
* From these concepts, I am beginning to understand how both user-defined and built-in data types interact with one another.

## Chapter 11 Object-Oriented Programming: Inheritance
* This chapter introduces the *has-a* OOP concept of inheritance where a base class is the one from which a derived class inherits
* Derived classes represent more specialized groups of objects
* Focuses on public inheritance which stresses encapsulation

## Chapter 12 Object-Oriented Programming: Polymorphism
* This chapter introduces Polymorphism, the OOP concept where derived classes can be referred to from base class pointers
* Virtual functions and dynamic binding are responsible for polymorphism through use of a vtable

## Chapter 13
## Chapter 14
## Chapter 15
## Chapter 17
## Chapter 18
## Chapter 19
## Chapter 20
## Chapter 21
## Chapter 22