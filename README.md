# Dijkstra

## Overview
This program is an implementation of Dijkstra's "shortest path" algorithm.

It calculates which series of roads should be taken to travel the shortest path between two locations.

## Details
The user will specify a source file of
roads and what locations they connect, and request
the shortest path between two locations which the
program calculates using a Graph and Dijkstra's 
algorithm. The program also outputs some useful
information about the distance, time, and road path.

There is an example default file named "lab04.txt" which contains roads and locations for some cities in Oregon.

### Input
The program prompts for filename of the source file, if the
user inputs 'd' then a default file will be used (lab04.txt).
Then the user is prompted for the name of a start location
and then an end location. After outputing results, the user
is prompted if they would like to continue. If 'y' is input,
then the program will start over from asking the start and 
end locations.

### Output
The program will prompt the user for filename, then start
location, then end location. After calculating, the program
outputs the shortest distance between the locations, the
time it will take in hours and then in minutes, and also
the route one should take for this shortest path. The user
is then prompted to continue and starts over from the 
start location prompt.

## Installation
Open and run with Visual Studio 2022 (or your IDE of choice)

You may also create a custom file of locations, roads, and distances in the following format (see "lab04.txt" for example):

Location 1,Location 2,Road name,[# indicating distance]

## Status
This project is finished.

## Screenshots
![Dijkstra](https://user-images.githubusercontent.com/49173127/166086947-2304cd4e-15bc-4434-9d0e-97141da81ce1.png)

![image](https://user-images.githubusercontent.com/49173127/166086938-cdd069e4-7098-4e59-a7d9-ab4b1f4bdd60.png)
