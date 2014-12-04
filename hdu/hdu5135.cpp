#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[12];
// 用Python 打了一个C(12, 3)的表
int table[220][3] = {{0, 1, 2}, {0, 1, 3}, {0, 1, 4}, {0, 1, 5}, {0, 1, 6}, {0, 1, 7}, {0, 1, 8}, {0, 1, 9}, {0, 1, 10}, {0, 1, 11}, {0, 2, 3}, {0, 2, 4}, {0, 2, 5}, {0, 2, 6}, {0, 2, 7}, {0, 2, 8}, {0, 2, 9}, {0, 2, 10}, {0, 2, 11}, {0, 3, 4}, {0, 3, 5}, {0, 3, 6}, {0, 3, 7}, {0, 3, 8}, {0, 3, 9}, {0, 3, 10}, {0, 3, 11}, {0, 4, 5}, {0, 4, 6}, {0, 4, 7}, {0, 4, 8}, {0, 4, 9}, {0, 4, 10}, {0, 4, 11}, {0, 5, 6}, {0, 5, 7}, {0, 5, 8}, {0, 5, 9}, {0, 5, 10}, {0, 5, 11}, {0, 6, 7}, {0, 6, 8}, {0, 6, 9}, {0, 6, 10}, {0, 6, 11}, {0, 7, 8}, {0, 7, 9}, {0, 7, 10}, {0, 7, 11}, {0, 8, 9}, {0, 8, 10}, {0, 8, 11}, {0, 9, 10}, {0, 9, 11}, {0, 10, 11}, {1, 2, 3}, {1, 2, 4}, {1, 2, 5}, {1, 2, 6}, {1, 2, 7}, {1, 2, 8}, {1, 2, 9}, {1, 2, 10}, {1, 2, 11}, {1, 3, 4}, {1, 3, 5}, {1, 3, 6}, {1, 3, 7}, {1, 3, 8}, {1, 3, 9}, {1, 3, 10}, {1, 3, 11}, {1, 4, 5}, {1, 4, 6}, {1, 4, 7}, {1, 4, 8}, {1, 4, 9}, {1, 4, 10}, {1, 4, 11}, {1, 5, 6}, {1, 5, 7}, {1, 5, 8}, {1, 5, 9}, {1, 5, 10}, {1, 5, 11}, {1, 6, 7}, {1, 6, 8}, {1, 6, 9}, {1, 6, 10}, {1, 6, 11}, {1, 7, 8}, {1, 7, 9}, {1, 7, 10}, {1, 7, 11}, {1, 8, 9}, {1, 8, 10}, {1, 8, 11}, {1, 9, 10}, {1, 9, 11}, {1, 10, 11}, {2, 3, 4}, {2, 3, 5}, {2, 3, 6}, {2, 3, 7}, {2, 3, 8}, {2, 3, 9}, {2, 3, 10}, {2, 3, 11}, {2, 4, 5}, {2, 4, 6}, {2, 4, 7}, {2, 4, 8}, {2, 4, 9}, {2, 4, 10}, {2, 4, 11}, {2, 5, 6}, {2, 5, 7}, {2, 5, 8}, {2, 5, 9}, {2, 5, 10}, {2, 5, 11}, {2, 6, 7}, {2, 6, 8}, {2, 6, 9}, {2, 6, 10}, {2, 6, 11}, {2, 7, 8}, {2, 7, 9}, {2, 7, 10}, {2, 7, 11}, {2, 8, 9}, {2, 8, 10}, {2, 8, 11}, {2, 9, 10}, {2, 9, 11}, {2, 10, 11}, {3, 4, 5}, {3, 4, 6}, {3, 4, 7}, {3, 4, 8}, {3, 4, 9}, {3, 4, 10}, {3, 4, 11}, {3, 5, 6}, {3, 5, 7}, {3, 5, 8}, {3, 5, 9}, {3, 5, 10}, {3, 5, 11}, {3, 6, 7}, {3, 6, 8}, {3, 6, 9}, {3, 6, 10}, {3, 6, 11}, {3, 7, 8}, {3, 7, 9}, {3, 7, 10}, {3, 7, 11}, {3, 8, 9}, {3, 8, 10}, {3, 8, 11}, {3, 9, 10}, {3, 9, 11}, {3, 10, 11}, {4, 5, 6}, {4, 5, 7}, {4, 5, 8}, {4, 5, 9}, {4, 5, 10}, {4, 5, 11}, {4, 6, 7}, {4, 6, 8}, {4, 6, 9}, {4, 6, 10}, {4, 6, 11}, {4, 7, 8}, {4, 7, 9}, {4, 7, 10}, {4, 7, 11}, {4, 8, 9}, {4, 8, 10}, {4, 8, 11}, {4, 9, 10}, {4, 9, 11}, {4, 10, 11}, {5, 6, 7}, {5, 6, 8}, {5, 6, 9}, {5, 6, 10}, {5, 6, 11}, {5, 7, 8}, {5, 7, 9}, {5, 7, 10}, {5, 7, 11}, {5, 8, 9}, {5, 8, 10}, {5, 8, 11}, {5, 9, 10}, {5, 9, 11}, {5, 10, 11}, {6, 7, 8}, {6, 7, 9}, {6, 7, 10}, {6, 7, 11}, {6, 8, 9}, {6, 8, 10}, {6, 8, 11}, {6, 9, 10}, {6, 9, 11}, {6, 10, 11}, {7, 8, 9}, {7, 8, 10}, {7, 8, 11}, {7, 9, 10}, {7, 9, 11}, {7, 10, 11}, {8, 9, 10}, {8, 9, 11}, {8, 10, 11}, {9, 10, 11} };

struct Area {
  int x, y, z;
  double area;
  Area(int x, int y, int z):x(x), y(y), z(z) {
    double p = (a[x] + a[y] + a[z])/2.0;
    //cout << p << endl;
    area = sqrt(p*(p-a[x])*(p-a[y])*(p-a[z]));
    //cout << area << endl;
  }
  bool operator<(const Area &aa) const {
    return area < aa.area;
  }
};

bool v[20];

int main(void) {
  int n, x, y, z;
  while(scanf("%d", &n) && n) {
    for(int i = 0; i < n; ++i)
      scanf("%d", a+i);
    sort(a, a+n);
    priority_queue<Area> as;
    for(int i = 0; i < 220; ++i) {
      x = table[i][0];
      y = table[i][1];
      z = table[i][2];
      if(a[x] + a[y] > a[z] && a[z]) {
        //cout << a[x] << " " << a[y] << " " << a[z] << endl;
        as.push(Area(x, y, z));
        //cout << Area(x, y, z).area << endl;
      }
    }
    memset(v, 0, sizeof(v));
    double ans = 0;
    while(!as.empty()) {
      Area aa = as.top(); as.pop();
      if(!v[aa.x] && !v[aa.y] && !v[aa.z]) {
        ans += aa.area;
        v[aa.x] = v[aa.y] = v[aa.z] = true;
      }
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
