#include <iostream>     // for I/O operations
#include <fstream>		// for outputting into file
#include <cstring>		// for basic string functions

// To keep student related information
struct Student
{
	char Name[20], Section[3], FatherName[20], MotherName[20], AdmissionNumber[6], Class[4], DOB[11], ResidentialAddress[100];
	int RollNumber, ToalWorkingDays, DaysPresent;
	float Attendance;
	uint64_t PrimaryPhoneNo, SecondaryPhoneNo;		// typedef unsigned long long uint64_t
} student;

// To keep student’s academic related information
struct Marks
{
	int Total, TotalEnglish, TotalMaths, TotalPhysics, TotalChemistry, TotalComputer;
	float Obtained, ObtainedEnglish, ObtainedMaths, ObtainedPhysics, ObtainedChemistry, ObtainedComputer;
	float Percentage;
	bool AcademicStatus;
	char Grade;
} marks;

// To clear screen
void clearScreen()
{
    #if defined(_WIN32)			// if the operating system is an i386 Windows
    std::system("CLS");
    #elif defined(_WIN64)		// if the operating system is an amd64 Windows
    std::system("CLS");
    #endif

    #if defined(__UNIX__) || (defined(__APPLE__) && defined(__MACH__))			// if the operating system is UNIX or MacOS (OSX)
    #include <sys/param.h>
    std::system("clear");
    #endif

    #if defined(__linux__)		// if the operating system runs on the Linux kernel
    std::system("clear");
    #endif
}

// To get information about the student
void studentDetails()
{
	std::cout << "Enter the following information about the student: " << std::endl;
	std::cout << "\nAdmission number: ";
	std::cin.getline(student.AdmissionNumber, 6);

	std::cout << "Student's name: ";
	std::cin.getline(student.Name, 20);

	std::cout << "Class: ";
	std::cin.getline(student.Class, 4);

	std::cout << "Section: ";
	std::cin.getline(student.Section, 3);

	std::cout << "Date of birth: ";
	std::cin.getline(student.DOB, 11);

	std::cout << "Father's name: ";
	std::cin.getline(student.FatherName, 20);

	std::cout << "Mother's name: ";
	std::cin.getline(student.MotherName, 20);

	std::cout << "Residential Address: ";
	std::cin.getline(student.ResidentialAddress, 100);

	std::cout << "Roll number: ";
	std::cin >> student.RollNumber;

	std::cout << "Primary phone number: ";
	std::cin >> student.PrimaryPhoneNo;

	std::cout << "Secondary phone number: ";
	std::cin >> student.SecondaryPhoneNo;

	std::cout << "Total working days: ";
	std::cin >> student.ToalWorkingDays;

	std::cout << "Days present: ";
	std::cin >> student.DaysPresent;

	return;
}

// To calculate student’s grade
void Grade()
{
	if (static_cast<int>(marks.Percentage) >= 65 && static_cast<int>(marks.Percentage) < 90)
	{
		marks.Grade = 'B';
		return;
	}

	else if (static_cast<int>(marks.Percentage) >= 40 && static_cast<int>(marks.Percentage) < 65)
	{
		marks.Grade = 'C';
		return;
	}

	else if (static_cast<int>(marks.Percentage) >= 90 && static_cast<int>(marks.Percentage) <= 100)
	{
		marks.Grade = 'A';
		return;
	}

	else if (static_cast<int>(marks.Percentage) >= 0 && static_cast<int>(marks.Percentage) < 33)
	{
		marks.Grade = 'F';
		return;
	}

	else if (static_cast<int>(marks.Percentage) >= 33 && static_cast<int>(marks.Percentage) < 40)
	{
		marks.Grade = 'D';
		return;
	}

	return;
}

// To calculate student’s percentage
void Percentage()
{
	marks.Total = marks.TotalEnglish + marks.TotalMaths + marks.TotalPhysics + marks.TotalChemistry + marks.TotalComputer;

	marks.Obtained = marks.ObtainedEnglish + marks.ObtainedMaths + marks.ObtainedPhysics + marks.ObtainedChemistry + marks.ObtainedComputer;

	marks.Percentage = (marks.Obtained / static_cast<float>(marks.Total) * 100);

	if (static_cast<int>(marks.Percentage) >= 33)
	{
		marks.AcademicStatus = true;
	}
	else
	{
		marks.AcademicStatus = false;
	}

	return;
}

