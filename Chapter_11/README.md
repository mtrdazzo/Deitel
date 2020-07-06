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