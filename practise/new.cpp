#include <iostream> 
#include <map>
using namespace std;

map<char,int> findShortestFrom(char){}

void dijkstra(map<char,map<char,int>> nodes){

    map<char,int> distance={{'A',INT16_MAX},{'B',INT16_MAX},{'C',INT16_MAX},{'D',INT16_MAX},{'E',INT16_MAX},{'F',INT16_MAX}};

    map<char,bool> visitedStatus={{'A',false},{'B',false},{'C',false},{'D',false},{'E',false},{'F',false}};

    map<char,int> ShortNext=findShortestFrom('A');

    while (ShortNext[0]!='N'){

        distance[ShortNext[0]]=ShortNext[1];
        visitedStatus[ShortNext[0]]=true;
        ShortNext=findShortestFrom(ShortNext[0]);
    }
}

int main()
{
        cout<<"name";
        map<char,map<char,int>> nodes={
            {'A',{{'B',3},{'D',2},{'E',5}}},
            {'B',{{'E',1},{'F',2}}},
            {'D',{{'E',3},{'A',2}}},
            {'E',{{'D',3},{'B',1},{'C',2}}},
            {'C',{{'E',2},{'F',5}}},
            {'F',{{'B',2},{'C',2}}}     
            };
            dijkstra(nodes);

        // map<char,int> nodes={{'A',3}};
}