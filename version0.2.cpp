#include <iostream>
#include <windows.h>
using namespace std;

void map1();
void loadingScreen();
void flag();
void printplayer();
void eraseplayer();

void printenemy1();
void eraseenemy1();
bool moveeU1();
bool moveeD1();
void moveenemy();
void moveenemyU1();
void moveenemyD1();
void eraseShell(int Sx, int Sy);
void printShell(int Sx, int Sy);
void moveShell(int Sx, int Sy);
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);


int pprx=10, ppry=12;
int eprx=10, epry=12;

int pex=75, pey=12;
int eex=75, eey=12;

bool movementup=false;

int m=0; 


main()
{
    
    loadingScreen();
    Sleep(400);
    map1();
    // printplayer();
    flag();
    bool fire=false;
    while(true)
    {
        int Sx=pprx+26, Sy=pprx+4;
        Sleep(100);
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (getCharAtxy(pprx, ppry+8) == ' ')
            {
                eraseplayer();
                ppry=ppry+1;
                printplayer();
                
            }
            Sleep(50);
        }    
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (getCharAtxy(pprx + 26, ppry) == ' ')
            {
                eraseplayer();
    			pprx = pprx + 1;
    			printplayer();
            }
            Sleep(20);
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (getCharAtxy(pprx - 1, ppry) == ' ')
            {
                eraseplayer();
   			   	pprx = pprx - 1;
  		        printplayer();
            }
            Sleep(20);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            if (getCharAtxy(pprx, ppry-1) == ' ')
            {
                eraseplayer();
                ppry=ppry-1;
                printplayer();
            }
            Sleep(50);
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            fire=true;
            Sx=pprx+26;
            Sy=ppry+4;
        }
        
        if(fire==true &&(getCharAtxy(Sx+1, Sy) == ' '))   
        {
            moveShell(Sx , Sy); 
        }
       
        moveenemy();
    }
}

void printplayer()
{    
    gotoxy(pprx, ppry);
    cout<<"                         "<<endl;    
    gotoxy(pprx, ppry+1);
    cout<<"  ____________           "<<endl;
    gotoxy(pprx, ppry+2);
    cout<<" |   ____     |          "<<endl;
    gotoxy(pprx, ppry+3);
    cout<<" |  |    |____|_________ "<<endl;
    gotoxy(pprx, ppry+4);
    cout<<" |  |     ______________ "<<endl;
    gotoxy(pprx, ppry+5);
    cout<<" |  |____|    |          "<<endl;
    gotoxy(pprx, ppry+6);
    cout<<" |____________|          "<<endl;
    gotoxy(pprx, ppry+7);
    cout<<"                         "<<endl;
}
void eraseplayer()
{
    gotoxy(eprx, epry);
    cout<<"                           "<<endl;
    gotoxy(eprx, epry+1);
    cout<<"                           "<<endl;
    gotoxy(eprx, epry+2);
    cout<<"                           "<<endl;
    gotoxy(eprx, epry+3);
    cout<<"                           "<<endl;
    gotoxy(eprx, epry+4);
    cout<<"                           "<<endl;
    gotoxy(eprx, epry+5);
    cout<<"                           "<<endl;
    gotoxy(eprx, epry+6);
    cout<<"                           "<<endl;
    gotoxy(eprx, epry+7);
    cout<<"                           "<<endl;
}
void printenemy1()
{
    gotoxy(pex, pey);
    cout<<"                 "<<endl;
    gotoxy(pex, pey+1);   
    cout<<"        _________  "<<endl;
    gotoxy(pex, pey+2);
    cout<<"       |   ____  | "<<endl;
    gotoxy(pex, pey+3);
    cout<<":::::::::::    | | "<<endl;
    gotoxy(pex, pey+4);
    cout<<"       |  |    | | "<<endl;
    gotoxy(pex, pey+5);
    cout<<":::::::::::____| | " <<endl;
    gotoxy(pex, pey+6);
    cout<<"       |_________| "<<endl;
    gotoxy(pex, pey+7);
    cout<<"                  "<<endl;
}
void eraseenemy1()
{
    gotoxy(eex, eey-1);
    cout<<"                     "<<endl;
    gotoxy(eex, eey);   
    cout<<"                     "<<endl;
    gotoxy(eex, eey+1);   
    cout<<"                     "<<endl;
    gotoxy(eex, eey+2);
    cout<<"                     "<<endl;
    gotoxy(eex, eey+3);
    cout<<"                     "<<endl;
    gotoxy(eex, eey+4);
    cout<<"                     "<<endl;
    gotoxy(eex, eey+5);
    cout<<"                     "<<endl;
    gotoxy(eprx, epry+6);
    cout<<"                     "<<endl;
    gotoxy(eprx, epry+7);
    cout<<"                     "<<endl;
    
}
void moveenemy()
{
    eraseenemy1();
    if(movementup)
    {
        pey--;
        if (pey<=2)
        {  
            movementup=false;
        }
    }
    else
    {
        pey++;
        if (pey>=21)
        {
            movementup=true;
        }
    }
    
    printenemy1();
}
void flag()
{
    gotoxy(120,23);
    cout<<"|\\"<<endl;
    gotoxy(120,24);
    cout<<"|/"<<endl;
    gotoxy(120,25);
    cout<<"|"<<endl;
    gotoxy(120,26);
    cout<<"|"<<endl;
}

