/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 11:25:05 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 16:55:02 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "===== VALID BUREAUCRAT =====" << std::endl;

    try
    {
        Bureaucrat a("Alice", 42);

        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << "After increment: " << a << std::endl;

        a.decrementGrade();
        std::cout << "After decrement: " << a << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "===== GRADE TOO HIGH =====" << std::endl;

    try
    {
        Bureaucrat b("Bob", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "===== GRADE TOO LOW =====" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 151);
        std::cout << c << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "===== INCREMENT LIMIT =====" << std::endl;

    try
    {
        Bureaucrat d("David", 1);

        std::cout << d << std::endl;
        d.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "===== DECREMENT LIMIT =====" << std::endl;

    try
    {
        Bureaucrat e("Eve", 150);

        std::cout << e << std::endl;
        e.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}