// Project 01: Music Library Tool
// The goal of this project is to reorganize a music discography file 
//      into something that's easier to understand. 
// COSC 302
// Swasti Mishra and Katie Nuchols
// Date: August 24th, 2021
// Professor Emrich

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int strtoint(string number);
void Print(vector<vector<string>> album, vector<int> sets, vector<int> albumx);
//string TotalTime(vector<vector<string>> album, vector<int> sets);
// Functions


struct Album {
    map <int, Song* > songs;
    string name;
    int time;
    int nsongs;

    Album( string name ){
        this->name = name ;
        this->time = 0 ;
        this->nsongs = 0 ;
    } ;
};

struct Artist {
    map <string, Album* > albums;
    string name;
    int time;
    int nsongs;
    
    Artist( string name ){
        this->name = name ;
        this->time = 0 ;
        this->nsongs = 0 ;
    } ;
};

struct Song { 
    struct Artist *artist ;
    string title;
    int time;  // could also be a string
    int track;

    Song( string title , int time , int track){
        this->artist = nullptr ;
        this->title = title ;
        this->time = time ;
        this->track = track ;
    } ;
};

int main(){
//    Countdown 2:25 Coltrane,_John Giant_Steps Jazz 3

    string songTitle ;
    string songTime ;
    string artistName ;
    string albumName ;
    string songGenre ;
    int songTrack ;

    map <string, Artist * > NameArtist ;
    NameArtist::iterator it ;
    
    map <int, Song * > NameAlbum ;
    NameAlbum::iterator itna ;
    
    Artist *artist ;
    Song *song ;
    Album *album ;

    int minutes, seconds ;

    // Variables 
    
    while( cin >> songTitle >> songTime >> artistName >> albumName >> songGenre >> songTrack ){
    
        // reads in title and replaces underscores with space
        songTitle = replace( songTitle.begin(), songTitle.end(), '_', ' ');
        // reads in time data
        scanf("%i:%i", songTime, minutes, seconds);
        song = new Song( songTitle, ( minutes * 60 + seconds ), songTrack ) ;
 
        // reads in the Artist name replaces underscores with spaces
        artistName = replace( artistName.begin(), artistName.end(), '_', ' ');
        it = NameArtist.find(artistName);
        
        // Creates a new artist if the artist name doesn't already exist 
        if ( it == NameArtist.end()){
            artist = new Artist(artistName) ;
            NameArtist[artistName] = artist ;
        }
        else{ 
            artist = it->second ;
        }
        artist->time += song->time ;
        song->artist = artist ;
        artist->nsongs++ ;

        albumName = replace( albumName.begin(), albumName.end(), '_', ' ');
        itna = NameAlbum.find(albumName) ;

        if ( itna == NameAlbum.end()){
            album = new Album(albumName) ; 
        }
        else{
            album = itna->second ;
        }
        artist->albums[albumName] = album ;
        album->nsongs++ ;
        album->time += minuts*60+seconds ;
        album->album[songTrack] = song ;
    }
    

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

    vector<int> usedlisting;
    vector<int> matchingset;
    vector<int> matchsetartist ;
    vector<int> matchsetalbum ;                                                //throw set of matching into it and then print out
    vector<vector<string>> Albumlisting(readin.size());
    vector<string> temporary ;
    

    int used = 0;
    for(int i = 0; i < var-1; i++){                                         //was gonna search through the artists at position 2 to see if they match
        used = 0;     
        matchingset.erase(matchingset.begin(), matchingset.end()); 
        matchsetalbum.erase(matchsetalbum.begin(), matchsetalbum.end());
                             
                                                                            //kinda lost on what to do with matching though
                                                                            //looking at this http://www.cplusplus.com/forum/general/45549/
                                                                            //for some inspiration on how to find the matching artists
        for(int j = 0; j < var; j++){
            if(storage[j].at(2) == storage[i].at(2)){
                matchingset.push_back(j);
                usedlisting.push_back(j);
            }
            if(storage[j].at(3) == storage[i].at(3)){
                matchsetalbum.push_back(j);

            }                                                               //finds all of the matching ones in the set
        }
        for(int k = 0; k < (usedlisting.size()-matchingset.size()); k++){
            for(int m = 0; m < matchingset.size(); m++){
                if(matchingset.at(m) == usedlisting.at(k)){
                    used = 1;
                }                                   
            }
        }
        
        if(used==1){
            continue;
        }
        
        else{
            Print(storage, matchingset, matchsetalbum);
        }
        //TotalTime(storage, matchingset);
        //Print(storage, matchingset);

    //this will be so that there is no overlapping files printed more than once or we can just implement a count that might work better but this has errors right now
        /*for(int m = 0; m < matchingset.size(); m++){
            storage[matchingset.at(m)].erase(storage.begin(), storage.end());
        }*/
        //used =+ matchingset.size();
        //cout << used;
        //storage.shrink_to_fit();
        
        matchingset.erase(matchingset.begin(), matchingset.end());
        matchsetalbum.erase(matchsetalbum.begin(), matchsetalbum.end());
        
    }
    return 0;
}

// End of section I haven't cleaned up yet, the print below is clean


void Print(vector<vector<string>> album, vector<int> sets, vector<int> albumx){
    char space = ' ' ;
    printf("%s: %d, total time\n",
    album[sets.at(0)].at(2).c_str(), sets.size()) ;
    
    for ( int j = 0 ; j < albumx.size()-1 ; j++){
        if ( album[sets.at(j)].at(3) == album[sets.at(j+1) ].at(3) ){
            continue ;
        }
        else{
            printf("%8c%s: %d, total time\n" , space, album[sets.at(j+1)].at(3).c_str(), sets.size());  
            printf("%16c%s. %s: %s\n", space, album[sets.at(j+1)].at(5).c_str(),
                    album[sets.at(j+1)].at(0).c_str(), album[sets.at(j+1)].at(1).c_str());  
        }

    }
    printf("%8c%s: %d, total time\n" , space, album[sets.at(0)].at(3).c_str(), sets.size());

    // * we need to make a function that finds the total amount of time in the file so that can be impemented into the code
    
    for(int i = 0; i < sets.size(); i++){
        printf("%16c%s. %s: %s\n", space, album[sets.at(i)].at(5).c_str(),
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

/*string TotalTime(vector<vector<string>> album, vector<int> sets){

}*/