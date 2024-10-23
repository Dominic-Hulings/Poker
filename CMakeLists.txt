cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

project(poker VERSION 1.0)

add_executable(poker.o ${SRC_FILES})
target_link_libraries(poker.o PUBLIC gtk-4.0 pangocairo-1.0 pango-1.0 harfbuzz gdk_pixbuf-2.0 cairo-gobject cairo vulkan graphene-1.0 gio-2.0 gobject-2.0 glib-2.0)
target_compile_options(poker.o PUBLIC -I/usr/include/gtk-4.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/sysprof-6 -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/x86_64-linux-gnu -I/usr/include/webp -I/usr/include/graphene-1.0 -I/usr/lib/x86_64-linux-gnu/graphene-1.0/include)