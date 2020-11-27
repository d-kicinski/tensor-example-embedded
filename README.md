# tensor-example-embedded

Repository contains example usage of the [tensor](https://www.github.com/d-kicinski/tensor) library
in application that targets embedded platform.

In this example, we target the stm32f4-discovery board but it could be easily adopted for any other
board. It essentially blinks green led if computation is performed correctly and red if program hits
hard-fault.

#### Project structure
```
tensor-example-embedded \
-- compute/     # library that uses `tensor` lib for matrix computations, exposes "C" interface
-- scripts/     # scripts for building project witout IDE
-- stm32f4/     # generated with stm32cubemx, depends on `compute` library
-- third-party/
---- tensor     # root of the tensor library repository
```
note: both `compute` and `tensor` are build with arm-none-eabi-g++ compiler and `stm32f4` is build with 
arm-none-eabi-gcc.

#### How to build and run
Project depends on bare-metal arm toolchain (arm-none-eabi) and openocd. Both dependencies are
available in ubuntu repositories:
```shell script
sudo apt install gcc-arm-none-eabi openocd
```

To build and run on device execute the following scripts
```shell script
./scripts/build.sh
```


