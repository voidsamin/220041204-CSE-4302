#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class BaseCharacter;

class CharacterActions {
    public:
        CharacterActions() {}
        virtual void attack(BaseCharacter* enemy) = 0;
        virtual int defend() = 0;
        virtual void useSpecialAbility() = 0;
        virtual void displayStats() const = 0;
        virtual ~CharacterActions() {}
};

class BaseCharacter : public CharacterActions {
    protected:
        string name;
        int health;
        int mana;

    public:
        BaseCharacter(string __name, int hp) : name(__name), health(hp), mana(0) {}

        virtual void setHealth(int hp) {
            health = hp;
        };
        virtual int getHealth() const {
            return health;
        };

        string getName() const {
            return name;
        }

        void attack(BaseCharacter* enemy) {}

        int defend() {}

        void useSpecialAbility() {}

        void displayStats() const {
            cout << "Name: " << name << endl;
            cout << "HP: " << health << endl;
            cout << "Mana: " << mana << endl;
        }

        bool isAlive() {
            if(health > 0)
                return true;
            else
                return false;
        }

        virtual void defeated() {
            cout << name << " defeated! Players lose!" << endl;
        }

        virtual ~BaseCharacter() {}
};

class Warrior : public BaseCharacter {
    protected:
        const static int attackPower;
        const static string specialAbility;
        const static int specialAbilityPower;

    public:
        Warrior() : BaseCharacter("Warrior", 100) {}
        ~Warrior() {};

        void setHealth(int hp) {
            health = hp;
        }

        int getHealth() const {
            return health;
        }

        void attack(BaseCharacter* enemy) {
            int temp = 0;

            cout << "Warrior attacks with power 25!" << endl;

            if(enemy->defend()) {
                enemy->setHealth(enemy->getHealth() - attackPower);
                temp += attackPower;
                mana += 50;
            }
            if(mana >= 100) {
                useSpecialAbility();
                temp += specialAbilityPower;
                enemy->setHealth(enemy->getHealth() - specialAbilityPower);
                mana = 0;
            }
            cout << "Boss takes " << temp << " damage! Health now: " << enemy->getHealth() << endl;
        }

        int defend() {
            int r = rand() % 5;

            if(!r)
                cout << "Warrior successfully defended attack. Health now: " << health << endl;

            return r;
        }

        void useSpecialAbility() {
            cout << "Warrior uses Berserk Rage with power 35!" << endl;
        }

        void displayStats() const {
            BaseCharacter::displayStats();
            cout << "Attack Power: " << attackPower << endl;
            cout << "Special Ability: " << specialAbility << endl;
            cout << "Special Ability Power: " << specialAbilityPower << endl;
        }
};
const int Warrior::attackPower = 25;
const string Warrior::specialAbility = "Berserk Rage";
const int Warrior::specialAbilityPower = 35;

class Mage : public BaseCharacter {
    protected:
        const static int attackPower;
        const static string specialAbility;
        const static int specialAbilityPower;

    public:
        Mage() : BaseCharacter("Mage", 120) {}
        ~Mage() {};

        void displayStats() const {
            BaseCharacter::displayStats();
            cout << "Attack Power: " << attackPower << endl;
            cout << "Special Ability: " << specialAbility << endl;
            cout << "Special Ability Power: " << specialAbilityPower << endl;
        }

        void setHealth(int hp) {
            health = hp;
        }

        int getHealth() const {
            return health;
        }

        void attack(BaseCharacter* enemy) {
            int temp = 0;

            cout << "Mage attacks with power 20!" << endl;

            if(enemy->defend()) {
                enemy->setHealth(enemy->getHealth() - attackPower);
                temp += attackPower;
                mana += 50;
            }
            if(mana >= 100) {
                useSpecialAbility();
                temp += specialAbilityPower;
                enemy->setHealth(enemy->getHealth() - specialAbilityPower);
                mana = 0;
            }
            cout << "Boss takes " << temp << " damage! Health now: " << enemy->getHealth() << endl;
        }

        int defend() {
            int r = rand() % 5;

            if(!r)
                cout << "Mage successfully defended attack. Health now: " << health << endl;

            return r;
        }

