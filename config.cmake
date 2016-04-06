#FIND_PATH(V8_INCLUDE_DIR NAMES include/v8.h PATHS /usr/include /usr/local/include)
#include_directories(${V8_INCLUDE_DIR})

include_directories("/opt/v8" "/opt/v8/include")

HHVM_EXTENSION(v8js
	src/ext_v8js.cpp
	src/v8js.cpp
)
HHVM_SYSTEMLIB(v8js src/ext_v8js.php)

target_link_libraries(v8js
	"/opt/v8/out/x64.release/obj.target/tools/gyp/libv8_libplatform.a"
	"/opt/v8/out/x64.release/lib.target/libv8.so"
	"/usr/lib64/libicuuc.so"
	"/usr/lib64/libicui18n.so"
)