// To get information about the student’s academics
void studentAcademics()
{
	std::cout << std::endl << std::endl;

	std::cout << "Enter marks of the following subjects: " << std::endl;

	std::cout << "Total marks in English: ";
	std::cin >> marks.TotalEnglish;
	std::cout << "Marks obtained: ";
	std::cin >> marks.ObtainedEnglish;

	std::cout << "Total marks in Mathematics: ";
	std::cin >> marks.TotalMaths;
	std::cout << "Marks obtained: ";
	std::cin >> marks.ObtainedMaths;

	std::cout << "Total marks in Physics: ";
	std::cin >> marks.TotalPhysics;
	std::cout << "Marks obtained: ";
	std::cin >> marks.ObtainedPhysics;

	std::cout << "Total marks in Chemistry: ";
	std::cin >> marks.TotalChemistry;
	std::cout << "Marks obtained: ";
	std::cin >> marks.ObtainedChemistry;

	std::cout << "Total marks in Computer: ";
	std::cin >> marks.TotalComputer;
	std::cout << "Marks obtained: ";
	std::cin >> marks.ObtainedComputer;

	Percentage();
	Grade();
	return;
}

// To check if the entered data is correct
void checkDataAuthenticity()
{
	char answer;
	int choice;

	std::cout << std::endl << std::endl << "The following details were entered: " << std::endl;

	// Details about the student
	std::cout << "Admission number: " << student.AdmissionNumber << std::endl;
	std::cout << "Student's name: " << student.Name << std::endl;
	std::cout << "Class: " << student.Class << std::endl;
	std::cout << "Section: " << student.Section << std::endl;
	std::cout << "Roll number: " << student.RollNumber << std::endl;
	std::cout << "Total working days: " << student.ToalWorkingDays << std::endl;
	std::cout << "Days present: " << student.DaysPresent << std::endl;
	std::cout << "Date of birth: " << student.DOB << std::endl;
	std::cout << "Father's name: " << student.FatherName << std::endl;
	std::cout << "Mother's name: " << student.MotherName << std::endl;
	std::cout << "Residential address: " << student.ResidentialAddress << std::endl;
	std::cout << "Primary phone number: " << student.PrimaryPhoneNo << std::endl;
	std::cout << "Secondary phone number: " << student.SecondaryPhoneNo << std::endl;

	// Details about the student's academics
	std::cout << "Total marks in English: " << marks.TotalEnglish << std::endl;
	std::cout << "Marks obtained: " << marks.ObtainedEnglish << std::endl;
	std::cout << "Total marks in Mathematics: " << marks.TotalMaths << std::endl;
	std::cout << "Marks obtained: " << marks.ObtainedMaths << std::endl;
	std::cout << "Total marks in Physics: " << marks.TotalPhysics << std::endl;
	std::cout << "Marks obtained: " << marks.ObtainedPhysics << std::endl;
	std::cout << "Total marks in Chemistry: " << marks.TotalChemistry << std::endl;
	std::cout << "Marks obtained: " << marks.ObtainedChemistry << std::endl;
	std::cout << "Total marks in Computer: " << marks.TotalComputer << std::endl;
	std::cout << "Marks obtained: " << marks.ObtainedComputer << std::endl;
	std::cout << "Subject total: " << marks.Total << std::endl;
	std::cout << "Student total: " << marks.Obtained << std::endl;
	std::cout << "Percentage: " << marks.Percentage << "%" << std::endl;
	std::cout << "Grade: " << marks.Grade << std::endl;

	// Confirm if the displayed data is correct
	std::cout << std::endl << "Is the displayed data correct? (Y/n): ";
	std::cin >> answer;

	if (answer == 'n' || answer == 'N')
	{
		std::cout << "1. Information about the student is wrong." << std::endl;
		std::cout << "2. Information about the student's academics is wrong." << std::endl;
		std::cout << "3. Both." << std::endl;
		std::cout << "Enter your choice. Please note that you will have to re-enter the data. (1/2/3): ";
		std::cin >> choice;

		switch (choice)
		{
		case 1: std::cout << "Modifying student's details...";
			std::cin.ignore();
			studentDetails();
			break;

		case 2: std::cout << "Modifying student's academic details...";
			std::cin.ignore();
			studentAcademics();
			break;

		case 3: std::cout << "Modyfying student's details...";
		std::cin.ignore();
			studentDetails();
			std::cout << "Modifying student's academic details...";
			studentAcademics();
			break;

		default: std::cout << "Wrong choice. The given information could not be               modified. " << std::endl;
			break;
		}
	}

	std::cout << "Press Enter to preview the report card..." << std::endl;
	std::cin.get();
	clearScreen();

	return;
}

