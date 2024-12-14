CXX = g++
CXXFLAGS = -Wall --std=c++17

comp_all: product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp  catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS)  product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp  catch_amalgamated.cpp -o main


comp_products: product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_products.cpp product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp catch_amalgamated.cpp -o test_products.o

test_products: comp_products
	./test_products.o

comp_test_shop: test_shop.cpp product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_shop.cpp product.cpp food_product.cpp paper_product.cpp bread.cpp mineral_water.cpp pen.cpp notebook.cpp shop.cpp supplier.cpp catch_amalgamated.cpp -o test_shop.o

test_shop: comp_test_shop
	./test_shop.o

clean:
	rm -f main *.o