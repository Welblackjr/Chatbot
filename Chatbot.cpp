#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// This is for QNA Class

class QNA
{
public:
        QNA(string question, string answer);
        void setQuestion(string question);
        void setAnswer(string answer);
        void addKeyWord(string word);
        int getNumberOfKeyWord();
        bool areKeyWordMatched(string userQuestion);
        string getQuestion();
        string getAnswer();
private:
    string _question, _answer;
    vector<string> _qKeyWords;

};

    QNA::QNA(string question, string answer)
{ setQuestion(question); setAnswer(answer); }


bool QNA::areKeyWordMatched(string userQuestion)
{

    bool answer=true;

    for(int i=0; i < _qKeyWords.size(); i++)
    {
       if(userQuestion.find(_qKeyWords[i])==string::npos)
       {
           answer=false; i=_qKeyWords.size();
       }
    }

    return answer;
}



int QNA::getNumberOfKeyWord() {return _qKeyWords.size();    }

void QNA::addKeyWord(string word) {  _qKeyWords.push_back(word);  }

void QNA::setQuestion(string question)
{   _question=question; }

void QNA::setAnswer(string answer)
{   _answer=answer; }

string QNA::getQuestion()
{   return _question;   }

string QNA::getAnswer()
{   return _answer;    }



// This is the end of the QNA Class





// This is the start of the TeamArsenal Class

class TeamArsenal
{
    public:

        bool isQuestionValid(string userQuestion);
        string getResponses(string userQuestion);

    TeamArsenal();
    int getSize();


private:

    vector<QNA> _QNAs;
};


TeamArsenal::TeamArsenal()
{
    _QNAs.push_back(QNA("Who is in the starting 11 for Arsenal ", "Leno, Chambers, Mari, Holding, Tierney, Xhaka, Partey, Aubameyang, Lacazette, Saka, Smith-Rowe") );
    _QNAs[0].addKeyWord("Who"); _QNAs[0].addKeyWord("start"); _QNAs[0].addKeyWord("11"); _QNAs[0].addKeyWord("Arsenal");
    _QNAs.push_back(QNA("Who is the top goal scorer for Arsenal ", "Theirry Henry") );
    _QNAs[1].addKeyWord("Who"); _QNAs[1].addKeyWord("top"); _QNAs[1].addKeyWord("score"); _QNAs[1].addKeyWord("Arsenal");
    _QNAs.push_back(QNA("What year did Arsenal won the Premier League without losing a game ", "2003/04") );
    _QNAs[2].addKeyWord("What"); _QNAs[2].addKeyWord("year"); _QNAs[2].addKeyWord("won"); _QNAs[2].addKeyWord("losing");
    _QNAs.push_back(QNA("In what year did Mesut Ozil join Arsenal ", "2013/14") );
    _QNAs[3].addKeyWord("In"); _QNAs[3].addKeyWord("Mesut"); _QNAs[3].addKeyWord("Ozil"); _QNAs[3].addKeyWord("join");
    _QNAs.push_back(QNA("What is Arsenals biggest home defeat ", " 6-0") );
    _QNAs[4].addKeyWord("What"); _QNAs[4].addKeyWord("home"); _QNAs[4].addKeyWord("defeat");
    _QNAs.push_back(QNA("When was the last time Arsenal Qualified for Champions League", "2016/17") );
    _QNAs[5].addKeyWord("When"); _QNAs[5].addKeyWord("Qualified"); _QNAs[5].addKeyWord("Champions"); _QNAs[5].addKeyWord("League");
}

bool TeamArsenal::isQuestionValid(string userQuestion)
{
    bool answer=false;

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=true; i=_QNAs.size();
        }
    }

    return answer;
}

string TeamArsenal::getResponses(string userQuestion)
{
      string answer="";

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=_QNAs[i].getAnswer(); i= _QNAs.size();
        }
    }

    return answer;
}

int TeamArsenal::getSize()
{ return _QNAs.size();  }






// This is the end of the TeamArsenal Class

class TeamManCity
{
    public:

        bool isQuestionValid(string userQuestion);
        string getResponses(string userQuestion);

    TeamManCity();
    int getSize();


private:

    vector<QNA> _QNAs;
};


