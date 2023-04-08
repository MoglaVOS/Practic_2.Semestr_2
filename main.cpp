#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student {
    string FIO;
    char Sex;
    short int Group;
    short int Id;
    short int Subject[7];
    float avg;
};

struct wrStudent {
    string Firstname;
    string Name;
    string LastName;
    char Sex;
    short int Group;
    short int Id;
    short int Subject[7];
};

struct Compition {
    string commandName;
    string FIO;
    int GoldMedal;
    int Date;

};

int countStudents() {
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (database.is_open()) {
        int temp = 0;
        string data;
        while (!database.eof()) {
            getline(database, data);
            temp++;
        }
        database.close();
        int n;
        n = temp / 12;
        return n;
    } else return 0;
}

void FileRead() {
    int size = countStudents();
    if (size == 0) {
        cout << "Database has no entries!\n";
        return;
    }
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (database.is_open()) {
        Student *student = new Student[size];
        for (int i = 0; i < size; i++) {
            string lastname, firstname, name;
            database >> lastname >> firstname >> name;
            student[i].FIO = lastname + " " + firstname + " " + name;
            database >> student[i].Sex;
            database >> student[i].Group;
            database >> student[i].Id;
            for (int j = 0; j < 8; j++) {
                database >> student[i].Subject[j];
            }
        }
        database.close();

        for (int i = 0; i < size; i++) {
            cout << "FI0: " << student[i].FIO << '\n';
            cout << "Gender: " << student[i].Sex << '\n';
            cout << "Group: " << student[i].Group << '\n';
            cout << "Number in group: " << student[i].Id << '\n';
            cout << "The results of the differentiated test: ";
            for (int j = 0; j < 5; j++)
                cout << student[i].Subject[j] << " ";
            cout << "\nExam result: ";
            for (int k = 5; k < 8; k++)
                cout << student[i].Subject[k] << " ";
            cout << "\n--------------------------\n";
        }
        delete[] student;
    } else cout << "Error!\n";
}

void ShowGroup() {
    int n;
    int size = countStudents();
    cout << "Enter the group number:" << endl;
    cin >> n;
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (size == 0) {
        cout << "The database is empty." << endl;
        return;
    } else {
        if (database.is_open()) {
            Student *student = new Student[size];
            for (int i = 0; i < size; i++) {
                string lastname, firstname, name;
                database >> lastname >> firstname >> name;
                student[i].FIO = firstname + " " + lastname + " " + name;
                database >> student[i].Sex >> student[i].Group >> student[i].Id;
                for (int j = 0; j < 8; j++) {
                    database >> student[i].Subject[j];
                }
            }
            database.close();
            for (int i = 0; i < size; i++) {
                if (student[i].Group == n) {
                    cout << "FIO: " << student[i].FIO;
                    cout << "\nNumber in group: " << student[i].Id << '\n';
                    cout << "Gender: " << student[i].Sex << '\n';
                    cout << "The results of the differentiated test: ";
                    for (int j = 0; j < 5; j++)
                        cout << student[i].Subject[j] << " ";
                    cout << "\nExam result: ";
                    for (int k = 5; k < 8; k++)
                        cout << student[i].Subject[k] << " ";
                    cout << "\n--------------------------\n";
                }
            }
            delete[] student;
        } else cout << "Database read error!";
    }
}

void ShowId() {
    int n;
    cout << "Enter id student:" << endl;
    cin >> n;
    int size = countStudents();
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (size == 0) {
        cout << "The database is empty." << endl;
        return;
    } else {
        if (database.is_open()) {
            Student *student = new Student[size];
            for (int i = 0; i < size; i++) {
                string lastname, firstname, name;
                database >> lastname >> firstname >> name;
                student[i].FIO = firstname + " " + lastname + " " + name;
                database >> student[i].Sex >> student[i].Group >> student[i].Id;
                for (int j = 0; j < 8; j++) {
                    database >> student[i].Subject[j];
                }
            }
            database.close();

            for (int i = 0; i < size; i++) {
                if (student[i].Id == n) {
                    cout << "FI0: " << student[i].FIO << '\n';
                    cout << "Gender: " << student[i].Sex << '\n';
                    cout << "Group: " << student[i].Group << '\n';
                    cout << "Number in group: " << student[i].Id << '\n';
                    cout << "The results of the differentiated test: ";
                    for (int j = 0; j < 5; j++)
                        cout << student[i].Subject[j] << " ";
                    cout << "\nExam result: ";
                    for (int k = 5; k < 8; k++)
                        cout << student[i].Subject[k] << " ";
                    cout << "\n--------------------------" << endl;
                }
            }
            delete[] student;
        } else cout << "Database read error!";
    }
}

