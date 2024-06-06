//For MyList logic: The Destructor is automatically called if the list is not constantly reloaded
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "GachaFile.h"

void ShowMenu(int, int, int, std::string, std::string);
void BoxMenu();
void IdolMenu();
void ChangeRate(int&, int&, int&);
char Gacha(int, int&, int&, int&, int, int, int);
bool Display();
void LoadCards(char, vector<int>&, std::string, vector<int>, vector<int>, vector<int>, GachaFile);

int main()
{
    int x{ 0 };
    char menu{ 'a' };
    int total_UR{ 0 };
    int total_SR{ 0 };
    int total_R{ 0 };
    int UR_rate{ 1 };
    int SR_rate{ 10 };
    int R_rate{ 10 };
    int Display_UR{ 1 };
    int Display_SR{ 9 };
    int Display_R{ 90 };
    vector<int> cardNumber;
    vector<int> kayArray;
    vector<int> URList;
    vector<int> SRList;
    vector<int> RList;
    cardNumber = {};
    int size{ 0 };
    std::string toggle = "ON";
    std::string box = "Main";
    GachaFile myList;
    myList.ReadFile("myList cards.txt");
    int mySize;
    mySize = myList.GetSize();
    srand(time(0));
    int totalSize{ 0 };

    for (int i = 0; i < mySize; i++) {
        if (myList[i]->GetRarity() == "UR") {
            URList.push_back(myList[i]->GetNumber());
        }
    }

    for (int i = 0; i < mySize; i++) {
        if (myList[i]->GetRarity() == "SR") {
            SRList.push_back(myList[i]->GetNumber());
        }
    }

    for (int i = 0; i < mySize; i++) {
        if (myList[i]->GetRarity() == "R") {
            RList.push_back(myList[i]->GetNumber());
        }
    }

    do {
        std::cout << "\n";
        ShowMenu(Display_UR, Display_SR, Display_R, toggle, box);
        std::cout << "\n>: ";
        std::cin >> menu;
        menu = toupper(menu);
        char rare{ 'y' };
        char boxMenu{ 'n' };
        char idol{ 'z' };
        switch (menu) {

        case 'S':
            while (menu != 'n') {
                int UR{ 0 };
                int SR{ 0 };
                int R{ 0 };
                int i{ 0 };
                std::cout << "Press any key to Scout! ";
                std::cin >> menu;
                std::cout << "\n";

                
                while (i < 10) {
                    rare = Gacha(x, UR, SR, R, UR_rate, SR_rate, R_rate);
                    LoadCards(rare, cardNumber, toggle, RList, SRList, URList, myList);
                    i = i + 1;
                }

                std::cout << "\n";
                if (UR > 0) {
                    std::cout << "You received " << UR << " UR's!" << std::endl;
                    total_UR = total_UR + UR;
                }
                if (SR > 0) {
                    std::cout << "You received " << SR << " SR's!" << std::endl;
                    total_SR = total_SR + SR;
                }
                if (R > 0) {
                    std::cout << "You received " << R << " R's!" << std::endl;
                    total_R = total_R + R;
                }
                
                std::cout << "\nWould you like to scout again? (y/n) ";
                std::cin >> menu;
            }
            break;

        case 'C':
            ChangeRate(UR_rate, SR_rate, R_rate);
            Display_UR = UR_rate;
            if (SR_rate == 0) {
                Display_SR = 0;
            }
            else if (SR_rate > UR_rate) {
                Display_SR = SR_rate - UR_rate;
            }
            else if (SR_rate <= UR_rate) {
                Display_SR = UR_rate - SR_rate;
            }
            Display_R = 100 - (UR_rate + Display_SR);
            break;

        case 'D':
            if (Display() == true) {
                toggle = "ON";
            }
            else {
                toggle = "OFF";
            }
            break;

        case 'F':
            std::cout << "\n";
            BoxMenu();
            std::cout << "\n>: ";
            std::cin >> boxMenu;
            boxMenu = toupper(boxMenu);
            switch (boxMenu) {
            case 'P':
                std::cout << "\nYou chose Printemps!";
                box = "Printemps";
                break;

            case 'B':
                std::cout << "\nYou chose BiBi!";
                box = "BiBi";
                break;

            case 'L':
                std::cout << "\nYou chose Lily White!";
                box = "Lily White";
                break;

            case 'F':
                std::cout << "\nYou chose First-Years!";
                box = "First-Years";
                break;

            case 'S':
                std::cout << "\nYou chose Second-Years!";
                box = "Second-Years";
                break;

            case 'T':
                std::cout << "\nYou chose Third-Years!";
                box = "Third-Years";
                break;

            case 'I':
                std::cout << "\nYou chose Individual Scouting";
                IdolMenu();
                std::cout << "\n>: ";
                std::cin >> idol;
                idol = toupper(idol);
                switch (idol) {
                case 'H':
                    std::cout << "\nYou chose Honoka Scouting";
                    box = "Honoka";
                    break;

                case 'E':
                    std::cout << "\nYou chose Eri Scouting";
                    box = "Eri";
                    break;

                case 'K':
                    std::cout << "\nYou chose Kotori Scouting";
                    box = "Kotori";
                    break;

                case 'U':
                    std::cout << "\nYou chose Umi Scouting";
                    box = "Umi";
                    break;

                case 'R':
                    std::cout << "\nYou chose Rin Scouting";
                    box = "Rin";
                    break;

                case 'M':
                    std::cout << "\nYou chose Maki Scouting";
                    box = "Maki";
                    break;

                case 'N':
                    std::cout << "\nYou chose Nozomi Scouting";
                    box = "Nozomi";
                    break;

                case 'P':
                    std::cout << "\nYou chose Hanayo Scouting";
                    box = "Hanayo";
                    break;

                case 'Y':
                    std::cout << "\nYou chose Niko Scouting";
                    box = "Niko";
                    break;

                default:
                    std::cout << "\nInvalid input";
                    std::cout << "\nGoing back to the menu";
                    break;
                }

                break;

            case 'A':
                std::cout << "\nYou chose Default Box!";
                box = "Main";
                break;

            default:
                std::cout << "\nInvalid input";
                std::cout << "\nGoing back to the menu";
                break;
            }
            break;

        case 'L':

            size = cardNumber.size();
            kayArray.resize(size);

            for (int i = 0; i < size; i++) {
                int k{ 1 };
                if (cardNumber[i] != 0) {
                    for (int j = i + 1; j < size; j++) {
                        if (cardNumber[j] == cardNumber[i]) {
                            k = k + 1;
                            cardNumber[j] = 0;
                        }
                    }
                    kayArray[i] = k;
                }
            }

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < mySize; j++) {
                    if (cardNumber[i] == myList[j]->GetNumber()) {
                        std::cout << myList[j]->toString();
                        std::cout << " x" << kayArray[i] << std::endl;
                    }
                }
            }
            break;

        case 'V':
            std::cout << "You have " << total_UR << " Ultra-Rare(s)" << std::endl;
            std::cout << "You have " << total_SR << " Super-Rare(s)" << std::endl;
            std::cout << "You have " << total_R << " Rare(s)" << std::endl;
            break;

        case 'Q':
            std::cout << "\nThanks for scouting!";
            break;

        default:
            std::cout << "Invalid Input" << std::endl;
            std::cout << "Please try again" << std::endl;
            break;
        }
    } while (menu != 'Q');
}

