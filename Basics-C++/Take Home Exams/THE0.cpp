#include <iostream>
#include <string>

using namespace std;

/* 
    Calculates Sabaci CS201 Grade
*/

string name;
float midterm, final, the1, the2, the3, the4, the5, 
q1, q2 ,q3, q4, counter_q, counter_t, 
weighted_average, numeric_grade, the_average, quiz, the_ratio, take_home_grade,
quiz_grade, quiz_avr, quiz_ratio;


int main(){
    cout << "The purpose of this program is to calculate your CS201 grade." << endl;
    cout << "What is your name? ";
    cin >> name;
    cout << "Hello " << name << " what are your midterm and final exam grades? ";
    cin >> midterm >> final;
    
    if (midterm == -100 || final == -100)
    {
    cout << midterm << final << name << " one of your midterm or final exam grade is -100, you will fail the course!" << endl;    
    }
    
    else if (midterm == -1)
    {
    cout << name << " you did not enter the midterm exam, you will fail the course!" << endl;
    }

    else if (final == -1)
    {
    cout << name << " you did not enter the final exam, you will fail the course!" << endl;
    }
    
    else 
    { 
        weighted_average = (.3 * midterm + final * .3) / .6;
        if (weighted_average >= 30)
        {
            cout << "What are the grades of your 5 take-home exams? ";
            cin >> the1 >> the2 >> the3 >> the4 >> the5;
            if (the1 == -100)
            {
                counter_t++;
            }
            if (the2 == -100)
            {
                counter_t++;
            }
            if (the3 == -100)
            {
                counter_t++;
            }
            if (the4 == -100)
            {
                counter_t++;
            }
            if (the5 == -100)
            {
                counter_t++;
            }
            if (counter_t >= 2)
            {
                cout << name << " at least two of your THE grades are -100, you will fail the course!" << endl;
            }
            else if (counter_t < 2)
            {
                the_average = (the1 + the2 + the3 + the4 + the5) / 5;
                the_ratio = the_average / weighted_average;
                if (the_ratio <= 2)
                {
                    take_home_grade = the_average;
                }
                else if (2 < the_ratio && the_ratio < 3)
                {
                    take_home_grade = the_average * (3 - the_ratio);
                }
                else if (the_ratio > 3)
                {
                    take_home_grade = 0;
                }
                cout << "What are the grades of your 4 quizzes? ";
                cin >> q1 >> q2 >> q3 >> q4;
                counter_q = 0;
                if (q1 == -100)
                {
                    counter_q++;
                }
                if (q2 == -100)
                {
                    counter_q++;
                }
                if (q3 == -100)
                {
                    counter_q++;
                }
                if (q4 == -100)
                {
                    counter_q++;
                }
                if (counter_q >= 2)
                {
                    cout << name << " at least two of your quiz grades are -100, you will fail the course!" << endl;
                }
                if (counter_q + counter_t >= 2)
                {
                    cout << name << " one of your THE and one of your quiz grades is -100, you will fail the course!" << endl;
                }
                else if (counter_q < 2)
                {
                    quiz_avr = (q1+q2+q3+q4) / 4;
                    quiz_ratio = quiz_avr / weighted_average;
                    cout << quiz_ratio << endl;
                    if (quiz_ratio <= 2)
                    {
                        quiz_grade = quiz_avr;
                    }
                    else if (2 < quiz_ratio && quiz_ratio < 3)
                    {  
                        quiz_grade = quiz_avr * (3-quiz_ratio);
                    }
                    else if (quiz_ratio >= 3)
                    {
                        quiz_grade = 0;
                    }
                    numeric_grade = quiz_grade * .2 + take_home_grade * .2 + midterm * .3 + final * .3;
                    cout << name << " your  weighted exam average is: " << weighted_average << endl;
                    cout << name <<", your THE average is: " << the_average << " and you will get " << take_home_grade << " of it." << endl;
                    cout << name << ", your quiz average is: " << quiz_avr << " and you will get " << quiz_grade << " out of it." << endl;
                    cout << name << ", your grade for CS201 is: " << numeric_grade << endl;
                }
            }

        } else {
            cout << name << " your weighted exam average is less than 30, you will fail the course!" << endl;
        }
    } 
    return 0;
}