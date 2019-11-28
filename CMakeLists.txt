cmake_minimum_required(VERSION 3.13.4)
project(OrgaCompu_TP2)

set(CMAKE_CXX_STANDARD 14)

add_executable(OrgaCompu_TP2
        tests/prueba1.mem
        tests/prueba2.mem
        tests/prueba3.mem
        tests/prueba3b.mem
        tests/prueba4.mem
        tests/prueba5.mem
        main.c command.c command.h cache.c cache.h set.c set.h way.c way.h fileReader.c fileReader.h commandParser.c commandParser.h commandExecutor.c commandExecutor.h addressHelper.c addressHelper.h mainMemory.c mainMemory.h)