TeamManCity::TeamManCity()
{
    _QNAs.push_back(QNA("How many times has Manchester City won the Premier League", "6 times") );
    _QNAs[0].addKeyWord("How"); _QNAs[0].addKeyWord("times"); _QNAs[0].addKeyWord("won"); _QNAs[0].addKeyWord("League");
    
    _QNAs.push_back(QNA("In the 2017/18 season, how many points did Manchester City manage to obtain? ", "100") );
    _QNAs[1].addKeyWord("2017/18"); _QNAs[1].addKeyWord("points"); _QNAs[1].addKeyWord("manage"); _QNAs[1].addKeyWord("obtain");
   
    _QNAs.push_back(QNA("In what year did Manchester City experience a financial takeover? ", "2009") );
    _QNAs[2].addKeyWord("What"); _QNAs[2].addKeyWord("experience"); _QNAs[2].addKeyWord("financial"); _QNAs[2].addKeyWord("takeover");
    
    _QNAs.push_back(QNA("Who is Manchester City's current manager ", "Pep Guardiola") );
    _QNAs[3].addKeyWord("Who"); _QNAs[3].addKeyWord("current"); _QNAs[3].addKeyWord("manager");
    
    _QNAs.push_back(QNA("Who is Manchester City's top goalscorer ", "Kun Augero") );
    _QNAs[4].addKeyWord("Who"); _QNAs[4].addKeyWord("top"); _QNAs[4].addKeyWord("goalscorer");
    
    _QNAs.push_back(QNA("Do you think Manchester City will win the champions league in the next 4 years", "Yes i do but only if they get a new striker for the club :)") );
    _QNAs[5].addKeyWord("Do"); _QNAs[5].addKeyWord("win"); _QNAs[5].addKeyWord("champions"); _QNAs[5].addKeyWord("next");
}

bool TeamManCity::isQuestionValid(string userQuestion)
{
    bool answer=false;

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=true; i=_QNAs.size();
        }
    }

    return answer;
}

string TeamManCity::getResponses(string userQuestion)
{
      string answer="";

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=_QNAs[i].getAnswer(); i= _QNAs.size();
        }
    }

    return answer;
}

int TeamManCity::getSize()
{ return _QNAs.size();  }

//Class for liverpool


class TeamLiverpool
{
    public:

        bool isQuestionValid(string userQuestion);
        string getResponses(string userQuestion);

    TeamLiverpool();
    int getSize();


private:

    vector<QNA> _QNAs;
};


TeamLiverpool::TeamLiverpool()
{
    _QNAs.push_back(QNA("In the 2005 Champions League Final, what team did they manage to beat after going 3-0 down before half time", "AC Milian") );
    _QNAs[0].addKeyWord("In"); _QNAs[0].addKeyWord("Final"); _QNAs[0].addKeyWord("3-0"); _QNAs[0].addKeyWord("half");
    
    _QNAs.push_back(QNA("How did Liverpool win the match? Penalties or in the 90 minutes ", "Penalties") );
    _QNAs[1].addKeyWord("Match"); _QNAs[1].addKeyWord("Penalties"); _QNAs[1].addKeyWord("or"); _QNAs[1].addKeyWord("minutes");
   
    _QNAs.push_back(QNA("What is the name of the Liverpool stadium", "Anfield") );
    _QNAs[2].addKeyWord("What"); _QNAs[2].addKeyWord("name"); _QNAs[2].addKeyWord("Liverpool"); _QNAs[2].addKeyWord("Stadium");
    
    _QNAs.push_back(QNA("How many goals did Mo Salah score within the 2017/18 Premier League season ", "32") );
    _QNAs[3].addKeyWord("How"); _QNAs[3].addKeyWord("Mo"); _QNAs[3].addKeyWord("Salah");
    
    _QNAs.push_back(QNA("How much did Liverpool buy Van Dijk for ", "75 million") );
    _QNAs[4].addKeyWord("much"); _QNAs[4].addKeyWord("Dijk"); _QNAs[4].addKeyWord("for");
    
    _QNAs.push_back(QNA("What was the score in the famous match against Barcelona in 2019 in the second leg of the Champions League semi finals", "4-0, ORIGI!!!!!!!!") );
    _QNAs[5].addKeyWord("What"); _QNAs[5].addKeyWord("score"); _QNAs[5].addKeyWord("famous"); _QNAs[5].addKeyWord("Barcelona");
}

