tests-cplusplus
===============

Tests about things directly related with c/c++

* *Memory Alignment Test*
   
   This a a test to check the memory alignment and to see
   how the size changes.
   With this example and a 64 bits config, the difference sorting
   the params is 16 bytes. 
   It's important to keep the attributes sorted as a good practice
   because some times (for example, using particles systems) we can
   save a lot of memory.
   Keep in mind that pointers change its size depending on the platform