// To print lines for table
void lines()
{
	for (int i = 0; i < 110; ++i)
	{
		std::cout << "_";
	}

	std::cout << std::endl << std::endl;

	return;
}

// To display the report card in console
void displayResult()
{
	clearScreen();
	std::cout << "\t\t\tDAV MODEL SCHOOL, DURGAPUR" << std::endl;
	std::cout << "\t\t\t  FINAL TERM REPORT CARD" << std::endl;
	std::cout << "\nStudent name: " << student.Name;
	std::cout << "\t\t\tAdmission number: " << student.AdmissionNumber << std::endl;
	std::cout << "Class/Section: " << student.Class << "/" << student.Section;
	std::cout << "\t\t\t\tDate of birth: " << student.DOB << std::endl;
	std::cout << "Roll number: " << student.RollNumber;
	std::cout << "\t\t\t\t\tTotal working days: " << student.ToalWorkingDays << std::endl;
	std::cout << "Father's name: " << student.FatherName;
	std::cout << "\t\t\tDays present: " << student.DaysPresent << std::endl;
	std::cout << "Mother's name: " << student.MotherName << std::endl;
	std::cout << "Primary phone number: " << student.PrimaryPhoneNo << std::endl;
	std::cout << "Secondary phone number: " << student.SecondaryPhoneNo << std::endl;

	std::cout << "Residential address: " << student.ResidentialAddress << std::endl;

	lines();
	// Row 1
	std::cout << "\t\tEnglish";
	std::cout << "\t\tMathematics";
	std::cout << "\tPhysics";
	std::cout << "\t\tChemistry";
	std::cout << "\tComputer" << std::endl;

	// Row 2
	std::cout << "Total marks: \t";
	// English total marks
	std::cout << marks.TotalEnglish << "\t\t";
	// Maths total marks
	std::cout << marks.TotalMaths << "\t\t";
	// Physics total marks
	std::cout << marks.TotalPhysics << "\t\t";
	// Chemistry total marks
	std::cout << marks.TotalChemistry << "\t\t";
	// Computer total marks
	std::cout << marks.TotalComputer << std::endl;

	// Row 3
	std::cout << "Marks obtained: ";
	// English marks
	std::cout << marks.ObtainedEnglish << "\t\t";
	// Maths marks
	std::cout << marks.ObtainedMaths << "\t\t";
	// Physics marks
	std::cout << marks.ObtainedPhysics << "\t\t";
	// Chemistry marks
	std::cout << marks.ObtainedChemistry << "\t\t";
	// Computer marks
	std::cout << marks.ObtainedComputer << std::endl;
	lines();

	std::cout << "Grade: " << marks.Grade << std::endl;
	std::cout << "Percentage: " << marks.Percentage << "%" << std::endl;

	if (marks.AcademicStatus)
	{
		std::cout << std::endl << student.Name << " has been PROMOTED to Class XII" << std::endl;
	}
	else
	{
		std::cout << std::endl << student.Name << " is NOT eligible to attend classes for Class XII" << std::endl;
	}

    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "Parent's signature" << "\t\t\t\t";
	std::cout << "Class teacher's signature" << "\t\t";
	std::cout << "Principal's signature" << std::endl;
	lines();

	std::cout << "Phone: 0343 123 4567" << "\t\t\t\t\t\t";
	std::cout << "Website: www.davmodelschooldurgapur.com" << std::endl;

	return;
}

