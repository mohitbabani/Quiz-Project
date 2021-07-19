#include<fstream>
#include<istream>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int no_of_questions;
string player_name;
int score=0;
class Question{
    public:
        string question;
        string options[4];
        char ans; 
};
void introduction(){
    cout << "Hello There :)\n";
    cout << "Welcome to this small quiz program\n"; 
}
void inputPlayerDetails(){
    cout << "\nPlease Enter Your Name : ";
    getline(cin,player_name);
    cout << "\nHello " << player_name << "!\n";
    cout << "\nHow many questions you wish to see in your quiz : ";
    cin >> no_of_questions;
    cout << "\n" << player_name <<" your quiz will have " << no_of_questions << " no of questions\n";
}
bool starting(){
    cout << "\nDo you want to start your Quiz Now: Y/N\n";
    string s;
    getline(cin,s);
    if(s == "Y" || s == "y" || s == "Yes" || s == "YES" || s == "yes"){
        cout << "\nYour Quiz starts Now\n";   
        return 1;
    }
    return 0;
}
void out(Question q){
    cout << "\n" << q.question << endl << endl ;
    for(auto s: q.options){
        cout << s <<"\n";
    }
    cout << "\nYour Response: ";
}
void outputResults(){
    cout << "\n"<< player_name <<" your score is " << score << " out of " << no_of_questions << "\n";
    cout << "\nThank you for participating :)\n";
    cout << endl;
}
int main(){
    score=0;
    introduction();
    inputPlayerDetails();
    ifstream fin[no_of_questions];
    Question questions[no_of_questions];
    for(int que = 0; que < no_of_questions; que++){
        string s =  "Question No " + to_string(que+1) + ".txt";
        fin[que].open("QuestionBank/" + s);
        Question curr_que;
        int line_no=1;
        string line;
        while(fin[que]){
            getline(fin[que],line);
            if(line_no == 1){
                curr_que.question = line;
            }else if(line_no == 6){
                curr_que.ans = line[0];
            }else{
                curr_que.options[line_no-2] = line;
            }
            line_no++;
        }
        questions[que] = curr_que;
    }
    // out(questions[0]);
    // bool start = starting();
    // if(start == 0){
    //     return 0;
    // }
    for(int que=0; que<no_of_questions; que++){
        auto curr_que = questions[que];
        out(curr_que);
        char ch;cin>>ch;
        if(curr_que.ans == ch || curr_que.ans == (ch-32)) score++;
    }
    outputResults();
    cout << "Press Q to exit\n";
    string ext;
    cin>>ext;
}