        void useSpecialAbility() {
            cout << "Mage uses Arcane Blast with power 30!" << endl;
        }
};
const int Mage::attackPower = 20;
const string Mage::specialAbility = "Arcane Blast";
const int Mage::specialAbilityPower = 30;

class Archer : public BaseCharacter {
    protected:
        const static int attackPower;
        const static string specialAbility;
        const static int specialAbilityPower;

    public:
        Archer() : BaseCharacter("Archer", 90) {}
        ~Archer() {};

        void displayStats() const {
            BaseCharacter::displayStats();
            cout << "Attack Power: " << attackPower << endl;
            cout << "Special Ability: " << specialAbility << endl;
            cout << "Special Ability Power: " << specialAbilityPower << endl;
        }

        void setHealth(int hp) {
            health = hp;
        }

        int getHealth() const {
            return health;
        }

        void attack(BaseCharacter* enemy) {
            int temp = 0;

            cout << "Archer attacks with power 20!" << endl;

            if(enemy->defend()) {
                enemy->setHealth(enemy->getHealth() - attackPower);
                temp += attackPower;
                mana += 50;
            }
            if(mana >= 100) {
                useSpecialAbility();
                temp += specialAbilityPower;
                enemy->setHealth(enemy->getHealth() - specialAbilityPower);
                mana = 0;
            }
            cout << "Boss takes " << temp << " damage! Health now: " << enemy->getHealth() << endl;
        }

        int defend() {
            int r = rand() % 5;

            if(!r)
                cout << "Archer successfully defended attack. Health now: " << health << endl;

            return r;
        }

        void useSpecialAbility() {
            cout << "Archer uses Fire Arrow with power 35!" << endl;
        }
};
const int Archer::attackPower = 20;
const string Archer::specialAbility = "Fire Arrow";
const int Archer::specialAbilityPower = 35;

class BossEnemy : public BaseCharacter{
    protected:
        const static int attackPower;

    public:
        BossEnemy() : BaseCharacter("Boss", 150) {}

        void setHealth(int hp) {
            health = hp;
        }

        int getHealth() const {
            return health;
        }

        void attack(BaseCharacter* enemy) {
            int temp = 0;
            cout << "Boss attacks with power 30!" << endl;

            if(enemy->defend()) {
                enemy->setHealth(enemy->getHealth() - attackPower);
                temp += attackPower;
                mana += 50;
            }

            cout << enemy->getName() << " takes " << temp << " damage! Health now: " << enemy->getHealth() << endl;
        }

        int defend() {
            int r = rand() % 5;

            if(!r)
                cout << "Boss successfully defended attack. Health now: " << health << endl;

            return r;
        }

        void defeated() {
            cout << "Boss defeated! Players win!" << endl;
        }

        void useSpecialAbility() {}

        void displayStats() const {
            cout << "Name: " << name << endl;
            cout << "HP: " << health << endl;
            cout << "Attack Power: " << attackPower << endl;
        }
};
const int BossEnemy::attackPower = 30;

class GameEngine {
    private:
        BaseCharacter* players[3];
        BaseCharacter* boss;

    public:
        GameEngine() {
            players[0] = new Warrior();
            players[1] = new Mage();
            players[2] = new Archer();
            boss = new BossEnemy();
        }

        void start() {
            while(true){
                players[0]->attack(boss);
                if(!boss->isAlive()){
                    boss->defeated();
                    break;
                }
                players[1]->attack(boss);
                if(!boss->isAlive()){
                    boss->defeated();
                    break;
                }
                players[2]->attack(boss);
                if(!boss->isAlive()){
                    boss->defeated();
                    break;
                }

                boss->attack(players[0]);
                if(!players[0]->isAlive()){
                    players[0]->defeated();
                    break;
                }
                boss->attack(players[1]);
                if(!players[1]->isAlive()){
                    players[1]->defeated();
                    break;
                }
                boss->attack(players[2]);
                if(!players[2]->isAlive()){
                    players[2]->defeated();
                    break;
                }
            }
        }

        ~GameEngine() {
            for(int i = 0; i < 3; i++)
                delete players[i];
            delete boss;
        }
};

int main() {
    GameEngine* game = new GameEngine();
    game->start();
    delete game;

    return 0;
}
