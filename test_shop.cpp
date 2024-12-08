// test_shop_supplier.cpp
#include "catch_amalgamated.hpp"
#include "shop.h"
#include "supplier.h"
#include "bread.h"
#include "mineral_water.h"
#include "notebook.h"
#include "pen.h"

TEST_CASE("Shop addToStore and checkAvailability methods", "[Shop]") {
    Shop shop;
    Bread bread;
    MineralWater water;
    shop.addToStore(&bread);
    shop.addToStore(&water);
    REQUIRE(shop.checkAvailability("Bread") == true);
    REQUIRE(shop.checkAvailability("MineralWater") == true);
    REQUIRE(shop.checkAvailability("Pen") == false);
}

TEST_CASE("Shop sellProduct method", "[Shop]") {
    Shop shop;
    Bread bread;
    shop.addToStore(&bread);
    shop.sellProduct("Bread");
    REQUIRE(shop.checkAvailability("Bread") == false);
    shop.sellProduct("Bread"); // Selling a product that is not available
    REQUIRE(shop.checkAvailability("Bread") == false);
}

TEST_CASE("Shop printProductsList method", "[Shop]") {
    Shop shop;
    Bread bread;
    MineralWater water;
    Notebook notebook;
    Pen pen;
    shop.addToStore(&bread);
    shop.addToStore(&water);
    shop.addToStore(&notebook);
    shop.addToStore(&pen);
    std::string productList = shop.printProductsList();
    REQUIRE(productList.find("Bread") != std::string::npos);
    REQUIRE(productList.find("MineralWater") != std::string::npos);
    REQUIRE(productList.find("Notebook") != std::string::npos);
    REQUIRE(productList.find("Pen") != std::string::npos);
}

TEST_CASE("Supplier deliverProduct method", "[Supplier]") {
    Shop shop;
    Supplier supplier(&shop);
    Notebook notebook;
    Pen pen;
    supplier.deliverProduct(&notebook);
    supplier.deliverProduct(&pen);
    REQUIRE(shop.checkAvailability("Notebook") == true);
    REQUIRE(shop.checkAvailability("Pen") == true);
}

TEST_CASE("Shop sellProduct and printProductsList methods", "[Shop]") {
    Shop shop;
    Bread bread;
    MineralWater water;
    shop.addToStore(&bread);
    shop.addToStore(&water);
    shop.sellProduct("Bread");
    std::string productList = shop.printProductsList();
    REQUIRE(productList.find("Bread") == std::string::npos);
    REQUIRE(productList.find("MineralWater") != std::string::npos);
}


TEST_CASE("Shop printProductsListByType method", "[Shop]") {
    Shop shop;
    Bread bread;
    MineralWater water;
    Notebook notebook;
    Pen pen;
    shop.addToStore(&bread);
    shop.addToStore(&water);
    shop.addToStore(&notebook);
    shop.addToStore(&pen);

    std::string foodProducts = shop.printProductsListByType("FoodProduct");
    REQUIRE(foodProducts.find("Bread") != std::string::npos);
    REQUIRE(foodProducts.find("MineralWater") != std::string::npos);
    REQUIRE(foodProducts.find("Notebook") == std::string::npos);
    REQUIRE(foodProducts.find("Pen") == std::string::npos);

    std::string paperProducts = shop.printProductsListByType("PaperProduct");
    REQUIRE(paperProducts.find("Notebook") != std::string::npos);
    REQUIRE(paperProducts.find("Pen") != std::string::npos);
    REQUIRE(paperProducts.find("Bread") == std::string::npos);
    REQUIRE(paperProducts.find("MineralWater") == std::string::npos);
}

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