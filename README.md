# UniformTest
Simple C++ code to test whether the numerator of the coarse flag Hilbert&ndash;Poincar&eacute; series at Y=1 satisfies an integrality condition.

This uses the [GMP Library](https://gmplib.org/). To compile on Linux, run the following.

```bash
$ g++ -o Uniform ./Uniform.cpp -lgmpxx -lgmp
```

The `compile_run.sh` is used to initialize a number of parallel screens running the integrality test on different intervals. It will edit `IntegralityTest.cpp` and compile a number of times. The file `IntegralityTest.cpp` will not compile as is.
