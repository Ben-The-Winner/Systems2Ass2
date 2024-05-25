#include <iostream>
using namespace std;
#include "Graph.hpp"




Graph operator+(const Graph& , const Graph& );

Graph operator+(const Graph& , int);

Graph operator+(const Graph& );

Graph operator-(const Graph& , const Graph& );

Graph operator-(const Graph& , int );

Graph operator-(const Graph& );

bool operator==(const Graph& , const Graph& );

bool operator>(const Graph& , const Graph& );

bool operator<(const Graph& , const Graph& );

bool operator>=(const Graph& , const Graph& );

bool operator<=(const Graph& , const Graph& );

bool operator!=(const Graph& , const Graph& );

Graph operator++(const Graph& );

Graph operator++(const Graph& , int);

Graph operator*(const Graph& , int );

Graph operator*(const Graph& , const Graph& ) ;

Graph print(const Graph& );
