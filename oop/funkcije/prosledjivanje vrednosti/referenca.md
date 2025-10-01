```cpp
// pozivamo funkciju
polar(x, y, r, fi);
```

 ```cpp
// deklaracija i definicija funkcije
void polar(double x, double y, double& r, double& fi) {
	r  = sqrt(x*x + y*y);
	fi = (x==0 && y==0) ? 0 : atan2(y, x);
}
```
