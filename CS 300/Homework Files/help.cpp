#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Apartment
{
    Apartment(int x_left, int x_right, int y_value)
    {
        this->x_left = x_left;
        this->x_right = x_right;
        this->y_value = y_value;
    }
    int x_left, x_right, y_value;
};

bool checkExists(vector<vector<int>> input, int val)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i][2] == val)
        {
            return true;
        }
    }
    return false;
}

template <class Comparable>
class singleHeap
{
public:
    singleHeap(int capacity) //* Constructor
    {
        this->currentSize = capacity;
    }
    // ~singleHeap()
    // {
    //     delete array;
    // }
    void insert(Apartment x, int label)
    {
        array.push_back({x.x_left, x.y_value, label, 1});
        array.push_back({x.x_right, x.y_value, label, 0});
    }

    void printArray()
    {
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i][0] << " " << array[i][1] << " " << array[i][2] << " " << array[i][3] << endl;
        }
        cout << endl;
    }

    void printLabels()
    {
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i][2] << " ";
        }
        cout << endl;
    }

    void buildHeap()
    {
        int j;
        // loop over the passes
        for (int p = 1; p < array.size(); p++)
        {
            int tmp = array[p][0];
            int tmp1 = array[p][1];
            int tmp2 = array[p][2];
            int tmp3 = array[p][3];
            // loop over the elements
            for (j = p; j > 0 && tmp < array[j - 1][0]; j--)
            {
                array[j] = array[j - 1];
            }
            array[j][0] = tmp;
            array[j][1] = tmp1;
            array[j][2] = tmp2;
            array[j][3] = tmp3;
        }
    }

    void printFirstIndex()
    {
        for (int a = 0; a < array.size(); a++)
        {
            cout << array[a][0] << " ";
        }
        cout << endl;
    }

    int findArrayInLabel(vector<vector<int>> &labels, int value)
    {
        for (int k = 0; k < labels.size(); k++)
        {
            if (labels[k][2] == value)
            {
                return k;
            }
        }
    }

    int findLabelinArray(int value)
    {
        for (int j = 0; j < currentSize / 2; j++)
        {
            if (array[j][2] == value)
            {
                return j;
            }
        }
    }

    int getMax(int a, int b)
    {
        if (a >= b)
        {
            return a;
        }
        return b;
    }

    void setOrigin()
    {
        if (array[0][1] > 0 && array[0][0] != 0)
        {
            array.insert(array.begin(), {0, 0, 0});
        }
    }

    void checkDuplicate(vector<vector<int>> &input)
    {
        int max = 0;
        bool first = true;
        for (int i = 0; i < currentSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (input[j][0] == input[i][0] && input[j][1] >= input[i][1] && input[j][1] > max)
                {
                    if (!first)
                    {
                        // cout << "SOMETHING HERE 149" << endl;
                        first = false;
                    }
                    input[i][1] = input[j][1];
                    input[i][3] = input[j][3];
                }
                else if (input[j][0] == input[i][0] && input[j][1] <= input[i][1] && input[i][1] > max)
                {
                    if (!first)
                    {
                        // cout << "SOMETHING HERE 159" << endl;
                        first = false;
                    }
                    input[j][1] = input[i][1];
                    input[j][3] = input[i][3];
                }
                // else if (input[j][0] == input[i][0] && j == i - 1)
                // {
                //     cout << max << " for " << input[i][0] << endl;
                //     // input[i][1] = max;
                // }
            }
            first = false;
        }
    }

    void copyLabels(vector<vector<int>> &input)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (array[i][2] < 0)
            {
                input.push_back(array[i]);
                // cout << array[i][2] << " 244 " << endl;
            }
        }
    }

    void missingCheck(vector<vector<int>> & array , vector<vector<int>> & labels)
    {

    }

    vector<vector<int>> copy()
    {
        return array;
    }

private:
    int currentSize;           // Number of elements in heap
    vector<vector<int>> array; // The heap array
};

