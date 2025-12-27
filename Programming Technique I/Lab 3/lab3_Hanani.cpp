#include <iostream>
#include <cstring>

using namespace std;

void dispStatus(int cases);
void getInput(int &totalCases,int &newCases,int &totalDeath,int &totalRecovered);
void dispOutput(int cases);
double calcAverage(int states,int total);

void dispStatus(int cases){
    if (cases == 0){
        cout << "Green zone" << endl;
    }
    else if (cases < 20){
        cout << "Yellow zone" << endl;
    }
    else if (cases < 40){
        cout << "Orange zone" << endl;
    }
    else{
        cout << "Red zone" << endl;
    }
}


void getInput(int &totalCases,int &newCases,int &totalDeath,int &totalRecovered){
    cout<<"Total cases    : ";
    cin>>totalCases;
    cout<<"New cases      : ";
    cin>>newCases;
    cout<<"Total death    :";
    cin>>totalDeath;
    cout<<"Total recovered: ";
    cin>>totalRecovered;
}

void dispOutput(int cases){
    cout<<"<<<<<<<<<<< SUMMARY >>>>>>>>>>>"<<endl;
    cout <<"Active cases   : "<<cases<<endl;
    cout <<"Status         : ";
    dispStatus(cases);
    cout<<endl;

}

double calcAverage(int states,int total){
    double avg;
    avg=total/states;
    return avg;
}

int main(){
    char state[50];
    int totalCases,newCases,totalDeath,totalRecovered,activeCases,totalActive=0;
    int highest=0,count=1;
    char highestState[50];
    char cont;
    do{
        cout<<"<<<<<<<<<<< DATA >>>>>>>>>>>"<<endl;
        cout<<"State name   :";
        cin.getline(state,50);

        getInput(totalCases,newCases,totalDeath,totalRecovered);
        cout<<endl;

        activeCases=totalCases+newCases-totalDeath-totalRecovered;


        dispOutput(activeCases);

        if(activeCases>highest) {
            highest=activeCases;
            strcpy(highestState, state);
        }
        totalActive+=activeCases;
        count=count+1;

        cout<<"Press <Enter> to continue...";
        cont = cin.get();
        cout<<endl;
    }while(cont=='\n');

    cout<<"<<<<<<<<< ACTIVE CASES >>>>>>>>>"<<endl;
    cout<<"Total     :"<<totalActive<<endl;
    cout<<"Highest   :"<<highest<<" ("<<highestState<<")"<<endl;
    cout<<"Average for "<<count<<" states: "<<calcAverage(count,totalActive)<<endl;

    return 0;
}