#include <iostream>   // for input and output
#include <string>     //for managing string dynamically
#include <fstream>    //handle file input and output
#include <conio.h>   // For getch()
#include <sstream>    // For stringstream
using namespace std;

// Function Declarations
int login();
void mainPage();
void callExit();
void addPatient();
void addStaff();
void viewPatients();
void viewStaff();
void editPatient();
void editStaff();
void clearScreen();
void savePatientRecord(const string& name, const string& address, const string& dob, const string& condition, const string& doctor);
void saveStaffRecord(const string& staffID, const string& name, const string& specialty, const string& assignedPatients);

// Clear screen (cross-platform)
void clearScreen() 
{
    system("cls"); 
}

// Login Function
int login() 
{
    clearScreen();
    string username, password;
    int attempts = 0;
    const int max_attempts = 3;
    const string correct_username = "admin";
    const string correct_password = "1234";

    while (attempts < max_attempts) 
	{
        password.clear(); // Clear password for each attempt
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t\t    ----------------------------------\n";
        cout << "\t\t\t\t    |	HOSPITAL MANAGEMENT SYSTEM	|\n";
        cout << "\t\t\t\t    ----------------------------------\n";
        cout << "\n\n";
        cout << "\t\t\t\t\tUsername: ";
        cin >> username;
        cout << "\t\t\t\t\tPassword: ";
        char ch;
        while ((ch = getch()) != '\r') 
		{ // '\r' is Enter key
            if (ch == '\b' && !password.empty()) 
			{ 
                cout << "\b \b"; 
                password.pop_back(); 
            }
            else if (ch != '\b') 
			{
                cout << "*"; 
                password += ch;
            }
        }

        if (username == correct_username && password == correct_password) 
		{
            cout << "\n\n";
            cout << "\t\t\t\tYou have successfully logged into the system!\n\n";
            return 1;
        }
        else 
		{
            attempts++;
            cout << "\n\n\n\n\n\n";
            cout << "\t\t\t\tNo. of attempts remaining: " << max_attempts - attempts << "\n\n";
        }
    }

    return 0;
}

// Main Page Function
void mainPage() {
    system("cls");
    cout << "\t\t\t\t\t\t" << __DATE__ << endl;
    cout << "\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\t\t\t\t    |	HOSPITAL MANAGEMENT SYSTEM	|\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\tPrepared By  : 1:Muhammad Hassan\t2:Khuram Shehzad\t3:Kashif Javed\n";
    cout << "\t\t\t\tSubject        : Programming Fundamentals\n";
    cout << "\t\t\t\tProject Title   : Hospital Management System\n";
    cout << "\t\t\t\tProfessor Name     : Waqar Hussain\n";
    cout << "\t\t\t\tGovernment College University Faislabad Chiniot Campus\n";
    cout << "\n\n";
    system("pause");
}
// Exit function
void callExit() 
{
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\n\tTaking You Out of The System\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\tYou are out of the System.\n";
    cout << "\t\t\t\t\tThank You!\n";
    exit(0);
}

// Save Patient Record
void savePatientRecord(const string& name, const string& address, const string& dob, const string& condition, const string& doctor) {
    ofstream file("patient_records.txt", ios::app); // Open file in append mode
    if (file.is_open()) 
	{
        file << name << "\n";
        file << address << "\n";
        file << dob << "\n";
        file << condition << "\n";
        file << doctor << "\n";
        file << "----------------------------\n";
        file.close();
        cout << "Patient details saved successfully." << endl;
    } 
	else 
	{
        cout << "Error: Unable to open file!" << endl;
    }
}

// Save Staff (Doctor) Record
void saveStaffRecord(const string& staffID, const string& name, const string& specialty, const string& assignedPatients) {
    ofstream file("staff_records.txt", ios::app); // Append mode
    if (file.is_open()) 
	{
        file << staffID << "\n";
        file << name << "\n";
        file << specialty << "\n";
        file << assignedPatients << "\n";
        file << "----------------------------\n";
        file.close();
        cout << "Staff member details saved successfully." << endl;
    } 
	else 
	{
        cout << "Error: Unable to open file!" << endl;
    }
}
// Add Patient Function
void addPatient() 
{
    clearScreen();
    string name, address, dob, condition, doctor;
    cin.ignore(); // To clear any leftover input buffer
    cout << "Enter the name of the patient: ";
    getline(cin, name);
    cout << "Enter the address of the patient: ";
    getline(cin, address);
    cout << "Enter the date of birth (DD/MM/YYYY): ";
    getline(cin, dob);
    cout << "Enter the patient's condition: ";
    getline(cin, condition);
    cout << "Enter the assigned doctor: ";
    getline(cin, doctor);

    savePatientRecord(name, address, dob, condition, doctor);
}
// Add Staff (Doctor) Function
void addStaff() 
{
    clearScreen();
    string staffID, name, specialty, assignedPatients;
    cin.ignore(); // To clear any leftover input buffer
    cout << "Enter Staff ID: ";
    getline(cin, staffID);
    cout << "Enter Staff Name: ";
    getline(cin, name);
    cout << "Enter Staff Specialty: ";
    getline(cin, specialty);
    cout << "Enter Assigned Patients: ";
    getline(cin, assignedPatients);

    saveStaffRecord(staffID, name, specialty, assignedPatients);
}

