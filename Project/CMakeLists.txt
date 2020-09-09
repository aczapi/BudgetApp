cmake_minimum_required (VERSION 3.10)
project(BudgetApp)

set(SOURCE_FILES Markup.cpp date.cpp helpMethods.cpp dateManager.cpp user.cpp userManager.cpp budgetApp.cpp budgetManager.cpp userFile.cpp)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCE_FILES})

add_executable(${PROJECT_NAME} main.cpp)
#add_executable(${PROJECT_NAME}-ut test/budget.ut.cpp)


target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
#target_link_libraries(${PROJECT_NAME}-ut  ${PROJECT_NAME}-lib)

#set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)
set(FLAGS -Wall -Wextra -pedantic -O3)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
#target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})

#set_target_properties(${PROJECT_NAME} PROPERTIES
#                   CXX_STANDARD 17
#                   CXX_STANDARD_REQUIRED ON)
#set_target_properties(${PROJECT_NAME}-lib PROPERTIES
#                   CXX_STANDARD 17
#                   CXX_STANDARD_REQUIRED ON)
#set_target_properties(${PROJECT_NAME}-ut PROPERTIES
#                   CXX_STANDARD 17
#                   CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_STANDARD 17)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_features(${PROJECT_NAME}-lib PRIVATE cxx_std_17)
#target_compile_features(${PROJECT_NAME}-ut PRIVATE cxx_std_17)

#enable_testing()
#add_test(NAME greeterTests COMMAND ${PROJECT_NAME}-ut)