void printShell(int Sx, int Sy)
{
    gotoxy(Sx, Sy);
    cout<<"*";
}
void eraseShell(int Sx, int Sy)
{
    gotoxy(Sx, Sy);
    cout<<"   ";
}
void moveShell(int Sx, int Sy)
{
    int x, y;

    x=Sx+m;
    y=Sy;
      // eraseShell(S, Sy); 
    m++;
    m++;
    printShell(x, y);
    Sleep(2);
    eraseShell(x, y); 
}

void map1()
{
    system("cls");
    cout<<" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@                                                                                                                              @@ "<<endl;
    cout<<" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ "<<endl;
   
}
void loadingScreen()
{
    int l=0;
    while(true)
    {
        
        system("cls");
        cout<<"                       ##############################################################################################  "<<endl;
        cout<<"                      ##############################################################################################  "<<endl;
        cout<<"                     ############################################################################################# "<<endl;
        cout<<"                           #######                                                 ######                 ######"<<endl;
        cout<<"                          #######         #######               #########         ######   ######      ######"<<endl;
        cout<<"                         #######        ##########             ###########       ######   ######    ######"<<endl;
        cout<<"                        #######       ###### ######           ###### ######     ######   ######  ######" <<endl;
        cout<<"                       #######      ######    ######         ######   ######   ######   ############   "<<endl;
        cout<<"                      #######     ###################       ######     ###### ######   ######   ###### "<<endl;
        cout<<"                     #######    ######          ######     ######       ###########   ######      ######"<<endl;
        cout<<"                    #######   ######             ######   ######         #########   ######         ######"<<endl;
        cout<<"                                                         ###### "<<endl;
        cout<<"           ###################################################   ###########          ############# #######             ######"<<endl;
        cout<<"          ###################################################     ############       ############# ##########         #########"<<endl;
        cout<<"         #####   #####             #####              ######     #####   ######     #####         #####  ######     #####    "<<endl;
        cout<<"        #####      #####         ########            ######     #####     ######   #####         #####     ###### #####      "<<endl;
        cout<<"       #####   #####           ##### #####          ######     #####       ###### #########     #####  ######    #####   "<<endl;
        cout<<"      ##########             #####    #####        ######     #####       ###### #####         ###########        #####   "<<endl;
        cout<<"     #####   #####         #################      ######     #####     ######   #####         #####   ######       #####"<<endl;
        cout<<"    #####      #####     #####          #####    ######     #####   ######     ############# #####      ######      #####"<<endl;
        cout<<"   #####         ##### #####             ##### ######### #############        ############# #####         ######     #####"<<endl;
        cout<<"                                                                                                                      #####"<<endl;
        cout<<" ########################################################################################################################   "<<endl; 
        cout<<"#######################################################################################################################     "<<endl; 
        cout<<" "<<endl;
        cout<<"                                                  Loading: "<<l<<"%";
        l++;
        if (l==101)
        {
            break;
        }

    }
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}