// Project 01: Music Library Tool
// The goal of this project is to reorganize a music discography file 
//      into something that's easier to understand. 
// COSC 302
// Swasti Mishra and Katie Nuchols
// Date: August 24th, 2021
// Professor Emrich

#include <iostream>
#include <vector>

using namespace std;

int strtoint(string number);
void Print(vector<vector<string>> album, vector<int> sets);
// Functions

int main(){
    string temp;
    vector<string> readin;
    vector<vector<string>> storage;
    // Variables 
    
    while(cin >> temp){
        for ( int i = 0 ; i < temp.size() ; i++ ){
            if ( temp[i] == '_' ){
            temp[i] = ' ' ;
            }
        }
        readin.push_back(temp);      
    }
    // Reads all the information into a temporary vector of strings
    //      using the string variable "temp". Also replaces the underscores
    //      with spaces right away

    int iterator = 0;
    int var = readin.size()/6;  // *We need to rename this variable bc it's not apparent what it does from the name alone
    // Variables

    storage.resize(readin.size());
    // Resizes our official two-dimensional vector so that there's space for 
    //      the data we're about to put in  

    for(int j = 0; j < var; j++){
        for(int i = 0; i < 6; i++){
            storage[j].push_back(readin.at(iterator));
            iterator++;
        }
    }
    // First goes through each line in the file, and then goes through each 
    //      item in the line, pushes them back into the storage vector, and 
    //      then iterates

    // I haven't cleaning this section up yet because it needs more work

    vector<int> matchingset;                                                //throw set of matching into it and then print out
    vector<vector<string>> Albumlisting(readin.size());
    

    int used = 0;
    for(int i = 0; i < var-1; i++){                                         //was gonna search threw the artists at position 2 to see if they match
                                                                            //kinda lost on what to do with matching though
                                                                            //looking at this http://www.cplusplus.com/forum/general/45549/
                                                                            //for some inspiration on how to find the matching artists
        for(int j = 0; j < var; j++){
            if(storage[j].at(2) == storage[i].at(2)){
                matchingset.push_back(j);
            }                                                               //finds all of the matching ones in the set
        }
        Print(storage, matchingset);
    //this will be so that there is no overlapping files printed more than once or we can just implement a count that might work better but this has errors right now
       /* for(int m = 0; m < matchingset.size(); m++){
            storage.erase(storage.begin() + matchingset.at(m));
        }
        used =+ matchingset.size();
        cout << used;
        storage.shrink_to_fit();*/
        matchingset.erase(matchingset.begin(), matchingset.end());
    }
    return 0;
}

// End of section I haven't cleaned up yet, the print below is clean

int titleSpacing = 8 ;
int songSpacing = 16 ;

void Print(vector<vector<string>> album, vector<int> sets){
    printf("%s: %d, total time\n %8s: %d, total time\n",
    album[sets.at(0)].at(2).c_str(), sets.size(), album[sets.at(0)].at(3).c_str(), sets.size());
    // * we need to make a function that finds the total amount of time in the file so that can be impemented into the code
    
    for(int i = 0; i < sets.size(); i++){
        printf("%16s: %s %s\n", album[sets.at(i)].at(5).c_str(),
        album[sets.at(i)].at(0).c_str(), album[sets.at(i)].at(1).c_str());
    }

}
// Finally prints the cleaned data

// Artist: # of songs, total time
//         Album: # of songs, total time
//                 track: song time
// it's 8 spaces indented for the album and sixteen for the track

int strtoint(string number){
    int changedvar;
    return changedvar; 
}