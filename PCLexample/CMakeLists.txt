# 최소 요구 버젼
CMAKE_MINIMUM_REQUIRED (VERSION 2.8 FATAL_ERROR)

# 패키지 이름
PROJECT (MY_FIRST_PCL)
MESSAGE ( STATUS ${CMAKE_PROJECT_NAME} ) #( [<Type>] <메시지> )

# 변수 설정
SET(COMPIL_FLAGS "-std=c++11")

# 의존성 패키지
FIND_PACKAGE (PCL 1.2 REQUIRED) #프로그램 실행시 필요한 패키지 #없을 경우 에러 발생

#헤더디렉토리 지정
INCLUDE_DIRECTORIES(
  ${PCL_INCLUDE_DIRS}
)

# 라이브러리 디렉토리 지정 (-L)
LINK_DIRECTORIES(${PCL_LIBRARY_DIRS})


# 전처리기 매크로 추가 (-D)
ADD_DEFINITIONS(${COMPILE_FLAGS})
ADD_DEFINITIONS(${PCL_DEFINITIONS})

# 생성할 실행 파일 옵션
# ADD_EXECUTABLE (advanced_icp_example advanced_icp_example.cpp)
ADD_EXECUTABLE (pcd_write_test pcd_write.cpp)
ADD_EXECUTABLE (pcl_icp_example pcl_icp_example.cpp)
# Target 링크 옵션 및 라이브러리 지정 (-l)
TARGET_LINK_LIBRARIES(pcd_write_test ${PCL_LIBRARIES})    #( <Target_이름> <라이브러리> <라이브러리> ... )
                                                    # 실행 파일생성하기에 앞서 링크 해야 하는 라이브러리와 실행 파일 링크
target_link_libraries(pcl_icp_example ${PCL_LIBRARIES})
# target_link_libraries(advanced_icp_example ${PCL_LIBRARIES})
