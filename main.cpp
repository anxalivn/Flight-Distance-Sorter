#include <iostream>
#include "graph.h"
#include "city.h"
#include <stdexcept>
using namespace std;

int main()
{
   Graph<City> map(DIRECTED,WEIGHTED);

   City Fargo("Fargo");
   City Minneapolis("Minneapolis");
   City Chicago("Chicago");
   City Detroit("Detroit");
   City NewYork ("New York");
   City Miami("Miami");
   City StLouis("St. Louis");
   City Houston("Houston");
   City Denver("Denver");
   City Phoenix("Phoenix");
   City LosAngeles("Los Angeles");
   City Seattle("Seattle");
   City SanFrancisco("San Francisco");

   if (map.isEmpty()) // true if graph has no vertices
      cout << "graph is empty" << endl;
   else
      cout << "graph is not empty" << endl;

   try
   {
      map.insertVertex(Seattle);
      map.insertVertex(LosAngeles);
      map.insertVertex(Phoenix);
      map.insertVertex(Denver);
      map.insertVertex(Fargo);
      map.insertVertex(Minneapolis);
      map.insertVertex(Houston);
      map.insertVertex(StLouis);
      map.insertVertex(Chicago);
      map.insertVertex(Detroit);
      map.insertVertex(Miami);
      map.insertVertex(NewYork);
      map.insertVertex(SanFrancisco);
      map.insertVertex(Fargo); // exception - duplicate vertex
   }
   // logic_error catches all of below, pick what you want for possible errors
   //     logic_error
   //          domain_error
   //          invalid_argument
   //          length_error
   //          out_of_range
   catch (logic_error error)
   {
      cout << error.what() << endl;
   }

   if (map.isEmpty())
      cout << "graph is empty" << endl;
   else
      cout << "graph is not empty" << endl;

   if (map.isFull()) // out of vertices, depends on your implementation
      cout << "graph is full" << endl;
   else
      cout << "graph is not full" << endl;

   try
   {
      map.insertEdge(Fargo,Minneapolis,240);    // from,to,miles
      map.insertEdge(Minneapolis,Fargo,240);
      map.insertEdge(Minneapolis,Chicago,409);
      map.insertEdge(Minneapolis,Denver,920);
      map.insertEdge(Chicago,Minneapolis,409);
      map.insertEdge(Chicago,Detroit,286);
      map.insertEdge(Chicago,NewYork,821);
      map.insertEdge(Detroit,Chicago,286);
      map.insertEdge(Detroit,StLouis,547);
      map.insertEdge(Detroit,NewYork,640);
      map.insertEdge(NewYork,Miami,1281);
      map.insertEdge(NewYork,LosAngeles,2824);
      map.insertEdge(NewYork,Chicago,821);
      map.insertEdge(Miami,NewYork,1281);
      map.insertEdge(Miami,Houston,1190);
      map.insertEdge(StLouis,Detroit,547);
      map.insertEdge(StLouis,Denver,861);
      map.insertEdge(Houston,StLouis,780);
      map.insertEdge(Houston,Miami,1190);
      map.insertEdge(Houston,Phoenix,1186);
      map.insertEdge(Phoenix,Houston,1186);
      map.insertEdge(Phoenix,LosAngeles,381);
      map.insertEdge(LosAngeles,Phoenix,381);
      map.insertEdge(LosAngeles,NewYork,2824);
      map.insertEdge(LosAngeles,Denver,1023);
      map.insertEdge(LosAngeles,Seattle,1151);
      map.insertEdge(Seattle,SanFrancisco,807);
      map.insertEdge(SanFrancisco,Seattle,807);
      map.insertEdge(SanFrancisco,Denver,1249);
      map.insertEdge(Denver,Minneapolis,920);
      map.insertEdge(Denver,LosAngeles,1023);
      map.insertEdge(Seattle,Chicago,2072);
      map.insertEdge(Fargo,Denver,909);
      map.insertEdge(Seattle,Denver,1332);
      map.insertEdge(Seattle,Denver,1332);  // exception - duplicate edge
   }
   catch (logic_error error) // duplicate edge
   {
      cout << error.what() << endl;
   }

   cout << "vertex count = " << map.vertexCount() << endl;
   cout << "edge count = " << map.edgeCount() << endl;

   map.dump(); // dump out the graph in a readable form

   if (map.isAdjacentTo(SanFrancisco,Denver))  // from,to    should be true
      cout << map.edgeWeight(SanFrancisco,Denver) << " miles from "
           << SanFrancisco << " to " << Denver << endl;
   else
      cout << SanFrancisco << " is not adjacent to " << Denver << endl;
   if (map.isAdjacentTo(Denver,SanFrancisco)) // from,to     should be false
      cout << map.edgeWeight(Denver,SanFrancisco) << " miles from "
           << Denver << " to " << SanFrancisco << endl;
   else
      cout << Denver << " is not adjacent to " << SanFrancisco << endl;

   try
   {
      map.deleteEdge(SanFrancisco,Denver);   // from,to
      map.deleteEdge(SanFrancisco,Denver);   // exception - edge doesn't exist
   }
   catch (logic_error error)
   {
      cout << error.what() << endl;
   }
   if (map.isAdjacentTo(SanFrancisco,Denver))
      cout << map.edgeWeight(SanFrancisco,Denver) << " miles from "
           << SanFrancisco << " to " << Denver << endl;
   else
      cout << SanFrancisco << " is not adjacent to " << Denver << endl;

   // below deletes 2 edges: SF to Seattle and Seattle to SF
   try
   {
      map.deleteVertex(SanFrancisco); 
      map.deleteVertex(SanFrancisco);   // exception - vertex doesn't exist
   }
   catch (logic_error error)
   {
      cout << error.what() << endl;
   }

   cout << "vertex count = " << map.vertexCount() << endl;
   cout << "edge count = " << map.edgeCount() << endl;

   map.dump();    // dump out the graph in a readable form
   map.destroy();
   if (map.isEmpty()) 
      cout << "graph is empty" << endl;
   else
      cout << "graph is not empty" << endl;

   return 0;
}

