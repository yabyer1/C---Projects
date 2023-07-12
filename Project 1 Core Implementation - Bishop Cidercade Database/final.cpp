
// Abhay Iyer AXI210015
#include <iostream>
#include<fstream>
#include <string>
#include <cstdio>

#include <iomanip>

using namespace std;
const string database = "database.dat";
//your filestream for the database will connect to this variable
int timescounter = 0;//needed for console formatting
bool NothingAdded = true; //Needed for console formatting
void addRecord(string name, int HighScore, string initials, int plays, float revenue){ // Will take each parameter, and insert it into the file

    fstream file;
    //file.clear();
    string line = "";
/*
    file.open(database, ios::in|ios::out|ios::app);
    while(getline(file,line)){
        if ((line.find(name) != std::string::npos)){
            return;
        }
    }
    file.clear();
    file.close();
*/
    file.open(database, ios::in|ios::out|ios::app); //open the file
    file<<name <<", "; // start adding the parameters
    file<<std::setw(9)<<std::setfill('0')<< HighScore<<", ";
    file<< initials<<", ";
    file<<std::setw(4)<<std::setfill('0')<< plays<<", ";
    file<<"$"<<std::setw(7)<<std::setfill('0')<<std::fixed<<std::showpoint<< std::setprecision(2)<< revenue; //use appropriate formatting
    file<<endl;
    file.close();

    if (timescounter == 0 && NothingAdded == true){
        cout<<"RECORD ADDED"<<endl; // print statement takes all the parameters inputted into the database and prints to the console
        cout<<"Name: "<<name<<endl;
        cout<<"High Score: "<<HighScore<<endl;
        cout<<"Initials: "<<initials<<endl;
        cout<<"Plays: "<<plays<<endl;
        cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    }
    else{
        cout<<"\n"<<"RECORD ADDED"<<endl; // print statement takes all the parameters inputted into the database and prints to the console
        cout<<"Name: "<<name<<endl;
        cout<<"High Score: "<<HighScore<<endl;
        cout<<"Initials: "<<initials<<endl;
        cout<<"Plays: "<<plays<<endl;
        cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    }
    timescounter++;
    NothingAdded = false;
    file.close();
}
void Updateprint(string name, int count){ //Used if the search record function finds the name, if the search record found more than one instance of the name, thats how count gets appended
    int namecounter = 0; // initialize all the useful variables
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) {
        if (line.find(name) != std::string::npos) {
            namecounter++; //keep track of how many lines contain the name of interest
            if (namecounter == count){
                name = line.substr(0,line.find(",")); // start to parse the string in order to get the variables of interest to be printed to console
                line = line.substr(line.find(",") + 2);
                string Hline = line.substr(0, 9);
                for (int i = 0; i < Hline.length(); i++) {
                    if (Hline[i] != '0'){ //Find where the preceding zeroes end and the highscore starts

                        pointer = i;
                        break;
                    }
                }
                HighScore = Hline.substr(pointer,Hline.length() - pointer);
                line = line.substr(line.find(",") + 2);
                initials = line.substr(0, 3);
                line = line.substr(line.find(",") + 2);
                string Pline = line.substr(0, 4);
                for (int i = 0; i < Pline.length(); i++) { // find where the preceding zeroes end and the plays starts
                    if (Pline[i] != '0'){
                        pointer = i;
                        break;
                    }
                }
                plays = Pline.substr(pointer);
                revenue = stof(plays) * .25;
            }
        }

    }
    cout<<"\n"<< name <<" FOUND"<<endl; // print all the appropriate variables tot he console
    cout<<"High Score: "<<HighScore<<endl;
    cout<<"Initials: "<<initials<<endl;
    cout<<"Plays: "<<plays<<endl;
    cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    NothingAdded = false;
    file.close();
}
void HSprint(string name){
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) {
        if (name == line.substr(0, line.find(","))) { //Similar tot he previous function, once we find the line which contains the name, we start splitting up the aspects of the line, and store them in their respective variables in order to be later displayed on the console
            name = line.substr(0,line.find(","));
            line = line.substr(line.find(",") + 2);
            string Hline = line.substr(0, 9);
            for (int i = 0; i < Hline.length(); i++) {
                if (Hline[i] != '0'){

                    pointer = i;
                    break;
                }
            }
            HighScore = Hline.substr(pointer,Hline.length() - pointer);
            line = line.substr(line.find(",") + 2);
            initials = line.substr(0, 3);
            line = line.substr(line.find(",") + 2);
            string Pline = line.substr(0, 4);
            for (int i = 0; i < Pline.length(); i++) {
                if (Pline[i] != '0'){
                    pointer = i;
                    break;
                }
            }
            plays = Pline.substr(pointer);
            revenue = stof(plays) * .25;
        }
    }
    cout<<"\n"<< name <<" UPDATED"<<endl;
    cout<<"UPDATE TO high score - VALUE "<<HighScore<<endl; //used in tandem with the HSEdit function that updates High Score
    cout<<"Name: "<< name<<endl;
    cout<<"High Score: "<<HighScore<<endl;
    cout<<"Initials: "<<initials<<endl;
    cout<<"Plays: "<<plays<<endl;
    cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    NothingAdded = false;
    file.close();
}
void PLprint(string name){
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) { //As we loop through the file, once we find the line containing the name, we start breaking the parts of the line up, in order to get the correct information for later display on the console
        if (name == line.substr(0,line.find(","))) {
            name = line.substr(0,line.find(","));
            line = line.substr(line.find(",") + 2);
            string Hline = line.substr(0, 9);
            for (int i = 0; i < Hline.length(); i++) {
                if (Hline[i] != '0'){

                    pointer = i;
                    break;
                }
            }
            HighScore = Hline.substr(pointer,Hline.length() - pointer);
            line = line.substr(line.find(",") + 2);
            initials = line.substr(0, 3);
            line = line.substr(line.find(",") + 2);
            string Pline = line.substr(0, 4);
            for (int i = 0; i < Pline.length(); i++) {
                if (Pline[i] != '0'){
                    pointer = i;
                    break;
                }
            }
            plays = Pline.substr(pointer);
            revenue = stof(plays) * .25; // Re-Update Revenue
        }
    }
    cout<<"\n"<< name <<" UPDATED"<<endl;
    cout<<"UPDATE TO plays - VALUE "<<plays<<endl; // Used in tandem with the PLEdit function
    cout<<"Name: "<< name<<endl;
    cout<<"High Score: "<<HighScore<<endl;
    cout<<"Initials: "<<initials<<endl;
    cout<<"Plays: "<<plays<<endl;
    cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    NothingAdded = false;
    file.close();
}
void Iprint(string name){
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) {
        if (name == line.substr(0,line.find(","))) { //Once we find the name, we can start parsing the string
            name = line.substr(0,line.find(",")); //Use the commas in order to appropriately find the variables
            line = line.substr(line.find(",") + 2);
            string Hline = line.substr(0, 9);
            for (int i = 0; i < Hline.length(); i++) {  // Necessary in order to see where the preceeding zeroes end
                if (Hline[i] != '0'){

                    pointer = i;
                    break;
                }
            }
            HighScore = Hline.substr(pointer,Hline.length() - pointer);
            line = line.substr(line.find(",") + 2);
            initials = line.substr(0, 3);
            line = line.substr(line.find(",") + 2);
            string Pline = line.substr(0, 4);
            for (int i = 0; i < Pline.length(); i++) { // Want to ignore the preceding zeroes
                if (Pline[i] != '0'){
                    pointer = i;
                    break;
                }
            }
            plays = Pline.substr(pointer);
            //cout<<"plays is"<<plays;
            revenue = stof(plays) * .25;
        }
    }
    cout<<"\n"<< name <<" UPDATED"<<endl;
    cout<<"UPDATE TO initials - VALUE "<<initials<<endl; //Used in tandem with the IEdit
    cout<<"Name: "<< name<<endl;
    cout<<"High Score: "<<HighScore<<endl;
    cout<<"Initials: "<<initials<<endl;
    cout<<"Plays: "<<plays<<endl;
    cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    NothingAdded = false;
    file.close();
}
void searchRecord(string name){
    fstream file;
    int count = 0;
    string line;
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) {
        if(line.find(name) != std::string::npos   ){ //If we find the name while looping through the file, we increment count and call UpdatePrint.
            //cout<< "I am running";
            count++; //Necessary if there is more than one game which shares a component of a name
            Updateprint(name, count);

        }
        //cout<<"in regular loop";
    }

    if (count == 0){
        cout<<name <<" NOT FOUND"; //If there isnt a match
        //return false;
    }
