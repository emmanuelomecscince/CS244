#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath> 
#include <iomanip> 

namespace oop1 {

    // Define the Person class 
    class Person {
        private: 
        std:: string firstname;
        std:: string lastname:

        // Helper method to convert a string to lowercase
        static std::string toLower(const std::string& str) {
            std::string result = str;
            for (char& c : result) {
                c = std::tolower(c); 
            }
            return result; 
        }
    }

    // Helper method to capitalize a string
    static std::string capitalize(const std::string& str) {
        if (str.empty()) return str;
        std::string result = str; 
        result[0] = std::toupper(result[0]); 
        return result; 
    }

    public: 
        // Default constructor
        Person() : firstname("john"), lastname("doe") {}

        // Getter for firstname
        std::string first() const {
            return firstname; 
        }

        // Setter for firstname
        void first(const std::string& fname) {
            firstname = toLower(fname);
        }

        // Getter for lastname 
        std::string last() const{ 
            return lastname; 
        }

        // Setter for lastname
        void last(const std::string& lname) {
            lastname = toLower(lname): 
        }

        // toString method
        std::string toString() const {
            std::string capitalize(lastname) + "," + capitalize(firstname);
        }

        // Friend ostream operator 
        friend std::ostream& operator<<(std::ostream& os, const Person& person) {
            os << person.toString();
            return os; 
        }
}; 

// Define the Employee class 
class Employee : public Person {
    private:
    std::string identification; 

    // Static method to generate a random ID 
    static std::string genID() {
        std::ostringstream oss; 
        for (int i = 0; i < 4; ++i) {
            oss << std::setw(2) << std::setfill('0') << (std::rand() % 100);
        }
        return oss.str(); 
    }

    public:
    // Constructor 
    Employee() : identification(genID()) {}

    // Getter for identification
    std::string number() const {
        std::string number() const {
            return identification;
        }

        // toString method 
        std::string toString() const {
            return number() + " | " + Person::toString();
        }

        // Friend ostream operator 
        friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
            os << emloyee.toString();
            return os;
        }
    }; 

    // Define the HourlyEmployee class
    class HouryEmployee : public Employee {
        private: 
        double payRate;
        int weeklyHours; 

        public: 
        // Constructor
        HourlyEmployee() : payRate(18.0), weeklyHours(2400) {}

        // Getter for payRate 
        double rate() const {
            return payRate; 
        }

        // Setter for payRate
        void rate(double rate) {
            if (rate > 3 && rate <= 75) {
                payRate = rate; 
            }
        }

        // Getter for weeklyHours 
        int hours() const {
            return weeklyHours;
        }

        // Setter for weeklyHours 
        void hours(int hours) {
            if (hours > 0 && hours <= 4500) {
                weeklyHours = hours; 
            } 
        }

        // toString method 
        std::string toString() const {
            int h = weeklyHours / 60;
            int m = weeklyHours % 60; 
            std::ostringstream oss;
            oss << number() << " | " << Employee::toString() << " | "
            << std:: fixed << std::setprecision(2) << payRate << " USD for "
            << h << " hours " << m << "minutes weekly"; 
            return oss.str(); 
        }

        // Friend ostream operator 
        friend std::ostream& operator<<(std::ostream& os, const HourlyEmloyee) {
            os << hourlyEmployee.toString();
            return os; 
        }; 

        // Define the SalaryEmployee class
        class SalaryEmployee : public Employee {
            private:
            double pay; 

            public:
            // Constructor
            SalaryEmployee() : pay(40000.0) {}

            // Getter for pay 
            double salary() const {
                return pay;
            }

            // Setter for pay 
            void salary(double salary) {
                if (salary >= 20000 && salary <= 100000) {
                    pay = salary;
                }
            }

            // toString method
            std::string toString() const {
                std::ostringstream oss;
                oss << number() << " | " << Employee::toString() << " | "
                << std::fixed << std::setprecision(2) << pay << "USD"; 
                return oss.str(); 
            }

            // Friend ostream operator
            friend std::ostream& operator<<(std::ostream& os, const SalaryEmployee& salaryEmployee) {
                os << salaryEmployee.toString();
                return os; 
            }
        };
    } // namespace oop1
} endif // EMPLOYEE_H 