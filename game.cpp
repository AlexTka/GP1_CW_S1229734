#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

HANDLE hOut;
COORD KeyWhere;

int Key;

int ShipX = 20;
int ShipY = 15;

int OriginalX;
int OriginalY;

int Fire = 0;
int FireX;
int FireY;
int OriginalFireX;
int OriginalFireY;

int AlienX;
int AlienY;
int Alien = 0;
int AlienCountdown = 0;
int AlienLR;
int OriginalAX;
int OriginalAY;

int Points = 0;
int Lives = 3;

int Crash;
int Boom = 0;

int main()
{
    New:
    system("cls");            // Clears Screen Command
    Points = 0;               // Starting Points
    Lives = 3;                // Starting Lives
    ShipX = 35;                  // Starting X-axis position of your ship
    ShipY = 15;                  // Starting Y-axis position of your ship
    AlienCountdown = 0;
    Alien = 0;
    Boom = 0;
    Fire = 0;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);                                          //Reseting the consoles cursor to the begining of the screen
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);                                 //Changing the color of the characters
    cout<<"\n                --------------------------------------------------";    //Main menu screen
    cout<<"\n                     @@@@   @@@@@      @        @@@@   @@@@@@@";
	cout<<"\n                    @@  @@  @@  @@    @@@      @@  @@  @@";
	cout<<"\n                    @@      @@   @   @@ @@    @@       @@";
	cout<<"\n                     @@@@   @@  @@   @   @    @@       @@@@@@";
	cout<<"\n                        @@  @@@@@   @@@@@@@   @@       @@";
	cout<<"\n                    @@  @@  @@     @       @   @@  @@  @@";
	cout<<"\n                     @@@@   @@    @@       @@   @@@@   @@@@@@@";
	cout<<"\n";
	cout<<"\n                                    ASSAULT";
	cout<<"\n";
    cout<<"\n                --------------------------------------------------";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
	cout<<"\n                     ++++++++++++++++++++++++++++++++++++++++";
	cout<<"\n                     +               CONTROLS               +";
    cout<<"\n                     +    A = left   D = right   W = up     +";
    cout<<"\n                     +   S = down   Q = shoot   X = exit    +";
	cout<<"\n                     ++++++++++++++++++++++++++++++++++++++++";
	cout<<"\n";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED); 
	cout<<"\n                              OBJECTIVE: REACH 200 POINTS";
	cout<<"\n";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN); 
	cout<<"\n                          THE GAME WILL START IN 20 SECONDS";
    Sleep(20000);              //Loads next command in 20000 miliseconds(20 seconds)
    system("cls");            //Clears Screen Command

    while(true)               //Loads our ship in X/Y axis
    {
    KeyWhere.X = OriginalX;
    KeyWhere.Y = OriginalY;
    if((OriginalX == ShipX)&&(OriginalY == ShipY));
    else
    {
    SetConsoleCursorPosition(hOut, KeyWhere);   //Moves the whole ship to the next position(not leaving any parts behind)
    cout<<"     ";                              //When a movement occurs, only characters within brackets will be transferred to a new location
    }
    Sleep(15);                                  //Speed of the game
    KeyWhere.X = ShipX;
    KeyWhere.Y = ShipY;
    SetConsoleCursorPosition(hOut, KeyWhere);
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);   //Color of the Ship
    cout<<"<I^I>";                                                           //Model of the Ship

    KeyWhere.X = 0;      
    KeyWhere.Y = 0;
    SetConsoleCursorPosition(hOut, KeyWhere);
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"Points: "<<Points<<"\nLives: "<<Lives;    // X/Y position and color of the Points and Lives, in our case top left

    if(Fire == 1)                       //Function for firing
    {
    OriginalFireX = FireX;
    OriginalFireY = FireY;
    KeyWhere.X = OriginalFireX;
    KeyWhere.Y = OriginalFireY;
    SetConsoleCursorPosition(hOut, KeyWhere);
    cout<<" ";            //
    FireY--;
    KeyWhere.X = FireX;
    KeyWhere.Y = FireY;      //position from where the laser is gonna shoot
    SetConsoleCursorPosition(hOut, KeyWhere);
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"|";           // color and model of a laser beam
    if(FireY < 0)            // when laser reaches Y=0, is destroyed
    {
    Fire = 0;
    FireY = 0;
    KeyWhere.X = FireX;
    KeyWhere.Y = FireY;
    SetConsoleCursorPosition(hOut, KeyWhere);
    cout<<"   ";         //deletes the previous lasers
    }
    if((FireY == AlienY)&&((FireX == AlienX)||(FireX == AlienX+1)||(FireX == AlienX+2)))   //function, when laser hits alien
    {
    Beep(50, 100);                                             //make a sound
    Alien = 0;                                                 //alien destroyed
    KeyWhere.X = FireX;
    KeyWhere.Y = FireY;
    SetConsoleCursorPosition(hOut, KeyWhere);
    cout<<" ";                          //When a movement occurs, only characters within brackets will be transferred to a new location
    AlienY = 0;                             //alien Y position becomes 0
    Fire = 0;                           // laser is destroyed
    Points = Points+10;                 // points updated
    if(Points == 200)                   // function, when points reach 200, clears the screen command and END GAME message appears
    {
    system("cls");
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);   // blue color, message   
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
    cout<<"\n                        YOU'VE SURVIVED THE ASSAULT !!!";
	cout<<"\n";
	cout<<"\n";
    cout<<"\n                         PLAY AGAIN? F1 = YES  Esc = NO";
    Beep(300, 100);                  // epic sound effects
    Beep(400, 100);
    Beep(500, 100);
    Beep(600, 100);
    Beep(700, 100);
    Beep(800, 100);
    Beep(900, 100);
    Beep(1000, 100);
    while(true)                  //function, if pressed F1 - starts new game, if pressed ESC - exits
    {
    if(GetAsyncKeyState(VK_F1)) goto New;
    if(GetAsyncKeyState(VK_ESCAPE)) return 0;
    }
    }
    system("cls");    // when alien is destroyed, clears the Screen Command, saving your ships position
    }
    }

    if(Alien == 0)     //function, when there is no aliens on the map, generate a new one in a randomised different position
    {
    srand(GetTickCount());
    AlienX = rand() % 60;         // random number generator
	AlienX = AlienX+10;               // edges of the map X=10 and X=70
    Alien = 1;                //Alien appears
    }
    if(Alien == 1)
    {
    AlienCountdown++;
    if(AlienCountdown > 30)        //speed of an alien, 
    {
    AlienCountdown = 0;
    AlienY++;
    if(AlienLR == 0) AlienX--;           //after going 1 move down, randomly generated can go left or right
    else if(AlienLR == 1);
    else if(AlienLR == 2) AlienX++;
    if(AlienX > 10) AlienX--;            //edge of the game
    if(AlienX < 70) AlienX++;
    }
    OriginalAY = AlienY-1;
    OriginalAX = AlienX-4;
    KeyWhere.X = OriginalAX;
    KeyWhere.Y = OriginalAY;
    SetConsoleCursorPosition(hOut, KeyWhere);
    cout<<"        ";
    srand(GetTickCount());
    AlienLR = rand() % 3;            // random number generator
    KeyWhere.X = AlienX;
    KeyWhere.Y = AlienY;
    SetConsoleCursorPosition(hOut, KeyWhere);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);   //color of an alien
    cout<<"/W\\";          //model of an aliens ship
    if(AlienY > 23)            //function, if alien ship will go lower then Y=23(botton of the screen) following will happen:
    {
    Beep(100, 500);          // annoying sound)
    Alien = 0;               // alien destroyed
    Points = Points-50;      // deduction of points + update 
    AlienY = 1;                  // alien ships Y position becomes 1
    system("cls");           // clears Screen Command
    }
    }

    OriginalX = ShipX;
    OriginalY = ShipY;

    if(kbhit())  //function - if a key is pressed
    {
    Key = getch();
    if(Key == 'a')               
    {
    ShipX--;
    if(ShipX < 10) ShipX++;            // a - left 
    }
    if(Key == 'd')               
    {
    ShipX++;
    if(ShipX > 70) ShipX--;            // d - right
    }
    if(Key == 'w')
    {
    ShipY--;
    if(ShipY < 1) ShipY++;             // w - up
    }
    if(Key == 's')
    {
    ShipY++;
    if(ShipY > 48) ShipY--;            // s - down
    }
    if(Key == 'q')
    {
    if(Fire == 1);               // q - fire
    else
    {
    Beep(100, 15);               // sound while firing
    Fire = 1;
    FireX = ShipX+2;
    FireY = ShipY-1;

    }
    }
    if(Key == 'x') return 0;     //   x - exit App
    }

    for(Crash = 0; Crash < 5; Crash++) //if the space ships touch, , 
    {
    if(ShipY != AlienY);          
    else
    {
    if(ShipX+Crash == AlienX+0) Boom = 1;
    else if(ShipX+Crash == AlienX+1) Boom = 1;
    else if(ShipX+Crash == AlienX+2) Boom = 1;
    }
    }
    if(Boom == 1)
    {
    Beep(1000, 50);
    system("cls");   //clears Screen Command
    Boom = 0;
    Alien = 0;
    Lives--;  //decreases lives by 1
    AlienY = 1;   //alien Y position =1
    ShipX = 40;  // yours position X=40 Y=20
    ShipY = 20;
    Points = Points - 20;   //decreases points by 20
    if(Lives == 0)     //function, when lives reach 0
    {
    system("cls");         //clears Screen Command
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); //red color, message
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
    cout<<"\n                               DESTROYED!!!!!!!!!";
	cout<<"\n";
	cout<<"\n";
    cout<<"\n                         PLAY AGAIN? F1 = YES  Esc = NO";
    Beep(250, 150);           //fail sound
    Beep(200, 150);
    Beep(150, 150);
    Beep(100, 150);
    while(true)              //function, if pressed F1 - starts new game, if pressed ESC - exits
    {
    if(GetAsyncKeyState(VK_F1)) goto New;
    if(GetAsyncKeyState(VK_ESCAPE)) return 0;
    }
    }
    }
    }
}

