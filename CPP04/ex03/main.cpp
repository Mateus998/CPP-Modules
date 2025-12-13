/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 18:50:19 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) {
MateriaSource spellBook;
spellBook.learnMateria(new Ice);
spellBook.learnMateria(new Cure);

Character mage("Harry Potter");
mage.equip(spellBook.createMateria("cure"));
mage.equip(spellBook.createMateria("cure"));
mage.equip(spellBook.createMateria("cure"));
mage.equip(spellBook.createMateria("cure"));

Character wizard("Malfoy");
wizard.equip(spellBook.createMateria("ice"));
wizard.equip(spellBook.createMateria("ice"));
wizard.equip(spellBook.createMateria("ice"));
wizard.equip(spellBook.createMateria("ice"));

mage.use(0,wizard); 
wizard.use(2, mage);

wizard = mage;
mage.unequip(2);
mage.unequip(3);

std::cout << "wizard name is " << wizard.getName() << std::endl;
wizard.use(3, mage);
return 0;
}
