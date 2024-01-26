#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

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

string assignDirection(Node *root, int x1, int y1)
{
    string direction = "null";
    if (x1 < root->x)
    {
        if (y1 < root->y)
        {
            direction = "SW";
        }

        else if (y1 >= root->y)
        {
            direction = "NW";
            // nwVector.push_back(p);
        }
    }

    else if (y1 < root->y || x1 == root->x)
    {
        direction = "SE";
        // cout << "SE" << endl;
        // seVector.push_back(p);
    }

    else
    {
        direction = "NE";
        // cout << "NE" << endl;
        // neVector.push_back(p);
    }

    return direction;
}

double calculateDistance(int qx, int qy, int cx, int cy, int radius)
{
    //! x1, y1 -> QUERY POINT
    //! x2, y2 -> CITY COORDINATES
    // double distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    float const1x = qx + radius;
    float const2x = qx - radius;

    float const1y = qy + radius;
    float const2y = qy - radius;

    (const1x, const1y);
    (const1x, const2y);
    (const2x, const1y);
    (const2x, const2y);

    if (const1y > cy)
    {
        if (const1x >= cx)
        {
            cout << "NE" << endl;
        }
        else
        {
            cout << "NW" << endl;
        }
    }

    else if (const1y < cy)
    {
        if (const1x >= cx)
        {
            cout << "SE" << endl;
        }
        else
        {
            cout << "SW" << endl;
        }
    }

    else
    {
        if (const1x > cx)
        {
            cout << "NE" << endl;
        }
        else
        {
            cout << "NW" << endl;
        }
    }
    return 0;
}

void recursiveSearch(Node *root, int x1, int y1)
{
    Node *tmp = new Node();
    Node *father = new Node();

    tmp = root;
    father = tmp;

    string direction = "null";
    if (root != NULL)
    {

        if (x1 < root->x)
        {
            if (y1 < root->y)
            {
                direction = "SW";
                tmp = father->sw;
                recursiveSearch(tmp, x1, y1);
            }

            else if (y1 >= root->y)
            {
                direction = "NW";
                tmp = father->nw;
                recursiveSearch(tmp, x1, y1);
            }
        }

        else if (y1 < root->y || x1 == root->x)
        {
            direction = "SE";
            tmp = father->se;
            recursiveSearch(tmp, x1, y1);
        }

        else
        {
            direction = "NE";
            tmp = father->ne;
            recursiveSearch(tmp, x1, y1);
        }
    }
}

