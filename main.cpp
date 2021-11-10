#include<bits/stdc++.h>
#include<cmath>
#include<ctime>
using namespace std;

class student{
    int rightAnswers=0,wrongAnswers=0,roll;
    string name;
    public:
    void get_studentdetails();
    void display_studentdetails();
    void problemtype_difficulty();
    void getQuestion(int questionType,int difficultyLevel);
    int getNumber(int difficultyLevel);
    int getRandomNumberBetweenRange(int start,int end);
    void printCorrectAnswer();
    void printWrongAnswer();
};

void student::get_studentdetails(){
    cout<< "Enter your Name :";
    cin>>name;
    cout<< "Enter your Roll Number :";
    cin>>roll;
    
}

void student::display_studentdetails(){
    cout<< "Welcome "<<name<<", glad to see you !"<<endl;
}

void student::problemtype_difficulty(){
    srand(time(0));
    int questionsCount = 0;
    do
    {
        cout << "\n1. Addition problems\n2. Subtraction problems \n3. Multiplication problems\n4. Division problems\n5. Mixed\n6. Terminate"<<endl;
        int problemType = 0;
        do
        {
            cout<<"\nPick your problem (1 to 5) or 6 to terminate: "; 
            cin>> problemType;
            if(problemType == 6) return ; // terminate the program.
            if(problemType < 1 && problemType > 5)
            {
                cout << "That's an invalid input."<<endl;
            }
            else break;
            
        }while(1);
        int difficultyLevel = 0;
        do
        {
            // lets limit to 3 levels.
            cout<<"\nEnter difficulty level (1 to 3): "; 
            cin>> difficultyLevel;
            if(difficultyLevel < 1 && difficultyLevel > 3)
            {
                cout << "\nThat's an invalid input."<<endl;
                
            }
            else break;
            
        }while(1);
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

void student::getQuestion(int questionType, int difficultyLevel)
{
    int firstNumber = getNumber(difficultyLevel);
    int secondNumber = getNumber(difficultyLevel);
    if(questionType == 5) questionType = getRandomNumberBetweenRange(1,4);
    char op = ' ';
    do
    {
        switch(questionType)
        {
            case 1: op = '+'; break;
            case 2: op = '-'; break;
            case 3: op = '*'; break;
            case 4: op = '/'; break;
            
        }
        cout <<"\nHow much is "<<firstNumber<<" "<<op<<" "<<secondNumber<<"?"<<endl;
        double studentAnswer = 0, answer = 0;
        scanf("%lf", &studentAnswer);
        switch(questionType)
        {
            case 1: answer = firstNumber + secondNumber; break;
            case 2: answer = firstNumber - secondNumber; break;
            case 3: answer = firstNumber * secondNumber; break;
            case 4: answer = (double)firstNumber / secondNumber; break;
            
        }
        if(questionType == 4)
        {
            if(abs(answer-studentAnswer) < 0.01)
            {
                printCorrectAnswer();
                break;
                
            }
            else
            {
                printWrongAnswer();
            }
            
        }
        else
        {
            if(studentAnswer == answer)
            {
                printCorrectAnswer();
                break;
            }
            else
            {
                printWrongAnswer();
                
            }
            
        }
        
    }while(1);
}

int student::getNumber(int difficultyLevel)
{
    // we don't want to generate number 0. ( in case of divisions) hence this check.
    int number = 0;
    do
    {
        number = rand() % (int)pow(10, difficultyLevel);
        
    }while(number == 0);
    return number;
}

int student::getRandomNumberBetweenRange(int start, int end)
{
    return (rand() % (end - start + 1)) + start;
}

void student::printCorrectAnswer()
{
    const static char message[][40] = {"Very good!", "Excellent!", "Nice Work!", "Keep the good work!"};
    int messageIndex = getRandomNumberBetweenRange(0,3);
    cout << message[messageIndex] <<endl;
    rightAnswers++;
}

void student::printWrongAnswer()
{
    const static char message[][40] = {"No. Please try again.", "Wrong. Try once more.", "Don't give up!", "No. Keep trying"};
    int messageIndex = getRandomNumberBetweenRange(0,3);
    cout << message[messageIndex] <<endl;
    wrongAnswers++;
}

int main()
{
    student s1;
    s1.get_studentdetails();
    s1.display_studentdetails();
    s1.problemtype_difficulty();
}
