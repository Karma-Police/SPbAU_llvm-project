copy_files_to_build_dir(*.c)

include_directories (${SteensgaardsAnalysis_SOURCE_DIR}/AAHelloWorld/include)

set (AAHelloWorldCode
        AAHello.cpp
        DSU_Node.cpp 
)


add_library (AAHelloWorldObj OBJECT ${AAHelloWorldCode})
add_library (AAHelloWorld SHARED $<TARGET_OBJECTS:AAHelloWorldObj>)
add_library (AAHelloWorldStatic STATIC $<TARGET_OBJECTS:AAHelloWorldObj>)
