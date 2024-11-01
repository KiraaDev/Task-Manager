#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void SetColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((bgColor << 4) | textColor));
}


void displayMenu(const string menuItems[], int size) {
    cout << "\n==================== Menu ====================\n";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]  " << menuItems[i] << "\n";
    }
    cout << "================================================\n";
}

class ConsoleApp {

private:
    string menuItems[3] = {"Templates", "Exit"};
    string templateItems[3] = {"Express", "ReactJs", "Back"};

    string expressItems[3] = {"Express Basic Auth", "Express CRUD", "Back" };
    string express[3] = {"https://github.com/KiraaDev/Express-Basic-Auth.git", "https://github.com/KiraaDev/CRUD-Express.git"};

    string reactItems[2] = {"ReactTs+Shadcn", "Back" };
    string react[2] = {"https://github.com/hayyi2/react-shadcn-starter.git"};

public:
    void logo();
    void logoExit();
    void menu();
    void templates();
    void expressApp();
    void reactApp();
    void cloneRepository(const string& repoUrl);
};

int main()
{
    ConsoleApp myObj;
    myObj.logo();
    myObj.menu();

    return 0;
}

void ConsoleApp::cloneRepository(const string& repoUrl) {
    string command = "git clone " + repoUrl;
    int result = system(command.c_str());

    if (result == 0) {
        cout << "Repository cloned successfully!" << endl;
        logoExit();
    } else {
        cout << "Failed to clone the repository." << endl;
        templates();
    }
}


void ConsoleApp::menu() {

    int choice;

    displayMenu(menuItems, 2);
    cout << "\nSelect Option: ";
    cin >> choice;


    switch(choice){
        case 1:
            exit(0);
        break;
        case 0:
            templates();
        break;
        default:
            exit(0);
    }
}


void ConsoleApp::templates() {

    int choice;
    system("cls");
    logo();

    displayMenu(templateItems, 3);

    do {
        cout << "\nSelect Option: ";
        cin >> choice;

        switch(choice){
            case 0:
                expressApp();
            break;
            case 1:
                reactApp();
            case 2:
                menu();
            break;
        }
    } while(choice != 0 || choice != 1 || choice != 2);
}

void ConsoleApp::expressApp() {

    int choice;
    system("cls");
    logo();

    displayMenu(expressItems, 3);

    do {
        cout << "\nSelect Option: ";
        cin >> choice;

        switch(choice){
            case 0:
                cloneRepository(express[0]);
            break;
            case 1:
                cloneRepository(express[1]);
            case 2:
                templates();
            break;
        }
    } while(choice != 0 || choice != 1 || choice != 2);
}

void ConsoleApp::reactApp() {

    int choice;
    system("cls");
    logo();

    displayMenu(reactItems, 2);

    do {
        cout << "\nSelect Option: ";
        cin >> choice;

        switch(choice){
            case 0:
                cloneRepository(react[0]);
            break;
            case 1:
                templates();
            break;
        }
    } while(choice != 0 || choice != 1);
}


void ConsoleApp::logo() {

    SetColor(10, 0);
    cout << R"(
___ ____ _  _ ___  _    ____ ___ ____    _  _ ____ _  _ ____ ____ ____ ____
 |  |___ |\/| |__] |    |__|  |  |___    |\/| |__| |\ | |__| | __ |___ |__/
 |  |___ |  | |    |___ |  |  |  |___    |  | |  | | \| |  | |__] |___ |  \

)" << endl;
    SetColor(7, 0);

}

void ConsoleApp::logoExit(){
    SetColor(10, 0);
    cout << R"(

_  _ ____ ___  ___  _   _    _  _ ____ ____ _  _ _ _  _ ____   /
|__| |__| |__] |__]  \_/     |__| |__| |    |_/  | |\ | | __  /
|  | |  | |    |      |      |  | |  | |___ | \_ | | \| |__] .


)" << endl;
    SetColor(7, 0);
    exit(0);
}

