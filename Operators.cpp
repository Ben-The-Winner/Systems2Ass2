#include <iostream>
using namespace std;
#include "Graph.hpp"
#include "operators.hpp"




Graph operator+(const Graph& g1, const Graph& g2)
{
    if(g1.adjMatrix.size() != g2.adjMatrix.size() || g1.adjMatrix[0].size() != g2.adjMatrix[0].size() || g1.adjMatrix.size() != g1.adjMatrix[0].size())
    {
        throw invalid_argument("can't multiply");; 
    }

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j] += g2.adjMatrix[i][j];
        }
    }

    return result;
}

Graph operator+(const Graph& g1, int a)
{

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j] += a;
        }
    }

    return result;
}


Graph operator+(const Graph& g1)
{

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j] = +result.adjMatrix[i][j];
        }
    }

    return result;
}


Graph operator-(const Graph& g1, const Graph& g2)
{
    if(g1.adjMatrix.size() != g2.adjMatrix.size() || g1.adjMatrix[0].size() != g2.adjMatrix[0].size() || g1.adjMatrix.size() != g1.adjMatrix[0].size())
    {
        cout << "the matrices aren't the same size or not squares, can't proceed" << endl;
        return g1; 
    }

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j] -= g2.adjMatrix[i][j];
        }
    }

    return result;
}



Graph operator-(const Graph& g1, int a)
{

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j] -= a;
        }
    }

    return result;
}



Graph operator-(const Graph& g1)
{

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j] = -result.adjMatrix[i][j];
        }
    }

    return result;
}


bool operator==(const Graph& g1, const Graph& g2)
{
    if(g1.adjMatrix.size() != g2.adjMatrix.size() || g1.adjMatrix[0].size() != g2.adjMatrix[0].size() || g1.adjMatrix.size() != g1.adjMatrix[0].size())
    {
        cout << "the matrices aren't the same size or not squares, can't proceed" << endl;
        return false; 
    }

    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            if(g1.adjMatrix[i][j] != g2.adjMatrix[i][j])//this will check if they have the same edges too
                    return false;
        }
    }

    return true;
}



bool operator>(const Graph& g2, const Graph& g1)
{
    bool flag = true;
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            if(g1.adjMatrix[i][j] != g2.adjMatrix[i][j])//this will check if they have the same edges too
                    flag = false;
        }
    }

    if(flag == true && g2.adjMatrix.size() > g1.adjMatrix.size())
        return true;

    else
    {
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < g1.adjMatrix.size(); i++)
        {
            for(int j = 0; j < g1.adjMatrix.size(); j++)
            {
                if(g1.adjMatrix[i][j] != 0)
                    count1++;
            }
        }

        for(int i = 0; i < g2.adjMatrix.size(); i++)
        {
            for(int j = 0; j < g2.adjMatrix.size(); j++)
            {
                if(g2.adjMatrix[i][j] != 0)
                    count2++;
            }
        }

        if(count2 > count1)
            return true;
        else if(count2 == count1)
        {
            if(g2.adjMatrix.size() > g1.adjMatrix.size())
                return true;
        }

        return false;

    }
}



bool operator<(const Graph& g2, const Graph& g1)
{
    bool flag = true;
    for(int i = 0; i < g2.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g2.adjMatrix.size(); j++)
        {
            if(g2.adjMatrix[i][j] != g1.adjMatrix[i][j])//this will check if they have the same edges too
                    flag = false;
        }
    }

    if(flag == true && g1.adjMatrix.size() > g2.adjMatrix.size())
        return true;

    else
    {
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < g1.adjMatrix.size(); i++)
        {
            for(int j = 0; j < g1.adjMatrix.size(); j++)
            {
                if(g1.adjMatrix[i][j] != 0)
                    count1++;
            }
        }

        for(int i = 0; i < g2.adjMatrix.size(); i++)
        {
            for(int j = 0; j < g2.adjMatrix.size(); j++)
            {
                if(g2.adjMatrix[i][j] != 0)
                    count2++;
            }
        }

        if(count2 < count1)
            return true;
        else if(count2 == count1)
        {
            if(g2.adjMatrix.size() < g1.adjMatrix.size())
                return true;
        }

        return false;

    }
}


bool operator>=(const Graph& g2, const Graph& g1)
{
    if(g2 > g1 or g2 == g1)
        return true;
    return false;
}


bool operator<=(const Graph& g2, const Graph& g1)
{
    if(g2 < g1 or g2 == g1)
        return true;
    return false;
}

bool operator!=(const Graph& g1, const Graph& g2)
{
    if(g1.adjMatrix.size() != g2.adjMatrix.size() || g1.adjMatrix[0].size() != g2.adjMatrix[0].size())
    {
        return true; 
    }

    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            if(g1.adjMatrix[i][j] != g2.adjMatrix[i][j])//this will check if they have the same edges too
                    return true;
        }
    }

    return false;
}



Graph operator++(const Graph& g1)
{

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j]++;
        }
    }

    return result;
}

Graph operator++(const Graph& g1, int)
{

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            ++result.adjMatrix[i][j];
        }
    }

    return result;
}


Graph operator*(const Graph& g1, int a)
{

    Graph result(g1); 
    for(int i = 0; i < g1.adjMatrix.size(); i++)
    {
        for(int j = 0; j < g1.adjMatrix.size(); j++)
        {
            result.adjMatrix[i][j] *= a;
        }
    }

    return result;
}


Graph operator*(const Graph& g1, const Graph& g2) 
{
    if (g1.adjMatrix.size() != g2.adjMatrix.size()) {
        throw invalid_argument("can't multiply");
    }

    int rows1 = g1.adjMatrix.size();
    int cols1 = g1.adjMatrix[0].size();
    int cols2 = g2.adjMatrix[0].size();

    Graph result(g1); 

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result.adjMatrix[i][j] += g1.adjMatrix[i][k] * g2.adjMatrix[k][j];
            }
        }
    }

    return result;
}


Graph print(const Graph& g)
{
  int countE = 0;
  
  for(int i = 0; i < g.adjMatrix.size(); i++) 
  {
    for(int j = 0; j < g.adjMatrix.size(); j++) 
    {
      if(g.adjMatrix[i][j] != 0)
        countE++;
    }
  }

  cout << "the number of vertices is " << g.adjMatrix.size() << endl;
  cout << "the number of edges is " << countE << endl;

}
