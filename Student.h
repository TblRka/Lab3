#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
	string firstName;
	string middleName;
	string lastName;

	int group = 0;
	int list_number = 0;
	double GPA = 0.0;

public:
	Student() {}
	Student(string f_name, string m_name, string l_name, int group, int number, double gpa) :
		firstName(f_name), middleName(m_name), lastName(l_name), group(group), list_number(number), GPA(gpa) {}
	Student(const Student& another)
	{
		firstName = another.firstName;
		middleName = another.middleName;
		lastName = another.lastName;
		group = another.group;
		list_number = another.list_number;
		GPA = another.GPA;
	}

	string GetFname() const
	{
		return firstName;
	}
	string GetMname() const
	{
		return middleName;
	}
	string GetLname() const
	{
		return lastName;
	}
	int GetGroup() const
	{
		return group;
	}
	double GetGPA() const
	{
		return GPA;
	}
	double GetNum() const
	{
		return list_number;
	}
	Student& operator=(Student student) {
		swap(firstName, student.firstName);
		swap(middleName, student.middleName);
		swap(lastName, student.lastName);
		swap(group, student.group);
		swap(list_number, student.list_number);
		swap(GPA, student.GPA);
		return *this;
	}
	void Print()
	{
		cout << firstName << " " << middleName << " " << lastName << " " << group << " " << list_number << " " << GPA << endl;
	}
};

bool operator==(const Student& student1, const Student& student2)
{
	return (student1.GetFname() == student2.GetFname() && student1.GetMname() == student2.GetMname() && student1.GetLname() == student2.GetLname() && student1.GetGroup() == student2.GetGroup() && student1.GetNum() == student2.GetNum() && student1.GetGPA() == student2.GetGPA());
}
bool operator!=(const Student& student1, const Student& student2)
{
	return !(student1 == student2);
}
ostream& operator<<(ostream& out, const Student& student) {
	out << student.GetFname() << " " << student.GetMname() << " " << student.GetLname() << " " << student.GetGroup() << " " << student.GetNum() << " " << student.GetGPA();
	return out;
}
