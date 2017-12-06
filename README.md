[TOC]
# 3DAOI (V2.0)

## 目录树

- [ ] debug模式的编译相对路径为:../debug/
- [ ] release模式的编译相对路径为:../release/
- [ ] AppSetting.ini配置文件相对路径为:../AppSetting.ini
- [ ] CaptureSetting.ini配置文件相对路径为:../CaptureSetting.ini

```
3DAOI/
├── AppSetting.ini              // UI相关的配置文件，包含主题、语言等
├── CaptureSetting.ini          // 程序运行所必须的文件，图像面阵尺寸等
├── data                        // 存放程式文件的文件夹
│  └── iPhoneV1                     // 程式文件
├── include                     // 第三方库的头文件
│  └── ...                          // 头文件
├── lib                         // 编译的静态库文件夹
│  └── ...                          // 静态库文件
├── flowchart_peter_02.png      // 软件运行流程图
├── README.md                   // 本说明文档
└── src                         // 源代码
    ├── 3DAOI.pro                   // QT的项目配置文件
    ├── App
    │   └── ...
    ├── DB 
    │   └── ...
    ├── Job
    │  └── ...
    ├── main.cpp
    └── SDK
        └──...
```


## 一.软件运行流程及功能

![Markdown](http://i4.cfimg.com/602518/9257849502e910d0.png)

1. 启动程序，加载AppSetting.ini和CaptureSetting.ini
    - [ ] AppSetting.ini不是软件运行所必须的配置，没有或参数错误可自动生成
    - [ ] CaptureSetting.ini是软件运行所必须的配置文件，没有或参数错误则直接停止软件运行
2. 在2个配置都加载成功的基础上，扫描data目录下的程式文件
    - [ ] 如果JobFolderPath没有文件的话，自动生成程式文件
    - [ ] 如果JobFolderPath有文件的话，将扫描到的程式文件打印到屏幕供用户选择
3. 在有程式文件的基础上，加载用户选择的程式
    - [ ] 若为V1版本,则自动将其转换为V2版本程式文件
    - [ ] 若为v2版本(当前版本),则直接读取
4. 读取成功后把所有的InspectionData信息在屏幕上打印出来
5. 读取成功后把所有的InspectionData信息以xml格式输出

## 二.配置文件说明

### 1.AppSetting.ini

---      | 配置名       |  参数
:---:    |:---:         |:---:
主题	 | Theme        |  Black / White
语言	 | Lang         |  CN / EN
机器类型 | LaneMode     |  Simulator / SingleLane / DualLane
机器名字 | MachineName  |  SPI / 3DAOI
公司名	 | CompanyName  |  Scijet / sung


    AppSetting.ini默认配置:
    
    [General]
    CompanyName=sung
    LaneMode=DualLane
    Language=EN
    MachineName=aoi
    Theme=white

### 2.CaptureSetting.ini
---                 |   配置名          |  参数
:---:               |   :---:           |  :---:
相机的图像面阵宽度  |   ImgWidth        |  3072
 相机的图像面阵高度 |  	ImgHeight       |  4096
支持的图像位数		|	ImgBits         |  BIT8/BIT16


    CaptureSetting.ini默认配置:
    
    [General]
    ImageWidth=3072
    ImageHeight=4096
    ImageBits=Bit8

## 三.程式文件说明

![Markdown](http://i1.cfimg.com/602518/7da3cc6fca0dcd39.jpg)


    Job表包含信息如下：
    1.软件版本
    2.最近一次编辑时间
    
    Board表包含信息如下：
    1.板子名称
    2.原点x轴坐标
    3.原点y轴坐标
    4.板子长度
    5.板子宽度
    
    MeasureObjs表包含信息如下：
    1.元件名称
    2.元件中心点x坐标
    3.元件中心点y坐标
    4.元件角度
    5.元件宽度
    6.元件高度
    


##  四.Change Log
>给measuredObj加入了角度属性，读V1程式的时候考虑到兼容问题自动将V1程式转换为V2程式。
