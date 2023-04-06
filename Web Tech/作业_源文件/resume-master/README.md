## 这是一份借鉴了许多优秀简历而制作出来的简历

我观摩（借cao鉴xi）优秀简历， 取其精华制作成了自己的简历，并向他们致谢！

如果你也喜欢，**Fork或借鉴请遵循[LICENSE](https://link.zhihu.com/?target=https%3A//github.com/mcc108/resume/blob/master/LICENSE)并注明出处。**

- 主要样式设计及代码等：[闵聪学长的在线简历](https://link.zhihu.com/?target=https%3A//resume.congm.in/)
- 二维码灵感：[饥人谷前端模拟面试锦集](https://link.zhihu.com/?target=https%3A//xiedaimala.com/courses/ec472c6f-4a87-4983-9609-2f9ae5674c43/random/89dbe7185b%23/common) 同学的简历
- 分页打印及修改功能：[方应杭老师的简历](https://link.zhihu.com/?target=http%3A//fangyinghang.com/cv-2020/dist/index.html%3Fv%3D1%23)
- emoji表情及博客描述：[清栀UI](https://link.zhihu.com/?target=https%3A//a_fei_fei_fei_fei_fei_fei.gitee.io/zhizz-ui-website/%23/doc/blog)

## 页面效果

[我的在线简历](https://link.zhihu.com/?target=https%3A//wu-sili.gitee.io/resume/)

[简历 | 吴思里 - Sili Wuwu-sili.gitee.io![图标](https://pic2.zhimg.com/v2-8e668d081c8fde1fe1457dabb0939db9_ipico.jpg)](https://link.zhihu.com/?target=https%3A//wu-sili.gitee.io/resume/)

![img](https://pic1.zhimg.com/80/v2-a2e99e90388c36ba9513cda13443c658_720w.jpg)PC端显示效果

![img](https://pic3.zhimg.com/80/v2-1d51be78bebe5881ac7ebe346403ea56_720w.jpg)简历第二页

![img](https://pic4.zhimg.com/80/v2-13eb1b1d44d7d5259d9755ef714c1a7b_720w.jpg)手机版效果

## 历史版本

其实我一开始的简历并不是现在所看到的样子，

它是我迭代改进的产物。

它的*优秀之处并非原创*，它的*原创*之处并不优秀。(优秀的*地方*大部分是从别的*地方*借鉴过来的——而我自己只是站在巨人的肩膀上修改）。

## 表格式简历

万事开头难，写简历一开始就是**填报表格**。

简历太丑没有项目不要想太多不如开写。

**填鸭式的表格式简历能让你快速开始第一步，也能让你在开始的时候不用太纠结思考写什么东西。**

![img](https://pic3.zhimg.com/80/v2-5d44aafd687e7fc7c2a02f9057dee3a2_720w.jpg)表格版简历

![img](https://pic4.zhimg.com/80/v2-5406fb56bdd8422a82525afce8997933_720w.jpg)word版简历

![img](https://pic3.zhimg.com/80/v2-64c39b689254abeacecb11de7aad8712_720w.jpg)

## **细节的点**

**代码块效果**

修改strong默认样式，拥有`代码块`效果

```css
strong {
  font-family: 'Helvetica Neue', Helvetica, 'PingFang SC', 'Microsoft YaHei', '微软雅黑', Arial, sans-serif;
  font-size: 13px;
  line-height: 15px;
  font-weight: 500;
  color: #494949;
  margin: 0 3px;
  padding: 3px 8px;
  background-color: #F6F6F6;
  border-radius: 5px;
  border: 1px solid rgb(235, 235, 235);
}
```

使用时将代码块用`<strong>`标签包住即可

```html
熟悉<strong>HTML</strong>、<strong>JS(TS)</strong>、<strong>AJAX</strong>、<strong>ES6</strong>
```

### **修改滚动条**

```css
::-webkit-scrollbar {
  width: 5px;
  background-color: #f1f1f1;
}

::-webkit-scrollbar-thumb {
  background-color: rgba(0, 0, 0, 0.2);
  border-radius: 50px;
}

```

### **打印**

**A4尺寸为21cm\*29.7cm**

所以简历每页的大小比例相同即可

```css
.page{
    width: 1024px;
    min-height: 1440px;
}
```

**简历不只一页，不该断的地方在分页处了怎么办？**

<style>标签中添加media属性

值为“print”，说明打印时才生效的样式

CSS `page-break-before`避免分页时内容的断开

```html
<style media="print">
    .page2{
        page-break-before:always;
    }
</style>
<section class=".page2">...</section>
```

### **PDF简历**

开始还不知道右键打印可以网页另存为PDF

一开始还傻傻的先做word简历，

再用HTML把简历给写出来

说实话前端出身操作HHTML+CSS可比操作office擅长多了

**附上pdf简历下载链接**

在a标签上添加`download`属性就可以点击下载

```html
<a class="pdf" href="resume.pdf" download>
```

### **简历可编辑**

**怎么让别人拿你的简历改了就可以用?**

修改`designMode`属性

```js
document.designMode='on'
```

### **响应式**

适配不同宽度的效果

```css
@media screen and (max-width:1024px) {}
@media screen and (max-width: 720px) {}
```