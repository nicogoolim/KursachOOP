#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



 struct Student{
	 int id;
	 int course;
	 int group;
	 string fio;
 };

 inline istream& operator>>(istream& is, Student& cur) {
	 is >> cur.id >> cur.course >> cur.group;
	 getline(is, cur.fio);
	 return is;
 }
 struct marks {
	 int id;
	 string mark;
 };
 inline istream& operator>>(istream& is, marks& cur) {
	 is >> cur.id;
	 getline(is, cur.mark);
	 return is;
 }