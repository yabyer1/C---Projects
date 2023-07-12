
// Abhay Iyer AXI210015
#include <memory>
#include <iostream>
#include<fstream>
#include <string>
#include <cstdio>
#include <map>
#include <iomanip>
using namespace std;
string Reportbatch = ""; //Will be used to store file name for Answer Key Input
void compareTOAnswer(shared_ptr<string[]> contestantAnswersArray, string id, shared_ptr<string[]> AnswerKeyArray, int count, shared_ptr<float[]> ContestantScoreArray, int timesran){
    int formattingcounter = 0;
    float accuracy = 0; //Will be used to calculate percentages
    shared_ptr<float[]> ContestantScoreArrayHolder = ContestantScoreArray;
    shared_ptr<int[]> WrongQuestions(new int[count]); //Will hold all the incorrect questions for console output
    shared_ptr<string[]> WrongAnswers(new string[count]); //Will hold all the wrong contestant answer choices for the question
    shared_ptr<string[]> CorrectAnswers(new string[count]);// Will hold all the correct answers for the questions which were answered wrong
    int wrongQuestionsLength = 0;
    shared_ptr<string[]> ContestantAnswer = contestantAnswersArray;
    shared_ptr<string[]> AnswerKey = AnswerKeyArray;
    for (int i = 0; i < count; i++){
        if(*(ContestantAnswer.get() + i) != *((AnswerKey.get())+ i)){ //If the answer the contestant has given is different than the correct answer, we must input each different aspect into the respective array
            *(WrongQuestions.get() + wrongQuestionsLength) = i+1; //This adds the question number
            *(WrongAnswers.get() + wrongQuestionsLength) =  *(ContestantAnswer.get() + i); //this adds the contestants answer
            *(CorrectAnswers.get() + wrongQuestionsLength) = *(AnswerKey.get() + i); // this adds the correct answer from the key
            wrongQuestionsLength++; //used as a custom count for all of these dynamic arrays to make sure they are all at the right index
        }
        if (*(ContestantAnswer.get() + i) == *(AnswerKey.get()+i)){
            accuracy++; //accuracy increases if the contestant gets the same answer as the answer key
            *(CorrectAnswers.get()+i) = *(AnswerKey.get() + i);
        }


        if (i == count - 1){ //During the last run of the loop, after we garner the data, we now can output the grade the constant got in the adequate format
            cout<<endl;
            cout<<id<<" - "<<std::fixed<<std::showpoint<<std::setprecision(2)<<(accuracy/static_cast<float>(count))*100<<endl;
        }

    }

    if (accuracy < static_cast<float>(count)){ // If the contestant didnt receive a 100, we need to output all the questions they didnt get right

        for (int i = 0; i < wrongQuestionsLength; i++){
            if (formattingcounter == 0){
                cout<< *(WrongQuestions.get()+ i); // for the first question we dont want a preceeding space, so the formattingcounter is used for this formatting
                formattingcounter++;
            }
            else{
                cout<<" ";
                cout<< *(WrongQuestions.get()+ i); //Rest of the incorrect questions can be outputted to the console as they are
            }

        }
        cout<<endl;
        formattingcounter = 0;
        for (int i = 0; i <wrongQuestionsLength; i++){
            if (*(WrongQuestions.get()+ i) >= 100 && i < wrongQuestionsLength - 1){ //if the question is a 3 digit number, make sure the spaces line up for the answers that are outputted below the respective question
                cout<<"  ";
                cout<<*(WrongAnswers.get()+i);
                cout<<" ";
            }
            else if (*(WrongQuestions.get() + i) >= 100 && i == wrongQuestionsLength - 1){ //Tests similar test case, only now if its the last question in the output
                cout<<"  ";
                cout<<*(WrongAnswers.get() + i);
            }
            else if (*(WrongQuestions.get() +i) >= 10 && i < wrongQuestionsLength - 1){ //if the question is a 2 digit number, make sure the spaces line up for the answers that are outputted below the respective question

                cout<<" ";
                cout<< *(WrongAnswers.get()+i);
                cout<<" ";
            }
            else if(*(WrongQuestions.get() +i) >= 10 && i == wrongQuestionsLength - 1){ //Tests similar test case, only now if its the last question in the output
                cout<<" ";
                cout<< *(WrongAnswers.get()+i);
            }
            else if (i == wrongQuestionsLength - 1){ //if its the last question
                cout<< *(WrongAnswers.get()+i);

            }
            else {
                cout<< *(WrongAnswers.get()+i); //All other test cases will have the wrong answers outputted in this way
                cout<<" ";
            }
        }
        cout<<endl;
        for (int i = 0; i <wrongQuestionsLength; i++){
            if (*(WrongQuestions.get()+ i) >= 100 && i < wrongQuestionsLength - 1){ //if the question is a 3 digit number, make sure the spaces line up for the answers that are outputted below the respective question
                cout<<"  ";
                cout<<*(CorrectAnswers.get()+i);
                cout<<" ";
            }
            else if (*(WrongQuestions.get() +i) >= 100 && i == wrongQuestionsLength - 1){ //Tests similar test case, only now if its the last question in the output
                cout<<"  ";
                cout<<*(CorrectAnswers.get() + i);
            }
            else if (*(WrongQuestions.get() + i)>= 10 && i < wrongQuestionsLength - 1){ //if the question is a 2 digit number, make sure the spaces line up for the answers that are outputted below the respective question
                cout<<" ";
                cout<< *(CorrectAnswers.get() + i);
                cout<<" ";
            }
            else if (*(WrongQuestions.get() +i) >= 10 && i == wrongQuestionsLength - 1){  //Tests similar test case, only now if its the last question in the output
                cout<<" ";
                cout<<*(CorrectAnswers.get() + i);
            }
            else if( i == wrongQuestionsLength - 1){ //if its the last question
                cout<< *(CorrectAnswers.get() + i);
            }
            else{
                cout<<*(CorrectAnswers.get()+i);  //All other test cases will have the correct answers outputted in this way
                cout<<" ";
            }
        }
        cout<<endl;
    }
    *(ContestantScoreArrayHolder.get() + timesran) = (accuracy/static_cast<float>(count)) * 100; //Add the contestant score into the correct array in the right format for later calculations
//cout<<endl;
}
void MathFunctions(shared_ptr<float[]> scoreArraypointer, int contestantnumber){
    bool swapped = false;
    float mean = 0;
    float median = 0;
    map<float, int> GradesMap; //Will be used to try and output frequency of the grades in order to pick out a mode
    shared_ptr<float[]> ContestantArray = scoreArraypointer;
    for (int i = 0; i < contestantnumber - 1; i++){ //Use a basic bubble sort in order to sort the array for the math function median
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
        if (GradesMap.find(*(ContestantArray.get() + i)) == GradesMap.end()){ //Map out the frequency of the grades. If the grade is already in the map, append the frequency, if not, add it to the map and set frequency to 1
            GradesMap[*(ContestantArray.get() + i)] = 1;

        }
        else{
            GradesMap[*(ContestantArray.get()+ i)]++;
        }
        mean += *(ContestantArray.get() + i); //Add up all elements within the array to find the total
    }
    int highestFreq = 0;
    int howmanyarethere = 0;
    for (auto& it : GradesMap) {
        if (it.second > highestFreq){
            highestFreq = it.second; //Find the highest frequency in the map for mode
        }
    }

    for (auto& it : GradesMap){
        if (it.second == highestFreq){
            howmanyarethere++; //Find the amount of mapped data which may be the mode, used to find a size for the array
        }
    }
    shared_ptr<float[]> mode(new float[howmanyarethere]);
    int placeholder = 0;
    for (auto& it : GradesMap){
        if (it.second == highestFreq){
            *(mode.get() + placeholder) = it.first; //If the element in the map has the highest frequency, add that element into the mode array
            placeholder++;
        }
    }
    mean = mean/static_cast<float>(contestantnumber); // divide the sum by the amount of elements to get mean
    if (contestantnumber % 2 == 1){ // if there is an odd number of elements in the contestants array, the median is simply the middle element in the list
        median = *(ContestantArray.get() + contestantnumber/2);
    }
    else if (contestantnumber % 2 == 0) { // if these is an even number of elements in the contestants array, the median is the average of the middle element and the middle minus 1 element
        median = (*(ContestantArray.get() + contestantnumber/2)  + *(ContestantArray.get() + contestantnumber/2 - 1))/2  ;
    }
    //Rest of the function is for formatting the info as we now have a mode array, a median and mean value
    cout<<endl;
    cout<<"Mean: "<<mean<<endl;
    cout<<"Median: "<<median<<endl;
    if(howmanyarethere == 1){ //if the size of the mode array is 1, we can just input it as is to the console
        cout<<"Mode: "<<*(mode.get())<<endl;
    }
    else{ // if the mode array is over 1, we want to input every mode to the console followed by a comma, until the last element, we then input the last element
        cout<<"Mode: ";

        for (int i = 0;i < howmanyarethere - 1; i++){
            cout<<*(mode.get() + i)<<", ";
        }
        cout<<*(mode.get() +(howmanyarethere-1))<<endl;
    }
}
void contestantReader(shared_ptr<string[]> answerkeypointer, int count, int contestantnumber){
    map<int, int> AccuracyMap; // Will be used for later Accuracy mapping of most Missed Questions
    shared_ptr<float[]> ContestantScoreArrayHolder(new float[contestantnumber]) ; //Will be used to hold the scores of each contestants for the later math manipulations
    shared_ptr<string[]> answerkeypointerHolder = answerkeypointer; //store the answerkey
    int timesran = 0;
    int linecount = 0;
    string line;
    string ID; //Every unique student ID
    shared_ptr<string[]>contestantAnswerspointer(new string[count]); //Answers from each contestant
    fstream contestantreportFile;
    contestantreportFile.open(Reportbatch, ios::in|ios::out);
    while(getline(contestantreportFile,line)){ // We traverse through the contestant file, and we start by storing the line in a string, then we parse the string in order to get the ID, and the raw data
        linecount = 0; // Used as a custom count for offset notation
        //cout<<"i am in the line";
        ID = line.substr(0,line.find(" "));  //The Respective ID of each student
        //cout<<ID;
        line = line.substr(line.find(" ")+1); // The answers of the students
        for (long unsigned int i = 0; i < line.length(); i++){
            if(isalpha(line[i])){ //Check if that index has a letter, if so, store it into the contestant answer array, then append the custom count
                *(contestantAnswerspointer.get() + linecount) = line[i];
                linecount++;
            }
        }

        for (int i = 0; i < count; i++){ //If the answer that has been
            if (*(answerkeypointerHolder.get() + i) != *(contestantAnswerspointer.get() + i)){ // If the answer given by the contestant doesnt match the Answer Key, we then add it into the Map. If the question is already in the map, we append the frequency, if not, we add it into the map with a count of 1
                if (AccuracyMap.find(i+1) == AccuracyMap.end()){
                    AccuracyMap[i+1] = 1;

                }
                else{
                    AccuracyMap[i+1]++;
                }
            }
        }

        compareTOAnswer(contestantAnswerspointer, ID,answerkeypointerHolder, count,ContestantScoreArrayHolder, timesran); // We now have the adequate data to call a comparison function between the contestant answer and the answer key and output the console
        timesran++;

    }
    MathFunctions(ContestantScoreArrayHolder,contestantnumber); // We now can call math functions since we are finished inputting the data from each contestant, this will be used to output mean, median and mode to the console

    cout<<endl;
    cout<<"MOST MISSED QUESTIONS"<<endl;

    for (auto& it : AccuracyMap){ //If the inaccuracy count for each respective question in the map is greater than .6 the total amount of questions, we then input these questions to the console in the adequate formatting
        if (static_cast<float>(it.second) / static_cast<float>(contestantnumber) > .6 ) {
            cout<<it.first<<'\t'<<std::fixed<<std::showpoint<<std::setprecision(2)<<(static_cast<float>(it.second) / static_cast<float>(contestantnumber))*100<<"%"<<endl;
        }


    }
    contestantreportFile.close();
}

