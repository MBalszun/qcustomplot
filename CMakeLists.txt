#/***************************************************************************
#**                                                                        **
#**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
#**  Copyright (C) 2020 Michael Balszun                                    **
#**                                                                        **
#**  This program is free software: you can redistribute it and/or modify  **
#**  it under the terms of the GNU General Public License as published by  **
#**  the Free Software Foundation, either version 3 of the License, or     **
#**  (at your option) any later version.                                   **
#**                                                                        **
#**  This program is distributed in the hope that it will be useful,       **
#**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
#**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
#**  GNU General Public License for more details.                          **
#**                                                                        **
#**  You should have received a copy of the GNU General Public License     **
#**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
#**                                                                        **
#****************************************************************************


cmake_minimum_required(VERSION 3.13...3.18)

get_directory_property( parentdir PARENT_DIRECTORY)
if(parentdir)
  set( hasParent True )
  set( default_include_example OFF)
else()
  set( hasParent False )
  set( default_include_example ON)
endif()

#### Project interface
option(MBA_QCUSTOM_PLOT_INCLUDE_EXAMPLES "Include QCustomPlot Examples"  ${default_include_example})

project(MBaQCustomPlot LANGUAGES CXX)

#### General compilation settings
set(CMAKE_AUTOMOC True)

if(MSVC)
  add_compile_options(/W4)
else()
 add_compile_options(-Wall -Wextra)
endif()


####  Create library
add_library( mba-qcustom_plot
  src/qcustomplot.cpp
  include/qcustomplot/qcustomplot.h
  include/qcustomplot/utils/supress_common_qt_warnings_start.h
  include/qcustomplot/utils/supress_common_qt_warnings_stop.h
)

add_library(MBa::QCustomPlot ALIAS mba-qcustom_plot)

target_include_directories( mba-qcustom_plot
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

####  link to qt
if(NOT hasParent)
  find_package(Qt5Widgets REQUIRED)
  find_package(Qt5PrintSupport REQUIRED)
endif()

target_link_libraries(mba-qcustom_plot PUBLIC Qt5::Core Qt5::Widgets Qt5::PrintSupport)

if( MBA_QCUSTOM_PLOT_INCLUDE_EXAMPLES )
    add_subdirectory(examples/axis-tags)
    add_subdirectory(examples/interactions)
    add_subdirectory(examples/plots)
    add_subdirectory(examples/scrollbar-axis-range-control)
    add_subdirectory(examples/text-document-integration)
endif()