void recursiveRadius(Node *root, int x1, int y1, int radius)
{
    Node *tmp = new Node();
    Node *father = new Node();

    tmp = root;
    father = tmp;

    string direction = "null";

    if (root != NULL)
    {
        float distance = distance = sqrt(((root->x - x1) * (root->x - x1)) + ((root->y - y1) * (root->y - y1)));
        cout << root->cityName << endl;
        // inside
    }

    else
    {
        cout << "Nowehere" << endl;
        //  outside
    }

    if (root != NULL)
    {

        if (x1 < root->x)
        {
            if (y1 < root->y)
            {
                direction = "SW";
                tmp = father->sw;
                recursiveRadius(tmp, x1, y1, radius);
            }

            else if (y1 >= root->y)
            {
                direction = "NW";
                tmp = father->nw;
                recursiveRadius(tmp, x1, y1, radius);
            }
        }

        else if (y1 < root->y || x1 == root->x)
        {
            direction = "SE";
            tmp = father->se;
            recursiveRadius(tmp, x1, y1, radius);
        }

        else
        {
            direction = "NE";
            tmp = father->ne;
            recursiveRadius(tmp, x1, y1, radius);
        }
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

bool cityInVector(vector<string> visitedPlaces, string name)
{
    for (string i : visitedPlaces)
    {
        if (i == name)
        {
            return true;
        }
    }
    return false;
}

void searchTree(Node *root, int qx, int qy, int radius, vector<string> &visitedPlaces)
{
    //* Maxes
    int ymax = qy + radius;
    int ymin = qy - radius;
    int xmax = qx + radius;
    int xmin = qx - radius;

    if (root != NULL)
    {
        if (!cityInVector(visitedPlaces, root->cityName))
        {
            visitedPlaces.push_back(root->cityName);
        }
        //* Root
        int rootx = root->x;
        int rooty = root->y;

        float distance = sqrt(((rootx - qx) * (rootx - qx)) + ((rooty - qy) * (rooty - qy)));
        if (rooty > ymax && rootx < xmin)
        {
            // 1 SE
            searchTree(root->se, qx, qy, radius, visitedPlaces);
        }

        else if (rooty > ymax && rootx < xmax && rootx > xmin)
        {
            // root = root->se;
            searchTree(root->se, qx, qy, radius, visitedPlaces);
            // root = root->sw;
            searchTree(root->sw, qx, qy, radius, visitedPlaces);
            // 2 SE, SW
        }

        else if (rooty > ymax && rootx > xmax)
        {
            searchTree(root->sw, qx, qy, radius, visitedPlaces);
            // 3 SW
        }

        else if (rooty < ymax && rooty > ymin && rootx < xmin)
        {
            searchTree(root->se, qx, qy, radius, visitedPlaces);
            searchTree(root->ne, qx, qy, radius, visitedPlaces);
            // 4 SE, NE
        }

        else if (rooty < ymax && rooty > ymin && rootx > xmax)
        {
            searchTree(root->sw, qx, qy, radius, visitedPlaces);
            searchTree(root->nw, qx, qy, radius, visitedPlaces);
            // 5 SW, NW
        }

        else if (rooty < ymin && rootx < xmin)
        {
            searchTree(root->ne, qx, qy, radius, visitedPlaces);
            // 6 NE
        }

        else if (rooty < ymin && rootx > xmin && rootx < xmax)
        {
            searchTree(root->ne, qx, qy, radius, visitedPlaces);
            searchTree(root->nw, qx, qy, radius, visitedPlaces);
            // 7 NE, NW
        }

        else if (rooty < ymin && rootx > xmax)
        {
            searchTree(root->nw, qx, qy, radius, visitedPlaces);
            // 8 NW
        }

        else if (rooty < ymax && rootx > xmin && distance > radius)
        {
            searchTree(root->se, qx, qy, radius, visitedPlaces);
            searchTree(root->sw, qx, qy, radius, visitedPlaces);
            searchTree(root->ne, qx, qy, radius, visitedPlaces);
            // 9 SE, SW, NE (ALL BUT NW)
        }

        else if (rooty < ymax && rootx < xmax && distance > radius)
        {
            searchTree(root->se, qx, qy, radius, visitedPlaces);
            searchTree(root->sw, qx, qy, radius, visitedPlaces);
            searchTree(root->nw, qx, qy, radius, visitedPlaces);
            // 10 SE, SW, NW (ALL BUT NE)
        }

        else if (rooty < ymin && rootx > xmin && distance > radius)
        {
            searchTree(root->se, qx, qy, radius, visitedPlaces);
            searchTree(root->ne, qx, qy, radius, visitedPlaces);
            searchTree(root->nw, qx, qy, radius, visitedPlaces);
            // 11 SE, NE, NW (ALL BUT SW)
        }

        else if (rooty > ymin && rootx < xmax && distance > radius)
        {
            searchTree(root->sw, qx, qy, radius, visitedPlaces);
            searchTree(root->ne, qx, qy, radius, visitedPlaces);
            searchTree(root->nw, qx, qy, radius, visitedPlaces);
            // 12 SW, NE, NW (ALL BUT SE)
        }

        else if(distance < radius)
        {
            searchTree(root->se, qx, qy, radius, visitedPlaces);
            searchTree(root->sw, qx, qy, radius, visitedPlaces);
            searchTree(root->ne, qx, qy, radius, visitedPlaces);
            searchTree(root->nw, qx, qy, radius, visitedPlaces);
            // 13 SE, SW, NE, NW (ALL)
        }
    }
    else
    {
        return;
    }
}

void pretty_print(Node *root, vector<Node *> &sortedCities)
{ // pretty print the quadtree rooted at root:
    if (root == NULL)
    {
        return;
    }
    if (root->isRead == false)
    {
        cout << root->cityName << endl;
        sortedCities.push_back(root);
        root->isRead = true;
    }
    // if the tree is not empty
    pretty_print(root->se, sortedCities); // recursively print the south east subtree
    pretty_print(root->sw, sortedCities); // recursively print the south west subtree
    pretty_print(root->ne, sortedCities); // recursively print the north east subtree
    pretty_print(root->nw, sortedCities); // recursively print the north west subtree
}

int main()
{
    ifstream citiesFile, queryFile;
    string citiesTxt = "cities.txt", queriesTxt = "queries0.txt", boardSize, line, s;
    bool error_found = false, error_closing = false;

    citiesFile.open(citiesTxt);
    queryFile.open(queriesTxt);

    vector<string> cities;
    vector<int> coordinates;
    vector<Node *> allCities;
    vector<Node *> sortedCities;
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
    vector<int> radiuses;
    // cout << endl << "Queries: " << endl;
    while (getline(queryFile, line))
    {
        // cout << line << endl;
        string queryX = line.substr(0, line.find(','));
        string queryY = line.substr(line.find(' ') + 1).substr(0, line.find(','));
        string radius = line.substr(line.find(' ') + 1).substr(line.find(' ') + 1);

        queries.push_back(stoi(queryX));
        queries.push_back(stoi(queryY));
        radiuses.push_back(stoi(radius));

        // cout << "queryX: " << stoi(queryX) << endl;
        // cout << "queryY: " << stoi(queryY) << endl;
        // cout << "radius: " << radius << endl;
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

    int c = 0;

    for (int b = 0; b < queries.size() - 1; b += 2)
    {
        // cout << queries[b] << " " << queries[b + 1] << " " << assignDirection(rootNode, queries[b], queries[b + 1]) << " ";
        // recursiveRadius(rootNode, queries[b], queries[b + 1], radiuses[c]);
        if (c != queries.size() / 2)
        {
            // cout << " Radius: " << radiuses[c] << endl;
            c++;
        }
    }

    pretty_print(rootNode, sortedCities);
    cout << endl;

    vector<string> visitedPlaces;

    for (int d = 0; d < queries.size() - 1; d += 2)
    {
        vector<Node *> inArea;
        // cout << queries[d] << " " << queries[d + 1] << " " << radiuses[(d / 2)] << endl;
        for (int e = 0; e < sortedCities.size(); e++)
        {
            float distance = sqrt(((sortedCities[e]->x - queries[d]) * (sortedCities[e]->x - queries[d])) + ((sortedCities[e]->y - queries[d + 1]) * (sortedCities[e]->y - queries[d + 1])));
            // cout << "City Name: " << sortedCities[e]->cityName << " Coordinate X: " << sortedCities[e]->x << " Query X: " << queries[d] << " Coordinate Y: " << sortedCities[e]->y
            //      << " Query Y: " << queries[d + 1] << " Radius: " << radiuses[d / 2] << " Distance: " << distance << endl;
            // cout << distance << endl;
            visitedPlaces.clear();
            searchTree(rootNode, queries[d], queries[d + 1], radiuses[d / 2], visitedPlaces);
            if (distance <= radiuses[d / 2])
            {
                inArea.push_back(sortedCities[e]);
            }
        }
        cout << endl;
        if (visitedPlaces.size() > 0)
        {
            for (int s = 0; s < visitedPlaces.size(); s++)
            {
                cout << visitedPlaces[s] << " ";
            }
        }
        cout << endl;
        if (inArea.size() > 0)
        {
            for (int s = 0; s < inArea.size(); s++)
            {
                if (s - 1 != inArea.size() - 2)
                {
                    cout << inArea[s]->cityName << ", ";
                }
                else
                {
                    cout << inArea[s]->cityName;
                }
            }
        }
        else
        {
            cout << "<None>";
        }
        cout << endl;
    }

    return 0;
};