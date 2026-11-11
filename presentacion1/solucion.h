// Solucion.h
#include <vector>

struct Subtour {
    int root_id;                  // Nodo VC donde se estaciona el remolque
    std::vector<int> clientes;    // Clientes (TC o VC) atendidos en el subtour por el camión solo
    double demanda_total = 0.0;
    double distancia = 0.0;
};

struct Ruta {
    int tipo_ruta;                // 0: PTR (Camión solo), 1: PVR (Vehículo completo), 2: CVR (Con subtours)
    std::vector<int> secuencia_principal; // Nodos visitados por la unidad combinada/camión principal
    std::vector<Subtour> subtours;        // Subtours desacoplados en esta ruta
    double carga_camion = 0.0;
    double carga_remolque = 0.0;
    double distancia_total = 0.0;
};

class Solucion {
public:
    std::vector<Ruta> rutas;
    double costo_total = 0.0;
    bool es_factible = true;

    void calcular_costo_total();
};