//return true;
    file.clear();
    file.close();

}
void HSedit(string name, int HighScore){
    //cout<<name;
    fstream file;
    string secondline;
    string line;
    int tellpointer = 0;
    //int counter = 0;
    int insertionpointer = 0;
    int linecounter = 0;
    string HScore = "";
    file.open(database, ios::in|ios::out);
    while (getline(file,line) && name != line.substr(0,line.find(","))){
        linecounter++; //Need a line count so that we can later find out where to reinsert the new string
    }
    //cout<<"Line Counter is "<<linecounter<<endl;
    file.clear();
    file.close();
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) {
        if(name == line.substr(0, line.find(","))){
            insertionpointer = line.find(", ")+2; //Find where to position the pointer for later usage
            line = line.substr(line.find(", ") +2, 9); //The highscore
            HScore = to_string(HighScore); //turn the parameter into a string
        }
    }

    file.clear();
    file.close();
    file.open(database, ios::in|ios::out);
    for (int i = 0; i < linecounter; i++){
        getline(file,line);
        tellpointer = file.tellg();
    }
    file.seekg(tellpointer + insertionpointer); //Reopen file, iterate through the lines to find the correct position, now insert the string
    file<<std::setw(9)<<std::setfill('0')<< HScore;
    file.flush();
    file.close();
    file.clear();
    HSprint(name); // console output
}
void Iedit(string name, string initials){ //Similar logic as HSedit, but now for Initials
    fstream file;
    string line;
    string secondline;
    int insertionpointer = 0;
    int linecounter = 0;
    int tellpointer = 0;
    //cout<<initials<<endl;
    file.open(database, ios::in|ios::out);
    while (getline(file,line) && name != line.substr(0,line.find(","))){
        linecounter++; //Count lines for later usage
    }
    //cout<<linecounter;
    file.clear();
    file.close();
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) {
        if(name == line.substr(0,line.find(","))){
            insertionpointer  = line.find(" $")-10; // Find where there is a space followed by a $, and use as reference for the pointer
            line = line.substr(line.find(" $")-10, 3);
            //cout<< insertionpointer<<endl;
            // cout<<line<<endl;
            line.replace(0,3,initials); //String now is just the initials
            secondline = line; //Store string into second string for safekeeping
            // cout<< secondline<<endl;
        }
    }
    file.clear();
    file.close();
    file.open(database, ios::in|ios::out);
    for (int i = 0; i < linecounter; i++){
        getline(file,line);
        tellpointer = file.tellg(); // Find where in file the pointer is, after looping the appropriate amount of lines
    }
    file.seekg(tellpointer + insertionpointer);
    file<<secondline;//Input the initials
    file.flush();
    file.close();
    file.clear();

    Iprint(name); //Call Iprint for the console output
}

