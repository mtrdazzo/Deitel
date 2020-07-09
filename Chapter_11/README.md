# Chapter 11
## Object Oriented Programming: Inheritance

### Exercise 11-1
Fill in the blanks in each of the following statements:
1. **Inheritence** enables new classes to absorb the data and behaviors of existing classes and embellish these classes with new capabilities. <br><br>
1. A base class's **public** and **protected** members can be accessed in the base-class definition, in derived-class definitions and in friends of the base class and derived classes. <br><br>
1. **Class hierarchies**  are formed due to inheritance relationships between classes.<br><br>
1. **Private** members of a base class are *not* accessible directly from that class's derived classes.<br><br>
1. With **single** inheritance, a class is derived from one base class.<br><br>
1. A base class's **public** members are accessible within that base call and anywhere that the program has a handle to an object of that class or one of its derived classes.<br><br>
1. A base class's **private** members are accessible only within the base class or from its friends.<br><br>
1. When deriving a class, the base class may be declared as either **public**, **protected**, or **private**.<br><br>
1. When an object of a derived class in instantiated, the base class's **constructor** is called implicitly or explicitly to do any necessary initialization of the base-class data members in the derived-class object.<br><br>
1. Declaring base-class data members as **private** allows you to change the base-class implementation without having to change derived class implementations.<br><br>
1. When an object of a derived class is created, then first the constructors for the members of the **base class** execute, and then the base class **constructor** body executes.<br><br>

### Exercise 11-2
State whether each of the following is *true* or *false*. If *false*, explain why.
1. Software reuse reduces program development time and cost. **True** <br><br>
1. A direct base class is the one from which a derived class explicitly inherits. **True** <br><br>
1. A base class's public members are accessible only within the base class or from its friends. <br><br>**False** private members are onlye accessible from within the base class and its friends.<br><br>
1. When deriving a class with **protected** inheritance, public and protected members of the base class become protected members of the derived class.  **True** <br><br>

### Exercise 11-3
Composition as an Alternative to Inheritance
* Rewrites class BasePlusCommissionEmployee and CommissionEmployee without inheritence to stress the importance of inheritance
* Inheritance offers much less code maintenance and is less error-prone than this "copy and paste" approach
* Copy and past may be easier at first, but when making a change to one class, I eventually had to do the same with the other class

### Exercise 11-4
is-a Relationship vs. has-a Relationship
Distinguish between an *is-a* relationship and a *has-a* relationship.
An *is-a* relationship represents inheritance where an object of a derived class is also an object of its base class. The *has-a* relationship represents composition where an object has certain characteristics.

### Exercise 11-5
Protected vs Private Base Classes
Some programmers prefer not to use <code>protected</code> access because they believe it breaks the encapsulation of the base class. Discuss the relative merits of using <code>protected</code> access vs. using <code>private</code> access in base classes.
* Using protected access would be more efficient code, since derived classes could access bbase class variables directly rather than using *getter* functions
    * However these optimizations could also be accomplished through compiler optimizations without breaking encapsulation
* Using private variables limits the amount the derived class depends on the base class implementation. With encapsulation, changing the base class would not result in needing to change subsequent derived classes.

### Exercise 11-6
Student Inheritance Hierarchy
* Created an inheritance hierarchy to show the relationship between Undergraduate and Graduate students
* <code>Student</code> is the base class for which all <code>UndergraduteStudent</code> and <code>GraduateStudent</code> derive from
* <code>Freshman</code>, <code>Sophomore</code>, <code>Junior</code>, and <code>Senior</code> derive from <code>UndergraduateStudent</code> and <code>MastersStudent</code> and <code>DoctorateStudent</code> derive from <code>GraduateStudent</code>

### Exercise 11-7
Richer Shape Hierarchy

### Exercise 11-9
Package Inheritance Hierarchy
* Added an <code>Address</code> class that contains members for name, street, city, state, and zip
* Base class <code>Package</code> that represents package information that contains sender address, recipient address, weight, and cost per ounce, and calculate cost
* Class <code>TwoDayPackage</code> derives from <code>Package</code> and adds a flat-fee member that is incorporated into calculating cost
* Class <code>OvernightPackage</code> derives from <code>Package</code> and adds an overnight fee per ounce incorporated into calculating cost
* All classes contain a <code>toString()</code> member function, and friend function so the string representation can be output to a stream

### Exercise 11-10
Account Inheritance Hierarchy
* Account base class represents a bank account with private member balance
    * Contains public methods for <code>credit</code> (deposit), <code>debit</code> (withdraw), and <code>getBalance</code>
    * If an amount is attempted to be debited that is larger than the amount "Debit amount exceeded account balance" is printed, and no amount is removed from the balance.
    * Cannot credit values less than or equal to 0.0
    * Cannot debit values less than or equal to 0.0
