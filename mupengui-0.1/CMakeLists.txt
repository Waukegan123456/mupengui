cmake_minimum_required(VERSION 2.8.9)
project(mupengui)

find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Gui REQUIRED)
#find_package(Qt5Core REQUIRED)

add_executable(mupengui main.cpp mainwindow.cpp settingsdialog.cpp moc_mainwindow.cpp moc_settingsdialog.cpp)
install(TARGETS mupengui RUNTIME DESTINATION bin)

qt5_use_modules(mupengui Widgets)
