#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "grid.h"
using namespace std;

bool isRouteWellFormed (string route);
int navigateSegment (int r, int c, char dir, int maxSteps);
int navigateRoute (int sr, int sc, int er, int ec, string route, int& nsteps);

int main()
{
  setSize(3,4);      // make a 3 by 4 grid
  setWall(1,4);      // put a wall at (1,4)
  setWall(2,2);      // put a wall at (2,2)
  if (!isWall(3,2))  // if there's no wall at (3,2)  [there isn't]
    setWall(3,2);  //    put a wall at (3,2)
  draw(3,1, 3,4);  // draw the grid, showing an S at (3,1)
                       //    start position, and an E at (3,4)
  assert(isRouteWellFormed(""));
  assert(isRouteWellFormed("n"));
  assert(!isRouteWellFormed("2"));
  assert(isRouteWellFormed("n0"));
  assert(isRouteWellFormed("n22"));
  assert(!isRouteWellFormed("n222"));
  assert(!isRouteWellFormed("e1x"));
    
  cout << "isRouteWellFormed Test PASSED!" << endl;
    
  assert(navigateSegment(3, 1, 'n', 3) == 2);
    cout << navigateSegment(3, 1, 'n', 3) << endl;
  assert(navigateSegment(0, 1, 'n', 3));
    cout << navigateSegment(0, 1, 'n', 3) << endl;
  assert(navigateSegment(0, 1, 'x', 3));
    cout << navigateSegment(0, 1, 'x', 3) << endl;
  assert(navigateSegment(0, 1, 'n', -1));
    cout << navigateSegment(0, 1, 'n', -1) << endl;
  assert(navigateSegment(1, 5, 'n', 3));
    cout << navigateSegment(1, 5, 'n', 3) << endl;
  assert(navigateSegment(1, 1, 'N', 3) == 0);
    cout << navigateSegment(1, 1, 'N', 3) << endl;
  assert(navigateSegment(1, 1, 'S', 3) == 2);
    cout << navigateSegment(1, 1, 'S', 3) << endl;
  assert(navigateSegment(1, 1, 'E', 3) == 2);
    cout << navigateSegment(1, 1, 'E', 3) << endl;
  assert(navigateSegment(1, 1, 'W', 3) == 0);
    cout << navigateSegment(1, 1, 'W', 3) << endl;
    
  cout << endl;
    
  int len;
  len = -999;  // so we can detect whether navigateRoute sets len
  assert(navigateRoute(3,1, 3,4, "N2eE01n0s2e1", len) == 0  &&  len == 7);
  len = -999;  // so we can detect whether navigateRoute sets len
  assert(navigateRoute(3,1, 3,4, "e1x", len) == 2  &&  len == -999);
  len = -999;  // so we can detect whether navigateRoute sets len
  assert(navigateRoute(2,4, 1,1, "w3n1", len) == 3  &&  len == 1);
  len = -999;  // so we can detect whether navigateRoute sets len
  assert(navigateRoute(1,3, 3,4, "sse", len) == 0  &&  len == 3);
    
  cout << "All tests succeeded" << endl;
    
}

bool isRouteWellFormed (string route) {
  size_t k = 0;
  while (k != route.size())
  {
    char dir = tolower(route[k]);
    if(dir != 'n' && dir != 'e' && dir != 'w' && dir !='s')
      return false;
    
    k++;
    if(k != route.size() && isdigit(route[k])) {
      k++;
      if(k != route.size() && isdigit(route[k]))
        k++;
    }
  }
  return true;
}

int navigateSegment (int r, int c, char dir, int maxSteps)
{
  return 0;
}


int navigateRoute (int sr, int sc, int er, int ec, string route, int& nsteps)
{
  return 0;
}


