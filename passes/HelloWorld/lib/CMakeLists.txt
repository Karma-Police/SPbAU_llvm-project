copy_files_to_build_dir(*.c)

include_directories (${SteensgaardsAnalysis_SOURCE_DIR}/HelloWorld/include)

set (HelloWorldCode
        Pass.cpp
        DSU_Node.cpp 
)


add_library (HelloObj OBJECT ${HelloWorldCode})
add_library (Hello SHARED $<TARGET_OBJECTS:HelloObj>)
add_library (HelloStatic STATIC $<TARGET_OBJECTS:HelloObj>)
