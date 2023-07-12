// Abhay Iyer AXI210015
#include <memory>
#include <iostream>
#include<fstream>
#include <string>
#include <cstdio>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;
const string answers = "answers.txt";
const string report =  "contestants.txt";
string Reportbatch; //variable for Student Report filename
void compareTOAnswer(shared_ptr<string[]> contestantAnswersArray, string id, shared_ptr<string[]> AnswerKeyArray, int count, shared_ptr<float[]> ContestantScoreArray, int timesran){
    int formattingcounter = 0;
    float accuracy = 0;
//shared<int[]> ContestantScore1 = ContestantScoreArray;
    shared_ptr<float[]> ContestantScoreArrayHolder = ContestantScoreArray;
    shared_ptr<int[]> WrongQuestions(new int[count]);
    shared_ptr<string[]> WrongAnswers(new string[count]);
    shared_ptr<string[]> CorrectAnswers(new string[count]);
    int wrongQuestionsLength = 0;
    shared_ptr<string[]> ContestantAnswer = contestantAnswersArray;
    shared_ptr<string[]> AnswerKey = AnswerKeyArray;
//cout<<*contestantAnswerArray<<endl;
    for (int i = 0; i < count; i++){
        if(*(ContestantAnswer.get() + i) != *((AnswerKey.get())+ i)){
            *(WrongQuestions.get() + wrongQuestionsLength) = i+1;
            *(WrongAnswers.get() + wrongQuestionsLength) =  *(ContestantAnswer.get() + i);
            *(CorrectAnswers.get() + wrongQuestionsLength) = *(AnswerKey.get() + i);
            wrongQuestionsLength++;
            /*
           *pointertoWrongAnswers = *contestantAnswerArray;
            pointertoWrongAnswers++;
            *pointertotheWrongQuestions = i;
            pointertotheWrongQuestions++;
            *pointertoCorrectAnswers = *answerArray;
            pointertoCorrectAnswers++;
            contestantAnswerArray++;
            answerArray++;
            */
        }
        if (*(ContestantAnswer.get() + i) == *(AnswerKey.get()+i)){
            accuracy++;
            *(CorrectAnswers.get()+i) = *(AnswerKey.get() + i);
        }


        if (i == count - 1){
            cout<<endl;
            cout<<id<<" - "<<std::fixed<<std::showpoint<<std::setprecision(2)<<(accuracy/count)*100<<endl;
            /*
            for (int i = 0; i < wrongQuestionsLength; i++){
        cout<<*(WrongQuestions.get()+i);
        }
            for (int i = 0; i < wrongQuestionsLength; i++){
        cout<<*(WrongAnswers.get()+i);
        */
        }

    }

    if (accuracy < count){

        for (int i = 0; i < wrongQuestionsLength; i++){
            if (formattingcounter == 0){
                cout<< *(WrongQuestions.get()+ i);
                formattingcounter++;
            }
            else{
                cout<<" ";
                cout<< *(WrongQuestions.get()+ i);
            }

        }
        cout<<endl;
        formattingcounter = 0;
        for (int i = 0; i <wrongQuestionsLength; i++){
            if (*(WrongQuestions.get() +i) >= 10 && i < wrongQuestionsLength - 1){

                cout<<" ";
                cout<< *(WrongAnswers.get()+i);
                cout<<" ";
            }
            else if(*(WrongQuestions.get() +i) >= 10 && i == wrongQuestionsLength - 1){
                cout<<" ";
                cout<< *(WrongAnswers.get()+i);
            }
            else{
                cout<< *(WrongAnswers.get()+i);
                cout<<" ";
            }
        }
        cout<<endl;
        for (int i = 0; i <wrongQuestionsLength; i++){
            if (*(WrongQuestions.get() + i)>= 10 && i < wrongQuestionsLength - 1){
                cout<<" ";
                cout<< *(CorrectAnswers.get() + i);
                cout<<" ";
            }
            else if (*(WrongQuestions.get() +i) >= 10 && i == wrongQuestionsLength - 1){
                cout<<" ";
                cout<<*(CorrectAnswers.get() + i);
            }
            else{
                cout<<*(CorrectAnswers.get()+i);
                cout<<" ";
            }
        }
        cout<<endl;
    }
    *(ContestantScoreArrayHolder.get() + timesran) = (accuracy/count) * 100;
//cout<<endl;
}
/*
cout<<wrongQuestions[0]<<endl;
//cout<<*pointertotheWrongQuestions<<endl;
//cout<<*pointertoWrongAnswers<<endl;
//cout<<*pointertoCorrectAnswers<<endl;
for (int i = 0; i <wrongQuestionsLength; i++){
    cout<<wrongQuestions[i];
}
cout<<endl;
for (int i = 0; i <wrongQuestionsLength; i++){
    cout<<wrongQuestions[i];
}
cout<<endl;
*/

