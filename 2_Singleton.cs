/*
��Ŀ�����һ���࣬����ֻ�����ɸ����һ��ʵ��
��չ�������ģʽ��
ע�⣺�Լ���ֽ����д����@Qzl

*/
//���߳�
class Singleton {
	private Singleton instance;
	private Singleton(){ } //��̬���캯��
	public Singleton getInstance(){
		if(instance == null)
			instance = new Singleton();
		return instance;
	}
}
//���߳�
class Singleton1 {
	private Singleton1 instance;
	private static readonly object sync = new object();
	private Singleton(){ }
	public Singleton1 getInstance(){
		if(instance == null){ //���Ч�ʣ�û��Ҫÿ����ͼ�õ�ʵ��ʱ������ͬ����
			lock(sync){ //��ͬ����
				if(instance == null)
					instance = new Singleton1();
			}
		}
		return instance;
	}
}
//C#��̬��ʼ������
class sealed class Singleton2{
	private static readonly Singleton2 instance = new Singleton2();
	private Singleton2(){}
	public Singleton2 getInstance(){
		return instance;
	}
}
