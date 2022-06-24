#pragma once
#include <iostream>
#include <cstring>

class Teacher
{
private:
	std::string firstName;
	std::string middleName;
	std::string lastName;

	std::string subject;
	int seniority = 0;

public:
	Teacher() {}
	Teacher(std::string firstName, std::string middleName, std::string lastName, std::string subject, int seniority) :
		firstName(firstName), middleName(middleName), lastName(lastName), subject(subject), seniority(seniority) {}
	Teacher(const Teacher& another) :
		firstName(another.firstName), middleName(another.middleName), lastName(another.lastName), subject(another.subject), seniority(another.seniority) {}
	~Teacher() {}

	std::string GetFname() const
	{
		return firstName;
	}
	std::string GetMname() const
	{
		return middleName;
	}
	std::string GetLname() const
	{
		return lastName;
	}
	std::string GetSubject() const
	{
		return subject;
	}
	int GetSeniority() const
	{
		return seniority;
	}
	Teacher& operator=(Teacher teacher) {
		std::swap(firstName, teacher.firstName);
		std::swap(middleName, teacher.middleName);
		std::swap(lastName, teacher.lastName);
		std::swap(subject, teacher.subject);
		std::swap(seniority, teacher.seniority);
		return *this;
	}
	void Print()
	{
		std::cout << firstName << " " << middleName << " " << lastName << " " << subject << " " << seniority << std::endl;
	}

};

bool operator==(const Teacher& theacher1, const Teacher& teacher2)
{
	return (theacher1.GetFname() == teacher2.GetFname() && theacher1.GetMname() == teacher2.GetMname() && theacher1.GetLname() == teacher2.GetLname() && theacher1.GetSubject() == teacher2.GetSubject() && theacher1.GetSeniority() == teacher2.GetSeniority());
}

bool operator!=(const Teacher& theacher1, const Teacher& teacher2)
{
	return !(theacher1 == teacher2);
}

std::ostream& operator<<(std::ostream& out, const Teacher& teacher) {
	out << teacher.GetFname() << " " << teacher.GetMname() << " " << teacher.GetLname() << " " << teacher.GetSubject() << " " << teacher.GetSeniority();
	return out;
};
