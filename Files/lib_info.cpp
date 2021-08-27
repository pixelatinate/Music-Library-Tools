//Author: Swasti Mishra and Katie Nuchols
//Date: August 24th, 2021
//Professor: Emrich

#include <iostream>
#include <vector>

using namespace std;

void Print(vector<vector<string>> album, vector<int> sets);
int strtoint(string number);

int main(){
    vector<vector<string>> storage;
    string temp;
    vector<string> readin;
    while(cin >> temp){
        readin.push_back(temp);
    }                                                                       //read everything into an initial vector that will store all of the information from the givven file
    int var = readin.size()/6;                                              //pull the size of input that you are looking at
    int yeah = 0;                                                           //set a variabel to iterate through the initial vector
    storage.resize(readin.size());                                          //resize the vector to allow you to add all of the needed information into it
    for(int j = 0; j < var; j++){                                           //goes threw each line in the file
        for(int i = 0; i < 6; i++){                                         //goes through each item in the line 
            storage[j].push_back(readin.at(yeah));
            yeah++;
        }
    }
    vector<int> matchingset;                                                //throw set of matching into it and then print out
    vector<vector<string>> Albumlisting;
    Albumlisting.resize(readin.size());
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

void Print(vector<vector<string>> album, vector<int> sets){                                         //use a prinf function so that everything is organized well
/*Artist: # of songs, total time
    Album: # of songs, total time
        track: song time
        keep going with info till done*/
    printf("%s: %d, total time\n        %s: %d, totaltime\n",
    album[sets.at(0)].at(2).c_str(), sets.size(), album[sets.at(0)].at(3).c_str(), sets.size());
    //print the head part of the album listing
    //we need to make a function that finds the total amount of time in thee file so that can be impemented into the code
    for(int i = 0; i < sets.size(); i++){
        printf("                %s: %s %s\n", album[sets.at(i)].at(5).c_str(),
         album[sets.at(i)].at(0).c_str(), album[sets.at(i)].at(1).c_str());
    }//this needs to be ordered correctly
    //remove the spacing and make it %8 or something. couldn't get it working right now 
}

int strtoint(string number){
    int changedvar;
    return changedvar; 
}