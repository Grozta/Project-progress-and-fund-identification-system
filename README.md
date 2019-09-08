## Project-progress-and-fund-identification-system

工程进度及资金认定系统 (PPF_system)

####  示例图片



![展示的成果图]()

![展示的成果图]()

![展示的成果图]()

![展示的成果图]()

#### 前言

```笔者的基友从事于某国有建筑企业，每次一到游戏时间，也就是他吐槽他们公司当前的矛盾问题的时间,渐渐的对他所在的行业有了一点认识。想到当前自己的学习，不如自己弄一个能够解决他们问题的小软件。一来可以对自己所有有所巩固，二来也还是自我学习```

---

- 比较有意思的是最近刚好看了一个库DUillb，一看大佬写的博客。厉害了，这个库好厉害，基本上那种小程序必备啊。这个UI库的接口很直接，更加重要的是有教程啊。再次感谢Alberl大哥，给我这种弱鸡有个方向。在这里先贴出来吧，这个库就是我们后面程序UI核心

[Duilib库的所在地](<https://github.com/duilib/duilib>)

[Duilib入门简明教程](<https://www.cnblogs.com/Alberl/p/3354459.html>)



#### 项目背景

- 现阶段大型建筑公司内部普遍出现的关于工程进度和资金认定上的尖锐矛盾。项目外包后，产生了由项目部->生产经理->生产队的资金和工程进度认定体系。随着网络时代的发展，在工程队伍中的年轻化的过程中，公正公开的，安全的资金认定考虑越来越成为焦点话题

![这是一个现阶段工程进度和资金认定的概图]()

- 这个图就是当前他们资金和工程进度认定的流水图（这里面的门道太多，在这里不细讲）

#### 出现的问题

- 在普通工人和生产队长之间的问题
    1. 有的工人不想记录的自己的工时，虽然说队长也会记录，但是有时又会记错。或者说工人说队长记错了，然后这个工人就去项目部去闹（队长既不想出这个钱，也不想他取闹），但是没办法，这个时候一般是给钱，炒鱿鱼。
    2. 队长每月要去核对工时，很麻烦。没有出错还好，一旦出错了，就要找好多人来对峙。而且很费时间，经常对一个月的工时需要2到4个晚上
- 队长和生产经理之间的矛盾
    1. 生产经理一般会审批生产队的任务，和每个月申请的资金（生产队的工资），但是这个资金评估希望尽可能少，不然项目部会找他麻烦。但是工程队希望能评估的多，队长不愿意就不断去找生产经理（各种手段）
    2. 生产经理会审批底下的工程队的资金和进度，同时需要向项目部报给项目经理工程进度，这个时候项目经理批复给他，批复完了给财务，再审批。流程多，材料多，单据多。
- 项目部
    1. 每到年底都会有各种工资认定不清的人，找到按项目部来，查单据，由于审批单据多，很难找。
    2. 同时年底结算的时候需要核对每一个单据，需要很多人提前做工作，影响工作效率

#### 解决办法

- 通过软件记录的方式，详细记录每个工作资金和进度的认定

-----------

队长客户端

![这是一个介绍队长客户端操作流程的图片]()



生产经理客户端

![这是一个展示生产经理客户端操作的图片]()

项目部客户端

![这是一个展示项目部审批项目、查阅操作的流程图]()

- 各个客户端功能以及系统构想

-----------------

>  需求：

![这是一个介绍PPF_SYSTEM需求的图片]()

>  系统构想：







- 数据库设计

-------

![这是一张数据库设计概念图]()

项目文件中 [数据库设计.sql](<https://github.com/Grozta/Project-progress-and-fund-identification-system/blob/master/%E6%95%B0%E6%8D%AE%E5%BA%93%E8%AE%BE%E8%AE%A1.sql>)就是我创建表的信息，由于使用的mysql5.5，所以有的功能不支持，比如说外键功能

#### 项目开始

- 学习Duillb库，这里又要提到我看的博客了[Duilib入门简明教程](<https://www.cnblogs.com/Alberl/p/3354459.html>)

- 这里就是提及一下我遇到的问题，以及我的解决方案

    1. 【编码转换问题】duilib库中有定义好的ANSC码转UNIcode码的宏``` _T()``` 这个宏可以将我们的字符串信息，转成ANSC码，但是这个中却没有将Unicode转ANSC

        ```   c++
        CDuiString ANSIToUnicode(const string& str)
        {
        	int  len = 0;
        	len = str.length();
        	int  unicodeLen = ::MultiByteToWideChar(CP_ACP,
        		0,
        		str.c_str(),
        		-1,
        		NULL,
        		0);
        	wchar_t *  pUnicode;
        	pUnicode = new  wchar_t[unicodeLen + 1];
        	memset(pUnicode, 0, (unicodeLen + 1)*sizeof(wchar_t));
        	::MultiByteToWideChar(CP_ACP,
        		0,
        		str.c_str(),
        		-1,
        		(LPWSTR)pUnicode,
        		unicodeLen);
        	CDuiString rt(pUnicode);
        	delete  pUnicode;
        
        	return  rt;
        }
        
        string UnicodeToANSI(const CDuiString& str)
        {
        	char*     pElementText;
        	int    iTextLen;
        	// wide char to multi char
        	iTextLen = WideCharToMultiByte(CP_ACP,
        		0,
        		str.GetData(),
        		-1,
        		NULL,
        		0,
        		NULL,
        		NULL);
        	pElementText = new char[iTextLen + 1];
        	memset((void*)pElementText, 0, sizeof(char)* (iTextLen + 1));
        	::WideCharToMultiByte(CP_ACP,
        		0,
        		str.GetData(),
        		-1,
        		pElementText,
        		iTextLen,
        		NULL,
        		NULL);
        	string strText;
        	strText = pElementText;
        	delete[] pElementText;
        	return strText;
        }
        ```