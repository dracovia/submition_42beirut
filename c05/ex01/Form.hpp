/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 17:00:16 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/08 12:40:37 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Form 
{
    private:
        const std::string _name;
        bool _is_signed ;
        const int _grade;
    public:
        Form();
        Form(std::string name, int grade);
        Form(const Form& other );
        ~Form();
        
        
        
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
        const std::string& getName() const;
        int getGrade() const;
        bool getSign() const;
};

std::ostream& operator<<(std::ostream& out, const Form& bureaucrat);

#endif