// View Patients Function
void viewPatients() 
{
    clearScreen();
    ifstream file("patient_records.txt");
    string line;
    if (file.is_open()) 
	{
        cout << "Patient Records:\n";
        cout << "-----------------------------------\n";
        while (getline(file, line)) 
		{
            cout << line << endl;
        }
        file.close();
    } 
	else 
	{
        cout << "Error: Unable to open patient records file!" << endl;
    }
}

// View Staff Members Function
void viewStaff() 
{
    clearScreen();
    ifstream file("staff_records.txt");
    string line;
    if (file.is_open()) 
	{
        cout << "Staff Members Records:\n";
        cout << "-----------------------------------\n";
        while (getline(file, line)) 
		{
            cout << line << endl;
        }
        file.close();
    } 
	else 
	{
        cout << "Error: Unable to open staff records file!" << endl;
    }
}

// Edit Patient Function
void editPatient() 
{
    clearScreen();
    string name, line;
    cout << "Enter the name of the patient to edit: ";
    cin.ignore(); // To clear any leftover input buffer
    getline(cin, name);

    ifstream file("patient_records.txt");
    ofstream tempFile("temp_patient_records.txt");
    bool found = false;

    while (getline(file, line)) 
	{
        if (line == name) 
		{
            found = true;
            cout << "Editing details for patient: " << name << endl;
            string newName, newAddress, newDob, newCondition, newDoctor;
            cout << "Enter new name: ";
            getline(cin, newName);
            cout << "Enter new address: ";
            getline(cin, newAddress);
            cout << "Enter new DOB (DD/MM/YYYY): ";
            getline(cin, newDob);
            cout << "Enter new condition: ";
            getline(cin, newCondition);
            cout << "Enter new doctor: ";
            getline(cin, newDoctor);

            savePatientRecord(newName, newAddress, newDob, newCondition, newDoctor);
            continue; // Skip writing the old record
        }
        tempFile << line << "\n";
    }

    if (found) 
	{
        cout << "Patient details updated successfully." << endl;
        file.close();
        tempFile.close();
        remove("patient_records.txt");
        rename("temp_patient_records.txt", "patient_records.txt");
    } 
	else 
	{
        cout << "Patient not found!" << endl;
    }
}

// Edit Staff Function
void editStaff() 
{
    clearScreen();
    string staffID, line;
    cout << "Enter the Staff ID to edit: ";
    cin.ignore(); // To clear any leftover input buffer
    getline(cin, staffID);

    ifstream file("staff_records.txt");
    ofstream tempFile("temp_staff_records.txt");
    bool found = false;

    while (getline(file, line)) 
	{
        if (line == staffID) 
		{
            found = true;
            cout << "Editing details for Staff ID: " << staffID << endl;
            string newStaffID, newName, newSpecialty, newAssignedPatients;
            cout << "Enter new Staff ID: ";
            getline(cin, newStaffID);
            cout << "Enter new Name: ";
            getline(cin, newName);
            cout << "Enter new Specialty: ";
            getline(cin, newSpecialty);
            cout << "Enter new Assigned Patients: ";
            getline(cin, newAssignedPatients);

            saveStaffRecord(newStaffID, newName, newSpecialty, newAssignedPatients);
            continue; // Skip writing the old record
        }
        tempFile << line << "\n";
    }

    if (found) 
	{
        cout << "Staff details updated successfully." << endl;
        file.close();
        tempFile.close();
        remove("staff_records.txt");
        rename("temp_staff_records.txt", "staff_records.txt");
    } 
	else 
	{
        cout << "Staff not found!" << endl;
    }
}

// Main function
int main() 
{
    cout << __DATE__ << endl;
    mainPage();
    system("pause");

    if (login()) 
	{
        char choice;
        do 
		{
            clearScreen();
            cout << "Hospital Management System\n";
            cout << "=========================\n";
            cout << "1. Add Patient\n";
            cout << "2. Add Staff Member\n";
            cout << "3. View Patients\n";
            cout << "4. View Staff Members\n";
            cout << "5. Edit Patient\n";
            cout << "6. Edit Staff Member\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) 
			{
                case '1': addPatient(); break;
                case '2': addStaff(); break;
                case '3': viewPatients(); break;
                case '4': viewStaff(); break;
                case '5': editPatient(); break;
                case '6': editStaff(); break;
                case '7': callExit(); break;
                default: cout << "Invalid choice! Try again.\n";
            }
            cout << "\nPress any key to return to menu...\n";
            system("pause");
        } while (choice != '7');
    }
    callExit();
    return 0;
}