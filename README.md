Bit Manipulation

Check if ith bit is on
```cpp

for(int i = 0; i < 32; i++) {
    if(x & (1 << i)) {
        // True if ith bit of x is set
    }
}

```