Day1：第一个实验项目  按键控制实验
实验效果：
利用key1按键来实现功能切换，当第一次按下key1时，马达和RGB灯开始工作，再次按下key1时，
LED1~LED4流水灯开始工作，然后循环以上两种状态工作。
1.Keil5基本编译功能熟悉和使用；
2.学习使用FlyMcu软件烧录工具；
3.利用key1来控制LED1~LED4跑马灯功能；//KEY_Handle(void)中添加需要按键配合的功能
4.LED1~LED4开机即实现跑马灯功能；//Hal_hed.c中添加代码
sq1:
for(LEDNUM=1;LEDNUM<=4;LEDNUM++)
				{
					LED_ON(LEDNUM);
					Delay_us(100000);
					LED_OFF(LEDNUM);
					if(LEDNUM==4)
						LED_OFF(LED4);  //不添加最后两句led4不会熄灭？？？
				}
Day2：
1.尝试创建新工程；
sq:
   对于如何添加初始工程文件无从下手。(祥子传授点经验)
2.在实现流水灯功能基础上添加按键控制马达功能；
sq:
  程序保持在流水灯死循环内，按键控制马达功能无法执行。
3.安装git for windows版，实现基础配置，学习上传项目；
sq:执行 “git push -u origin master”报以下错误
error: src refspec master does not match any.
error: failed to push some refs to 'git@github.com:https://github.com/firstcst/-.git'

git remote add origin git@github.com:https://github.com/firstcst/-.git

Day3~6第一个项目优化:
优化key1切换功能的灵敏度和准确性，提交代码到github。
sq:
将实现功能的代码整合后放在whlie()内执行，效果和直接在while()内执行效果完全不同

Day7：第二个项目实验   红外感应实验
实验效果：当有物体靠近红外感应区时，马达和RGB灯开始工作(起到报警目的)；
当物体远离后，马达和RGB灯停止工作(警报结束)。
1.查看理解红外感应函数，尝试在合适的地方添加功能实现代码;
2.编译代码，烧录文件到设备，验证执行结果通过。