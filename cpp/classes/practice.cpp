#include <iostream>
#include <string>
using namespace std;

class Character{
    protected:
        string name;
    public:
        string getName(){
            return this->name;
        }
        void setName(string name){
            this->name = name;
        }
};

class Hero : public Character{
    protected:
        int hp;
        int level;
    
    public:
        int getHp(){
            return this->hp;
        }
        void setHp(int hp){
            this->hp = hp;
        }
        int getLevel(){
            return this->level;
        }
        void setLevel(int level){
            this->level = level;
        }
        void showDesc(){
            cout << "-----------------------------------" << endl;
            cout << "Name: " << getName() << endl;
            cout << "Health: " << getHp() << endl;
            cout << "Level: " << getLevel() << endl;
            cout << "-----------------------------------" << endl;
        }
        void inputInfo(int hp, int level, string name){
            setHp(hp);
            setLevel(level);
            setName(name);
        }
};

class Enemy : public Character{
    protected:
        int hp;
        int power;
    
    public:
        int getHp(){
            return this->hp;
        }
        void setHp(int hp){
            this->hp = hp;
        }
        int getPower(){
            return this->power;
        }
        void setPower(int power){
            this->power = power;
        }
        void attack(Hero *hero){
            cout << this->getName() << " attacked " << hero->getName() << endl;
            hero->setHp( hero->getHp() - this->getPower() );
            hero->showDesc();

        }
        void showDesc(){
            cout << "-----------------------------------" << endl;
            cout << "Name: " << getName() << endl;
            cout << "Health: " << getHp() << endl;
            cout << "Power: " << getPower() << endl;
            cout << "-----------------------------------" << endl;
        }
        void inputInfo(int hp, int power, string name){
            setHp(hp);
            setPower(power);
            setName(name);
        }
};

class Weapon{
    private:
        string name;
        int durability;
        int damage;
    public:
        Weapon(string name = "notFound", int durability = 0, int damage = 0){
            this->name = name;
            this->durability = durability;
            this->damage = damage;
        }

        string getName(){
            return this->name;
        }
        void setName(string name){
            this->name = name;
        }
        int getDurability(){
            return this->durability;
        }
        void setDurability(int durability){
            this->durability = durability;
        }
        int getDamage(){
            return this->damage;
        }
        void setDamage(int damage){
            this->damage = damage;
        }
        void doDamage(Enemy *enemy){
            durability--;
            enemy->setHp(enemy->getHp()-damage);
        }
        void showDesc(){
            cout << "Name: " << getName() << endl;
            cout << "Damage per hit: " << getDamage() << endl;
            cout << "Hits remaining: " << getDurability() << endl;
        }
};

class NPC : public Character{
    protected:
        string townName;
    public:
        string getTownName(){
            return this->townName;
        }
        void setTownName(string townName){
            this->townName = townName;
        }
        void greeting(){
            cout << "Hello my name is " << getName() << " of " << getTownName() << endl;
        }
};

class Player : public Hero{
    protected: 
        Weapon weapon;
    public:
        Weapon getWeapon(){
            return this->weapon;
        }
        void setWeapon(Weapon weapon){
            this->weapon = weapon;
        }
        void useWeapon(Enemy *enemy){
            cout << this->getName() << " attacked " << enemy->getName() << endl;
            weapon.doDamage(enemy);
            enemy->showDesc();
        }
        void showDesc(){
            cout << "-----------------------------------" << endl;
            cout << "Name: " << getName() << endl;
            cout << "Health: " << getHp() << endl;
            cout << "Level: " << getLevel() << endl;
            cout << "Weapon: " << endl;
            weapon.showDesc();
            cout << "-----------------------------------" << endl;
        }
        
};

class Pet: public Hero{
    protected: 
        int power;
        Player owner;

    public:
        Pet(string name, int hp, int level, int power, Player owner){
            this->setHp(hp);
            this->setName(name);
            this->setLevel(level);
            this->power = power;
            this->owner = owner;

        }
        int getPower(){
            return this->power;
        }
        void setPower(int power){
            this->power = power;
        }
        Player getOwner(){
            return this->owner;
        }
        void setOwner(Player owner){
            this->owner = owner;
        }
        void showDesc(){
            cout << "-----------------------------------" << endl;
            cout << getOwner().getName() << "'s pet" << endl;
            cout << "Name: " << getName() << endl;
            cout << "Health: " << getHp() << endl;
            cout << "Level: " << getLevel() << endl;
            cout << "Power: " << getPower() << endl;
            cout << "-----------------------------------" << endl;
        }
        void attack(Enemy *enemy){
            cout << this->getName() << " attacked " << enemy->getName() << endl;
            enemy->setHp( enemy->getHp() - this->getPower() );
            enemy->showDesc();
        }
};

int main(){
    NPC jeff;
    jeff.setName("Jeff");
    jeff.setTownName("Mordor");

    jeff.greeting();
    
    Player hero1;
    hero1.inputInfo(100, 20, "Mr JEFFREY");
    
    Weapon sword("Sword of doom", 20, 10);
    sword.setDamage(10);
    sword.setName("Sword of doom");
    sword.setDurability(20);

    hero1.setWeapon(sword);
    hero1.showDesc();

    Pet dog("Doggy", 30, 1, 5, hero1);
    dog.showDesc();

    Enemy slime;
    slime.inputInfo(30, 5, "Slimey");
    slime.showDesc();

    // attack test
    // cout << "slime hp: " << slime.getHp() << endl;
    // cout << "hero hp: " << hero1.getHp() << endl;

    slime.attack(&hero1);
    // cout << "slime hp: " << slime.getHp() << endl;
    // cout << "hero hp: " << hero1.getHp() << endl;

    hero1.useWeapon(&slime);
    // cout << "slime hp: " << slime.getHp() << endl;
    // cout << "hero hp: " << hero1.getHp() << endl;

    dog.attack(&slime);
    // cout << "slime hp: " << slime.getHp() << endl;
    // cout << "hero hp: " << hero1.getHp() << endl;
    return 0;
}