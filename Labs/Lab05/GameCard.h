#ifndef GAMECARD_H
#define GAMECARD_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include <iomanip>

namespace oop1 {
    // Object Interface 
    class Object {
        public: 
        virtual std::string toString() const = 0; // Pure virtual method 
        friend std::ostream& operator<<(std::ostream& os, const Object& obj) {
            os << obj.toString(); 
            return os;
        }
        virtual ~Object() = default; // Virtual destructor 
    }; 

    // Card Abstract Class 
    class Card : public Object {
        private: 
        std::string id;
        unsigned int value; 

        protected: 
        void name(const std::string& newName) { id = newName; }
        void cost(unsigned int newCost) { value = newCost; }

        public: 
        Card() : id(""), value(0) {} // Default constructor
        virtual ~Card() = default; // Virtual destructor
        Card(const Card& other) = default; // Copy constructor 
        Card& operator=(const Card& other) = default; // Assignment operator 

        std::string name() const { return id; }
        unsigned int cost() const { return value; }

        virtual void ability() = 0; // Pure virtual method 

        std::string toString() const override {
            std::ostringstream oss; 
            oss << id << " (" << value << ")"; 
            return oss.str(); 
        }
    }; 

    // Creature Abstract Class 
    class Creature : public Card {
        private: 
        unsigned int aspects[5]; 
        
        protected: 
        void attack(unsigned int atk) { aspects[0] = atk; }
        void defense(unsigned int def) { aspects[1] = def; }
        void mana(unsigned int m) { aspects [2] = m; }
        void life(unsigned int l) { aspects[3] = l; }
        void damage(unsigned int dmg) {
            if (dmg <= aspects[3]) {
                aspects[4] = dmg; 
            }
        }

        public:
        Creature() { std::fill(std::begin(aspects), std::end(aspects), 0); } // Default Constructor 
        virtual ~Creature() = default; // Virtual destuctor
        Creature(const Creature& other) = default; // Copy constructor 
        Creature& operator=(const Creature& other) = default; // Assignment operator 

        unsigned int attack() const { return aspects[0]; }
        unsigned int defense() const { return aspects[1]; }
        unsigned int mana() const { return aspects[2]; }
        unsigned int life() const { return aspects[3]; }
        unsigned int damage() const { return aspects[4]; }

        std::string toString() const override {
            std::ostringstream oss;
            oss << name() << "(" << cost() << ")" $LP:" " << (aspects[3] - aspect[4]) 
                << "$ [M:" << aspects[2] << "\\nATK:" << aspects[0] << "/DEF:" << 
            aspects[1] << "]"; 
            return oss.str(); 
        }
    }; 

    // Spell Abstract Class
    class Spell : public Card {
        private: 
        Creature* sources[2]; 
        unsigned int lengths[2]; 

        protected: 
        Creature* user() const { return sources[0]; }
        Creature* target() const { return sources[1]; }
        void uses(unsigned int u) {
            if (u <= lenghts[0]) {
                lengths[1] = u; 
            }
        }
        void duration(unsigned int d) { lengths[0] = d; }

        public: 
        Spell() {
            sources[0] = nullptr; 
            sources[1] = nullptr; 
            lengths[0] = lengths[1] = 0; 
        } // Default constructor 
        virtual ~Spell() = default; // Virtual destructor 
        Spell(const Spell& other) = default; // Copy constructor 
        Spell& operator=(const Spell& other) = default; // Assignment operator 

        virtual void user(Creature* u) { sources[0] = u; }
        virtual void target(Creature* t) { sources[1]= t; }

        unsigned int uses() const { return lenghts[1]; }
        usnigned int duration() const { return lenghts[0]; }
    }; 

    // Warrior Class
    class Warrior : public Creature {
        private: 
        unsigned int boost; 
        bool active; 

        public: 
        Warrior() : boost(0), active(false) {} // Defalt constructor 
        Warrior(const std::string& id, unsigned int cost, unsigned int atk, unsigned int def, 
        unsigned int m, unsigned int l, unsigned int b)
        : boost(b), active(false) {
            name(id); 
            this->cost(cost); 
            attack(atk);
            defense(def); 
            mana(m); 
            life(l); 
            damage(0); 
        }

        void ability() override {
            if (!active && damage() > 0) {
                attack(attack() + boost); 
                active = true; 
            } else if (damage() == 0 && active) {
                attack(attack() - boost); 
                active = false; 
            }
        }
    }; 

    // Restororation Class 
    class Restoration : public Spell {
        private: 
        unsigned int restore; 

        public: 
        Restoration() : restore(0) {} // Default constructor 
        Restoration(const std::string& id, unsigned int cost, unsigned int dur, usigned int r)
        : restore(r) {
            name(id);
            this -> cost(cost); 
            duration(dur); 
            uses(0); 
        }

        void user(Creature* u) override {
            sources[0] = u; 
            sources[1] = u;
        }

        void ability() override {
            if (sources[0] != nullptr && lengths[0] != lengths[1]) {
                sources[0]->damage() - restore; 
                lengths[1]++; 
                if (lengths[0] == lenghts[1]) {
                    sources[0] = nullptr; 
                    sources[1] = nullptr; 
                    lengths[1] = 0; 
                }
            }
        }
    }; 

} // namespace oop1
#endif // GAMECARD_H