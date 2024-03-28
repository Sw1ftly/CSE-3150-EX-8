#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector_utils.h"

TEST_CASE("Check vector magnitude") {
    CHECK(Vector2D(3, 4).magnitude() == doctest::Approx(5.0));
    CHECK(Vector2D(-3, 4).magnitude() == doctest::Approx(5.0));
    CHECK(Vector2D(0, 0).magnitude() == doctest::Approx(0.0));
}

TEST_CASE("Check dot product") {
    CHECK(dotProduct(Vector2D(1, 0), Vector2D(0, 1)) == doctest::Approx(0.0));
    CHECK(dotProduct(Vector2D(3, 5), Vector2D(2, -1)) == doctest::Approx(1.0));
    CHECK(dotProduct(Vector2D(-1, -1), Vector2D(1, 1)) == doctest::Approx(-2.0));
}

TEST_CASE("Check cosine distance") {
    CHECK(cosineDistance(Vector2D(1, 0), Vector2D(0, 1)) == doctest::Approx(0.0));
    CHECK(cosineDistance(Vector2D(10, 0), Vector2D(0, 10)) == doctest::Approx(0.0));
    CHECK(cosineDistance(Vector2D(1, 1), Vector2D(1, 1)) == doctest::Approx(1.0));
    CHECK(cosineDistance(Vector2D(3, 5), Vector2D(2, -1)) == doctest::Approx(1.0 / (std::sqrt(34) * std::sqrt(5))));
}