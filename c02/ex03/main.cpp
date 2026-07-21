/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:59:51 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/21 17:12:21 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point const a(0.0f, 0.0f);
	Point const b(10.0f, 0.0f);
	Point const c(0.0f, 10.0f);

	Point const inside(2.0f, 2.0f);
	Point const outside(8.0f, 8.0f);
	Point const edge(5.0f, 0.0f);
	Point const vertex(0.0f, 0.0f);

	std::cout << std::boolalpha;

	std::cout << "Inside point: "
		<< bsp(a, b, c, inside) << std::endl;

	std::cout << "Outside point: "
		<< bsp(a, b, c, outside) << std::endl;

	std::cout << "Point on edge: "
		<< bsp(a, b, c, edge) << std::endl;

	std::cout << "Point on vertex: "
		<< bsp(a, b, c, vertex) << std::endl;

	return (0);
}