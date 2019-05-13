#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "Student.h"

void readData(std::vector<Student> & vec) {
    // File I/O code can also be used in the other readData functions
    std::ifstream file;
    file.open("input.txt");
    std::string fn, ln;
    int id;
    float test1, test2, test3, test4, test5, grade;
    file >> fn;
    while(!file.eof()) {
        file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
        std::cout << fn << " " << ln << " " << id << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5 << std::endl;
        // implement logic to store data in STL container
        grade = (test1 + test2 + test3 + test4 + test5) / 5;
        vec.emplace_back(fn, ln, id, grade);
        file >> fn;
    }
    file.close();
}

void readData(std::stack<Student> & myStack) {
    std::ifstream file("input.txt");
    int id;
    std::string fn, ln;
    float test1, test2, test3, test4, test5, grade;

    file >> fn;
    while(!file.eof()) {
        // read from the file
        file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
        std::cout << fn << " " << ln << " " << test1 << " " << test2 << " "
          << test3 << " " << test4 << " " << test5 << std::endl;


        grade = (test1 + test2 + test3 + test4 + test5) / 5;
        myStack.emplace(fn, ln, id, grade);
        file >> fn;
    }
    file.close();
}

void readData(std::queue<Student> & myQueue) {
    std::ifstream file("input.txt");
    int id;
    std::string fn, ln;
    float test1, test2, test3, test4, test5, grade;

    while(file >> fn) {
        file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
        std::cout << fn << " " << ln << " " << test1 << " " << test2 << " "
          << test3 << " " << test4 << " " << test5 << std::endl;

        grade = (test1 + test2 + test3 + test4 + test5) / 5;
        myQueue.emplace(fn, ln, id, grade);
    }
    file.close();
}

void readData(std::list<Student> & myList) {
  std::ifstream file("input.txt");
  int id;
  std::string fn, ln;
  float test1, test2, test3, test4, test5, grade;

  while(file >> fn) {
      file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
      std::cout << fn << " " << ln << " " << test1 << " " << test2 << " "
        << test3 << " " << test4 << " " << test5 << std::endl;

      grade = (test1 + test2 + test3 + test4 + test5) / 5;
      myList.emplace_back(fn, ln, id, grade);
  }
  file.close();
}

void readData(std::map<int, Student> & myMap) {
  std::ifstream file("input.txt");
  int id;
  std::string fn, ln;
  float test1, test2, test3, test4, test5, grade;
  Student temp;

  while(file >> fn) {
      file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
      std::cout << fn << " " << ln << " " << test1 << " " << test2 << " "
        << test3 << " " << test4 << " " << test5 << std::endl;

      grade = (test1 + test2 + test3 + test4 + test5) / 5;
      temp.setfirstName(fn);
      temp.setLastName(ln);
      temp.setStudentId(id);
      temp.setClassGrade(grade);
      myMap.insert(std::pair<int, Student>(id, temp));
  }

}

void print(std::vector<Student> myVec) {
  std::vector<Student>::iterator current = myVec.begin();
  std::cout << std::endl;
  std::cout << "Vector example" << std::endl;
  while(current != myVec.end()) {
      std::cout << current->getFirstName() << " " << current->getLastName() << " "
        << current->getStudentId() << " " << current->getClassGrade() << std::endl;
        current++;
  }
  std::cout << std::endl;
}

void print(std::stack<Student> myStack) {
    std::cout << std::endl;
    std::cout << "Stack example" << std::endl;

    std::stack<Student> tempStack;
    while(!myStack.empty()) {
        tempStack.push(myStack.top());
        myStack.pop();
    }

    while(!tempStack.empty()) {
        std::cout << tempStack.top().getFirstName() << " " << tempStack.top().getLastName()
          << " " << tempStack.top().getStudentId() << " " << tempStack.top().getClassGrade()
            << std::endl;
        tempStack.pop();
    }
    std::cout << std::endl;
}

void print(std::queue<Student> myQueue) {
    std::cout << std::endl;
    std::cout << "Queue example" << std::endl;

    while(!myQueue.empty()) {
        std::cout << myQueue.front().getFirstName() << " " << myQueue.front().getLastName()
          << " " << myQueue.front().getStudentId() << " " << myQueue.front().getClassGrade()
            << std::endl;
        myQueue.pop();
    }
    std::cout << std::endl;
}

void print(std::list<Student> myList) {
    std::cout << std::endl;
    std::cout << "List example" << std::endl;

    std::list<Student>::iterator current = myList.begin();
    while(current != myList.end()) {
        std::cout << current->getFirstName() << " " << current->getLastName() << " "
          << current->getStudentId() << " " << current->getClassGrade() << std::endl;
        current++;
    }
    std::cout << std::endl;
}

void print(std::map<int, Student> myMap) {
  std::cout << std::endl;
  std::cout << "Map example" << std::endl;

  std::map<int, Student>::iterator current = myMap.begin();
  while(current != myMap.end()) {
      std::cout << current->second.getFirstName() << " "
        << current->second.getLastName() << " " << current->first
          << " " << current->second.getClassGrade() << std::endl;
      current++;
  }
}

int main() {
    std::vector<Student> studentVec;
    std::stack<Student> studentStack;
    std::queue<Student> studentQueue;
    std::list<Student> studentList;
    std::map<int, Student> studentMap; // use the student ID for the key

    readData(studentVec);
    print(studentVec);

    readData(studentStack);
    print(studentStack);

    readData(studentQueue);
    print(studentQueue);

    readData(studentList);
    print(studentList);

    readData(studentMap);
    print(studentMap);
    return 0;
}
