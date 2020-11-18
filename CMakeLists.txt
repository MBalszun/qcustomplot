cmake_minimum_required(VERSION 3.10)

project(MBaQCustomPlot)

add_library(mba-qcustom_plot qcustomplot.cpp)
add_library(MBa::QCustomPlot ALIAS mba-qcustom_plot)

target_include_directories( mba-qcustom_plot
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)
  find_package(Qt5Widgets REQUIRED)
  find_package(Qt5PrintSupport REQUIRED)
endif()

target_link_libraries(mba-qcustom_plot PUBLIC Qt5::Core Qt5::Widgets Qt5::PrintSupport)
