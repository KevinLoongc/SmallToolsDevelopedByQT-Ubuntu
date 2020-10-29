## 问题

本次项目开发在Qt中使用了png图片，编译出现下面警告信息：

```bash
libpng warning: iCCP: known incorrect sRGB profile
```

虽然对程序没什么影响，但是由于有点小强迫症，必须要搞掉这个烦人的警告。网上搜索了一下，这个警告貌似是和png图片的格式有关，是在png中嵌入了什么导致的。



## 解决方法

直接用QImage读取一下，然后直接保存回去就可以了。

```cpp
QImage img;

img.load("*.png");
img.save("*.png");
```

这里也就是给png做了一个Qt的适配。



执行程序如下图（Ubuntu16.04系统）。

[![0xUgsg.png](https://s1.ax1x.com/2020/10/19/0xUgsg.png)](https://imgchr.com/i/0xUgsg)


