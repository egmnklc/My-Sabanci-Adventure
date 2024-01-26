#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    bool isRead = false;
    string cityName;
    int x, y;
    Node *ne, *nw, *sw, *se;

public:
    Node(string cityName_param = "", Node *ne_p = nullptr, Node *nw_p = nullptr, Node *sw_p = nullptr, Node *se_p = nullptr, int x = 0, int y = 0)
    {
        ne = ne_p;
        nw = nw_p;
        cityName = cityName_param;
        sw = sw_p;
        se = se_p;
    }
};

void createVectors(Node *rootNode, Node *otherNode, vector<Node *> &neVector, vector<Node *> &seVector, vector<Node *> &swVector, vector<Node *> &nwVector)
{
    if (otherNode->x < rootNode->x)
    {
        if (otherNode->y < rootNode->y)
        {
            // cout << "SW" << endl;
            swVector.push_back(otherNode);
        }

        else if (otherNode->y >= rootNode->y)
        {
            // cout << "NW" << endl;
            nwVector.push_back(otherNode);
        }
    }

    else if (otherNode->y < rootNode->y)
    {
        // cout << "SE" << endl;
        seVector.push_back(otherNode);
    }

    else if (otherNode->x == rootNode->x)
    {
        // cout << "SE" << endl;
        seVector.push_back(otherNode);
    }

    else
    {
        // cout << "NE" << endl;
        neVector.push_back(otherNode);
    }
}

void createCityNodes(string cityName, int xPoint, int yPoint, vector<Node *> &cityVector_p)
{
    Node *cityNode = new Node(cityName);
    cityNode->x = xPoint;
    cityNode->y = yPoint;
    cityVector_p.push_back(cityNode);
}

void inserter(Node *city, Node *root)
{
    if (root->x <= city->x && root->y > city->y)
    {
        if (root->se == NULL)
        {
            root->se = city;
        }
        else
        {
            root = root->se;
            inserter(city, root);
        }
    }

    else if (root->x > city->x && root->y > city->y)
    {
        if (root->sw == NULL)
        {
            root->sw = city;
        }
        else
        {
            root = root->sw;
            inserter(city, root);
        }
    }

    else if (root->x <= city->x && root->y <= city->y)
    {
        if (root->ne == NULL)
        {
            root->ne = city;
        }
        else
        {
            root = root->ne;
            inserter(city, root);
        }
    }

    else if (root->x > city->x && root->y <= city->y)
    {
        if (root->nw == NULL)
        {
            root->nw = city;
        }
        else
        {
            root = root->nw;
            inserter(city, root);
        }
    }
}

void pretty_print(Node *root)
{ // pretty print the quadtree rooted at root:
    if (root == NULL)
    {
        return;
    }
    if (root->isRead == false)
    {
        cout << root->cityName << endl;
        root->isRead = true;
    }                       
    // if the tree is not empty
    pretty_print(root->se); // recursively print the south east subtree
    pretty_print(root->sw); // recursively print the south west subtree
    pretty_print(root->ne); // recursively print the north east subtree
    pretty_print(root->nw); // recursively print the north west subtree
}

int main()
{
    ifstream citiesFile, queryFile;
    string citiesTxt = "cities.txt", queriesTxt = "queries.txt", boardSize, line, s;
    bool error_found = false, error_closing = false;

    citiesFile.open(citiesTxt);
    queryFile.open(queriesTxt);

    vector<string> cities;
    vector<int> coordinates;
    vector<Node *> neVector;
    vector<Node *> seVector;
    vector<Node *> swVector;
    vector<Node *> nwVector;

    vector<Node *> allCities;

    // cout << "Cities and coordinates: " << endl;
    while (getline(citiesFile, line))
    {
        if (line.find(' ') == line.rfind(' '))
        {
            boardSize = line;
        }

        // cout << line << endl;
        string m = line.substr(line.find(' ') + 1);
        string cityName = line.substr(0, line.find(' '));
        string xCoordinate = m.substr(0, m.find(' '));
        string yCoordinate = m.substr(m.find(' ') + 1);
        coordinates.push_back(stoi(xCoordinate));
        coordinates.push_back(stoi(yCoordinate));
        cities.push_back(cityName);
    }

    vector<int> queries;
    // cout << endl << "Queries: " << endl;
    while (getline(queryFile, line))
    {
        // cout << line << endl;
        string queryX = line.substr(0, line.find(','));
        string queryY = line.substr(line.find(' ') + 1).substr(0, line.find(','));
        string radius = line.substr(line.find(' ') + 1).substr(line.find(' ') + 1);

        queries.push_back(stoi(queryY));
        queries.push_back(stoi(queryY));
        queries.push_back(stoi(queryY));

        cout << "queryX: " << stoi(queryX) << endl;
        cout << "queryY: " << stoi(queryY) << endl;
        cout << "radius: " << radius << endl;
    }

    // for (int i = 2; i < coordinates.size(); i+=2)
    // {
    //     cout << "x coordinate: " << coordinates[i] << ", y coordinate: " << coordinates[i+1] << ", city name: "<< cities[i/2] << endl;
    // }

    // for (int y = 1; y < cities.size(); y++)
    // {
    //     cout << cities[y] << endl;
    // }

    // for (int i = 2; i < coordinates.size(); i+=2)
    // {
    //     cout << "x coordinate: " << coordinates[i] << ", y coordinate: " << coordinates[i+1] << ", city name: "<< cities[i/2] << endl;
    // }

    Node *rootNode = nullptr;

    for (int j = 2; j < coordinates.size(); j += 2)
    {
        createCityNodes(cities[j / 2], coordinates[j], coordinates[j + 1], allCities);
    }

    // for (int k = 0; k < allCities.size(); k++)
    // {
    //     cout << allCities[k]->cityName << " " << allCities[k]->ne << " " << allCities[k]->se << " " << allCities[k]->sw << " " << allCities[k]->nw << " " << allCities[k]->x << " " << allCities[k]->y << endl;
    // }

    int ctr = 1;
    while (ctr != allCities.size())
    {
        // cout << "City name: " << allCities[ctr]->cityName << " ";
        createVectors(allCities[0], allCities[ctr], neVector, seVector, swVector, nwVector);
        // cout << endl;
        ctr++;
    }

    // setFirstLevel(rootNode, neVector, seVector, swVector, nwVector);

    // recursiveSetter(rootNode, neVector, seVector, swVector, nwVector);

    // cout << allCities[0]->cityName << endl;
    // cout << allCities[0]->ne << endl;
    // cout << allCities[0]->se << endl;
    // cout << allCities[0]->sw << endl;
    // cout << allCities[0]->nw << endl;
    // cout << allCities[0]->x << endl;
    // cout << allCities[0]->y << endl;

    rootNode = allCities[0];
    for (int a = 1; a < allCities.size(); a++)
    {
        inserter(allCities[a], rootNode);
    }

    pretty_print(rootNode);

    return 0;
};