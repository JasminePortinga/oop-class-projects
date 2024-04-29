// HEader file (Employee.h)

// Fig. 9.28: Employee.h
// Employee class definition with a static data member to 
// track the number of Employee objects in memory
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
   Employee(const std::string&, const std::string&); // constructor

   Employee* empPtr{ nullptr };

   ~Employee() { 
       std::cout << "destroy the pointer empPtr" << std::endl;
       delete empPtr; 
   }

   std::string getFirstName() const; // return first name
   std::string getLastName() const; // return last name
   friend std::string getName(); // return last name

   // static member function                                          
   static unsigned int getCount(); // return # of objects instantiated
   static void display();
   void getPtr(Employee*);
   
private:
   std::string firstName;
   std::string lastName;   
   // static data
   static unsigned int count; // number of objects instantiated
   
};

#endif