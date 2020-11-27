BUILD_DIR=cmake-build

# build .elf
cmake -H. -B${BUILD_DIR}
cd ${BUILD_DIR} && make -j 12 && cd ..

openocd \
  -c "tcl_port disabled" \
  -c "gdb_port 3333" \
  -c "telnet_port 4444" \
  -f scripts/stm32f4discovery.cfg \
  -c "program \"${BUILD_DIR}/stm32f4/tensor-example-embedded.elf\"" \
  -c reset \
  -c shutdown
