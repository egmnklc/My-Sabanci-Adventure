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

    void printArray()
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = 0; j < array[i].size(); j++)
            {
                cout << array[i][j] << " ";
            }
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

    void printOutput(vector<vector<int>> &labels, vector<vector<int>> &xstart, vector<vector<int>> &xend, vector<vector<int>> &skyline)
    {
        vector<vector<int>> onlyLabels;
        for (int i = 0; i < currentSize; i++)
        {
            bool exists = checkExists(onlyLabels, array[i][2]);
            if (!exists)
            {
                onlyLabels.push_back(array[i]);
                if (onlyLabels.size() > 1)
                {
                    // cout << "Building " << array[i][2] << " begins in " << onlyLabels[0][2] << endl;
                    if (array[i][1] > onlyLabels[0][1])
                    {
                        cout << array[i][0] << " " << array[i][1] << endl;
                        // << " 151 " << endl;
                        skyline.push_back(array[i]);
                    }
                }
                else if (onlyLabels.size() == 1)
                {
                    skyline.push_back(array[i]);
                    cout << array[i][0] << " " << array[i][1] << endl;
                    // << " 157 " << endl;
                }
                else
                {
                    cout << 165 << endl;
                }
                xstart.push_back(array[i]);
            }
            else
            {
                // cout << "Building " << array[i][2] << " ends " << endl;
                xend.push_back(array[i]);
                int onlyLabelsIndex = findArrayInLabel(onlyLabels, array[i][2]);
                int deletedX = array[i][0];
                int deletedY = array[i][1];
                int deletedLabel = array[i][2];
                onlyLabels.erase(onlyLabels.begin() + onlyLabelsIndex);
                if (onlyLabels.size() > 0)
                {
                    // cout << "Building " << array[i][2] << " ends in building " << onlyLabels[0][2]  << " deleted label: " << deletedLabel << endl;
                    if (onlyLabels[0][2] != deletedLabel && array[i][1] > onlyLabels[0][1])
                    {
                        cout << array[i][0] << " " << onlyLabels[0][1] << endl;
                        // << " 169 " << endl;
                        vector<int> zi;
                        zi.push_back(array[i][0]);
                        zi.push_back(onlyLabels[0][1]);
                        zi.push_back(onlyLabels[0][2]);
                        skyline.push_back(zi);
                    }
                    else
                    {
                        // cout << "Another building starts: " << endl;
                        // cout << 192 << endl;
                    }
                }
                else
                {
                    if (deletedLabel == array[i][2])
                    {
                        if (deletedY > array[i][1])
                        {
                            cout << array[i][0] << " " << array[i][1] << " 193 " << endl;
                            vector<int> pu = array[i];
                            pu[1] = 0;
                            skyline.push_back(pu);
                        }
                        else
                        {
                            cout << array[i][0] << " " << 0 << endl;
                            // << " 200 "
                            // << " Building ends here " << array[i][0] << " " << array[i][1] << " " << array[i][2] << "|" << array[i - 1][0] << " " << array[i - 1][0] << " " << array[i - 1][2] << endl; // Should be: building ends without any other building starts.
                            vector<int> ku = array[i];
                            ku[1] = 0;
                            skyline.push_back(ku);
                        }
                    }
                    else
                    {
                        cout << 208 << endl;
                    }
                }
            }
        }
    }

private:
    int currentSize;           // Number of elements in heap
    vector<vector<int>> array; // The heap array
};

int main()
{
    ifstream apartmentsFile;
    string apartmentsText = "input3.txt";

    int apartmentQuantity = 0, x_left, x_right, y_value, identifier = 0, arraySize;
    string line;
    vector<int> apartmentVector;
    vector<vector<int>> labels, xstart, xend, skyline;

    apartmentsFile.open(apartmentsText);
    getline(apartmentsFile, line);
    apartmentQuantity = stoi(line);
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
        identifier -= 1;
    }

    array.buildHeap();

    // array.printFirstIndex();

    array.printOutput(labels, xstart, xend, skyline);

    // cout << endl
    //      << "SKYLINES ARE" << endl;

    bool goin = true;

    int first = skyline[0][0];
    int height = skyline[0][1];

    int ctr = 0;

    // while (ctr != skyline.size() - 2)
    // {
    //     if (goin && first != 0 && height != 0)
    //     {
    //         cout << 0 << " " << 0 << endl;
    //         goin = false;
    //     }
    //     if (ctr == 0)
    //     {
    //         cout << skyline[ctr][0] << " " << skyline[ctr][1] << " " << skyline[ctr][2] << " 296 " << endl;
    //         ctr++;
    //     }
    //     else
    //     {

    //         int px = skyline[ctr][0];
    //         int py = skyline[ctr][1];
    //         int plabel = skyline[ctr][2];
    //         ctr++;
    //         // cout << px << " " << py << " " << plabel << " 286 p" << endl;
    //         int ax = skyline[ctr][0];
    //         int ay = skyline[ctr][1];
    //         int alabel = skyline[ctr][2];
    //         // cout << ax << " " << ay << " " << alabel << " 299 a" << endl;
    //         if (ax != px)
    //         {
    //             if (!(px == ax && (ay <= skyline[0][1] || py <= skyline[0][1]) && ay == skyline[0][1]))
    //             {
    //                 if (plabel != alabel && ay != 0)
    //                 {
    //                     if (py == 0)
    //                     {
    //                         cout << px << " " << py << " " << alabel << " 302 f" << endl;
    //                         cout << ax << " " << ay << " " << alabel << " 309 f" << endl;
    //                     }
    //                 }
    //                 else if (plabel == alabel && ay == 0)
    //                 {
    //                     cout << ax << " " << ay << " " << alabel << " 308 d" << endl;
    //                 }
    //                 else if (plabel != alabel && ay == py)
    //                 {
    //                     cout << ax << " " << ay << " " << alabel << " 308 d" << endl;
    //                 }
    //                 else if (px != ax && py == 0 && plabel != alabel)
    //                 {
    //                     cout << 3 << endl;
    //                 }
    //             }
    //             else
    //             {
    //                 // cout << 'g' << endl;
    //             }
    //         }
    //         else
    //         {
    //             cout << 329 << endl;
    //         }
    //     }
    // }
    // cout << skyline[ctr + 1][0] << " " << skyline[ctr + 1][1] << " " << skyline[ctr + 1][2] << " 300 " << endl;

    // cout << "-----------------" << endl;

    // int go = true;
    // for (int s = 0; s < skyline.size(); s++)
    // {
    //     if (go && first != 0 && height != 0)
    //     {
    //         cout << 0 << " " << 0 << endl;
    //         go = false;
    //     }
    //     cout << skyline[s][0] << " " << skyline[s][1] << " " << skyline[s][2] << endl;
    // }

    // array.printFirstIndex();
    // for (int k = 0; k < skyline.size(); k++)
    // {
    //     if (k == 0)
    //     {
    //         cout << skyline[k][0] << " " << skyline[k][1] << " " << skyline[k][2] << " 253" << endl;
    //     }
    //     else
    //     {
    //         if (skyline[k][0] != first)
    //         {
    //             if (skyline[k][1] > height || k == skyline.size() - 1)
    //             cout << skyline[k][0] << " " << skyline[k][1] << " " << skyline[k][2] << " 259 " << endl;
    //         }
    //     }
    // }

    cout << endl
         << "PROGRAM END";
    return 0;
}