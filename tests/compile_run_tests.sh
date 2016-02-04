echo Compiling and linking tests...
g++ -std=c++11 vector2_test.cpp -o tests -lboost_unit_test_framework
./tests
rm tests
