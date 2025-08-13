set(SOURCES
    main.cpp
    # add other .cpp files here as we implement
)

add_executable(Card_RPG ${SOURCES})
target_include_directories(Card_RPG PRIVATE ${CMAKE_SOURCE_DIR}/include)
