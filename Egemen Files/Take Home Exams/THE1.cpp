#include <iostream>

using namespace std;

/*
    - Calculates the burnt calorie depending on reps of specific exercises. 
*/

void getInput(int &minLunge, int &minPullUp,int &minPushUp,int &repsLunge,
int &repsPushUp ,int &repsPullUp, string &name, int &minWeightLift, int &repWeight, int &liftedWeight)
{
    cout << "Lunges: "; cin >> minLunge >> repsLunge;
    cout << "Push Ups: "; cin >> minPushUp >> repsPushUp;
    cout << "Pull Ups: "; cin >> minPullUp >> repsPullUp;
    cout << name << ", please enter minutes, repetitions and lifted weight in a week for the activities below." << endl;
    cout << "Weight Lifting: ";
    cin >> minWeightLift >> repWeight >> liftedWeight;
}

bool inputCheck(int &minLunge, int &minPullUp,int &minPushUp, int &minWeightLift, 
int &repsLunge, int &repsPushUp ,int &repsPullUp, int &repsWeight, int &liftedWeight, int weight)
{
    if (weight < 30)
    {
        cout << "Weight out of range!" << endl;
        return false;
    } 
    else if (liftedWeight <= 0 || liftedWeight > 35)
    {
        cout << "Lifted weight out of range!" << endl;
        return false;
    }
    else if (repsLunge < 0 || repsPullUp < 0 || repsPushUp < 0 || repsWeight < 0 ||
    repsLunge > 50 || repsPullUp > 50 || repsPushUp > 50 || repsWeight > 50)
    {
        cout << "Reps out of range!" << endl;
        return false;
    } 
    else if (minLunge < 0 || minPullUp < 0 || minPushUp < 0 || minWeightLift < 0 ||
    minLunge > 2000 || minPullUp > 2000 || minPushUp > 2000 || minWeightLift > 2000)
    {
        cout << "Minute out of range!" << endl;
        return false;
    }
    else
    {
    return true;
    }
    return true;
}

void calculateMET(int repsLunge, int repsPushUp,int repsPullUp ,double &METLunge, double &METPullUp, double &METPushUp)
{
    if (repsLunge < 15)
    {
        METLunge = 3;
    }
    if (repsLunge >= 15 && repsLunge < 30)
    {
        METLunge = 6.5;  
    }
    if (repsLunge >= 30)
    {
        METLunge = 10.5;
    }
    if (repsPushUp < 15)
    {
        METPushUp = 4;   
    }
    if (repsPushUp >= 15)
    {
        METPushUp = 7.5;
    }
    if (repsLunge >= 15 && repsLunge < 30)
    {
        METLunge = 6.5; 
    }
    if (repsLunge >= 30)
    {
        METLunge = 10.5;
    }
    if (repsLunge >= 15 && repsLunge < 30)
    {
        METLunge = 6.5;
    }   
    if (repsPullUp < 25)
    {
        METPullUp = 5;
    }  
    if (repsPullUp >= 25)
    {
        METPullUp = 9;
    } 
}