bool TeamLiverpool::isQuestionValid(string userQuestion)
{
    bool answer=false;

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=true; i=_QNAs.size();
        }
    }

    return answer;
}

string TeamLiverpool::getResponses(string userQuestion)
{
      string answer="";

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=_QNAs[i].getAnswer(); i= _QNAs.size();
        }
    }

    return answer;
}

int TeamLiverpool::getSize()
{ return _QNAs.size();  }

// This is the start of the TeamManUnited Class

class TeamManUnited
{
    public:

        bool isQuestionValid(string userQuestion);
        string getResponses(string userQuestion);

    TeamManUnited();
    int getSize();


private:

    vector<QNA> _QNAs;
};


TeamManUnited::TeamManUnited()
{
    _QNAs.push_back(QNA("What Manchester United player won the PFA player of the year award in 2000  ", " Roy Keane ") );
    _QNAs[0].addKeyWord("Manchester"); _QNAs[0].addKeyWord("United"); _QNAs[0].addKeyWord("player"); _QNAs[0].addKeyWord("won"); _QNAs[0].addKeyWord("PFA"); _QNAs[0].addKeyWord("award"); _QNAs[0].addKeyWord("2000");

    _QNAs.push_back(QNA("Which player scored the winning goal for Manchester United to win their only treble in 1999 ", " Ole Gunnar Solskjaer  ") );
    _QNAs[1].addKeyWord("player"); _QNAs[1].addKeyWord("scored"); _QNAs[1].addKeyWord("goal"); _QNAs[1].addKeyWord("Manchester"); _QNAs[1].addKeyWord("United"); _QNAs[1].addKeyWord("win"); _QNAs[1].addKeyWord("treble"); _QNAs[1].addKeyWord("1999");

    _QNAs.push_back(QNA("What team did Wayne Rooney score his debut goal against ", "Arsenal") );
    _QNAs[2].addKeyWord("team"); _QNAs[2].addKeyWord("Wayne"); _QNAs[2].addKeyWord("Rooney"); _QNAs[2].addKeyWord("score"); _QNAs[2].addKeyWord("debut"); _QNAs[2].addKeyWord("goal"); _QNAs[2].addKeyWord("against");

    _QNAs.push_back(QNA(" In your opinion, who do you think is a better goalkeeper? De Gea or Edward Van De Sar ", "Edward Van De Sar") );
    _QNAs[3].addKeyWord("opinion"); _QNAs[3].addKeyWord("better"); _QNAs[3].addKeyWord("goalkeeper"); _QNAs[3].addKeyWord("De"); _QNAs[3].addKeyWord("Gea"); _QNAs[3].addKeyWord("Edward"); _QNAs[3].addKeyWord("Sar");

    _QNAs.push_back(QNA("What year did Cristiano Ronaldo leave Manchester United ", " 2009") );
    _QNAs[4].addKeyWord("What"); _QNAs[4].addKeyWord("year"); _QNAs[4].addKeyWord("Cristiano"); _QNAs[4].addKeyWord("Ronaldo"); _QNAs[4].addKeyWord("leave"); _QNAs[4].addKeyWord("Manchester"); _QNAs[4].addKeyWord("United");
}

bool TeamManUnited::isQuestionValid(string userQuestion)
{
    bool answer=false;

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=true; i=_QNAs.size();
        }
    }

    return answer;
}

string TeamManUnited::getResponses(string userQuestion)
{
      string answer="";

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=_QNAs[i].getAnswer(); i= _QNAs.size();
        }
    }

    return answer;
}

int TeamManUnited::getSize()
{ return _QNAs.size();  }




// This is the end of the TeamManUnited Class

class TeamChelsea
{
    public:

        bool isQuestionValid(string userQuestion);
        string getResponses(string userQuestion);

    TeamChelsea();
    int getSize();


private:

    vector<QNA> _QNAs;
};


