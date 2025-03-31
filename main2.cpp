#include <iostream>
#include <string>
using namespace std;


int main(){

    class ROT{
        private:
            int* health;
            string* name;
        public:
            //Copy Constructor
            //Copy Assignment Constructor ✔
            //Destructor ✔

            ROT(){ //Constructor
                health = new int;
                name = new string;
                *health = 0;
                *name = "none";
            }
            ROT(int health, string name){ //Constructor
                this->health = new int;
                this->name = new string;
                *this->health = health;
                *this->name = name;
            }

            ROT& operator=(const ROT& stamp){ //Copy Assignment Constructor
                name = new string;
                health = new int;
                *health = *(stamp.health);
                *name = *(stamp.name);
                return *this;
            }

            ~ROT(){ //Destructor
                delete health;
                delete name;
            }
            void Print(){
                cout << *name << ": " << *health << endl;
                return;
            }
    };

    ROT mainCharacter(15, "Jon4");

    mainCharacter.Print();
    while(true);
    

    return 0;
}