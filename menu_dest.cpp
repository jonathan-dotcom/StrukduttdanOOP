#include <iostream>
#include <vector>
#include <iomanip>

// Deklarasi kelas Graph
class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Konstruktor
    Graph(int vertices) : vertices(vertices) {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    // Destruktor
    ~Graph() {
        std::cout << "Graph object is being destroyed." << std::endl;
    }

    // Metode untuk menambahkan edge pada graf
    void addEdge(int source, int destination) {
        adjMatrix[source][destination] = 1;
        adjMatrix[destination][source] = 1;
    }

    // Metode untuk menampilkan graf
    void displayGraph() {
        std::cout << "Graph Adjacency Matrix:" << std::endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int option, vertices, vertex1, vertex2;

    std::cout << std::setw(130) << std::setfill('*') << "" << std::endl;
    std::cout << std::setw(80) << std::setfill(' ') << " WELCOME TO FP KELOMPOK 5 STRUKDAT B " << std::endl;
    std::cout << std::setw(130) << std::setfill('*') << "" << std::endl;

    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> vertices;

    Graph graph(vertices);

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Edge\n";
        std::cout << "2. Display Graph\n";
        std::cout << "3. Exit\n";
        std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "\nEnter vertices for the edge (space-separated): ";
                std::cin >> vertex1 >> vertex2;
                graph.addEdge(vertex1, vertex2);
                break;

            case 2:
                graph.displayGraph();
                break;

            case 3:
                std::cout << "\nExiting program.\n";
                break;

            default:
                std::cout << "\nInvalid choice. Please try again.\n";
        }
    } while (option != 3);

    return 0;
}