TeamChelsea::TeamChelsea()
{
    _QNAs.push_back(QNA(" Name 3 strikers that Chelsea had ", " Drogba, Diego Costa, Crespo ") );
    _QNAs[0].addKeyWord("Name"); _QNAs[0].addKeyWord("3"); _QNAs[0].addKeyWord("strikers"); _QNAs[0].addKeyWord("Chelsea");

    _QNAs.push_back(QNA("In the 2008/9 season, who did Chelsea lose too in the Champions League Finals ", " Man United  ") );
    _QNAs[1].addKeyWord("2008/9"); _QNAs[1].addKeyWord("season"); _QNAs[1].addKeyWord("Chelsea"); _QNAs[1].addKeyWord("lose"); _QNAs[1].addKeyWord("Champions"); _QNAs[1].addKeyWord("League"); _QNAs[1].addKeyWord("Finals");

    _QNAs.push_back(QNA("Who scored a header in the 2012 Champions League Finals to take them to extra time", "Drogba") );
    _QNAs[2].addKeyWord("scored"); _QNAs[2].addKeyWord("head"); _QNAs[2].addKeyWord("2012"); _QNAs[2].addKeyWord("Champions"); _QNAs[2].addKeyWord("League"); _QNAs[2].addKeyWord("Finals"); _QNAs[2].addKeyWord("extra");  _QNAs[2].addKeyWord("time");

    _QNAs.push_back(QNA(" Who was Chelsea 's most influencial player this decade ", " Hazard") );
    _QNAs[3].addKeyWord("Who"); _QNAs[3].addKeyWord("Chelsea"); _QNAs[3].addKeyWord("influencial"); _QNAs[3].addKeyWord("player"); _QNAs[3].addKeyWord("this"); _QNAs[3].addKeyWord("decade");

    _QNAs.push_back(QNA("When did Roman Abramovich buy the club ", " 2002") );
    _QNAs[4].addKeyWord("When"); _QNAs[4].addKeyWord("Roman"); _QNAs[4].addKeyWord("Abramovich"); _QNAs[4].addKeyWord("buy"); _QNAs[4].addKeyWord("club");
}

bool TeamChelsea::isQuestionValid(string userQuestion)
{
    bool answer=false;

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=true; i=_QNAs.size();
        }
    }

    return answer;
}

string TeamChelsea::getResponses(string userQuestion)
{
      string answer="";

    for(int i=0; i<_QNAs.size(); i++)
    {
        if(_QNAs[i].areKeyWordMatched(userQuestion))
        {
           answer=_QNAs[i].getAnswer(); i= _QNAs.size();
        }
    }

    return answer;
}

int TeamChelsea::getSize()
{ return _QNAs.size();  }


// This is the start of the  Soccer Stats Chatbot


class SoccerStats
{
public:

    void run();

private:
    TeamArsenal _arsenal ;
    TeamManCity _mancity ;
    TeamLiverpool _liverpool ;
    TeamChelsea _chelsea ;
    TeamManUnited _manunited ;

};

void SoccerStats::run()
{
     bool repeat=true;


     while(repeat)
     {
         cout<<"\n What would you like to know about any of the 5 teams : \n Chelsea, Liverpool, Manchester City, Manchester United, Arsenal?"<<endl;
        //string userQuestion; getline(cin,userQuestion);
        string userQuestion="", temp;

        while(cin>>temp && temp!="?")
        {   if(temp!="?")
            userQuestion+=temp;
        }

    // run arsenal response

        if(_arsenal.isQuestionValid(userQuestion))   // Detect questions which are relevant to Arsenal only
        {
            cout<<_arsenal.getResponses(userQuestion)<<endl;
        }
        else if(_manunited.isQuestionValid(userQuestion))
        {
            cout<<_manunited.getResponses(userQuestion)<<endl;
        }
        else if(_chelsea.isQuestionValid(userQuestion))
        {
            cout<<_chelsea.getResponses(userQuestion)<<endl;
        }
        else if(_liverpool.isQuestionValid(userQuestion))
        {
            cout<<_liverpool.getResponses(userQuestion)<<endl;
        }
        else if(_mancity.isQuestionValid(userQuestion))
        {
            cout<<_mancity.getResponses(userQuestion)<<endl;
        }

        else
        {
            cout<<"\n I do not understand your question \n"<<endl;
        }

        cout<<" Would you like to ask another question? Y or N? \n";
        char userResponse; cin>>userResponse;

        if( userResponse=='N' || userResponse=='n')
        {
            repeat=false;

            cout<<" I hope i was able to answer your questions successfully, see you next time! \n";
        }

     }



}


