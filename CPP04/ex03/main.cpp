/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/15 11:29:35 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) {
std::cout << "MY TESTS\n" << std::endl;
 
MateriaSource spellBook;
spellBook.learnMateria(new Ice);
spellBook.learnMateria(new Cure);

Character wiz1("Harry");
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("ice"));

Character wiz2("Draco");
wiz2.equip(spellBook.createMateria("ice"));
wiz2.equip(spellBook.createMateria("ice"));
wiz2.equip(spellBook.createMateria("ice"));

wiz1.use(0,wiz2); 
wiz2.use(2, wiz1);
wiz2.use(3, wiz1);

wiz2 = wiz1;
wiz1.unequip(2);
wiz1.unequip(3);

std::cout << "wiz2 name is " << wiz2.getName() << std::endl;
wiz2.use(3, wiz1);

wiz1.unequip(0);
wiz1.unequip(1);

wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));

wiz1.unequip(0);
wiz1.unequip(1);
wiz1.unequip(2);
wiz1.unequip(3);

wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));
wiz1.equip(spellBook.createMateria("cure"));

wiz1.unequip(0);
wiz1.unequip(1);
wiz1.unequip(2);
wiz1.unequip(3);

std::cout << "\nSUBJECT TESTS\n" << std::endl;

MateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);

ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);

delete bob;
delete me;
delete src;
return 0;
}