void Pledit(string name, int plays){
    fstream file;
    string line;
    string secondline;
    int insertionpointer = 0;
    int tellpointer = 0;
    int linecounter = 0;
    //int counter = 0;
    float revenue = plays * .25;
    string playstring = "";
    //string zeroplacer = "";
    //cout<<revenue;
    file.open(database, ios::in|ios::out);
    while (getline(file,line) && name != line.substr(0, line.find(","))){
        linecounter++; //Find the line number for later locating
    }
    //cout<<linecounter;
    file.clear();
    file.close();
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) {
        if(name == line.substr(0,line.find(","))){
            //cout<<"in the loop";
            insertionpointer = line.find(" $") - 5; //Finds where the plays start in the line
            line = line.substr(line.find(" $") - 5, 4); //Finds the string where plays is located
            playstring = to_string(plays);  // convert to a string so we can insert with formatting

        }

    }
    //cout<< insertionpointer<<endl<< secondline;
    file.clear();
    file.close();
    file.open(database, ios::in|ios::out);
    for (int i = 0; i < linecounter; i++){
        getline(file,line);
        tellpointer = file.tellg();
    }
    file.seekg(tellpointer + insertionpointer); //Find the spot in the file once again for reinsertion
    file<<std::setw(4)<<std::setfill('0')<<playstring;  //Putting in the new plays, formatted correctly
    tellpointer = file.tellg();
    file.seekg(tellpointer+3); // Find where the revenue starts
    file<<std::setw(7)<<std::setfill('0')<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;  //Input revenue with correct formatting
    file.flush();
    file.close();
    file.clear();
    PLprint(name); //Call the print function

}

