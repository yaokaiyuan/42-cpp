#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat high("TopG", 1);
        AForm* rrf;
        AForm* scf;
        AForm* ppf;
        AForm* unknown;

        std::cout << "\n=== Testing RobotomyRequestForm Creation ===" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        high.signForm(*rrf);
        high.executeForm(*rrf);
        delete rrf;

        std::cout << "\n=== Testing ShrubberyCreationForm Creation ===" << std::endl;
        scf = someRandomIntern.makeForm("shrubbery creation", "home");
        high.signForm(*scf);
        high.executeForm(*scf);
        delete scf;

        std::cout << "\n=== Testing PresidentialPardonForm Creation ===" << std::endl;
        ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        high.signForm(*ppf);
        high.executeForm(*ppf);
        delete ppf;

        std::cout << "\n=== Testing Unknown Form Creation ===" << std::endl;
        try {
            unknown = someRandomIntern.makeForm("unknown form", "target");
            delete unknown;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
