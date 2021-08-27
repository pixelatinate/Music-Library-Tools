//Author: Swasti Mishra and Katie Nuchols
//Date: August 24th, 2021
//Professor: Emrich

#include <iostream>
#include <vector>

using namespace std;

void Print(vector<vector<string>>);

int main(){
    
    string temp;
    vector<string> readin;
    vector<vector<string>> storage;
    //string storage[50][6];
    

    while(cin >> temp){
        readin.push_back(temp);
    }                                                                       //read everything into an initial vector that will store all of the information from the givven file
    
    int var = readin.size()/6;                                              //pull the size of input that you are looking at
    int yeah = 0;         
                                                      //set a variabel to iterate through the initial vector
    storage.resize(readin.size());  
                                            //resize the vector to allow you to add all of the needed information into it
    for(int j = 0; j < var; j++){                                           //goes threw each line in the file
        for(int i = 0; i < 6; i++){                                         //goes through each item in the line 
            storage[j].push_back(readin.at(yeah));
            
            for ( int k = 0 ; k < readin.size() ; k++ ){
                if ( k == ' ' ){
                    k = '_' ;
                }
            }
            cout << readin.at( yeah ) ;
            yeah++;
        }
        
    }
    for(int i = 0; i < var; i++){                                           //was gonna search threw the artists at position 2 to see if they match
                                                                            //kinda lost on what to do with matching though
                                                                            //looking at this http://www.cplusplus.com/forum/general/45549/
                                                                            //for some inspiration on how to find the matching artists

    }
    return 0;
}

void Print(vector<vector<string>>){                                         //use a prinf function so that everything is organized well


/*Artist: # of songs, total time
    Album: # of songs, total time
        track: song time
        keep going with info till done*/
}