void deleteRecordPrinter(string name){
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open(database, ios::in|ios::out);
    while (getline(file,line)) { //While iterating through the file, find th eline where the name is located, then start parsing the string to get the correct information to be inputted to the console
        if (name == line.substr(0,line.find(","))) {
            name = line.substr(0,line.find(","));
            line = line.substr(line.find(",") + 2);
            string Hline = line.substr(0, 9);
            for (int i = 0; i < Hline.length(); i++) {
                if (Hline[i] != '0'){

                    pointer = i;
                    break;
                }
            }
            HighScore = Hline.substr(pointer,Hline.length() - pointer);
            line = line.substr(line.find(",") + 2);
            initials = line.substr(0, 3);
            line = line.substr(line.find(",") + 2);
            string Pline = line.substr(0, 4);
            for (int i = 0; i < Pline.length(); i++) {
                if (Pline[i] != '0'){
                    pointer = i;
                    break;
                }
            }
            plays = Pline.substr(pointer);
            revenue = stof(plays) * .25;
        }
    }
    cout<<"\n"<<"RECORD DELETED"<<endl; //Console output for deletion
    cout<<"Name: "<< name<<endl;
    cout<<"High Score: "<<HighScore<<endl;
    cout<<"Initials: "<<initials<<endl;
    cout<<"Plays: "<<plays<<endl;
    cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    NothingAdded = false;
    file.clear();
}
void deleteRecord(string name){
    ofstream newfile; //Dummy file which holds the temporary file
    fstream file; // Will access the current file
    string line;
    int linecounter = 0;
    int currentline = 0;
    deleteRecordPrinter(name);
    file.open(database, ios::in|ios::out);
    while (getline(file,line)){
        if (name != line.substr(0,line.find(","))){
            linecounter++; //Count to make sure the linespacing stays consistent
        }
    }
    //cout<<"line counter is: "<<linecounter;
    file.clear();
    file.close();
    newfile.open("temp.txt", ios::in|ios::out);
    file.open(database,ios::in|ios::out);
    while (getline(file,line) ) {
        //cout<<line;
        if (name != line.substr(0,line.find(","))){ //If the names dont match in the current file, add it to the new file
            // cout<< "In the if statement";
            newfile << line;
            if (currentline < linecounter){ // As long as we arent on the last line of the file, keep adding the \n
                currentline++;
                newfile<<"\n";
            }
        }

    }
    remove(database.c_str()); //Replace the old database file with the temporary file and rename the temporary file
    rename("temp.txt", database.c_str());
    newfile.clear();
    newfile.close();
    newfile.open("temp.txt"); //Open a new temp text file if there is more delete record functions, without this command, if there is another delete command, it doesn't display properly
}

