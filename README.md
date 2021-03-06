# My set of Algorithm Tools


> I am currently solving problems from: **[Competitve Programming 3](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=604)**

## Suggestions
- [ ] Convert functions **cmp(something, something)** to **lambda functions**
- [ ] Write tests for each Tool
- [ ] Convert Tools to another programming languagues, such as: Javascript, Java, etc...

## Need some help
> I would really appreciate if someone can help me fix some bugs. Many thanks!

- [ ] Solution topcoder/SRM177_Div1_Warehouse.cpp is wrong at one test case. Maybe because double error. My weakness!!!
- [ ] Why is solution 10138_uva.cpp.cpp wrong ??? Maybe I misunderstood problem statement ?!
- [ ] Solution 10158_uva.cpp keeps getting Segmentation fault (Core dumped) when compiling and running with g++ in ubuntu. I don't know why!!!

## Template
```cpp
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif


#ifndef ONLINE_JUDGE
  printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
}
```

## Test and submit source code
- Install xdotool ```sudo apt-get install xdotool```
- Install uva-node ```sudo npm install -g uva-node```
- If your source file is ABC.cpp, then create test files as ABC.i0 and ABC.o0, ABC.i1 and ABC.o1, etc...
- Run ```./ac.sh <program nam> <number test>```. E.g: ```./ac.sh ABC 1```
- 

## Some tips for testing machines in ACM-ICPC
- Submit problems for **Accepted**, **Wrong Answer**, **Time Limit Exceeded** answers.
- Check memory limit by e.g **creating an array of 10^8 elements**
- Check time for running program with complexity **10^8**, **3 * 10^8**, **5 * 10^8**
- Check recursion limit by make recursion program of **10^6** steps
- Check if ACM server check **Wrong Presentation** in output
- Check which editor is available. Usually there are DevCpp, Eclipse, CodeBlock.
- Check limit of file size of source code. Just in case, we can cheat some problems by storing precalculated answer.
- Try to submit as fast as you can and as many as you can, to see how stable is server.
- Try the **above template**

## Your test cases should include
- Sample test cases
- 2 or more test cases in single run, for ACM-ICPC
- Very small input
- Very large input
- Boundary test cases
- Unformatted input, more whitespaces (spaces, tabs)

## Tips for teamwork in ACM-ICPC
- Right after submitting, **print the source code**. Just in case solution is not AC, you can debug your code in printout and leave computer for your teammate to solve another problem. Moreover, print process is quite slow.
- If computer is being used by another teammate, **think and code your solution on blank paper**.
- **Prepare test cases** when your teammate is coding solution.

## Bit Manipulation
```cpp
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

void printSet(int vS) {                         // in binary representation
  printf("S = %2d = ", vS);
  stack<int> st;
  while (vS)
    st.push(vS % 2), vS /= 2;
  while (!st.empty())                         // to reverse the print order
    printf("%d", st.top()), st.pop();
  printf("\n");
}
```

