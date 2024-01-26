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
        inner_vec.push_back(label);
        array.push_back(inner_vec);
        inner_vec.clear();
        inner_vec.push_back(x.x_right);
        inner_vec.push_back(label);
        array.push_back(inner_vec);
    }

   void printArray()
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = 0; j < array[i].size(); j++){
                cout << array[i][j] << " ";
            }
        }
    }
    const Comparable Remove(int label);
    Comparable GetMax();

private:
    int currentSize;   // Number of elements in heap
    vector<vector<int>> array; // The heap array

    void percolateDown(int hole)
    {
        int child;
        Comparable tmp = array[hole];
    };

    void buildHeap(Comparable *input)
    {
        array = input;
        currentSize = input.size();

        for (int i = currentSize / 2; i > 0; i--)
        {
            percolateDown(i);
        }
    }

    bool isEmpty()
    {
        return (array.size() == 0);
    }
};

int main()
{
    ifstream apartmentsFile;
    string apartmentsText = "input1.txt";

    int apartmentQuantity = 0, x_left, x_right, y_value, identifier = 0, arraySize;
    string line;
    vector<int> apartmentVector;

    apartmentsFile.open(apartmentsText);
    getline(apartmentsFile, line);
    apartmentQuantity = stoi(line);
    cout << "Apartment quantity: " << apartmentQuantity << endl;
    arraySize = apartmentQuantity * 4;
    singleHeap<int> array(arraySize);

    while (getline(apartmentsFile, line))
    {
        x_left = stoi(line.substr(0, line.find(' ')));
        apartmentVector.push_back(x_left);
        line = line.substr(line.find(' ') + 1);
        y_value = stoi(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
        x_right = stoi(line);
        apartmentVector.push_back(x_right);

        Apartment a = Apartment(x_left, x_right, y_value);
        array.insert(a, identifier - 1);
        identifier -= 1;

        cout << "x_left is: " << x_left << " x_right is: " << x_right << " y_value is: " << y_value << endl;
    }

    array.printArray();

    return 0;
}