void StudentTop() {
    int size = countStudents();
    if (size == 0) {
        cout << "Database has no entries!\n";
        return;
    }
    cout << "Top 5 students with highest average grade\n";
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (database.is_open()) {
        Student *student = new Student[size];
        for (int i = 0; i < size; i++) {
            int sum = 0;
            string lastname, firstname, name;
            database >> lastname >> firstname >> name;
            student[i].FIO = lastname + " " + firstname + " " + name;
            database >> student[i].Sex;
            database >> student[i].Group;
            database >> student[i].Id;
            for (int j = 0; j < 8; j++) {
                database >> student[i].Subject[j];
                sum += student[i].Subject[j];
            }
            student[i].avg = (float) sum / 8;
        }
        database.close();

        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (student[j].avg < student[j + 1].avg)
                    swap(student[j], student[j + 1]);

        for (int i = 0; i < min(size, 5); i++) {
            cout << "Top " << i + 1 << ": " << student[i].Group << " " << student[i].FIO << " with average "
                 << student[i].avg << " -";
            for (int j = 0; j < 7; j++)
                cout << ' ' << student[i].Subject[j];
            cout << '\n';
        }

        delete[] student;
    } else cout << "Database read error!\n";
}

void FemaleAndMale() {
    int size = countStudents();
    if (size == 0) {
        cout << "Database has no entries!\n";
        return;
    }
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (database.is_open()) {
        Student *students = new Student[size];
        int male = 0, female = 0;
        for (int i = 0; i < size; i++) {
            string lastname, firstname, name;
            database >> lastname >> firstname >> name;
            students[i].FIO = lastname + " " + firstname + " " + name;
            database >> students[i].Sex;
            database >> students[i].Group;
            database >> students[i].Id;
            for (int j = 0; j < 8; j++) {
                database >> students[i].Subject[j];
            }
        }
        database.close();

        for (int i = 0; i < size; i++) {
            if (students[i].Sex == 'M')
                male++;
            else
                female++;
        }
        cout << "Female: " << female << "\nMale: " << male << endl;
        delete[] students;
    } else cout << "Database read error!\n";
}

void WriteStudent() {
    wrStudent student;
    cout << "Firstname" << endl;
    cin >> student.Firstname;
    cout << "Name" << endl;
    cin >> student.Name;
    cout << "Lastname" << endl;
    cin >> student.LastName;
    cout << "Sex" << endl;
    cin >> student.Sex;
    cout << "Group" << endl;
    cin >> student.Group;
    cout << "Number in group" << endl;
    cin >> student.Id;
    cout << "Grades" << endl;
    for (int j = 0; j < 8; j++) {
        cin >> student.Subject[j];
    }
    cin.clear();
    ofstream database;
    database.open("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt", ios::app);
    if (database.is_open()) {
        database << student.Firstname << ' ' << student.Name << ' ' << student.LastName << '\n';
        database << student.Sex << '\n';
        database << student.Group << '\n';
        database << student.Id << '\n';
        for (int j = 0; j < 8; j++) {
            database << student.Subject[j] << '\n';
        }
        database.close();
    } else
        cout << "Database read error!!" << endl;
}

