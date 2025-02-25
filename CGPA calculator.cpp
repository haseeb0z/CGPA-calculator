#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <numeric> 

using namespace std;

double gradeToPoint(string grade) {
    transform(grade.begin(), grade.end(), grade.begin(), ::toupper);

    if (grade == "A") return 4.0;
    if (grade == "A-") return 3.7;
    if (grade == "B+") return 3.30;
    if (grade == "B") return 3.0;
    if (grade == "B-") return 2.70;
    if (grade == "C+") return 2.30;
    if (grade == "C") return 2.0;
    if (grade == "C-") return 1.70;
    if (grade == "D") return 1.0;
    if (grade == "F") return 0.0;
    return 0.0;  
}

double calculateGPA(const vector<int>& credits, const vector<double>& gradePoints) {
    double totalCredits = 0;
    double totalGradePoints = 0;

    for (size_t i = 0; i < credits.size(); ++i) {
        totalCredits += credits[i];
        totalGradePoints += credits[i] * gradePoints[i];
    }

    return totalCredits == 0 ? 0.0 : totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<int> credits(numCourses);
    vector<double> gradePoints(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter the credit hours for course " << i + 1 << ": ";
        cin >> credits[i];
        string grade;
        cout << "Enter the grade for course " << i + 1 << " : ";
        cin >> grade;
        gradePoints[i] = gradeToPoint(grade);
    }

    double gpa = calculateGPA(credits, gradePoints);

    cout << "\nTotal Credits: " << accumulate(credits.begin(), credits.end(), 0) << endl;
    cout << "Total Grade Points: " << gpa * accumulate(credits.begin(), credits.end(), 0) << endl;
    cout << "Your GPA for this semester is: " << gpa << endl;

    return 0;
}
