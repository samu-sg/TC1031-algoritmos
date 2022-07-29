#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> 
#include <map>
#include <queue>
#include "LinkedList.h"
#include "IP.h"
#include "HashTable.h"

#define inf 0x3f3f3f3f

template <class T>
class Graph {
  private:
    int numNodes;
    int numEdges;
    int indexBootMaster;

    // boot master <ip, degree>
    std::pair<std::string, int> BootMaster;
    // Lista de adyacencia, vector de listas ligadas de pares (vertice, peso)
    std::vector<LinkedList<std::pair<int, int>>> adjList;
    // ips a numero entero
    std::map<unsigned int, IP> mapIP;
    // vector de ips
    std::vector<IP> IPS;
    // max heap <degree, IP>
    std::priority_queue<std::pair<int, std::string>> maxHeap;
    // Hash Table
    HashTable<unsigned int, IP> hashTable;

    void split(std::string line, std::vector<int> &res);
    
  public:
    Graph();
    ~Graph();
    void readGraph(std::string fileName);
    void writeDegreesOut(std::string fileName);
    void writeIpTopDegreesOut(std::string fileName);
    void writeShortestPath(std::string fileName);

    void createHashTable();
    void getIpSummary();
};

template <class T>
// Complejidad O(1)
Graph<T>::Graph() {
  numNodes = 0;
  numEdges = 0;
}

template <class T>
// Complejidad O(1)
Graph<T>::~Graph(){
  adjList.clear();
  IPS.clear();
}

template <class T>
// Almacena los datos en en una lista de adyacencias organizada por la dirección IP. Complejidad O(n)
void Graph<T>::readGraph(std::string fileName){
  std::string IP1, IP2, line, W;
  int i = 0; 
  std::ifstream archivo (fileName);
  if (!archivo.good()) {
    archivo.close();
    throw std::invalid_argument("File not found");
  }
  else {
    while (std::getline(archivo, line)) {
      if (i == 0) {
        std::vector<int> res;
        split(line, res);
        numNodes = res[0];
        numEdges = res[1];
        // Reservar memoria para los renglones de la lista de adyacencia
        // (renglon 0 no utilizado)
        adjList.resize(numNodes + 1);
        IPS.resize(numNodes + 1);
        // Declara una lista vacia para cada renglon y la almacena en el vector
        for (int j = 1; j <= numNodes; j++) {
          LinkedList<std::pair<int, int>> List;
          adjList[j] = List;
        }
      } else if (i > 0 && i <= numNodes) {
        IP ip(line, i);
        IPS[i] = ip;
        mapIP.insert({ip.getIPValue(), ip}); // {string ip, int}
      } else if (i > numNodes) {
        std::size_t found = line.find(":", 15);
        IP1 = line.substr(15, found - 15);
        std::size_t f2 = line.find(" ", found + 1);
        std::size_t f3 = line.find(":", f2 + 1);
        IP2 = line.substr(f2, f3 - f2);
        std::size_t f4 = line.find(" ", f3 + 1);
        std::size_t f5 = line.find(" ", f4 + 1);
        W = line.substr(f4, f5 - f4);
        // Crear arista ip1 a ip2 con un peso
        IP ip1(IP1, 0);
        IP ip2(IP2, 0);
        std::map<unsigned int, IP>::iterator k;
        int ip1Index, ip2Index;
        k = mapIP.find(ip1.getIPValue());
        if (k != mapIP.end())
          ip1Index = k->second.getIpIndex();
        k = mapIP.find(ip2.getIPValue());
        if (k != mapIP.end())
          ip2Index = k->second.getIpIndex();
        adjList[ip1Index].addLast({ip2Index, stoi(W)});
        // Grafo dirigido - Aumentar grados de salida y entrada
        IPS[ip1Index].addDegreeOut();
        IPS[ip2Index].addDegreeIn();
      }
      i++;
    }
    archivo.close();
  }
}

