#include<iostream>
using std::string ;
// class is user defined data type 
// class is a blue print of what we want to create 

class AbstractEmployee{
    virtual void AskForPromotion()=0; // pure virtual function
};

class Employee : public AbstractEmployee{
  // attributes  

private: 
   string Company ;
   int Age ; 
protected:
  string Name ;
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
    // Abstractor is a class which has at least one pure virtual function
    void AskForPromotion(){
        if(Age>30){
            std::cout<<Name<<" got promoted!"<<std::endl;
        }
        else{
            std::cout<<Name<<" sorry no promotion for you!"<<std::endl;
        }
    }

    virtual void work(){
        std::cout<<Name<<" is working..."<<std::endl;
    }   

};

class Developer :  public Employee{
    private:
        string FavProgrammingLanguage;
    public:
        Developer(string name, string company, int age, string favProgrammingLanguage) : Employee(name, company, age){
            FavProgrammingLanguage = favProgrammingLanguage;
        }
        void ShowInfo(){
            Employee::IntroduceYourSelf();
            std::cout<<"Fav Programming Language: "<<FavProgrammingLanguage<<std::endl;
        }
        void FixBug(){
            std::cout<<Name<<" fixed bug using "<<FavProgrammingLanguage<<std::endl;
        }
        void work(){
            std::cout<<Name<<" is writing "<<FavProgrammingLanguage<<" code..."<<std::endl;
        }
};

class Teacher : public Employee{
    private: 
        string Subject;
    public:
        Teacher(string name, string company, int age, string subject) : Employee(name, company, age){
            Subject = subject;
        }
        void ShowInfo(){
            Employee::IntroduceYourSelf();
            std::cout<<"Subject: "<<Subject<<std::endl;
        }
        void PrepareLesson(){
            std::cout<<Name<<" is preparing "<<Subject<<" lesson..."<<std::endl;
        }
         void work(){
            std::cout<<Name<<" is teaching "<<Subject<<"..."<<std::endl;
        }
};

int main(){
  
    Employee employee1 = Employee("Debranjan" , "Google" , 20);
    //employee1.Name="Debranjan";
   // employee1.Company="Google";
   // employee1.Age=20;
    employee1.IntroduceYourSelf();
    Employee employee2 = Employee("Tejas" , "Microsoft" , 21);
   employee2.setAge(34);
   employee2.IntroduceYourSelf();
   employee2.AskForPromotion();

    Developer d = Developer("Debranjan" , "Google" , 20 , "C++");
    d.ShowInfo();
    d.FixBug();
    d.AskForPromotion();

    Teacher t= Teacher("Tejas" , "IIT KGP" , 21 , "Math");
    t.ShowInfo();
    t.AskForPromotion();
    t.PrepareLesson();

    Employee* e1 = &d; // Upcasting
    Employee* e2 = &t; // Upcasting

    e1->work(); // Calls Developer's work() function
    e2->work(); // Calls Teacher's work() function
    
    return 0 ;