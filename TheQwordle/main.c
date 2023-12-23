#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
int check(char *a);
struct set
{
    char word[6];
    char guess[6];
    char guesscopy[6];
    char guesscopy1[6];
    char color[6] = {8,8,8,8,8};
}s;
void setCColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
} 
int isequal(const char *a, const char *b)
{
    if(strlen(a)!=strlen(b)){
        return 0;
    }
    int i =0;
    while(a[i]&&b[i])
        {
            if(a[i]!= b[i])
                return 0;
            i++;
        }
    return 1;
    }
void specialcheck(char *a)
{
    char special[3][19] ={"jogi","thala","msdhoni"};
    if(isequal(a,special[0]))
    {
        for (int i = 0; i < 10000; ++i)
        {
            printf("Bhupendra Jogi");
        }
    }
    else if(isequal(a,special[1])||isequal(a,special[2]))
    {
        printf("YOU WOM!!!\n\n");
        setCColor(14);
        printf("thala for a reason");

        system("111.mp4 ");
         exit(0);
    }
}
void input()
{   
    // Declare a buffer of size 19 for special check
    char buffer[19];
    printf("Enter a word : ");
    // fgets is safer than scanf
 
        fgets(buffer, sizeof(buffer), stdin) ;

        // to remove newline character
        if(buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';

        // For special check
        specialcheck(buffer);
        if(!check(buffer))
        {
            printf("Invalid word\n");
            input();
        }
        else
        {
            strcpy(s.guess,buffer);
        }
}
//checks if the chars are alphabets are not would save file search time if not true ig
int areAlphabets(char *a )
{
    int i =0;
    while(a[i])
    {
        if (!((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')))
            return 0;
        i++;
    }

    return 1;
}
//checks if its a valid 5 letter word from the file
int validWord(char *a) {
    FILE *file = fopen("5letterwords.txt", "r");
    if (file == NULL) {
        printf("Could not open file 5letterwords.txt\n");
        exit(0);
    }

    // Remove newline character if present
    size_t len = strlen(a);
    if (len > 0 && a[len-1] == '\n') {
        a[len-1] = '\0';
    }

    char buffer[100];
    while (fgets(buffer, 100, file)) 
    {
        buffer[strlen(buffer) - 1] = '\0'; // Remove newline character if present
        if (strcmp(buffer, a) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
int check(char *a)
{
    if(strlen(a)!=5)
    {
        return 0;
    }
    else if(!(areAlphabets(a)&&validWord(a)))
    {// will save file comparing time
        return 0;
    }
    else
        return 1;
}   
void correctposition()
{
    int i = 0;
    while(s.guess[i])
    {
        if(s.guess[i]==s.word[i])
        {
            s.color[i] = 2;
            s.guesscopy[i] = '*';
            s.guess[i] = '*';
        }
        i++;
    }
}
void wrongposition()
{
    int i = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5 ; ++j)
        {
            if(s.guesscopy[j]==s.guess[i]&&s.guess[i]!='*')
            {
                s.color[i] = 6;
                s.guesscopy[j] = '*';
                break;
            }
        }
    }
}
void print()
{
    int i =0;

    while(s.guess[i])
    {
        setCColor(s.color[i]);
        printf("%c",s.guesscopy1[i]);
        s.color[i]=8;
        i++;
    }
    printf("\n");
}
char* getRandomWord(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return NULL;
    }

    std::string word;
    while (std::getline(file, word)) {
        words.push_back(word);
    }

    file.close();

    srand(time(0));
    int random_index = rand() % words.size();

    char* cstr_word = new char[words[random_index].length() + 1];
    strcpy(cstr_word, words[random_index].c_str());

    return cstr_word;
}
void setdefault()
{
    setCColor(15);
        strcpy(s.guesscopy,s.word);


}
void instructions()
{
        setCColor(15);
printf("\n");
    printf("        *****************************************************************************************\n");
    printf("        *                                                                                       *\n");
    printf("        *                            W   W   OOO   RRRR   DDDD   L      EEEEE                   *\n");
    printf("        *                            W   W  O   O  R   R  D   D  L      E                       *\n");
    printf("        *                            W W W  O   O  RRRR   D   D  L      EEEE                    *\n");
    printf("        *                            W W W  O   O  R R    D   D  L      E                       *\n");
    printf("        *                            W   W   OOO   R  RR  DDDD   LLLLL  EEEEE                   *\n");
    printf("        *                                                                                       *\n");
    printf("        *****************************************************************************************\n");
    printf("\n");

    printf("  RULES :\n\n");
    printf("> You have to guess a 5 - letter word from English Language\n");
    printf("> The word you must exits in english Language\n");
    printf("> If the character printed is of \n\n");
    setCColor(2);
    printf("> oooo");
    setCColor(15);
    printf(" Means the character in your guess is in the same position in the world.\n");
    setCColor(6);
    printf("> oooo");
    setCColor(15);
    printf(" Means the character in your guess is exist in the word but is in wrong place.\n");
    setCColor(8);
    printf("> oooo");
    setCColor(15);
    printf(" Means the character in your guess does not exist in the word.\n \n\n");

}
int main()
{

    int  k =1;
    int tries;
    while(k==1)
    {
        system("cls");
        instructions();
        tries =1;
    strcpy(s.word,getRandomWord("5letterwords.txt"));


    while(tries<=5)
    {
        setdefault();
        input();
        strcpy(s.guesscopy1,s.guess);
        if(isequal(s.word,s.guesscopy1))
        {
            printf("Congrats !!!\nYou Won in %d tries\n",tries);// it will be try if won at 1 will implement it later
            goto here;
        }
        correctposition();
        wrongposition();
        print();
        tries++;
    }
    setCColor(15);
    printf("Gr8 try!\nBetter luck next time\nThe word was :%s\n", s.word);
    here :
    setCColor(15);
    printf("Enter 1 to play again\n");
    scanf("%d",&k);
    }
}