void EditStudent() {
    int n;
    int size = countStudents();
    cout << "Enter id student:" << endl;
    cin >> n;
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (size == 0) {
        cout << "The database is empty." << endl;
        return;
    } else {
        if (database.is_open()) {
            wrStudent *student = new wrStudent[size];
            for (int i = 0; i < size; i++) {
                string lastname, firstname, name;
                database >> student[i].Firstname >> student[i].Name >> student[i].LastName;
                database >> student[i].Sex >> student[i].Group >> student[i].Id;
                for (int j = 0; j < 8; j++) {
                    database >> student[i].Subject[j];
                }
            }
            database.close();
            for (int i = 0; i < size; i++) {
                if (student[i].Id == n) {
                    cout << "Firstname" << endl;
                    cin >> student[i].Firstname;
                    cout << "Name" << endl;
                    cin >> student[i].Name;
                    cout << "Lastname" << endl;
                    cin >> student[i].LastName;
                    cout << "Sex" << endl;
                    cin >> student[i].Sex;
                    cout << "Group" << endl;
                    cin >> student[i].Group;
                    cout << "Number in group" << endl;
                    cin >> student[i].Id;
                    cout << "Grades" << endl;
                    for (int j = 0; j < 8; j++) {
                        cin >> student[i].Subject[j];
                    }
                    ofstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
                    if (!database.is_open()) {
                        cout << "Database write error!\n";
                    } else {
                        for (int i = 0; i < size; i++) {

                            database << student[i].Firstname << ' ' << student[i].Name << ' ' << student[i].LastName
                                     << '\n';
                            database << student[i].Sex << '\n';
                            database << student[i].Group << '\n';
                            database << student[i].Id << '\n';
                            for (int j = 0; j < 8; j++) {
                                database << student[i].Subject[j] << '\n';
                            }
                        }
                    }
                    cout << '\n' << "Profile successfully updated.\n";
                    database.close();
                    delete[] student;
                    break;
                }
            }

        }

    }
}

void GradeFive() {
    int size = countStudents();
    if (size == 0) {
        cout << "Database has no entries!\n";
        return;
    }
    cout << "Student grades 5" << endl;
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (database.is_open()) {
        Student *students = new Student[size];
        for (int i = 0; i < size; i++) {
            string lastname, firstname, name;
            database >> lastname >> firstname >> name;
            students[i].FIO = lastname + " " + firstname + " " + name;
            database >> students[i].Sex;
            database >> students[i].Group;
            database >> students[i].Id;
            for (int j = 0; j < 8; j++) {
                database >> students[i].Subject[j];
            }
        }
        database.close();

        int value = 0;
        for (int l = 0; l < size; l++) {
            for (int n = 0; n < 8; n++) {
                if (students[l].Subject[n] == 5)
                    value++;
            }
            if (value == 8) {
                cout << "FI0: " << students[l].FIO << '\n';
                cout << "The results of the differentiated test: ";
                for (int j = 0; j < 5; j++)
                    cout << students[l].Subject[j] << " ";
                cout << "\nExam result: ";
                for (int k = 5; k < 8; k++)
                    cout << students[l].Subject[k] << " ";
                cout << "\n--------------------------\n";
            }
            value = 0;
        }
        delete[] students;
    } else cout << "Database read error!\n";
}

void GradeFiveOrFour() {
    int size = countStudents();
    if (size == 0) {
        cout << "Database has no entries!\n";
        return;
    }
    cout << "Student grades 4 or 5" << endl;
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (database.is_open()) {
        Student *students = new Student[size];
        for (int i = 0; i < size; i++) {
            string lastname, firstname, name;
            database >> lastname >> firstname >> name;
            students[i].FIO = lastname + " " + firstname + " " + name;
            database >> students[i].Sex;
            database >> students[i].Group;
            database >> students[i].Id;
            for (int j = 0; j < 8; j++) {
                database >> students[i].Subject[j];
            }
        }
        database.close();

        int value = 0;
        for (int l = 0; l < size; l++) {
            for (int n = 0; n < 8; n++) {
                if (students[l].Subject[n] == 5 || students[l].Subject[n] == 4)
                    value++;
            }
            if (value == 8) {
                cout << "FI0: " << students[l].FIO << '\n';
                cout << "The results of the differentiated test: ";
                for (int j = 0; j < 5; j++)
                    cout << students[l].Subject[j] << " ";
                cout << "\nExam result: ";
                for (int k = 5; k < 8; k++)
                    cout << students[l].Subject[k] << " ";
                cout << "\n--------------------------\n";
            }
            value = 0;
        }
        delete[] students;
    } else
        cout << "Database read error!\n";
}

