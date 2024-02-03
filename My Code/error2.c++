#include<iostream>

using namespace std;

class SNU;
class Btech{
    string dept;
    public:
    Btech(){
        dept="CSE";
    }
        void student(SNU & obj);
};

class SNU{
    private:
        int reg_no;
    protected:
        int enroll_no;
    public:
        SNU(){
            reg_no= 22001208;
            enroll_no= 22112000;
        }
        friend void Btech::student(SNU & obj);
};

void Btech::student(SNU & obj){
    cout<<"Registration Number: "<<obj.reg_no<<endl;
    cout<<"Enrollment Number: "<<obj.enroll_no<<endl;
    cout<<"Department: "<<dept<<endl;
}

int main(){
    SNU collage;
    Btech stud;
    stud.student(collage);
    
}