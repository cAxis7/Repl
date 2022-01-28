// Algorithmo Bellman-Ford pero el grafo es no dirigido

//Juan Del Valle Del Valle
//4 de octubre de 2021
#include <bits/stdc++.h> 
using namespace std;

// una estructura para representar el borde de un grafico
struct Edge { 
    int src, dest, weight; 
}; 
  
// la estructura de grupo conectado y ponderado
struct Graph { 
    int V, E;// V: Numero de vertices, E: Numeros de ejes   
    struct Edge* edge; 
}; 
  
// Se crea una grafica con vertices V y eje E. 
struct Graph* createGraph(int V, int E) { 
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
  
// Funcion para imprimir los Vertice y con sus distancias en el grafo
void printArr(int dist[], int n){ 
    printf("Vertice   Distancia desde la fuente\n"); 
    for (int i = 0; i < n; ++i)  printf("%d 		 %d\n", i, dist[i]); 
} 
  
// Esta es la funcion de hallar las distancias usando la funcion Bellman-Ford 
void BellmanFord(struct Graph* graph, int src) { 
    int V = graph->V; 
    int E = graph->E; 
    int dist[V]; 
  
    // Aqui vamos a inicializar todos los nodos del vertice a infinito.
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX; 
    dist[src] = 0; 
  
    
    for (int i = 1; i <= V - 1; i++) { 
        for (int j = 0; j < E; j++) { 
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 
  
    for (int i = 0; i < E; i++) { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
            printf("El gráfico contiene un ciclo de peso negativo"); 
            return; // Si se detecta un ciclo negativo se sale 
        } 
    } 
  
    printArr(dist, V); 
  
    return; 
} 
  
// La funcion para inicializar 
int main() { 
      int V; // Numero de vertices en el grafo 
      int E; // Numeros de ejes en el grafo 
      int N; // punto de inicio
    
      printf("Entra el numero de vertices\n"); 
      cin >> V;

      printf("Entra el numero de ejes\n"); 
      cin >> E;
      
      struct Graph* graph = createGraph(V, E * 2);
      
      int src, dest, weight;
      printf("Entra el punto origen, el punto final y el peso\n"); 
      for(int i = 0; i < E; i++){

        cin >> src >> dest >> weight;

        //Aqui ponemos el destino y el origen con su valor en la grafica para ambos lados por el grafo es no dirigido
        graph->edge[i * 2].src = src; 
        graph->edge[i * 2].dest = dest;
        graph->edge[i * 2].weight = weight;

        graph->edge[i * 2 + 1].src = dest; 
        graph->edge[i * 2 + 1].dest = src;
        graph->edge[i * 2 + 1].weight = weight;        
      }
          
      printf("Ahora inserta el punto de inicio\n");
      cin >> N;
      BellmanFord(graph, N); 
    
      return 0; 
} 