void GradeThree() {
    int size = countStudents();
    if (size == 0) {
        cout << "Database has no entries!\n";
        return;
    }
    cout <<  "Students who will not receive a scholarship:" << endl;
    ifstream database("C:/Users/super/CLionProjects/2sem/sem2prac1/database.txt");
    if (database.is_open()) {
        Student *students = new Student[size];
        for (int i = 0; i < size; i++) {
            string lastname, firstname, name;
            database >> lastname >> firstname >> name;
            students[i].FIO = lastname + " " + firstname + " " + name;
            database >> students[i].Sex;
            database >> students[i].Group;
            database >> students[i].Id;
            for (int j = 0; j < 8; j++) {
                database >> students[i].Subject[j];
            }
        }
        database.close();

        int value = 0;
        for (int l = 0; l < size; l++) {
            for (int n = 0; n < 8; n++) {
                if (students[l].Subject[n] == 3)
                    value++;
            }
            if (value > 0) {
                cout << "FI0: " << students[l].FIO << '\n';
                cout << "The results of the differentiated test: ";
                for (int j = 0; j < 5; j++)
                    cout << students[l].Subject[j] << " ";
                cout << "\nExam result: ";
                for (int k = 5; k < 8; k++)
                    cout << students[l].Subject[k] << " ";
                cout << "\n--------------------------\n";
            }
            value = 0;
        }
        delete[] students;
    } else
        cout << "Database read error!\n";
}

void IDZ() {
    ifstream dat("C:/Users/super/CLionProjects/2sem/sem2prac1/gold.txt");
    Compition person[3];
    if (!dat.is_open()) {
        cout << "Error";
    } else {
        for (int i = 0; i < 3; i++) {
            dat >> person[i].commandName;
            string lastname, firstname, name;
            dat >> lastname >> firstname >> name;
            person[i].FIO = lastname + " " + name + " " + firstname;
            dat >> person[i].GoldMedal;
            dat >> person[i].Date;
        }

        for (int i = 0; i < 3; i++) {
            if ((person[i].GoldMedal == 1) && ((2023 - person[i].Date) < 18)) {
                cout << "Capitan's name: " << person[i].FIO << endl;
                cout << "Command name: " << person[i].commandName << endl;
                cout << "Availability of gold medal: Yes" << endl;
                cout << "Birth Date: " << person[i].Date << endl;
            }
        }
    }
}

int main() {
    int key;
    cout <<
         "\nChoose task:\n"
         "0. Exit\n"
         "1. View all entries\n"
         "2. Create student\n"
         "3. Edit student\n"
         "4. View students from group\n"
         "5. View students from id\n"
         "6. Top 5 students\n"
         "7. Count males/females\n"
         "8. View students with lowest grade 5\n"
         "9. View students with lowest grade 4 or 5\n"
         "10. View students with lowest grade 3 (no scholarship)\n"
         "11. IDZ\n\n";
    cout << "Enter exercise number" << endl;
    cin >> key;
    switch (key) {
        case 0:
            return 0;
        case 1:
            FileRead();
            break;
        case 2:
            WriteStudent();
            break;
        case 3:
            EditStudent();
            break;
        case 4:
            ShowGroup();
            break;
        case 5:
            ShowId();
            break;
        case 6:
            StudentTop();
            break;
        case 7:
            FemaleAndMale();
            break;
        case 8:
            GradeFive();
            break;
        case 9:
            GradeFiveOrFour();
            break;
        case 10:
            GradeThree();
            break;
        case 11:
            IDZ();
            break;
        default:
            cout << "Error!" << endl;
            break;
    }
    system("pause");
    return 0;
}