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


cmake_minimum_required(VERSION 3.10)

project(MBaQCustomPlot)

set(CMAKE_AUTOMOC True)

add_library( mba-qcustom_plot
  qcustomplot.cpp
  include/qcustomplot/qcustomplot.h
)
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
