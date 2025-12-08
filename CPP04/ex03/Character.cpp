#include "Character.hpp"

Character::Character(void){
    _name = "default";
}
Character::Character(std::string& name){
    _name = name;
}
Character::Character(Character& c){
    *this = c;
}
Character::~Character(){}
Character& Character::operator=(const Character& c){
    if(this != &c){
        _name = c._name;
        for(int i = 0; i < sizeof(_inventory); i++){
            _inventory[i] = c._inventory[i];
        }
    }
    return *this;
}
std::string const & Character::getName() const{
    return _name;
}
void Character::equip(AMateria* m){
    //criar variavel auxiliar que conta slots do inventario
}
void unequip(int idx){

}
void use(int idx, ICharacter& target){

}