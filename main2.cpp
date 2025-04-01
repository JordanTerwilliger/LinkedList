#include <iostream>
#include <string>
using namespace std;


int main(){

    class ROT{
        private:
            int* health; //Pointers since Dynamic Memory Management requires pointers.
            string* name;
        public:
            //Copy Constructor ✔
            //Copy Assignment Constructor ✔
            //Destructor ✔

            ROT(){ //Null Constructor
                health = new int;
                name = new string;
                *health = 0;
                *name = "none";
            }
            ROT(int health, const string& name){ //Default Constructor
                this->health = new int;
                this->name = new string;
                *this->health = health;
                *this->name = name;
            }

            ROT(const ROT& stamp) {  // Copy Constructor
                name = new string(*stamp.name);
                health = new int(*stamp.health);
            }

            ROT& operator=(const ROT& stamp){ //Copy Assignment Operator
                if (this != &stamp){
                    delete name; 
                    delete health;
                    name = new string(*stamp.name);
                    health = new int(*stamp.health);
                }
                return *this;
            }

            ~ROT(){ //Destructor
                delete health;
                delete name;
            }
            void Print(){
                cout << getName() << ": " << getHealth() << endl;
                return;
            }

            string getName(){
                return *name;
            }
            void setName(string name){
                *this->name = name;
            }
            int getHealth(){
                return *health;
            }
            void setHealth(int health){
                *this->health = health;
            }
    };

    ROT mainCharacter(15, "Jon4");

    mainCharacter.Print();
    
    ROT a(mainCharacter);
    a.Print();
    a.setName("Heath");
    a.setHealth(4);
    a.Print();
    a = mainCharacter;
    a.Print();
    return 0;
}