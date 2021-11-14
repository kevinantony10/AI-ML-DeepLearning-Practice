#include<bits/stdc++.h>
#include<cmath>
#include<ctime>
#include <windows.h>
using namespace std;

class cai{
    public:

    int rightAnswers=0,wrongAnswers=0,roll;
    string name;

    void get_studentdetails();

    void problemtype_difficulty();
    void getQuestion(int questionType,int difficultyLevel);
    int getNumber(int difficultyLevel);
    int getRandomNumberBetweenRange(int start,int end);
    void Answer(int);//function overloading
    void Answer(char );
};

void cai::get_studentdetails(){
    cout<< "Enter your Name :";
    cin>>name;
    cout<< "Enter your Roll Number :";
    cin>>roll;

}



void cai::problemtype_difficulty(){
    srand(time(0));
    int questionsCount = 0;
    do
    {
        cout << "\n1. Addition problems\n2. Subtraction problems \n3. Multiplication problems\n4. Division problems\n5. Mixed\n6. Terminate"<<endl;
        int problemType = 0;
        while(1)
        {
            cout<<"\nPick your problem (1 to 5) or 6 to terminate: ";
            cin>> problemType;
            if(problemType == 6) return ; // terminate the program.
            if(problemType < 1 && problemType > 5)
            {
                cout << "That's an invalid input."<<endl;
            }
            else break;

        }
        int difficultyLevel = 0;
        while(1)
        {
            // lets limit to 3 levels.
            cout<<"\nEnter difficulty level (1 to 3): ";
            cin>> difficultyLevel;
            if(difficultyLevel < 1 && difficultyLevel > 3)
            {
                cout << "\nThat's an invalid input."<<endl;

            }
            else break;

        }
        while(questionsCount < 10)
        {
            getQuestion(problemType, difficultyLevel);
            questionsCount++;

        }
        int totalAnswers = rightAnswers + wrongAnswers;
        if((float)rightAnswers / totalAnswers < 0.75)
        {
            cout << "\nPlease ask your teacher for extra help."<<endl;

        }
        else
        {
            cout << "\nCongratulations you are ready to go to the next level"<<endl;

        }
        questionsCount = 0;
        rightAnswers = 0;
        wrongAnswers = 0;

    }while(1);
    return ;
}

void cai::getQuestion(int questionType, int difficultyLevel)
{
    int firstNumber = getNumber(difficultyLevel);
    int secondNumber = getNumber(difficultyLevel);
    if(questionType == 5) questionType = getRandomNumberBetweenRange(1,4);
    char op = ' ';
    int ct=0;//questionsCount = ct
    // do
    // {
        switch(questionType)
        {
            case 1: op = '+'; break;
            case 2: op = '-'; break;
            case 3: op = '*'; break;
            case 4: op = '/'; break;

        }
        cout <<"\nHow much is "<<firstNumber<<" "<<op<<" "<<secondNumber<<"?"<<endl;
        double studentAnswer = 0, answer = 0;
        cin>>studentAnswer;
        switch(questionType)
        {
            case 1: answer = firstNumber + secondNumber; break;
            case 2: answer = firstNumber - secondNumber; break;
            case 3: answer = firstNumber * secondNumber; break;
            case 4: answer = (double)firstNumber / secondNumber; break;

        }
        ct++;
        if(questionType == 4)
        {
            if(abs(answer-studentAnswer) < 0.01)
            {
                Answer(1);
                // break;

            }
            else
            {
                Answer('a');
            }

        }
        else
        {
            if(studentAnswer == answer)
            {
                Answer(1);
                // break;
            }
            else
            {
                Answer('a');

            }

        }

    // }while(ct<10);
}

int cai::getNumber(int difficultyLevel)
{
    // we don't want to generate number 0. ( in case of divisions) hence this check.
    int number = 0;
    do
    {
        number = rand() % (int)pow(10, difficultyLevel);

    }while(number == 0);
    return number;
}

int cai::getRandomNumberBetweenRange(int start, int end)
{
    return (rand() % (end - start + 1)) + start;
}

void cai::Answer(int a)
{
    const static char message[][40] = {"Very good!", "Excellent!", "Nice Work!", "Keep the good work!"};
    int messageIndex = getRandomNumberBetweenRange(0,3);
    cout << message[messageIndex] <<endl;
    rightAnswers++;
}

void cai::Answer(char a)
{
    const static char message[][40] = {"No. Please try again.", "Wrong. Try once more.", "Don't give up!", "No. Keep trying"};
    int messageIndex = getRandomNumberBetweenRange(0,3);
    cout << message[messageIndex] <<endl;
    wrongAnswers++;
}
class student: public cai{
    public:
    student(){
    cout<<"Welcome to CAI,you can test your mathematical skills here"<<endl;//default constructor
    }
    friend void display_studentdetails(student s);
};

void display_studentdetails(student s){
    cout<< "Welcome "<<s.name<<", glad to see you !"<<endl;
}

int main()
{

    student s1;
    s1.get_studentdetails();
    display_studentdetails(s1);
    s1.problemtype_difficulty();
}
