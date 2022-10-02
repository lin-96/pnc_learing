# pnc_learing

1.cpp_bezier: 基于C++的贝塞尔曲线
    ## 1.安装下载matplotlib-cpp
    从git上拉取matplotlib-cpp源码,拉取完之后还需要按照matplotlib-cpp相关要求安装依赖,依赖安装完之后要替换下matplotlibcpp.h,如果不替换编译会报错.
    ```
        cd include
        git clone https://github.com/lava/matplotlib-cpp.git
        cp matplotlibcpp.h matplotlib-cpp/
        cd ..
    ```
    ## 2.编译运行
    ```
        mkdir build && cd build
        cmake ..
        make
        ./cpp_bezier
    ```
