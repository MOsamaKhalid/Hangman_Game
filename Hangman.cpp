#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int check=0;
string generate_guess_word(int length_of_secret_word)
{
    string word = "";
    for(int i=0; i<length_of_secret_word; i++)
    {
        word = word+"*";
    }
    return word;

}

bool found_word(std::string word,char guess,string guess_word)
{
    for(int i=0; i<word.size(); i++)
    {
        if(guess==word.at(i))
        {
            guess_word[i] = guess;


            return true;

        }

    }
}
string get_guessed_word(std::string word, string guess_word,char guess)
{
    for(int i=0; i<word.size(); i++)
    {
        if(guess==word.at(i))
        {
            guess_word[i] = guess;
            check++;


            return guess_word;

        }

    }



}
int main()
{
    char guess;
    int counter = 0;
    string guess_word;
    string words_list[10] = {"pakistan" , "india", "ethopia" , "malaysia" , "spain" , "switzerland" , "germany" , "italy" , "austria" , "chile" };
    srand(time(NULL));
    std::string secret_word = words_list[rand()% 10];

    cout<<secret_word;
    cout<<"\n Guess the word ";
    guess_word = generate_guess_word(secret_word.size());
    cout<<guess_word<< "\n";


    while(counter<5 && check<secret_word.size())
    {
        cout<<"\n Enter the guess \n";
        cin>>guess;

        if(found_word(secret_word,guess,guess_word))
        {
            guess_word = get_guessed_word(secret_word,guess_word,guess);
            cout<<guess_word;
            if(check==secret_word.size())
            {
                cout<<"\n YOU WIN \n";
                break;
            }
        }
        else
        {
            counter++;
            cout<<"TRY AGAIN- "<<5-counter<<" chances left \n";
            if(counter==5)
            {
                cout<<"YOU LOSE\n";
                cout<<"WORD WAS "<<"''"<<secret_word<<"''"<<"\n";
                break;
            }
        }


    }

    getch();
    return 0;
}


