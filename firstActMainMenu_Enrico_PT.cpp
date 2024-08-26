#include <iostream>
using namespace std;

void listFILE(){
	int num;
	cout << "\t------> LIST FILE DETAILS <------"<< endl;
	cout << "[1] List All Files "<< endl;
	cout << "[2] List of Extension Files " << endl;
	cout << "[3] List of Name Wise"<< endl;
	cout << "Enter your Choice: ";
		cin >> num;
		
		if(num == 1){
	cout << "\nList of All(*.*) Files "<< endl;
	cout << "file1.txt\nfile2.cpp\nreport.doc\nimage.jpg\n(continues...)"<< endl;
	cout << "\nTotal Files: 4"<< endl;
	cout << "Press any key  to continue...\n"<< endl;
	
		}
}

void createDIRECTORY(){
	string Name;
	cout << "Enter the Directory name: "<< endl;
		cin >> Name;
	cout << "Current directory: C: \\Users\\UserName\\Documents"<< endl;
	cout << Name << "Directory Successfully Created"<< endl;
	cout << "Press any key to continue...\n"<< endl;
}
 
 void changeDIRECTORY() {
    string Name;
    int num;
    cout << "\nCurrent Directory: C:\\Users\\UserName\\Documents\n" << endl;
    cout << "------> CHANGE DIRECTORY <------"<< endl;
    cout << "[1] Step by Step Backward"<< endl;
    cout << "[2] Goto Root Directory"<< endl;
    cout << "[3] Forward Directory"<< endl;
    cout << "Enter the Number: ";
    	cin >> num;
    cout <<""<<endl;
    cout << "Please enter the Directory Name: ";
    	cin >> Name;
    cout << "Current Directory: C:\\Users\\UserName\\Documents\\" << Name << endl;
    cout << "Press any key  to continue...\n"<< endl;
}

int main (){
	int num;
    do{
        cout << "\t------> MAIN MENU <------" << endl;
        cout << "[1] To Display List of Files"<< endl;
        cout << "[2] To Create New Directory"<< endl;
        cout << "[3] To Change the Working Directory"<< endl;
        cout << "[4] Exit"<< endl;
        cout << "Enter the Number: ";
        cin >> num;
  		
     
        if (num == 1){
        	listFILE();
		}else if(num == 2){
			createDIRECTORY();
		}else if(num == 3){
			changeDIRECTORY();
		}else if(num == 4){
			cout << "Exiting..." << endl;
		}else {
			cout << "Invalid choice! Try again." << endl;
		}

    } while (num != 4);

	return 0;
}
























