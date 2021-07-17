#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    private:
    public:
        string name;
        int age;
        int cur_id;

        virtual void getdata();
        virtual void putdata();
        void set_id(int id);            
};

void Person::getdata() {
    cin >> name >> age;
}

void Person::putdata() {
    cout << name << " " << age;
}

void Person::set_id(int id) {
    cur_id = id;
}

class Professor : public Person {
    private:
        int publications;
    public:
        void getdata();
        void putdata();
};

void Professor::getdata() {
    Person::getdata();
    cin >> publications;
}

void Professor::putdata() {
    Person::putdata();
    cout << " " << publications << " " << cur_id;
}

class Student : public Person {
    private:
        vector<int> marks;
     public:
        void getdata();
        void putdata();
};

void Student::getdata() {
    Person::getdata();
    for (int i=0; i < 6; i++) {
        int val;
        cin >> val;
        marks.push_back(val);
    } 
}

void Student::putdata() {
    Person::putdata();
    int sum = 0;
    for (int i=0; i < 6; i++) {
        sum += marks[i];
    }
    cout << " " << sum << " " << cur_id;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, classType;
    string name;
    int age;
    int cp = 1;
    int cs = 1;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> classType;
        if (classType==1) {
            // Create Professor
            Professor prof;
            prof.set_id(cp);
            cp += 1;
            prof.getdata();
            prof.putdata();
            cout << endl;
        } else if (classType==2) {
            // Create Student
            Student stud;
            stud.set_id(cs);
            cs += 1;
            stud.getdata();
            stud.putdata();
            cout << endl;
        }
    }
    return 0;
}