void printVector(vector<vector<int>> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (i == 0)
        {
            cout << input[i][0] << " " << input[i][1] << " " << input[i][2] << " " << input[i][3] << " qq " << endl;
        }
        else if (i == input.size() - 1)
        {
            cout << input[i][0] << " " << 0 << " " << input[i][2] << " " << input[i][3] << " w " << endl;
        }
        else
        {
            if (input[i][2] == input[i - 1][2])
            {
                cout << input[i][0] << " " << 0 << " " << input[i][2] << " " << input[i][3] << " sss " << endl;
            }
            else
            {
                // if (input[i + 1][3] == 1 && input[i][3] == 1) //input[i + 1][3] > input[i][3]
                if (input[i][1] != input[i + 1][1])
                {
                    cout << input[i][0] << " " << input[i][1] << " " << input[i][2] << " " << input[i][3] << " X " << endl;
                }
            }
        }
    }
}

vector<vector<int>> batuhan(vector<vector<int>> array)
{
    int j = 0;
    vector<vector<int>> Yvector;
    for (int i = 0; i < array.size(); i += j)
    {
        int Ymax = array[i][1];
        while (array[i][0] == array[j][0])
        {
            if (array[j][1] > Ymax)
            {
                Ymax = array[j][1];
            }
            j++;
        }
        Yvector.push_back({array[i][0], Ymax});
    }
    return Yvector;
}

vector<vector<int>> removeDuplicates(vector<vector<int>> input, vector<vector<int>> &toFill)
{
    int s = 0;
    while (s != input.size() - 1)
    {
        if (s > 0)
        {
            if (input[s - 1][0] != input[s][0])
            {
                if (input[s - 1][3] == 1 && input[s - 1][2] != input[s][2])
                {
                    input[s-1][3] = 1;
                }
                if (input[s][3] == 1 && input[s - 1][2] != input[s][2])
                {
                    input[s][3] = 1;
                }
                toFill.push_back(input[s]);
            }
        }
        else
        {
            toFill.push_back(input[s]);
        }
        s++;
    }
    toFill.push_back(input[s]);

    return toFill;
}

int returnIndex(vector<vector<int>> input, int search)
{
    for (int k = 0; k < input.size(); k++)
    {
        if (input[k][2] == search)
        {
            return k;
        }
    }
}

int main()
{
    ifstream apartmentsFile;
    string apartmentsText = "input1.txt";

    int apartmentQuantity = 0, x_left, x_right, y_value, identifier = 0, arraySize;
    string line;
    vector<int> apartmentVector;
    vector<vector<int>> xstart, xend, skyline, final, labels;

    apartmentsFile.open(apartmentsText);
    getline(apartmentsFile, line);
    apartmentQuantity = stoi(line);
    arraySize = apartmentQuantity * 2;
    singleHeap<int> array(arraySize);

    bool check = true;
    while (getline(apartmentsFile, line))
    {
        x_left = stoi(line.substr(0, line.find(' ')));
        apartmentVector.push_back(x_left);
        line = line.substr(line.find(' ') + 1);
        y_value = stoi(line.substr(0, line.find(' ')));
        // nestToY.push_back(y_value);
        line = line.substr(line.find(' ') + 1);
        x_right = stoi(line);
        apartmentVector.push_back(x_right);
        Apartment a = Apartment(x_left, x_right, y_value);
        array.insert(a, identifier - 1);
        identifier -= 1;
    }

    array.buildHeap();
    array.setOrigin();

    cout << "Array is: 347" << endl;
    array.printArray();
    array.printLabels();

    array.copyLabels(labels);

    for (int x = 0; x < labels.size(); x++)
    {
        cout << labels[x][2] << " ";
    }
    cout << endl;

    singleHeap<int> arrayCopy = array;

    vector<vector<int>> arrayCopyVector;
    arrayCopyVector = array.copy();

    // array.printOutput(labels, xstart, xend, skyline);

    cout << "-----------------" << endl;

    arrayCopy.checkDuplicate(arrayCopyVector);

    cout << " Arraycopy vector is: " << endl;
    printVector(arrayCopyVector);

    cout << endl
         << "PROGRAM END";
    return 0;
}