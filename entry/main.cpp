#include "airports.h"
#include "graph.h"
#include <iostream>

void tests() {
  // Testing Graph Constructor - Small File 
  Graph graph1("/tests/small.csv");
   vector<Airport*> airports = graph1.getAirports();
  // checks num of airports initialized.
  if (airports.size() != 10) std::cout << "FAIL";
  // checks all values of first airp../tests/small.csvort
  if (!(airports[0]->GetName() == "Goroka Airport" && 
      airports[0]->GetCity() == "Goroka" && 
      airports[0]->GetCountry() == "Papua New Guinea" && 
      airports[0]->GetLatitude() == -6.081689834590001 && 
      airports[0]->GetLongitude() == 145.391998291)) std::cout << "FAIL";
  
  // Graph Constructor - Big File
  Graph graph2("/tests/airports.csv");
  vector<Airport*> airports2 = graph2.getAirports();
  if(airports2.size() != 7698) std::cout << "FAIL";

  Graph graph3("/tests/faulty.csv");
  vector<Airport*> airports3 = graph3.getAirports();
  if (airports3.size() != 1)
    std::cout << "FAIL";
  //   // excluded airports with empty name, coordinates or out of range latitude/longitude 

  std::cout << "finished tests";

}

int main() {
  Graph graph("../tests/airports.csv");
 // tests();
  graph.PrintAllAirports();
}

