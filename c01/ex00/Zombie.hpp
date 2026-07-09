/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 21:08:52 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/09 21:21:59 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string _name ;
        Zombie (void);
    public:
        void announce( void );
        const std::string &getName(void) const;
        Zombie (const std::string  &name);
};

#endif