//Author: Swasti Mishra and Katie Nuchols
//Date: August 24th, 2021
//Professor: Emrich

#include <iostream>
#include <vector>

using namespace std;

int main(){
    //read in the file
    //run through and seperate data
    //while(cin)
    //store into 2d array going by lines
    //find matching information 
    //order matching information
    //print to user
    vector<vector<string>> storage;
    //string storage[50][6];
    string temp;
    vector<string> readin;
    while(cin >> temp){
        readin.push_back(temp);
        /*for(int i = 0; i <= 5; i++){
            storage[i][i] = temp;
        }*/
    }                                                                       //read everything into an initial vector that will store all of the information from the givven file
    //cout << readin.size() << ' ' << (readin.size()/6) << ' ' << storage.size() << '\n';
    int var = readin.size()/6;                                              //pull the size of input that you are looking at
    int yeah = 0;                                                           //set a variabel to iterate through the initial vector
    storage.resize(readin.size());                                          //resize the vector to allow you to add all of the needed information into it
    for(int j = 0; j < var; j++){                                           //goes threw each line in the file
        for(int i = 0; i < 6; i++){                                         //goes through each item in the line 
            storage[j].push_back(readin.at(yeah));
            //cout << storage[j].at(i) << ' ';
            yeah++;
        }
        //cout << endl;
    }
    for(int i = 0; i < var; i++){                                           //was gonna search threw the artists at position 2 to see if they match
                                                                            //kinda lost on what to do with matching though
        
    }
    return 0;
}