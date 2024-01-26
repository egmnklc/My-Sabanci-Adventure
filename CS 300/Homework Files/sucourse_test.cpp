#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Apartment
{
    Apartment(signed int x_left, signed int x_right, signed int y_value, signed int active)
    {
        this->x_left = x_left;
        this->x_right = x_right;
        this->y_value = y_value;
        this->active = active;
    }
    signed int x_left, x_right, y_value, active;
};

bool checkExists(vector<vector<signed int>> input, signed int val)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (input[i][2] == val)
        {
            return true;
        }
    }
    return false;
}

bool checkOnlyLabel(vector<vector<signed int>> input, signed int val)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (input[i][2] == val)
        {
            return true;
        }
    }
    return false;
}

signed int getMax(signed int a, signed int b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

class singleHeap
{
public:
    singleHeap(signed int capacity) //* Constructor
    {
        this->currentSize = capacity;
    }
    // ~singleHeap()
    // {
    //     delete array;
    // }
    void insert(Apartment x, signed int label)
    {
        vector<signed int> inner_vec;
        inner_vec.push_back(x.x_left);
        inner_vec.push_back(x.y_value);
        inner_vec.push_back(label);
        inner_vec.push_back(x.active);
        array.push_back(inner_vec);
        inner_vec.clear();
        inner_vec.push_back(x.x_right);
        inner_vec.push_back(x.y_value);
        inner_vec.push_back(label);
        inner_vec.push_back(x.active);
        array.push_back(inner_vec);
    }

    void setOrigin()
    {
        vector<signed int> inner_vec;
        inner_vec.push_back(0);
        inner_vec.push_back(0);
        inner_vec.push_back(0); // Output tuhaf olursa bak
        array.push_back(inner_vec);
    }

    void printArray()
    {
        for (unsigned int i = 0; i < array.size(); i++)
        {
            for (unsigned int j = 0; j < array[i].size(); j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void buildHeap()
    {
        signed int j;
        // loop over the passes
        for (unsigned int p = 1; p < array.size(); p++)
        {
            signed int tmp = array[p][0];
            signed int tmp1 = array[p][1];
            signed int tmp2 = array[p][2];
            // loop over the elements
            for (j = p; j > 0 && tmp < array[j - 1][0]; j--)
            {
                array[j] = array[j - 1];
            }
            array[j][0] = tmp;
            array[j][1] = tmp1;
            array[j][2] = tmp2;
        }
    }

    void printFirstIndex()
    {
        for (unsigned int a = 0; a < array.size(); a++)
        {
            cout << array[a][0] << " ";
        }
        cout << endl;
    }

    signed int findLabelinArray(signed int value) // Finds a value in array and returns its index in array
    {
        signed int f;
        for (signed int j = 0; j < currentSize; j++)
        {
            if (array[j][2] == value)
            {
                f = j;
            }
        }
        return f;
    }

    signed int findMaxInOnlyLabels(vector<vector<signed int>> onlyLabels)
    {
        signed int max = -1;
        for (unsigned int i = 0; i < onlyLabels.size(); i++)
        {
            if (onlyLabels[i][1] > max)
            {
                max = onlyLabels[i][1];
            }
        }
        return max;
    }

    signed int findHeight(vector<vector<signed int>> input, signed int value)
    {
        signed int a;
        for (unsigned int g = 0; g < input.size(); g++)
        {
            if (input[g][2] == value)
            {
                a = g;
                break;
            }
        }

        return a;
    }

    void printOutput(vector<vector<signed int>> &labels, vector<vector<signed int>> &skyline)
    {
        for (signed int i = 0; i < currentSize; i++)
        {
            labels.push_back(array[i]);
        }
        if (labels[0][0] > 0)
        {
            vector<signed int> dum;
            dum.push_back(0);
            dum.push_back(0);
            dum.push_back(0);
            dum.push_back(0);
            skyline.push_back(dum);
        }

        vector<vector<signed int>> onlyLabels;
        for (signed int k = 0; k < currentSize; k++)
        {
            bool exists = checkOnlyLabel(onlyLabels, labels[k][2]);
            if (!exists)
            {
                labels[k][3] = 1;
                onlyLabels.push_back(labels[k]);
                // cout << "Building " << labels[k][2] << " begins " << endl;
                if (onlyLabels.size() > 1) // Basini vermeme conditionu
                {
                    for (unsigned int a = 0; a < onlyLabels.size(); a++)
                    {
                        signed int indexInOnlyLabels = findHeight(labels, onlyLabels[a][2]);
                        if (labels[indexInOnlyLabels][1] < labels[k][1])
                        {
                            signed int check = k;
                            signed int maxValue = labels[k][1];
                            while (labels[check][0] == labels[check - 1][0])
                            {
                                maxValue = getMax(labels[check][1], labels[check - 1][1]);
                                check++;
                            }
                            if (labels[k][0] == labels[k - 1][0])
                            {
                                // signed int yMax = getMax(labels[k][1], labels[k - 1][1]);
                                labels[k][1] = maxValue;
                                // cout << labels[k][0] << " " << labels[k][1] << " " << labels[k][3] << " " << labels[k][2] << " 215 " << maxValue << endl;
                                skyline.push_back(labels[k]);
                            }
                            else
                            {
                                for (int i = 0; i < onlyLabels.size(); i++)
                                {
                                    if (onlyLabels[i][1] > maxValue)
                                    {
                                        maxValue = onlyLabels[i][1];
                                    }
                                }
                                labels[k][1] = maxValue;
                                // cout << labels[k][0] << " " << labels[k][1] << " " << labels[k][3] << " " << labels[k][2] << " 241 " << maxValue << endl;
                                skyline.push_back(labels[k]);
                            }
                            break;
                        }
                    }
                }
                else
                {
                    // cout << labels[k][0] << " " << labels[k][1] << " " << labels[k][3] << " " << labels[k][2] << " 222 " << endl;
                    skyline.push_back(labels[k]);
                }
            }
            else
            {
                labels[k][3] = 0;
                signed int deleteLabelIndex;

                signed int deletedX, deletedY;

                for (unsigned int s = 0; s < onlyLabels.size(); s++)
                {
                    if (onlyLabels[s][2] == labels[k][2])
                    {
                        deleteLabelIndex = s;
                    }
                }
                deletedX = labels[k][0];
                deletedY = labels[k][1];
                // cout << "Building " << labels[k][2] << " ends " << endl;
                onlyLabels.erase(onlyLabels.begin() + deleteLabelIndex);
                if (onlyLabels.size() == 0)
                {
                    // cout << labels[k][0] << " " << 0 << " " << labels[k][3] << " " << labels[k][2] << " 245 " << endl;
                    vector<int> dum;
                    dum.push_back(labels[k][0]);
                    dum.push_back(0);
                    dum.push_back(labels[k][2]);
                    dum.push_back(labels[k][3]);
                    skyline.push_back(dum);
                }
                else
                {
                    signed int maxHeight;
                    for (unsigned int b = 0; b < onlyLabels.size(); b++)
                    {
                        signed int indexinLabel = findHeight(labels, onlyLabels[b][2]);

                        if (labels[indexinLabel][1] < labels[k][1])
                        {
                            maxHeight = labels[k][1];
                        }
                        else
                        {
                            maxHeight = labels[indexinLabel][1];
                        }
                    }
                    if (maxHeight < labels[k][1])
                    {
                        // cout << labels[k][0] << " " << maxHeight << " 253 " << labels[k][3] << endl;
                        //  << endl;
                        skyline.push_back(labels[k]);
                    }
                    else
                    {
                        if (labels[k][0] == deletedX)
                        {
                            signed int yMax = 0;
                            signed int dominantX;
                            if (onlyLabels.size() != 0)
                            {
                                for (unsigned int x = 0; x < onlyLabels.size(); x++)
                                {
                                    signed int search = findLabelinArray(onlyLabels[x][2]);
                                    if (array[search][1] >= yMax)
                                    {
                                        yMax = array[search][1];
                                        dominantX = array[search][0];
                                        // cout << "Dominant x: " << dominantX << endl;
                                    }
                                }
                                if (yMax < labels[k][1])
                                {
                                    // cout << labels[k][0] << " " << yMax << " " << labels[k][3] << " " << labels[k][2] << " 287 " << onlyLabels.size() << endl;
                                    vector<int> dum2;
                                    dum2.push_back(labels[k][0]);
                                    dum2.push_back(yMax);
                                    dum2.push_back(labels[k][2]);
                                    dum2.push_back(labels[k][3]);
                                    skyline.push_back(dum2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

private:
    signed int currentSize;           // Number of elements in heap
    vector<vector<signed int>> array; // The heap array

    bool isEmpty()
    {
        return (array.size() == 0);
    }
};

void printSkyline(const vector<vector<signed int>> input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        cout << input[i][0] << " " << input[i][1] << endl;
    }
}

vector<vector<signed int>> setMaxHeight(const vector<vector<signed int>> skyline)
{
    vector<vector<signed int>> uniqueX;
    uniqueX = skyline;
    signed int tail = 0;
    for (unsigned int head = 1; head < uniqueX.size(); head++)
    {
        if (uniqueX[tail][0] == uniqueX[head][0])
        {
            signed int yMax = getMax(uniqueX[tail][1], uniqueX[head][1]);
            if (uniqueX[tail][1] < uniqueX[head][1])
            {
                uniqueX[tail][1] = uniqueX[head][1];
            }
        }
        tail++;
    }
    return uniqueX;
}

vector<vector<signed int>> removeDuplicatesFromSkyline(const vector<vector<signed int>> skyline)
{
    vector<vector<signed int>> uniqueSkylines;

    signed int tail = 0;
    for (unsigned int head = 1; head < skyline.size(); head++)
    {
        if (skyline[tail][0] != skyline[head][0])
        {
            uniqueSkylines.push_back(skyline[tail]);
        }
        tail++;
    }

    if (skyline[tail][0] != skyline[tail - 1][0])
    {
        uniqueSkylines.push_back(skyline[tail]);
    }

    return uniqueSkylines;
}

vector<vector<signed int>> removeDuplicateY(const vector<vector<signed int>> skyline) // Working here
{
    vector<vector<signed int>> uniqueY;

    for (unsigned int i = 0; i < skyline.size(); i++)
    {
        if (i == 0)
        {
            uniqueY.push_back(skyline[i]);
        }
        else if (i == skyline.size() - 1)
        {
            uniqueY.push_back(skyline[i]);
        }
        else
        {
            if (skyline[i][0] != skyline[i - 1][0] && skyline[i][1] != skyline[i - 1][1])
            {
                uniqueY.push_back(skyline[i]);
            }
        }
    }

    return uniqueY;
}

int main()
{
    ifstream apartmentsFile;
    string apartmentsText = "input8.txt";

    signed int apartmentQuantity = 0, x_left, x_right, y_value, identifier = 0, arraySize;
    string line;
    vector<vector<signed int>> labels, skyline;

    apartmentsFile.open(apartmentsText);
    getline(apartmentsFile, line);
    apartmentQuantity = stoi(line);
    arraySize = apartmentQuantity * 2;
    singleHeap array(arraySize);

    while (getline(apartmentsFile, line))
    {
        x_left = stoi(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
        y_value = stoi(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
        x_right = stoi(line);
        Apartment a = Apartment(x_left, x_right, y_value, 1);
        array.insert(a, identifier - 1);
        identifier -= 1;
    }

    array.buildHeap();

    // array.printArray();
    // cout << " array.printOutput(labels, skyline) " << endl;
    array.printOutput(labels, skyline);
    // cout << " setMaxHeight(skyline) " << endl;
    skyline = setMaxHeight(skyline);
    // printSkyline(skyline);
    // cout << " removeDuplicatesFromSkyline(skyline) " << endl;
    skyline = removeDuplicatesFromSkyline(skyline);
    // printSkyline(skyline);
    // cout << " removeDuplicateY(skyline " << endl;
    skyline = removeDuplicateY(skyline);
    printSkyline(skyline);

    return 0;
}