// test_products.cpp
#include "catch_amalgamated.hpp"
#include "bread.h"
#include "mineral_water.h"
#include "notebook.h"
#include "pen.h"

TEST_CASE("Bread is instance of FoodProduct", "[Bread]") {
    Bread bread;
    FoodProduct *foodProduct = dynamic_cast<FoodProduct *>(&bread);
    REQUIRE(foodProduct != nullptr);
}

TEST_CASE("MineralWater is instance of FoodProduct", "[MineralWater]") {
    MineralWater water;
    FoodProduct *foodProduct = dynamic_cast<FoodProduct *>(&water);
    REQUIRE(foodProduct != nullptr);
}

TEST_CASE("Notebook is instance of PaperProduct", "[Notebook]") {
    Notebook notebook;
    PaperProduct *paperProduct = dynamic_cast<PaperProduct *>(&notebook);
    REQUIRE(paperProduct != nullptr);
}

TEST_CASE("Pen is instance of PaperProduct", "[Pen]") {
    Pen pen;
    PaperProduct *paperProduct = dynamic_cast<PaperProduct *>(&pen);
    REQUIRE(paperProduct != nullptr);
}

TEST_CASE("Bread inheritance and methods", "[Bread]") {
    Bread bread;
    REQUIRE(bread.getProductType() == "FoodProduct");
    REQUIRE(bread.getName() == "Bread");
}

TEST_CASE("MineralWater inheritance and methods", "[MineralWater]") {
    MineralWater water;
    REQUIRE(water.getProductType() == "FoodProduct");
    REQUIRE(water.getName() == "MineralWater");
}

TEST_CASE("Notebook inheritance and methods", "[Notebook]") {
    Notebook notebook;
    REQUIRE(notebook.getProductType() == "PaperProduct");
    REQUIRE(notebook.getName() == "Notebook");
}

TEST_CASE("Pen inheritance and methods", "[Pen]") {
    Pen pen;
    REQUIRE(pen.getProductType() == "PaperProduct");
    REQUIRE(pen.getName() == "Pen");
}