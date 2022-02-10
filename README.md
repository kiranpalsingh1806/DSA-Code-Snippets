Bit Manipulation
### Check if ith bit is on
```cpp
for(int i = 0; i < 32; i++) {
    if(x & (1 << i)) {
        // True if ith bit of x is set
    }
}
```
### Moving in four directions in grid

```cpp
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

for (auto &dir : dirs) {
    int a = x + dir[0], b = y + dir[1];
    // Here x and y is our current location.
}
```

### Heading
```cpp
Code here
```