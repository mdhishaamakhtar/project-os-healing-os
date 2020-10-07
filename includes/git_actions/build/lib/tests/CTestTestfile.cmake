# CMake generated Testfile for 
# Source directory: /home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests
# Build directory: /home/vaishnav/Documents/OS project/cppgit2/build/lib/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(offline "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-xonline")
set_tests_properties(offline PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;63;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
add_test(invasive "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-score::ftruncate" "-sfilter::stream::bigfile" "-sodb::largefiles" "-siterator::workdir::filesystem_gunk" "-srepo::init" "-srepo::init::at_filesystem_root")
set_tests_properties(invasive PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;64;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
add_test(online "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-sonline")
set_tests_properties(online PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;65;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
add_test(gitdaemon "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-sonline::push")
set_tests_properties(gitdaemon PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;66;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
add_test(ssh "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-sonline::push" "-sonline::clone::ssh_cert" "-sonline::clone::ssh_with_paths" "-sonline::clone::path_whitespace_ssh")
set_tests_properties(ssh PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;67;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
add_test(proxy "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-sonline::clone::proxy")
set_tests_properties(proxy PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;68;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
add_test(auth_clone "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-sonline::clone::cred")
set_tests_properties(auth_clone PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;69;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
add_test(auth_clone_and_push "/home/vaishnav/Documents/OS project/cppgit2/build/lib/libgit2_clar" "-v" "-sonline::clone::push" "-sonline::push")
set_tests_properties(auth_clone_and_push PROPERTIES  _BACKTRACE_TRIPLES "/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;59;ADD_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;70;ADD_CLAR_TEST;/home/vaishnav/Documents/OS project/cppgit2/ext/libgit2/tests/CMakeLists.txt;0;")
