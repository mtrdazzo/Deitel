# Chapter 14
## File Processing

### Exercise 14-1
*(Fill in the blanks)*
1. Permanent retention of data can be ahieved by using **files**.
1. The <code>istream</code> member function **read** inputs a fixed number of bytes from the specified stream to an area in memory beginning at a specified address.
1. **Random access** is used for instant access to a file.
1. The <code>ostream</code> member function **write** outputs a fixed number of bytes, beginning at a specific location in memory, to the specified location.
1. Member functions **seekg** and **seekp** OF <code>ifstream</code> and <code>ofstream</code> set the file-position pointer to a specific location in an input or output stream, respectively.

### Exercise 14-2
*(True of False)*
1. When a file is opened, an object is created, and a stream is associated with the objects.
**True**
1. Files can be structured to meet the application's requirements. **True**
1. A program must call function <code>close</code> explicitly to close a file associated with an <code>ifstream</code>, <code>ofstream</code>, or <code>fstream</code> object.
**False, these files will be closed with the object goes out of scope**
1. To ensure that a program reads quoted text from a stream, including any white space characters in the quoted text, and discards the double quote delimiters we can use the header <code>iomanip</code>. **True**
1. <code>reinterpet_case</code> is *not* a compiler dependent and *will not*P cause programs to behave differently on different platforms.
**False, it is compiler dependent**
1. Data in sequential files always is updated without overwriting nearby data.
**False, sequential records are not of uniform length. Changing a record requires changing the entire file**
1. Data can be inserted into a random-access file without destroying other data in the file.
**True**
1. Member functions <code>tellg</code> and <code>tellp</code> are provided to return the current locations of the "get" and "put" pointers, respectively.
**True**

### Exercise 14-3
**Assume that each of the following statements applies to the same program.**
1. Write a statement that opens file <code>oldEmployee.dat</code> for input; use an <code>ifstream</code> object called <code>inOldEmployee</code>.
<br><br><code>std::ifstream inOldEmployee{"oldEmployee.dat", std::ios::in}</code><br><br>
1. Write a statement that opens file <code>transaction.dat</code> for input; use an <code>ifstream</code> object called <code>inTrans</code>
<br><br><code>std::ifstream inTrans{"transaction.dat", std::ios::in}</code><br><br>
1. Write a statement that opens a file <code>newemployee.dat</code> for output (and creation); use <code>ofstream</code> object <code>outNewEmployee</code>
<br><br><code>std::ofstream outNewEmployee{"newemployee.dat", std::ios:out}</code><br><br>
1. Write a statement that reads a record from the file <code>oldemployee.dat</code>. The record consists of integer <code>employeeNum</code>, string name (containing spaces) and floating-point <code>salary</code>. Use <code>ifstream</code> object <code>inOldEmployee</code>.
<br><br><code>inOldEmployee >> employeeNum >> std::quoted(name) >> salary; </code><br><br>
1. Write a statement that reads a record from the file transaction.dat. The record consists of integer <code>empNum</code> and floating-point <code>bonus</code>. Use <code>ifstream</code> object <code>inTrans</code>.
<br><br><code>inTrans >> empNum >> bonus;</code><br><br>
1. Write a statement that writes a record to the file <code>newemployee.dat</code>. The record consists of integer <code>employeeNum</code>, string <code>name</code>, and floating-point <code>salary</code>. Use <code>ofstream</code> object <code>outNewEmployee</code>.
<br><br><code> outNewEmployee << employeeNum << 
" " << name << " " <<>> salary;</code><br><br>

### Exercise 14-4
*Find the error(s) and show how to correct it (them) in each of the following:*
1. File *payables.dat* referred to by <code>ofstream</code> object <code>outPayable</code> has not been opened.
<br><br><code>outPayable << account << company << amount << endl;</code><br><br>
**The file payables.dat has not been opened before the attempt to output data to the stream**<br><br>
1. The following statement should read a record from the file *payables.dat*. The <code>ifstream</code> object <code>inPayable</code> refers to this file, and <code>ifstream</code> object <code>inReceivable</code> refers to the file *receivables.dat*
<br><br><code>inReceivable >> account >> company >> amount;</code>
<br><br>**Shoule use inPayable indentifier to read records from payables.dat**<br><br>
1. The file *tools.dat* should be opened to add data to the file without discarding the current data.
<br><br><code>ofstream outTools{"tools.dat", ios:out}</code><br><br>
**Open the file with <code>(ios::ate)</code> or for appending <code>(ios::app)</code>**

### Exercise 14-5
*(Fill in the Blanks)*
1. The string member function **length** gets the length of a string.
1. The standard stream objects declared by header <code>iostream</code> are <code>cin</code>, <code>cout</code>, <code>clog</code>, and <code>cerr</code>.