void calculateWeightLiftMET(double &METLifted, int liftedWeight, int repsWeight){
    if (liftedWeight < 5)
    {
        if (repsWeight < 20)
        {
            METLifted = 3;
        }
        else if (repsWeight >= 20 && repsWeight < 40)
        {
            METLifted = 5.5;
        }
        else if (repsWeight >= 40)
        {
            METLifted =  10;
        }
    }
    else if (liftedWeight >= 5 && liftedWeight < 15)
    {
        if (repsWeight < 20)
        {
            METLifted = 4;
        }
        else if (repsWeight >= 20 && repsWeight < 40)
        {
            METLifted = 7.5;
        }
        else if (repsWeight >= 40)
        {
            METLifted =  12;
        }
    }
    else if (liftedWeight >= 15)
    {
        if (repsWeight < 20)
        {
            METLifted = 5;
        }
        else if (repsWeight >= 20 && repsWeight < 40)
        {
            METLifted = 9;
        }
        else if (repsWeight >= 40)
        {
            METLifted =  13.5;
        }
    }
}
void displayResults(double &difference, double &total, double weight, double goal, double METLunge, double METPushUp, 
double METPullUp, double METLifted, double calorieLunge, double caloriePushUp,double caloriePullUp,double calorieWeight,
int minLunge, int minPushUp, int minPullUp, int minWeightLift){

    double toLunge, toPushUp, toPullUp, toLift;

    total = calorieWeight + calorieLunge + caloriePullUp + caloriePushUp; 
    difference = goal - total;

    toLunge = (difference*200) / (METLunge * 3.5 * weight);
    toPushUp = (difference*200) / (METPushUp * 3.5 * weight);
    toPullUp = (difference*200) / (METPullUp * 3.5 * weight);
    toLift = (difference*200) / (METLifted * 3.5 * weight);


    if (goal > total)
    {  
        cout << "You did not reach your goal by " << difference << " calories." << endl;
        cout << "You need to do lunges " << toLunge << " more minutes or, " << endl; 
        cout << "You need to do push ups " << toPushUp << " more minutes or, " << endl; 
        cout << "You need to do pull ups " << toPullUp << " more minutes or, " << endl; 
        cout << "You need to do weight lifting " << toLift << " to reach your goal." << endl; 
    }

    else if (total > goal)
    {
        cout << "You have surpassed your goal! You can eat something worth " << difference*-1 << " calories :)" << endl;
    }

    else if (total == goal)
    {
        cout << "Congratulations! You have reached your goal!" << endl;
    }
}
void computeResults(int weight, int goal, int repsLunge, int repsPushUp,int repsPullUp, 
int repsWeight, int minLunge, int minPushUp, int minPullUp, int minWeightLift, int liftedWeight)
{
    double METLunge, METPullUp, METPushUp, METLifted, calorieLunge, 
    caloriePullUp, caloriePushUp, calorieWeight, difference, total;

    calculateMET(repsLunge, repsPushUp, repsPullUp, METLunge, METPullUp, METPushUp);
    calculateWeightLiftMET(METLifted, liftedWeight, repsWeight);

    calorieLunge = (minLunge) * (METLunge*3.5*weight)/200;
    caloriePullUp = (minPullUp) * (METPullUp*3.5*weight)/200;
    caloriePushUp = (minPushUp) * (METPushUp*3.5*weight)/200;
    calorieWeight = (minWeightLift) * (METLifted*3.5*weight)/200;
    
    cout << "From Lunges, you burned " << calorieLunge << " calories."<< endl;
    cout << "From Push Ups, you burned " << caloriePushUp << " calories." << endl;
    cout << "From Pull Ups, you burned " << caloriePullUp << " calories." << endl;
    cout << "From weight lifting, you burned "<< calorieWeight << " calories." << endl;
    cout << "You burned " << (calorieLunge + caloriePushUp + caloriePullUp + calorieWeight) << " calories. \n" << endl;

    displayResults(difference, total,  weight, goal, METLunge, METPushUp, 
 METPullUp,  METLifted,  calorieLunge, caloriePushUp, caloriePullUp, calorieWeight, minLunge, minPushUp,  minPullUp, minWeightLift);
}


int main()
{
    int weight, goal, minLunge, minPullUp, minPushUp, repsLunge, repsPushUp , repsPullUp, minWeightLift, liftedWeight, repsWeight;
    double difference, total;
    string name;
    
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Welcome " << name << ", please enter your weight(kg): "; cin >> weight;
    cout << name << ", please enter minutes and repetitions in a week for the activities below." << endl;
    getInput(minLunge, minPullUp, minPushUp, repsLunge, repsPushUp , repsPullUp, name, minWeightLift, repsWeight, liftedWeight);
    cout << name << ", please enter your weekly calorie burn goal: "; cin >> goal;

    if (inputCheck(minLunge, minPullUp, minPushUp, minWeightLift, 
    repsLunge, repsPushUp ,repsPullUp, repsWeight, liftedWeight, weight) == true)
    {
        computeResults(weight, goal, repsLunge, repsPushUp, repsPullUp, 
 repsWeight,  minLunge,  minPushUp,  minPullUp,  minWeightLift,  liftedWeight);
        return true;
    }
    return 0;
}