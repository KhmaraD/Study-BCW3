#include <iostream>
#include "Unit.h"

void Unit::ensureIsAlive() {
    if ( hitPoints == 0 ) {
       throw UnitIsDead();
   }
}

Unit::Unit(const std::string& name, int hp, int dmg) {
    this->damage = dmg;
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this->name = name;
}

Unit::~Unit() {}

int Unit::getDamage() const {
    return this->damage;
}

int Unit::getHitPoints() const {
    return this->hitPoints;
}

int Unit::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

const std::string& Unit::getName() const {
    return this->name;
}

void Unit::addHitPoints(int hp) {
    this->ensureIsAlive();
    
    this->hitPoints += hp;
    
    if ( this->hitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
    }
    
    std::cout << "The " << this->getName() << " was healed for " << hp << " hp!" << std::endl;
}

void Unit::takeDamage(int dmg) {
    this->ensureIsAlive();
    
    this->hitPoints -= dmg;
    
    if ( this->hitPoints <= 0 ) {
        this->hitPoints == 0;
        std::cout << "The " << this->getName() << " is dead!" << std::endl;
    }
}

void Unit::attack(Unit& enemy) {
    this->ensureIsAlive();
    
    std::cout << "The " << this->getName() << " attacked " << enemy.getName();
    std::cout << " and inflict " << this->getDamage() << " damage!" << std::endl;
    
    enemy.takeDamage(this->damage);
    
    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(*this);
    }
}

void Unit::counterAttack(Unit& enemy) {
    this->ensureIsAlive();
    
    enemy.takeDamage(this->damage/2);
    
    std::cout << "The " << this->getName() << " counter attacked " << enemy.getName();
    std::cout << " and inflicted " << this->getDamage()/2 << " damage!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    std::cout << "Name: " << unit.getName() << std::endl;
    std::cout << "Hit Points: " << unit.getHitPoints() << '/' << unit.getHitPointsLimit() << std::endl;
    std::cout << "Damage: " << unit.getDamage() << std::endl;
    
    return out;
}
