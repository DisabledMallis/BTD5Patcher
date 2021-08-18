if(MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT> #---------|
            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
            $<$<CONFIG:Release>:/MT> #--|
    )
endif()

link_directories("${CMAKE_CURRENT_LIST_DIR}/Lib/PolyHook_2_0/_install/lib/")

add_library(Patcher SHARED)

target_sources(Patcher PRIVATE 
    "main.cpp"
    "Utils.cpp"
)

add_subdirectory(Patches)
add_subdirectory(Classes)

target_include_directories(Patcher PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Lib/PolyHook_2_0/_install/include")

message("${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries(Patcher PRIVATE PolyHook_2 capstone)