## Geometry 2D
```cpp
double cross(double p[], double p1[], double p2[]) {
    double v1[2], v2[2];
    for (int i = 0; i < 2; ++i) {   
        v1[i] = p1[i] - p[i];
        v2[i] = p2[i] - p[i];
    }
    return v1[0] * v2[1] - v1[1] * v2[0];
}
double areaSimplePolygon(double a[][2], int N) {    
    double res = 0;
    for (int i = 1; i < N - 1; ++i) {
        res += cross(a[0], a[i], a[i + 1]);
    }   
    return abs(res) / 2;
}
double dist(double p1[], double p2[]) {
    double ret = 0;
    for (int i = 0; i < 2; ++i) ret += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    return sqrt(ret);
}

bool cmpConvex(pdd p1, pdd p2) {
    double t1[2], t2[2];
    t1[0] = p1.first;
    t1[1] = p1.second;
    
    t2[0] = p2.first;
    t2[1] = p2.second;
    
    if (fabs(cross(a[0], t1, t2)) <= EPS) return dist(a[0], t1) < dist(a[0], t2);
    return cross(a[0], t1, t2) > 0;
}
int convex(double b[][2], int N) {    
    int p = 0;
    for (int i = 1; i < N; ++i) {
        if (b[i][1] < b[p][1] || (b[i][1] == b[p][1] && b[i][0] < b[p][0])) {
            p = i;
        }
    }
    swap(b[0][0], b[p][0]);
    swap(b[0][1], b[p][1]);
    auto aa = (pdd*)b;
    sort(aa + 1, aa + N, cmpConvex);
    b[N][0] = b[0][0];
    b[N][1] = b[0][1];
    ++N;
    int M = 2;
    for (int i = 2; i < N; ++i) {
        bool ok = true;
        while (M >= 2 && cross(b[M - 2], b[M - 1], b[i]) <= 0) {
            if (fabs(cross(b[M - 2], b[M - 1], b[i])) <= EPS) {
                ok = false;
                if (dist(b[M - 2], b[M - 1]) < dist(b[M - 2], b[i])) {
                    b[M - 1][0] = b[i][0];
                    b[M - 1][1] = b[i][1];
                }
                break;
            }
            --M;
        }
        if (ok) {
            b[M][0] = b[i][0];
            b[M][1] = b[i][1];
            ++M;
        }
    }
    return M;
}
void toLine1(double p[], double v[], double c[]) {
    // ax + by + c = 0
    c[0] = v[0];
    c[1] = v[1];
    c[2] = -c[0] * p[0] - c[1] * p[1];  
}
void toLine(double p1[], double p2[], double c[]) {
    // ax + by + c = 0
    double v[2];
    for (int i = 0; i < 2; ++i) v[i] = p2[i] - p1[i];    
    c[0] = -v[1];
    c[1] = v[0];
    c[2] = -c[0] * p1[0] - c[1] * p1[1];
}
void intersection2Lines(double c1[], double c2[], double p[]) {
    double det = c1[0] * c2[1] - c2[0] * c1[1];
    if (fabs(det) <= EPS) {
        p[0] = p[1] = +foo;
        return;
    }
    double dx = c1[1] * c2[2] - c2[1] * c1[2];
    double dy = c1[2] * c2[0] - c2[2] * c1[0];
    p[0] = dx / det;
    p[1] = dy / det;
}
double distPointToLine(double p[], double p1[], double p2[]) {
    double ret = abs(cross(p, p1, p2));
    return ret / dist(p1, p2);
}
double distPointToSegment(double p[], double p1[], double p2[]) {
    if (dot(p, p1, p2) > 0) return dist(p, p1);
    if (dot(p, p2, p1) > 0) return dist(p, p2);
    double ret = abs(cross(p, p1, p2) / 2);
    ret /= dist(p1, p2);
    return ret;
}
bool isPointInSegment(double p[], double p1[], double p2[]) {
    return p[0] >= min(p1[0], p2[0]) && p[0] <= max(p1[0], p2[0]) && p[1] >= min(p1[1], p2[1]) && p[1] <= max(p1[1], p2[1]);
}
bool isIntersect2Segments(double a1[], double b1[], double a2[], double b2[]) {
    double c1[3], c2[3];        
    toLine(a1, b1, c1);
    toLine(a2, b2, c2);
    
    double det = c1[0] * c2[1] - c2[0] * c1[1];
    if (fabs(det) <= EPS) return false;
    double dx = c1[1] * c2[2] - c2[1] * c1[2];
    double dy = c1[2] * c2[0] - c2[2] * c1[0];
    double p[2];
    p[0] = dx / det;
    p[1] = dy / det;
    return isPointInSegment(p, a1, b1) && isPointInSegment(p, a2, b2);
}
bool isIntersect2Lines(double c1[], double c2[]) {    
    double det = c1[0] * c2[1] - c2[0] * c1[1];
    return !(fabs(det) <= EPS);        
}
void reflectPointThroughLine(double line[], double p[], double q[]) {
    double temp[3];
    temp[0] = line[1];
    temp[1] = -line[0];
    temp[2] = -temp[0] * p[0] - temp[1] * p[1];
    
    double d = line[0] * temp[1] - temp[0] * line[1];
    double dx = line[1] * temp[2] - temp[1] * line[2];
    double dy = line[2] * temp[0] - temp[2] * line[0];
    dx /= d;
    dy /= d;
    q[0] = 2 * dx - p[0];
    q[1] = 2 * dy - p[1];
}
bool isSameLine(double l1[], double l2[]) {
    double d = l1[0] * l2[1] - l2[0] * l1[1];
    if (fabs(d) <= EPS) {
        if (fabs(l1[2] * l2[1] - l1[1] * l2[2]) <= EPS) {
            return true;
        }
    }
    return false;
}
```

## Geometry 3D
```cpp
void sphereToXYZ(double p[], double radius, double q[]) {
    p[0] = p[0] / 180 * PI;
    p[1] = p[1] / 180 * PI;
    q[0] = dist * cos(p[0]) * cos(p[1]);
    q[1] = dist * cos(p[0]) * sin(p[1]);
    q[2] = dist * sin(p[0]);
}
double cross3D(double a[], double b[], double c[]) {
    double p1[3], p2[3];
    for (int i = 0; i < 3; ++i) {
        p1[i] = b[i] - a[i];
        p2[i] = c[i] - a[i];
    }
    double v[3];
    v[0] = p1[1] * p2[2] - p2[1] * p1[2];
    v[1] = p1[2] * p2[0] - p2[2] * p1[0];
    v[2] = p1[0] * p2[1] - p2[0] * p1[1];
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
double dot3D(double p1[], double p2[], double p3[]) {
    double v1[3], v2[3];
    for (int i = 0; i < 3; ++i) {
        v1[i] = p2[i] - p1[i];
        v2[i] = p3[i] - p2[i];
    }
    double ret = 0;
    for (int i = 0; i < 3; ++i) ret += v1[i] * v2[i];
    return ret;
}
double dist3D(double p1[], double p2[]) {
    double v[3];
    for (int i = 0; i < 3; ++i) v[i] = p2[i] - p1[i];
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
double distCurve3D(double p1[], double p2[], int radius) {
    double dot = 0;
    for (int i = 0; i < 3; ++i) dot += p1[i] * p2[i];
    double angle = acos(dot / dist3D(p1) / dist3D(p2));
    return angle * radius;      
}
double distPointToLine3D(double p[], double p1[], double p2[]) {
    return cross3D(p, p1, p2) / dist3D(p1, p2);
}
```