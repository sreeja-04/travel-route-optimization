#include<iostream>
#include<limits.h>
using namespace std;

#define max 5

void shortestPathFromSource(int m[max][max], int s)
{
    int v[max][max] = {0};
    int pathTaken[max];
    int pathLength = 0;

    int x = s;
    int min;
    int visited = 1 << s;

    for(int i = 0; i < max - 1; i++) 
    {
        min = INT_MAX;
        int next = -1;

        for(int j = 0; j < max; j++)
        {
            if (m[x][j] < min && m[x][j] != 0 && !(visited & (1 << j)))
            {
                min = m[x][j];
                next = j;
            }
        }

        if(next != -1)
        {
            visited |= (1 << next);
            pathTaken[pathLength++] = x; 
            x = next;
        }
    }

    v[x][s] = m[x][s];
    visited |= (1 << s);
    pathTaken[pathLength++] = x; 

    cout << "Path from source " << s << " to all vertices: ";
    for(int i = 0; i < pathLength; i++)
    {
        cout << pathTaken[i] << " -> ";
    }
    cout << s << endl; 
}

int main()
{
    int distance[max][max] = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 20},
        {20, 25, 30, 0, 40},
        {25, 30, 20, 40, 0}
    };

    int price[max][max] = {
        {0, 123, 456, 789, 234},
        {567, 0, 890, 321, 654},
        {987, 432, 0, 765, 210},
        {543, 876, 109, 0, 321},
        {678, 210, 543, 876, 987}
    };

    int s, d;
    char choice;

    int e = 1;
    do{
    cout << "Enter 'S' to find shortest path/least price between a source and destination." << endl;
    cout << "Enter 'A' to find shortest path from a source to all vertices." << endl;
    cin >> choice;
        if(choice == 'S' || choice == 's')
        {   
            e = 0;
            cout << "Enter the source vertex: ";
            cin >> s;
            if (s < 0 || s >= max) {
                cout << "Invalid source vertex! Please enter a number between 0 and " << (max - 1) << "." << endl;
                e = 1;
                continue;
            }
            cout << "Enter the destination vertex: ";
            cin >> d;
            if (d < 0 || d >= max) {
                cout << "Invalid destination vertex! Please enter a number between 0 and " << (max - 1) << "." << endl;
                e = 1;
                continue;
            }
            cout << "Enter 'D' for shortest distance or 'P' for least price: ";
            cin >> choice;
            if (choice != 'D' && choice != 'd' && choice != 'P' && choice != 'p') {
                cout << "Invalid choice! Please enter 'D' or 'P'." << endl;
                e = 1;
                continue;
            }

            int path[max][max];
            if(choice == 'D' || choice == 'd')
            {
                for(int i = 0; i < max; i++)
                {
                    for(int j = 0; j < max; j++)
                    {
                        path[i][j] = distance[i][j];
                    }
                }
            }
            else if(choice == 'P' || choice == 'p')
            {
                for(int i = 0; i < max; i++)
                {
                    for(int j = 0; j < max; j++)
                    {
                        path[i][j] = price[i][j];
                    }
                }
            }
            else
            {
                cout << "Invalid choice! Please enter 'D' or 'P'." << endl;
                return 0;
            }

            for(int k = 0; k < max; k++)
            {
                for(int i = 0; i < max; i++)
                {
                    for(int j = 0; j < max; j++)
                    {
                        if(path[i][k] != INT_MAX && path[k][j] != INT_MAX && path[i][k] + path[k][j] < path[i][j])
                        {
                            path[i][j] = path[i][k] + path[k][j];
                        }
                    }
                }
            }

            cout << "Shortest ";
            if(choice == 'D' || choice == 'd')
            {
                cout << "distance";
            }
            else
            {
                cout << "price";
            }
            cout << " between " << s << " and " << d << ": " << path[s][d] << endl;
        }
        else if(choice == 'A' || choice == 'a')
        {
            e = 0;
            cout << "Enter the source vertex: ";
            cin >> s;
            if (s < 0 || s >= max) {
                cout << "Invalid source vertex! Please enter a number between 0 and " << (max - 1) << "." << endl;
                e = 1;
                continue;
            }
            shortestPathFromSource(distance, s);
        }
        else
        {
            e = 1;
            cout << "Invalid choice! Please enter 'S' or 'A'." << endl;
        }

    }while(e==1);

    return 0;
}