void ChangeRate(int& UR_rate, int& SR_rate, int& R_rate) {
    std::cout << "\nPlease indicate what you want the Ultra-Rare rate to be: " << std::endl;
    std::cin >> UR_rate;
    std::cout << "Please indicate what you want the Super-Rare rate to be: " << std::endl;
    std::cin >> SR_rate;
    std::cout << "Please indicate what you want the Rare rate to be: " << std::endl;
    std::cin >> R_rate;
    if (UR_rate + SR_rate + R_rate != 100) {
        std::cout << "\nThe total number must be 100, please try again." << std::endl;
        ChangeRate(UR_rate, SR_rate, R_rate);
    }
    if (UR_rate + SR_rate + R_rate == 100) {
        if (SR_rate == 0) {
            SR_rate = 0;
            R_rate = UR_rate;
        }
        else {
            SR_rate = UR_rate + SR_rate;
            R_rate = SR_rate;
        }
    }
}

char Gacha(int x, int& UR, int& SR, int& R, int UR_rate, int SR_rate, int R_rate) {
    x = 1 + rand() % 100;
    if (x <= UR_rate) {
        UR = UR + 1;
        return 'U';
    }
    if ((x <= SR_rate) && (x > UR_rate)) {
        SR = SR + 1;
        return 'S';
    }
    if (x > R_rate) {
        R = R + 1;
        return 'R';
    }
}

