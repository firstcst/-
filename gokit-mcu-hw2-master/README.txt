Day1����һ��ʵ����Ŀ  ��������ʵ��
ʵ��Ч����
����key1������ʵ�ֹ����л�������һ�ΰ���key1ʱ������RGB�ƿ�ʼ�������ٴΰ���key1ʱ��
LED1~LED4��ˮ�ƿ�ʼ������Ȼ��ѭ����������״̬������
1.Keil5�������빦����Ϥ��ʹ�ã�
2.ѧϰʹ��FlyMcu�����¼���ߣ�
3.����key1������LED1~LED4����ƹ��ܣ�//KEY_Handle(void)�������Ҫ������ϵĹ���
4.LED1~LED4������ʵ������ƹ��ܣ�//Hal_hed.c����Ӵ���
sq1:
for(LEDNUM=1;LEDNUM<=4;LEDNUM++)
				{
					LED_ON(LEDNUM);
					Delay_us(100000);
					LED_OFF(LEDNUM);
					if(LEDNUM==4)
						LED_OFF(LED4);  //������������led4����Ϩ�𣿣���
				}
Day2��
1.���Դ����¹��̣�
sq:
   ���������ӳ�ʼ�����ļ��޴����֡�(���Ӵ��ڵ㾭��)
2.��ʵ����ˮ�ƹ��ܻ�������Ӱ���������﹦�ܣ�
sq:
  ���򱣳�����ˮ����ѭ���ڣ�����������﹦���޷�ִ�С�
3.��װgit for windows�棬ʵ�ֻ������ã�ѧϰ�ϴ���Ŀ��
sq:ִ�� ��git push -u origin master�������´���
error: src refspec master does not match any.
error: failed to push some refs to 'git@github.com:https://github.com/firstcst/-.git'

git remote add origin git@github.com:https://github.com/firstcst/-.git

Day3~6��һ����Ŀ�Ż�:
�Ż�key1�л����ܵ������Ⱥ�׼ȷ�ԣ��ύ���뵽github��
sq:
��ʵ�ֹ��ܵĴ������Ϻ����whlie()��ִ�У�Ч����ֱ����while()��ִ��Ч����ȫ��ͬ

Day7���ڶ�����Ŀʵ��   �����Ӧʵ��
ʵ��Ч�����������忿�������Ӧ��ʱ������RGB�ƿ�ʼ����(�𵽱���Ŀ��)��
������Զ�������RGB��ֹͣ����(��������)��
1.�鿴�������Ӧ�����������ں��ʵĵط���ӹ���ʵ�ִ���;
2.������룬��¼�ļ����豸����ִ֤�н��ͨ����