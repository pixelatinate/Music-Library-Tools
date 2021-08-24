//Author: Swasti Mishra and Katie Nuchols
//Date: August 24th, 2021
//Professor: Emrich

#include <iostream>

using namespace std;

int main(){
    //read in the file
    //run through and seperate data
    //while(cin)
    //store into 2d array going by lines
    //find matching information 
    //order matching information
    //print to user
    string storage[50][6];
    string temp;
    while(cin >> temp){
        for(int i = 0; i <= 5; i++){
            storage[i][i] = temp;
        }
    }
    for(int j = 0; j <= 5; j++){
        for(int i = 0; i <= 5; i++){
        cout << storage[j][i];
        }
    }
    return 0;
}