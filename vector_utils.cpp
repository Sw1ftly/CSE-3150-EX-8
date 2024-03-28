#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>


struct Vector2D {
    double x, y;

    
    Vector2D(double x, double y) : x(x), y(y) {}

    
    double magnitude() const {
        return sqrt(x*x + y*y);
    }
};


double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}


double cosineDistance(const Vector2D& v1, const Vector2D& v2) {
    double dot = dotProduct(v1, v2);
    double magV1 = v1.magnitude();
    double magV2 = v2.magnitude();
    return dot / (magV1 * magV2);
}

int main() {
    std::vector<Vector2D> vectors;
    std::string filename = "vectors.txt";
    std::ifstream file(filename);

    
    double x, y;
    while (file >> x >> y) {
        vectors.emplace_back(x, y);
    }

    
    std::vector<std::pair<double, std::pair<int, int>>> distances;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double distance = cosineDistance(vectors[i], vectors[j]);
            distances.emplace_back(distance, std::make_pair(i, j));
        }
    }

    
    std::sort(distances.begin(), distances.end());

    
    for (const auto& pair : distances) {
        std::cout << "(" << pair.second.first << ", " << pair.second.second << "): ";
        std::cout << pair.first << std::endl;
    }

    return 0;
}