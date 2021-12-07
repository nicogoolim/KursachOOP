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
	 bool studBuyId(int idd) {
		 if (idd==id)
		 {
			 return true;
		 }
		 return false;
	 }
 };

 inline istream& operator>>(istream& is, Student& cur) {
	 is >> cur.id >> cur.course >> cur.group;
	 getline(is, cur.fio);
	 return is;
 }
 inline ostream& operator<<(ostream& os, Student& cur) {
	 os << cur.id << " " << cur.course << " " << cur.group << " " << cur.fio;
	 return os;
 }
 class marks {
 public:
	 int Studid;
	 vector<int> idLess;
	 vector<int> mark;

	 int markByLess(int lessId) {
		 for (int i = 0; i < idLess.size(); i++)
		 {
			 if (idLess[i] == lessId) return mark[i];
		 }
	 }
 };
 inline istream& operator>>(istream& is, marks& cur) {
	 is >> cur.Studid;
	 string str;
	 getline(is, str);
	 markstrToVec(str, cur.idLess, cur.mark);
	 return is;
 }
 inline ostream& operator<<(ostream& os, marks& cur) {
	 os << cur.Studid<< " ";
	 for (int i = 0; i < cur.idLess.size(); i++)
	 {
		 os << cur.idLess[i] << " " << cur.mark[i] << " ";
	 }

	 return os;
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
 inline ostream& operator<<(ostream& os, lessons& cur) {
	 os << cur.id << " " << cur.name;
	 return os;
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

 inline Student StudById(vector<Student> arrStud,int id) {
	 for each (Student var in arrStud)
	 {
		 if (var.id == id) {
			 return var;
		 }
	 }
 }
 inline marks marksByStudId(vector<marks> arrMarks, int id) {
	 for each (marks var in arrMarks)
	 {
		 if (var.Studid == id) {
			 return var;
		 }
	 }
 }

 inline string lessByIdStr(vector<lessons> arrLess, int id) {
	 for each (lessons var in arrLess)
	 {
		 if (var.id == id) {
			 return var.name;
		 }
	 }
 }

 inline lessons lessById(vector<lessons> arrLess, int id) {
	 for each (lessons var in arrLess)
	 {
		 if (var.id == id) {
			 return var;
		 }
	 }
 }

 inline vector<marks> addMarks(Student stud, lessons less, vector<marks> mark, int newMark) {
	 int idLess = less.id;
	 int idStud = stud.id;
	 int count = -1;
	 marks cur;
	 for each (marks var in mark)
	 {
		 count++;
		 if (idStud == var.Studid)
		 {
			 cur = var;
			 break;
		 }
	 }
	 for (int i = 0; i < cur.idLess.size(); i++)
	 {
		 if (cur.idLess[i] == idLess)
		 {
			 cur.mark[i] = newMark;
			 mark[count] = cur;
			 return mark;
		 }
	 }
	 cur.idLess.push_back(idLess);
	 cur.mark.push_back(newMark);
	 mark[count] = cur;
	 return mark;
 }