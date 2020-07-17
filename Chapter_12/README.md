# Chapter 12
## Object Oriented Programming: Polymorphism

### Exercise 12-1
Fill in the blanks in each of the following statements:
1. Polymorphism is implemented via **Virtual Functions** and **Dynamic Binding**.
1. Polymorphism helps eliminate **switch** logic.
1. If a class contains at least one pure virutal function, it's an **abstract** class.
1. Classes from which objects can be instantiated are called **concrete** classes.
1. Each class with virtual functions has a **vtable**.
1. Constructors cannot be declared **virtual**.
1. Dynamic binding with virtual functions occurs only off **pointers** and **references**.
1. Overridable functions are declared using keyword  **virtual**.
1. To call a function appropriately at execution time is known as **dynamic binding**.

### Exercise 12-2
State whether each of the following is *true* or *false*. If *false*, explain why.
1. Polymorphism enables "programming in the specific."
 <br><br>**False** Polymorphism enbles "programming in the *general*."<br><br>
1. With polymorphism, one function class can cause different actions to occur. **True**<br><br>
1. Polymorphism is implemented only via dynamic binding.
<br><br>**False** Polymorphism is also implemented via static binding, through operator and function overloading.<br><br>
1. Although we cannot intantiate objects of abstract base classes, we can declare pointers and references to objects of abstract base classes. **True** <br><br>
1. Classes without any <code>nullptr</code> vtable pointers are concrete classes. **True**

### Exercise 12-3
*Programming in the General*<br>
How is it that polymorphism enables you to program "in the general" rather than "in the specific"? Discuss the key advantages of programming "in the general." <br>

Polymorphism enables you to program "in the general" by using a single method identifier that results in different behaviors based on the types of arguments (static binding) or the types of objects (dynamic polymorphism). Dynamic polymorphism allows for many objects under the same class hierarchy to be referenced as a base class pointer. Since these objects share many of the same behaviors and characteristics, these objects can be interacted with under a single common interface, and maintain their own respective behaviors. This could come in handy when extending the program to another object type that has the same interface as another related object.

### Exercise 12-4
*Polymorphism vs. switch logic*<br>
Discuss the problems of programming with switch logic. Explain why polymorphism can be an effective alternative to using switch logic. <br>

When using switch logic, each new class addition must also be added to the switch statement. The same is true when deleting an object type. With many types, this could become a code maitenance and testing nightmare. With polymorphism, related objects can have the same interface, so it is much more easily extensible and take on a more simplified appearance. <br>

### Exercise 12-5
*Run time type information*<br>
What do you need to understand by runtime type information (RTTI)? How is RTTI useful?<br>
This enables a program to determine an object's type at execution time and act on that object accordingly.

### Exercise 12-7
*Dynamic Binding vs. Static Binding*<br>
Distinguish between static binding and dynamic binding. Explain the use of <code>virtual</code> functions and the *table* in dynamic binding.<br>

Static binding occurs during compile time (operator, function overloading, static casts) while dynamic binding occurs during runttime using the vtable. The vtable a pointer that point's to the object's class vtable. For pure virtual methods, these point to <code>nullptr</code>.

### Exercise 12-8
*Pure Virtual Function*<br>
How are <code>virtual</code> functions specified to be as pure? In what situations are pure virtual functions used?

<code> virtual returnType functionName(args) = 0;</code>

Pure virtual functions would be useful in a class which does make sense to have a method definition itself, but all child classes that should be instantiated should have this method definition. For example, a generic Employee class might not need a <code>calculateSalary()</code> definition, but all derived classes should override this definition.

### Exercise 12-9
*Applying virtual functions*<br>
Suppose you have an inheritance hierarchy with a base class Animal and two derived classes Bird and Snake. Based on the characteristics of animals in general and birds and snakes specifically, can you think of possible virtual and pure virtual functions to place in animal? Justify your answer.<br>

Some functions that can be made virtual would be <code>getNumberLegs()</code>, <code>breathe()</code>, and <code>drinkWater()</code>.

Some pure virutal functions that are specific to the animal and are too specific for class Animal are <code>move()</code>, <code>eat()</code>, <code>birth()</code>. These are too different for all types of class Animal, and wouldn't make sense to define until defining a more specific class.

### Exercise 12-10
*Abstract classes*<br>
What is an abstract class? What condition should be met for a class to be abstract?<br>

An abstract class is one that is not meant to be instantiated, but only derived by more specialized classes. In order for a class to be abstract, a class method must be pure virtual.

### Exercise 12-11
*Payroll-System Modification*
* Added a <code>dateOfBirth</code> member to the <code>Employee</code> class to include a birthday for each employee
* Tested adding $100 bonus to each salaried and base plus commission employee if the current month matches their respective birth month
    * Stored each employee in a vector of type <code>Employee *</code> and refernced each polymorphically

### Exercise 12-12
*Package Inheritance Hierarchy*
* Added virtual <code>toString</code> and <code>calculateCost</code> methods to add polymorphic behavior to the <code>Package</code> hierarchy
* Tested polymorphic behavior by verifying virtual functions in vector of <code>Package *</code> objects with expected outputs

### Exercise 12-13
*Polymorphic Banking Program Using Account Hierarchy*
* Added virtual <code>getBalance</code> to add polymorphic behavior to the <code>Account</code> hierarchy
* Tested polymorphic behavior by verifying virtual functions in vector of <code>Account *</code> objects with expected outputs
* Added polymorphice behavior for debit to extract fee for CheckingAccount class

### Exercise 12-14
*Payroll-System Modification*
* Added class for <code>PieceWorker</code> to represent an employee who gets paid a rate of pieces completed
* Added class for <code>HourlyWorker</code> to represent an employee that gets paid per hour
    * The hourly rate is 1.5 times the wage when the <code>HourlyWorker</code> works more than 40 hours in a week

### Exercise 12-15
*CarbonFootprint Abstract Class: Polymorphism*
* Created unrelated classes <code>Bicycle</code>, <code>Building</code>, and <code>Car</code> that derive from CarbonFootprint where each can calculate its carbon footprint
* The <code>Bicycle</code> class calculates its carbon footprint as a function of its production cost
* The <code>Building</code> class calculates its carbon footprint as a function of its square footage
* The <code>Car</code> class calculates its carbon footprint as a function of its mpg and miles driven

### Chapter Notes
* Be sure to use the base class name along with the scope resolution operator (::) when referencing base class methods that are overriden in the derived
class. Failure to do so will result in infinte recursion and was seen as a *Segmentation Fault* error.