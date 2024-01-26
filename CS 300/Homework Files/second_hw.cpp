#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Apartment
{
    Apartment(int x_left, int x_right, int y_value, int active)
    {
        this->x_left = x_left;
        this->x_right = x_right;
        this->y_value = y_value;
        this->active = active;
    }
    int x_left, x_right, y_value, active;
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

bool checkOnlyLabel(vector<vector<int>> input, int val)
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
        vector<int> inner_vec;
        inner_vec.push_back(x.x_left);
        inner_vec.push_back(x.y_value);
        inner_vec.push_back(label);
        array.push_back(inner_vec);
        inner_vec.clear();
        inner_vec.push_back(x.x_right);
        inner_vec.push_back(x.y_value);
        inner_vec.push_back(label);
        array.push_back(inner_vec);
    }

    void setOrigin()
    {
        vector<int> inner_vec;
        inner_vec.push_back(0);
        inner_vec.push_back(0);
        inner_vec.push_back(0); // Output tuhaf olursa bak
        array.push_back(inner_vec);
    }

    void printArray()
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = 0; j < array[i].size(); j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
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
        for (int a = 0; a < array.size(); a++)
        {
            cout << array[a][0] << " ";
        }
        cout << endl;
    }

    void removeElement(int hole)
    {
        array[hole][0] = -1;
        array[hole][1] = -1;
        array[hole][2] = -1;
        // array.erase(array.begin() + hole);
    }

    int setSkyline(int a, int b)
    {
        if (a >= b)
        {
            return a;
        }
        return b;
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

    int findLabelinArray(int value) // Finds a value in array and returns its index in array
    {
        for (int j = 0; j < currentSize; j++)
        {
            if (array[j][2] == value)
            {
                return j;
            }
        }
    }

    int findMaxInOnlyLabels(vector<vector<int>> onlyLabels)
    {
        int max = -1;
        for (int i = 0; i < onlyLabels.size(); i++)
        {
            if (onlyLabels[i][1] > max)
            {
                max = onlyLabels[i][1];
            }
        }
        return max;
    }

    int getMax(int a, int b)
    {
        if (a >= b)
        {
            return a;
        }
        return b;
    }

    int findHeight(vector<vector<int>> input, int value)
    {
        for (int g = 0; g < input.size(); g++)
        {
            if (input[g][2] == value)
            {
                return g;
            }
        }
    }

    void printOutput(vector<vector<int>> &labels, vector<vector<int>> &skyline)
    {
        for (int i = 0; i < currentSize; i++)
        {
            labels.push_back(array[i]);
        }
        if (labels[0][0] > 0)
        {
            cout << 0 << " " << 0 << endl;
            skyline.push_back({0, 0});
        }

        vector<vector<int>> onlyLabels;
        for (int k = 0; k < currentSize; k++)
        {
            bool exists = checkOnlyLabel(onlyLabels, labels[k][2]);
            if (!exists)
            {
                labels[k][3] = 1;
                onlyLabels.push_back(labels[k]);
                // cout << "Building " << labels[k][2] << " begins " << endl;
                if (onlyLabels.size() > 1) // Basini vermeme conditionu
                {
                    for (int a = 0; a < onlyLabels.size(); a++)
                    {
                        int indexInOnlyLabels = findHeight(labels, onlyLabels[a][2]);
                        if (labels[indexInOnlyLabels][1] < labels[k][1])
                        {
                            int check = k;
                            int maxValue = labels[k][1];
                            while (labels[check][0] == labels[check - 1][0])
                            {
                                maxValue = getMax(labels[check][1], labels[check - 1][1]);
                                check++;
                            }
                            if (labels[k][0] == labels[k - 1][0])
                            {
                                // int yMax = getMax(labels[k][1], labels[k - 1][1]);
                                labels[k][1] = maxValue;
                                cout << labels[k][0] << " " << labels[k][1] << " " << labels[k][3] << " " << labels[k][2] << " 215 " << maxValue << endl;
                                // cout << labels[k][0] << " " << maxValue << " " << labels[k][3] << " " << labels[k][2] << " 235 " << endl;
                                skyline.push_back(labels[k]);
                            }
                            else
                            {
                                cout << labels[k][0] << " " << labels[k][1] << " " << labels[k][3] << " " << labels[k][2] << " 241 " << maxValue << endl;
                                skyline.push_back(labels[k]);
                            }
                            break;
                        }
                    }
                }
                else
                {
                    cout << labels[k][0] << " " << labels[k][1] << " " << labels[k][3] << " " << labels[k][2] << " 222 " << endl;
                    skyline.push_back(labels[k]);
                }
            }
            else
            {
                int deleteLabelIndex;

                int deletedX, deletedY;

                for (int s = 0; s < onlyLabels.size(); s++)
                {
                    if (onlyLabels[s][2] == labels[k][2])
                    {
                        deleteLabelIndex = s;
                    }
                }
                deletedX = labels[k][0];
                deletedY = labels[k][1];
                // cout << "Building " << labels[k][2] << " ends " << endl;
                labels[k][3] = 0;
                onlyLabels.erase(onlyLabels.begin() + deleteLabelIndex);
                if (onlyLabels.size() == 0)
                {
                    cout << labels[k][0] << " " << 0 << " " << labels[k][3] << " " << labels[k][2] << " 245 " << endl;
                    skyline.push_back({labels[k][0], 0, labels[k][2]});
                }
                else
                {
                    int maxHeight;
                    for (int b = 0; b < onlyLabels.size(); b++)
                    {
                        int indexinLabel = findHeight(labels, onlyLabels[b][2]);

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
                        cout << labels[k][0] << " " << maxHeight << " 253 " << labels[k][3] << endl
                             << endl;
                        skyline.push_back(labels[k]);
                    }
                    else
                    {
                        if (labels[k][0] == deletedX)
                        {
                            int yMax = 0;
                            int dominantX;
                            if (onlyLabels.size() != 0)
                            {
                                for (int x = 0; x < onlyLabels.size(); x++)
                                {
                                    int search = findLabelinArray(onlyLabels[x][2]);
                                    if (array[search][1] >= yMax)
                                    {
                                        yMax = array[search][1];
                                        dominantX = array[search][0];
                                        // cout << "Dominant x: " << dominantX << endl;
                                    }
                                }
                                if (yMax < labels[k][1])
                                {
                                    cout << labels[k][0] << " " << yMax << " " << labels[k][3] << " " << labels[k][2] << " 287 " << onlyLabels.size() << endl;
                                    skyline.push_back(labels[k]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void sortLabelsInArray()
    {

    }

    
private:
    int currentSize;           // Number of elements in heap
    vector<vector<int>> array; // The heap array

    bool isEmpty()
    {
        return (array.size() == 0);
    }
};

void printSkyline(const vector<vector<int>> input)
{
    for (int i = 1; i < input.size(); i++)
    {
        cout << input[i][0] << " " << input[i][1] << " " << input[i][2] << endl;
    }
}

int main()
{
    ifstream apartmentsFile;
    string apartmentsText = "input4.txt";

    int apartmentQuantity = 0, x_left, x_right, y_value, identifier = 0, arraySize;
    string line;
    vector<int> apartmentVector;
    vector<vector<int>> labels, skyline;
    // vector<vector<int>> yVector;
    // nestToY.push_back(0);
    // nestToY.push_back(0);

    apartmentsFile.open(apartmentsText);
    getline(apartmentsFile, line);
    apartmentQuantity = stoi(line);
    // cout << "Apartment quantity: " << apartmentQuantity << endl;
    arraySize = apartmentQuantity * 2;
    singleHeap<int> array(arraySize);

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

        Apartment a = Apartment(x_left, x_right, y_value, 1);
        array.insert(a, identifier - 1);
        // nestToY.push_back(identifier - 1);
        identifier -= 1;
        // yVector.push_back(nestToY);
        // yVector.push_back(nestToY);
        // nestToY.clear();
        // cout << "x_left is: " << x_left << " x_right is: " << x_right << " y_value is: " << y_value << endl;
    }

    // array.printArray();

    array.buildHeap();

    // array.printFirstIndex();

    array.printArray();
    cout << "----------------- " << endl;
    array.printOutput(labels, skyline);
    cout << "----------------- " << endl;
    printSkyline(skyline);

    // cout << "Labels are: ";
    // for (int s = 0; s < labels.size(); s++)
    // {
    //     cout << labels[s][2] << " ";
    // }

    return 0;
}