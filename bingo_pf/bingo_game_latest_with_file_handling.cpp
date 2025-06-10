#include<iostream>
#include<cstdlib>
#include<thread>
#include<time.h>
#include<string>
#define NOMINMAX
#include<windows.h>
#include<fstream>
using namespace std;
bool has=true;
void score(int arr[25][25], int& point, int size)
{                     //function for checking score for player 1
          //it check the sum of each row,column and diagonal . if it equal to zero than increment in score of first player
    point = 0;
    for (int i = 0; i < size; i++)
    {                                       //cheking each row
        int sum1 = 0;
        for (int j = 0; j < size; j++)
        {
            sum1 = sum1 + arr[i][j];
        }
        if (sum1 == 0)                           //if sum of any row equal to zero so increment in score
        {
            point++;
        }
    }
    for (int i = 0; i < size; i++)
    {                              //loop for cheking column
        int sum1 = 0;
        for (int j = 0; j < size; j++)
        {
            sum1 = sum1 + arr[j][i];
        }
        if (sum1 == 0)                  //if sum of any column equal to zero so increment in score          
        {
            point++;
        }
    }
    int sum1 = 0;
    for (int i = 0; i < size; i++)   //cheking sum of diagonal
    {
        sum1 = sum1 + arr[i][i];
    }
    if (sum1 == 0)         //if sum of diagonal is zero increment in score
    {
        point++;
    }
    sum1 = 0;
    for (int i = 0; i < size; i++)       //cheking sum of antidiagonal
    {
        sum1 = sum1 + arr[i][(size - 1) - i];
    }
    if (sum1 == 0)           //if sum of antidiagonal is zero increment in score
    {
        point++;
    }
    if(point==1)
    {
        has=false;
    }
}
void checknumber(int arr[25][25], int arr2[25][25], int num2, int& point, bool& hello, int size)
{                        //function to put zero in both cards at the place where input number is found by player second
    hello = true;
    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j < size;j++)        //both loops for row and columns
        {
            if (arr2[i][j] == num2)         //where number found in row equal the number to zero card two
            {
                arr2[i][j] = 0;
                hello = false;
            }
            if (arr[i][j] == num2)
            {                              //where number found in row equal the number to zero in card one
                arr[i][j] = 0;

            }
        }
    }
    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j < size;j++)
        {
            if (arr2[j][i] == num2)       //where number found in column equal the number to zero in card two
            {
                arr2[j][i] = 0;
                hello = false;

            }
            if (arr[j][i] == num2)        //where number found in column equal the number to zero in card one
            {
                arr[j][i] = 0;

            }
        }
    }
    for (int i = 0, j = 0;i < size, j < size;i++, j++)
    {                                    //loop for diagonal if number found in any index of diagonla to insert the zero at place of that number
        if (arr2[i][j] == num2)
        {                                 //for card2
            arr2[i][j] = 0;
            hello = false;
        }
        if (arr[i][j] == num2)              //for card1
        {
            arr[i][j] = 0;

        }
    }
    for (int i = 0, j = size - 1;j > 0;i++, j--)
    {                            //loop for antidiagonal if number found in any index of antidiagonla to insert the zero at place of that number
        if (arr2[i][j] == num2)
        {                                   //for card 2
            arr2[i][j] = 0;
            hello = false;
        }
        if (arr[i][j] == num2)               //for card1
        {
            arr[i][j] = 0;

        }
    }
    score(arr2, point, size);      //to check every  row or column or dioganal sum is zero for every input number for 
    //card 2 to increase score for player 2 
}
bool NumUsed(int array[25][25], int num, int size)         //function two stop repitatian in cards 
{                                              //function check every number which is enter the cards
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == num)
            {
                return true;                   //return true if number is not already present
            }
        }
    }
    return false;                         //return false if number is not aiready present so random function work agian to generate other number
}
bool f1(int q)                          //function to check total  digits in number to make perfect output
{
    int counter = 0, counter2 = 0;
    while (q > 0) {
        counter = q % 10;
        q = q / 10;
        counter2++;
    }
    if (counter2 == 2)
    {
        return true;                //if two digits return 1;
    }
    else
    {
        return false;
    }
}
void inputnumber(int arr[25][25], int arr2[25][25], int& point, int& point2, string username1, string username2, int  size)
{                                                  //inputnumber contain winning condition and loop to continue take input as long as one of
                                                  //both player win this function also show the both cards
    int num1 = 0, num2 = 0, a = 1, t = 0;
    bool hel=true;
    while ((has) && (hel)&&/*( point <=1) && (point1 <=1) &&*/ num2 != -1 && num1 != -1)                 //continue game untill one player win
    {
        cout << username1 << "'s  card " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << "\t" << "\t";
                for (int j = 0; j < size; j++)
                {
                    if (size < 10) {  //if number less than 10
                        if (arr[i][j] == 1 || arr[i][j] == 2 || arr[i][j] == 3 || arr[i][j] == 4 || arr[i][j] == 5 || arr[i][j] == 6 || arr[i][j] == 7 || arr[i][j] == 8 || arr[i][j] == 9 || arr[i][j] == 0)
                        {
                            cout << arr[i][j] << " |";  //give to space
                        }
                        else
                        {
                            cout << arr[i][j];
                            cout << "|";         //for no space
                        }
                    }
                    else
                    {
                        t = arr[i][j];
                        if (arr[i][j] == 1 || arr[i][j] == 2 || arr[i][j] == 3 || arr[i][j] == 4 || arr[i][j] == 5 || arr[i][j] == 6 || arr[i][j] == 7 || arr[i][j] == 8 || arr[i][j] == 9 || arr[i][j] == 0)
                        {
                            cout << arr[i][j] << "  |";   //for two space 
                        }
                        else  if (f1(t))                  //use fuction to count digits in number
                        {
                            cout << arr[i][j];
                            cout << " |";
                        }
                        else
                        {
                            cout << arr[i][j];
                            cout << "|";
                        }
                    }
                }
                cout << endl;
            }
            fstream cont2;                            //file for save first array 
            cont2.open("fil2.txt", ios::out);          //it change with every input 
            for(int i=0;i<size;i++)
            {
                for (int j = 0;j < size;j++)
                {
                    cont2 << arr[i][j] << " ";
                }
                cont2 << endl;
            }
            cont2 << point;
            cont2 << endl;
            cont2.close();
        cout << endl;
        cout << endl;
        cout << "Point is " << point << endl;
         if(point>=1)
         {
            hel=false;
         }
        //if (point == size + 1)                //condition to stop draw condition 
        //{                             //so when player one reach wining score  loop terminate and player one win
        //    break;
        //}
        bool already2 = false;
        do {
            cout << "Enter the number from the given card and -1 for quit : ";
            cin >> num1;
            if (cin.fail())
            {
                already2 = true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                checknumber(arr, arr2, num1, point, already2, size);       //function to check the number in card and at that poistion in card found it we zero it
            }
        } while ((already2 || num1 <= 0 || num1 > (size * size)) && num1 != -1);         //num1 is player one input and point is its score
      
        if (num1 == -1)
        {
            break;
        }
        if (point ==1 )
        {
            break;
        }
        if(point>=1)
        {
            hel=false;
        }
        system("cls");                                  //for clear screen
        cout << username2 << " 's   card " << endl;
        if (size < 10) {
            for (int i = 0; i < size; i++)            //conditons for space in card
            {
                cout << "\t" << "\t";
                for (int j = 0; j < size; j++)
                {

                    if (arr2[i][j] == 1 || arr2[i][j] == 2 || arr2[i][j] == 3 || arr2[i][j] == 4 || arr2[i][j] == 5 || arr2[i][j] == 6 || arr2[i][j] == 7 || arr2[i][j] == 8 || arr2[i][j] == 9 || arr2[i][j] == 0)
                    {
                        cout << arr2[i][j] << " |";
                    }
                    else
                    {
                        cout << arr2[i][j];
                        cout << "|";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            for (int i = 0;i < size;i++) {
                cout << "\t" << "\t";
                for (int j = 0;j < size;j++)
                {
                    t = arr2[i][j];                //loops for space in card 
                    if (arr2[i][j] == 1 || arr2[i][j] == 2 || arr2[i][j] == 3 || arr2[i][j] == 4 || arr2[i][j] == 5 || arr2[i][j] == 6 || arr2[i][j] == 7 || arr2[i][j] == 8 || arr2[i][j] == 9 || arr2[i][j] == 0)
                    {
                        cout << arr2[i][j] << "  |";
                    }
                    else if (f1(t))
                    {
                        cout << arr2[i][j];
                        cout << " |";
                    }
                    else
                    {
                        cout << arr2[i][j];
                        cout << "|";
                    }
                }
                cout << endl;
            }
        }
        fstream cont3;                    //for saving array 2 in file
        cont3.open("fil3.txt", ios::out);        //for second array which update with every in put 
        for (int i = 0;i < size;i++)
        {
            for (int j = 0;j < size;j++)
            {
                cont3 << arr2[i][j] << " ";
            }
            cont3 << endl;
        }
        cont3 << point2;
        cont3<< endl;
        cont3.close();
        cout << endl;
        cout << endl;
        cout << "Point is " << point2 << endl;
        bool alr_zero = false;
        do {
            cout << "Enter the number from the given card and -1 for quit : ";
            cin >> num2;
            if (cin.fail())   //always true if number is already present or input is alphabet
            {
                alr_zero = true;      //make it true
                cin.clear();            //clear input number
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
                checknumber(arr, arr2, num2, point2, alr_zero, size);       //function to check the number in card and at that postion in card found it we zero it
        } while ((alr_zero || num2 <= 0 || num2 > (size * size)) && num2 != -1);
                                                                       //loop will check range of number and check input is not alphabet and terminate on input 1
       
                                                                 //num2 is input of number from player 2 and point2 is its score
        system("cls");
    }
    fstream file;
    file.open("file1.txt", ios::out | ios::app);  //for saving winner in prevoius games in history
    if (point >= size)                         //winning condition for player one
    {
        cout << endl;
        cout << username1 << "  is winner ";
        file << "winner of that game is  " << username1 << endl;
    }
    else if (point2 >= size)                 //winning condition for second player
    {
        cout << username2 << "  is winner ";
        file << "winner of that game is  " << username2 << endl;            
    }
    else
    {
        cout << "winner at point 1 ";
    }
    file.close();
}


void mainmenue()                                            //for main menue and also for taking numbers in cards
{
    srand(time(0));                                          //built in function for random function
    int arr[25][25], z, n=0, arr2[25][25];                             //taking two arrays for making two cards
    int point = 0;       //for player one                        //for counting score
    int point2 = 0;       //for player two                        //for counting score of player two
    int checkcard, f, choice,id;
    cout << "***************************************************** B  I  N  G  O*****************************************************\n";
    cout << endl;
    cout << "\t" << "\t" << "Enter 1 for play game game " << endl;                    //main menue
    cout << "\t" << "\t" << "Enter 2 for game history " << endl;
    cout << "\t" << "\t" << "Enter 3 for checking high score " << endl;
    cout << "\t" << "\t" << "Enter 4 how to play  " << endl;
    cout << "\t" << "\t" << "Enter 5 for exit  " << endl;
    do
    {
        cin >> n;                  //for input of given option


       if (n == 1)
       {
            cout << "Enter 1 for new game and 2 for previous game ";
            cin >> choice;
           if (choice == 1)
           {

              cout << endl;
              cout << endl;
              cout << endl;
              id= (rand() % 999) + 3000;
              cout << " Game ID  " << id;           //for random game id
              cout << endl;
              cout << endl;
              string name1, name2, username1, username2;                   //for input names of both players
              cout << "\t" << "\t" << "first player input the name   ";
              cin.ignore();
              getline(cin,name1);                                          //function for input
              //cout << endl;
              cout << "\t" << "\t" << "second player input the name  ";
              getline(cin, name2);                                 //for second player name input

              int toss;
              toss = (rand() % 4) + 1;                              //for toss    
              if (toss == 1)                                        //for random choice of player from two
              {
                username1 = name2;
                username2 = name1;
              }
              else
              {
                username1 = name1;
                username2 = name2;
              }

              system("color  01");
              cout << "Enter the size of card ";
              cin >> z;
              while (z < 0 || z>25)
              {
                cout << "its a game card not a joke please input the corect size of card  ";
                cin >> z;
              }
              cout << endl;
              cout << " Toss is won by  " << username1;
              system("pause");
              system("cls");
             // cout << username1 << endl;
              for (int i = 0; i < z; i++)                  //loop for rows in matrix
              {
                  // cout << "\t" << "\t";
                  for (int j = 0; j < z; j++)              //for colums in matrix
                  {

                      do                                    //for random number input in card in given range
                      {
                          checkcard = (rand() % (z * z)) + 1;
                      } while (NumUsed(arr, checkcard, z));           //numused is a function to stop repitation of same number in card

                      arr[i][j] = checkcard;

                  }
              }
              for (int i = 0; i < z; i++)                          //loop for rows in matrix
              {
                    for (int j = 0; j < z; j++)                    //for colums in matrix
                    {
                        do                                           //for random number input in card in given range
                        {
                            f = (rand() % (z * z)) + 1;
                        } while (NumUsed(arr2, f, z));           //numused is a function to stop repitation of same number in card

                        arr2[i][j] = f;
                    }
                    //  cout << endl;
                
              }
              fstream file;            
              file.open("file1.txt", ios::out|ios::app);     //for saving history about every game
              if (!(file.is_open()))
              {
                  cout << "not open ";
              }
              else
              {
              
                  file << username1 << endl;
                  file << username2 << endl;
             
              }
               file.close();
               fstream cont; 
               cont.open("file3.txt", ios::out);         //saving names for continue the same game
               //cont << id << endl;
               cont << username1 << endl;
               cont << username2 << endl;
               cont << z;
               cont.close();
             inputnumber(arr, arr2, point, point2, username1, username2, z);      //call function for input number from both users
           }
          else if (choice == 2)                      //for previous game
          {
               int point = 0, point2 = 0;    
               string username1, username2;
               fstream cont, cont2, cont3;
               cont.open("file3.txt", ios::in);         //for output name from file for same players
               getline(cont, username1);
               //cout << username1;
               getline(cont, username2);
              
               cont >> z;
               //cout << z;
               cont.close();
               cont2.open("fil2.txt", ios::in);            //for first card previous left game from where game is left
               for (int i = 0;i < z;i++)
               {
                   for (int j = 0;j < z;j++)
                   {
                       cont2 >> arr[i][j];
                   }
               }
               cont >> point;
               cont2.close();
               cont3.open("fil3.txt", ios::in);           //for second card input from file where game is left
               for (int i = 0;i < z;i++)
               {
                   for (int j = 0;j < z;j++)
                   {
                       cont3 >> arr2[i][j];
                   }
               }
               cont3 << point2;
               cont3.close();
               inputnumber(arr, arr2, point, point2, username1, username2, z);  //recall function for continue the game
          }
          else
          {
            cout << "error";
          }
       }
        else if (n == 2)                 
        {
            fstream file;
            file.open("file1.txt", ios::in);
            char ch;
            ch = file.get();
            while (!file.eof())
            {
                cout << ch;
                ch = file.get();
            }
            file.close();
        }
        else if (n == 3)
        {
            cout << "View high score " << endl;
            fstream score;
            score.open("file2.txt", ios::in);
            if (!score.is_open())
            {
                cout << "hahahahhah ";
            }
            else
            {
                cout << endl;
                char ch;
                ch = score.get();
                while (!(score.eof()))
                {
                        cout << ch;
                        ch = score.get();
                }
            }
            score.close();
           
        }
        else if (n == 4)        //for option four to seak help
        {
            cout << "so you need help I am here to teach you how to play this game " << endl;
            cout << "In this game you have a card in which numbers are given in random arrangement in given range of number .";
            cout << "So you have to input number if your number is correct in the given arrange than that number in card your card and your oppnent card becomes zero .";
            cout << "if you convert the whole row or column or diagonal into zeros you score 1 .To win you have to do score equal to the size of card .";
            cout << "Now you are ready to play ";
        }
        
        else if (n == 5)
        {
            cout << "you want to quit  press enter ";
            break;
        }
        else
        {
            cout << "error " <<"enter again any choice"<< endl;
        }

    }while (true); //loop if input is not valid
}
int main()                                   //main function
{
    system("color  F8");
    mainmenue();        //we call our first and main function    
    system("pause");
    return 0;                              //for succesful run of programe
}

