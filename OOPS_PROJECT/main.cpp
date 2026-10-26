#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int main()
{
    graph g1, g2;
    int choice, graphNo, weight;
    string source, destination, label;

    do
    {
        cout << "\n========== GraphTheory Explorer ==========\n";
        cout << "1. Add vertex\n";
        cout << "2. Add edge\n";
        cout << "3. Display graphs\n";
        cout << "4. Input a complete graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Select graph (1 or 2): ";
                cin >> graphNo;

                if (graphNo != 1 && graphNo != 2)
                {
                    cout << "Invalid graph number!\n";
                    break;
                }

                cout << "Enter vertex label: ";
                cin >> label;

                bool added = false;

                switch (graphNo)
                {
                    case 1:
                        added = g1.add_vertex(label);
                        break;

                    case 2:
                        added = g2.add_vertex(label);
                        break;
                }

                if (added)
                    cout << "Vertex added successfully.\n";
                else
                    cout << "Vertex could not be added. It may already exist or the graph may be full.\n";

                break;
            }

            case 2:
            {
                cout << "Select graph (1 or 2): ";
                cin >> graphNo;

                if (graphNo != 1 && graphNo != 2)
                {
                    cout << "Invalid graph number!\n";
                    break;
                }

                cout << "Enter source vertex: ";
                cin >> source;

                cout << "Enter destination vertex: ";
                cin >> destination;

                cout << "Enter edge weight: ";
                cin >> weight;

                bool added = false;

                switch (graphNo)
                {
                    case 1:
                        added = g1.add_edge(source, destination, weight);
                        break;

                    case 2:
                        added = g2.add_edge(source, destination, weight);
                        break;
                }

                if (added)
                    cout << "Edge added successfully.\n";
                else
                    cout << "Edge could not be added. Check whether both vertices exist.\n";

                break;
            }

            case 3:
            {
                cout << "\n--- Graph 1 ---\n";
                cout << g1;

                cout << "\n--- Graph 2 ---\n";
                cout << g2;

                break;
            }

            case 4:
            {
                cout << "Select graph (1 or 2): ";
                cin >> graphNo;

                if (graphNo != 1 && graphNo != 2)
                {
                    cout << "Invalid graph number!\n";
                    break;
                }

                cout << "\nEnter graph data in this format:\n";
                cout << "Number of vertices\n";
                cout << "Vertex labels separated by spaces\n";
                cout << "Number of edges\n";
                cout << "Source destination weight (one edge per line)\n";

                if (graphNo == 1)
                    cin >> g1;
                else
                    cin >> g2;

                if (cin.fail())
                {
                    cout << "Invalid graph input!\n";
                    return 1;
                }

                cout << "Graph input completed successfully.\n";
                break;
            }

            case 5:
            {
                cout << "Exiting GraphTheory Explorer.\n";
                break;
            }

            default:
            {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }

    } while (choice != 5);

    return 0;
}
