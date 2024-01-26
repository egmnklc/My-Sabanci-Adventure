#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Building
{
    int leftXpos;
    int yPos;
    int rightXpos;
    int idx;
};

struct BuildingOnX
{
    int id;
    bool isLeft;
    int xPos;
    int yValue;


BuildingOnX()
{
	isLeft = true;
}
};

struct MpqBuilding
{
    int id;
    int yPos;

    bool operator<(const MpqBuilding& rhs) const
    {
        return yPos > rhs.yPos;
    }
};

class MPQ
{
public:
    MPQ();
    ~MPQ();
    void Insert(int value, int label);
    int Remove(int label);
    int RemoveAt(int id);
    int GetMax();
    bool IsEmpty();
    void printAll();
    void shiftUp(int i);
    void shiftDown(int n);

private:
    int size;
    vector<MpqBuilding> bQueue;
};

MPQ::MPQ()
{
	size = -1;
}


MPQ::~MPQ()
{
}

void MPQ::shiftUp(int i)
{
    while (i > 0 && bQueue[(i-1) / 2].yPos < bQueue[i].yPos) {

        // Swap parent and current node
        MpqBuilding tmp = bQueue[(i - 1) / 2];
        bQueue[(i - 1) / 2] = bQueue[i];
        bQueue[i] = tmp;


        // Update i to parent of i
        i = (i - 1) / 2;
    }

}

void MPQ::shiftDown(int i)
{
    int maxIndex = i;

    // Left Child
    int l = ((2 * i) + 1);

    if (l <= size && bQueue[l].yPos > bQueue[maxIndex].yPos) {
        maxIndex = l;
    }

    // Right Child
    int r = ((2 * i) + 2);

    if (r <= size && bQueue[r].yPos > bQueue[maxIndex].yPos) {
        maxIndex = r;
    }

    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(bQueue[i], bQueue[maxIndex]);
        shiftDown(maxIndex);
    }
}

void MPQ::Insert(int value, int label)
{
    MpqBuilding newBuilding;
    newBuilding.yPos = value;
    newBuilding.id = label;


    size = size + 1;
    bQueue.push_back(newBuilding);

    // Shift Up to maintain heap property
    shiftUp(size);
}

int MPQ::RemoveAt(int id)
{
    bQueue[id].yPos = bQueue[id].yPos + 100;

    // Shift the node to the root
    // of the heap
    shiftUp(id);

    //-----------------------------------
    int result = bQueue[0].yPos;

    // Replace the value at the root
    // with the last leaf
    bQueue[0] = bQueue[size];
    size = size - 1;

    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
    bQueue.pop_back();
    return 0;
}

int MPQ::Remove(int label)
{
	for(int i = 0; i < bQueue.size() ; i++)
	{
		if (bQueue[i].id == label)
		{
			RemoveAt(i);
		}
	}
    return 0;
}

int  MPQ::GetMax()
{
	if(IsEmpty())
	{
		return 0;
	}
    return bQueue[0].yPos;
}

bool MPQ::IsEmpty()
{
    return bQueue.empty();
}

void MPQ::printAll()
{
    for (MpqBuilding b : bQueue)
    {
        cout << "ID: "<< b.id << " Y: " << b.yPos << endl;
    }
}



int ReadInput(vector<Building>& buildings)
{
    string name = "input.txt";
    string left, up, right;
    ifstream file(name);
    int buildingNo = 0;
    bool firstLine = true;
    int id = 100;
    if (file.is_open())
    {
        string line, word;
        while (getline(file, line))
        {
            istringstream stream(line);
            stream >> left >> up >> right;

            if (firstLine)
            {
                firstLine = false;
                buildingNo = stoi(left);
            }
            else
            {
                Building newBldng;
                newBldng.leftXpos = stoi(left);
                newBldng.yPos = stoi(up);
                newBldng.rightXpos = stoi(right);
                newBldng.idx = id;
                buildings.push_back(newBldng);
                id++;
            }
        }
    }
    return buildingNo;
}

void InsertionSort(vector<BuildingOnX>& arr)
{
    int i, j;
	BuildingOnX key;
    for (i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;

		while (j >= 0 && arr[j].xPos > key.xPos)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
		
    }
}

void SortByXValues(vector<Building>  buildings, vector<BuildingOnX> &sortedBuildings)
{
    for (Building b : buildings)
    {
        BuildingOnX leftTmp;
        leftTmp.id = b.idx;
        leftTmp.xPos = b.leftXpos;
        leftTmp.isLeft = true;
        leftTmp.yValue = b.yPos;

        BuildingOnX rightTmp;
        rightTmp.id = b.idx;
        rightTmp.xPos = b.rightXpos;
        rightTmp.isLeft = false;
        rightTmp.yValue = b.yPos;

        sortedBuildings.push_back(leftTmp);
        sortedBuildings.push_back(rightTmp);
    }
    InsertionSort(sortedBuildings);
}


int main()
{
    vector<Building> buildings;
    int buildingsNo = ReadInput(buildings);
    vector<BuildingOnX> sortedBuildings;

    MPQ prioQueue;

    SortByXValues(buildings, sortedBuildings);
	for (int i = 0; i < sortedBuildings.size()-1; i++)
	{
		if (sortedBuildings[i].xPos == sortedBuildings[i+1].xPos && sortedBuildings[i+1].isLeft)
		{
			swap(sortedBuildings[i], sortedBuildings[i+1]);
		}
	}

	for (BuildingOnX b:sortedBuildings)
	{
		cout << "ID: "<< b.id << " X: "<< b.xPos << " Y: "<< b.yValue  << " ON LEFT? " << b.isLeft << endl;
	}

	bool canPrint = true;
	bool originIsEmpty = true;
	int lastY = 0;
	int lastX = 0;

	for (int i = 0; i < sortedBuildings.size(); i++)
    {
		BuildingOnX b = sortedBuildings[i];
        int maxY = 0;

		if (b.xPos == 0)
		{
			originIsEmpty = false;
		}
		if (originIsEmpty)
		{
			cout << "0 0" << endl;
			originIsEmpty = false;
		}	
        
        if (b.isLeft)
        {
			if (sortedBuildings[i+1].xPos == b.xPos && sortedBuildings[i+1].isLeft)
			{
				canPrint = false;
			}
			else
			{
				canPrint = true;
			}

            prioQueue.Insert(b.yValue, b.id);
            maxY = prioQueue.GetMax();

			if (maxY != lastY)
			{
				
				if (canPrint)
				{
					lastY = maxY;
					cout << b.xPos << " " << lastY << endl;
				}
			}
        }
        else
        {
            prioQueue.Remove(b.id);
			maxY = prioQueue.GetMax();

			if (maxY != lastY)
			{
				lastY = maxY;
				cout << b.xPos << " " << lastY << endl;
				
			}
        }
    }

}