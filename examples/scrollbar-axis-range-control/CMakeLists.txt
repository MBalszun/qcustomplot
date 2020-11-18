cmake_minimum_required(VERSION 3.10...3.18)

set(CMAKE_AUTOUIC True)
set(CMAKE_AUTORCC True)

file(GLOB_RECURSE SOURCE_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "*.h")
LIST(APPEND SOURCE_FILES mainwindow.ui)

add_executable(mba-qcustom_plot-ex-scrollbar_axis_range_control
	${SOURCE_FILES}
	${HEADER_FILES}
)

target_link_libraries(mba-qcustom_plot-ex-scrollbar_axis_range_control PUBLIC MBa::QCustomPlot)
