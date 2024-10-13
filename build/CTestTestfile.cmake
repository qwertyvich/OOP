# CMake generated Testfile for 
# Source directory: /home/user/oop/lab1
# Build directory: /home/user/oop/lab1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(PalindromeTests "/home/user/oop/lab1/build/run_tests")
set_tests_properties(PalindromeTests PROPERTIES  _BACKTRACE_TRIPLES "/home/user/oop/lab1/CMakeLists.txt;28;add_test;/home/user/oop/lab1/CMakeLists.txt;0;")
subdirs("googletest")
