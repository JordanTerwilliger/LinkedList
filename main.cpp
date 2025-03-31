// "New" means new compared to previous level
#include <iostream>
using namespace std;

class SubstituteTeacher {
   public:
      SubstituteTeacher();
      ~SubstituteTeacher();
      SubstituteTeacher& operator=(const SubstituteTeacher& objToCopy);

      // New: grade pointer member in SubstituteTeacher
      void SetSubjectAndGrade(string setSubject, int setGrade) {
         *grade = setGrade;
         *subject = setSubject;
      }

      void Print();
   private:
      int* grade;
      string* subject;
};

SubstituteTeacher::SubstituteTeacher() {
   subject = new string;
   *subject = "none";
   grade = new int;
   *grade = 0;
}

SubstituteTeacher::~SubstituteTeacher() {
   delete grade;
   delete subject;
}

// New: assignment operator also copies grade member
SubstituteTeacher& SubstituteTeacher::operator=(const SubstituteTeacher& objToCopy) {
   if (this != &objToCopy) {
      delete subject;
      subject = new string;
      subject = (objToCopy.subject);

      delete grade;
      grade = new int;
      *grade = *(objToCopy.grade);
   }

   return *this;
}

// New: Print function
void SubstituteTeacher::Print() {
   cout << *grade << ": " << *subject << endl;
}

int main() {
   SubstituteTeacher msWong;
   SubstituteTeacher mrPark;
   SubstituteTeacher mrDorf;

   msWong.SetSubjectAndGrade("Science", 1);
   mrPark.SetSubjectAndGrade("Gym", 2);
   mrDorf.SetSubjectAndGrade("Music", 6);

   mrDorf = mrPark;
   mrPark = msWong;

   mrDorf.Print();
   mrPark.Print();

   return 0;
}