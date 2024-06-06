//Fix filtering by using vectors. Then comment the code
/*
    It's not calling my constructor, make a individual call thing with new. 
    New Gacha(
*/
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
bool Display();
void Filter(char, char, vector<int>&, vector<int>&, vector<int>&, GachaFile);
void PrintList(vector<int>, vector<int>, vector<int>, GachaFile);

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
        if (myList[i]->GetRarity() == "SR") {
            SRList.push_back(myList[i]->GetNumber());
        }
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

        switch(menu) {

        case 'S':
            while (menu != 'n') {
                int UR{ 0 };
                int SR{ 0 };
                int R{ 0 };
                int i{ 0 };
                std::cout << "Press any key to Scout! ";
                std::cin >> menu;
                std::cout << "\n";

                char rare{ 'm' };

                int y{ 0 };
                int URSize{ 0 };
                int SRSize{ 0 };
                int RSize{ 0 };

                URSize = URList.size();
                SRSize = SRList.size();
                RSize = RList.size();

                GachaFile myList;
                myList.ReadFile("myList cards.txt");
                int mySize;
                mySize = myList.GetSize();


                while (i < 10) {
                    x = 1 + rand() % 100;
                    if (x <= UR_rate) {
                        UR = UR + 1;
                        rare = 'U';
                    }
                    if ((x <= SR_rate) && (x > UR_rate)) {
                        SR = SR + 1;
                        rare = 'S';
                    }
                    if (x > R_rate) {
                        R = R + 1;
                        rare = 'R';
                    }

                    //Random card algorithm
                    if (rare == 'U') {
                        y = rand() % URSize;//chooses a random number between 1 and URSize
                        cardNumber.push_back(URList[y]);//Whichever card corresponds to that index
                        if (toggle == "ON") {
                            std::cout << myList[cardNumber.back()]->toString() << std::endl;//Spits out the most recent entry. CardNumber is full btw, every card goes into cardnumber
                        }
                        if (toggle == "OFF") {
                            std::cout << "\nYou received an UR!";
                        }
                    }
                    else if (rare == 'S') {
                        y = rand() % SRSize;
                        cardNumber.push_back(SRList[y]);
                        if (toggle == "ON") {
                            std::cout << myList[cardNumber.back()]->toString() << std::endl;
                        }
                        if (toggle == "OFF") {
                            std::cout << "\nYou received an SR!";
                        }
                    }
                    else if (rare == 'R') {
                        y = rand() % RSize;
                        cardNumber.push_back(RList[y]);
                        if (toggle == "ON") {
                            std::cout << myList[cardNumber.back()]->toString() << std::endl;
                        }
                        if (toggle == "OFF") {
                            std::cout << "\nYou received an R!";
                        }
                    }
                    i = i + 1;
                }

                std::cout << "\n";
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
            cardNumber.clear();
            cardNumber.resize(0);
            switch (boxMenu) {
            case 'P':
                std::cout << "\nYou chose Printemps!";
                box = "Printemps";
                Filter(idol, boxMenu, URList, SRList, RList, myList);
                break;

            case 'B':
                std::cout << "\nYou chose BiBi!";
                box = "BiBi";
                Filter(idol, boxMenu, URList, SRList, RList, myList);
                break;

            case 'L':
                std::cout << "\nYou chose Lily White!";
                box = "Lily White";
                Filter(idol, boxMenu, URList, SRList, RList, myList);
                break;

            case 'F':
                std::cout << "\nYou chose First-Years!";
                box = "First-Years";
                Filter(idol, boxMenu, URList, SRList, RList, myList);
                break;

            case 'S':
                std::cout << "\nYou chose Second-Years!";
                box = "Second-Years";
                Filter(idol, boxMenu, URList, SRList, RList, myList);
                break;

            case 'T':
                std::cout << "\nYou chose Third-Years!";
                box = "Third-Years";
                Filter(idol, boxMenu, URList, SRList, RList, myList);
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
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'E':
                    std::cout << "\nYou chose Eri Scouting";
                    box = "Eri";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'K':
                    std::cout << "\nYou chose Kotori Scouting";
                    box = "Kotori";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'U':
                    std::cout << "\nYou chose Umi Scouting";
                    box = "Umi";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'R':
                    std::cout << "\nYou chose Rin Scouting";
                    box = "Rin";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'M':
                    std::cout << "\nYou chose Maki Scouting";
                    box = "Maki";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'N':
                    std::cout << "\nYou chose Nozomi Scouting";
                    box = "Nozomi";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'P':
                    std::cout << "\nYou chose Hanayo Scouting";
                    box = "Hanayo";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
                    break;

                case 'Y':
                    std::cout << "\nYou chose Niko Scouting";
                    box = "Niko";
                    Filter(idol, boxMenu, URList, SRList, RList, myList);
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
                Filter(idol, boxMenu, URList, SRList, RList, myList);
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
                if (cardNumber[i] != -1) {
                    for (int j = i + 1; j < size; j++) {
                        if (cardNumber[j] == cardNumber[i]) {
                            k = k + 1;
                            cardNumber[j] = -1;
                        }
                    }
                    kayArray[i] = k;
                }
            }

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < mySize; j++) {
                    if (cardNumber[i] == myList[j]->GetNumber()) {
                        std::cout << myList[j]->toString();
                        std::cout << " x" << kayArray[i]<< std::endl;
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

        case 'X':
            std::cout << "\nDisplaying Cards in Scouting box";
            PrintList(URList, SRList, RList, myList);
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

void Filter(char idol, char box, vector<int>& URList, vector<int>& SRList, vector<int>& RList, GachaFile myList) {
    int mySize{ 0 };
    mySize = myList.GetSize();
    URList.clear();
    SRList.clear();
    RList.clear();
    URList.resize(0);
    SRList.resize(0);
    RList.resize(0);

    //Honoka if
    if ((box == 'P') || (box == 'S') || (idol == 'H')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Honoka") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Eri if 
    if ((box == 'B') || (box == 'T') || (idol == 'E')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Eri") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Kotori if 
    if ((box == 'P') || (box == 'S') || (idol == 'P')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Kotori") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Umi if 
    if ((box == 'L') || (box == 'S') || (idol == 'U')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Umi") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Rin if 
    if ((box == 'L') || (box == 'F') || (idol == 'R')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Rin") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Maki if 
    if ((box == 'B') || (box == 'F') || (idol == 'M')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Maki") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Nozomi if 
    if ((box == 'L') || (box == 'T') || (idol == 'N')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Nozomi") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Hanayo if 
    if ((box == 'P') || (box == 'F') || (idol == 'P')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Hanayo") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }
    //Niko if 
    if ((box == 'B') || (box == 'T') || (idol == 'Y')) {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetName() == "Niko") {
                if (myList[i]->GetRarity() == "UR") {
                    URList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "SR") {
                    SRList.push_back(myList[i]->GetNumber());
                }
                if (myList[i]->GetRarity() == "R") {
                    RList.push_back(myList[i]->GetNumber());
                }
            }
        }
    }

    if (box == 'A') {
        for (int i = 0; i < mySize; i++) {
            if (myList[i]->GetRarity() == "UR") {
                URList.push_back(myList[i]->GetNumber());
            }       
            if (myList[i]->GetRarity() == "SR") {
                SRList.push_back(myList[i]->GetNumber());
            }
            if (myList[i]->GetRarity() == "R") {
                RList.push_back(myList[i]->GetNumber());
            }
        }
    }
}\

void PrintList(vector<int> URList, vector<int> SRList, vector<int> RList, GachaFile myList) {
    int URSize{ 0 };
    int SRSize{ 0 };
    int RSize{ 0 };
    int mySize{ 0 };

    URSize = URList.size();
    SRSize = SRList.size();
    RSize = RList.size();
    mySize = myList.GetSize();

    std::cout << "\nThe contents of URList";
    for (int i = 0; i < URSize; i++) {
        for (int j = 0; j < mySize; j++) {
            if (URList[i] == myList[j]->GetNumber()) {
                std::cout << myList[j]->toString();
            }
        }
    }
    std::cout << "\nThe contents of SRList";
    for (int i = 0; i < SRSize; i++) {
        for (int j = 0; j < mySize; j++) {
            if (SRList[i] == myList[j]->GetNumber()) {
                std::cout << myList[j]->toString();
            }
        }
    }
    std::cout << "\nThe contents of RList";
    for (int i = 0; i < RSize; i++) {
        for (int j = 0; j < mySize; j++) {
            if (RList[i] == myList[j]->GetNumber()) {
                std::cout << myList[j]->toString();
            }
        }
    }
}