int main() {

    string Answertemp;  //variable for Answer Key filename

    cout << "Enter Answer Key Name: ";
    cin >> Answertemp;
    string line;
    cout << "Enter Report File Name: ";
    cin >> Reportbatch;
    int count = 0; //Used to count the number of questions are in the Answers Text Files
    int contestantnumber = 0;
    //string line;
    // string *pointertoanswerkey;
    fstream answerkeyFile;
    fstream contestantfiles;
    contestantfiles.open(Reportbatch, ios::in|ios::out);
    while(getline(contestantfiles,line)){
        contestantnumber++; // Will be used to count the number of contestants in the Contestants File
    }
    contestantfiles.clear();
    contestantfiles.close();
    //cout<<contestantnumber<<endl;
    answerkeyFile.open(Answertemp, ios::in|ios::out);
    while(answerkeyFile.good()){
        getline(answerkeyFile,line);
        for (long unsigned int i = 0; i <line.length(); i++){
            if(isalpha(line[i])){
                count++; // Traverse through the Answer Key File, put every line into a string, then check every space if its a letter, if its a letter, append count
            }

        }
    }

    answerkeyFile.clear();
    answerkeyFile.close();
    shared_ptr<string[]> pointertoanswerkey(new string[count]); //Use smart Pointer to dynamically create an array to store all the correct answers from the answer key
    answerkeyFile.open(Answertemp, ios::in|ios::out);
    int g = 0; // Will be used as a custom count in order to use offset notation to append pointertoanswerkey
    while (answerkeyFile.good()){
        getline(answerkeyFile,line);
        for(long unsigned int j = 0; j < line.length(); j++ ){
            if(isalpha(line[j])){
                *(pointertoanswerkey.get() + g) = line[j]; //If that spot contains a letter, then store the letter within the array
                g++; //Append the custom count in order to get to the next unmarked spot
            }
        }
    }
    answerkeyFile.close();
    contestantReader(pointertoanswerkey, count, contestantnumber); //We have the answer key array, the amount of questions and the number of contestants, with this information, we can call contestant reader.

}