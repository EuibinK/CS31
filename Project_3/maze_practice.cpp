#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "grid.h"
using namespace std;

bool isRouteWellFormed (string route);
int navigateSegment (int r, int c, char dir, int maxSteps);
int navigateRoute (int sr, int sc, int er, int ec, string route, int& nsteps);
bool getDeltas (char dir, int& dr, int& dc);

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
  assert(navigateSegment(0, 1, 'n', 3));
  assert(navigateSegment(0, 1, 'x', 3));
  assert(navigateSegment(0, 1, 'n', -1));
  assert(navigateSegment(1, 5, 'n', 3));
  assert(navigateSegment(1, 1, 'N', 3) == 0);
  assert(navigateSegment(1, 1, 'S', 3) == 2);
  assert(navigateSegment(1, 1, 'E', 3) == 2);
  assert(navigateSegment(1, 1, 'W', 3) == 0);
    
  cout << "navigateSegment Test PASSED!" << endl;
    
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
  int nr = getRows();
  int nc = getCols();
  if (r < 1 || r > nr || c < 1 || c > nc || isWall(r,c))
    return -1;

  if (maxSteps < 0)
    return -1;

  int dr;
  int dc;
  if(!getDeltas(dir, dr, dc))
    return -1;

  int ns;
  for (ns = 0; ns < maxSteps; ns++) {
    r += dr;
    c += dc;

    if (r < 1 || r > nr || c < 1 || c > nc || isWall(r,c))
      break;
  }
  return ns;
}


int navigateRoute (int sr, int sc, int er, int ec, string route, int& nsteps)
{
  return 0;
}

bool getDeltas (char dir, int& dr, int& dc) {
  switch (tolower(dir)) {
    case 'n': dr = -1; dc = 0; break;
    case 'e': dr = 0; dc = 1; break;
    case 'w': dr = 0; dc = -1; break;
    case 's': dr = 1; dc = 0; break;
    default:  return false;
  }
  return true;
}
