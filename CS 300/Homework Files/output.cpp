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

bool checkOnlyLabel(vector<int> input, int val)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == val)
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
        bool first = true;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[0][0] != 0 && array[0][1] != 0 && first)
            {
                cout << 0 << " " << 0 << endl;
                first = false;
            }
            cout << array[i][0] << " " << array[i][1] << endl;
        }
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

    // void buildHeap()
    // {
    //     vector<vector<int>> input = array;
    //     currentSize = input.size();

    //     input.insertionSort();
    // }

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

    void printOutput(vector<vector<int>> &labels)
    {
        for (int i = 0; i < currentSize; i++)
        {
            labels.push_back(array[i]);
        }

        vector<int> onlyLabels;
        for (int k = 0; k < currentSize; k++)
        {
            bool exists = checkOnlyLabel(onlyLabels, labels[k][2]);
            if (!exists)
            {
            }
            else
            {
                int deleteLabelIndex;

                int deletedX, deletedY;

                for (int s = 0; s < onlyLabels.size(); s++)
                {
                    if (onlyLabels[s] == labels[k][2])
                    {
                        deleteLabelIndex = s;
                    }
                }
                deletedX = labels[k][0];
                deletedY = labels[k][1];
                // cout << "Building " << labels[k][2] << " ends " << endl;
                onlyLabels.erase(onlyLabels.begin() + deleteLabelIndex);
            }
        }
    }

private:
    int currentSize;           // Number of elements in heap
    vector<vector<int>> array; // The heap array

    bool isEmpty()
    {
        return (array.size() == 0);
    }
};

int main()
{
    ifstream apartmentsFile;
    string apartmentsText = "input3.txt";

    int apartmentQuantity = 0, x_left, x_right, y_value, identifier = 0, arraySize;
    string line;
    vector<int> apartmentVector;
    vector<vector<int>> labels;
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
        Apartment a = Apartment(x_left, x_right, y_value);
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

    // array.printOutput(labels);

    // cout << "Labels are: ";

    return 0;
}