# Porkplayer
## 一、概述

Porkplayer 2是一款基于`Qt`和`libmpv`的视频播放器。相对普通播放器而言，Porkplayer 2的优点有以下几点：

- **色彩管理**更加完善
- **播放控制**更符合影视工作者的习惯
- 支持查看**视频元数据**

Porkplayer 2参考了以下项目：

- libmpv：https://github.com/mpv-player/mpv-examples/tree/master/libmpv/qt_opengl
- libedl：https://github.com/bradcordeiro/libedl
- MediaInfoLib：https://github.com/MediaArea/MediaInfoLib

Porkplayer 2只有Windows版本，使用Visual Studio 2019作为IDE，使用了Visual Studio的Qt Tools拓展。

## 二、系统功能设计

### 1. 基本功能

- 图形用户界面
- 视频载入
- 正放、暂停、倒放、快进快退、慢放慢退、逐帧播放
- 窗口关闭、最大化/最小化
- 拖拽进度条改变播放进度

### 2. 进阶功能

- 快捷键操作
    - O：打开文件
    - A：回退5秒
    - D：前进5秒
    - N：上一帧
    - M：下一帧
    - K：暂停
    - J：倒放，重复按加速
    - L：正放，重复按加速
    - 空格：播放/暂停
    - Y：慢速倒放
    - U：慢速正放
    - E：输出
- 转码、转封装（需要在设置中指定ffmpeg路径）
- 视频截图
- 不同格式编解码
- 播放速度显示
- 帧计数与时间码显示
- 色彩管理（指定输出色彩空间，支持HDR）
- 查看视频元数据

### 3. 系统流程分析

### 3.1 函数调用

在一个函数的调用过程中，至少需要以下三个cpp文件的参与：

- **main.cpp**
    1. 初始化QApplication类
    2. 初始化mainwindow类，调用show函数显示
    3. 调用exec函数运行QT程序
- **mainwindow.cpp**
    1. 初始化mpvwidget类，初始化UI窗体
    2. 初始化**信号与槽：**单击信号、属性变化信号，文字刷新槽
    3. 接收信号后触发槽函数，可改变UI内容，或向mpvwidget类传入/获取参数
- **mpvwidget.cpp**
    1. 初始化mpv类
    2. 设定observe函数以观察mpv_event，属性变化后并发送信号（可传参）
    3. 根据传入参数（目标文件、播放控制信息）完成解码、渲染等操作

此处举MainWindow类中的两个方法为例。

- openMedia()
    
    ![openMedia(1).png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/cd17d0bb-4d76-4209-ae4f-e79f3457ecde/openMedia(1).png)
    
- refreshText()
    
    ![refreshTimeText(1).png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b8e59066-a71b-4ac8-837d-99a9f1ce103b/refreshTimeText(1).png)
    

### 3.2 **视频解码流程**

**3.2.1 预处理**

![preparation(1).png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4e4fcaad-6cb2-4323-8ca8-5d503baf9682/preparation(1).png)

1. 选取文件
2. 返回文件名与文件路径
3. 读取元数据
4. 加入播放列表
5. 初始化mpv，并将视频载入

**3.2.2 解码渲染**

![decode(3).png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/83ac538a-6270-42fc-9129-855af5d68a3c/decode(3).png)

1. 解封装
2. 解码
3. 渲染视频，渲染音频
4. 以播放控制的设定输出

**3.2.3 后处理**

1. 自动播放下一条（若有）
2. 结束播放后，终止mpv

## 三、GUI设计

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e586e5b5-8813-43df-8d88-fce9568fada8/Untitled.png)

- 上方放置TextLabel作时间、速度信息的显示
- 上方放置PushButton作设置按钮
- 上方放置PushButton作元数据按钮
- 上方放置PushButton作输出按钮
- 下方放置Slider显示播放进度
- 下方放置PushButton作控件

## 四、模块设计

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/277ea0c3-0a46-4eba-a868-5ac177273a15/Untitled.png)

- main.cpp，main函数入口
- mainwindow.cpp，处理UI与交互，将参数传递给mpvwidget.cpp
- mpvwidget.cpp，处理包括视频解码、渲染在内的mpv_event
- timecode.cpp，处理帧到时间码的转换
- mediainfowidget.cpp，负责读取视频元数据
- settingwindow.cpp，负责指定输出色彩空间及ffmpeg.exe的路径
- exportwidget.cpp，负责制定转码/转封装的目标路径及目标格式

> 文中流程图使用iodraw绘制。
>
