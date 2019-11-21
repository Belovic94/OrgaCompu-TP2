cmake_minimum_required(VERSION 3.15)
project(OrgaCompu_TP2)

set(CMAKE_CXX_STANDARD 14)

add_executable(OrgaCompu_TP2
        tests/prueba1.mem
        tests/prueba2.mem
        tests/prueba3.mem
        tests/prueba3b.mem
        tests/prueba4.mem
        tests/prueba5.mem
        main.c command.c command.h cache.c cache.h queue.c queue.h cache_block.c cache_block.h)
