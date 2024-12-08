CXX = g++
CXXFLAGS = -Wall --std=c++17

comp_all: product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp  catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS)  product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp  catch_amalgamated.cpp -o main

comp_test_shop: test_shop.cpp product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_shop.cpp product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp catch_amalgamated.cpp -o test_shop.o

test_shop: comp_test_shop
	./test_shop.o

clean:
	rm -f main *.o