void FileCopier(string batch){
    string line = "";
    string name = "";
    int HighScore = 0;
    string initials = "";
    int plays = 0;
    float revenue = 0;
    fstream file;
    fstream newfile;
    string Hd = ""; //Will be used for input validation
    int invalidcounter = 0; //Will be used for input validation
    file.open(batch, ios::in); //Traverse the batch File
    while(file.good()){
        while(getline(file,line)){
            //std::cout << "COMMAND: " << line << endl;
            //if(line == "") break;
            if(line[0]  == '1') { // If the first character is a 1 on the line, we want to parse the line in order to get the appropriate parameters to call AddRecord
                int index = line.find("\" ");
                name = line.substr(3, index - 3);
                Hd = name;
                for (int i = 0; i < Hd.length(); i++){
                    if(!(isalnum(Hd[i])||ispunct(Hd[i]) || isspace(Hd[i]))){ //input validation for Name (to make it match the criteria)
                        invalidcounter++;
                    }
                }
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                // cout<<"my name is "<< name<<endl;
                line = line.substr(index + 2);
                //name.erase(remove(name.begin(), name.end(), '\"'), name.end());
                Hd = line.substr(0, line.find(" "));
                // cout<< "String Hd IS "<<Hd<<endl;
                invalidcounter = 0;
                if (Hd.length() > 9 || Hd.length() < 1){
                    invalidcounter++;
                }
                for (int i = 0; i < Hd.length(); i++) {
                    if (isdigit(Hd[i]) == false || !(isprint(Hd[i]))) { //Input Validation
                        invalidcounter++;
                        //cout<< Hd[i]<<endl;
                    }
                }

                //cout<< "Invalid Counter is: "<<invalidcounter<<endl;
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                HighScore = stoi(line.substr(0, line.find(" ")));


                line = line.substr(line.find(" ") + 1);
                Hd = line.substr(0,3);
                //cout <<"Hd is "<<Hd<<"Done"<<endl;
                for (int i = 0; i < Hd.length(); i++){
                    if(!(isprint(Hd[i])) || isspace(Hd[i])){
                        invalidcounter++;
                    }
                }
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                initials = line.substr(0, 3);
                Hd = initials;
                for (int i = 0; i < Hd.length(); i++){
                    if (! (isalnum(Hd[i])||ispunct(Hd[i]))){
                        invalidcounter++;
                    }
                }
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                line = line.substr(4);
                Hd = line.substr(0, line.find(" "));
                if (Hd.length() < 1 || Hd.length() > 4) {
                    invalidcounter++;
                }
                for (int i = 0; i < Hd.length(); i++) {
                    if (!(isdigit(Hd[i])) || !(isprint(Hd[i]))) {
                        invalidcounter++;
                    }

                }

                //cout<< "Invalid Counter is: "<<invalidcounter<<endl;
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                plays = stoi(line.substr(0, line.find(" ")));
                line = line.substr(line.find(" "));
                Hd = line.substr(line.find("$")+1);
                if (!(Hd.find("."))){
                    invalidcounter++;
                }
                Hd = Hd.substr(Hd.find(".")+1);
                if (Hd.length() < 2){
                    invalidcounter++;
                }
                revenue = stof(line.substr(line.find("$") + 1));
                if (revenue <1 || revenue > 9999){
                    invalidcounter++;
                }
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                //cout<< "Revenue is "<< revenue<<endl;
                addRecord(name, HighScore, initials, plays, revenue); //If the invalid counter = 0, after all input validation, we call addrecord

            }
            else if(line[0] == '2'){ // If the first character is a 2 on the line, we want to parse the line in order to get the appropriate parameters to call searchRecord
                line = line.substr(2);
                name = line;
                Hd = name;
                for (int i = 0; i < Hd.length(); i++){
                    if(!(isalnum(Hd[i])||ispunct(Hd[i]) || isspace(Hd[i]))){
                        invalidcounter++;
                    }
                }
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                searchRecord(name); //If the invalid counter = 0, after all input validation, we call searchrecord

            }
            else if (line[0] == '3'){ //If the first character is a 3 on the line, we want to parse the line in order to get the appropriate parameters to call Edit Record
                // int fieldnum = 0;
                name = line.substr(3,line.find("\" ")-3);
                Hd = name;
                for (int i = 0; i < Hd.length(); i++){
                    if(!(isalnum(Hd[i])||ispunct(Hd[i]) || isspace(Hd[i]))){
                        invalidcounter++;
                    }
                }
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                line = line.substr(line.find("\" ")+2); //Parse string to locate Field Number
                //cout<<name<<endl;
                // cout<<line<<endl;
                if (line[0] == '1'){ //If the Field Number is 1, we want to get the parametrs for HSedit
                    //fieldnum = 1;
                    string Hd = line.substr(2);
                    line = line.substr(2);
                    if (Hd.length() > 9 || Hd.length() < 1){
                        invalidcounter++;
                    }
                    for (int i = 0; i < Hd.length(); i++) {
                        if (!(isdigit(Hd[i])) || !(isprint(Hd[i]))) { //Input Validation
                            invalidcounter++;
                        }

                    }
                    //cout<< "Invalid Counter is: "<<invalidcounter<<endl;
                    if (invalidcounter > 0){
                        continue;
                    }
                    invalidcounter = 0;
                    HighScore = stoi(line);

                    HSedit(name, HighScore); //If the invalid counter = 0, after all input validation, we call HSedit

                }
                if (line[0] == '2'){ //If the field Number is 2, we want to get the parameters for Iedit

                    //fieldnum = 2;
                    Hd = line.substr(2);
                    if (Hd.length() > 3){
                        continue;
                    }

                    line = line.substr(2);
                    //cout<< line<<endl;
                    initials = line;
                    Hd = initials;
                    for (int i = 0; i < Hd.length(); i++){
                        if (!(isalnum(Hd[i])||ispunct(Hd[i]))){
                            invalidcounter++;
                        }
                    }
                    if (invalidcounter > 0){
                        continue;
                    }
                    invalidcounter = 0;
                    Iedit(name, initials); //If the invalid counter = 0, after all input validation, we call Iedit

                }
                if (line[0] == '3'){ //If the field Number is 2, we want to get the parameters for Pledit
                    //fieldnum = 3;
                    string Hd = line.substr(2);
                    line = line.substr(2);
                    if (Hd.length() > 4 || Hd.length() < 1){
                        invalidcounter++;
                    }
                    for (int i = 0; i < Hd.length(); i++) {
                        if (!(isdigit(Hd[i])) || !(isprint(Hd[i]))) {
                            invalidcounter++;
                        }

                    }
                    //cout<< "Invalid Counter is: "<<invalidcounter<<endl;
                    if (invalidcounter > 0){
                        continue;
                    }
                    invalidcounter = 0;
                    plays = stoi(line);
                    Pledit(name,plays); //If the invalid counter = 0, after all input validation, we call Pledit


                }
                //cout<<endl;
                //cout<<fieldnum;
            }
            else if(line[0] == '4'){ //If the first character is a 4 on the line, we want to parse the line in order to get the appropriate parameters to call Delete Record
                name = line.substr(2);
                Hd = name;
                for (int i = 0; i < Hd.length(); i++){
                    if(!(isalnum(Hd[i])||ispunct(Hd[i]) || isspace(Hd[i]))){
                        invalidcounter++;
                    }
                }
                if (invalidcounter > 0){
                    continue;
                }
                invalidcounter = 0;
                //cout<< name;
                deleteRecord(name); //If the invalid counter = 0, after all input validation, we call deleteRecord
            }
        }
    }
    file.close();
    cout<<endl; //Need an endline after all the console commands have been called in order to comply with formatting
}

int main() {

/* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */

    string temp;  //variable for database filename
    string batch; //variable for batch filename

    cout << "Enter Database Name: ";
    cin >> temp;

    ifstream infile(temp, ios::binary);
    ofstream outfile(database, ios::binary);
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
    cout << "Enter Batch File Name: ";
    cin >> batch;

    ifstream BatchIn(temp, ios::binary);
    ofstream BatchOut(database, ios::binary);
    string linebatch;
    if (BatchIn)
        while (BatchIn.good()) {
            getline(BatchIn, linebatch);
            if (linebatch != "")
                BatchOut << linebatch << "\n";
        }

    BatchIn.close();
    BatchOut.close();

    //add your code for main here
    //data.open("batch.txt",ios::in);
    FileCopier(batch); //Call File Copier in order for the Batch File to be read
    //fstream file;
    /*
    file.open(database, ios::in|ios::out|ios::app);
    file<<"\n"; //For formatting the file with a last new line
    file.close();
    */
    // addRecord(outfile, "high", 30, "ABI", 30, 40.03240);
    //hi
    //final
    //lol
    //updatedversion7
}