template <class T>
// Complejidad O(n)
void Graph<T>::split(std::string line, std::vector<int> &res) {
 size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

template <class T>
// Determina el grado de salida de cada nodo del grafoy almacena los pares (IP, grado de salida) en un archivo de texto. Complejidad O(n)
void Graph<T>::writeDegreesOut(std::string fileName) {
  std::ofstream archivo(fileName);
  if(!archivo.good()) {
    archivo.close();
    throw std::invalid_argument("File not foud");
  }
  else {
  for (int i = 1 ; i <= numNodes ; i++) {
    archivo << "ip: " << IPS[i].getIp() << " - grado: " << IPS[i].getDegreeOut() << std::endl;
    maxHeap.push(std::make_pair(IPS[i].getDegreeOut(), IPS[i].getIp()));
  }
  archivo.close();
  }
}

template <class T>
// Determina las 5 IPs con mayor grado de salida y almacena una lista con los pares (IP, grado de salida). Complejidad O(n)
void Graph<T>::writeIpTopDegreesOut(std::string fileName) {
  std::ofstream archivo(fileName);
  if(!archivo.good()) {
    archivo.close();
    throw std::invalid_argument("File not foud");
  }
  else {
    archivo << "Ip, Degree" << std::endl;
    for(int i = 1 ; i <= 5 ; i++) {
      std::pair<int, std::string> p = maxHeap.top();
      archivo << p.second << ", " << p.first << std::endl;
      maxHeap.pop();
      if (i == 1) {
        BootMaster.first = p.second;
        BootMaster.second = p.first;
        IP tmpBootMaster(BootMaster.first, 0);
        std::map<unsigned int, IP>::iterator it;
        it = mapIP.find(tmpBootMaster.getIPValue());
        if (it != mapIP.end())
          indexBootMaster = it->second.getIpIndex();
      }
    }
    // ¿En qué dirección IP presumiblemente se encuentra el boot master?
    std::cout << "BOOTMASTER\n";
    std::cout << "Ip: " << BootMaster.first << std::endl;
    std::cout << "Degree: " << BootMaster.second << std::endl;
    std::cout << "Position (index): " << indexBootMaster << std::endl;
    
  archivo.close();
  }
}

template <class T>
// Encuentre el camino más corto entre la IP que identificó como el boot master y el resto de los nodos (IPs) del grafo. Complejidad O(E log V)
void Graph<T>::writeShortestPath(std::string fileName) {
  // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>> path;

  int x = indexBootMaster;
  std::vector<int> dist(numNodes + 1, inf);

  // Insert source itself in priority queue and initialize
  // its distance as 0.
  path.push(std::make_pair(0, x)); // par (distancia, nodo)
  dist[x] = 0;

  // Looping till priority queue becomes empty (or all distances are not
  // finalized)
  while (!path.empty()) {
    // The first vertex in pair is the minimum distance
    // vertex, extract it from priority queue.
    // vertex label is stored in second of pair (it
    // has to be done this way to keep the vertices
    // sorted distance (distance must be first item
    // in pair)
    int u = path.top().second;
    path.pop();
    // Recupera los vecinos del nodo "u"
    for (int j = 0; j < adjList[u].getNumElements(); j++) {
      std::pair<int, int> p = adjList[u].getData(j);

      // Get vertex label and weight of current adjacent of u.
      int v = p.first;
      int weight = p.second;
      //  If there is shorted path to v through u.
      if (dist[v] > dist[u] + weight) {
        // Updating distance of v
        dist[v] = dist[u] + weight;
        path.push(std::make_pair(dist[v], v));
      }
    }
  }

  // Print shortest distances stored in fileName
  std::ofstream file(fileName);
  if(!file.good()) {
    file.close();
    throw std::invalid_argument("File not foud");
  }
  else {
    int maxDistance = dist[1];
    int maxIndex = 1;
    file << "Ip, Distance" << std::endl;
    for(int j = 1 ; j <= numNodes ; j++){
      file << IPS[j].getIp() << ", " << dist[j] << std::endl;
      if (dist[j] > maxDistance) {
        maxDistance = dist[j];
        maxIndex = j;
      }
    }
    // ¿Cuál es la dirección IP que presumiblemente requiere más esfuerzo para que el boot master la ataque?
    std::cout << std::endl;
    std::cout << "Farthest Ip from BootMaster: " << IPS[maxIndex].getIp() << std::endl;
    std::cout << "Distance from BootMaster: " << maxDistance << std::endl;
    std::cout << "Position (index): " << maxIndex << std::endl;
    file.close();
  }
}


template <class T>
// Llena la tabla hash con la informacion de cada IP.
// Complejidad O(n)
void Graph<T>::createHashTable() {
  // Test para colisiones 
  // resultados redondeados a los primos mas cercanos
  // 13370 * 1.4 = 17383, colisiones: 8804
  //             = 17377, colisiones: 8914
  // 13370 * 2.1 = 28081, colisiones: 2093
  //               28069, colisiones: 2029
  // 13370 * 2.2 = 29411, colisiones: 1975
  hashTable.setMaxSize(29411);
  std::cout << "Filling hashTable... " << std::endl;
  std::cout << "Maximum capacity: " << hashTable.getMaxSize() << std::endl;
  for (int i = 1; i < IPS.size(); i++) {
    hashTable.add(IPS[i].getIPValue(), IPS[i]);
  }
  std::cout << "Hash Table Size: " << hashTable.getSize() << std::endl;
  std::cout << "Colllisions: " << hashTable.getColisiones() <<std::endl;
}

template <class T>
// Despliega informacion de la Ip dada por el ususario
// Complejidad O(n logn) 
void Graph<T>::getIpSummary() {
	std::string input;
	std::cout << "Enter Ip to display summary: ";
  std::cin >> input;
	IP ip(input, 0);
	IP inputIp = hashTable.find(ip.getIPValue());

  // Ip summary
  std::cout << std::endl;
  std::cout << "Writing summary..." << std::endl;
  std::cout << "Ip: " << inputIp.getIp() << std::endl;
  std::cout << "No. of addresses accessed by the Ip: " << inputIp.getDegreeOut() << std::endl;
  std::cout << "No. of addresses trying to access the Ip: " << inputIp.getDegreeIn() << std::endl;

  std::vector<IP> accessIps;
  int j = inputIp.getIpIndex();
  for (int i = 0; i < adjList[j].getNumElements(); i++) {
    std::pair<int, int> par = adjList[j].getData(i);
    accessIps.push_back(IPS[par.first]);
  }
  // sort using built-in function in STL
  // https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/
  std::sort(accessIps.begin(), accessIps.end());
  std::cout << "Addresses accessed by the Ip: " << std::endl;
  for (int i = 0; i < accessIps.size(); i++) {
    std::cout << accessIps[i].getIp() << std::endl;
  }
}


#endif  // _GRAPH_H_