/*
contestantAnswerArray -= count;
pointertoCorrectAnswers -= count;
answerArray -=count;
pointertotheWrongQuestions -=count;
pointertoWrongAnswers -= count;
cout<<endl;
*/


void MathFunctions(shared_ptr<float[]> scoreArraypointer, int contestantnumber){
    bool swapped = false;
    float temp = 0;
    float mean = 0;
    float median = 0;
    vector<float> mode;
    map<float, int> GradesMap;
    shared_ptr<float[]> ContestantArray = scoreArraypointer;
    for (int i = 0; i < contestantnumber - 1; i++){
        for (int j = 0; j < contestantnumber - i - 1; j++){
            if ( *(ContestantArray.get() + j) > *(ContestantArray.get() + j + 1)){
                swap(*(ContestantArray.get() + j), *(ContestantArray.get() + j + 1));
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }

    for (int i = 0; i < contestantnumber; i++){
        // GradesMap.insert(pair<float,int>(*(ContestantArray.get() + i),1) );
        if (GradesMap.find(*(ContestantArray.get() + i)) == GradesMap.end()){
            GradesMap[*(ContestantArray.get() + i)] = 1;

        }
        else{
            GradesMap[*(ContestantArray.get()+ i)]++;
        }
        mean += *(ContestantArray.get() + i);
        //cout<<*(ContestantArray.get() + i)<<endl;
    }
    int highestFreq = 0;
    for (auto& it : GradesMap) {
        if (it.second > highestFreq){
            highestFreq = it.second;
        }
    }
    for (auto& it : GradesMap){
        if (it.second == highestFreq){
            mode.push_back(it.first);
        }
    }
    /*
    for (int i = 0; i < contestantnumber; i++){
        if (GradesMap[*(ContestantArray.get() + i)] == highestFreq){
            mode.push_back(*(ContestantArray.get() + i));
        }
    }
    */
    for (int i = 0; i < mode.size(); i++){
        cout<<"Start of Mode"<< i << " " <<mode.at(i)<<" ";
    }

    mean = mean/contestantnumber;
//cout<<mean<<endl;
    if (contestantnumber % 2 == 1){
        median = *(ContestantArray.get() + contestantnumber/2);
    }
    else if (contestantnumber % 2 == 0) {
        median = (*(ContestantArray.get() + contestantnumber/2)  + *(ContestantArray.get() + contestantnumber/2 - 1))/2  ;
    }
//cout<<median<<endl;
    cout<<endl;
    cout<<"Mean: "<<mean<<endl;
    cout<<"Median: "<<median<<endl;
    if(mode.size() == 1){
        cout<<"Mode: "<<mode.at(0)<<endl;
    }
    else{
        cout<<"Mode: ";
        int i = 0;
        while ( i < mode.size() - 1){
            cout<<mode.at(i)<<", ";
            i++;
        }
        cout<<mode.at(mode.size() -1)<<endl;
    }
}
void contestantReader(shared_ptr<string[]> answerkeypointer, int count, int contestantnumber){
    cout << count << endl;
    map<int, int> AccuracyMap;
    shared_ptr<float[]> ContestantScoreArrayHolder(new float[contestantnumber]) ;
    shared_ptr<string[]> answerkeypointerHolder = answerkeypointer;
    int timesran = 0;
    int linecount = 0;
    string line;
    string ID;
    shared_ptr<string[]>contestantAnswerspointer(new string[count]);
    fstream contestantreportFile;
    contestantreportFile.open(Reportbatch, ios::in|ios::out);
    while(getline(contestantreportFile,line)){
        linecount = 0;
        //cout<<"i am in the line";
        ID = line.substr(0,line.find(" "));
        //cout<<ID;
        line = line.substr(line.find(" ")+1);
        for (int i = 0; i < line.length(); i++){
            if(isalpha(line[i])){
                *(contestantAnswerspointer.get() + linecount) = line[i];
                linecount++;
            }
        }
        /*
        for (int i = 0; i < count; i++){
    cout<<*(contestantAnswerspointer.get()+i);
    }
   cout<<endl;
   */
        //pointertocontestantanswers -=count;
        //cout<<*pointertocontestantanswers;
        /*
        cout<<ID<<endl;
        for (int i = 0; i <count;i++){
            cout<<contestantAnswers[i];
        }
        */
        //cout<<endl;
        /*
        for (int i = 0; i < count; i++){
    cout<<*(answerkeypointerHolder.get()+i);
}
cout<<endl;
for (int i = 0; i < count; i++){
    cout<<*(contestantAnswerspointer.get()+i);
}
cout<<endl;
*/
        for (int i = 0; i < count; i++){
            if (*(answerkeypointerHolder.get() + i) != *(contestantAnswerspointer.get() + i)){
                if (AccuracyMap.find(i+1) == AccuracyMap.end()){
                    AccuracyMap[i+1] = 1;

                }
                else{
                    AccuracyMap[i+1]++;
                }
            }
        }

        compareTOAnswer(contestantAnswerspointer, ID,answerkeypointerHolder, count,ContestantScoreArrayHolder, timesran);
        timesran++;
        //break;
    }
    MathFunctions(ContestantScoreArrayHolder,contestantnumber);
    /*
     for (auto& it : AccuracyMap) {
        cout << it.first << ' '
             << it.second << '\n';
    }
    */
    cout<<endl;
    cout<<"MOST MISSED QUESTIONS"<<endl;

    for (auto& it : AccuracyMap){
        if (static_cast<float>(it.second) / static_cast<float>(contestantnumber) > .6 ){
            cout<<it.first<<"        "<<std::fixed<<std::showpoint<<std::setprecision(2)<<(static_cast<float>(it.second) / static_cast<float>(contestantnumber))*100<<"%"<<endl;
        }
    }
}

int main() {
    /* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */

    string Answertemp;  //variable for Answer Key filename


    cout << "Enter Answer Key Name: ";
    cin >> Answertemp;

    fstream infile(Answertemp, ios::binary);
    fstream outfile(answers, ios::binary);
    string line;
    if (infile)
        while (infile.good()) {
            getline(infile, line);
            if (line != "")
                outfile << line << "\n";
        }

    infile.close();
    outfile.close();

/* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */
    cout << "Enter Report File Name: ";
    cin >> Reportbatch;

    fstream BatchIn(Reportbatch, ios::binary);
    fstream BatchOut(report, ios::binary);
    string linebatch;
    if (BatchIn)
        while (BatchIn.good()) {
            getline(BatchIn, linebatch);
            if (linebatch != "")
                BatchOut << linebatch << "\n";
        }

    BatchIn.close();
    BatchOut.close();
    int count = 0;
    int contestantnumber = 0;
    //string line;
    // string *pointertoanswerkey;
    fstream answerkeyFile;
    fstream contestantfiles;
    contestantfiles.open(Reportbatch, ios::in|ios::out);
    while(getline(contestantfiles,line)){
        contestantnumber++;
    }
    cout << contestantnumber << endl;
    contestantfiles.clear();
    contestantfiles.close();
    //cout<<contestantnumber<<endl;
    answerkeyFile.open(Answertemp, ios::in|ios::out);
    while(answerkeyFile.good()){
        getline(answerkeyFile,line);
        count++;

    }
    //cout<<count<<endl;
    answerkeyFile.clear();
    answerkeyFile.close();
    shared_ptr<string[]> pointertoanswerkey(new string[count]);
    answerkeyFile.open(Answertemp, ios::in|ios::out);
    for (int i = 0; i < count; i++){
        getline(answerkeyFile,line);
        *(pointertoanswerkey.get() + i) = line;
    }
    //cout<<contestantnumber<<endl;
    //shared_ptr<int[]>ContestantScoreArray(new int[contestantnumber]);
    //int ScoreArray[contestantnumber];
    //int * scoreArrayPointer = ScoreArray;
    //pointertoanswerkey = pointertoanswerkey - count;

    contestantReader(pointertoanswerkey, count, contestantnumber);


/*
for (int i = 0; i < count; i++){
    cout<<*(pointertoanswerkey.get()+i);
}
*/
//loll
}