#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void markstrToVec(string str, vector<int>& less, vector<int>& mark);
class Student{
public:
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
 class marks {
 public:
	 int Studid;
	 vector<int> idLess;
	 vector<int> mark;
 };
 inline istream& operator>>(istream& is, marks& cur) {
	 is >> cur.Studid;
	 string str;
	 getline(is, str);
	 markstrToVec(str, cur.idLess, cur.mark);
	 return is;
 }

 class lessons {
 public:
	 int id;
	 string name;
	 bool nameById(int idd)
	 {
		 if (idd == id)
		 {
			 return true;
		 }
		 return false;
	 };
 };

 inline istream& operator>>(istream& is, lessons& cur) {
	 is >> cur.id;
	 getline(is, cur.name);
	 return is;
 }

 inline void markstrToVec(string str, vector<int>& less, vector<int>& mark) {
	 less.push_back(str[1] - '0');
	 for (int i = 2; i < str.length(); i++)
	 {
		 if (str[i] != ' ')
		 {
			 if (less.size() <= mark.size())
			 {
				 less.push_back(str[i] - '0');
			 }
			 else {
				 mark.push_back(str[i] - '0');
			 }
		 }
	 }
 }