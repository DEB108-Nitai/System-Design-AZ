#include<iostream>
using std::string ;
// class is user defined data type 
// class is a blue print of what we want to create 

class Employee{
  // attributes  

  private: 
   string Name ;
   string Company ;
   int Age ; 

   // Methods / Function
public:
   void IntroduceYourSelf(){
    std::cout<<"Name : "<<Name<<std::endl;
    std::cout<<"Company : "<<Company<<std::endl;
    std::cout<<"Age: "<<Age<<std::endl;
   }

   // Setters and Getters 
       void setName(string name){
        Name=name;
      }
       string getname(){
        return Name;
    }
        void setCompany(string company){
            Company=company;
        }
        string getCompany(){
            return Company;
        }
        void setAge(int age){
            if(age>=18){    
            Age=age;
        }
    }
        int getAge(){
            return Age;
        }

   // constructor is a special function which is automatically called when an object is created
   // constructor is used to initialize the attributes of the class
   // constructor has the same name as the class and it does not have a return type
   // As soon as our own constructor is created the default constructor is destroyed
    Employee(string name , string company , int age){
        Name = name ;
        Company = company ;
        Age = age ;
    }
};


int main(){
  
    Employee employee1 = Employee("Debranjan" , "Google" , 20);
    //employee1.Name="Debranjan";
   // employee1.Company="Google";
   // employee1.Age=20;
    employee1.IntroduceYourSelf();
    Employee employee2 = Employee("Tejas" , "Microsoft" , 21);
   employee2.setAge(25);
   employee2.IntroduceYourSelf();

    return 0 ;