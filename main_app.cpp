#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <string>
#include <limits>
#include <sstream>
#include<fstream>

using namespace std;

char host[] = "localhost";
char user[] = "root";
char pass[] = "********";

const size_t MAX_LENGTH = 100;

unsigned int manualHash(const char input[MAX_LENGTH]);
void insider();
void encryptout();
void encryptin();
void decryptin();
void decryptout();


void decryptin(const string& encryptedFileName, const string& decryptedFileName, const string& key)
{
	
	ifstream encryptedFile(encryptedFileName.c_str(), ios::binary);
ofstream decryptedFile(decryptedFileName.c_str(), ios::binary);


    if (!encryptedFile || !decryptedFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    size_t keyLength = key.length();

    char byte;
    size_t keyIndex = 0;

    while (encryptedFile.get(byte)) {
        byte ^= key[keyIndex % keyLength];
        decryptedFile.put(byte);
        keyIndex++;
    }

    encryptedFile.close();
    decryptedFile.close();
	
}

void decryptout()
{
   
     string encryptedFileName, decryptedFileName, key;

    cout << "Enter the encrypted file name: ";
    cin >> encryptedFileName;

    cout << "Enter the output file name for decrypted data: ";
    cin >> decryptedFileName;

    cout << "Enter the decryption key: ";
    cin >> key;
    
    decryptin(encryptedFileName, decryptedFileName, key);
    
    
    cout << "File decrypted successfully." << endl;

}

void encryptin(const string& inputFileName, const string& outputFileName, const string& key)
{
	
	ifstream inputFile(inputFileName.c_str(), ios::binary);
    ofstream outputFile(outputFileName.c_str(), ios::binary);


    if (!inputFile || !outputFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    size_t keyLength = key.length();

    char byte;
    size_t keyIndex = 0;

    while (inputFile.get(byte)) {
        byte ^= key[keyIndex % keyLength];
        outputFile.put(byte);
        keyIndex++;
    }

    inputFile.close();
    outputFile.close();
	
}

void encryptout()
{
	
	string inputFileName, outputFileName, key;

    cout << "Enter the input file name: ";
    cin >> inputFileName;

    cout << "Enter the output file name: ";
    cin >> outputFileName;

    cout << "Enter the encryption key: ";
    cin >> key;

    encryptin(inputFileName, outputFileName, key);

    cout << "File encrypted successfully." << endl;
}


void insider(const string& thisname)
{
   cout<<"welcome"<<thisname<<"to your own personalized vault"<<endl;
   cout<<endl;
   

                cout << "1. encrypt your file" << endl;
                cout << "2. decrypt your file" << endl;
                cout << "3. logout" << endl;
                int choice;

            a:
                while (!(cin >> choice)) {
                    cout << "error: enter a number";
                    cin.clear();
                    cout << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl << endl;
                if (choice != 1 && choice != 2 && choice!=3) {
                    cout << "wrong option selected, please enter a valid choice" << endl;
                    goto a;
                }

                if (choice == 1) {
                	encryptout();
                }
                else if(choice==2)
                {
				
                
				decryptout();
            }
            
            
                 
}





bool searchPassword(const string& fullname,MYSQL* obj, const string& username, int password) {
    
	
	stringstream ss;
    ss << password;
    string hashedPassStr = ss.str();
    string selectQuery = "SELECT COUNT(*) AS count FROM userx WHERE username = '" + username + "' AND password = '" + hashedPassStr + "'";

    if (mysql_ping(obj)) {
        cout << "Error: Unable to connect to the database" << endl;
        cout << mysql_error(obj) << endl;
        return false;
    }

    if (mysql_query(obj, selectQuery.c_str())) {
        cout << "Error: " << mysql_error(obj) << endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(obj);
    if (result == NULL) {
        cout << "Error in mysql_store_result: " << mysql_error(obj) << endl;
        return false;
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    int count = atoi(row[0]);

    mysql_free_result(result);

    if (count > 0) {
        cout << "Password matched. Login successful!" << endl;
        insider(fullname);
		return true;
        
    } else {
        cout << "User not found or password does not match. Login failed!" << endl;
        return false;
    }
}








unsigned int manualHash(const char input[MAX_LENGTH]) {
    unsigned int hashValue = 0;

    for (size_t i = 0; i < strlen(input); ++i) {
        hashValue += static_cast<unsigned int>(input[i]);
    }

    return hashValue;
}





void delay() {
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(2000);
    }
}





int main() {
    MYSQL* obj;

    char name[20];
    char username[20];
    char password[50];

    bool programisopened = true;

    if (!(obj = mysql_init(0))) {
        cout << "error: mysql object could not be created" << endl;
    } else {
        if (!mysql_real_connect(obj, host, user, pass, "new_user", 3306, NULL, 0)) {
            cout << "error: some database info is wrong or does not exist" << endl;
            cout << mysql_error(obj) << endl;
        } else {
            cout << "logged in" << endl << endl;
            while (programisopened) {
            	
            	
                cout << "***************welcome to your own personalized vault******************" << endl << endl;
                cout << "1. log in (already a registered user)" << endl;
                cout << "2. register as a new user" << endl;
                int choice;

            a:
                while (!(cin >> choice)) {
                    cout << "error: enter a number";
                    cin.clear();
                    cout << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << endl << endl;
                if (choice != 1 && choice != 2) {
                    cout << "wrong option selected, please enter a valid choice" << endl;
                    goto a;
                }

                if (choice == 1) {
                	
                	
                	
                	
                    system("CLS");
                    cout << "*********************welcome to your own personalized vault****************" << endl << endl;
                    cout << endl << endl << endl;

                    int hashPass1;
                    char uname1[20];
                    char pass1[50];

                hello:
                    cin.ignore();
                    cout << "enter your username:";
                    cin.getline(uname1, 20, '\n');
                    cout << endl;
                    string struname1 = string(uname1);
                    cout << "\n enter your password: ";
                    cin.getline(pass1, 50, '\n');
                    cout << endl;
                     hashPass1 = manualHash(pass1);

                    searchPassword(name,obj, struname1, hashPass1);
                    

                } else {
                	
                	
                	
                	
                    cout << "***************welcome to the portal of registration******************" << endl << endl;

                    cout << "enter your name: ";
                    cin.ignore();
                    cin.getline(name, 20, '\n');
                    cout << endl;
                    string strname = string(name);

                    cout << "enter your username: ";
                    cin.getline(username, 20, '\n');
                    cout << endl;
                    string strusername = string(username);

                    cout << "enter your password: ";
                    cin.getline(password, 50, '\n');
                    cout << endl;
                    int hashedPass = manualHash(password);

                    string sentence_aux = "insert into userx(name,username,password) values('%s','%s','%d')";
                    char* sentence = new char[sentence_aux.length() + 1];
                    strcpy(sentence, sentence_aux.c_str());

                    char* consult = new char[strlen(sentence) + strname.length() + strusername.length() + sizeof(hashedPass)];
                    sprintf(consult, sentence, strname.c_str(), strusername.c_str(), hashedPass);

                    if (mysql_ping(obj)) {
                        cout << "error: unable to connect" << endl;
                        cout << mysql_error(obj) << endl;
                    }

                    if (mysql_query(obj, consult)) {
                        cout << "error: " << mysql_error(obj) << endl;
                        rewind(stdin);
                        getchar();
                    } else {
                        cout << "info added correctly" << endl;
                        delay();
                        system("cls");
                    }

                    delete[] sentence;
                    delete[] consult;

                    MYSQL_RES* result = mysql_store_result(obj);
                    if (result == NULL) {
                        cout << "Error in mysql_store_result: " << mysql_error(obj) << endl;
                    }
                }
            }
        }
        cout << "bye" << endl;
    }

    return 0;
}
