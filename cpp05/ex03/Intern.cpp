/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:52:55 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/05/29 20:52:58 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
    _formCreators["shrubbery creation"] = &Intern::createShrubberyForm;
    _formCreators["robotomy request"] = &Intern::createRobotomyForm;
    _formCreators["presidential pardon"] = &Intern::createPresidentialForm;
}

Intern::Intern(const Intern& other) : _formCreators(other._formCreators) {}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        _formCreators = other._formCreators;
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string lowercaseName = formName;
    for (size_t i = 0; i < lowercaseName.length(); ++i) {
        lowercaseName[i] = std::tolower(lowercaseName[i]);
    }

    std::map<std::string, FormCreator>::const_iterator it = _formCreators.find(lowercaseName);
    if (it == _formCreators.end()) {
        throw FormNotFoundException();
    }

    AForm* form = (this->*(it->second))(target);
    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}