// 1. This is the userID class space;
class UserID
{
    public:

        UserID();
        UserID(string name, string surname, int age, double height, int number);
        string getName();
        string getSurname();
        int getAge();
        int getNumber();
        double getHeight();
        void setName(string name);
        void setSurname(string surname);
        void setAge(int age);
        void setNumber(int number);
        void setHeight(double height);
        void update(string name, string surname, int age, double height, int number);

    private:

        string _name,_surname;
        int _age, _number;
        double _height;
};

UserID::UserID()
{
    _name="Nonsoh";_surname="Chiemeka"; _age=0; _number=0; _height=0;
}

UserID::UserID(string name, string surname, int age, double height, int number)
{
    setName(name); setSurname(surname); setAge(age); setHeight(height); setNumber(number);
}

string UserID::getName() {  return _name;   }

string UserID::getSurname() {return _surname;   }

int UserID::getAge() {  return _age;    }

int UserID::getNumber() {   return _number; }

double UserID::getHeight() {    return _height; }

void UserID::setName(string name) { _name=name; }

void UserID::setSurname(string surname) {   _surname=surname;   }

void UserID::setAge(int age) {  _age=age;   }

void UserID::setNumber(int number) {    _number=number; }

void UserID::setHeight(double height) {    _height=height; }

void UserID::update(string name, string surname, int age, double height, int number)
{
   setName(name); setSurname(surname); setAge(age); setHeight(height); setNumber(number);
}









// This is the start of the User Database Class

class UserDataBase
{
public:

    UserDataBase();
    string getFileName();

    void setFileName(string fileName);
    void add(UserID userId);
    bool doesUserExist(UserID userId);
    bool doesNameExist(UserID userId);
    string getSurname(string name);

private:

    string _fileName;
};


UserDataBase::UserDataBase()
{
   _fileName="userNames.txt";
}

string UserDataBase::getFileName() {    return _fileName;   }

bool UserDataBase::doesUserExist(UserID userId)
{
    bool answer=false;  // start by assuming that it does not exist

    ifstream inputRead("userNames.txt");

    if(inputRead.is_open())
    {
        // do the comparision

        //File format (string name, string surname, int age, double height, int number)

        string name="", surname=""; int age=0, number=0; double height=0;

        while(!inputRead.eof() && !answer)
        {
            inputRead>>name>>surname>>age>>height>>number;

            if(userId.getName()==name && userId.getSurname() ==surname && userId.getNumber() ==number )
            {
                answer=true;
            }
        }
        inputRead.close();
    }
    else
    {
        cout<< " Could not open file";
    }

    return answer;
}
bool UserDataBase::doesNameExist(UserID userId)
{
    bool answer=false;  // start  by assuming that it does not exist

    ifstream inputRead("userNames.txt");

    if(inputRead.is_open())
    {
        // do the comparision

        //File format string name, string surname, int age, double height, int number)

        string name="", surname=""; int age=0, number=0; double height=0;

        while(!inputRead.eof() && !answer)
        {
            inputRead>>name>>surname>>age>>height>>number;

            if(userId.getName()==name)
            {
                answer=true;
            }
        }
        inputRead.close();
    }
    else
    {
        cout<< " Could not open file !";
    }

    return answer;
}
void UserDataBase::setFileName(string fileName) {   _fileName=fileName; }

void UserDataBase::add(UserID userId)
{
    // 1. Check if the user exist

        if(!doesUserExist(userId))
        {

             // 2. open the file (Append)
            ofstream outFile; outFile.open("userNames.txt", ios::app);

            if(outFile.is_open())
            {

            // 3. Add the new user details

            outFile<<userId.getName()<<" "<<userId.getSurname()<<" "<<userId.getAge()<<" "<<userId.getHeight()<<" "<<userId.getNumber()<<endl;

            // 4. Close the file
               outFile.close();
            }
            else
            {
                cout<<" Could not open outfile !!!"<<endl;
            }

        }

}