// Creates File for the Report Card
void createFile()
{
	char fileName[30], extension[5] = ".txt";

	std::cout << "\n\nPress Enter to generate the report card...";
	std::cin.ignore();
    
	std::cout << "\nCreating your Report Card Text File\n";

	std::cout << "Enter your Filename (without file extention) : ";
	std::cin.getline(fileName, 30);
	std::strcat(fileName, extension);

	std::ofstream reportFile(fileName);

	// Checks if file is successfully opened
	if (!reportFile.is_open())
	{
		std::cerr << "File was not created successfully" << std::endl;
	}

	// Writing to the file
	reportFile << "\t\t\tDAV MODEL SCHOOL, DURGAPUR\n";
	reportFile << "\t\t\t  FINAL TERM REPORT CARD\n\n";

	reportFile << "Student Name: " << student.Name;
	reportFile << "\t\t\tAdmission number: " << student.AdmissionNumber << std::endl;

	reportFile << "Class/Section: " << student.Class << "/" << student.Section;
	reportFile << "\t\t\t\tDate of birth: " << student.DOB << std::endl;

	reportFile << "Roll number: " << student.RollNumber;
	reportFile << "\t\t\t\t\tTotal working days: " << student.ToalWorkingDays << std::endl;

	reportFile << "Father's name: " << student.FatherName;
	reportFile << "\t\t\tDays present: " << student.DaysPresent << std::endl;

	reportFile << "Mother's name: " << student.MotherName << std::endl;
	reportFile << "Primary phone number: " << student.PrimaryPhoneNo << std::endl;
	reportFile << "Secondary phone number: " << student.SecondaryPhoneNo << std::endl;
	reportFile << "Residential address: " << student.ResidentialAddress << std::endl;

	for (int i = 0; i < 110; ++i)
	{
		reportFile << "_";
	}

	reportFile << std::endl << std::endl;

	reportFile << "\t\tEnglish\t\tMathematics\tPhysics\t\tChemistry\tComputer" << std::endl;

	for (int i = 0; i < 110; ++i)
	{
		reportFile << "_";
	}
	reportFile << std::endl << std::endl;
	reportFile << "Total marks: \t" << marks.TotalEnglish << "\t\t" << marks.TotalMaths << "\t\t" << marks.TotalPhysics << "\t\t" << marks.TotalChemistry << "\t\t" << marks.TotalComputer << std::endl;
	reportFile << "Marks obtained: " << marks.ObtainedEnglish << "\t\t" << marks.ObtainedMaths << "\t\t" << marks.ObtainedPhysics << "\t\t" << marks.ObtainedChemistry << "\t\t" << marks.ObtainedComputer << std::endl;

	for (int i = 0; i < 110; ++i)
	{
		reportFile << "_";
	}
	reportFile << std::endl << std::endl;
	reportFile << "Grade: " << marks.Grade << std::endl;
	reportFile << "Percentage: " << marks.Percentage << "%" << std::endl;

	if (marks.AcademicStatus)
	{
		reportFile << student.Name << " has been PROMOTED to Class XII";
	}
	else
	{
		reportFile << student.Name << " is NOT eligible to attend classes for Class XII" << std::endl;
	}


	reportFile << std::endl << std::endl << std::endl << std::endl << std::endl;
	reportFile << "Parent's signature\t\t\t\tClass teacher's signature\t\tPrincipal's signature" << std::endl;
	reportFile << "Phone: 0343 567 1234\t\t\t\t\t\t\tWebsite: www.davmodelschooldurgapur.com" << std::endl;

	for (int i = 0; i < 110; ++i)
	{
		reportFile << "_";
	}
	reportFile << std::endl;

	// Closes the file
	reportFile.close();
}

// Driver function. The program starts and ends here.
int main()
{
	studentDetails();
	studentAcademics();
	checkDataAuthenticity();
	displayResult();
	createFile();

	std::cout << std::endl << std::endl << "Result generation complete. Press Enter to exit...";
	std::cin.ignore();
	std::cin.get();

	return 0;
}
