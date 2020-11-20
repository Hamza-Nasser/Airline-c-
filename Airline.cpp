#include<iostream>
#include<iomanip>
int id1, id2;
using namespace std;
void print(char theclass[][6], int listseat[15], int rows); /* this function prints the class */
void choicefune(char classfoe[][6], int listseat[15],int rows);
void addpass(char first_class[5][6], char economy_class[15][6], int listseat[15]);
void deletreservation(char classfoe[][6]);
int main(){
    int letters=0, userchoice=0, backhome, listseat[15];
    /* assignment the first seat and it's appearance depending on ASCII table */
    char first_class[5][6];
    for (int i = 0; i < 6; i++){
        /* to make a list that shows from 1 to 6, but here we'll use just to 5 */
        listseat[i] = 1 + i;
        for (int j = 0; j < 5; j++){ 
            /* to assign A B C D E F the A will be assigned when the first column comes and B when second one does and so on */
            first_class[j][i] = 'A' + letters;
        }
        letters++;
    }
    letters = 0;
    /* declaring the economy class at the same way */
    char economy_class[15][6];
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 15; j++){
            if(i == 0){
                if(j >= 6)
                /* continue the assignment of the list starts from 7, ends when 15*/
                listseat[j] = 1 + j;
            }
            economy_class[j][i] = 'A' + letters;
        }
        letters++;
    }
    do{
    cout<<"Press 1 to add passengers \n";
    cout<<"Press 2 to show seating \n";
    cout<<"Press 3 to delete reservation \n";
    cout<<"Press any other key to quit \n";
    cin>>userchoice;
    switch(userchoice){
        case 1:
            /* add passengers */
            addpass(first_class, economy_class, listseat);
            break;
        case 2:
            /* show seating */
            int show_foe;
            cout<<"For first class press 1, for economy one presss 2: ";
            cin>>show_foe;
            /* error type handling with inputs */
            for (int i = 0; i < 1; i++){
                if(!(show_foe == 1 || show_foe == 2)){
                    cout<<"Please, Enter a valid value.\n";
                    cout<<"For first class press 1, for economy one presss 2: ";
                    cin>>show_foe;
                    i--;
                }
            }
            switch (show_foe){
            case 1:
                /* print the first class */
                print(first_class, listseat, 5);
                break;
            case 2:
                /* prints the economy one */
                print(economy_class, listseat, 15);
                break;
            }
            break;
        case 3: 
            /* delet reservation of either first or economy class*/ 
            int dfoe;
            cout<<"First or economy? for first press 1 for economy press 2: ";
            cin>>dfoe;
            for (int i = 0; i < 1; i++){
                if(dfoe != 1 && dfoe != 2){
                    cout<<"Please Enter a valid value."<<endl;
                    cin>>dfoe;
                    i--;
                }
            }
                switch (dfoe){
                case 1:
                    deletreservation(first_class);
                    break;
                case 2:
                    deletreservation(economy_class);
                    break;
                }          
    }
    cout<<"Back Home Press 1, any other key for Exit: ";
    cin>>backhome;
    }while(backhome == 1);
    system("pause");
    return 0;
} /* This function will do the same but in the economy class */
void choicefune(char classfoe[][6], int listseat[15], int rows){
    int seate;
    cin>>seate;
    char seatletter;
    cin>>seatletter;
    for (int i = 0; i < 1; i++){
        if(!(seatletter <= 'F' && seatletter >= 'A') || !(seate <= 15 && seate >= 1)){
            cout<<"Please Enter a valid value: ";
            cin>>seate>>seatletter;
            i--;
        }
    }
    for (int i = 0; i < rows; i++){
        /* listing seat recognition */
        if(seate == listseat[i]){
            for (int j = 0; j < 6; j++){
                if(seatletter == 'A' + j && classfoe[i][0 + j] == 'X'){
                        cout<<"Already occupied"<<endl;
                        cout<<"Enter the seat: ";
                        choicefune(classfoe, listseat, rows);
                }        
                if(classfoe[i][j] == seatletter){
                    classfoe[i][j] = 'X';
                    if(rows == 5){
                        id1 = i;
                        id2 = j;
                    }else {
                        id1 = i + 5;
                        id2 = j;
                    }
                    break;
                }
            }
        }
    }
}
void print(char theclass[][6], int listseat[15], int rows){
    for (int i = 0; i < rows; i++){
        cout<<setw(2)<<listseat[i]<<"|  ";
        for (int j = 0; j < 6; j++){
            cout<<theclass[i][j]<<"  ";   
        }   
    cout<<endl;
    }
}
void deletreservation(char classfoe[][6]){
    int id[2], separation;
    cout<<"Please Enter your id: ";
    cin>>separation;
    id[0] = separation / 10;
    if(id[0] > 5){
        id[0] -= 5;
    }                        /* this step will do that: if input = 141,we want 14 to be the first number and 1 be the second */
    id[1] = separation % 10;
    /* making 14 indicates to the index of row and 1 to the index of column then,
    if the arr[14][1] = 'X' it will be return to the first value wether it was A, B, D, E or F
    if it doesn't equal 'X' that is mean this is a wrong id */
    if(classfoe[id[0]][id[1]] == 'X'){
        switch(id[1]){
            case 0:
            classfoe[id[0]][id[1]] = 'A';
            break;
            case 1:
            classfoe[id[0]][id[1]] = 'B';
            break;
            case 2:
            classfoe[id[0]][id[1]] = 'C';
            break;
            case 3:
            classfoe[id[0]][id[1]] = 'D';
            break;
            case 4:
            classfoe[id[0]][id[1]] = 'E';
            break;
            case 5:
            classfoe[id[0]][id[1]] = 'F';
            break;
        }   
        cout<<"Done"<<endl;
    }else {
        int exit = 0;
        cout<<"This id is invalid, press 1 to re-enter the seat id or any other key to back home: "<<endl;
        cin>>exit;
        if(exit == 1){
            deletreservation(classfoe); 
        } 
    }
}
void addpass(char first_class[5][6], char economy_class[15][6], int listseat[15]){
    int foe = 0, sod=0;
    cout<<"For first class press 1, for economy one presss 2: ";
    cin>>foe;
    /* handling with the type error */
    for (int i = 1; i < 2; i++){
        if(!(foe == 1 || foe == 2)){
            cout<<"Please, Enter a valid value.\n";
            cout<<"For first class press 1, for economy one presss 2: ";
            cin>>foe;
            i--;
        }
    }
    switch (foe){
    case 1:
        cout<<"Single OR double. for single press 1, for double press 2:";
        cin>>sod;
        for (int i = 0; i < 1; i++){
            /* also handling with the type error */
            if(!(sod == 1 || sod == 2)){
                cout<<"Please, Enter a valid value.\n";
                cout<<"for single press 1, for double press 2:";
                cin>>sod;
                i--;
            }
        }
        /* a prototype for the chosen seat */
        cout<<"\nNotice that! every \"A\" and \"F\" seat is beside the window\n";
        switch (sod){
        case 1:
            print(first_class, listseat, 5);
            cout<<"Enter the seat you want like (1E): ";
            choicefune(first_class, listseat, 5);
            print(first_class, listseat, 5);
            cout<<"Your id is: "<<id1<<id2<<endl;
            break;
        case 2:
            print(first_class, listseat, 5);
            cout<<"Enter the first seat (like 1A): ";
            choicefune(first_class, listseat, 5);
            cout<<"Your first id is: "<<id1<<id2<<endl;
            cout<<"Enter the second seat (like 2B): ";
            choicefune(first_class, listseat, 5);
            cout<<"Your second id is: "<<id1<<id2<<endl;
            print(first_class, listseat, 5);
            break;
        }
        break;
    case 2:
        cout<<"Single, double or trible? for single press 1, double press 2, trible press 3:";
        int sodot;
        cin>>sodot;
        for (int i = 0; i < 1; i++){
           if(!(sodot >= 1 && sodot <= 3)){
                cout<<"Please, Enter a valid value. "<<endl;
                cout<<"for single press 1, double press 2, trible press 3:";
                cin>>sodot;
                i--;
           } 
        }
        switch(sodot){
        case 1:
            print(economy_class, listseat, 15);
            cout<<"Enter the seat you want like (14A): ";
            choicefune(economy_class, listseat, 15);
            print(economy_class, listseat, 15);
            cout<<"Your seat id is "<<id1<<id2<<endl;
            break;
        case 2:
            print(economy_class, listseat, 15);
            cout<<"Enter the first seat (like 1A): "<<endl;
            choicefune(economy_class, listseat, 15);
            cout<<"Your first seat id is "<<id1<<id2<<endl;
            cout<<"Enter the second seat (like 2B): ";
            choicefune(economy_class, listseat, 15);
            print(economy_class, listseat, 15);
            cout<<"Your second seat id is "<<id1<<id2<<endl;
            break;
        case 3:
            print(economy_class, listseat, 15);
            cout<<"Enter the first seat (like 1A): ";
            choicefune(economy_class, listseat, 15);
            cout<<"Your first seat id is "<<id1<<id2<<endl;
            cout<<"Enter the second seat (like 2B): ";
            choicefune(economy_class, listseat, 15);
            cout<<"Your second seat id is "<<id1<<id2<<endl;
            cout<<"Enter the third seat (like 3C): ";
            choicefune(economy_class, listseat, 15);
            print(economy_class, listseat, 15);
            cout<<"Your third seat id is "<<id1<<id2<<endl;
            break;
        }
        break;
    }
}