string UserDataBase::getSurname(string Name)
{

    string answer="";

    ifstream inputRead("userNames.txt");

    if(inputRead.is_open())
    {
        // do the comparision

        //File format string name, string surname, int age, double height, int number)

        string name="", surname=""; int age=0, number=0; double height=0;
        bool firstMatch=false;
        while(!inputRead.eof() && !firstMatch)
        {
            inputRead>>name>>surname>>age>>height>>number;

            if(Name==name)
            {
                answer=surname; firstMatch=true;
            }
        }
        inputRead.close();
    }
    else
    {
        cout<< " Could not open file !!!";
    }

    return answer;

}


// This is the end of the User Database Class 





// This is the end of the userId space 





// This is the start of UserLogin Space

class UserLogin
{

public:
        UserLogin();
        void collectUserDetails();

private:
        UserID _user;
        UserDataBase _userDB;
        SoccerStats _soccerStats;

        void collectOtherUserDetails();
};

UserLogin::UserLogin()
{


}

void UserLogin::collectUserDetails()
{

    string name="",surname=""; int age=0, number=0; double height=0;

    cout<< " Please enter your name : "; cin>>name; _user.setName(name);

    if(_userDB.doesNameExist(_user))
    {

        cout<<" Hey, your name sounds familar "<<endl;
        cout<<" I bet I can guess your surname, would you like me to try ? Y or N ?"<<endl;

        // Random Guessing of the surname

        char userResponse;
        cin>>userResponse;

        if(userResponse=='y' || userResponse=='Y')
        {

            // guess the user's surname

            cout<<"Is your Surname "<<_userDB.getSurname(_user.getName())<< " ? Y or N ?";
            cin>>userResponse;

            if(userResponse=='y' || userResponse=='Y')
            {
                // User agree to surname guess, we go stright to the soccer stats alogorithm

                cout<< "\n Yes!!! Get in there! Erm well welcome back ! \n As you already know, I am a chatbot for football, \n Would you like to ask me questions about Football? (Press Y or N to continue)? "<<endl;
                cin>>userResponse;

                if(userResponse=='y' || userResponse=='Y')
                {
                    _soccerStats.run();
                }
                else
                {
                    cout<< " Thank you, see you next time ! "<<endl;
                }
            }
            else
            {
             collectOtherUserDetails();
            }

        }
        else
        {
            collectOtherUserDetails();
        }

    }
    else
    {
       // new user
       cout<<"\n This is the first time meeting you, I am so excited, Welcome ! "<<endl;

       collectOtherUserDetails();
    }


}

void UserLogin::collectOtherUserDetails()
{
    //string name="",surname=""; int age=0, number=0; double height=0;

    cout<< " What is your Surname ?"<<endl;
    string surname; cin>>surname; _user.setSurname(surname);

    cout<< "\n What is your Number ?"<<endl;
    int number; cin>>number; _user.setNumber(number);

    if(_userDB.doesUserExist(_user))
    {
       // user already exist

       cout<< "\n Welcome back !!! \n Would you like to ask me any queestions about football? Y or N  "<<endl;
       char userResponse; cin>>userResponse;

       if(userResponse=='y' || userResponse=='Y')
        {
            _soccerStats.run();
        }
        else
        {
            cout<< " Thank you, see you next time !!! "<<endl;
        }

    }
    else
    {
        // it mean the user does not exist and their details have to be captured in gthe data
        
        cout<< "\n How old are you ?"<<endl;
        int age; cin>>age; _user.setAge(age);

        cout<< "\n How tall are you in meters ?"<<endl;
        double height; cin>>height; _user.setHeight(height);

        // Record the user details in our database
        _userDB.add(_user);

       cout<< "\n Hello, Nice to meet you, I am a chatbot \n\n Would you like to know about about football with me Y or N? "<<endl;
       char userResponse; cin>>userResponse;

       if(userResponse=='y' || userResponse=='Y')
        {
            _soccerStats.run();
        }
        else
        {
            cout<< " Thank you, see you next time "<<endl;
        }
    }

}



// This is the end of UserLogin



int main()
{

   UserLogin userManager;

   userManager.collectUserDetails();

    return 0;
}


