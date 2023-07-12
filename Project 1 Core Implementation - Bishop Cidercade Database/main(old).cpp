
// Abhay Iyer AXI210015
#include <iostream>
#include<fstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;
const string database = "database.dat";  
//your filestream for the database will connect to this variable

void addRecord(fstream &file, string name, int HighScore, string initials, int plays, float revenue){
    //file.clear();
file.open("sampledb.dat", ios::in|ios::out|ios::app);
file<<"\n"<<name <<", ";
file<<std::setw(9)<<std::setfill('0')<< HighScore<<", ";
file<< initials<<", ";
file<<std::setw(4)<<std::setfill('0')<< plays<<", ";
file<<"$"<<std::setw(7)<<std::setfill('0')<<std::fixed<<std::showpoint<< std::setprecision(2)<< revenue;
file<<endl;
file.close();
cout<<endl<<"RECORD ADDED"<<endl;
cout<<"Name: "<<name<<endl;
cout<<"High Score: "<<HighScore<<endl;
cout<<"Initials: "<<initials<<endl;
cout<<"Plays: "<<plays<<endl;
cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;

}

void print(string name){
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open("sampledb.dat", ios::in|ios::out);
    while (getline(file,line)) {
        if(line.find(name) != std::string::npos){
            line = line.substr(line.find(",")+2);
           string Hline =  line.substr(0, 9);
            for(int i = 0; i < Hline.length(); i++){
                if(Hline[i] != 0)
                    pointer = i;
                break;
            }
            HighScore = Hline.substr(pointer);
            line = line.substr(line.find(",")+2);
             initials = line.substr(0,3);
            line = line.substr(line.find(",")+2);
            string Pline = line.substr(0,4);
            for(int i = 0; i < Pline.length(); i++){
                if(Pline[i] != 0)
                    pointer = i;
                break;
            }
            plays = Pline.substr(pointer);
            revenue = stof(plays) * .25;
        }
        cout<<"Name: "<<name<<endl;
        cout<<"High Score: "<<HighScore<<endl;
        cout<<"Initials: "<<initials<<endl;
        cout<<"Plays: "<<plays<<endl;
        cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;
    }
}
void Updateprint(string name){
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open("sampledb.dat", ios::in|ios::out);
    while (getline(file,line)) {
        if (line.find(name) != std::string::npos) {
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
    cout<<"\n"<< name <<" FOUND"<<endl;
    cout<<"High Score: "<<HighScore<<endl;
        cout<<"Initials: "<<initials<<endl;
        cout<<"Plays: "<<plays<<endl;
        cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;


}
void HSprint(string name){
    fstream file;
    string line;
    string HighScore = "";
    string plays = "";
    string initials = "";
    float revenue = 0;
    int pointer = 0;
    file.open("sampledb.dat", ios::in|ios::out);
    while (getline(file,line)) {
        if (line.find(name) != std::string::npos) {
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
    cout<<"UPDATE TO high score - VALUE "<<HighScore<<endl;
    cout<<"Name: "<< name<<endl;
    cout<<"High Score: "<<HighScore<<endl;
    cout<<"Initials: "<<initials<<endl;
    cout<<"Plays: "<<plays<<endl;
    cout<<"Revenue: $"<<std::fixed<<std::showpoint<< std::setprecision(2)<<revenue<<endl;


}
bool searchRecord(string name){
    fstream file;
    int count = 0;
    string line;
file.open("sampledb.dat", ios::in|ios::out);
    while (getline(file,line)) {
     if(line.find(name) != std::string::npos   ){
     Updateprint(name);
     count++;
     }
    }

    if (count == 0){
        cout<<name <<" NOT FOUND";
        return false;
    }
return true;


}
void HSedit(string name, int HighScore){
fstream file;
string secondline;
string line;
int tellpointer = 0;
int counter = 0;
int insertionpointer = 0;
int linecounter = 0;
file.open("sampledb.dat", ios::in|ios::out);
 while (getline(file,line) && line.find(name) == std::string::npos){
     linecounter++;
 }
 //cout<<"Line Counter is "<<linecounter<<endl;
 file.clear();
 file.close();
 file.open("sampledb.dat", ios::in|ios::out);
    while (getline(file,line)) {
        if(line.find(name) != std::string::npos){
            insertionpointer = line.find(", ")+2;
            line = line.substr(line.find(", ") +2, 9);
            //cout<<line<<endl;
            string HScore = to_string(HighScore);
            //cout <<HScore<<endl;
            counter = 9 - HScore.length();
          for(int i = 0; i < counter; i++){
              line[i] = '0';
          }
           insertionpointer = insertionpointer + counter;
          //cout<<"insertion pointer is "<<insertionpointer<<endl;
          line = line.substr(counter);
          for(int i = 0; i < HScore.length(); i++){
              line[i] = HScore[i];
          }
          //cout<<"Line is now "<<line<<endl;
          secondline = line;
       
        }
    }
    
    file.clear();
    file.close();
    file.open("sampledb.dat", ios::in|ios::out);
    for (int i = 0; i < linecounter; i++){
        getline(file,line);
       tellpointer = file.tellg();
    }
     file.seekg(tellpointer + insertionpointer);
        file<<secondline;
        file.flush();
       file.close();
       file.clear();
       //file.open("sampledb.dat", ios::in|ios::out);
       /*
       while(getline(file,line)){
           cout<<line<<endl;
       }
       */
        HSprint(name);
}
void Iedit(string name, string initials){
    fstream file;
    string line;
    file.open("sampledb.dat", ios::in|ios::out);
    while (getline(file,line)) {
        if(line.find(name) != std::string::npos   ){
           line = line.substr(line.find(initials), 3);
           line.replace(0,3,initials);
        }
        cout<<line;
    }
}
void Pledit(string name, int plays){
    fstream file;
    string line;
    file.open("sampledb.dat", ios::in|ios::out);
    while (getline(file,line)) {
        if(line.find(name) != std::string::npos){
            line = line.substr(line.find("  $") - 5, line.find("  $")-1);
            if (plays < 1000){
                file << std::setfill('0') << std::setw(4) << plays;
            }
        }
        cout<<line;
    }
}

//class MyType;
/*
    void deleteRecord(string name){
    fstream newfile;
    fstream file;
    string line;
    file.open("sampledb.dat",ios::in|ios::out);
    while (getline(file,line)) {
        if(line.find(name) != std::string::npos   ){
            line = line.substr(line.find("  $") - 5, line.find("  $")-1);
            if (plays < 1000){
                file << std::setfill('0') << std::setw(4) << plays;
            }
        }
        cout<<line;
    }
}
 */
void FileCopier(string batch){
    string line = "";string name = ""; int HighScore = 0; string initials = ""; int plays = 0; float revenue = 0;
    fstream file;
    fstream newfile;
    file.open(batch, ios::in);
    while(file.good()){
        while(getline(file,line)){
            std::cout << "COMMAND: " << line << endl;
            //if(line == "") break;
            if(line[0]  == '1'){
                int index = line.find("\" ");
                name = line.substr(3,index - 3);
                line = line.substr(index+2);
                //name.erase(remove(name.begin(), name.end(), '\"'), name.end());
                HighScore = stoi(line.substr(0, line.find(" ")));
                line = line.substr(line.find(" ")+1);
                initials = line.substr(0, 3);
                line = line.substr(4);
                plays = stoi(line.substr(0,line.find(" ")));
                line = line.substr(line.find(" "));
                revenue = stof(line.substr(line.find("$")+1,4));
                addRecord( newfile,  name, HighScore, initials, plays,  revenue);
                
            }
            else if(line[0] == '2'){
                line = line.substr(2);
                name = line;
                searchRecord(name);
              
            }
           else if (line[0] == '3'){
                int fieldnum = 0;
                name = line.substr(3,line.find("\" ")-3);
                line = line.substr(line.find("\" ")+2);
                //cout<<name<<endl;
               // cout<<line<<endl;
                if (line[0] == '1'){
                     fieldnum = 1;
                     line = line.substr(2);
                     HighScore = stoi(line);
                    
                    HSedit(name, HighScore);
                    
                }
                if (line[0] == '2'){
                     fieldnum = 2;
                     line = line.substr(2);
                     initials = line;
                     Iedit(name, initials);
                  
                }
                if (line[0] == '3'){
                     fieldnum = 3;
                     line = line.substr(2);
                     plays = stoi(line);
                     Pledit(name,plays);
                     

                }
                //cout<<endl;
                //cout<<fieldnum;
            }
        }
    }
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
        FileCopier(batch);
       // addRecord(outfile, "high", 30, "ABI", 30, 40.03240);
}