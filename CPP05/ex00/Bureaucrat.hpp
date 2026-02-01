#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
    Bureaucrat(void);

    class GradeTooHighException : public std::exception{
        public:
        const char *what() const throw(){
            return "Grade too high";
        }
    };
    class GradeTooLowException : public std::exception{
        public:
        const char *what() const throw(){
            return "Grade too low";
        }
    };

public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat(void);

    Bureaucrat& operator=(const Bureaucrat& b);
    std::string getName(void) const;
    int getGrade(void) const;
    void increaseGrade(void);
    void decreaseGrade(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