bool Display() {
    char choice{ 'n' };
    std::cout << "\nWould you like to display the cards you received during scouting? (y/n)" << std::endl;
    std::cin >> choice;
    if (choice == 'y') {
        std::cout << "\nYou decided to Display the cards";
        return true;
    }
    if (choice == 'n') {
        std::cout << "\nYou decided not to Display the cards";
        return false;
    }
    else {
        std::cout << "\n Invalid input. Indicate your answer with y or n." << std::endl;
        Display();
    }
}

void ShowMenu(int Display_UR, int Display_SR, int Display_R, std::string toggle, std::string box) {
    std::cout << "\n********** Welcome to the Gacha **********";
    std::cout << "\n\tYour current scouting rates are: ";
    std::cout << "\n\t\t" << Display_UR << "%" << "\tFor Ultra-Rare";
    std::cout << "\n\t\t" << Display_SR << "%" << "\tFor Super-Rare";
    std::cout << "\n\t\t" << Display_R << "%" << "\tFor Rare";
    std::cout << "\n\t Your current display is set to: " << toggle;
    std::cout << "\n\t Your current scouting is set to: " << box;
    std::cout << "\n\n********** Please make the following selection **********";
    std::cout << "\n\tS \tScouting";
    std::cout << "\n\tC \tChange Scouting Rates";
    std::cout << "\n\tD \tChange Display Setting";
    std::cout << "\n\tF \tFilter Cards Scouting";
    std::cout << "\n\tL \tList all Cards received";
    std::cout << "\n\tV \tView Card Amount";
    std::cout << "\n\tQ \tQuit Program";
}

void BoxMenu() {
    std::cout << "\n\n********** Please select the new scouting box **********";
    std::cout << "\n\tP \tPrintemps-only Scouting";
    std::cout << "\n\tB \tBiBi-only Scouting";
    std::cout << "\n\tL \tLily White-only Souting";
    std::cout << "\n\tF \tFirst-Year - only Scouting";
    std::cout << "\n\tS \tSecond-Year only Scouting";
    std::cout << "\n\tT \tThird-Year only Scouting";
    std::cout << "\n\tI \tFor Individual Idol Scouting";
    std::cout << "\n\tA \tAll available for Scouting";
}

void IdolMenu() {
    std::cout << "\n\n********** Please select the new scouting box **********";
    std::cout << "\n\tH \tHonoka only Scouting";
    std::cout << "\n\tE \tEri only Scouting";
    std::cout << "\n\tK \tKotori only Scouting";
    std::cout << "\n\tU \tUmi only Scouting";
    std::cout << "\n\tR \tRin only Scouting";
    std::cout << "\n\tM \tMaki only Scouting";
    std::cout << "\n\tN \tNozomi only for Scouting";
    std::cout << "\n\tP \tHanayo only for Scouting";
    std::cout << "\n\tY \tNiko only for Scouting";
}

void LoadCards(char rare, vector<int>& cardNumber, std::string toggle, vector<int> RList, vector<int> SRList, vector<int> URList, GachaFile myList) {
    int x{ 0 };
    int URSize{ 0 };
    int SRSize{ 0 };
    int RSize{ 0 };

    URSize = URList.size();
    SRSize = SRList.size();
    RSize = RList.size();

    //Random card algorithm
    if (rare == 'U') {
        x = rand() % URSize;
        cardNumber.push_back(URList[x]);
        if (toggle == "ON") {
            std::cout << myList[cardNumber.back()]->toString() << std::endl;
        }
        if (toggle == "OFF") {
            std::cout << "You got an UR!" << std::endl;
        }
    }
    else if (rare == 'S') {
        x = rand() % SRSize;
        cardNumber.push_back(SRList[x]);
        if (toggle == "ON") {
            std::cout << myList[cardNumber.back()]->toString() << std::endl;
        }
        if (toggle == "OFF") {
            std::cout << "You got an SR!" << std::endl;
        }
    }
    else if (rare == 'R') {
        x = rand() % RSize;
        cardNumber.push_back(RList[x]);
        if (toggle == "ON") {
            std::cout << myList[cardNumber.back()]->toString() << std::endl;
        }
        if (toggle == "OFF") {
            std::cout << "You got an R!" << std::endl;
        }
    }
}