/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:19:47 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/13 12:31:25 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string replaceAll(
	const std::string& content,
	const std::string& s1,
	const std::string& s2)
{
	std::string result;
	std::size_t start = 0;
	std::size_t pos;

	while ((pos = content.find(s1, start)) != std::string::npos)
	{
		result += content.substr(start, pos - start);
		result += s2;
		start = pos + s1.length();
	}
	result += content.substr(start);

	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0]
				  << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream input(filename.c_str());
	if (!input.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return 1;
	}

	std::ostringstream buffer;
	buffer << input.rdbuf();
	input.close();

	std::string content = buffer.str();
	std::string result = replaceAll(content, s1, s2);

	std::string outputFilename = filename + ".replace";

	std::ofstream output(outputFilename.c_str());
	if (!output.is_open())
	{
		std::cerr << "Error: could not create output file." << std::endl;
		return 1;
	}

	output << result;
	output.close();

	return 0;
}